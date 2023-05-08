# Generated from REQ.g4 by ANTLR 4.9.1
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .REQParser import REQParser
else:
    from REQParser import REQParser

# This class defines a complete generic visitor for a parse tree produced by REQParser.

class REQVisitor(ParseTreeVisitor):

    # Visit a parse tree produced by REQParser#REQUIREMENT.
    def visitREQUIREMENT(self, ctx:REQParser.REQUIREMENTContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#REPEATNUM.
    def visitREPEATNUM(self, ctx:REQParser.REPEATNUMContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#REPEATBOOL.
    def visitREPEATBOOL(self, ctx:REQParser.REPEATBOOLContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#CONCRETENUM.
    def visitCONCRETENUM(self, ctx:REQParser.CONCRETENUMContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#CONCRETEBOOL.
    def visitCONCRETEBOOL(self, ctx:REQParser.CONCRETEBOOLContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#EMPTY.
    def visitEMPTY(self, ctx:REQParser.EMPTYContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#BOUND.
    def visitBOUND(self, ctx:REQParser.BOUNDContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#INFBOUND.
    def visitINFBOUND(self, ctx:REQParser.INFBOUNDContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#BASICFALSE.
    def visitBASICFALSE(self, ctx:REQParser.BASICFALSEContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#BASICNUM.
    def visitBASICNUM(self, ctx:REQParser.BASICNUMContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#VARNAMEINDEX.
    def visitVARNAMEINDEX(self, ctx:REQParser.VARNAMEINDEXContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#BASICTRUE.
    def visitBASICTRUE(self, ctx:REQParser.BASICTRUEContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#PARENTHESIS.
    def visitPARENTHESIS(self, ctx:REQParser.PARENTHESISContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#VARNAME.
    def visitVARNAME(self, ctx:REQParser.VARNAMEContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#BINARY.
    def visitBINARY(self, ctx:REQParser.BINARYContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#UNARY.
    def visitUNARY(self, ctx:REQParser.UNARYContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#amap.
    def visitAmap(self, ctx:REQParser.AmapContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#adapter.
    def visitAdapter(self, ctx:REQParser.AdapterContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#pname.
    def visitPname(self, ctx:REQParser.PnameContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#varname.
    def visitVarname(self, ctx:REQParser.VarnameContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#NUMDATA.
    def visitNUMDATA(self, ctx:REQParser.NUMDATAContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#TIMEDATA.
    def visitTIMEDATA(self, ctx:REQParser.TIMEDATAContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#number.
    def visitNumber(self, ctx:REQParser.NumberContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#bools.
    def visitBools(self, ctx:REQParser.BoolsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#timeval.
    def visitTimeval(self, ctx:REQParser.TimevalContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#booldatas.
    def visitBooldatas(self, ctx:REQParser.BooldatasContext):
        return self.visitChildren(ctx)



del REQParser