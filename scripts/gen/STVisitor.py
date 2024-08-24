# Generated from ST.g4 by ANTLR 4.9.1
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .STParser import STParser
else:
    from STParser import STParser

# This class defines a complete generic visitor for a parse tree produced by STParser.

class STVisitor(ParseTreeVisitor):

    # Visit a parse tree produced by STParser#stapp.
    def visitStapp(self, ctx:STParser.StappContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#config.
    def visitConfig(self, ctx:STParser.ConfigContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#programSection.
    def visitProgramSection(self, ctx:STParser.ProgramSectionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#aProgram.
    def visitAProgram(self, ctx:STParser.AProgramContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#cycletime.
    def visitCycletime(self, ctx:STParser.CycletimeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#typeSection.
    def visitTypeSection(self, ctx:STParser.TypeSectionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#enum.
    def visitEnum(self, ctx:STParser.EnumContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#bitfield.
    def visitBitfield(self, ctx:STParser.BitfieldContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#structure.
    def visitStructure(self, ctx:STParser.StructureContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#var_priv.
    def visitVar_priv(self, ctx:STParser.Var_privContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#var_in.
    def visitVar_in(self, ctx:STParser.Var_inContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#var_in_out.
    def visitVar_in_out(self, ctx:STParser.Var_in_outContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#var_out.
    def visitVar_out(self, ctx:STParser.Var_outContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#var_global.
    def visitVar_global(self, ctx:STParser.Var_globalContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#stappTypes.
    def visitStappTypes(self, ctx:STParser.StappTypesContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#arrayType.
    def visitArrayType(self, ctx:STParser.ArrayTypeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#YESINITDECL.
    def visitYESINITDECL(self, ctx:STParser.YESINITDECLContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#NOINITDECL.
    def visitNOINITDECL(self, ctx:STParser.NOINITDECLContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#var_decl_collection.
    def visitVar_decl_collection(self, ctx:STParser.Var_decl_collectionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#pros.
    def visitPros(self, ctx:STParser.ProsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#subs.
    def visitSubs(self, ctx:STParser.SubsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#udfbs.
    def visitUdfbs(self, ctx:STParser.UdfbsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#funcs.
    def visitFuncs(self, ctx:STParser.FuncsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#program.
    def visitProgram(self, ctx:STParser.ProgramContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#statementList.
    def visitStatementList(self, ctx:STParser.StatementListContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#statement.
    def visitStatement(self, ctx:STParser.StatementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#assign.
    def visitAssign(self, ctx:STParser.AssignContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#USERDEFINEFUNCALL.
    def visitUSERDEFINEFUNCALL(self, ctx:STParser.USERDEFINEFUNCALLContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#STANDARDFUNCALL.
    def visitSTANDARDFUNCALL(self, ctx:STParser.STANDARDFUNCALLContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#FORSTATEMENTWITHBY.
    def visitFORSTATEMENTWITHBY(self, ctx:STParser.FORSTATEMENTWITHBYContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#FORSTATEMENT.
    def visitFORSTATEMENT(self, ctx:STParser.FORSTATEMENTContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#WHILESTATEMENT.
    def visitWHILESTATEMENT(self, ctx:STParser.WHILESTATEMENTContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#REPEATSTATEMENT.
    def visitREPEATSTATEMENT(self, ctx:STParser.REPEATSTATEMENTContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#IFSTATEMENT.
    def visitIFSTATEMENT(self, ctx:STParser.IFSTATEMENTContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#CASESTATEMENT.
    def visitCASESTATEMENT(self, ctx:STParser.CASESTATEMENTContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#CASESTATEMENTWITHELSE.
    def visitCASESTATEMENTWITHELSE(self, ctx:STParser.CASESTATEMENTWITHELSEContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#caseoption.
    def visitCaseoption(self, ctx:STParser.CaseoptionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#caseoptionline.
    def visitCaseoptionline(self, ctx:STParser.CaseoptionlineContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#opwithequal.
    def visitOpwithequal(self, ctx:STParser.OpwithequalContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#exitstatement.
    def visitExitstatement(self, ctx:STParser.ExitstatementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#returnstatement.
    def visitReturnstatement(self, ctx:STParser.ReturnstatementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#emptystatement.
    def visitEmptystatement(self, ctx:STParser.EmptystatementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#PRIMARYEXPR.
    def visitPRIMARYEXPR(self, ctx:STParser.PRIMARYEXPRContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#LOGICALBINARY.
    def visitLOGICALBINARY(self, ctx:STParser.LOGICALBINARYContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#NEGATIVEOPERATION.
    def visitNEGATIVEOPERATION(self, ctx:STParser.NEGATIVEOPERATIONContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#PARENTHESIS.
    def visitPARENTHESIS(self, ctx:STParser.PARENTHESISContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#FUNCTIONCALL.
    def visitFUNCTIONCALL(self, ctx:STParser.FUNCTIONCALLContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#NOTOPERATION.
    def visitNOTOPERATION(self, ctx:STParser.NOTOPERATIONContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#NUMERICALOPERATION.
    def visitNUMERICALOPERATION(self, ctx:STParser.NUMERICALOPERATIONContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#EXPONENTIAL.
    def visitEXPONENTIAL(self, ctx:STParser.EXPONENTIALContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#COMPARISON.
    def visitCOMPARISON(self, ctx:STParser.COMPARISONContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#ARRAYEXPR.
    def visitARRAYEXPR(self, ctx:STParser.ARRAYEXPRContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#ONETOONE.
    def visitONETOONE(self, ctx:STParser.ONETOONEContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#ONTTOONPARENTHESIS.
    def visitONTTOONPARENTHESIS(self, ctx:STParser.ONTTOONPARENTHESISContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#ONETOONELIST.
    def visitONETOONELIST(self, ctx:STParser.ONETOONELISTContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#ARGLIST.
    def visitARGLIST(self, ctx:STParser.ARGLISTContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#NUMPRIMARY.
    def visitNUMPRIMARY(self, ctx:STParser.NUMPRIMARYContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#TIMEPRIMARY.
    def visitTIMEPRIMARY(self, ctx:STParser.TIMEPRIMARYContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#BOOLTRUE.
    def visitBOOLTRUE(self, ctx:STParser.BOOLTRUEContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#BOOLFALSE.
    def visitBOOLFALSE(self, ctx:STParser.BOOLFALSEContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#VARPRIMARY.
    def visitVARPRIMARY(self, ctx:STParser.VARPRIMARYContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#ENUMPRIMARY.
    def visitENUMPRIMARY(self, ctx:STParser.ENUMPRIMARYContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#SPECIALTOKEN.
    def visitSPECIALTOKEN(self, ctx:STParser.SPECIALTOKENContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#varname.
    def visitVarname(self, ctx:STParser.VarnameContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#number.
    def visitNumber(self, ctx:STParser.NumberContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#timeval.
    def visitTimeval(self, ctx:STParser.TimevalContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#listInitVar.
    def visitListInitVar(self, ctx:STParser.ListInitVarContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by STParser#idList.
    def visitIdList(self, ctx:STParser.IdListContext):
        return self.visitChildren(ctx)



del STParser