# Generated from REQ.g4 by ANTLR 4.9.1
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .REQParser import REQParser
else:
    from REQParser import REQParser

# This class defines a complete listener for a parse tree produced by REQParser.
class REQListener(ParseTreeListener):

    # Enter a parse tree produced by REQParser#REQUIREMENT.
    def enterREQUIREMENT(self, ctx:REQParser.REQUIREMENTContext):
        pass

    # Exit a parse tree produced by REQParser#REQUIREMENT.
    def exitREQUIREMENT(self, ctx:REQParser.REQUIREMENTContext):
        pass


    # Enter a parse tree produced by REQParser#REPEATNUM.
    def enterREPEATNUM(self, ctx:REQParser.REPEATNUMContext):
        pass

    # Exit a parse tree produced by REQParser#REPEATNUM.
    def exitREPEATNUM(self, ctx:REQParser.REPEATNUMContext):
        pass


    # Enter a parse tree produced by REQParser#REPEATBOOL.
    def enterREPEATBOOL(self, ctx:REQParser.REPEATBOOLContext):
        pass

    # Exit a parse tree produced by REQParser#REPEATBOOL.
    def exitREPEATBOOL(self, ctx:REQParser.REPEATBOOLContext):
        pass


    # Enter a parse tree produced by REQParser#CONCRETENUM.
    def enterCONCRETENUM(self, ctx:REQParser.CONCRETENUMContext):
        pass

    # Exit a parse tree produced by REQParser#CONCRETENUM.
    def exitCONCRETENUM(self, ctx:REQParser.CONCRETENUMContext):
        pass


    # Enter a parse tree produced by REQParser#CONCRETEBOOL.
    def enterCONCRETEBOOL(self, ctx:REQParser.CONCRETEBOOLContext):
        pass

    # Exit a parse tree produced by REQParser#CONCRETEBOOL.
    def exitCONCRETEBOOL(self, ctx:REQParser.CONCRETEBOOLContext):
        pass


    # Enter a parse tree produced by REQParser#EMPTY.
    def enterEMPTY(self, ctx:REQParser.EMPTYContext):
        pass

    # Exit a parse tree produced by REQParser#EMPTY.
    def exitEMPTY(self, ctx:REQParser.EMPTYContext):
        pass


    # Enter a parse tree produced by REQParser#BOUND.
    def enterBOUND(self, ctx:REQParser.BOUNDContext):
        pass

    # Exit a parse tree produced by REQParser#BOUND.
    def exitBOUND(self, ctx:REQParser.BOUNDContext):
        pass


    # Enter a parse tree produced by REQParser#INFBOUND.
    def enterINFBOUND(self, ctx:REQParser.INFBOUNDContext):
        pass

    # Exit a parse tree produced by REQParser#INFBOUND.
    def exitINFBOUND(self, ctx:REQParser.INFBOUNDContext):
        pass


    # Enter a parse tree produced by REQParser#BASICFALSE.
    def enterBASICFALSE(self, ctx:REQParser.BASICFALSEContext):
        pass

    # Exit a parse tree produced by REQParser#BASICFALSE.
    def exitBASICFALSE(self, ctx:REQParser.BASICFALSEContext):
        pass


    # Enter a parse tree produced by REQParser#BASICNUM.
    def enterBASICNUM(self, ctx:REQParser.BASICNUMContext):
        pass

    # Exit a parse tree produced by REQParser#BASICNUM.
    def exitBASICNUM(self, ctx:REQParser.BASICNUMContext):
        pass


    # Enter a parse tree produced by REQParser#VARNAMEINDEX.
    def enterVARNAMEINDEX(self, ctx:REQParser.VARNAMEINDEXContext):
        pass

    # Exit a parse tree produced by REQParser#VARNAMEINDEX.
    def exitVARNAMEINDEX(self, ctx:REQParser.VARNAMEINDEXContext):
        pass


    # Enter a parse tree produced by REQParser#BASICTRUE.
    def enterBASICTRUE(self, ctx:REQParser.BASICTRUEContext):
        pass

    # Exit a parse tree produced by REQParser#BASICTRUE.
    def exitBASICTRUE(self, ctx:REQParser.BASICTRUEContext):
        pass


    # Enter a parse tree produced by REQParser#PARENTHESIS.
    def enterPARENTHESIS(self, ctx:REQParser.PARENTHESISContext):
        pass

    # Exit a parse tree produced by REQParser#PARENTHESIS.
    def exitPARENTHESIS(self, ctx:REQParser.PARENTHESISContext):
        pass


    # Enter a parse tree produced by REQParser#VARNAME.
    def enterVARNAME(self, ctx:REQParser.VARNAMEContext):
        pass

    # Exit a parse tree produced by REQParser#VARNAME.
    def exitVARNAME(self, ctx:REQParser.VARNAMEContext):
        pass


    # Enter a parse tree produced by REQParser#BINARY.
    def enterBINARY(self, ctx:REQParser.BINARYContext):
        pass

    # Exit a parse tree produced by REQParser#BINARY.
    def exitBINARY(self, ctx:REQParser.BINARYContext):
        pass


    # Enter a parse tree produced by REQParser#UNARY.
    def enterUNARY(self, ctx:REQParser.UNARYContext):
        pass

    # Exit a parse tree produced by REQParser#UNARY.
    def exitUNARY(self, ctx:REQParser.UNARYContext):
        pass


    # Enter a parse tree produced by REQParser#amap.
    def enterAmap(self, ctx:REQParser.AmapContext):
        pass

    # Exit a parse tree produced by REQParser#amap.
    def exitAmap(self, ctx:REQParser.AmapContext):
        pass


    # Enter a parse tree produced by REQParser#adapter.
    def enterAdapter(self, ctx:REQParser.AdapterContext):
        pass

    # Exit a parse tree produced by REQParser#adapter.
    def exitAdapter(self, ctx:REQParser.AdapterContext):
        pass


    # Enter a parse tree produced by REQParser#pname.
    def enterPname(self, ctx:REQParser.PnameContext):
        pass

    # Exit a parse tree produced by REQParser#pname.
    def exitPname(self, ctx:REQParser.PnameContext):
        pass


    # Enter a parse tree produced by REQParser#varname.
    def enterVarname(self, ctx:REQParser.VarnameContext):
        pass

    # Exit a parse tree produced by REQParser#varname.
    def exitVarname(self, ctx:REQParser.VarnameContext):
        pass


    # Enter a parse tree produced by REQParser#NUMDATA.
    def enterNUMDATA(self, ctx:REQParser.NUMDATAContext):
        pass

    # Exit a parse tree produced by REQParser#NUMDATA.
    def exitNUMDATA(self, ctx:REQParser.NUMDATAContext):
        pass


    # Enter a parse tree produced by REQParser#TIMEDATA.
    def enterTIMEDATA(self, ctx:REQParser.TIMEDATAContext):
        pass

    # Exit a parse tree produced by REQParser#TIMEDATA.
    def exitTIMEDATA(self, ctx:REQParser.TIMEDATAContext):
        pass


    # Enter a parse tree produced by REQParser#number.
    def enterNumber(self, ctx:REQParser.NumberContext):
        pass

    # Exit a parse tree produced by REQParser#number.
    def exitNumber(self, ctx:REQParser.NumberContext):
        pass


    # Enter a parse tree produced by REQParser#bools.
    def enterBools(self, ctx:REQParser.BoolsContext):
        pass

    # Exit a parse tree produced by REQParser#bools.
    def exitBools(self, ctx:REQParser.BoolsContext):
        pass


    # Enter a parse tree produced by REQParser#timeval.
    def enterTimeval(self, ctx:REQParser.TimevalContext):
        pass

    # Exit a parse tree produced by REQParser#timeval.
    def exitTimeval(self, ctx:REQParser.TimevalContext):
        pass


    # Enter a parse tree produced by REQParser#booldatas.
    def enterBooldatas(self, ctx:REQParser.BooldatasContext):
        pass

    # Exit a parse tree produced by REQParser#booldatas.
    def exitBooldatas(self, ctx:REQParser.BooldatasContext):
        pass



del REQParser