# Generated from D:/plc/scripts\REQ.g4 by ANTLR 4.9.2
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .REQParser import REQParser
else:
    from REQParser import REQParser

# This class defines a complete generic visitor for a parse tree produced by REQParser.

class REQVisitor(ParseTreeVisitor):

    # Visit a parse tree produced by REQParser#STEPYES.
    def visitSTEPYES(self, ctx:REQParser.STEPYESContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#STEPNO.
    def visitSTEPNO(self, ctx:REQParser.STEPNOContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#SYMBOLIC.
    def visitSYMBOLIC(self, ctx:REQParser.SYMBOLICContext):
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


    # Visit a parse tree produced by REQParser#STEPPPARTNUM.
    def visitSTEPPPARTNUM(self, ctx:REQParser.STEPPPARTNUMContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#STEPPARTID.
    def visitSTEPPARTID(self, ctx:REQParser.STEPPARTIDContext):
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


    # Visit a parse tree produced by REQParser#functionblock.
    def visitFunctionblock(self, ctx:REQParser.FunctionblockContext):
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


    # Visit a parse tree produced by REQParser#timeval.
    def visitTimeval(self, ctx:REQParser.TimevalContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by REQParser#booldatas.
    def visitBooldatas(self, ctx:REQParser.BooldatasContext):
        return self.visitChildren(ctx)



del REQParser