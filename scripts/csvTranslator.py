from antlr4 import *
from gen.CSVTransLexer import CSVTransLexer
from gen.CSVTransParser import CSVTransParser
from gen.CSVTransVisitor import CSVTransVisitor

class CSVMAKER(CSVTransVisitor):
    def __init__(self, stepsize):
        self.lengthCheck = True

        self.outputDict = {}
        self.inputDict = {}
        self.stepsize = 0

    def visitStart(self, ctx:CSVTransParser.StartContext):
        self.stepsize = self.visit(ctx.outputresult(0))

        self.visit(ctx.intputresult(0))
        for i in range(1, len(ctx.intputresult())): self.visit(ctx.intputresult(i))

        self.visit(ctx.typeresult(0))
        for i in range(1, len(ctx.typeresult())): self.visit(ctx.typeresult(i))

        self.visit(ctx.outputresult(0))
        for i in range(1, len(ctx.outputresult())): self.visit(ctx.outputresult(i))

    def visitPARENTHESIS(self, ctx:CSVTransParser.PARENTHESISContext):
        return self.visit(ctx.outputresult())

    def visitOUTPUTNUM(self, ctx:CSVTransParser.OUTPUTNUMContext):
        if self.lengthCheck:
            return self.visit(ctx.numdatas())

        keyVal = self.visit(ctx.functionblock()) + " :: " + self.visit(ctx.varname())
        self.outputDict[keyVal] = self.visit(ctx.numdatas())

    def visitOUTPUTBOOL(self, ctx:CSVTransParser.OUTPUTBOOLContext):
        if self.lengthCheck:
            return self.visit(ctx.booldatas())

        keyVal = self.visit(ctx.functionblock()) + " :: " + self.visit(ctx.varname())
        self.outputDict[keyVal] = self.visit(ctx.booldatas())

    # Visit a parse tree produced by CSVTransParser#OUTPUTEXPR.
    def visitOUTPUTEXPR(self, ctx: CSVTransParser.OUTPUTEXPRContext):
        if self.lengthCheck:
            return self.visit(ctx.exprs())
        keyVal = self.visit(ctx.functionblock()) + " :: " + self.visit(ctx.varname())
        self.outputDict[keyVal] = self.visit(ctx.exprs())

    def visitINPUTNUM(self, ctx:CSVTransParser.INPUTNUMContext):
        keyVal = self.visit(ctx.functionblock()) + " :: " + self.visit(ctx.varname())
        if not keyVal in self.inputDict:
            self.inputDict[keyVal] = ["0" for i in range(self.stepsize)]
        self.inputDict[keyVal][int(ctx.step.text)] = self.visit(ctx.semanticValuesNum())

    def visitINPUTBOOL(self, ctx:CSVTransParser.INPUTBOOLContext):
        keyVal = self.visit(ctx.functionblock()) + " :: " + self.visit(ctx.varname())
        if not keyVal in self.inputDict:
            self.inputDict[keyVal] = ["False" for i in range(self.stepsize)]
        self.inputDict[keyVal][int(ctx.step.text)] = self.visit(ctx.semanticValuesBoolean())

    def visitTYPEDATA(self, ctx:CSVTransParser.TYPEDATAContext):
        keyVal = self.visit(ctx.functionblock()) + " :: " + self.visit(ctx.varname())
        if not keyVal in self.inputDict:
            if ctx.dataType.text in ['REAL' , 'UINT' , 'SINT' , 'DINT' , 'USINT' , 'UDINT' , 'INT']:
                self.inputDict[keyVal] = ["0" for i in range(self.stepsize)]
            elif ctx.dataType.text in ['TIME']:
                self.inputDict[keyVal] = ["0" for i in range(self.stepsize)]
            else:
                self.inputDict[keyVal] = ["False" for i in range(self.stepsize)]

    def visitFRESHVARPART(self, ctx:CSVTransParser.FRESHVARPARTContext): return

    def visitFunctionblock(self, ctx:CSVTransParser.FunctionblockContext): return ctx.name.text

    def visitNAMELIST(self, ctx:CSVTransParser.NAMELISTContext):
        resultVarName = ctx.name.text
        splited = ctx.getText().split(resultVarName)[1].split(ctx.names.text)[0].split(".")[1:-1]
        for part in splited: resultVarName += " . " +  part.replace("'", "").strip()
        resultVarName += " . " +  ctx.names.text
        return resultVarName

    def visitSINGLENAME(self, ctx:CSVTransParser.SINGLENAMEContext): return ctx.name.text
    def visitSemanticValuesNum(self, ctx:CSVTransParser.SemanticValuesNumContext): return self.visit(ctx.number())
    def visitSemanticValuesBoolean(self, ctx:CSVTransParser.SemanticValuesBooleanContext):
        if ctx.data.text == "TRUE" or ctx.data.text == "true": return "True"
        else: return "False"
    def visitSymbolicValues(self, ctx:CSVTransParser.SymbolicValuesContext):
        keyVal = self.visit(ctx.functionblock()) + " :: " + self.visit(ctx.varname())
        return self.inputDict[keyVal][int(ctx.step.text)]


    def visitNumber(self, ctx: CSVTransParser.NumberContext): return ctx.getText()

    def visitNumdatas(self, ctx:CSVTransParser.NumdatasContext):
        if self.lengthCheck:
            self.lengthCheck = False
            return len(ctx.semanticValuesNum())

        resultDatas = []
        resultDatas.append(self.visit(ctx.semanticValuesNum(0)))

        for i in range(1, len(ctx.semanticValuesNum())):
            resultDatas.append(self.visit(ctx.semanticValuesNum(i)))

        return resultDatas

    def visitBooldatas(self, ctx:CSVTransParser.BooldatasContext):
        if self.lengthCheck:
            self.lengthCheck = False
            return len(ctx.semanticValuesBoolean())

        resultDatas = []
        resultDatas.append(self.visit(ctx.semanticValuesBoolean(0)))

        for i in range(1, len(ctx.semanticValuesBoolean())):
            resultDatas.append(self.visit(ctx.semanticValuesBoolean(i)))

        return resultDatas

    def visitExprs(self, ctx: CSVTransParser.ExprsContext):
        if self.lengthCheck:
            self.lengthCheck = False
            return len(ctx.expr())

        resultDatas = []
        try:
            resultDatas.append(eval(self.visit(ctx.expr(0))))
        except:
            resultDatas.append("EVAL\nERROR")


        for i in range(1, len(ctx.expr())):
            try:
                resultDatas.append(eval(self.visit(ctx.expr(i))))
            except:
                resultDatas.append("EVAL\nERROR")

        return resultDatas


    def visitPARENTHESISEXPR(self, ctx: CSVTransParser.PARENTHESISEXPRContext): return "(" + self.visit(ctx.expr()) + " )"
    def visitNEGATIVEOPERATION(self, ctx: CSVTransParser.NEGATIVEOPERATIONContext): return "-" + self.visit(ctx.expr())
    def visitNOTOPERATION(self, ctx: CSVTransParser.NOTOPERATIONContext): return "not " + self.visit(ctx.expr())
    def visitEXPONENTIAL(self, ctx: CSVTransParser.EXPONENTIALContext):
        return self.visit(ctx.expr(0)) + " " + "**" + " (" + self.visit(ctx.expr(1)) + ")"
    def visitNUMERICALOPERATION(self, ctx: CSVTransParser.NUMERICALOPERATIONContext):
        return self.visit(ctx.expr(0)) + " " + ctx.op.text + " " + self.visit(ctx.expr(1))
    def visitCOMPARISON(self, ctx: CSVTransParser.COMPARISONContext):
        return self.visit(ctx.expr(0)) + " " + ctx.op.text + " " + self.visit(ctx.expr(1))
    def visitLOGICALBINARY(self, ctx: CSVTransParser.LOGICALBINARYContext):
        return self.visit(ctx.expr(0)) + " " + ctx.op.text.lower() + " " + self.visit(ctx.expr(1))



class CSVTranslator:
    def __init__(self, testOut, stepsize):
        input_stream = FileStream(testOut)
        lexer = CSVTransLexer(input_stream)
        tokens = CommonTokenStream(lexer)
        parser = CSVTransParser(tokens)
        tree = parser.start()
        self.visitor = CSVMAKER(stepsize)
        self.visitor.visit(tree)
        self.maxLength = self.visitor.stepsize

    def results(self):
        return self.visitor.inputDict, self.visitor.outputDict, self.maxLength
"""
import os
import time

start = time.time()
test = CSVTranslator("PMSEmulator-req1_INF.log", 20)
print(test.results())
print(time.time() - start)

test = CSVTranslator("../apps/MA-example1.log", 20)
print(test.results())
print(time.time() - start)



import os
import time
file_list = os.listdir("logs")
print(file_list)

for files in file_list:
    start = time.time()
    testOut = "logs/" + files
    print(testOut)
    test = CSVTranslator(testOut, 20)
    print(test.results())
    print(time.time() - start)

"""








