from antlr4 import *
from gen.REQLexer import REQLexer
from gen.REQParser import REQParser
from gen.REQVisitor import REQVisitor



class DataExtractor(REQVisitor):
    def __init__(self):
        self.bound = ""
        self.INPUTSTREAM = ""
        self.CONDITION = ""
        self.AMAP = ""

    # Visit a parse tree produced by REQParser#STEPYES.
    def visitREQUIREMENT(self, ctx:REQParser.REQUIREMENTContext):
        self.visit(ctx.bound())

        self.INPUTSTREAM += "( " + self.visit(ctx.inputpart(0)) + " )"

        for i in range(1, len(ctx.inputpart())):
            self.INPUTSTREAM += " , \n" + "( " + self.visit(ctx.inputpart(i)) + " )"

        self.AMAP += "( " + self.visit(ctx.amap(0)) + " )"

        for i in range(1, len(ctx.amap())):
            self.AMAP += " , \n" + "( " + self.visit(ctx.amap(i)) + " )"

        self.CONDITION = self.visit(ctx.expr())

    def visitREPEATNUM(self, ctx:REQParser.REPEATNUMContext):
        return self.visit(ctx.pname()) + " :: " + self.visit(ctx.varname()) + " |-> repeat( " + self.visit(ctx.numdatas()) + " )"

    def visitREPEATBOOL(self, ctx:REQParser.REPEATBOOLContext):
        return self.visit(ctx.pname()) + " :: " + self.visit(ctx.varname()) + " |-> repeat( " + self.visit(ctx.booldatas()) + " )"

    def visitCONCRETENUM(self, ctx:REQParser.CONCRETENUMContext):
        return self.visit(ctx.pname()) + " :: " + self.visit(ctx.varname()) + " |-> " + self.visit(ctx.numdatas())

    def visitCONCRETEBOOL(self, ctx:REQParser.CONCRETEBOOLContext):
        return self.visit(ctx.pname()) + " :: " + self.visit(ctx.varname()) + " |-> " + self.visit(ctx.booldatas())

    def visitEMPTY(self, ctx:REQParser.EMPTYContext): return "empty"

    def visitBOUND(self, ctx: REQParser.BOUNDContext): self.bound = ctx.b.text
    def visitINFBOUND(self, ctx: REQParser.INFBOUNDContext):
        if ctx.b.text != "INF":
            print("Warning : Invalid step size.")
        self.bound = "INF"


    def visitUNARY(self, ctx:REQParser.UNARYContext): return ctx.op.text + " ( " + self.visit(ctx.expr()) +" ) "
    def visitBINARY(self, ctx:REQParser.BINARYContext):
        operation = ctx.op.text
        if operation == "==": operation = "===="

        return self.visit(ctx.expr(0)) + " " + operation + " " + self.visit(ctx.expr(1))
    def visitPARENTHESIS(self, ctx: REQParser.PARENTHESISContext): return "(" + self.visit(ctx.expr()) + ")"


    def visitVARNAME(self, ctx: REQParser.VARNAMEContext):
        if "I[" in ctx.getText():
            return "I[ " + self.visit(ctx.pname()) + " :: " + self.visit(ctx.varname()) + " ]"
        else:
            return self.visit(ctx.pname()) + " :: " + self.visit(ctx.varname())

    def visitVARNAMEINDEX(self, ctx:REQParser.VARNAMEINDEXContext):
        if "I[" in ctx.getText():
            return "I[ " + self.visit(ctx.pname()) + " :: " + self.visit(ctx.varname()) + " { " + ctx.index.text +" } " + " ]"
        else:
            return self.visit(ctx.pname()) + " :: " + self.visit(ctx.varname()) + " { " + ctx.index.text +" } "

    def visitBASICNUM(self, ctx: REQParser.BASICNUMContext): return "# " + ctx.getText()
    def visitBASICTRUE(self, ctx:REQParser.BASICTRUEContext): return "TRUE"
    def visitBASICFALSE(self, ctx: REQParser.BASICFALSEContext): return "FALSE"

    def visitAmap(self, ctx:REQParser.AmapContext): return self.visit(ctx.pname()) + " |-> " + self.visit(ctx.adapter()) + " / " + ctx.denominator.text

    def visitAdapter(self, ctx:REQParser.AdapterContext): return ctx.getText()

    def visitPname(self, ctx:REQParser.PnameContext): return "'" + ctx.getText()

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
        if ctx.getText() == "??":
            return " symbolic "
        else:
            return "[ (" + ctx.getText() + ").Int ]"

    def visitTimeval(self, ctx:REQParser.TimevalContext):
        if ctx.getText() == "??":
            return " symbolic "
        if "ms" == ctx.ms.text.lower():
            return "T[ (" + ctx.number().getText() + ").Int ]"
        elif "s" == ctx.ms.text.lower():
            return "T[ (" + str(int(ctx.number().getText()) * 1000) + ").Int ]"
        else:
            print("Warning : Unsupported time unit used.")
            return "T[ (" + ctx.number().getText() + ").Int ]"

    def truefalseTranslator(self, booleanData):
        if booleanData == "TRUE" or booleanData =="true": return "[(true).Bool]"
        elif booleanData == "??": return " symbolic "
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
"  op cond : ~> PExp . \n" \
"  op appExt : ~> KConfig . \n" \
"  op ranges : ~> Ranges . \n" \
"  ops rawis is os : ~> StreamMap .  \n" \
"  op bound : -> Nat . \n" \
"  op am : ~> AdapterMap . \n" \
"  eq bound = " + visitor.bound + " . \n" \
"  op srange : ~> Nat . \n" \
"  eq srange = srange(ranges, am) . \n" \
"  eq cond = " + visitor.CONDITION + " . \n" \
"  eq rawis = ( \n" + visitor.INPUTSTREAM + \
"              ) . \n" \
"  eq ranges = genRanges(app, bound) . \n"\
"  eq is = genIS(annotateType(rawis, app), ranges) .  \n" \
"  eq os = genEmptyStream(setDiff(collectKeySet(cond), streamKeySet(transformISKey(is)))) .\n" \
"  eq am = ( \n" + visitor.AMAP + \
"           ) . \n" \
"  eq appExt = app maxTime(bound) inStream(is) outStream(os) inVars(streamKeySet(is)) outVars(streamKeySet(os)) LTLCondition(cond). \n" \
"  var CONST : SemanticValue . \n" \
"  vars IS' OS' : StreamMap . \n" \
"endm\n" \
"search [1] \n" \
"appExt =>* constraints(CONST) \n" \
"           outStream(OS') REST:KConfig \n" \
"such that \n" \
"checkSAT((adapt((transformISKey(is), OS'), am) |= genFormula(NOT cond, 0, srange - 1)) AND CONST) . "
        if "symbolic" in visitor.INPUTSTREAM:
            self.symbolicOrconcrete = "symbolic"
        else:
            self.symbolicOrconcrete = "concrete"

        self.BOUND = visitor.bound

    def results(self):
        return self.searchFormat, self.symbolicOrconcrete, self.BOUND


