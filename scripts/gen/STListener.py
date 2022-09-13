# Generated from D:/plc/scripts\ST.g4 by ANTLR 4.9.2
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .STParser import STParser
else:
    from STParser import STParser

# This class defines a complete listener for a parse tree produced by STParser.
class STListener(ParseTreeListener):

    # Enter a parse tree produced by STParser#stapp.
    def enterStapp(self, ctx:STParser.StappContext):
        pass

    # Exit a parse tree produced by STParser#stapp.
    def exitStapp(self, ctx:STParser.StappContext):
        pass


    # Enter a parse tree produced by STParser#config.
    def enterConfig(self, ctx:STParser.ConfigContext):
        pass

    # Exit a parse tree produced by STParser#config.
    def exitConfig(self, ctx:STParser.ConfigContext):
        pass


    # Enter a parse tree produced by STParser#programSection.
    def enterProgramSection(self, ctx:STParser.ProgramSectionContext):
        pass

    # Exit a parse tree produced by STParser#programSection.
    def exitProgramSection(self, ctx:STParser.ProgramSectionContext):
        pass


    # Enter a parse tree produced by STParser#aProgram.
    def enterAProgram(self, ctx:STParser.AProgramContext):
        pass

    # Exit a parse tree produced by STParser#aProgram.
    def exitAProgram(self, ctx:STParser.AProgramContext):
        pass


    # Enter a parse tree produced by STParser#cycletime.
    def enterCycletime(self, ctx:STParser.CycletimeContext):
        pass

    # Exit a parse tree produced by STParser#cycletime.
    def exitCycletime(self, ctx:STParser.CycletimeContext):
        pass


    # Enter a parse tree produced by STParser#typeSection.
    def enterTypeSection(self, ctx:STParser.TypeSectionContext):
        pass

    # Exit a parse tree produced by STParser#typeSection.
    def exitTypeSection(self, ctx:STParser.TypeSectionContext):
        pass


    # Enter a parse tree produced by STParser#enum.
    def enterEnum(self, ctx:STParser.EnumContext):
        pass

    # Exit a parse tree produced by STParser#enum.
    def exitEnum(self, ctx:STParser.EnumContext):
        pass


    # Enter a parse tree produced by STParser#bitfield.
    def enterBitfield(self, ctx:STParser.BitfieldContext):
        pass

    # Exit a parse tree produced by STParser#bitfield.
    def exitBitfield(self, ctx:STParser.BitfieldContext):
        pass


    # Enter a parse tree produced by STParser#structure.
    def enterStructure(self, ctx:STParser.StructureContext):
        pass

    # Exit a parse tree produced by STParser#structure.
    def exitStructure(self, ctx:STParser.StructureContext):
        pass


    # Enter a parse tree produced by STParser#var_priv.
    def enterVar_priv(self, ctx:STParser.Var_privContext):
        pass

    # Exit a parse tree produced by STParser#var_priv.
    def exitVar_priv(self, ctx:STParser.Var_privContext):
        pass


    # Enter a parse tree produced by STParser#var_in.
    def enterVar_in(self, ctx:STParser.Var_inContext):
        pass

    # Exit a parse tree produced by STParser#var_in.
    def exitVar_in(self, ctx:STParser.Var_inContext):
        pass


    # Enter a parse tree produced by STParser#var_in_out.
    def enterVar_in_out(self, ctx:STParser.Var_in_outContext):
        pass

    # Exit a parse tree produced by STParser#var_in_out.
    def exitVar_in_out(self, ctx:STParser.Var_in_outContext):
        pass


    # Enter a parse tree produced by STParser#var_out.
    def enterVar_out(self, ctx:STParser.Var_outContext):
        pass

    # Exit a parse tree produced by STParser#var_out.
    def exitVar_out(self, ctx:STParser.Var_outContext):
        pass


    # Enter a parse tree produced by STParser#var_global.
    def enterVar_global(self, ctx:STParser.Var_globalContext):
        pass

    # Exit a parse tree produced by STParser#var_global.
    def exitVar_global(self, ctx:STParser.Var_globalContext):
        pass


    # Enter a parse tree produced by STParser#stappTypes.
    def enterStappTypes(self, ctx:STParser.StappTypesContext):
        pass

    # Exit a parse tree produced by STParser#stappTypes.
    def exitStappTypes(self, ctx:STParser.StappTypesContext):
        pass


    # Enter a parse tree produced by STParser#arrayType.
    def enterArrayType(self, ctx:STParser.ArrayTypeContext):
        pass

    # Exit a parse tree produced by STParser#arrayType.
    def exitArrayType(self, ctx:STParser.ArrayTypeContext):
        pass


    # Enter a parse tree produced by STParser#YESINITDECL.
    def enterYESINITDECL(self, ctx:STParser.YESINITDECLContext):
        pass

    # Exit a parse tree produced by STParser#YESINITDECL.
    def exitYESINITDECL(self, ctx:STParser.YESINITDECLContext):
        pass


    # Enter a parse tree produced by STParser#NOINITDECL.
    def enterNOINITDECL(self, ctx:STParser.NOINITDECLContext):
        pass

    # Exit a parse tree produced by STParser#NOINITDECL.
    def exitNOINITDECL(self, ctx:STParser.NOINITDECLContext):
        pass


    # Enter a parse tree produced by STParser#var_decl_collection.
    def enterVar_decl_collection(self, ctx:STParser.Var_decl_collectionContext):
        pass

    # Exit a parse tree produced by STParser#var_decl_collection.
    def exitVar_decl_collection(self, ctx:STParser.Var_decl_collectionContext):
        pass


    # Enter a parse tree produced by STParser#pros.
    def enterPros(self, ctx:STParser.ProsContext):
        pass

    # Exit a parse tree produced by STParser#pros.
    def exitPros(self, ctx:STParser.ProsContext):
        pass


    # Enter a parse tree produced by STParser#subs.
    def enterSubs(self, ctx:STParser.SubsContext):
        pass

    # Exit a parse tree produced by STParser#subs.
    def exitSubs(self, ctx:STParser.SubsContext):
        pass


    # Enter a parse tree produced by STParser#udfbs.
    def enterUdfbs(self, ctx:STParser.UdfbsContext):
        pass

    # Exit a parse tree produced by STParser#udfbs.
    def exitUdfbs(self, ctx:STParser.UdfbsContext):
        pass


    # Enter a parse tree produced by STParser#funcs.
    def enterFuncs(self, ctx:STParser.FuncsContext):
        pass

    # Exit a parse tree produced by STParser#funcs.
    def exitFuncs(self, ctx:STParser.FuncsContext):
        pass


    # Enter a parse tree produced by STParser#program.
    def enterProgram(self, ctx:STParser.ProgramContext):
        pass

    # Exit a parse tree produced by STParser#program.
    def exitProgram(self, ctx:STParser.ProgramContext):
        pass


    # Enter a parse tree produced by STParser#statementList.
    def enterStatementList(self, ctx:STParser.StatementListContext):
        pass

    # Exit a parse tree produced by STParser#statementList.
    def exitStatementList(self, ctx:STParser.StatementListContext):
        pass


    # Enter a parse tree produced by STParser#statement.
    def enterStatement(self, ctx:STParser.StatementContext):
        pass

    # Exit a parse tree produced by STParser#statement.
    def exitStatement(self, ctx:STParser.StatementContext):
        pass


    # Enter a parse tree produced by STParser#assign.
    def enterAssign(self, ctx:STParser.AssignContext):
        pass

    # Exit a parse tree produced by STParser#assign.
    def exitAssign(self, ctx:STParser.AssignContext):
        pass


    # Enter a parse tree produced by STParser#USERDEFINEFUNCALL.
    def enterUSERDEFINEFUNCALL(self, ctx:STParser.USERDEFINEFUNCALLContext):
        pass

    # Exit a parse tree produced by STParser#USERDEFINEFUNCALL.
    def exitUSERDEFINEFUNCALL(self, ctx:STParser.USERDEFINEFUNCALLContext):
        pass


    # Enter a parse tree produced by STParser#STANDARDFUNCALL.
    def enterSTANDARDFUNCALL(self, ctx:STParser.STANDARDFUNCALLContext):
        pass

    # Exit a parse tree produced by STParser#STANDARDFUNCALL.
    def exitSTANDARDFUNCALL(self, ctx:STParser.STANDARDFUNCALLContext):
        pass


    # Enter a parse tree produced by STParser#FORSTATEMENTWITHBY.
    def enterFORSTATEMENTWITHBY(self, ctx:STParser.FORSTATEMENTWITHBYContext):
        pass

    # Exit a parse tree produced by STParser#FORSTATEMENTWITHBY.
    def exitFORSTATEMENTWITHBY(self, ctx:STParser.FORSTATEMENTWITHBYContext):
        pass


    # Enter a parse tree produced by STParser#FORSTATEMENT.
    def enterFORSTATEMENT(self, ctx:STParser.FORSTATEMENTContext):
        pass

    # Exit a parse tree produced by STParser#FORSTATEMENT.
    def exitFORSTATEMENT(self, ctx:STParser.FORSTATEMENTContext):
        pass


    # Enter a parse tree produced by STParser#WHILESTATEMENT.
    def enterWHILESTATEMENT(self, ctx:STParser.WHILESTATEMENTContext):
        pass

    # Exit a parse tree produced by STParser#WHILESTATEMENT.
    def exitWHILESTATEMENT(self, ctx:STParser.WHILESTATEMENTContext):
        pass


    # Enter a parse tree produced by STParser#REPEATSTATEMENT.
    def enterREPEATSTATEMENT(self, ctx:STParser.REPEATSTATEMENTContext):
        pass

    # Exit a parse tree produced by STParser#REPEATSTATEMENT.
    def exitREPEATSTATEMENT(self, ctx:STParser.REPEATSTATEMENTContext):
        pass


    # Enter a parse tree produced by STParser#IFSTATEMENT.
    def enterIFSTATEMENT(self, ctx:STParser.IFSTATEMENTContext):
        pass

    # Exit a parse tree produced by STParser#IFSTATEMENT.
    def exitIFSTATEMENT(self, ctx:STParser.IFSTATEMENTContext):
        pass


    # Enter a parse tree produced by STParser#CASESTATEMENT.
    def enterCASESTATEMENT(self, ctx:STParser.CASESTATEMENTContext):
        pass

    # Exit a parse tree produced by STParser#CASESTATEMENT.
    def exitCASESTATEMENT(self, ctx:STParser.CASESTATEMENTContext):
        pass


    # Enter a parse tree produced by STParser#CASESTATEMENTWITHELSE.
    def enterCASESTATEMENTWITHELSE(self, ctx:STParser.CASESTATEMENTWITHELSEContext):
        pass

    # Exit a parse tree produced by STParser#CASESTATEMENTWITHELSE.
    def exitCASESTATEMENTWITHELSE(self, ctx:STParser.CASESTATEMENTWITHELSEContext):
        pass


    # Enter a parse tree produced by STParser#caseoption.
    def enterCaseoption(self, ctx:STParser.CaseoptionContext):
        pass

    # Exit a parse tree produced by STParser#caseoption.
    def exitCaseoption(self, ctx:STParser.CaseoptionContext):
        pass


    # Enter a parse tree produced by STParser#caseoptionline.
    def enterCaseoptionline(self, ctx:STParser.CaseoptionlineContext):
        pass

    # Exit a parse tree produced by STParser#caseoptionline.
    def exitCaseoptionline(self, ctx:STParser.CaseoptionlineContext):
        pass


    # Enter a parse tree produced by STParser#opwithequal.
    def enterOpwithequal(self, ctx:STParser.OpwithequalContext):
        pass

    # Exit a parse tree produced by STParser#opwithequal.
    def exitOpwithequal(self, ctx:STParser.OpwithequalContext):
        pass


    # Enter a parse tree produced by STParser#exitstatement.
    def enterExitstatement(self, ctx:STParser.ExitstatementContext):
        pass

    # Exit a parse tree produced by STParser#exitstatement.
    def exitExitstatement(self, ctx:STParser.ExitstatementContext):
        pass


    # Enter a parse tree produced by STParser#returnstatement.
    def enterReturnstatement(self, ctx:STParser.ReturnstatementContext):
        pass

    # Exit a parse tree produced by STParser#returnstatement.
    def exitReturnstatement(self, ctx:STParser.ReturnstatementContext):
        pass


    # Enter a parse tree produced by STParser#emptystatement.
    def enterEmptystatement(self, ctx:STParser.EmptystatementContext):
        pass

    # Exit a parse tree produced by STParser#emptystatement.
    def exitEmptystatement(self, ctx:STParser.EmptystatementContext):
        pass


    # Enter a parse tree produced by STParser#PRIMARYEXPR.
    def enterPRIMARYEXPR(self, ctx:STParser.PRIMARYEXPRContext):
        pass

    # Exit a parse tree produced by STParser#PRIMARYEXPR.
    def exitPRIMARYEXPR(self, ctx:STParser.PRIMARYEXPRContext):
        pass


    # Enter a parse tree produced by STParser#LOGICALBINARY.
    def enterLOGICALBINARY(self, ctx:STParser.LOGICALBINARYContext):
        pass

    # Exit a parse tree produced by STParser#LOGICALBINARY.
    def exitLOGICALBINARY(self, ctx:STParser.LOGICALBINARYContext):
        pass


    # Enter a parse tree produced by STParser#NEGATIVEOPERATION.
    def enterNEGATIVEOPERATION(self, ctx:STParser.NEGATIVEOPERATIONContext):
        pass

    # Exit a parse tree produced by STParser#NEGATIVEOPERATION.
    def exitNEGATIVEOPERATION(self, ctx:STParser.NEGATIVEOPERATIONContext):
        pass


    # Enter a parse tree produced by STParser#PARENTHESIS.
    def enterPARENTHESIS(self, ctx:STParser.PARENTHESISContext):
        pass

    # Exit a parse tree produced by STParser#PARENTHESIS.
    def exitPARENTHESIS(self, ctx:STParser.PARENTHESISContext):
        pass


    # Enter a parse tree produced by STParser#FUNCTIONCALL.
    def enterFUNCTIONCALL(self, ctx:STParser.FUNCTIONCALLContext):
        pass

    # Exit a parse tree produced by STParser#FUNCTIONCALL.
    def exitFUNCTIONCALL(self, ctx:STParser.FUNCTIONCALLContext):
        pass


    # Enter a parse tree produced by STParser#NOTOPERATION.
    def enterNOTOPERATION(self, ctx:STParser.NOTOPERATIONContext):
        pass

    # Exit a parse tree produced by STParser#NOTOPERATION.
    def exitNOTOPERATION(self, ctx:STParser.NOTOPERATIONContext):
        pass


    # Enter a parse tree produced by STParser#NUMERICALOPERATION.
    def enterNUMERICALOPERATION(self, ctx:STParser.NUMERICALOPERATIONContext):
        pass

    # Exit a parse tree produced by STParser#NUMERICALOPERATION.
    def exitNUMERICALOPERATION(self, ctx:STParser.NUMERICALOPERATIONContext):
        pass


    # Enter a parse tree produced by STParser#EXPONENTIAL.
    def enterEXPONENTIAL(self, ctx:STParser.EXPONENTIALContext):
        pass

    # Exit a parse tree produced by STParser#EXPONENTIAL.
    def exitEXPONENTIAL(self, ctx:STParser.EXPONENTIALContext):
        pass


    # Enter a parse tree produced by STParser#COMPARISON.
    def enterCOMPARISON(self, ctx:STParser.COMPARISONContext):
        pass

    # Exit a parse tree produced by STParser#COMPARISON.
    def exitCOMPARISON(self, ctx:STParser.COMPARISONContext):
        pass


    # Enter a parse tree produced by STParser#ARRAYEXPR.
    def enterARRAYEXPR(self, ctx:STParser.ARRAYEXPRContext):
        pass

    # Exit a parse tree produced by STParser#ARRAYEXPR.
    def exitARRAYEXPR(self, ctx:STParser.ARRAYEXPRContext):
        pass


    # Enter a parse tree produced by STParser#ONETOONE.
    def enterONETOONE(self, ctx:STParser.ONETOONEContext):
        pass

    # Exit a parse tree produced by STParser#ONETOONE.
    def exitONETOONE(self, ctx:STParser.ONETOONEContext):
        pass


    # Enter a parse tree produced by STParser#ONTTOONPARENTHESIS.
    def enterONTTOONPARENTHESIS(self, ctx:STParser.ONTTOONPARENTHESISContext):
        pass

    # Exit a parse tree produced by STParser#ONTTOONPARENTHESIS.
    def exitONTTOONPARENTHESIS(self, ctx:STParser.ONTTOONPARENTHESISContext):
        pass


    # Enter a parse tree produced by STParser#ONETOONELIST.
    def enterONETOONELIST(self, ctx:STParser.ONETOONELISTContext):
        pass

    # Exit a parse tree produced by STParser#ONETOONELIST.
    def exitONETOONELIST(self, ctx:STParser.ONETOONELISTContext):
        pass


    # Enter a parse tree produced by STParser#ARGLIST.
    def enterARGLIST(self, ctx:STParser.ARGLISTContext):
        pass

    # Exit a parse tree produced by STParser#ARGLIST.
    def exitARGLIST(self, ctx:STParser.ARGLISTContext):
        pass


    # Enter a parse tree produced by STParser#NUMPRIMARY.
    def enterNUMPRIMARY(self, ctx:STParser.NUMPRIMARYContext):
        pass

    # Exit a parse tree produced by STParser#NUMPRIMARY.
    def exitNUMPRIMARY(self, ctx:STParser.NUMPRIMARYContext):
        pass


    # Enter a parse tree produced by STParser#TIMEPRIMARY.
    def enterTIMEPRIMARY(self, ctx:STParser.TIMEPRIMARYContext):
        pass

    # Exit a parse tree produced by STParser#TIMEPRIMARY.
    def exitTIMEPRIMARY(self, ctx:STParser.TIMEPRIMARYContext):
        pass


    # Enter a parse tree produced by STParser#BOOLTRUE.
    def enterBOOLTRUE(self, ctx:STParser.BOOLTRUEContext):
        pass

    # Exit a parse tree produced by STParser#BOOLTRUE.
    def exitBOOLTRUE(self, ctx:STParser.BOOLTRUEContext):
        pass


    # Enter a parse tree produced by STParser#BOOLFALSE.
    def enterBOOLFALSE(self, ctx:STParser.BOOLFALSEContext):
        pass

    # Exit a parse tree produced by STParser#BOOLFALSE.
    def exitBOOLFALSE(self, ctx:STParser.BOOLFALSEContext):
        pass


    # Enter a parse tree produced by STParser#VARPRIMARY.
    def enterVARPRIMARY(self, ctx:STParser.VARPRIMARYContext):
        pass

    # Exit a parse tree produced by STParser#VARPRIMARY.
    def exitVARPRIMARY(self, ctx:STParser.VARPRIMARYContext):
        pass


    # Enter a parse tree produced by STParser#ENUMPRIMARY.
    def enterENUMPRIMARY(self, ctx:STParser.ENUMPRIMARYContext):
        pass

    # Exit a parse tree produced by STParser#ENUMPRIMARY.
    def exitENUMPRIMARY(self, ctx:STParser.ENUMPRIMARYContext):
        pass


    # Enter a parse tree produced by STParser#SPECIALTOKEN.
    def enterSPECIALTOKEN(self, ctx:STParser.SPECIALTOKENContext):
        pass

    # Exit a parse tree produced by STParser#SPECIALTOKEN.
    def exitSPECIALTOKEN(self, ctx:STParser.SPECIALTOKENContext):
        pass


    # Enter a parse tree produced by STParser#varname.
    def enterVarname(self, ctx:STParser.VarnameContext):
        pass

    # Exit a parse tree produced by STParser#varname.
    def exitVarname(self, ctx:STParser.VarnameContext):
        pass


    # Enter a parse tree produced by STParser#number.
    def enterNumber(self, ctx:STParser.NumberContext):
        pass

    # Exit a parse tree produced by STParser#number.
    def exitNumber(self, ctx:STParser.NumberContext):
        pass


    # Enter a parse tree produced by STParser#timeval.
    def enterTimeval(self, ctx:STParser.TimevalContext):
        pass

    # Exit a parse tree produced by STParser#timeval.
    def exitTimeval(self, ctx:STParser.TimevalContext):
        pass


    # Enter a parse tree produced by STParser#listInitVar.
    def enterListInitVar(self, ctx:STParser.ListInitVarContext):
        pass

    # Exit a parse tree produced by STParser#listInitVar.
    def exitListInitVar(self, ctx:STParser.ListInitVarContext):
        pass


    # Enter a parse tree produced by STParser#idList.
    def enterIdList(self, ctx:STParser.IdListContext):
        pass

    # Exit a parse tree produced by STParser#idList.
    def exitIdList(self, ctx:STParser.IdListContext):
        pass



del STParser