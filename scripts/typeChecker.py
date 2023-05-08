from copy import deepcopy

from antlr4 import *
from gen.STLexer import STLexer
from gen.STParser import STParser
from gen.STVisitor import STVisitor


from dataFormat import FBEnv
from dataFormat import Enumformat
from dataFormat import BitFormat
from dataFormat import VarFormat

from builtinFUNdatafile import getBuiltinFun
from builtinFUNdatafile import getQOR
from builtinFBdatafile import libFBmap

import Helperfunctions


class typeCheck(STVisitor):
    def __init__(self, libFBs):
        self.programs = list()
        self.subprograms = list()
        self.udfbs = list()
        self.funcs = list()
        self.structures = list()

        self.globalVarEnv = dict()

        self.enumDict = dict()
        self.bitDict = dict()

        self.FBEnvDict = dict()
        self.FBEnvDict = deepcopy(libFBs)

        self.switch = True

        self.nowPou = ""

        self.libBackup = deepcopy(libFBs)

    def visitStapp(self, ctx:STParser.StappContext):
        self.visit(ctx.config())
        todolist = list()

        for i in range(len(ctx.pros())): todolist.append(self.visit(ctx.pros(i)))
        for i in range(len(ctx.subs())): todolist.append(self.visit(ctx.subs(i)))
        for i in range(len(ctx.udfbs())): todolist.append(self.visit(ctx.udfbs(i)))
        for i in range(len(ctx.funcs())): todolist.append(self.visit(ctx.funcs(i)))

        for pouName, pouProgram in todolist:
            self.nowPou = pouName
            self.visit(pouProgram)


    def visitConfig(self, ctx:STParser.ConfigContext):
        self.visit(ctx.programSection())
        self.visit(ctx.typeSection())

        try:
            self.globalVarEnv = deepcopy(Helperfunctions.makevarListTovarDict(self.visit(ctx.var_global())))
        except:
            pass

    def visitAProgram(self, ctx:STParser.AProgramContext):
        self.programs.append(ctx.name.text)

    def visitEnum(self, ctx:STParser.EnumContext):
        self.enumDict[ctx.name.text] = Enumformat(ctx.name.text, self.visit(ctx.idList()))

    def visitBitfield(self, ctx:STParser.BitfieldContext):
        self.bitDict[ctx.name.text] = BitFormat(ctx.name.text, ctx.varType.text, self.visit(ctx.idList()))

    def visitStructure(self, ctx:STParser.StructureContext):
        varDeclList = list()
        self.structures.append(ctx.name.text)
        for i in range(len(ctx.varDecl())): varDeclList.append(ctx.varDecl(i))
        self.FBEnvDict[ctx.name.text] = Helperfunctions.makeStructureFBformat("STRUCT", ctx.name.text, lambda x: self.visit(x), varDeclList)

    def visitIdList(self, ctx:STParser.IdListContext):
        return list(map(lambda x: x.strip(), ctx.getText().split(",")))

    def visitListInitVar(self, ctx: STParser.ListInitVarContext):
        return list(map(lambda x: x.strip(), ctx.getText().split(",")))

    def visitArrayType(self, ctx:STParser.ArrayTypeContext):
        return ctx.varType.text, ctx.dim.text

    def visitStappTypes(self, ctx:STParser.StappTypesContext):
        try:
            return self.visit(ctx.arrayType())
        except:
            return (ctx.getText(), Helperfunctions.genDummpy())

    def visitVar_decl_collection(self, ctx: STParser.Var_decl_collectionContext):
        varList = list()
        for i in range(len(ctx.var_priv())): varList += self.visit(ctx.var_priv(i))
        for i in range(len(ctx.var_in())): varList += self.visit(ctx.var_in(i))
        for i in range(len(ctx.var_in_out())): varList += self.visit(ctx.var_in_out(i))
        for i in range(len(ctx.var_out())): varList += self.visit(ctx.var_out(i))
        return varList

    def visitYESINITDECL(self, ctx:STParser.YESINITDECLContext):
        type, dim = self.visit(ctx.stappTypes())
        return Helperfunctions.makeVarFormat(ctx.name.text, type, dim,  self.visit(ctx.listInitVar()))

    def visitNOINITDECL(self, ctx:STParser.NOINITDECLContext):
        type, dim = self.visit(ctx.stappTypes())
        return Helperfunctions.makeVarFormat(ctx.name.text, type, dim, list())

    def visitVar_priv(self, ctx: STParser.Var_privContext):
        return Helperfunctions.makeVarFormatListFromVarDecl(lambda x: self.visit(x), ctx, "##PRIV")

    def visitVar_in(self, ctx: STParser.Var_inContext):
        return Helperfunctions.makeVarFormatListFromVarDecl(lambda x: self.visit(x), ctx, "##IN")

    def visitVar_in_out(self, ctx: STParser.Var_in_outContext):
        return Helperfunctions.makeVarFormatListFromVarDecl(lambda x: self.visit(x), ctx, "##INOUT")

    def visitVar_out(self, ctx: STParser.Var_outContext):
        return Helperfunctions.makeVarFormatListFromVarDecl(lambda x: self.visit(x), ctx, "##OUT")

    def visitVar_global(self, ctx:STParser.Var_globalContext):
        return Helperfunctions.makeVarFormatListFromVarDecl(lambda x: self.visit(x), ctx, "##GLOBAL")

    # Visit a parse tree produced by STParser#pros.
    def visitPros(self, ctx:STParser.ProsContext):
        self.FBEnvDict[ctx.name.text] = Helperfunctions.makeFBformat("PROGRAM", ctx.name.text, lambda x: self.visit(x), ctx, self.globalVarEnv)
        return (ctx.name.text, ctx.program())

    def visitSubs(self, ctx:STParser.SubsContext):
        self.subprograms.append(ctx.name.text)
        self.FBEnvDict[ctx.name.text] = Helperfunctions.makeFBformat("SUBPROGRAM", ctx.name.text, lambda x: self.visit(x), ctx, self.globalVarEnv)
        return (ctx.name.text, ctx.program())

    def visitUdfbs(self, ctx:STParser.UdfbsContext):
        self.udfbs.append(ctx.name.text)
        self.FBEnvDict[ctx.name.text] = Helperfunctions.makeFBformat("FUNCTION_BLOCK", ctx.name.text, lambda x: self.visit(x), ctx, self.globalVarEnv)
        return (ctx.name.text, ctx.program())

    def visitFuncs(self, ctx:STParser.FuncsContext):
        self.funcs.append(ctx.name.text)
        Helperfunctions.makeErrorMessage(self, "New Declared Function Error :", "Function Declaration is not supported", ctx.getText())
        self.FBEnvDict[ctx.name.text] = Helperfunctions.makeFBformat("FUNCTION", ctx.name.text, lambda x: self.visit(x), ctx, self.globalVarEnv, ctx.returntype.text)
        return (ctx.name.text, ctx.program())

    def visitBOOLTRUE(self, ctx: STParser.BOOLTRUEContext): self.FBEnvDict[self.nowPou].type[ctx.getText()] = "BOOL"
    def visitBOOLFALSE(self, ctx: STParser.BOOLFALSEContext): self.FBEnvDict[self.nowPou].type[ctx.getText()] = "BOOL"
    def visitTIMEPRIMARY(self, ctx: STParser.TIMEPRIMARYContext): self.FBEnvDict[self.nowPou].type[ctx.getText()] = "TIME"
    def visitSPECIALTOKEN(self, ctx:STParser.SPECIALTOKENContext): self.FBEnvDict[self.nowPou].type[ctx.getText()] = "TIME"

    def visitENUMPRIMARY(self, ctx:STParser.ENUMPRIMARYContext):
        isCorrectEnumType = ctx.ID(0).getText() in list(self.enumDict.keys())
        if isCorrectEnumType: isCorrectEnumVal = ctx.ID(1).getText() in self.enumDict[ctx.ID(0).getText()].vars
        else: isCorrectEnumVal = False

        if isCorrectEnumType and isCorrectEnumVal: self.FBEnvDict[self.nowPou].type[ctx.getText()] = ctx.ID(0).getText()
        else:
            if not isCorrectEnumType:
                Helperfunctions.makeErrorMessage(self, "Type Error :", ctx.ID(0).getText() + " is not enum type", ctx.getText())
            else:
                Helperfunctions.makeErrorMessage(self, "Type Error :", ctx.ID(0).getText() + " doesn't have " + ctx.ID(1).getText(), ctx.getText())
            self.FBEnvDict[self.nowPou].type[ctx.getText()] = "UNKNOWN"


    def visitAssign(self, ctx: STParser.AssignContext):
        self.visitChildren(ctx)
        left, right = Helperfunctions.checkWhetherTwoTypeSame(self,
                                                              self.FBEnvDict[self.nowPou].type[ctx.expr(0).getText()],
                                                              self.FBEnvDict[self.nowPou].type[ctx.expr(1).getText()], ctx.getText())

    def visitOpwithequal(self, ctx: STParser.OpwithequalContext):
        self.visitChildren(ctx)
        left, right = Helperfunctions.checkWhetherTwoTypeSame(self,
                                                              self.FBEnvDict[self.nowPou].type[ctx.expr(0).getText()],
                                                              self.FBEnvDict[self.nowPou].type[ctx.expr(1).getText()],
                                                              ctx.getText())

    def visitWHILESTATEMENT(self, ctx: STParser.WHILESTATEMENTContext):
        self.visitChildren(ctx)
        if not self.FBEnvDict[self.nowPou].type[ctx.expr().getText()] == "BOOL":
            Helperfunctions.makeErrorMessage(self, "Type Error :", "While condition must have BOOL type", ctx.getText())

    def visitREPEATSTATEMENT(self, ctx: STParser.REPEATSTATEMENTContext):
        self.visitChildren(ctx)
        if not self.FBEnvDict[self.nowPou].type[ctx.expr().getText()] == "BOOL":
            Helperfunctions.makeErrorMessage(self, "Type Error :", "Repeat condition must have BOOL type",ctx.getText())

    def visitIFSTATEMENT(self, ctx: STParser.IFSTATEMENTContext):
        self.visitChildren(ctx)
        for i in range(len(ctx.expr())):
            if not self.FBEnvDict[self.nowPou].type[ctx.expr(i).getText()] == "BOOL":
                Helperfunctions.makeErrorMessage(self,"Type Error :", "If condition must have BOOL type", ctx.getText())

    def visitPARENTHESIS(self, ctx: STParser.PARENTHESISContext):
        self.visitChildren(ctx)
        self.FBEnvDict[self.nowPou].type[ctx.getText()] = self.FBEnvDict[self.nowPou].type[ctx.expr().getText()]

    def visitCASESTATEMENT(self, ctx: STParser.CASESTATEMENTContext):
        self.visit(ctx.expr())
        typeSet = set()
        for i in range(len(ctx.caseoptionline())): typeSet.add(self.visit(ctx.caseoptionline(i)))
        if len(list(typeSet)) != 1:
            caseoptionlines = ""
            for i in range(len(ctx.caseoptionline())): caseoptionlines += ctx.caseoptionline().getText() + "\n"
            Helperfunctions.makeErrorMessage(self,"Type Error :", "list of options have different types", caseoptionlines)

    def visitCASESTATEMENTWITHELSE(self, ctx: STParser.CASESTATEMENTWITHELSEContext):
        self.visit(ctx.expr())
        typeSet = set()
        for i in range(len(ctx.caseoptionline())): typeSet.add(self.visit(ctx.caseoptionline(i)))
        if len(list(typeSet)) != 1:
            caseoptionlines = ""
            for i in range(len(ctx.caseoptionline())): caseoptionlines += ctx.caseoptionline().getText() + "\n"
            Helperfunctions.makeErrorMessage(self,"Type Error :", "list of options have different types", caseoptionlines)
        self.visit(ctx.statementList())

    def visitCaseoptionline(self, ctx: STParser.CaseoptionlineContext):
        caseOptionType = self.visit(ctx.caseoption())
        self.visit(ctx.statementList())
        return caseOptionType

    def visitCaseoption(self, ctx:STParser.CaseoptionContext):
        self.visitChildren(ctx)
        typeSet = set()
        for i in range(len(ctx.primary())):
            if "NUM" in self.FBEnvDict[self.nowPou].type[ctx.primary(i).getText()]: typeSet.add("NUM")
            elif self.FBEnvDict[self.nowPou].type[ctx.primary(i).getText()] in list(self.enumDict.keys()):
                typeSet.add(self.FBEnvDict[self.nowPou].type[ctx.primary(i).getText()])
            else:
                Helperfunctions.makeErrorMessage(self, "Type Error :", "Only Enum or Natural number can be used in case option", ctx.getText())
                self.FBEnvDict[self.nowPou].type[ctx.getText()] = "UNKNOWN"
                return "UNKNOWN"

        if len(list(typeSet)) != 1:
            Helperfunctions.makeErrorMessage(self, "Type Error :", "list of options have different types", ctx.getText())
            self.FBEnvDict[self.nowPou].type[ctx.getText()] = "UNKNOWN"
            return "UNKNOWN"
        return list(typeSet)[0]

    def visitARRAYEXPR(self, ctx: STParser.ARRAYEXPRContext):
        self.visitChildren(ctx)
        arrayIndexPart = self.FBEnvDict[self.nowPou].type[ctx.expr().getText()]
        arrayIndexSwitch = arrayIndexPart in Helperfunctions.intTypes()  or arrayIndexPart in Helperfunctions.numTypes()


        if not ("ARRAY[" in self.FBEnvDict[self.nowPou].type[ctx.varname().getText()] and arrayIndexSwitch):
            Helperfunctions.makeErrorMessage(self, "Type Error :", ctx.varname().getText() + " is not Array or array index is not INT type", ctx.getText())
            self.FBEnvDict[self.nowPou].type[ctx.getText()] = "UNKNOWN"
            return

        self.FBEnvDict[self.nowPou].type[ctx.getText()] = self.FBEnvDict[self.nowPou].type[ctx.varname().getText()][6:-1]

    def visitNOTOPERATION(self, ctx: STParser.NOTOPERATIONContext):
        self.visitChildren(ctx)
        if "REAL" == self.FBEnvDict[self.nowPou].type[ctx.expr().getText()]:
            Helperfunctions.makeErrorMessage(self, "Type Error :", "NOT operator only can have BOOL operand or INT operand", ctx.getText())
            self.FBEnvDict[self.nowPou].type[ctx.getText()] = "UNKNOWN"
        else:
            self.FBEnvDict[self.nowPou].type[ctx.getText()] = self.FBEnvDict[self.nowPou].type[ctx.expr().getText()]


    def visitLOGICALBINARY(self, ctx: STParser.LOGICALBINARYContext):
        self.visitChildren(ctx)
        left, right = Helperfunctions.checkWhetherTwoTypeSame(self,
                                                              self.FBEnvDict[self.nowPou].type[ctx.expr(0).getText()],
                                                              self.FBEnvDict[self.nowPou].type[ctx.expr(1).getText()], ctx.getText())
        if left == "UNKNOWN":
            self.FBEnvDict[self.nowPou].type[ctx.getText()] = "UNKNOWN"
        elif left == "BOOL" or left == "NUMBIT":
            self.FBEnvDict[self.nowPou].type[ctx.getText()] = "BOOL"

    def visitNEGATIVEOPERATION(self, ctx: STParser.NEGATIVEOPERATIONContext):
        self.visitChildren(ctx)
        targetType = self.FBEnvDict[self.nowPou].type[ctx.expr().getText()]
        if targetType in Helperfunctions.intTypes() + Helperfunctions.realTypes() + Helperfunctions.numTypes():
            self.FBEnvDict[self.nowPou].type[ctx.getText()] = self.FBEnvDict[self.nowPou].type[ctx.expr().getText()]
        else:
            Helperfunctions.makeErrorMessage(self, "Type Error :", "Integer expression expected after '-'", ctx.getText())
            self.FBEnvDict[self.nowPou].type[ctx.getText()] = "UNKNOWN"

    def visitNUMERICALOPERATION(self, ctx: STParser.NUMERICALOPERATIONContext):
        self.visitChildren(ctx)
        left, right = Helperfunctions.checkWhetherTwoTypeSame(self,
                                                              self.FBEnvDict[self.nowPou].type[ctx.expr(0).getText()],
                                                              self.FBEnvDict[self.nowPou].type[ctx.expr(1).getText()], ctx.getText())
        if left == "UNKNOWN":
            self.FBEnvDict[self.nowPou].type[ctx.getText()] = "UNKNOWN"
        else:
            self.FBEnvDict[self.nowPou].type[ctx.getText()] = left

        if ctx.op.text == "MOD" and (not left == "DINT"):
            self.FBEnvDict[self.nowPou].type[ctx.getText()] = "UNKNOWN"

    def visitCOMPARISON(self, ctx: STParser.COMPARISONContext):
        self.visitChildren(ctx)
        left, right = Helperfunctions.checkWhetherTwoTypeSame(self,
                                                              self.FBEnvDict[self.nowPou].type[ctx.expr(0).getText()],
                                                              self.FBEnvDict[self.nowPou].type[ctx.expr(1).getText()], ctx.getText())
        if left == "UNKNOWN":
            self.FBEnvDict[self.nowPou].type[ctx.getText()] = "UNKNOWN"
        else:
            self.FBEnvDict[self.nowPou].type[ctx.getText()] = "BOOL"

        if (ctx.op.text == ">" or ctx.op.text == "<" or ctx.op.text == ">=" or ctx.op.text == "<=") and left == "BOOL":
            Helperfunctions.makeErrorMessage(self, "Type Error :", "Boolean cannot be applied to comparison except equal and inequal", ctx.getText())
            self.FBEnvDict[self.nowPou].type[ctx.getText()] = "UNKNOWN"

    def visitEXPONENTIAL(self, ctx: STParser.EXPONENTIALContext):
        self.visitChildren(ctx)
        left, right = Helperfunctions.checkWhetherTwoTypeSame(self,
                                                              self.FBEnvDict[self.nowPou].type[ctx.expr(0).getText()],
                                                              self.FBEnvDict[self.nowPou].type[ctx.expr(1).getText()], ctx.getText())

        if "REAL" in left:
            self.FBEnvDict[self.nowPou].type[ctx.getText()] = left
        else:
            Helperfunctions.makeErrorMessage(self, "Type Error :", "** can be used with REAL values", ctx.getText())
            self.FBEnvDict[self.nowPou].type[ctx.getText()] = "UNKNOWN"

    def visitFUNCTIONCALL(self, ctx: STParser.FUNCTIONCALLContext):
        arguments = self.visit(ctx.argumentlist())

        if arguments[0][0] != "EMPTY":
            Helperfunctions.makeErrorMessage(self, "Not Support :", "In standard function call, FUN(in := Val .. ) is not supported : ", ctx.getText())


        numOfArguments = len(arguments)

        if ctx.op.text == "QOR": alternatives = getQOR(numOfArguments)
        else: alternatives = getBuiltinFun(ctx.op.text)


        for oneAlternative in alternatives:
            sizeOfArguments = oneAlternative[0]
            if not sizeOfArguments == numOfArguments:
                Helperfunctions.makeErrorMessage(self, "Type Error :", "Not Enough parameters\nExpected : " + str(sizeOfArguments) + " But : " + str(numOfArguments), ctx.getText())
                self.FBEnvDict[self.nowPou].type[ctx.getText()] = "UNKNOWN"
                return

            isCompatible = False
            for i in range(0, sizeOfArguments):

                if not Helperfunctions.checkWhetherTwoTypeSame(self, oneAlternative[1 + i], arguments[i][1], ctx.getText(), switch=False):
                    isCompatible = False
                    break
                else:
                    isCompatible = True

            if isCompatible:
                self.FBEnvDict[self.nowPou].type[ctx.getText()] = oneAlternative[1 + sizeOfArguments]
                return


        Helperfunctions.makeErrorMessage(self, "Type Error :", "Arguments don't have correct type", ctx.getText())
        self.FBEnvDict[self.nowPou].type[ctx.getText()] = "UNKNOWN"

    def visitSTANDARDFUNCALL(self, ctx:STParser.STANDARDFUNCALLContext):
        arguments = self.visit(ctx.argumentlist())
        argTypes = list(map(lambda x: x[0], arguments))
        AssignmentArgList = list(filter(lambda x: x != "EMPTY", argTypes))
        numOfArguments = len(arguments)

        if len(AssignmentArgList) > 0:
            Helperfunctions.makeErrorMessage(self, "Not Support :",
                                             "In specific function call, FUN(in := Val .. ) is not supported : ", ctx.getText())

        if numOfArguments != 1:
            Helperfunctions.makeErrorMessage(self, "Type Error :",
                                             "Not Enough parameters\nExpected : " + str(1) + " But : " + str(numOfArguments), ctx.getText())
        else:
            if ctx.funcall.text == '@#timerSetValue' or ctx.funcall.text == "WAIT_TIME":
                Helperfunctions.checkFunctionBlockCallArgument(self, ["TIME"], arguments, ctx.getText())
            else:
                Helperfunctions.checkFunctionBlockCallArgument(self, ["BOOL"], arguments, ctx.getText())



    def visitUSERDEFINEFUNCALL(self, ctx:STParser.USERDEFINEFUNCALLContext):
        self.visit(ctx.varname())

        functionName = ctx.varname().getText()

        if functionName in list(self.FBEnvDict[self.nowPou].type.keys()):
            functionNameType = self.FBEnvDict[self.nowPou].type[ctx.varname().getText()]
        elif functionName in self.subprograms:
            functionNameType = functionName
        else:
            Helperfunctions.makeErrorMessage(self, "Unknown Function :", functionName + " is not declared", ctx.getText())
            return

        arguments = self.visit(ctx.argumentlist())
        argTypes = list(map(lambda x: x[0], arguments))
        nonAssignmentArgList = list(filter(lambda x: x == "EMPTY", argTypes))
        numOfArguments = len(arguments)


        if not functionNameType in list(self.FBEnvDict.keys()):
            Helperfunctions.makeErrorMessage(self, "Type Error :", functionName + " is not Function Block",ctx.getText())


        parameterTypes = list(map(lambda x: x.type, self.FBEnvDict[functionNameType].inOrinoutParameter))
        sizeOfArguments = len(parameterTypes)

        if not (len(nonAssignmentArgList) == 0 or len(nonAssignmentArgList) == sizeOfArguments):
            Helperfunctions.makeErrorMessage(self, "Type Error :", "You cannot use function call by mixing two form", ctx.getText())

        if numOfArguments != sizeOfArguments:
            Helperfunctions.makeErrorMessage(self, "Type Error :",
                                  "Not Enough parameters\nExpected : " + str(sizeOfArguments) + " But : " + str(numOfArguments), ctx.getText())

        if len(nonAssignmentArgList) == sizeOfArguments:
            Helperfunctions.checkFunctionBlockCallArgument(self, parameterTypes, arguments, ctx.getText())
        else:
            if functionNameType in list(self.FBEnvDict.keys()):
                Helperfunctions.checkFunctionBlockCallArgumentMapping(self, self.FBEnvDict[functionNameType], arguments, ctx.getText())
            else:
                Helperfunctions.makeErrorMessage(self, "Unknown function block :", functionName, ctx.getText())



    def visitARGLIST(self, ctx: STParser.ARGLISTContext):
        self.visitChildren(ctx)
        arguments = list()
        for i in range(len(ctx.expr())): arguments.append(("EMPTY", self.FBEnvDict[self.nowPou].type[ctx.expr(i).getText()]))
        return arguments

    def visitONETOONELIST(self, ctx: STParser.ONETOONELISTContext):
        arguments = list()
        for i in range(len(ctx.assignargument())): arguments.append(self.visit(ctx.assignargument(i)))
        return arguments

    def visitONETOONE(self, ctx: STParser.ONETOONEContext):
        self.visit(ctx.expr())
        return(ctx.varname().getText(), self.FBEnvDict[self.nowPou].type[ctx.expr().getText()])

    def visitONTTOONPARENTHESIS(self, ctx: STParser.ONTTOONPARENTHESISContext):
        returnVal = self.visit(ctx.assignargument())
        self.FBEnvDict[self.nowPou].type[ctx.getText()] = self.FBEnvDict[self.nowPou].type[ctx.assignargument().getText()]
        return returnVal

    def visitVarname(self, ctx: STParser.VarnameContext):
        if not "." in ctx.getText():
            trueOrfalse, varType = Helperfunctions.checkENUM(self.enumDict, ctx.getText())
            if trueOrfalse:
                self.FBEnvDict[self.nowPou].type[ctx.getText()] = varType
            else:
                Helperfunctions.checkWhetherUnknownVar(self, self.FBEnvDict[self.nowPou], ctx.getText())

        else:

            splited = ctx.getText().split(".")
            nowVar = splited[0]
            accumulation = nowVar

            nowPOU = self.nowPou
            for i in range(1, len(splited)):
                nextVar = splited[1]
                accumulation += "." + nextVar
                result = Helperfunctions.checkWhetherUnknownVar(self, self.FBEnvDict[nowPOU], nowVar, switch=False)
                if result:
                    nowPOU = self.FBEnvDict[nowPOU].varEnv[nowVar].type
                    trueOrfalse, varType, varDim = Helperfunctions.checkFB(self.FBEnvDict, nowPOU, nextVar)
                    if trueOrfalse:
                        self.FBEnvDict[self.nowPou].type[accumulation] = varType
                        nowPOU = varType
                        nowVar = nextVar
                        continue

                    trueOrfalse, varType = Helperfunctions.checkBitField(self.bitDict, nextVar)
                    if trueOrfalse:
                        #print(ctx.getText(), accumulation,varType)
                        self.FBEnvDict[self.nowPou].type[accumulation] = varType
                        nowPOU = varType
                        nowVar = nextVar
                        continue

                else:
                    result = Helperfunctions.checkWhetherUnknownVar(self, self.FBEnvDict[nowPOU], nowVar)
                    return

            if int(varDim) > 0:
                self.FBEnvDict[self.nowPou].type[ctx.getText()] = "ARRAY[" + varType + "]"
            else:
                self.FBEnvDict[self.nowPou].type[ctx.getText()] = varType

    def visitNumber(self, ctx: STParser.NumberContext):
        if "-" in ctx.getText() and (not "." in ctx.getText()): self.FBEnvDict[self.nowPou].type[ctx.getText()] = "NNUMINT"
        elif not "." in ctx.getText():
            if int(ctx.getText()) == 0:  self.FBEnvDict[self.nowPou].type[ctx.getText()] = "NUMBIT"
            elif int(ctx.getText()) == 1:  self.FBEnvDict[self.nowPou].type[ctx.getText()] = "NUMBIT"
            else: self.FBEnvDict[self.nowPou].type[ctx.getText()] = "PNUMINT"
        else:
            self.FBEnvDict[self.nowPou].type[ctx.getText()] = "NUMREAL"
