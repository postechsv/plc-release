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


class stTranslate(STVisitor):
    def __init__(self, totalEnv):
        self.totalEnv = deepcopy(totalEnv)
        self.programListMaude = ""
        self.nowPou = ""
        self.FBEnv = deepcopy(self.totalEnv.FBEnvDict)
        self.switch = True

    def visitStapp(self, ctx:STParser.StappContext):
        self.programListMaude = self.visit(ctx.config())

        for i in range(len(ctx.pros())):
            self.nowPou, todo = self.visit(ctx.pros(i))
            self.visit(todo)

        for i in range(len(ctx.subs())):
            self.nowPou, todo = self.visit(ctx.subs(i))
            self.visit(todo)
        for i in range(len(ctx.udfbs())):
            self.nowPou, todo = self.visit(ctx.udfbs(i))
            self.visit(todo)

        for i in range(len(ctx.funcs())):
            self.nowPou, todo = self.visit(ctx.funcs(i))
            self.visit(todo)

    def visitConfig(self, ctx:STParser.ConfigContext):
        return self.visit(ctx.programSection())

    def visitProgramSection(self, ctx: STParser.ProgramSectionContext):
        programSection = ""
        for i in range(len(ctx.aProgram())):
            programSection += self.visit(ctx.aProgram(i))
        return "PROGRAMS\n" + programSection + "PROGRAMSEND\n"

    def visitAProgram(self, ctx:STParser.AProgramContext):
        return "'" + ctx.name.text + " ;; \n"

    def visitCycleTime(self, ctx:STParser.CycletimeContext):
        return "CycleTime: #  " + ctx.cycle.text + "\n"

    def visitPros(self, ctx:STParser.ProsContext): return ctx.name.text, ctx.program()
    def visitSubs(self, ctx:STParser.SubsContext): return ctx.name.text, ctx.program()
    def visitUdfbs(self, ctx:STParser.UdfbsContext): return ctx.name.text, ctx.program()
    def visitFuncs(self, ctx:STParser.FuncsContext): return ctx.name.text, ctx.program()

    def visitProgram(self, ctx:STParser.ProgramContext):
        numOfstatements = len(ctx.statement())
        resultString = ""
        for i in range(numOfstatements):
            resultString += self.visit(ctx.statement(i))

        if numOfstatements == 0:
            return "skip ;"

        self.FBEnv[self.nowPou].maudeCode = resultString

    def visitStatementList(self, ctx:STParser.StatementListContext):
        numoflines = len(ctx.statement())
        resultString = ""
        for i in range(numoflines): resultString += self.visit(ctx.statement(i))
        return resultString

    def visitAssign(self, ctx:STParser.AssignContext):
        leftKeep = self.visit(ctx.expr(0))
        left, right = Helperfunctions.insertExplicitConversion(self.FBEnv[self.nowPou].type,
                                                               ctx.expr(0).getText(),
                                                               leftKeep,
                                                               ctx.expr(1).getText(),
                                                               self.visit(ctx.expr(1)),
                                                               self.FBEnv[self.nowPou].type[ctx.expr(0).getText()])
        return leftKeep + " := " + right + " ; \n"

    def visitUSERDEFINEFUNCALL(self, ctx:STParser.USERDEFINEFUNCALLContext):
        return self.visit(ctx.varname()) + " ( " + self.visit(ctx.argumentlist()) + " ) ; \n"

    def visitSTANDARDFUNCALL(self, ctx:STParser.STANDARDFUNCALLContext):
        if ctx.funcall.text == "WAIT_TIME":
            return "WAITTIME" + " ( " + self.visit(ctx.argumentlist()) + " ) ; \n"
        else:
            return ctx.funcall.text + " ( " + self.visit(ctx.argumentlist()) + " ) ; \n"


    def visitFORSTATEMENTWITHBY(self, ctx:STParser.FORSTATEMENTWITHBYContext):
        return "FOR " + str(self.visit(ctx.assign())).replace(" ; \n", "") + " TO " + self.visit(ctx.expr(0)) + " BY " + self.visit(ctx.expr(1)) + " DO \n" \
        + self.visit(ctx.statementList()) + " ENDFOR ; \n"

    def visitFORSTATEMENT(self, ctx:STParser.FORSTATEMENTContext):
        return "FOR " + str(self.visit(ctx.assign())).replace(" ; \n", "")  + " TO " + self.visit(ctx.expr()) + " DO \n" \
        + self.visit(ctx.statementList()) + " ENDFOR ; \n"

    def visitWHILESTATEMENT(self, ctx:STParser.WHILESTATEMENTContext):
        return "WHILE " + self.visit(ctx.expr()) + " DO \n " + self.visit(ctx.statementList()) + "ENDWHILE ; \n"

    def visitREPEATSTATEMENT(self, ctx:STParser.REPEATSTATEMENTContext):
        print("Repeat statement is not supported")
        self.switch = False
        return "REPEAT " + self.visit(ctx.statementList()) + " UNTIL " + self.visit(ctx.expr()) + "ENDREPEAR ; \n"

    def visitIFSTATEMENT(self, ctx:STParser.IFSTATEMENTContext):
        ifPart = "IF " + self.visit(ctx.expr(0)) + " THEN \n" + self.visit(ctx.statementList(0))
        elifCounter = 0
        elifPart = ""
        elsePart = ""
        i = 4
        while i < ctx.getChildCount() - 1:
            if str(ctx.getChild(i)).lower() == "elsif":
                i += 4
                elifPart += "ELSIF " +  self.visit(ctx.expr(1 + elifCounter)) + " THEN \n" + self.visit(ctx.statementList(1 + elifCounter))
                elifCounter += 1
            elif str(ctx.getChild(i)).lower() == "else":
                i += 2
                elsePart += "ELSE \n" + self.visit(ctx.statementList(1 + elifCounter))

        return ifPart + elifPart + elsePart + "ENDIF ; \n"

        # Visit a parse tree produced by STRATONSRCParser#CASESTATEMENT.
    def visitCASESTATEMENT(self, ctx: STParser.CASESTATEMENTContext):
        resultString = "CASE " + self.visit(ctx.expr()) + " OF \n"
        for i in range(len(ctx.caseoptionline())): resultString += self.visit(ctx.caseoptionline(i))
        resultString += "ENDCASE ; \n"
        return resultString

        # Visit a parse tree produced by STRATONSRCParser#CASESTATEMENTWITHELSE.
    def visitCASESTATEMENTWITHELSE(self, ctx: STParser.CASESTATEMENTWITHELSEContext):
        resultString = "CASE " + self.visit(ctx.expr()) + " OF \n"
        for i in range(len(ctx.caseoptionline())): resultString += self.visit(ctx.caseoptionline(i))
        resultString += "ELSE \n" + self.visit(ctx.statementList())
        resultString += "ENDCASE ; \n"
        return resultString

    def visitCaseoption(self, ctx:STParser.CaseoptionContext):
        if "..." in ctx.getText():
            return "@ " + self.visit(ctx.primary(0)) + " ... " + self.visit(ctx.primary(1))
        elif "," in ctx.getText():
            resultString = self.visit(ctx.primary(0))
            for i in range(1, len(ctx.primary())):
                resultString += " , " + self.visit(ctx.primary(i))
            return "@ " + resultString
        else:
            return "@ " + self.visit(ctx.primary(0))


    def visitCaseoptionline(self, ctx:STParser.CaseoptionlineContext):
        return self.visit(ctx.caseoption()) + " : \n" + self.visit(ctx.statementList())

    def visitOpwithequal(self, ctx:STParser.OpwithequalContext):
        left, right = Helperfunctions.insertExplicitConversion(self.FBEnv[self.nowPou].type,
                                                               ctx.expr(0).getText(),
                                                               self.visit(ctx.expr(0)),
                                                               ctx.expr(1).getText(),
                                                               self.visit(ctx.expr(1)),
                                                               self.FBEnv[self.nowPou].type[ctx.expr(0).getText()])
        return left + " " + ctx.op.text + "= " + right + " ; \n"

    def visitExitstatement(self, ctx:STParser.ExitstatementContext):
        print("exit statement is not supported")
        exit()

    def visitReturnstatement(self, ctx:STParser.ReturnstatementContext):
        return "return ; \n"

    def visitEmptystatement(self, ctx:STParser.EmptystatementContext):
        return "skip ; \n"

    def visitLOGICALBINARY(self, ctx:STParser.LOGICALBINARYContext):
        left, right = Helperfunctions.insertExplicitConversion(self.FBEnv[self.nowPou].type,
                                                               ctx.expr(0).getText(),
                                                               self.visit(ctx.expr(0)),
                                                               ctx.expr(1).getText(),
                                                               self.visit(ctx.expr(1)),
                                                               self.FBEnv[self.nowPou].type[ctx.getText()])
        operation = ctx.op.text.lower()
        if operation == "and": operation = " AND "
        elif operation == "xor": operation = " XOR "
        else: operation = " OR "
        return left + operation + right

    def visitNEGATIVEOPERATION(self, ctx:STParser.NEGATIVEOPERATIONContext):
        return " - " + self.visit(ctx.expr())

    def visitPARENTHESIS(self, ctx:STParser.PARENTHESISContext):
        return " ( " + self.visit(ctx.expr()) + " ) "

    def visitFUNCTIONCALL(self, ctx:STParser.FUNCTIONCALLContext):
        return ctx.op.text.replace("_", "") + " ( " + self.visit(ctx.argumentlist()) + " ) "

    def visitNOTOPERATION(self, ctx:STParser.NOTOPERATIONContext):
        return " NOT " + self.visit(ctx.expr())

    def visitNUMERICALOPERATION(self, ctx:STParser.NUMERICALOPERATIONContext):
        operation = ctx.op.text
        if ctx.op.text == "MOD":
            operation = "%"
        left, right = Helperfunctions.insertExplicitConversion(self.FBEnv[self.nowPou].type,
                                                               ctx.expr(0).getText(),
                                                               self.visit(ctx.expr(0)),
                                                               ctx.expr(1).getText(),
                                                               self.visit(ctx.expr(1)),
                                                               self.FBEnv[self.nowPou].type[ctx.getText()])
        return left + " " + operation + " " + right

    def visitEXPONENTIAL(self, ctx:STParser.EXPONENTIALContext):
        left, right = Helperfunctions.insertExplicitConversion(self.FBEnv[self.nowPou].type,
                                                               ctx.expr(0).getText(),
                                                               self.visit(ctx.expr(0)),
                                                               ctx.expr(1).getText(),
                                                               self.visit(ctx.expr(1)),
                                                               self.FBEnv[self.nowPou].type[ctx.getText()])
        return left + " " + ctx.op.text + " ( " + right + " ) "

    def visitCOMPARISON(self, ctx:STParser.COMPARISONContext):
        operation = ctx.op.text
        if ctx.op.text == "=":
            operation = "===="

        left, right = Helperfunctions.insertExplicitConversion(self.FBEnv[self.nowPou].type,
                                                               ctx.expr(0).getText(),
                                                               self.visit(ctx.expr(0)),
                                                               ctx.expr(1).getText(),
                                                               self.visit(ctx.expr(1)),
                                                               self.FBEnv[self.nowPou].type[ctx.getText()])
        return left + " " + operation + " " + right

    def visitARRAYEXPR(self, ctx:STParser.ARRAYEXPRContext):
        return self.visit(ctx.varname()) + " [ " + self.visit(ctx.expr()) + " ] "

    def visitONETOONE(self, ctx:STParser.ONETOONEContext):
        return "( '" + ctx.varname().getText() + " <:= " + self.visit(ctx.expr()) + " )"

    def visitONTTOONPARENTHESIS(self, ctx:STParser.ONTTOONPARENTHESISContext):
        return " ( " +  self.visitChildren(ctx) + " ) "

    def visitONETOONELIST(self, ctx:STParser.ONETOONELISTContext):
        numofargs = len(ctx.assignargument())
        resultString = self.visit(ctx.assignargument(0))
        for i in range(1, numofargs): resultString += " , " + self.visit(ctx.assignargument(i))
        return resultString

    def visitARGLIST(self, ctx:STParser.ARGLISTContext):
        numofargs = len(ctx.expr())
        resultString = self.visit(ctx.expr(0))
        for i in range(1, numofargs): resultString += " , " + self.visit(ctx.expr(i))
        return resultString

    def visitTIMEPRIMARY(self, ctx:STParser.TIMEPRIMARYContext):
        if ctx.ms.text.lower() == "ms": unit = "ms"
        elif ctx.ms.text.lower() == "s": unit = "s"
        else:
            print("UNKNOWN TIMER UNIT --> " + ctx.ms.text)
            self.switch = False
            unit = ctx.ms.text.lower()

        return "T" + self.visit(ctx.number()) + " " + unit

    def visitBOOLTRUE(self, ctx:STParser.BOOLTRUEContext): return "TRUE"
    def visitBOOLFALSE(self, ctx:STParser.BOOLFALSEContext): return "FALSE"

    def visitVarname(self, ctx:STParser.VarnameContext):
        if "." in ctx.getText():
            splited = ctx.getText().split(".")
            processed = list(map(lambda x: "'" + x, splited))
            processedCode = " . ".join(processed)

            for i in range(1, len(splited) + 1):
                rawCode = ".".join(splited[:i])

                if self.FBEnv[self.nowPou].type[rawCode] == "NUMBIT":
                    bitfieldIndex = ""
                    if splited[i - 1].isdigit(): bitfieldIndex = splited[i - 1]
                    else:
                        bitfieldType = self.FBEnv[self.nowPou].type[".".join(splited[:(i-1)])]
                        for index, value in enumerate(self.totalEnv.bitDict[bitfieldType].vars):
                            if value == splited[i - 1]: bitfieldIndex = str(index)
                    processedCode = " . ".join(processed[:(i-1)]) + " . '" + bitfieldIndex

            return processedCode

        else:
            if self.FBEnv[self.nowPou].type[ctx.getText()] in (self.totalEnv.enumDict.keys()) and \
                    ctx.getText() in self.totalEnv.enumDict[self.FBEnv[self.nowPou].type[ctx.getText()]].vars:
                resultString = "'" + self.FBEnv[self.nowPou].type[ctx.getText()] + " # '" + ctx.getText()
            else: resultString = "'" + ctx.getText()


        return resultString

    def visitNumber(self, ctx:STParser.NumberContext):
        return "# " + ctx.getText()

    def visitENUMPRIMARY(self, ctx: STParser.ENUMPRIMARYContext):
        return "'" + ctx.ID(0).getText() + " # " + "'" + ctx.ID(1).getText()

    def visitSPECIALTOKEN(self, ctx: STParser.SPECIALTOKENContext):
        return ctx.getText()


    def visitTimeval(self, ctx: STParser.TimevalContext):
        if ctx.ms.text.lower() == "ms": unit = "ms"
        elif ctx.ms.text.lower() == "s": unit = "s"
        else:
            print("UNKNOWN TIMER UNIT --> " + ctx.ms.text)
            self.switch = False
            unit = ctx.ms.text.lower()

        return "T" + self.visit(ctx.timesize.text) + " " + unit
