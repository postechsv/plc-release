#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
#include <math.h>

// Declare nondet assignment functions
bool nondet_bool();
uint8_t nondet_uint8_t();
uint16_t nondet_uint16_t();
uint32_t nondet_uint32_t();
uint64_t nondet_uint64_t();
int8_t nondet_int8_t();
int16_t nondet_int16_t();
int32_t nondet_int32_t();
int64_t nondet_int64_t();
double nondet_float();
double nondet_double();

// Root data structure
typedef struct {
	bool Activate;
	bool S_ESPE_In;
	bool S_StartReset;
	bool S_AutoReset;
	bool Reset;
	bool Ready;
	bool S_ESPE_Out;
	bool Error;
	int32_t DiagCode;
} __SF_ESPE;
typedef struct {
	bool Activate;
	bool S_EStopIn;
	bool S_StartReset;
	bool S_AutoReset;
	bool Reset;
	bool Ready;
	bool S_EStopOut;
	bool Error;
	int32_t DiagCode;
} __SF_EmergencyStop;
typedef struct {
	bool Activate;
	bool S_ChannelA;
	bool S_ChannelB;
	bool Ready;
	bool S_EquivalentOut;
	bool Error;
	int32_t DiagCode;
} __SF_Equivalent;
typedef struct {
	bool Activate;
	bool S_StopIn;
	int32_t AxisID;
	int32_t MonitoringTime;
	bool Reset;
	bool Acknowledge;
	bool Ready;
	bool S_Stopped;
	bool Error;
	int32_t DiagCode;
} __SF_SafeStop1;
typedef struct {
	bool S1_S_EStopIn_1;
	bool S1_S_EStopIn_2;
	bool S2_S_ESPE_In;
	bool S0_Reset;
	bool S3_Drive_Reset;
	int32_t AxisD_1;
	bool InputDevice1_active;
	bool InputDevice2_active;
	bool Internal_Acknowledge;
	bool Error_Equiv1;
	int32_t Diag_Equiv1;
	bool Error_EStop1;
	int32_t Diag_EStop1;
	bool Error_ESPE1;
	int32_t Diag_ESPE1;
	bool Error_SafeStop1;
	int32_t Diag_SafeStop1;
	bool S_Stopped;
	bool S_EStopOut;
	__SF_Equivalent SF_Equivalent_1;
	__SF_EmergencyStop SF_EmergencyStop_1;
	__SF_ESPE SF_ESPE_1;
	__SF_SafeStop1 SF_SafeStop1_1;
	int32_t CYCLE;
} __Main;

// Global variables
__Main instance;
bool EoC;
bool __cbmc_eoc_marker;

// Automata declarations
void Main(__Main *__context);
void SF_Equivalent(__SF_Equivalent *__context);
void SF_EmergencyStop(__SF_EmergencyStop *__context);
void SF_ESPE(__SF_ESPE *__context);
void SF_SafeStop1(__SF_SafeStop1 *__context);
void VerificationLoop();

// Automata
void Main(__Main *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init;
	init: {
			__context->CYCLE = (__context->CYCLE + 1);
			goto l1;
		//assert(false);
		return;  			}
	l1: {
			// Assign inputs
			__context->SF_Equivalent_1.Activate = __context->InputDevice1_active;
			__context->SF_Equivalent_1.S_ChannelA = __context->S1_S_EStopIn_1;
			__context->SF_Equivalent_1.S_ChannelB = __context->S1_S_EStopIn_2;
			SF_Equivalent(&__context->SF_Equivalent_1);
			// Assign outputs
			goto l2;
		//assert(false);
		return;  			}
	l2: {
			// Assign inputs
			__context->SF_EmergencyStop_1.Activate = __context->SF_Equivalent_1.Ready;
			__context->SF_EmergencyStop_1.S_EStopIn = __context->SF_Equivalent_1.S_EquivalentOut;
			__context->SF_EmergencyStop_1.S_StartReset = false;
			__context->SF_EmergencyStop_1.S_AutoReset = false;
			__context->SF_EmergencyStop_1.Reset = __context->S0_Reset;
			SF_EmergencyStop(&__context->SF_EmergencyStop_1);
			// Assign outputs
			goto l3;
		//assert(false);
		return;  			}
	l3: {
			// Assign inputs
			__context->SF_ESPE_1.Activate = __context->InputDevice2_active;
			__context->SF_ESPE_1.S_ESPE_In = __context->S2_S_ESPE_In;
			__context->SF_ESPE_1.S_StartReset = false;
			__context->SF_ESPE_1.S_AutoReset = false;
			__context->SF_ESPE_1.Reset = __context->S0_Reset;
			SF_ESPE(&__context->SF_ESPE_1);
			// Assign outputs
			goto l4;
		//assert(false);
		return;  			}
	l4: {
			// Assign inputs
			__context->SF_SafeStop1_1.Activate = (__context->SF_EmergencyStop_1.Ready && __context->SF_ESPE_1.Ready);
			__context->SF_SafeStop1_1.S_StopIn = (__context->S_EStopOut && __context->SF_ESPE_1.S_ESPE_Out);
			__context->SF_SafeStop1_1.AxisID = __context->AxisD_1;
			__context->SF_SafeStop1_1.MonitoringTime = 100;
			__context->SF_SafeStop1_1.Reset = __context->S3_Drive_Reset;
			__context->SF_SafeStop1_1.Acknowledge = __context->Internal_Acknowledge;
			SF_SafeStop1(&__context->SF_SafeStop1_1);
			// Assign outputs
			goto l5;
		//assert(false);
		return;  			}
	l5: {
			__context->S_EStopOut = __context->SF_EmergencyStop_1.S_EStopOut;
			__context->Error_Equiv1 = __context->SF_Equivalent_1.Error;
			__context->Diag_Equiv1 = __context->SF_Equivalent_1.DiagCode;
			__context->Error_EStop1 = __context->SF_EmergencyStop_1.Error;
			__context->Diag_EStop1 = __context->SF_EmergencyStop_1.DiagCode;
			__context->Error_ESPE1 = __context->SF_ESPE_1.Error;
			__context->Diag_ESPE1 = __context->SF_ESPE_1.DiagCode;
			__context->Error_SafeStop1 = __context->SF_SafeStop1_1.Error;
			__context->Diag_SafeStop1 = __context->SF_SafeStop1_1.DiagCode;
			__context->S_Stopped = __context->SF_SafeStop1_1.S_Stopped;
			goto l15;
		//assert(false);
		return;  			}
	l15: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void SF_Equivalent(__SF_Equivalent *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init1;
	init1: {
		if ((! __context->Activate)) {
			__context->DiagCode = 0;
			goto l75;
		}
		if ((! (! __context->Activate))) {
			goto l31;
		}
		//assert(false);
		return;  			}
	l31: {
		if ((__context->DiagCode == 0)) {
			goto l51;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l6;
		}
		//assert(false);
		return;  			}
	l41: {
			goto l75;
		//assert(false);
		return;  			}
	l51: {
		if (__context->Activate) {
			__context->DiagCode = 32769;
			goto l10;
		}
		if ((! __context->Activate)) {
			goto l10;
		}
		//assert(false);
		return;  			}
	l6: {
		if ((__context->DiagCode == 32769)) {
			goto l11;
		}
		if ((! (__context->DiagCode == 32769))) {
			goto l12;
		}
		//assert(false);
		return;  			}
	l10: {
			goto l41;
		//assert(false);
		return;  			}
	l11: {
		if ((__context->S_ChannelA && (! __context->S_ChannelB))) {
			__context->DiagCode = 32772;
			goto l20;
		}
		if (((! (__context->S_ChannelA && (! __context->S_ChannelB))) && (__context->S_ChannelB && (! __context->S_ChannelA)))) {
			__context->DiagCode = 32788;
			goto l20;
		}
		if ((((! (__context->S_ChannelA && (! __context->S_ChannelB))) && (! (__context->S_ChannelB && (! __context->S_ChannelA)))) && (__context->S_ChannelA && __context->S_ChannelB))) {
			__context->DiagCode = 32768;
			goto l20;
		}
		if (((! (__context->S_ChannelA && (! __context->S_ChannelB))) && ((! ((! (__context->S_ChannelA && (! __context->S_ChannelB))) && (__context->S_ChannelB && (! __context->S_ChannelA)))) && (! (((! (__context->S_ChannelA && (! __context->S_ChannelB))) && (! (__context->S_ChannelB && (! __context->S_ChannelA)))) && (__context->S_ChannelA && __context->S_ChannelB)))))) {
			goto l20;
		}
		//assert(false);
		return;  			}
	l12: {
		if ((__context->DiagCode == 32772)) {
			goto l21;
		}
		if ((! (__context->DiagCode == 32772))) {
			goto l22;
		}
		//assert(false);
		return;  			}
	l20: {
			goto l41;
		//assert(false);
		return;  			}
	l21: {
		if (__context->Activate) {
			__context->DiagCode = 49153;
			goto l30;
		}
		if (((! __context->Activate) && (! __context->S_ChannelA))) {
			__context->DiagCode = 32769;
			goto l30;
		}
		if ((((! __context->Activate) && (! (! __context->S_ChannelA))) && __context->S_ChannelB)) {
			__context->DiagCode = 32768;
			goto l30;
		}
		if (((! __context->Activate) && ((! ((! __context->Activate) && (! __context->S_ChannelA))) && (! (((! __context->Activate) && (! (! __context->S_ChannelA))) && __context->S_ChannelB))))) {
			goto l30;
		}
		//assert(false);
		return;  			}
	l22: {
		if ((__context->DiagCode == 49153)) {
			goto l311;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l32;
		}
		//assert(false);
		return;  			}
	l30: {
			goto l41;
		//assert(false);
		return;  			}
	l311: {
		if (((! __context->S_ChannelA) && (! __context->S_ChannelB))) {
			__context->DiagCode = 32769;
			goto l36;
		}
		if ((! ((! __context->S_ChannelA) && (! __context->S_ChannelB)))) {
			goto l36;
		}
		//assert(false);
		return;  			}
	l32: {
		if ((__context->DiagCode == 49154)) {
			goto l37;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l38;
		}
		//assert(false);
		return;  			}
	l36: {
			goto l41;
		//assert(false);
		return;  			}
	l37: {
		if (((! __context->S_ChannelA) && (! __context->S_ChannelB))) {
			__context->DiagCode = 32769;
			goto l42;
		}
		if ((! ((! __context->S_ChannelA) && (! __context->S_ChannelB)))) {
			goto l42;
		}
		//assert(false);
		return;  			}
	l38: {
		if ((__context->DiagCode == 32788)) {
			goto l43;
		}
		if ((! (__context->DiagCode == 32788))) {
			goto l44;
		}
		//assert(false);
		return;  			}
	l42: {
			goto l41;
		//assert(false);
		return;  			}
	l43: {
		if (__context->Activate) {
			__context->DiagCode = 49154;
			goto l52;
		}
		if (((! __context->Activate) && (! __context->S_ChannelB))) {
			__context->DiagCode = 32769;
			goto l52;
		}
		if ((((! __context->Activate) && (! (! __context->S_ChannelB))) && __context->S_ChannelA)) {
			__context->DiagCode = 32768;
			goto l52;
		}
		if (((! __context->Activate) && ((! ((! __context->Activate) && (! __context->S_ChannelB))) && (! (((! __context->Activate) && (! (! __context->S_ChannelB))) && __context->S_ChannelA))))) {
			goto l52;
		}
		//assert(false);
		return;  			}
	l44: {
		if ((__context->DiagCode == 49155)) {
			goto l53;
		}
		if ((! (__context->DiagCode == 49155))) {
			goto l54;
		}
		//assert(false);
		return;  			}
	l52: {
			goto l41;
		//assert(false);
		return;  			}
	l53: {
		if (((! __context->S_ChannelA) && (! __context->S_ChannelB))) {
			__context->DiagCode = 32769;
			goto l58;
		}
		if ((! ((! __context->S_ChannelA) && (! __context->S_ChannelB)))) {
			goto l58;
		}
		//assert(false);
		return;  			}
	l54: {
		if ((__context->DiagCode == 32773)) {
			goto l59;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l60;
		}
		//assert(false);
		return;  			}
	l58: {
			goto l41;
		//assert(false);
		return;  			}
	l59: {
		if (__context->Activate) {
			__context->DiagCode = 49155;
			goto l66;
		}
		if (((! __context->Activate) && ((! __context->S_ChannelA) && (! __context->S_ChannelB)))) {
			__context->DiagCode = 32769;
			goto l66;
		}
		if (((! __context->Activate) && (! ((! __context->Activate) && ((! __context->S_ChannelA) && (! __context->S_ChannelB)))))) {
			goto l66;
		}
		//assert(false);
		return;  			}
	l60: {
		if ((__context->DiagCode == 32768)) {
			goto l67;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l41;
		}
		//assert(false);
		return;  			}
	l66: {
			goto l41;
		//assert(false);
		return;  			}
	l67: {
		if ((__context->S_ChannelA != __context->S_ChannelB)) {
			__context->DiagCode = 32773;
			goto l74;
		}
		if (((! (__context->S_ChannelA != __context->S_ChannelB)) && ((! __context->S_ChannelA) && (! __context->S_ChannelB)))) {
			__context->DiagCode = 32769;
			goto l74;
		}
		if (((! (__context->S_ChannelA != __context->S_ChannelB)) && (! ((! (__context->S_ChannelA != __context->S_ChannelB)) && ((! __context->S_ChannelA) && (! __context->S_ChannelB)))))) {
			goto l74;
		}
		//assert(false);
		return;  			}
	l74: {
			goto l41;
		//assert(false);
		return;  			}
	l75: {
		if ((__context->DiagCode == 0)) {
			__context->Ready = false;
			__context->Error = false;
			__context->S_EquivalentOut = false;
			goto l76;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l78;
		}
		//assert(false);
		return;  			}
	l76: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l78: {
		if ((__context->DiagCode == 32768)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_EquivalentOut = true;
			goto l76;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l83;
		}
		//assert(false);
		return;  			}
	l83: {
		if ((__context->DiagCode == 32769)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_EquivalentOut = false;
			goto l76;
		}
		if ((! (__context->DiagCode == 32769))) {
			goto l88;
		}
		//assert(false);
		return;  			}
	l88: {
		if ((__context->DiagCode == 32772)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_EquivalentOut = false;
			goto l76;
		}
		if ((! (__context->DiagCode == 32772))) {
			goto l93;
		}
		//assert(false);
		return;  			}
	l93: {
		if ((__context->DiagCode == 32788)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_EquivalentOut = false;
			goto l76;
		}
		if ((! (__context->DiagCode == 32788))) {
			goto l98;
		}
		//assert(false);
		return;  			}
	l98: {
		if ((__context->DiagCode == 32773)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_EquivalentOut = false;
			goto l76;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l103;
		}
		//assert(false);
		return;  			}
	l103: {
		if ((__context->DiagCode == 49153)) {
			__context->Ready = true;
			__context->Error = true;
			__context->S_EquivalentOut = false;
			goto l76;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l108;
		}
		//assert(false);
		return;  			}
	l108: {
		if ((__context->DiagCode == 49154)) {
			__context->Ready = true;
			__context->Error = true;
			__context->S_EquivalentOut = false;
			goto l76;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l113;
		}
		//assert(false);
		return;  			}
	l113: {
		if ((__context->DiagCode == 49155)) {
			__context->Ready = true;
			__context->Error = true;
			__context->S_EquivalentOut = false;
			goto l76;
		}
		if ((! (__context->DiagCode == 49155))) {
			goto l76;
		}
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void SF_EmergencyStop(__SF_EmergencyStop *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init2;
	init2: {
		if ((! __context->Activate)) {
			__context->DiagCode = 0;
			goto l71;
		}
		if ((! (! __context->Activate))) {
			goto l33;
		}
		//assert(false);
		return;  			}
	l33: {
		if ((__context->DiagCode == 0)) {
			goto l55;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l61;
		}
		//assert(false);
		return;  			}
	l45: {
			goto l71;
		//assert(false);
		return;  			}
	l55: {
		if (__context->Activate) {
			__context->DiagCode = 32769;
			goto l101;
		}
		if ((! __context->Activate)) {
			goto l101;
		}
		//assert(false);
		return;  			}
	l61: {
		if ((__context->DiagCode == 32769)) {
			goto l111;
		}
		if ((! (__context->DiagCode == 32769))) {
			goto l121;
		}
		//assert(false);
		return;  			}
	l101: {
			goto l45;
		//assert(false);
		return;  			}
	l111: {
		if ((! __context->S_StartReset)) {
			__context->DiagCode = 32770;
			goto l201;
		}
		if (((! (! __context->S_StartReset)) && (__context->S_StartReset && (! __context->S_EStopIn)))) {
			__context->DiagCode = 32772;
			goto l201;
		}
		if ((((! (! __context->S_StartReset)) && (! (__context->S_StartReset && (! __context->S_EStopIn)))) && (__context->S_EStopIn && __context->S_StartReset))) {
			__context->DiagCode = 32768;
			goto l201;
		}
		if (((! (! __context->S_StartReset)) && ((! ((! (! __context->S_StartReset)) && (__context->S_StartReset && (! __context->S_EStopIn)))) && (! (((! (! __context->S_StartReset)) && (! (__context->S_StartReset && (! __context->S_EStopIn)))) && (__context->S_EStopIn && __context->S_StartReset)))))) {
			goto l201;
		}
		//assert(false);
		return;  			}
	l121: {
		if ((__context->DiagCode == 32770)) {
			goto l211;
		}
		if ((! (__context->DiagCode == 32770))) {
			goto l221;
		}
		//assert(false);
		return;  			}
	l201: {
			goto l45;
		//assert(false);
		return;  			}
	l211: {
		if (__context->S_EStopIn) {
			__context->DiagCode = 32771;
			goto l26;
		}
		if ((! __context->S_EStopIn)) {
			goto l26;
		}
		//assert(false);
		return;  			}
	l221: {
		if ((__context->DiagCode == 32771)) {
			goto l27;
		}
		if ((! (__context->DiagCode == 32771))) {
			goto l28;
		}
		//assert(false);
		return;  			}
	l26: {
			goto l45;
		//assert(false);
		return;  			}
	l27: {
		if (__context->Reset) {
			__context->DiagCode = 49153;
			goto l34;
		}
		if (((! __context->Reset) && (! __context->S_EStopIn))) {
			__context->DiagCode = 32770;
			goto l34;
		}
		if (((! __context->Reset) && (! ((! __context->Reset) && (! __context->S_EStopIn))))) {
			goto l34;
		}
		//assert(false);
		return;  			}
	l28: {
		if ((__context->DiagCode == 49153)) {
			goto l35;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l361;
		}
		//assert(false);
		return;  			}
	l34: {
			goto l45;
		//assert(false);
		return;  			}
	l35: {
		if ((! __context->Reset)) {
			__context->DiagCode = 32771;
			goto l40;
		}
		if ((! (! __context->Reset))) {
			goto l40;
		}
		//assert(false);
		return;  			}
	l361: {
		if ((__context->DiagCode == 32772)) {
			goto l411;
		}
		if ((! (__context->DiagCode == 32772))) {
			goto l421;
		}
		//assert(false);
		return;  			}
	l40: {
			goto l45;
		//assert(false);
		return;  			}
	l411: {
		if ((__context->S_EStopIn && (! __context->S_AutoReset))) {
			__context->DiagCode = 32773;
			goto l48;
		}
		if (((! (__context->S_EStopIn && (! __context->S_AutoReset))) && (__context->S_EStopIn && __context->S_AutoReset))) {
			__context->DiagCode = 32768;
			goto l48;
		}
		if (((! (__context->S_EStopIn && (! __context->S_AutoReset))) && (! ((! (__context->S_EStopIn && (! __context->S_AutoReset))) && (__context->S_EStopIn && __context->S_AutoReset))))) {
			goto l48;
		}
		//assert(false);
		return;  			}
	l421: {
		if ((__context->DiagCode == 32773)) {
			goto l49;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l50;
		}
		//assert(false);
		return;  			}
	l48: {
			goto l45;
		//assert(false);
		return;  			}
	l49: {
		if (__context->Reset) {
			__context->DiagCode = 49154;
			goto l581;
		}
		if (((! __context->Reset) && (! __context->S_EStopIn))) {
			__context->DiagCode = 32772;
			goto l581;
		}
		if ((((! __context->Reset) && (! (! __context->S_EStopIn))) && __context->S_AutoReset)) {
			__context->DiagCode = 32768;
			goto l581;
		}
		if (((! __context->Reset) && ((! ((! __context->Reset) && (! __context->S_EStopIn))) && (! (((! __context->Reset) && (! (! __context->S_EStopIn))) && __context->S_AutoReset))))) {
			goto l581;
		}
		//assert(false);
		return;  			}
	l50: {
		if ((__context->DiagCode == 49154)) {
			goto l591;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l601;
		}
		//assert(false);
		return;  			}
	l581: {
			goto l45;
		//assert(false);
		return;  			}
	l591: {
		if ((! __context->Reset)) {
			__context->DiagCode = 32773;
			goto l64;
		}
		if ((! (! __context->Reset))) {
			goto l64;
		}
		//assert(false);
		return;  			}
	l601: {
		if ((__context->DiagCode == 32768)) {
			goto l65;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l45;
		}
		//assert(false);
		return;  			}
	l64: {
			goto l45;
		//assert(false);
		return;  			}
	l65: {
		if ((! __context->S_EStopIn)) {
			__context->DiagCode = 32772;
			goto l70;
		}
		if ((! (! __context->S_EStopIn))) {
			goto l70;
		}
		//assert(false);
		return;  			}
	l70: {
			goto l45;
		//assert(false);
		return;  			}
	l71: {
		if ((__context->DiagCode == 0)) {
			__context->Ready = false;
			__context->Error = false;
			__context->S_EStopOut = false;
			goto l72;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l741;
		}
		//assert(false);
		return;  			}
	l72: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l741: {
		if ((__context->DiagCode == 32769)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_EStopOut = false;
			goto l72;
		}
		if ((! (__context->DiagCode == 32769))) {
			goto l79;
		}
		//assert(false);
		return;  			}
	l79: {
		if ((__context->DiagCode == 32770)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_EStopOut = false;
			goto l72;
		}
		if ((! (__context->DiagCode == 32770))) {
			goto l84;
		}
		//assert(false);
		return;  			}
	l84: {
		if ((__context->DiagCode == 32771)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_EStopOut = false;
			goto l72;
		}
		if ((! (__context->DiagCode == 32771))) {
			goto l89;
		}
		//assert(false);
		return;  			}
	l89: {
		if ((__context->DiagCode == 49153)) {
			__context->Ready = true;
			__context->Error = true;
			__context->S_EStopOut = false;
			goto l72;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l94;
		}
		//assert(false);
		return;  			}
	l94: {
		if ((__context->DiagCode == 32772)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_EStopOut = false;
			goto l72;
		}
		if ((! (__context->DiagCode == 32772))) {
			goto l99;
		}
		//assert(false);
		return;  			}
	l99: {
		if ((__context->DiagCode == 32773)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_EStopOut = false;
			goto l72;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l104;
		}
		//assert(false);
		return;  			}
	l104: {
		if ((__context->DiagCode == 49154)) {
			__context->Ready = true;
			__context->Error = true;
			__context->S_EStopOut = false;
			goto l72;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l109;
		}
		//assert(false);
		return;  			}
	l109: {
		if ((__context->DiagCode == 32768)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_EStopOut = true;
			goto l72;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l72;
		}
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void SF_ESPE(__SF_ESPE *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init3;
	init3: {
		if ((! __context->Activate)) {
			__context->DiagCode = 0;
			goto l69;
		}
		if ((! (! __context->Activate))) {
			goto l39;
		}
		//assert(false);
		return;  			}
	l39: {
		if ((__context->DiagCode == 0)) {
			goto l56;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l62;
		}
		//assert(false);
		return;  			}
	l46: {
			goto l69;
		//assert(false);
		return;  			}
	l56: {
		if (__context->Activate) {
			__context->DiagCode = 32769;
			goto l102;
		}
		if ((! __context->Activate)) {
			goto l102;
		}
		//assert(false);
		return;  			}
	l62: {
		if ((__context->DiagCode == 32769)) {
			goto l112;
		}
		if ((! (__context->DiagCode == 32769))) {
			goto l122;
		}
		//assert(false);
		return;  			}
	l102: {
			goto l46;
		//assert(false);
		return;  			}
	l112: {
		if ((! __context->S_StartReset)) {
			__context->DiagCode = 32770;
			goto l202;
		}
		if (((! (! __context->S_StartReset)) && (__context->S_StartReset && (! __context->S_ESPE_In)))) {
			__context->DiagCode = 32772;
			goto l202;
		}
		if ((((! (! __context->S_StartReset)) && (! (__context->S_StartReset && (! __context->S_ESPE_In)))) && (__context->S_ESPE_In && __context->S_StartReset))) {
			__context->DiagCode = 32768;
			goto l202;
		}
		if (((! (! __context->S_StartReset)) && ((! ((! (! __context->S_StartReset)) && (__context->S_StartReset && (! __context->S_ESPE_In)))) && (! (((! (! __context->S_StartReset)) && (! (__context->S_StartReset && (! __context->S_ESPE_In)))) && (__context->S_ESPE_In && __context->S_StartReset)))))) {
			goto l202;
		}
		//assert(false);
		return;  			}
	l122: {
		if ((__context->DiagCode == 32770)) {
			goto l212;
		}
		if ((! (__context->DiagCode == 32770))) {
			goto l222;
		}
		//assert(false);
		return;  			}
	l202: {
			goto l46;
		//assert(false);
		return;  			}
	l212: {
		if (__context->S_ESPE_In) {
			__context->DiagCode = 32771;
			goto l261;
		}
		if ((! __context->S_ESPE_In)) {
			goto l261;
		}
		//assert(false);
		return;  			}
	l222: {
		if ((__context->DiagCode == 32771)) {
			goto l271;
		}
		if ((! (__context->DiagCode == 32771))) {
			goto l281;
		}
		//assert(false);
		return;  			}
	l261: {
			goto l46;
		//assert(false);
		return;  			}
	l271: {
		if (__context->Reset) {
			__context->DiagCode = 49153;
			goto l341;
		}
		if (((! __context->Reset) && (! __context->S_ESPE_In))) {
			__context->DiagCode = 32770;
			goto l341;
		}
		if (((! __context->Reset) && (! ((! __context->Reset) && (! __context->S_ESPE_In))))) {
			goto l341;
		}
		//assert(false);
		return;  			}
	l281: {
		if ((__context->DiagCode == 49153)) {
			goto l351;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l362;
		}
		//assert(false);
		return;  			}
	l341: {
			goto l46;
		//assert(false);
		return;  			}
	l351: {
		if ((! __context->Reset)) {
			__context->DiagCode = 32771;
			goto l401;
		}
		if ((! (! __context->Reset))) {
			goto l401;
		}
		//assert(false);
		return;  			}
	l362: {
		if ((__context->DiagCode == 32772)) {
			goto l412;
		}
		if ((! (__context->DiagCode == 32772))) {
			goto l422;
		}
		//assert(false);
		return;  			}
	l401: {
			goto l46;
		//assert(false);
		return;  			}
	l412: {
		if ((__context->S_ESPE_In && (! __context->S_AutoReset))) {
			__context->DiagCode = 32773;
			goto l481;
		}
		if (((! (__context->S_ESPE_In && (! __context->S_AutoReset))) && (__context->S_ESPE_In && __context->S_AutoReset))) {
			__context->DiagCode = 32768;
			goto l481;
		}
		if (((! (__context->S_ESPE_In && (! __context->S_AutoReset))) && (! ((! (__context->S_ESPE_In && (! __context->S_AutoReset))) && (__context->S_ESPE_In && __context->S_AutoReset))))) {
			goto l481;
		}
		//assert(false);
		return;  			}
	l422: {
		if ((__context->DiagCode == 32773)) {
			goto l491;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l501;
		}
		//assert(false);
		return;  			}
	l481: {
			goto l46;
		//assert(false);
		return;  			}
	l491: {
		if (__context->Reset) {
			__context->DiagCode = 49154;
			goto l561;
		}
		if (((! __context->Reset) && (! __context->S_ESPE_In))) {
			__context->DiagCode = 32772;
			goto l561;
		}
		if (((! __context->Reset) && (! ((! __context->Reset) && (! __context->S_ESPE_In))))) {
			goto l561;
		}
		//assert(false);
		return;  			}
	l501: {
		if ((__context->DiagCode == 49154)) {
			goto l57;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l582;
		}
		//assert(false);
		return;  			}
	l561: {
			goto l46;
		//assert(false);
		return;  			}
	l57: {
		if ((! __context->Reset)) {
			__context->DiagCode = 32773;
			goto l621;
		}
		if ((! (! __context->Reset))) {
			goto l621;
		}
		//assert(false);
		return;  			}
	l582: {
		if ((__context->DiagCode == 32768)) {
			goto l63;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l46;
		}
		//assert(false);
		return;  			}
	l621: {
			goto l46;
		//assert(false);
		return;  			}
	l63: {
		if ((! __context->S_ESPE_In)) {
			__context->DiagCode = 32772;
			goto l68;
		}
		if ((! (! __context->S_ESPE_In))) {
			goto l68;
		}
		//assert(false);
		return;  			}
	l68: {
			goto l46;
		//assert(false);
		return;  			}
	l69: {
		if ((__context->DiagCode == 0)) {
			__context->Ready = false;
			__context->Error = false;
			__context->S_ESPE_Out = false;
			goto l701;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l721;
		}
		//assert(false);
		return;  			}
	l701: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l721: {
		if ((__context->DiagCode == 32769)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_ESPE_Out = false;
			goto l701;
		}
		if ((! (__context->DiagCode == 32769))) {
			goto l77;
		}
		//assert(false);
		return;  			}
	l77: {
		if ((__context->DiagCode == 32770)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_ESPE_Out = false;
			goto l701;
		}
		if ((! (__context->DiagCode == 32770))) {
			goto l82;
		}
		//assert(false);
		return;  			}
	l82: {
		if ((__context->DiagCode == 32771)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_ESPE_Out = false;
			goto l701;
		}
		if ((! (__context->DiagCode == 32771))) {
			goto l87;
		}
		//assert(false);
		return;  			}
	l87: {
		if ((__context->DiagCode == 49153)) {
			__context->Ready = true;
			__context->Error = true;
			__context->S_ESPE_Out = false;
			goto l701;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l92;
		}
		//assert(false);
		return;  			}
	l92: {
		if ((__context->DiagCode == 32772)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_ESPE_Out = false;
			goto l701;
		}
		if ((! (__context->DiagCode == 32772))) {
			goto l97;
		}
		//assert(false);
		return;  			}
	l97: {
		if ((__context->DiagCode == 32773)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_ESPE_Out = false;
			goto l701;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l1021;
		}
		//assert(false);
		return;  			}
	l1021: {
		if ((__context->DiagCode == 49154)) {
			__context->Ready = true;
			__context->Error = true;
			__context->S_ESPE_Out = false;
			goto l701;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l107;
		}
		//assert(false);
		return;  			}
	l107: {
		if ((__context->DiagCode == 32768)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_ESPE_Out = true;
			goto l701;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l701;
		}
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void SF_SafeStop1(__SF_SafeStop1 *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init4;
	init4: {
		if ((! __context->Activate)) {
			__context->DiagCode = 0;
			goto l831;
		}
		if ((! (! __context->Activate))) {
			goto l310;
		}
		//assert(false);
		return;  			}
	l310: {
		if ((__context->DiagCode == 0)) {
			goto l510;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l610;
		}
		//assert(false);
		return;  			}
	l47: {
			goto l831;
		//assert(false);
		return;  			}
	l510: {
		if (__context->Activate) {
			__context->DiagCode = 32769;
			goto l105;
		}
		if ((! __context->Activate)) {
			goto l105;
		}
		//assert(false);
		return;  			}
	l610: {
		if ((__context->DiagCode == 32768)) {
			goto l114;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l123;
		}
		//assert(false);
		return;  			}
	l105: {
			goto l47;
		//assert(false);
		return;  			}
	l114: {
		if ((! __context->Acknowledge)) {
			__context->DiagCode = 49154;
			goto l18;
		}
		if (((! (! __context->Acknowledge)) && __context->S_StopIn)) {
			__context->DiagCode = 32786;
			goto l18;
		}
		if (((! (! __context->Acknowledge)) && (! ((! (! __context->Acknowledge)) && __context->S_StopIn)))) {
			goto l18;
		}
		//assert(false);
		return;  			}
	l123: {
		if ((__context->DiagCode == 32769)) {
			goto l19;
		}
		if ((! (__context->DiagCode == 32769))) {
			goto l203;
		}
		//assert(false);
		return;  			}
	l18: {
			goto l47;
		//assert(false);
		return;  			}
	l19: {
		if ((! __context->Acknowledge)) {
			__context->DiagCode = 32770;
			goto l262;
		}
		if (((! (! __context->Acknowledge)) && __context->Acknowledge)) {
			__context->DiagCode = 32786;
			goto l262;
		}
		if (((! (! __context->Acknowledge)) && (! ((! (! __context->Acknowledge)) && __context->Acknowledge)))) {
			goto l262;
		}
		//assert(false);
		return;  			}
	l203: {
		if ((__context->DiagCode == 32770)) {
			goto l272;
		}
		if ((! (__context->DiagCode == 32770))) {
			goto l282;
		}
		//assert(false);
		return;  			}
	l262: {
			goto l47;
		//assert(false);
		return;  			}
	l272: {
		if ((! __context->S_StopIn)) {
			__context->DiagCode = 32771;
			goto l342;
		}
		if (((! (! __context->S_StopIn)) && __context->Acknowledge)) {
			__context->DiagCode = 32786;
			goto l342;
		}
		if (((! (! __context->S_StopIn)) && (! ((! (! __context->S_StopIn)) && __context->Acknowledge)))) {
			goto l342;
		}
		//assert(false);
		return;  			}
	l282: {
		if ((__context->DiagCode == 32771)) {
			goto l352;
		}
		if ((! (__context->DiagCode == 32771))) {
			goto l363;
		}
		//assert(false);
		return;  			}
	l342: {
			goto l47;
		//assert(false);
		return;  			}
	l352: {
		if (__context->S_StopIn) {
			__context->DiagCode = 32786;
			goto l423;
		}
		if (((! __context->S_StopIn) && __context->Acknowledge)) {
			__context->DiagCode = 32768;
			goto l423;
		}
		if (((! __context->S_StopIn) && (! ((! __context->S_StopIn) && __context->Acknowledge)))) {
			goto l423;
		}
		//assert(false);
		return;  			}
	l363: {
		if ((__context->DiagCode == 32773)) {
			goto l431;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l441;
		}
		//assert(false);
		return;  			}
	l423: {
			goto l47;
		//assert(false);
		return;  			}
	l431: {
		if (__context->S_StopIn) {
			__context->DiagCode = 32786;
			goto l482;
		}
		if ((! __context->S_StopIn)) {
			goto l482;
		}
		//assert(false);
		return;  			}
	l441: {
		if ((__context->DiagCode == 32786)) {
			goto l492;
		}
		if ((! (__context->DiagCode == 32786))) {
			goto l502;
		}
		//assert(false);
		return;  			}
	l482: {
			goto l47;
		//assert(false);
		return;  			}
	l492: {
		if ((! __context->Acknowledge)) {
			__context->DiagCode = 32770;
			goto l583;
		}
		if (((! (! __context->Acknowledge)) && (! __context->S_StopIn))) {
			__context->DiagCode = 32771;
			goto l583;
		}
		if ((((! (! __context->Acknowledge)) && (! (! __context->S_StopIn))) && __context->Acknowledge)) {
			__context->DiagCode = 32768;
			goto l583;
		}
		if (((! (! __context->Acknowledge)) && ((! ((! (! __context->Acknowledge)) && (! __context->S_StopIn))) && (! (((! (! __context->Acknowledge)) && (! (! __context->S_StopIn))) && __context->Acknowledge))))) {
			goto l583;
		}
		//assert(false);
		return;  			}
	l502: {
		if ((__context->DiagCode == 49154)) {
			goto l592;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l602;
		}
		//assert(false);
		return;  			}
	l583: {
			goto l47;
		//assert(false);
		return;  			}
	l592: {
		if (__context->Reset) {
			__context->DiagCode = 49156;
			goto l641;
		}
		if ((! __context->Reset)) {
			goto l641;
		}
		//assert(false);
		return;  			}
	l602: {
		if ((__context->DiagCode == 49155)) {
			goto l651;
		}
		if ((! (__context->DiagCode == 49155))) {
			goto l661;
		}
		//assert(false);
		return;  			}
	l641: {
			goto l47;
		//assert(false);
		return;  			}
	l651: {
		if (__context->Reset) {
			__context->DiagCode = 49157;
			goto l702;
		}
		if ((! __context->Reset)) {
			goto l702;
		}
		//assert(false);
		return;  			}
	l661: {
		if ((__context->DiagCode == 49156)) {
			goto l711;
		}
		if ((! (__context->DiagCode == 49156))) {
			goto l722;
		}
		//assert(false);
		return;  			}
	l702: {
			goto l47;
		//assert(false);
		return;  			}
	l711: {
		if ((! __context->Reset)) {
			__context->DiagCode = 49154;
			goto l761;
		}
		if ((! (! __context->Reset))) {
			goto l761;
		}
		//assert(false);
		return;  			}
	l722: {
		if ((__context->DiagCode == 49157)) {
			goto l771;
		}
		if ((! (__context->DiagCode == 49157))) {
			goto l47;
		}
		//assert(false);
		return;  			}
	l761: {
			goto l47;
		//assert(false);
		return;  			}
	l771: {
		if ((! __context->Reset)) {
			__context->DiagCode = 49155;
			goto l821;
		}
		if ((! (! __context->Reset))) {
			goto l821;
		}
		//assert(false);
		return;  			}
	l821: {
			goto l47;
		//assert(false);
		return;  			}
	l831: {
		if ((__context->DiagCode == 0)) {
			__context->Ready = false;
			__context->S_Stopped = false;
			__context->Error = false;
			goto l841;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l86;
		}
		//assert(false);
		return;  			}
	l841: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l86: {
		if ((__context->DiagCode == 32768)) {
			__context->Ready = true;
			__context->S_Stopped = true;
			__context->Error = false;
			goto l841;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l91;
		}
		//assert(false);
		return;  			}
	l91: {
		if ((__context->DiagCode == 32769)) {
			__context->Ready = true;
			__context->S_Stopped = false;
			__context->Error = false;
			goto l841;
		}
		if ((! (__context->DiagCode == 32769))) {
			goto l96;
		}
		//assert(false);
		return;  			}
	l96: {
		if ((__context->DiagCode == 32770)) {
			__context->Ready = true;
			__context->S_Stopped = false;
			__context->Error = false;
			goto l841;
		}
		if ((! (__context->DiagCode == 32770))) {
			goto l1011;
		}
		//assert(false);
		return;  			}
	l1011: {
		if ((__context->DiagCode == 32771)) {
			__context->Ready = true;
			__context->S_Stopped = false;
			__context->Error = false;
			goto l841;
		}
		if ((! (__context->DiagCode == 32771))) {
			goto l106;
		}
		//assert(false);
		return;  			}
	l106: {
		if ((__context->DiagCode == 32773)) {
			__context->Ready = true;
			__context->S_Stopped = false;
			__context->Error = false;
			goto l841;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l1111;
		}
		//assert(false);
		return;  			}
	l1111: {
		if ((__context->DiagCode == 32786)) {
			__context->Ready = true;
			__context->S_Stopped = false;
			__context->Error = false;
			goto l841;
		}
		if ((! (__context->DiagCode == 32786))) {
			goto l116;
		}
		//assert(false);
		return;  			}
	l116: {
		if ((__context->DiagCode == 49154)) {
			__context->Ready = true;
			__context->S_Stopped = false;
			__context->Error = true;
			goto l841;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l1211;
		}
		//assert(false);
		return;  			}
	l1211: {
		if ((__context->DiagCode == 49155)) {
			__context->Ready = true;
			__context->S_Stopped = false;
			__context->Error = true;
			goto l841;
		}
		if ((! (__context->DiagCode == 49155))) {
			goto l126;
		}
		//assert(false);
		return;  			}
	l126: {
		if ((__context->DiagCode == 49156)) {
			__context->Ready = true;
			__context->S_Stopped = false;
			__context->Error = true;
			goto l841;
		}
		if ((! (__context->DiagCode == 49156))) {
			goto l131;
		}
		//assert(false);
		return;  			}
	l131: {
		if ((__context->DiagCode == 49157)) {
			__context->Ready = true;
			__context->S_Stopped = false;
			__context->Error = true;
			goto l841;
		}
		if ((! (__context->DiagCode == 49157))) {
			goto l841;
		}
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void VerificationLoop() {
	// Temporary variables
	
	// Start with initial location
	goto init5;
	init5: {
			goto loop_start;
		//assert(false);
		return;  			}
	end: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	loop_start: {
			instance.AxisD_1 = nondet_int32_t();
			instance.Diag_ESPE1 = nondet_int32_t();
			instance.Diag_EStop1 = nondet_int32_t();
			instance.Diag_Equiv1 = nondet_int32_t();
			instance.Diag_SafeStop1 = nondet_int32_t();
			instance.Error_ESPE1 = nondet_bool();
			instance.Error_EStop1 = nondet_bool();
			instance.Error_Equiv1 = nondet_bool();
			instance.Error_SafeStop1 = nondet_bool();
			instance.InputDevice1_active = nondet_bool();
			instance.InputDevice2_active = nondet_bool();
			instance.Internal_Acknowledge = nondet_bool();
			instance.S0_Reset = nondet_bool();
			instance.S1_S_EStopIn_1 = nondet_bool();
			instance.S1_S_EStopIn_2 = nondet_bool();
			instance.S2_S_ESPE_In = nondet_bool();
			instance.S3_Drive_Reset = nondet_bool();
			instance.S_Stopped = nondet_bool();
			goto l_main_call;
		if (false) {
			goto end;
		}
		//assert(false);
		return;  			}
	l_main_call: {
			// Assign inputs
			Main(&instance);
			// Assign outputs
			goto callEnd;
		//assert(false);
		return;  			}
	callEnd: {
			EoC = true;
			goto prepare_EoC;
		//assert(false);
		return;  			}
	prepare_EoC: {
		assert((!(EoC) || (((((! instance.Error_Equiv1) && (! instance.Error_EStop1)) && (! instance.Error_ESPE1)) && (! instance.Error_SafeStop1)) && ((0 <= instance.CYCLE) && (instance.CYCLE <= 20)))));
		__cbmc_eoc_marker = true; // to indicate the end of the loop for the counterexample parser
		__cbmc_eoc_marker = false;
			EoC = false;
			goto loop_start;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}

// Main
void main() {
	// Initial values
	instance.S1_S_EStopIn_1 = false;
	instance.S1_S_EStopIn_2 = false;
	instance.S2_S_ESPE_In = false;
	instance.S0_Reset = false;
	instance.S3_Drive_Reset = false;
	instance.AxisD_1 = 0;
	instance.InputDevice1_active = false;
	instance.InputDevice2_active = false;
	instance.Internal_Acknowledge = false;
	instance.Error_Equiv1 = false;
	instance.Diag_Equiv1 = 0;
	instance.Error_EStop1 = false;
	instance.Diag_EStop1 = 0;
	instance.Error_ESPE1 = false;
	instance.Diag_ESPE1 = 0;
	instance.Error_SafeStop1 = false;
	instance.Diag_SafeStop1 = 0;
	instance.S_Stopped = false;
	instance.S_EStopOut = false;
	instance.SF_Equivalent_1.Activate = false;
	instance.SF_Equivalent_1.S_ChannelA = false;
	instance.SF_Equivalent_1.S_ChannelB = false;
	instance.SF_Equivalent_1.Ready = false;
	instance.SF_Equivalent_1.S_EquivalentOut = false;
	instance.SF_Equivalent_1.Error = false;
	instance.SF_Equivalent_1.DiagCode = 0;
	instance.SF_EmergencyStop_1.Activate = false;
	instance.SF_EmergencyStop_1.S_EStopIn = false;
	instance.SF_EmergencyStop_1.S_StartReset = false;
	instance.SF_EmergencyStop_1.S_AutoReset = false;
	instance.SF_EmergencyStop_1.Reset = false;
	instance.SF_EmergencyStop_1.Ready = false;
	instance.SF_EmergencyStop_1.S_EStopOut = false;
	instance.SF_EmergencyStop_1.Error = false;
	instance.SF_EmergencyStop_1.DiagCode = 0;
	instance.SF_ESPE_1.Activate = false;
	instance.SF_ESPE_1.S_ESPE_In = false;
	instance.SF_ESPE_1.S_StartReset = false;
	instance.SF_ESPE_1.S_AutoReset = false;
	instance.SF_ESPE_1.Reset = false;
	instance.SF_ESPE_1.Ready = false;
	instance.SF_ESPE_1.S_ESPE_Out = false;
	instance.SF_ESPE_1.Error = false;
	instance.SF_ESPE_1.DiagCode = 0;
	instance.SF_SafeStop1_1.Activate = false;
	instance.SF_SafeStop1_1.S_StopIn = false;
	instance.SF_SafeStop1_1.AxisID = 0;
	instance.SF_SafeStop1_1.MonitoringTime = 0;
	instance.SF_SafeStop1_1.Reset = false;
	instance.SF_SafeStop1_1.Acknowledge = false;
	instance.SF_SafeStop1_1.Ready = false;
	instance.SF_SafeStop1_1.S_Stopped = false;
	instance.SF_SafeStop1_1.Error = false;
	instance.SF_SafeStop1_1.DiagCode = 0;
	instance.CYCLE = 0;
	EoC = false;
	
	VerificationLoop();
}

