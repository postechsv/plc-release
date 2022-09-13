from dataFormat import VarFormat
from dataFormat import FBEnv
from dataFormat import numTypes
from dataFormat import usingedIntTypes
from dataFormat import intTypes
from dataFormat import realTypes
from dataFormat import totalRealType

def genDummpy(): return "DUMMY"

def makeVarFormat(name, type, dim, init):
    if dim == "DUMMY":
        return VarFormat(name, type, str(0), init)
    else:
        return VarFormat(name, type, dim, init)

def makeVarFormatListFromVarDecl(visitFunction, ctx, useType):
    varlist = list()
    for i in range(len(ctx.varDecl())): varlist.append(visitFunction(ctx.varDecl(i)))
    return updateUseTypeOfVars(varlist, useType)


def updateUseTypeOfVars(varlist, useType):
    for var in varlist:
        var.setUseType(useType)
    return varlist

def makeFBformat(pouType, pouName, visitFun, ctx, globalEnv=dict(), outputType="NONE"):
    targetPou = FBEnv()
    targetPou.setNameType(pouName, pouType, outputType)
    targetPou.setGlobalEnv(globalEnv)
    pouVars = visitFun( ctx.var_decl_collection() )
    targetPou.mergeGlobalLocal(pouVars)
    return targetPou

def makeStructureFBformat(pouType, pouName, visitFun, ctxs):
    targetPou = FBEnv()
    targetPou.setNameType(pouName, pouType, "NONE")
    targetPou.setGlobalEnv(dict())
    pouVars = list()
    for ctx in ctxs: pouVars.append( visitFun( ctx ) )
    targetPou.mergeGlobalLocal(pouVars)
    return targetPou

def makevarListTovarDict(varList):
    resultDict = dict()
    for element in varList: resultDict[element.name] = element
    return resultDict


def makeErrorMessage(instance, errorType, content, code):
    print(errorType, content)
    print("Error Code :", code)
    print()
    instance.switch = False


def checkWhetherTwoTypeSame(instance, left, right, code, switch=True):
    if left == right:
        if switch: return left, right
        else: return True

    if left in numTypes() and (not right in numTypes()):
        left = processNumType(instance, left, right, code, switch)
        right = left

    elif (not left in numTypes()) and right in numTypes():
        right = processNumType(instance, right, left, code, switch)
        left = right

    elif left in numTypes() and right in numTypes():
        if left == "NUMREAL" or right == "NUMREAL":
            if switch:
                makeErrorMessage(instance, "Type Error :","Type " + left + " and Type " + right + " must have same Type\nBut Real has " + left + ", right has " + right, code)
            left, right = "UNKNOWN", "UNKNOWN"


    else:
        if switch:
            makeErrorMessage(instance, "Type Error :", "Type " + left + " and Type " + right + " must have same Type\nBut Real has " + left + ", right has " + right, code)
        left, right = "UNKNOWN", "UNKNOWN"

    if switch:
        return left, right
    else:
        if left == "UNKNOWN": return False
        else: return True

def processNumType(instance, yesNum, noNum, code, switch=True):
    if noNum in usingedIntTypes() and ("PNUMINT" == yesNum or "NUMBIT" == yesNum):
        return noNum
    elif noNum in totalRealType():
        return "REAL"
    elif noNum in intTypes() and (not (yesNum in realTypes())):
        return noNum
    elif "BOOL" == noNum and ("NUMBIT" == yesNum):
        return "BOOL"
    else:
        if switch:
            makeErrorMessage(instance, "Type Error :", " Operation between integer type and real number cannot be allowed", code)
        return "UNKNOWN"

def decideMemberVarType(instance, currentType, nextVar, memberData, code):
    if nextVar in list(memberData.keys()):
        return memberData[nextVar].type, memberData[nextVar].useType
    else:
        makeErrorMessage(instance, "Type Error :", "There is no " + nextVar + " in " + currentType + "as member variable", code)
        return "UNKNOWN", "UNKNOWN"

def checkWhetherUnknownVar(instance, FB, targetVar, switch=True):
    if targetVar in FB.varEnv.keys():
        if switch:
            if int(FB.varEnv[targetVar].dim) > 0:
                FB.type[targetVar] = "ARRAY[" + FB.varEnv[targetVar].type + "]"
            else:
                FB.type[targetVar] = FB.varEnv[targetVar].type

        return True
    else:
        if switch: makeErrorMessage(instance, "Error :", "Unkown variable", targetVar)
        if switch: FB.type[targetVar] = "UNKNOWN"
        return False

def checkFB(FB, nowPOU, target):
    if not nowPOU in list(FB.keys()):
        return False, "UNKNOWN", -1

    if target in list(FB[nowPOU].varEnv.keys()):
        useType = FB[nowPOU].varEnv[target].useType
        if useType in ["##IN", "##INOUT"]: return False, "UNKNOWN"
        return True, FB[nowPOU].varEnv[target].type, FB[nowPOU].varEnv[target].dim
    return False, "UNKNOWN", -1

def checkBitField(bitfields, target):
    for bitfield in list(bitfields.keys()):
        if target in bitfields[bitfield].vars or target.isdigit():
            return True, "NUMBIT"
    return False, "UNKNOWN"

def checkENUM(enums, target):
    for enum in list(enums.keys()):
        if target in enums[enum].vars:
            return True, enum
    return False, "UNKNWON"

def checkFunctionBlockCallArgument(instance, parameters, arguments, codes):
    sizeOfArguments = len(parameters)

    for i in range(0, sizeOfArguments):
        if not checkWhetherTwoTypeSame(instance, parameters[i], arguments[i][1], codes, switch=False):
            makeErrorMessage(instance, "Type Error :", "Arguments don't have correct type", codes)
            return

def checkFunctionBlockCallArgumentMapping(instance, FB, arguments, codes):
    for (varName, exprType) in arguments:
        if varName in list(FB.varEnv.keys()):
            result = checkWhetherTwoTypeSame(instance, FB.varEnv[varName].type, exprType, codes, switch=False)
            if not result:
                makeErrorMessage(instance, "Type Error :", "Invalid Argument Mapping", codes)
        else:
            makeErrorMessage(instance, "Unknown parameter : ", varName + "is not in " + FB.pouName, codes)
            return


def insertExplicitConversion(FBtype, rawLeft, processedLeft, rawRight, processedRight, totalType):
    leftType = FBtype[rawLeft]
    rightType = FBtype[rawRight]


    if "NUM" in leftType and "NUM" in rightType: return processedLeft, processedRight
    elif "NUM" in leftType : return "(ANYTO" + rightType + "(" + processedLeft + "))" , processedRight
    elif "NUM" in rightType: return processedLeft , "(ANYTO" + leftType + "(" + processedRight + "))"
    else: return processedLeft, processedRight


def returnVarDeclMaude(var):
    if len(var.init) == 0: return var.name + " : " + var.type
    else: return var.name + " : " + var.type + " := " + " , ".join(var.init)
