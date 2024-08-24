from antlr4 import *
from gen.DCLLexer import DCLLexer
from gen.DCLParser import DCLParser
from gen.DCLVisitor import DCLVisitor

import copy
from dataFormat import VarFormat

class DCLDATAEXTRACTOR(DCLVisitor):
    def __init__(self):
        self.cycletime = 0
        self.enumDict = dict()
        self.bitfieldDict = dict()

        self.mainprograms = list()
        self.subprograms = list()
        self.udfbs = list()
        self.structures = list()

        self.varENV = list()


    def visitStart(self, ctx: DCLParser.StartContext):
        for i in range(len(ctx.apart())): self.visit(ctx.apart(i))
        for i in range(len(ctx.tpart())): self.visit(ctx.tpart(i))
        for i in range(len(ctx.ppart())): self.visit(ctx.ppart(i))
        for i in range(len(ctx.vpart())): self.visit(ctx.vpart(i))

    def visitLocal(self, ctx: DCLParser.LocalContext):
        for i in range(len(ctx.vpart())): self.visit(ctx.vpart(i))

    def visitCYCLEPART(self, ctx:DCLParser.CYCLEPARTContext):
        if int(ctx.check.text) == 1:
            self.cycletime = int(int(ctx.cycletime.text) / 1000)

    def visitENUMPART(self, ctx:DCLParser.ENUMPARTContext):
        self.enumDict[ctx.enumname.text] = self.visit(ctx.varnamelist())

    def visitBITFIELDPART(self, ctx:DCLParser.BITFIELDPARTContext):
        self.bitfieldDict[ctx.bitfieldname.text] = ( ctx.fieldtype.text, self.visit(ctx.varnamelist()) )

    def visitMAINPARGRAM(self, ctx:DCLParser.MAINPARGRAMContext):
        if "pStartup" == ctx.name.text or 'pShutDown' == ctx.name.text: return
        period, phase, switch = 1, 1, True

        try:
            period = int(ctx.period.text)
            phase = int(ctx.phase.text)
        except: pass

        try:
            switch = ctx.switch.text
        except: pass

        if switch: self.mainprograms.append((ctx.name.text, period, phase))

    def visitSUBPROGRAM(self, ctx: DCLParser.SUBPROGRAMContext): self.subprograms.append(ctx.name.text)
    def visitUDFB(self, ctx:DCLParser.UDFBContext): self.udfbs.append(ctx.name.text)
    def visitSTRUCTURE(self, ctx:DCLParser.STRUCTUREContext): self.structures.append(ctx.name.text)

    def decideVarUsageType(self, usageType):
        if (usageType == '0'): return '##PRIV'
        elif (usageType == '8'): return '##IN'
        elif (usageType == '16'): return '##OUT'
        elif (usageType == '72'): return '##INOUT'
        else: return '##GLOBAL'


    def makeVarEnv(self, position, name, type, dim, useage, init):
        if position == "G,":
            self.varENV.append(VarFormat(name, type, dim, init, "##GLOBAL"))
        else:
            self.varENV.append(VarFormat(name, type, dim, init, self.decideVarUsageType(useage)))

    def visitVARDECLINITNUM(self, ctx: DCLParser.VARDECLINITNUMContext):
        try:
            self.makeVarEnv(ctx.position.text, ctx.variablename.text, ctx.typename.text, ctx.dimension.text, ctx.varUsageType.text, self.visit(ctx.numdatas()))
            return
        except:
            self.makeVarEnv(ctx.position.text, ctx.variablename.text, ctx.typename.text, ctx.dimension.text, ctx.varUsageType.text,list())
            return

    def visitVARDECLINITBOOL(self, ctx: DCLParser.VARDECLINITBOOLContext):
        try:
            self.makeVarEnv(ctx.position.text, ctx.variablename.text, ctx.typename.text, ctx.dimension.text, ctx.varUsageType.text, self.visit(ctx.booldatas()))
            return
        except:
            self.makeVarEnv(ctx.position.text, ctx.variablename.text, ctx.typename.text, ctx.dimension.text, ctx.varUsageType.text, list())
            return

    def visitVARDECLTIME(self, ctx:DCLParser.VARDECLTIMEContext):
        try:
            self.makeVarEnv(ctx.position.text, ctx.variablename.text, ctx.typename.text, ctx.dimension.text, ctx.varUsageType.text, self.visit(ctx.timedatas()))
            return
        except:
            self.makeVarEnv(ctx.position.text, ctx.variablename.text, ctx.typename.text, ctx.dimension.text, ctx.varUsageType.text, list())
            return

    def visitUSELESSVPART(self, ctx:DCLParser.USELESSVPARTContext): return ""
    def visitVarnamelist(self, ctx:DCLParser.VarnamelistContext): return ctx.getText()
    def visitNumdatas(self, ctx:DCLParser.NumdatasContext): return ctx.getText()
    def visitBooldatas(self, ctx:DCLParser.BooldatasContext): return ctx.getText()
    def visitTimedatas(self, ctx: DCLParser.TimedatasContext): return ctx.getText()

class dclStappMaker:
    def __init__(self):
        self.visitor = DCLDATAEXTRACTOR()

    def returnPrograms(self): return copy.deepcopy( list(map(lambda x: x[0], self.visitor.mainprograms))  )
    def returnSubprograms(self): return copy.deepcopy(self.visitor.subprograms)
    def returnUdfbs(self): return copy.deepcopy(self.visitor.udfbs)
    def returnStructures(self): return copy.deepcopy(self.visitor.structures)

    def makeStGlobalConfig(self, k5pfile):
        input_stream = FileStream(k5pfile)
        lexer = DCLLexer(input_stream)
        tokens = CommonTokenStream(lexer)
        parser = DCLParser(tokens)
        tree = parser.start()
        self.visitor.visit(tree)
        return self.makeStapp()

    def makeStLocalVarDecl(self, filePath):
        input_stream = FileStream(filePath)
        lexer = DCLLexer(input_stream)
        tokens = CommonTokenStream(lexer)
        parser = DCLParser(tokens)
        tree = parser.local()
        self.visitor.visit(tree)
        return self.makeStVars()


    def makeStPrograms(self):
        mains = ""
        for program in self.visitor.mainprograms:
            mains += program[0] + "([" + str(program[1]) + "," + str(program[2]) + "]) ;;\n"
        return mains

    def makeStSubPrograms(self):
        subs = ""
        for subprogram in self.visitor.subprograms:
            subs += subprogram + " ;;\n"
        return subs

    def makeStUDFBs(self):
        fbs = ""
        for fb in self.visitor.udfbs:
            fbs += fb + " ;;\n"
        return fbs

    def makeStSTRUCTURES(self):
        strs = ""
        for str in self.visitor.structures:
            strs += str + " ;;\n"
        return strs

    def makeStENUMS(self):
        ens = ""
        for enumType in self.visitor.enumDict.keys():
            ens += enumType + " : " + self.visitor.enumDict[enumType] + " ;\n"
        return ens


    def makeStBITFIELDS(self):
        bits = ""
        for bitType in self.visitor.bitfieldDict.keys():
            bits += bitType + " : " + self.visitor.bitfieldDict[bitType][0] + " : " + self.visitor.bitfieldDict[bitType][1] + " ;\n"
        return bits

    def makeArrayType(self, type, dim):
        if int(dim) == 0: return type
        else: return "ARRAY [ 0 .. " + str(int(dim) - 1) + " ] OF " + type

    def makeStVars(self, globalSwitch=False):
        if not globalSwitch:
            varPriv = self.makeStVarBasedOnType(list(filter(lambda x: x.useType == "##PRIV", self.visitor.varENV)), "VAR", "END_VAR")
            varIn = self.makeStVarBasedOnType(list(filter(lambda x: x.useType == "##IN", self.visitor.varENV)), "VAR_INPUT", "END_VAR")
            varInout = self.makeStVarBasedOnType(list(filter(lambda x: x.useType == "##INOUT", self.visitor.varENV)), "VAR_IN_OUT", "END_VAR")
            varOut = self.makeStVarBasedOnType(list(filter(lambda x: x.useType == "##OUT", self.visitor.varENV)), "VAR_OUTPUT", "END_VAR")
            return varPriv + varIn + varInout + varOut

        else:
            varGlobal = self.makeStVarBasedOnType(list(filter(lambda x: x.useType == "##GLOBAL", self.visitor.varENV)), "VAR_GLOBAL", "END_VAR")

            return varGlobal

    def makeStVarBasedOnType(self, vars, upperCap, bottomCap):

        result = upperCap + "\n"

        for var in vars:
            if len(var.init) > 0:
                result += var.name + " : " + self.makeArrayType(var.type, var.dim) + " := " + str(var.init) + " ;\n"
            else:
                result += var.name + " : " + self.makeArrayType(var.type, var.dim) + " ;\n"

        result += bottomCap + "\n\n"

        if len(vars) > 0: return result
        else: return ""



    def makeStapp(self):
        programConfig = ""
        programConfig += "PROGRAMS\n" + self.makeStPrograms() + "PROGRAMSEND\n"
        programConfig += "CycleTime: " + str(self.visitor.cycletime) + "\n"

        typeConfig = self.makeStENUMS() + "\n" + self.makeStBITFIELDS() + "\n"

        globalVarConfig = self.makeStVars(globalSwitch=True)

        return programConfig, typeConfig, globalVarConfig

