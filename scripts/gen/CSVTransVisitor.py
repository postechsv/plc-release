# Generated from CSVTrans.g4 by ANTLR 4.9.1
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .CSVTransParser import CSVTransParser
else:
    from CSVTransParser import CSVTransParser

# This class defines a complete generic visitor for a parse tree produced by CSVTransParser.

class CSVTransVisitor(ParseTreeVisitor):

    # Visit a parse tree produced by CSVTransParser#start.
    def visitStart(self, ctx:CSVTransParser.StartContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#PARENTHESIS.
    def visitPARENTHESIS(self, ctx:CSVTransParser.PARENTHESISContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#OUTPUTNUM.
    def visitOUTPUTNUM(self, ctx:CSVTransParser.OUTPUTNUMContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#OUTPUTBOOL.
    def visitOUTPUTBOOL(self, ctx:CSVTransParser.OUTPUTBOOLContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#OUTPUTEXPR.
    def visitOUTPUTEXPR(self, ctx:CSVTransParser.OUTPUTEXPRContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#INPUTNUM.
    def visitINPUTNUM(self, ctx:CSVTransParser.INPUTNUMContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#INPUTBOOL.
    def visitINPUTBOOL(self, ctx:CSVTransParser.INPUTBOOLContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#FRESHVARPART.
    def visitFRESHVARPART(self, ctx:CSVTransParser.FRESHVARPARTContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#EMPTYINPUT.
    def visitEMPTYINPUT(self, ctx:CSVTransParser.EMPTYINPUTContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#TYPEDATA.
    def visitTYPEDATA(self, ctx:CSVTransParser.TYPEDATAContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#EMPTYTYPE.
    def visitEMPTYTYPE(self, ctx:CSVTransParser.EMPTYTYPEContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#functionblock.
    def visitFunctionblock(self, ctx:CSVTransParser.FunctionblockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#NAMELIST.
    def visitNAMELIST(self, ctx:CSVTransParser.NAMELISTContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#SINGLENAME.
    def visitSINGLENAME(self, ctx:CSVTransParser.SINGLENAMEContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#semanticValuesNum.
    def visitSemanticValuesNum(self, ctx:CSVTransParser.SemanticValuesNumContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#semanticValuesBoolean.
    def visitSemanticValuesBoolean(self, ctx:CSVTransParser.SemanticValuesBooleanContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#symbolicValues.
    def visitSymbolicValues(self, ctx:CSVTransParser.SymbolicValuesContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#PRIMARYEXPR.
    def visitPRIMARYEXPR(self, ctx:CSVTransParser.PRIMARYEXPRContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#LOGICALBINARY.
    def visitLOGICALBINARY(self, ctx:CSVTransParser.LOGICALBINARYContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#PARENTHESISEXPR.
    def visitPARENTHESISEXPR(self, ctx:CSVTransParser.PARENTHESISEXPRContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#NEGATIVEOPERATION.
    def visitNEGATIVEOPERATION(self, ctx:CSVTransParser.NEGATIVEOPERATIONContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#NOTOPERATION.
    def visitNOTOPERATION(self, ctx:CSVTransParser.NOTOPERATIONContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#NUMERICALOPERATION.
    def visitNUMERICALOPERATION(self, ctx:CSVTransParser.NUMERICALOPERATIONContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#EXPONENTIAL.
    def visitEXPONENTIAL(self, ctx:CSVTransParser.EXPONENTIALContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#COMPARISON.
    def visitCOMPARISON(self, ctx:CSVTransParser.COMPARISONContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#PRIMARYSYMBOLICEXPR.
    def visitPRIMARYSYMBOLICEXPR(self, ctx:CSVTransParser.PRIMARYSYMBOLICEXPRContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#number.
    def visitNumber(self, ctx:CSVTransParser.NumberContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#numdatas.
    def visitNumdatas(self, ctx:CSVTransParser.NumdatasContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#booldatas.
    def visitBooldatas(self, ctx:CSVTransParser.BooldatasContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by CSVTransParser#exprs.
    def visitExprs(self, ctx:CSVTransParser.ExprsContext):
        return self.visitChildren(ctx)



del CSVTransParser