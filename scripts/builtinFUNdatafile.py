builtinFunMap = dict()
builtinFunMap["LIMIT"] = [(3, "DINT", "DINT", "DINT", "DINT")]

builtinFunMap["MAX"] = [(2, "ANY", "ANY", "ANY")]
builtinFunMap["MIN"] = [(2, "ANY", "ANY", "ANY")]
builtinFunMap["ODD"] = [(1, "DINT", "BOOL")]
builtinFunMap["MUX4"] = [(5, "DINT", "ANY", "ANY", "ANY", "ANY", "ANY")]
builtinFunMap["MUX8"] = [(9, "DINT", "ANY", "ANY", "ANY", "ANY", "ANY", "ANY", "ANY", "ANY", "ANY")]
builtinFunMap["SEL"] = [(3, "BOOL", "ANY", "ANY", "ANY")]
builtinFunMap["RAND"] = [(1, "DINT", "DINT")]
builtinFunMap["ABS"] = [(1, "ANY", "ANY")]
builtinFunMap["EXP"] = [(1, "REAL", "REAL"), (1, "LREAL", "LREAL")]
builtinFunMap["EXPT"] = [(2, "REAL", "DINT", "REAL")]
builtinFunMap["LOG"] = [(1, "REAL", "REAL")]
builtinFunMap["LN"] = [(1, "REAL", "REAL"), (1, "LREAL", "LREAL")]
builtinFunMap["POW"] = [(2, "REAL", "REAL", "REAL"), (2, "LREAL", "LREAL", "LREAL")]
builtinFunMap["ROOT"] = [(2, "REAL", "DINT", "REAL")]
builtinFunMap["ScaleLIn"] = [(5, "REAL", "REAL", "REAL", "REAL", "REAL", "REAL")]
builtinFunMap["TRUNC"] = [(1, "REAL", "REAL"), (1, "LREAL", "LREAL")]

builtinFunMap["SIN"] = [(1, "REAL", "REAL")]
builtinFunMap["COS"] = [(1, "REAL", "REAL")]
builtinFunMap["TAN"] = [(1, "REAL", "REAL")]
builtinFunMap["ASIN"] = [(1, "REAL", "REAL")]
builtinFunMap["ACOS"] = [(1, "REAL", "REAL")]
builtinFunMap["ATAN"] = [(1, "REAL", "REAL")]

builtinFunMap["ANY_TO_TIME"] = [(1, "ANY", "TIME")]
builtinFunMap["ANY_TO_BOOL"] = [(1, "ANY", "BOOL")]
builtinFunMap["ANY_TO_SINT"] = [(1, "ANY", "SINT")]
builtinFunMap["ANY_TO_INT"] = [(1, "ANY", "INT")]
builtinFunMap["ANY_TO_SINT"] = [(1, "ANY", "SINT")]
builtinFunMap["ANY_TO_LINT"] = [(1, "ANY", "LINT")]
builtinFunMap["ANY_TO_REAL"] = [(1, "ANY", "REAL")]
builtinFunMap["ANY_TO_LREAL"] = [(1, "ANY", "LREAL")]
builtinFunMap["ANY_TO_STRING"] = [(1, "ANY", "STRING")]
builtinFunMap["ANY_TO_DINT"] = [(1, "ANY", "DINT")]
builtinFunMap["NUM_TO_STRING"] = [(1, "NUM", "STRING")]
builtinFunMap["UDINT_TO_DINT"] = [(1, "UDINT", "DINT")]
builtinFunMap["DINT_TO_UDINT"] = [(1, "DINT", "UDINT")]
builtinFunMap["BOOL_TO_UDINT"] = [(1, "BOOL", "UDINT")]
builtinFunMap["BOOL_TO_DINT"] = [(1, "BOOL", "DINT")]
builtinFunMap["DINT_TO_DINT"] = [(1, "DINT", "DINT")]
builtinFunMap["isConnected"] = [(1, "STRING", "BOOL")]
builtinFunMap["connectRequest"] = [(1, "STRING", "BOOL")]
builtinFunMap["disconnect"] = [(1, "STRING", "BOOL")]
builtinFunMap["sendData"] = [(4, "STRING", "STRING", "STRING", "ANY", "BOOL")]
builtinFunMap["rcvData"] = [(3, "STRING", "STRING", "STRING", "ANY")]
builtinFunMap["wrcvData"] = [(3, "STRING", "STRING", "STRING", "ANY")]

totalTYPES = ['BOOL' , 'DINT' , 'INT' , 'SINT','UDINT', 'UINT' , 'USINT', 'TIME', 'REAL', 'STRING']

def getBuiltinFun(funName):
    rawData = builtinFunMap[funName]
    return rawData

def getQOR(numOfArgument):
    data = [numOfArgument]
    for i in range(numOfArgument + 1): data.append("BOOL")
    return [tuple(data)]





