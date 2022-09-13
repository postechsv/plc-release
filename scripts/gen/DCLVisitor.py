# Generated from D:/plc/scripts\DCL.g4 by ANTLR 4.9.2
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .DCLParser import DCLParser
else:
    from DCLParser import DCLParser

# This class defines a complete generic visitor for a parse tree produced by DCLParser.

class DCLVisitor(ParseTreeVisitor):

    # Visit a parse tree produced by DCLParser#start.
    def visitStart(self, ctx:DCLParser.StartContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by DCLParser#local.
    def visitLocal(self, ctx:DCLParser.LocalContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by DCLParser#USELESSAPART.
    def visitUSELESSAPART(self, ctx:DCLParser.USELESSAPARTContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by DCLParser#CYCLEPART.
    def visitCYCLEPART(self, ctx:DCLParser.CYCLEPARTContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by DCLParser#ENUMPART.
    def visitENUMPART(self, ctx:DCLParser.ENUMPARTContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by DCLParser#BITFIELDPART.
    def visitBITFIELDPART(self, ctx:DCLParser.BITFIELDPARTContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by DCLParser#MAINPARGRAM.
    def visitMAINPARGRAM(self, ctx:DCLParser.MAINPARGRAMContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by DCLParser#SUBPROGRAM.
    def visitSUBPROGRAM(self, ctx:DCLParser.SUBPROGRAMContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by DCLParser#UDFB.
    def visitUDFB(self, ctx:DCLParser.UDFBContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by DCLParser#STRUCTURE.
    def visitSTRUCTURE(self, ctx:DCLParser.STRUCTUREContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by DCLParser#VARDECLINITNUM.
    def visitVARDECLINITNUM(self, ctx:DCLParser.VARDECLINITNUMContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by DCLParser#VARDECLINITBOOL.
    def visitVARDECLINITBOOL(self, ctx:DCLParser.VARDECLINITBOOLContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by DCLParser#VARDECLTIME.
    def visitVARDECLTIME(self, ctx:DCLParser.VARDECLTIMEContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by DCLParser#USELESSVPART.
    def visitUSELESSVPART(self, ctx:DCLParser.USELESSVPARTContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by DCLParser#varnamelist.
    def visitVarnamelist(self, ctx:DCLParser.VarnamelistContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by DCLParser#numdatas.
    def visitNumdatas(self, ctx:DCLParser.NumdatasContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by DCLParser#booldatas.
    def visitBooldatas(self, ctx:DCLParser.BooldatasContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by DCLParser#number.
    def visitNumber(self, ctx:DCLParser.NumberContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by DCLParser#timedatas.
    def visitTimedatas(self, ctx:DCLParser.TimedatasContext):
        return self.visitChildren(ctx)



del DCLParser