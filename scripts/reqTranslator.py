from antlr4 import *
from gen.REQLexer import REQLexer
from gen.REQParser import REQParser
from gen.REQVisitor import REQVisitor



class DataExtractor(REQVisitor):
    def __init__(self):
        self.stepsize = ""
        self.INPUTSTREAM = ""
        self.CONDITION = ""

    # Visit a parse tree produced by REQParser#STEPYES.
    def visitSTEPYES(self, ctx:REQParser.STEPYESContext):
        self.visit(ctx.steppart())

        self.INPUTSTREAM += "( " + self.visit(ctx.inputpart(0)) + " )"

        for i in range(1, len(ctx.inputpart())):
            self.INPUTSTREAM += " , \n" + "( " + self.visit(ctx.inputpart(i)) + " )"

        self.CONDITION = self.visit(ctx.expr())


    # Visit a parse tree produced by REQParser#STEPNO.
    def visitSTEPNO(self, ctx:REQParser.STEPNOContext):
        self.INPUTSTREAM += "( " + self.visit(ctx.inputpart(0)) + " )"

        for i in range(1, len(ctx.inputpart())):
            self.INPUTSTREAM += " , \n" + "( " + self.visit(ctx.inputpart(i)) + " )"

        self.CONDITION = self.visit(ctx.expr())

    def visitSYMBOLIC(self, ctx:REQParser.SYMBOLICContext):
        return self.visit(ctx.functionblock()) + " :: " + self.visit(ctx.varname()) + " |-> " + "symbolic"

    def visitREPEATNUM(self, ctx:REQParser.REPEATNUMContext):
        return self.visit(ctx.functionblock()) + " :: " + self.visit(ctx.varname()) + " |-> repeat( " + self.visit(ctx.numdatas()) + " )"

    def visitREPEATBOOL(self, ctx:REQParser.REPEATBOOLContext):
        return self.visit(ctx.functionblock()) + " :: " + self.visit(ctx.varname()) + " |-> repeat( " + self.visit(ctx.booldatas()) + " )"

    def visitCONCRETENUM(self, ctx:REQParser.CONCRETENUMContext):
        return self.visit(ctx.functionblock()) + " :: " + self.visit(ctx.varname()) + " |-> " + self.visit(ctx.numdatas())

    def visitCONCRETEBOOL(self, ctx:REQParser.CONCRETEBOOLContext):
        return self.visit(ctx.functionblock()) + " :: " + self.visit(ctx.varname()) + " |-> " + self.visit(ctx.booldatas())

    def visitEMPTY(self, ctx:REQParser.EMPTYContext): return "empty"

    def visitSTEPPPARTNUM(self, ctx: REQParser.STEPPPARTNUMContext): self.stepsize = ctx.stepsize.text
    def visitSTEPPARTID(self, ctx: REQParser.STEPPARTIDContext):
        if ctx.stepsize.text != "INF":
            print("Warning : Step size is not correct. Tool assumes step size is infinite")
        self.stepsize = "INF"


    def visitUNARY(self, ctx:REQParser.UNARYContext): return ctx.op.text + " ( " + self.visit(ctx.expr()) +" ) "
    def visitBINARY(self, ctx:REQParser.BINARYContext):
        operation = ctx.op.text
        if operation == "==": operation = "===="

        return self.visit(ctx.expr(0)) + " " + operation + " " + self.visit(ctx.expr(1))
    def visitPARENTHESIS(self, ctx: REQParser.PARENTHESISContext): return "(" + self.visit(ctx.expr()) + ")"


    def visitVARNAME(self, ctx: REQParser.VARNAMEContext):
        if "I[" in ctx.getText():
            return "I[ " + self.visit(ctx.functionblock()) + " :: " + self.visit(ctx.varname()) + " ]"
        else:
            return self.visit(ctx.functionblock()) + " :: " + self.visit(ctx.varname())

    def visitVARNAMEINDEX(self, ctx:REQParser.VARNAMEINDEXContext):
        if "I[" in ctx.getText():
            return "I[ " + self.visit(ctx.functionblock()) + " :: " + self.visit(ctx.varname()) + " { " + ctx.index.text +" } " + " ]"
        else:
            return self.visit(ctx.functionblock()) + " :: " + self.visit(ctx.varname()) + " { " + ctx.index.text +" } "

    def visitBASICNUM(self, ctx: REQParser.BASICNUMContext): return "# " + ctx.getText()
    def visitBASICTRUE(self, ctx:REQParser.BASICTRUEContext): return "TRUE"
    def visitBASICFALSE(self, ctx: REQParser.BASICFALSEContext): return "FALSE"

    def visitFunctionblock(self, ctx:REQParser.FunctionblockContext): return "'" + ctx.getText()

    def translator(self, text, milestone, behavior):
        returnPart = ""

        if milestone in text:
            splited = text.split(milestone)
            returnPart += behavior(splited[0]) + " "

            for i in range(1, len(splited)):
                returnPart += " " + milestone + " " + behavior(splited[i])

        else:
            returnPart += behavior(text)

        return returnPart

    # Visit a parse tree produced by REQParser#varname.
    def visitVarname(self, ctx:REQParser.VarnameContext):
        returnPart =  self.translator(ctx.getText().replace("(", "").replace(")", ""), ".", lambda x: "'" + x)
        if "." in ctx.getText(): returnPart = " ( " + returnPart + " ) "
        return returnPart


    def visitNUMDATA(self, ctx: REQParser.NUMDATAContext):
        returnPart = ""

        if "," in ctx.getText():
            splited = ctx.getText().split(",")
            returnPart += self.visit(ctx.number(0))

            for i in range(1, len(splited)):
                returnPart += ", " + self.visit(ctx.number(i))

        else:
            returnPart += self.visit(ctx.number(0))

        return returnPart


    def visitTIMEDATA(self, ctx: REQParser.TIMEDATAContext):
        returnPart = ""

        if "," in ctx.getText():
            splited = ctx.getText().split(",")
            returnPart += self.visit(ctx.timeval(0))

            for i in range(1, len(splited)):
                returnPart += ", " + self.visit(ctx.timeval(i))

        else:
            returnPart += self.visit(ctx.timeval(0))

        return returnPart


    def visitNumber(self, ctx:REQParser.NumberContext):
        return "[ (" + ctx.getText() + ").Int ]"

    def visitTimeval(self, ctx:REQParser.TimevalContext):
        if "ms" == ctx.ms.text.lower():
            return "T[ (" + ctx.number().getText() + ").Int ]"
        elif "s" == ctx.ms.text.lower():
            return "T[ (" + str(int(ctx.number().getText()) * 1000) + ").Int ]"
        else:
            print("Warning : Unsupported time unit used. Tool interpret as 'MS'")
            return "T[ (" + ctx.number().getText() + ").Int ]"

    def truefalseTranslator(self, booleanData):
        if booleanData == "TRUE" or booleanData =="true": return "[(true).Bool]"
        else: return "[(false).Bool]"

    def visitBooldatas(self, ctx:REQParser.BooldatasContext):
        return self.translator(ctx.getText(), ",", lambda x: self.truefalseTranslator(x))


class ReqFileTranslator:
    def __init__(self, fullPathOfVerifFile):
        input_stream = FileStream(fullPathOfVerifFile)
        lexer = REQLexer(input_stream)
        tokens = CommonTokenStream(lexer)
        parser = REQParser(tokens)
        tree = parser.start()

        visitor = DataExtractor()
        visitor.visit(tree)


        self.searchFormat = "mod MC is \n" \
                       "  inc APP . \n" \
                       "  op COND : ~> PExp . \n" \
                       "  op APPEXT : ~> KConfig . \n" \
                       "  ops RAWIS IS OS : ~> StreamMap .  \n" \
                       "  op BOUND : -> Nat . \n" \
                       "  eq BOUND = " + visitor.stepsize + " . \n" \
                                                                 "  eq COND = \n" \
                                                                 "  NOT ( " + visitor.CONDITION + \
                       "       ) .\n" \
                       "  eq RAWIS = ( \n" + visitor.INPUTSTREAM + \
                       "              ) . \n" \
                       "  eq IS = genIS(RAWIS) .  \n" \
                       "  eq OS = genOS(COND, IS) .\n" \
                       "  eq APPEXT = replaceStreams(APP , cycleCounterBound(BOUND) inputCollector(IS) inputStreamSpec(RAWIS) LTLContainer(COND) inStream(IS) outStream(OS)) .\n" \
                       "endm\n" \
                       "search [1] \n" \
                       "APPEXT =>* LTLResult(RESULT:checkSATResult) constraints(CONST:SemanticValue) REST:KConfig    \n" \
                       "outStream(STRMAP:StreamMap) such that \n" \
                       "RESULT:checkSATResult =/= UNSAT /\ \n" \
                       "KTPS:KeyTypePairSet := genKeyTypePair(RAWIS, APP) ."

        if "symbolic" in visitor.INPUTSTREAM:
            self.symbolicOrconcrete = "symbolic"
        else:
            self.symbolicOrconcrete = "concrete"

        self.STEPSIZE = visitor.stepsize

    def results(self):
        return self.searchFormat, self.symbolicOrconcrete, self.STEPSIZE

