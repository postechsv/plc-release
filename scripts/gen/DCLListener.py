# Generated from D:/plc/scripts\DCL.g4 by ANTLR 4.9.2
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .DCLParser import DCLParser
else:
    from DCLParser import DCLParser

# This class defines a complete listener for a parse tree produced by DCLParser.
class DCLListener(ParseTreeListener):

    # Enter a parse tree produced by DCLParser#start.
    def enterStart(self, ctx:DCLParser.StartContext):
        pass

    # Exit a parse tree produced by DCLParser#start.
    def exitStart(self, ctx:DCLParser.StartContext):
        pass


    # Enter a parse tree produced by DCLParser#local.
    def enterLocal(self, ctx:DCLParser.LocalContext):
        pass

    # Exit a parse tree produced by DCLParser#local.
    def exitLocal(self, ctx:DCLParser.LocalContext):
        pass


    # Enter a parse tree produced by DCLParser#USELESSAPART.
    def enterUSELESSAPART(self, ctx:DCLParser.USELESSAPARTContext):
        pass

    # Exit a parse tree produced by DCLParser#USELESSAPART.
    def exitUSELESSAPART(self, ctx:DCLParser.USELESSAPARTContext):
        pass


    # Enter a parse tree produced by DCLParser#CYCLEPART.
    def enterCYCLEPART(self, ctx:DCLParser.CYCLEPARTContext):
        pass

    # Exit a parse tree produced by DCLParser#CYCLEPART.
    def exitCYCLEPART(self, ctx:DCLParser.CYCLEPARTContext):
        pass


    # Enter a parse tree produced by DCLParser#ENUMPART.
    def enterENUMPART(self, ctx:DCLParser.ENUMPARTContext):
        pass

    # Exit a parse tree produced by DCLParser#ENUMPART.
    def exitENUMPART(self, ctx:DCLParser.ENUMPARTContext):
        pass


    # Enter a parse tree produced by DCLParser#BITFIELDPART.
    def enterBITFIELDPART(self, ctx:DCLParser.BITFIELDPARTContext):
        pass

    # Exit a parse tree produced by DCLParser#BITFIELDPART.
    def exitBITFIELDPART(self, ctx:DCLParser.BITFIELDPARTContext):
        pass


    # Enter a parse tree produced by DCLParser#MAINPARGRAM.
    def enterMAINPARGRAM(self, ctx:DCLParser.MAINPARGRAMContext):
        pass

    # Exit a parse tree produced by DCLParser#MAINPARGRAM.
    def exitMAINPARGRAM(self, ctx:DCLParser.MAINPARGRAMContext):
        pass


    # Enter a parse tree produced by DCLParser#SUBPROGRAM.
    def enterSUBPROGRAM(self, ctx:DCLParser.SUBPROGRAMContext):
        pass

    # Exit a parse tree produced by DCLParser#SUBPROGRAM.
    def exitSUBPROGRAM(self, ctx:DCLParser.SUBPROGRAMContext):
        pass


    # Enter a parse tree produced by DCLParser#UDFB.
    def enterUDFB(self, ctx:DCLParser.UDFBContext):
        pass

    # Exit a parse tree produced by DCLParser#UDFB.
    def exitUDFB(self, ctx:DCLParser.UDFBContext):
        pass


    # Enter a parse tree produced by DCLParser#STRUCTURE.
    def enterSTRUCTURE(self, ctx:DCLParser.STRUCTUREContext):
        pass

    # Exit a parse tree produced by DCLParser#STRUCTURE.
    def exitSTRUCTURE(self, ctx:DCLParser.STRUCTUREContext):
        pass


    # Enter a parse tree produced by DCLParser#VARDECLINITNUM.
    def enterVARDECLINITNUM(self, ctx:DCLParser.VARDECLINITNUMContext):
        pass

    # Exit a parse tree produced by DCLParser#VARDECLINITNUM.
    def exitVARDECLINITNUM(self, ctx:DCLParser.VARDECLINITNUMContext):
        pass


    # Enter a parse tree produced by DCLParser#VARDECLINITBOOL.
    def enterVARDECLINITBOOL(self, ctx:DCLParser.VARDECLINITBOOLContext):
        pass

    # Exit a parse tree produced by DCLParser#VARDECLINITBOOL.
    def exitVARDECLINITBOOL(self, ctx:DCLParser.VARDECLINITBOOLContext):
        pass


    # Enter a parse tree produced by DCLParser#VARDECLTIME.
    def enterVARDECLTIME(self, ctx:DCLParser.VARDECLTIMEContext):
        pass

    # Exit a parse tree produced by DCLParser#VARDECLTIME.
    def exitVARDECLTIME(self, ctx:DCLParser.VARDECLTIMEContext):
        pass


    # Enter a parse tree produced by DCLParser#USELESSVPART.
    def enterUSELESSVPART(self, ctx:DCLParser.USELESSVPARTContext):
        pass

    # Exit a parse tree produced by DCLParser#USELESSVPART.
    def exitUSELESSVPART(self, ctx:DCLParser.USELESSVPARTContext):
        pass


    # Enter a parse tree produced by DCLParser#varnamelist.
    def enterVarnamelist(self, ctx:DCLParser.VarnamelistContext):
        pass

    # Exit a parse tree produced by DCLParser#varnamelist.
    def exitVarnamelist(self, ctx:DCLParser.VarnamelistContext):
        pass


    # Enter a parse tree produced by DCLParser#numdatas.
    def enterNumdatas(self, ctx:DCLParser.NumdatasContext):
        pass

    # Exit a parse tree produced by DCLParser#numdatas.
    def exitNumdatas(self, ctx:DCLParser.NumdatasContext):
        pass


    # Enter a parse tree produced by DCLParser#booldatas.
    def enterBooldatas(self, ctx:DCLParser.BooldatasContext):
        pass

    # Exit a parse tree produced by DCLParser#booldatas.
    def exitBooldatas(self, ctx:DCLParser.BooldatasContext):
        pass


    # Enter a parse tree produced by DCLParser#number.
    def enterNumber(self, ctx:DCLParser.NumberContext):
        pass

    # Exit a parse tree produced by DCLParser#number.
    def exitNumber(self, ctx:DCLParser.NumberContext):
        pass


    # Enter a parse tree produced by DCLParser#timedatas.
    def enterTimedatas(self, ctx:DCLParser.TimedatasContext):
        pass

    # Exit a parse tree produced by DCLParser#timedatas.
    def exitTimedatas(self, ctx:DCLParser.TimedatasContext):
        pass



del DCLParser