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
	bool S_SafetyActive;
	bool S_EnableSwitchCh1;
	bool S_EnableSwitchCh2;
	bool S_AutoReset;
	bool Reset;
	bool Ready;
	bool S_EnableSwitchOut;
	bool Error;
	int32_t DiagCode;
} __SF_EnableSwitch;
typedef struct {
	bool Activate;
	bool S_GuardMonitoring;
	bool S_SafetyActive;
	bool S_GuardLock;
	bool UnlockRequest;
	bool S_StartReset;
	bool S_AutoReset;
	bool Reset;
	bool Ready;
	bool S_GuardLocked;
	bool S_UnlockGuard;
	bool Error;
	int32_t DiagCode;
} __SF_GuardLocking;
typedef struct {
	bool Activate;
	bool S_Mode0;
	bool S_Mode1;
	bool S_Mode2;
	bool S_Mode3;
	bool S_Mode4;
	bool S_Mode5;
	bool S_Mode6;
	bool S_Mode7;
	bool S_Unlock;
	bool Reset;
	bool Ready;
	bool S_Mode0Sel;
	bool S_Mode1Sel;
	bool S_Mode2Sel;
	bool S_Mode3Sel;
	bool S_Mode4Sel;
	bool S_Mode5Sel;
	bool S_Mode6Sel;
	bool S_Mode7Sel;
	bool S_AnyModeSel;
	bool Error;
	int32_t DiagCode;
	bool Error1;
	bool Error2;
} __SF_ModeSelector;
typedef struct {
	bool Activate;
	bool S_OpMode;
	bool S_Acknowledge;
	int32_t MonitoringTime;
	bool Reset;
	bool Ready;
	bool S_SafetyActive;
	bool S_SafetyRequest;
	bool Error;
	int32_t DiagCode;
} __SF_SafetyRequest;
typedef struct {
	bool S1_S_EStopIn;
	bool S2_S_AutoMode;
	bool S2_S_SetupMode;
	bool S4_S_EnableSwitchCh1;
	bool S4_S_EnableSwitchCh2;
	bool S5_S_GuardSwitch;
	bool S7_S_GuardLock;
	bool S0_Reset;
	bool S8_UnlockGuard;
	bool M1_S_AcknowledgeSS1;
	bool M1_S_AcknowledgeSafeMotion;
	bool S_SafeStop_M1;
	bool S_SafeMotion_M1;
	bool S_Enable_M1;
	bool S_UnlockGuard_K1;
	bool S_SetupMode;
	bool S_AutoMode;
	bool S_SafeStandstill;
	bool S_SafeMotionActive;
	__SF_EmergencyStop SF_EmergencyStop_1;
	__SF_SafetyRequest SF_SafetyRequest_1;
	__SF_SafetyRequest SF_SafetyRequest_2;
	__SF_ModeSelector SF_ModeSelector_1;
	__SF_GuardLocking SF_GuardLocking_1;
	__SF_EnableSwitch SF_EnableSwitch_1;
	int32_t CYCLE;
} __Main;

// Global variables
__Main instance;
bool EoC;
bool __cbmc_eoc_marker;

// Automata declarations
void Main(__Main *__context);
void SF_EmergencyStop(__SF_EmergencyStop *__context);
void SF_SafetyRequest(__SF_SafetyRequest *__context);
void SF_ModeSelector(__SF_ModeSelector *__context);
void SF_GuardLocking(__SF_GuardLocking *__context);
void SF_EnableSwitch(__SF_EnableSwitch *__context);
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
			__context->SF_EmergencyStop_1.Activate = true;
			__context->SF_EmergencyStop_1.S_EStopIn = __context->S1_S_EStopIn;
			__context->SF_EmergencyStop_1.S_StartReset = false;
			__context->SF_EmergencyStop_1.S_AutoReset = false;
			__context->SF_EmergencyStop_1.Reset = __context->S0_Reset;
			SF_EmergencyStop(&__context->SF_EmergencyStop_1);
			// Assign outputs
			goto l2;
		//assert(false);
		return;  			}
	l2: {
			// Assign inputs
			__context->SF_SafetyRequest_1.Activate = true;
			__context->SF_SafetyRequest_1.S_OpMode = __context->SF_EmergencyStop_1.S_EStopOut;
			__context->SF_SafetyRequest_1.S_Acknowledge = __context->M1_S_AcknowledgeSS1;
			__context->SF_SafetyRequest_1.MonitoringTime = 100;
			__context->SF_SafetyRequest_1.Reset = __context->S0_Reset;
			SF_SafetyRequest(&__context->SF_SafetyRequest_1);
			// Assign outputs
			goto l3;
		//assert(false);
		return;  			}
	l3: {
			// Assign inputs
			__context->SF_SafetyRequest_2.Activate = true;
			__context->SF_SafetyRequest_2.S_OpMode = __context->S_AutoMode;
			__context->SF_SafetyRequest_2.S_Acknowledge = __context->M1_S_AcknowledgeSafeMotion;
			__context->SF_SafetyRequest_2.MonitoringTime = 100;
			__context->SF_SafetyRequest_2.Reset = __context->S0_Reset;
			SF_SafetyRequest(&__context->SF_SafetyRequest_2);
			// Assign outputs
			goto l4;
		//assert(false);
		return;  			}
	l4: {
			// Assign inputs
			__context->SF_ModeSelector_1.Activate = true;
			__context->SF_ModeSelector_1.S_Mode0 = __context->S2_S_AutoMode;
			__context->SF_ModeSelector_1.S_Mode1 = __context->S2_S_SetupMode;
			__context->SF_ModeSelector_1.S_Mode2 = false;
			__context->SF_ModeSelector_1.S_Mode3 = false;
			__context->SF_ModeSelector_1.S_Mode4 = false;
			__context->SF_ModeSelector_1.S_Mode5 = false;
			__context->SF_ModeSelector_1.S_Mode6 = false;
			__context->SF_ModeSelector_1.S_Mode7 = false;
			__context->SF_ModeSelector_1.S_Unlock = true;
			__context->SF_ModeSelector_1.Reset = __context->S0_Reset;
			SF_ModeSelector(&__context->SF_ModeSelector_1);
			// Assign outputs
			goto l5;
		//assert(false);
		return;  			}
	l5: {
			// Assign inputs
			__context->SF_GuardLocking_1.Activate = true;
			__context->SF_GuardLocking_1.S_GuardMonitoring = __context->S5_S_GuardSwitch;
			__context->SF_GuardLocking_1.S_SafetyActive = (__context->S_SafeStandstill || __context->S_SafeMotionActive);
			__context->SF_GuardLocking_1.S_GuardLock = __context->S7_S_GuardLock;
			__context->SF_GuardLocking_1.UnlockRequest = __context->S8_UnlockGuard;
			__context->SF_GuardLocking_1.S_StartReset = false;
			__context->SF_GuardLocking_1.S_AutoReset = false;
			__context->SF_GuardLocking_1.Reset = __context->S0_Reset;
			SF_GuardLocking(&__context->SF_GuardLocking_1);
			// Assign outputs
			goto l6;
		//assert(false);
		return;  			}
	l6: {
			// Assign inputs
			__context->SF_EnableSwitch_1.Activate = true;
			__context->SF_EnableSwitch_1.S_SafetyActive = (__context->S_SafeMotionActive && __context->S_SetupMode);
			__context->SF_EnableSwitch_1.S_EnableSwitchCh1 = __context->S4_S_EnableSwitchCh1;
			__context->SF_EnableSwitch_1.S_EnableSwitchCh2 = __context->S4_S_EnableSwitchCh2;
			__context->SF_EnableSwitch_1.S_AutoReset = false;
			__context->SF_EnableSwitch_1.Reset = __context->S0_Reset;
			SF_EnableSwitch(&__context->SF_EnableSwitch_1);
			// Assign outputs
			goto l7;
		//assert(false);
		return;  			}
	l7: {
			__context->S_SafeStandstill = __context->SF_SafetyRequest_1.S_SafetyActive;
			__context->S_SafeStop_M1 = __context->SF_SafetyRequest_1.S_SafetyRequest;
			__context->S_SafeMotionActive = __context->SF_SafetyRequest_2.S_SafetyActive;
			__context->S_SafeMotion_M1 = __context->SF_SafetyRequest_2.S_SafetyRequest;
			__context->S_SetupMode = __context->SF_ModeSelector_1.S_Mode1Sel;
			__context->S_AutoMode = (__context->SF_ModeSelector_1.S_Mode0Sel && __context->SF_GuardLocking_1.S_GuardLocked);
			__context->S_UnlockGuard_K1 = __context->SF_GuardLocking_1.S_UnlockGuard;
			__context->S_Enable_M1 = __context->SF_EnableSwitch_1.S_EnableSwitchOut;
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
void SF_EmergencyStop(__SF_EmergencyStop *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init1;
	init1: {
		if ((! __context->Activate)) {
			__context->DiagCode = 0;
			goto l71;
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
			goto l61;
		}
		//assert(false);
		return;  			}
	l41: {
			goto l71;
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
	l61: {
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
		if ((! __context->S_StartReset)) {
			__context->DiagCode = 32770;
			goto l20;
		}
		if (((! (! __context->S_StartReset)) && (__context->S_StartReset && (! __context->S_EStopIn)))) {
			__context->DiagCode = 32772;
			goto l20;
		}
		if ((((! (! __context->S_StartReset)) && (! (__context->S_StartReset && (! __context->S_EStopIn)))) && (__context->S_EStopIn && __context->S_StartReset))) {
			__context->DiagCode = 32768;
			goto l20;
		}
		if (((! (! __context->S_StartReset)) && ((! ((! (! __context->S_StartReset)) && (__context->S_StartReset && (! __context->S_EStopIn)))) && (! (((! (! __context->S_StartReset)) && (! (__context->S_StartReset && (! __context->S_EStopIn)))) && (__context->S_EStopIn && __context->S_StartReset)))))) {
			goto l20;
		}
		//assert(false);
		return;  			}
	l12: {
		if ((__context->DiagCode == 32770)) {
			goto l21;
		}
		if ((! (__context->DiagCode == 32770))) {
			goto l22;
		}
		//assert(false);
		return;  			}
	l20: {
			goto l41;
		//assert(false);
		return;  			}
	l21: {
		if (__context->S_EStopIn) {
			__context->DiagCode = 32771;
			goto l26;
		}
		if ((! __context->S_EStopIn)) {
			goto l26;
		}
		//assert(false);
		return;  			}
	l22: {
		if ((__context->DiagCode == 32771)) {
			goto l27;
		}
		if ((! (__context->DiagCode == 32771))) {
			goto l28;
		}
		//assert(false);
		return;  			}
	l26: {
			goto l41;
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
			goto l36;
		}
		//assert(false);
		return;  			}
	l34: {
			goto l41;
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
	l36: {
		if ((__context->DiagCode == 32772)) {
			goto l411;
		}
		if ((! (__context->DiagCode == 32772))) {
			goto l42;
		}
		//assert(false);
		return;  			}
	l40: {
			goto l41;
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
	l42: {
		if ((__context->DiagCode == 32773)) {
			goto l49;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l50;
		}
		//assert(false);
		return;  			}
	l48: {
			goto l41;
		//assert(false);
		return;  			}
	l49: {
		if (__context->Reset) {
			__context->DiagCode = 49154;
			goto l58;
		}
		if (((! __context->Reset) && (! __context->S_EStopIn))) {
			__context->DiagCode = 32772;
			goto l58;
		}
		if ((((! __context->Reset) && (! (! __context->S_EStopIn))) && __context->S_AutoReset)) {
			__context->DiagCode = 32768;
			goto l58;
		}
		if (((! __context->Reset) && ((! ((! __context->Reset) && (! __context->S_EStopIn))) && (! (((! __context->Reset) && (! (! __context->S_EStopIn))) && __context->S_AutoReset))))) {
			goto l58;
		}
		//assert(false);
		return;  			}
	l50: {
		if ((__context->DiagCode == 49154)) {
			goto l59;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l60;
		}
		//assert(false);
		return;  			}
	l58: {
			goto l41;
		//assert(false);
		return;  			}
	l59: {
		if ((! __context->Reset)) {
			__context->DiagCode = 32773;
			goto l64;
		}
		if ((! (! __context->Reset))) {
			goto l64;
		}
		//assert(false);
		return;  			}
	l60: {
		if ((__context->DiagCode == 32768)) {
			goto l65;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l41;
		}
		//assert(false);
		return;  			}
	l64: {
			goto l41;
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
			goto l41;
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
			goto l74;
		}
		//assert(false);
		return;  			}
	l72: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l74: {
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
void SF_SafetyRequest(__SF_SafetyRequest *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init2;
	init2: {
		if ((! __context->Activate)) {
			__context->DiagCode = 0;
			goto l73;
		}
		if ((! (! __context->Activate))) {
			goto l32;
		}
		//assert(false);
		return;  			}
	l32: {
		if ((__context->DiagCode == 0)) {
			goto l52;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l62;
		}
		//assert(false);
		return;  			}
	l43: {
			goto l73;
		//assert(false);
		return;  			}
	l52: {
		if (__context->Activate) {
			__context->DiagCode = 32769;
			goto l101;
		}
		if ((! __context->Activate)) {
			goto l101;
		}
		//assert(false);
		return;  			}
	l62: {
		if ((__context->DiagCode == 32768)) {
			goto l111;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l121;
		}
		//assert(false);
		return;  			}
	l101: {
			goto l43;
		//assert(false);
		return;  			}
	l111: {
		if ((! __context->S_Acknowledge)) {
			__context->DiagCode = 49154;
			goto l18;
		}
		if (((! (! __context->S_Acknowledge)) && __context->S_OpMode)) {
			__context->DiagCode = 32786;
			goto l18;
		}
		if (((! (! __context->S_Acknowledge)) && (! ((! (! __context->S_Acknowledge)) && __context->S_OpMode)))) {
			goto l18;
		}
		//assert(false);
		return;  			}
	l121: {
		if ((__context->DiagCode == 32769)) {
			goto l19;
		}
		if ((! (__context->DiagCode == 32769))) {
			goto l201;
		}
		//assert(false);
		return;  			}
	l18: {
			goto l43;
		//assert(false);
		return;  			}
	l19: {
		if ((! __context->S_Acknowledge)) {
			__context->DiagCode = 32770;
			goto l261;
		}
		if (((! (! __context->S_Acknowledge)) && __context->S_Acknowledge)) {
			__context->DiagCode = 32786;
			goto l261;
		}
		if (((! (! __context->S_Acknowledge)) && (! ((! (! __context->S_Acknowledge)) && __context->S_Acknowledge)))) {
			goto l261;
		}
		//assert(false);
		return;  			}
	l201: {
		if ((__context->DiagCode == 32770)) {
			goto l271;
		}
		if ((! (__context->DiagCode == 32770))) {
			goto l281;
		}
		//assert(false);
		return;  			}
	l261: {
			goto l43;
		//assert(false);
		return;  			}
	l271: {
		if ((! __context->S_OpMode)) {
			__context->DiagCode = 32771;
			goto l341;
		}
		if (((! (! __context->S_OpMode)) && __context->S_Acknowledge)) {
			__context->DiagCode = 32786;
			goto l341;
		}
		if (((! (! __context->S_OpMode)) && (! ((! (! __context->S_OpMode)) && __context->S_Acknowledge)))) {
			goto l341;
		}
		//assert(false);
		return;  			}
	l281: {
		if ((__context->DiagCode == 32773)) {
			goto l351;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l361;
		}
		//assert(false);
		return;  			}
	l341: {
			goto l43;
		//assert(false);
		return;  			}
	l351: {
		if (__context->S_OpMode) {
			__context->DiagCode = 32786;
			goto l401;
		}
		if ((! __context->S_OpMode)) {
			goto l401;
		}
		//assert(false);
		return;  			}
	l361: {
		if ((__context->DiagCode == 32786)) {
			goto l412;
		}
		if ((! (__context->DiagCode == 32786))) {
			goto l421;
		}
		//assert(false);
		return;  			}
	l401: {
			goto l43;
		//assert(false);
		return;  			}
	l412: {
		if ((! __context->S_Acknowledge)) {
			__context->DiagCode = 32770;
			goto l481;
		}
		if (((! (! __context->S_Acknowledge)) && (! __context->S_OpMode))) {
			__context->DiagCode = 32771;
			goto l481;
		}
		if (((! (! __context->S_Acknowledge)) && (! ((! (! __context->S_Acknowledge)) && (! __context->S_OpMode))))) {
			goto l481;
		}
		//assert(false);
		return;  			}
	l421: {
		if ((__context->DiagCode == 49154)) {
			goto l491;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l501;
		}
		//assert(false);
		return;  			}
	l481: {
			goto l43;
		//assert(false);
		return;  			}
	l491: {
		if (__context->Reset) {
			__context->DiagCode = 49156;
			goto l54;
		}
		if ((! __context->Reset)) {
			goto l54;
		}
		//assert(false);
		return;  			}
	l501: {
		if ((__context->DiagCode == 49155)) {
			goto l55;
		}
		if ((! (__context->DiagCode == 49155))) {
			goto l56;
		}
		//assert(false);
		return;  			}
	l54: {
			goto l43;
		//assert(false);
		return;  			}
	l55: {
		if (__context->Reset) {
			__context->DiagCode = 49157;
			goto l601;
		}
		if ((! __context->Reset)) {
			goto l601;
		}
		//assert(false);
		return;  			}
	l56: {
		if ((__context->DiagCode == 49156)) {
			goto l611;
		}
		if ((! (__context->DiagCode == 49156))) {
			goto l621;
		}
		//assert(false);
		return;  			}
	l601: {
			goto l43;
		//assert(false);
		return;  			}
	l611: {
		if ((! __context->Reset)) {
			__context->DiagCode = 49154;
			goto l66;
		}
		if ((! (! __context->Reset))) {
			goto l66;
		}
		//assert(false);
		return;  			}
	l621: {
		if ((__context->DiagCode == 49157)) {
			goto l67;
		}
		if ((! (__context->DiagCode == 49157))) {
			goto l43;
		}
		//assert(false);
		return;  			}
	l66: {
			goto l43;
		//assert(false);
		return;  			}
	l67: {
		if ((! __context->Reset)) {
			__context->DiagCode = 49155;
			goto l721;
		}
		if ((! (! __context->Reset))) {
			goto l721;
		}
		//assert(false);
		return;  			}
	l721: {
			goto l43;
		//assert(false);
		return;  			}
	l73: {
		if ((__context->DiagCode == 0)) {
			__context->Ready = false;
			__context->S_SafetyActive = false;
			__context->S_SafetyRequest = false;
			__context->Error = false;
			goto l741;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l76;
		}
		//assert(false);
		return;  			}
	l741: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l76: {
		if ((__context->DiagCode == 32768)) {
			__context->Ready = true;
			__context->S_SafetyActive = true;
			__context->S_SafetyRequest = false;
			__context->Error = false;
			goto l741;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l82;
		}
		//assert(false);
		return;  			}
	l82: {
		if ((__context->DiagCode == 32769)) {
			__context->Ready = true;
			__context->S_SafetyActive = false;
			__context->S_SafetyRequest = false;
			__context->Error = false;
			goto l741;
		}
		if ((! (__context->DiagCode == 32769))) {
			goto l88;
		}
		//assert(false);
		return;  			}
	l88: {
		if ((__context->DiagCode == 32770)) {
			__context->Ready = true;
			__context->S_SafetyActive = false;
			__context->S_SafetyRequest = true;
			__context->Error = false;
			goto l741;
		}
		if ((! (__context->DiagCode == 32770))) {
			goto l941;
		}
		//assert(false);
		return;  			}
	l941: {
		if ((__context->DiagCode == 32771)) {
			__context->Ready = true;
			__context->S_SafetyActive = false;
			__context->S_SafetyRequest = false;
			__context->Error = false;
			goto l741;
		}
		if ((! (__context->DiagCode == 32771))) {
			goto l100;
		}
		//assert(false);
		return;  			}
	l100: {
		if ((__context->DiagCode == 32773)) {
			__context->Ready = true;
			__context->S_SafetyActive = false;
			__context->S_SafetyRequest = false;
			__context->Error = false;
			goto l741;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l106;
		}
		//assert(false);
		return;  			}
	l106: {
		if ((__context->DiagCode == 32786)) {
			__context->Ready = true;
			__context->S_SafetyActive = false;
			__context->S_SafetyRequest = true;
			__context->Error = false;
			goto l741;
		}
		if ((! (__context->DiagCode == 32786))) {
			goto l112;
		}
		//assert(false);
		return;  			}
	l112: {
		if ((__context->DiagCode == 49154)) {
			__context->Ready = true;
			__context->S_SafetyActive = false;
			__context->S_SafetyRequest = false;
			__context->Error = true;
			goto l741;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l118;
		}
		//assert(false);
		return;  			}
	l118: {
		if ((__context->DiagCode == 49155)) {
			__context->Ready = true;
			__context->S_SafetyActive = false;
			__context->S_SafetyRequest = false;
			__context->Error = true;
			goto l741;
		}
		if ((! (__context->DiagCode == 49155))) {
			goto l124;
		}
		//assert(false);
		return;  			}
	l124: {
		if ((__context->DiagCode == 49156)) {
			__context->Ready = true;
			__context->S_SafetyActive = false;
			__context->S_SafetyRequest = false;
			__context->Error = true;
			goto l741;
		}
		if ((! (__context->DiagCode == 49156))) {
			goto l130;
		}
		//assert(false);
		return;  			}
	l130: {
		if ((__context->DiagCode == 49157)) {
			__context->Ready = true;
			__context->S_SafetyActive = false;
			__context->S_SafetyRequest = false;
			__context->Error = true;
			goto l741;
		}
		if ((! (__context->DiagCode == 49157))) {
			goto l741;
		}
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void SF_ModeSelector(__SF_ModeSelector *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init3;
	init3: {
		if ((! __context->Activate)) {
			__context->DiagCode = 0;
			goto l44;
		}
		if ((! (! __context->Activate))) {
			goto l44;
		}
		//assert(false);
		return;  			}
	l44: {
		if ((((((((__context->S_Mode0 || __context->S_Mode1) || __context->S_Mode2) || __context->S_Mode3) || __context->S_Mode4) || __context->S_Mode5) || __context->S_Mode6) || (__context->S_Mode7 == true))) {
			__context->Error1 = true;
			goto l9;
		}
		if ((! (((((((__context->S_Mode0 || __context->S_Mode1) || __context->S_Mode2) || __context->S_Mode3) || __context->S_Mode4) || __context->S_Mode5) || __context->S_Mode6) || (__context->S_Mode7 == true)))) {
			__context->Error1 = false;
			goto l9;
		}
		//assert(false);
		return;  			}
	l9: {
		if ((__context->DiagCode == 0)) {
			goto l113;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l122;
		}
		//assert(false);
		return;  			}
	l102: {
		if ((__context->DiagCode == 0)) {
			__context->Ready = false;
			__context->S_Mode0Sel = false;
			__context->S_Mode1Sel = false;
			__context->S_Mode2Sel = false;
			__context->S_Mode3Sel = false;
			__context->S_Mode4Sel = false;
			__context->S_Mode5Sel = false;
			__context->S_Mode6Sel = false;
			__context->S_Mode7Sel = false;
			__context->S_AnyModeSel = false;
			__context->Error = false;
			goto l63;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l651;
		}
		//assert(false);
		return;  			}
	l113: {
		if (__context->Activate) {
			__context->DiagCode = 32773;
			goto l16;
		}
		if ((! __context->Activate)) {
			goto l16;
		}
		//assert(false);
		return;  			}
	l122: {
		if ((__context->DiagCode == 32768)) {
			goto l23;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l24;
		}
		//assert(false);
		return;  			}
	l16: {
		if (__context->Error1) {
			__context->DiagCode = 49153;
			goto l221;
		}
		if (((! __context->Error1) && __context->Error2)) {
			__context->DiagCode = 49154;
			goto l221;
		}
		if (((! __context->Error1) && (! ((! __context->Error1) && __context->Error2)))) {
			goto l221;
		}
		//assert(false);
		return;  			}
	l221: {
			goto l102;
		//assert(false);
		return;  			}
	l23: {
		if (__context->Error1) {
			__context->DiagCode = 49153;
			goto l321;
		}
		if (((! __context->Error1) && ((((((((__context->S_Mode0 != __context->S_Mode0Sel) || (__context->S_Mode1 != __context->S_Mode1Sel)) || (__context->S_Mode2 != __context->S_Mode2Sel)) || (__context->S_Mode3 != __context->S_Mode3Sel)) || (__context->S_Mode4 != __context->S_Mode4Sel)) || (__context->S_Mode5 != __context->S_Mode5Sel)) || (__context->S_Mode6 != __context->S_Mode6Sel)) || (__context->S_Mode7 != __context->S_Mode7Sel)))) {
			__context->DiagCode = 32773;
			goto l321;
		}
		if ((((! __context->Error1) && (! ((((((((__context->S_Mode0 != __context->S_Mode0Sel) || (__context->S_Mode1 != __context->S_Mode1Sel)) || (__context->S_Mode2 != __context->S_Mode2Sel)) || (__context->S_Mode3 != __context->S_Mode3Sel)) || (__context->S_Mode4 != __context->S_Mode4Sel)) || (__context->S_Mode5 != __context->S_Mode5Sel)) || (__context->S_Mode6 != __context->S_Mode6Sel)) || (__context->S_Mode7 != __context->S_Mode7Sel)))) && (! __context->S_Unlock))) {
			__context->DiagCode = 32772;
			goto l321;
		}
		if (((! __context->Error1) && ((! ((! __context->Error1) && ((((((((__context->S_Mode0 != __context->S_Mode0Sel) || (__context->S_Mode1 != __context->S_Mode1Sel)) || (__context->S_Mode2 != __context->S_Mode2Sel)) || (__context->S_Mode3 != __context->S_Mode3Sel)) || (__context->S_Mode4 != __context->S_Mode4Sel)) || (__context->S_Mode5 != __context->S_Mode5Sel)) || (__context->S_Mode6 != __context->S_Mode6Sel)) || (__context->S_Mode7 != __context->S_Mode7Sel)))) && (! (((! __context->Error1) && (! ((((((((__context->S_Mode0 != __context->S_Mode0Sel) || (__context->S_Mode1 != __context->S_Mode1Sel)) || (__context->S_Mode2 != __context->S_Mode2Sel)) || (__context->S_Mode3 != __context->S_Mode3Sel)) || (__context->S_Mode4 != __context->S_Mode4Sel)) || (__context->S_Mode5 != __context->S_Mode5Sel)) || (__context->S_Mode6 != __context->S_Mode6Sel)) || (__context->S_Mode7 != __context->S_Mode7Sel)))) && (! __context->S_Unlock)))))) {
			goto l321;
		}
		//assert(false);
		return;  			}
	l24: {
		if ((__context->DiagCode == 32772)) {
			goto l33;
		}
		if ((! (__context->DiagCode == 32772))) {
			goto l342;
		}
		//assert(false);
		return;  			}
	l321: {
			goto l102;
		//assert(false);
		return;  			}
	l33: {
		if (__context->S_Unlock) {
			__context->DiagCode = 32768;
			goto l38;
		}
		if ((! __context->S_Unlock)) {
			goto l38;
		}
		//assert(false);
		return;  			}
	l342: {
		if ((__context->DiagCode == 49153)) {
			goto l39;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l402;
		}
		//assert(false);
		return;  			}
	l38: {
			goto l102;
		//assert(false);
		return;  			}
	l39: {
		if (__context->Reset) {
			__context->DiagCode = 49155;
			goto l441;
		}
		if ((! __context->Reset)) {
			goto l441;
		}
		//assert(false);
		return;  			}
	l402: {
		if ((__context->DiagCode == 49154)) {
			goto l45;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l46;
		}
		//assert(false);
		return;  			}
	l441: {
			goto l102;
		//assert(false);
		return;  			}
	l45: {
		if (__context->Reset) {
			__context->DiagCode = 49156;
			goto l502;
		}
		if ((! __context->Reset)) {
			goto l502;
		}
		//assert(false);
		return;  			}
	l46: {
		if ((__context->DiagCode == 49155)) {
			goto l511;
		}
		if ((! (__context->DiagCode == 49155))) {
			goto l521;
		}
		//assert(false);
		return;  			}
	l502: {
			goto l102;
		//assert(false);
		return;  			}
	l511: {
		if ((! __context->Reset)) {
			__context->DiagCode = 49153;
			goto l561;
		}
		if ((! (! __context->Reset))) {
			goto l561;
		}
		//assert(false);
		return;  			}
	l521: {
		if ((__context->DiagCode == 49156)) {
			goto l57;
		}
		if ((! (__context->DiagCode == 49156))) {
			goto l102;
		}
		//assert(false);
		return;  			}
	l561: {
			goto l102;
		//assert(false);
		return;  			}
	l57: {
		if ((! __context->Reset)) {
			__context->DiagCode = 49154;
			goto l622;
		}
		if ((! (! __context->Reset))) {
			goto l622;
		}
		//assert(false);
		return;  			}
	l622: {
			goto l102;
		//assert(false);
		return;  			}
	l63: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l651: {
		if ((__context->DiagCode == 32773)) {
			__context->Ready = true;
			__context->S_Mode0Sel = false;
			__context->S_Mode1Sel = false;
			__context->S_Mode2Sel = false;
			__context->S_Mode3Sel = false;
			__context->S_Mode4Sel = false;
			__context->S_Mode5Sel = false;
			__context->S_Mode6Sel = false;
			__context->S_Mode7Sel = false;
			__context->S_AnyModeSel = false;
			__context->Error = false;
			goto l63;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l78;
		}
		//assert(false);
		return;  			}
	l78: {
		if ((__context->DiagCode == 32768)) {
			__context->Ready = true;
			__context->S_Mode0Sel = __context->S_Mode0;
			__context->S_Mode1Sel = __context->S_Mode1;
			__context->S_Mode2Sel = __context->S_Mode2;
			__context->S_Mode3Sel = __context->S_Mode3;
			__context->S_Mode4Sel = __context->S_Mode4;
			__context->S_Mode5Sel = __context->S_Mode5;
			__context->S_Mode6Sel = __context->S_Mode6;
			__context->S_Mode7Sel = __context->S_Mode7;
			__context->S_AnyModeSel = true;
			__context->Error = false;
			goto l63;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l91;
		}
		//assert(false);
		return;  			}
	l91: {
		if ((__context->DiagCode == 32772)) {
			__context->Ready = true;
			__context->S_AnyModeSel = true;
			__context->Error = false;
			goto l63;
		}
		if ((! (__context->DiagCode == 32772))) {
			goto l1041;
		}
		//assert(false);
		return;  			}
	l1041: {
		if ((__context->DiagCode == 49153)) {
			__context->Ready = true;
			__context->S_Mode0Sel = false;
			__context->S_Mode1Sel = false;
			__context->S_Mode2Sel = false;
			__context->S_Mode3Sel = false;
			__context->S_Mode4Sel = false;
			__context->S_Mode5Sel = false;
			__context->S_Mode6Sel = false;
			__context->S_Mode7Sel = false;
			__context->S_AnyModeSel = false;
			__context->Error = true;
			goto l63;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l1091;
		}
		//assert(false);
		return;  			}
	l1091: {
		if ((__context->DiagCode == 49154)) {
			__context->Ready = true;
			__context->S_Mode0Sel = false;
			__context->S_Mode1Sel = false;
			__context->S_Mode2Sel = false;
			__context->S_Mode3Sel = false;
			__context->S_Mode4Sel = false;
			__context->S_Mode5Sel = false;
			__context->S_Mode6Sel = false;
			__context->S_Mode7Sel = false;
			__context->S_AnyModeSel = false;
			__context->Error = true;
			goto l63;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l1221;
		}
		//assert(false);
		return;  			}
	l1221: {
		if ((__context->DiagCode == 49155)) {
			__context->Ready = true;
			__context->S_Mode0Sel = false;
			__context->S_Mode1Sel = false;
			__context->S_Mode2Sel = false;
			__context->S_Mode3Sel = false;
			__context->S_Mode4Sel = false;
			__context->S_Mode5Sel = false;
			__context->S_Mode6Sel = false;
			__context->S_Mode7Sel = false;
			__context->S_AnyModeSel = false;
			__context->Error = true;
			goto l63;
		}
		if ((! (__context->DiagCode == 49155))) {
			goto l135;
		}
		//assert(false);
		return;  			}
	l135: {
		if ((__context->DiagCode == 49156)) {
			__context->Ready = true;
			__context->S_Mode0Sel = false;
			__context->S_Mode1Sel = false;
			__context->S_Mode2Sel = false;
			__context->S_Mode3Sel = false;
			__context->S_Mode4Sel = false;
			__context->S_Mode5Sel = false;
			__context->S_Mode6Sel = false;
			__context->S_Mode7Sel = false;
			__context->S_AnyModeSel = false;
			__context->Error = true;
			goto l63;
		}
		if ((! (__context->DiagCode == 49156))) {
			goto l63;
		}
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void SF_GuardLocking(__SF_GuardLocking *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init4;
	init4: {
		if ((! __context->Activate)) {
			__context->DiagCode = 0;
			goto l47;
		}
		if ((! (! __context->Activate))) {
			goto l47;
		}
		//assert(false);
		return;  			}
	l47: {
		if ((__context->DiagCode == 0)) {
			goto l68;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l75;
		}
		//assert(false);
		return;  			}
	l53: {
		if ((__context->DiagCode == 0)) {
			__context->Ready = false;
			__context->S_GuardLocked = false;
			__context->S_UnlockGuard = false;
			__context->Error = false;
			goto l98;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l1001;
		}
		//assert(false);
		return;  			}
	l68: {
		if (__context->Activate) {
			__context->DiagCode = 32769;
			goto l114;
		}
		if ((! __context->Activate)) {
			goto l114;
		}
		//assert(false);
		return;  			}
	l75: {
		if ((__context->DiagCode == 32768)) {
			goto l123;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l13;
		}
		//assert(false);
		return;  			}
	l114: {
			goto l53;
		//assert(false);
		return;  			}
	l123: {
		if (((! __context->S_GuardLock) || (! __context->S_GuardMonitoring))) {
			__context->DiagCode = 49156;
			goto l191;
		}
		if (((! ((! __context->S_GuardLock) || (! __context->S_GuardMonitoring))) && __context->S_SafetyActive)) {
			__context->DiagCode = 32787;
			goto l191;
		}
		if (((! ((! __context->S_GuardLock) || (! __context->S_GuardMonitoring))) && (! ((! ((! __context->S_GuardLock) || (! __context->S_GuardMonitoring))) && __context->S_SafetyActive)))) {
			goto l191;
		}
		//assert(false);
		return;  			}
	l13: {
		if ((__context->DiagCode == 32769)) {
			goto l202;
		}
		if ((! (__context->DiagCode == 32769))) {
			goto l211;
		}
		//assert(false);
		return;  			}
	l191: {
			goto l53;
		//assert(false);
		return;  			}
	l202: {
		if ((__context->Reset && (! __context->S_StartReset))) {
			__context->DiagCode = 49153;
			goto l29;
		}
		if (((! (__context->Reset && (! __context->S_StartReset))) && ((! __context->S_GuardLock) || (! __context->S_GuardMonitoring)))) {
			__context->DiagCode = 32785;
			goto l29;
		}
		if ((((! (__context->Reset && (! __context->S_StartReset))) && (! ((! __context->S_GuardLock) || (! __context->S_GuardMonitoring)))) && ((__context->S_StartReset && __context->S_GuardMonitoring) && __context->S_GuardLock))) {
			__context->DiagCode = 32768;
			goto l29;
		}
		if (((! (__context->Reset && (! __context->S_StartReset))) && ((! ((! (__context->Reset && (! __context->S_StartReset))) && ((! __context->S_GuardLock) || (! __context->S_GuardMonitoring)))) && (! (((! (__context->Reset && (! __context->S_StartReset))) && (! ((! __context->S_GuardLock) || (! __context->S_GuardMonitoring)))) && ((__context->S_StartReset && __context->S_GuardMonitoring) && __context->S_GuardLock)))))) {
			goto l29;
		}
		//assert(false);
		return;  			}
	l211: {
		if ((__context->DiagCode == 32771)) {
			goto l30;
		}
		if ((! (__context->DiagCode == 32771))) {
			goto l311;
		}
		//assert(false);
		return;  			}
	l29: {
			goto l53;
		//assert(false);
		return;  			}
	l30: {
		if ((__context->Reset && (! __context->S_AutoReset))) {
			__context->DiagCode = 49155;
			goto l391;
		}
		if (((! (__context->Reset && (! __context->S_AutoReset))) && ((! __context->S_GuardMonitoring) || (! __context->S_GuardLock)))) {
			__context->DiagCode = 32785;
			goto l391;
		}
		if ((((! (__context->Reset && (! __context->S_AutoReset))) && (! ((! __context->S_GuardMonitoring) || (! __context->S_GuardLock)))) && __context->S_AutoReset)) {
			__context->DiagCode = 32768;
			goto l391;
		}
		if (((! (__context->Reset && (! __context->S_AutoReset))) && ((! ((! (__context->Reset && (! __context->S_AutoReset))) && ((! __context->S_GuardMonitoring) || (! __context->S_GuardLock)))) && (! (((! (__context->Reset && (! __context->S_AutoReset))) && (! ((! __context->S_GuardMonitoring) || (! __context->S_GuardLock)))) && __context->S_AutoReset))))) {
			goto l391;
		}
		//assert(false);
		return;  			}
	l311: {
		if ((__context->DiagCode == 32785)) {
			goto l403;
		}
		if ((! (__context->DiagCode == 32785))) {
			goto l413;
		}
		//assert(false);
		return;  			}
	l391: {
			goto l53;
		//assert(false);
		return;  			}
	l403: {
		if (((! __context->S_SafetyActive) && ((! __context->S_GuardMonitoring) || (! __context->S_GuardLock)))) {
			__context->DiagCode = 49156;
			goto l492;
		}
		if (((! ((! __context->S_SafetyActive) && ((! __context->S_GuardMonitoring) || (! __context->S_GuardLock)))) && ((__context->S_SafetyActive && __context->UnlockRequest) || (! __context->S_GuardMonitoring)))) {
			__context->DiagCode = 32786;
			goto l492;
		}
		if ((((! ((! __context->S_SafetyActive) && ((! __context->S_GuardMonitoring) || (! __context->S_GuardLock)))) && (! ((__context->S_SafetyActive && __context->UnlockRequest) || (! __context->S_GuardMonitoring)))) && (__context->S_GuardMonitoring && __context->S_GuardLock))) {
			__context->DiagCode = 32771;
			goto l492;
		}
		if (((! ((! __context->S_SafetyActive) && ((! __context->S_GuardMonitoring) || (! __context->S_GuardLock)))) && ((! ((! ((! __context->S_SafetyActive) && ((! __context->S_GuardMonitoring) || (! __context->S_GuardLock)))) && ((__context->S_SafetyActive && __context->UnlockRequest) || (! __context->S_GuardMonitoring)))) && (! (((! ((! __context->S_SafetyActive) && ((! __context->S_GuardMonitoring) || (! __context->S_GuardLock)))) && (! ((__context->S_SafetyActive && __context->UnlockRequest) || (! __context->S_GuardMonitoring)))) && (__context->S_GuardMonitoring && __context->S_GuardLock)))))) {
			goto l492;
		}
		//assert(false);
		return;  			}
	l413: {
		if ((__context->DiagCode == 32786)) {
			goto l503;
		}
		if ((! (__context->DiagCode == 32786))) {
			goto l512;
		}
		//assert(false);
		return;  			}
	l492: {
			goto l53;
		//assert(false);
		return;  			}
	l503: {
		if (__context->S_GuardMonitoring) {
			__context->DiagCode = 32787;
			goto l571;
		}
		if (((! __context->S_GuardMonitoring) && ((! __context->S_SafetyActive) && (! __context->S_GuardMonitoring)))) {
			__context->DiagCode = 49156;
			goto l571;
		}
		if (((! __context->S_GuardMonitoring) && (! ((! __context->S_GuardMonitoring) && ((! __context->S_SafetyActive) && (! __context->S_GuardMonitoring)))))) {
			goto l571;
		}
		//assert(false);
		return;  			}
	l512: {
		if ((__context->DiagCode == 32787)) {
			goto l581;
		}
		if ((! (__context->DiagCode == 32787))) {
			goto l591;
		}
		//assert(false);
		return;  			}
	l571: {
			goto l53;
		//assert(false);
		return;  			}
	l581: {
		if ((! __context->S_GuardMonitoring)) {
			__context->DiagCode = 32786;
			goto l652;
		}
		if (((! (! __context->S_GuardMonitoring)) && (! __context->UnlockRequest))) {
			__context->DiagCode = 32785;
			goto l652;
		}
		if (((! (! __context->S_GuardMonitoring)) && (! ((! (! __context->S_GuardMonitoring)) && (! __context->UnlockRequest))))) {
			goto l652;
		}
		//assert(false);
		return;  			}
	l591: {
		if ((__context->DiagCode == 32788)) {
			goto l661;
		}
		if ((! (__context->DiagCode == 32788))) {
			goto l671;
		}
		//assert(false);
		return;  			}
	l652: {
			goto l53;
		//assert(false);
		return;  			}
	l661: {
		if (__context->Reset) {
			__context->DiagCode = 49154;
			goto l731;
		}
		if (((! __context->Reset) && (! __context->S_SafetyActive))) {
			__context->DiagCode = 49156;
			goto l731;
		}
		if (((! __context->Reset) && (! ((! __context->Reset) && (! __context->S_SafetyActive))))) {
			goto l731;
		}
		//assert(false);
		return;  			}
	l671: {
		if ((__context->DiagCode == 49153)) {
			goto l742;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l751;
		}
		//assert(false);
		return;  			}
	l731: {
			goto l53;
		//assert(false);
		return;  			}
	l742: {
		if ((! __context->Reset)) {
			__context->DiagCode = 32769;
			goto l791;
		}
		if ((! (! __context->Reset))) {
			goto l791;
		}
		//assert(false);
		return;  			}
	l751: {
		if ((__context->DiagCode == 49154)) {
			goto l80;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l81;
		}
		//assert(false);
		return;  			}
	l791: {
			goto l53;
		//assert(false);
		return;  			}
	l80: {
		if ((! __context->Reset)) {
			__context->DiagCode = 32788;
			goto l85;
		}
		if ((! (! __context->Reset))) {
			goto l85;
		}
		//assert(false);
		return;  			}
	l81: {
		if ((__context->DiagCode == 49155)) {
			goto l86;
		}
		if ((! (__context->DiagCode == 49155))) {
			goto l87;
		}
		//assert(false);
		return;  			}
	l85: {
			goto l53;
		//assert(false);
		return;  			}
	l86: {
		if ((! __context->Reset)) {
			__context->DiagCode = 32771;
			goto l911;
		}
		if ((! (! __context->Reset))) {
			goto l911;
		}
		//assert(false);
		return;  			}
	l87: {
		if ((__context->DiagCode == 49156)) {
			goto l92;
		}
		if ((! (__context->DiagCode == 49156))) {
			goto l53;
		}
		//assert(false);
		return;  			}
	l911: {
			goto l53;
		//assert(false);
		return;  			}
	l92: {
		if (__context->S_SafetyActive) {
			__context->DiagCode = 32788;
			goto l97;
		}
		if ((! __context->S_SafetyActive)) {
			goto l97;
		}
		//assert(false);
		return;  			}
	l97: {
			goto l53;
		//assert(false);
		return;  			}
	l98: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l1001: {
		if ((__context->DiagCode == 32768)) {
			__context->Ready = true;
			__context->S_GuardLocked = true;
			__context->S_UnlockGuard = false;
			__context->Error = false;
			goto l98;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l1061;
		}
		//assert(false);
		return;  			}
	l1061: {
		if ((__context->DiagCode == 32769)) {
			__context->Ready = true;
			__context->S_GuardLocked = false;
			__context->S_UnlockGuard = false;
			__context->Error = false;
			goto l98;
		}
		if ((! (__context->DiagCode == 32769))) {
			goto l1121;
		}
		//assert(false);
		return;  			}
	l1121: {
		if ((__context->DiagCode == 32771)) {
			__context->Ready = true;
			__context->S_GuardLocked = false;
			__context->S_UnlockGuard = false;
			__context->Error = false;
			goto l98;
		}
		if ((! (__context->DiagCode == 32771))) {
			goto l1181;
		}
		//assert(false);
		return;  			}
	l1181: {
		if ((__context->DiagCode == 32785)) {
			__context->Ready = true;
			__context->S_GuardLocked = false;
			__context->S_UnlockGuard = false;
			__context->Error = false;
			goto l98;
		}
		if ((! (__context->DiagCode == 32785))) {
			goto l1241;
		}
		//assert(false);
		return;  			}
	l1241: {
		if ((__context->DiagCode == 32788)) {
			__context->Ready = true;
			__context->S_GuardLocked = false;
			__context->S_UnlockGuard = false;
			__context->Error = false;
			goto l98;
		}
		if ((! (__context->DiagCode == 32788))) {
			goto l1301;
		}
		//assert(false);
		return;  			}
	l1301: {
		if (((__context->DiagCode == 32786) || (__context->DiagCode == 32787))) {
			__context->Ready = true;
			__context->S_GuardLocked = false;
			__context->S_UnlockGuard = true;
			__context->Error = false;
			goto l98;
		}
		if ((! ((__context->DiagCode == 32786) || (__context->DiagCode == 32787)))) {
			goto l136;
		}
		//assert(false);
		return;  			}
	l136: {
		if (((__context->DiagCode == 49153) || ((__context->DiagCode == 49154) || ((__context->DiagCode == 49155) || (__context->DiagCode == 49156))))) {
			__context->Ready = true;
			__context->S_GuardLocked = false;
			__context->S_UnlockGuard = false;
			__context->Error = true;
			goto l98;
		}
		if ((! ((__context->DiagCode == 49153) || ((__context->DiagCode == 49154) || ((__context->DiagCode == 49155) || (__context->DiagCode == 49156)))))) {
			goto l98;
		}
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void SF_EnableSwitch(__SF_EnableSwitch *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init5;
	init5: {
		if ((! __context->Activate)) {
			__context->DiagCode = 0;
			goto l95;
		}
		if (((! (! __context->Activate)) && (! __context->S_SafetyActive))) {
			__context->DiagCode = 32772;
			goto l95;
		}
		if (((! (! __context->Activate)) && (! ((! (! __context->Activate)) && (! __context->S_SafetyActive))))) {
			goto l510;
		}
		//assert(false);
		return;  			}
	l510: {
		if ((__context->DiagCode == 0)) {
			goto l77;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l8;
		}
		//assert(false);
		return;  			}
	l69: {
			goto l95;
		//assert(false);
		return;  			}
	l77: {
		if (__context->Activate) {
			__context->DiagCode = 32772;
			goto l125;
		}
		if ((! __context->Activate)) {
			goto l125;
		}
		//assert(false);
		return;  			}
	l8: {
		if ((__context->DiagCode == 32768)) {
			goto l131;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l14;
		}
		//assert(false);
		return;  			}
	l125: {
			goto l69;
		//assert(false);
		return;  			}
	l131: {
		if (((! (__context->S_EnableSwitchCh1 || __context->S_EnableSwitchCh2)) || (__context->S_EnableSwitchCh1 && (! __context->S_EnableSwitchCh2)))) {
			__context->DiagCode = 32775;
			goto l203;
		}
		if (((! ((! (__context->S_EnableSwitchCh1 || __context->S_EnableSwitchCh2)) || (__context->S_EnableSwitchCh1 && (! __context->S_EnableSwitchCh2)))) && ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) {
			__context->DiagCode = 32774;
			goto l203;
		}
		if (((! ((! (__context->S_EnableSwitchCh1 || __context->S_EnableSwitchCh2)) || (__context->S_EnableSwitchCh1 && (! __context->S_EnableSwitchCh2)))) && (! ((! ((! (__context->S_EnableSwitchCh1 || __context->S_EnableSwitchCh2)) || (__context->S_EnableSwitchCh1 && (! __context->S_EnableSwitchCh2)))) && ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))))) {
			goto l203;
		}
		//assert(false);
		return;  			}
	l14: {
		if ((__context->DiagCode == 32772)) {
			goto l212;
		}
		if ((! (__context->DiagCode == 32772))) {
			goto l222;
		}
		//assert(false);
		return;  			}
	l203: {
			goto l69;
		//assert(false);
		return;  			}
	l212: {
		if (__context->S_SafetyActive) {
			__context->DiagCode = 32773;
			goto l262;
		}
		if ((! __context->S_SafetyActive)) {
			goto l262;
		}
		//assert(false);
		return;  			}
	l222: {
		if ((__context->DiagCode == 32773)) {
			goto l272;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l282;
		}
		//assert(false);
		return;  			}
	l262: {
			goto l69;
		//assert(false);
		return;  			}
	l272: {
		if ((! ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) {
			__context->DiagCode = 49168;
			goto l343;
		}
		if (((! (! ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) && ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) {
			__context->DiagCode = 32774;
			goto l343;
		}
		if (((! (! ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) && (! ((! (! ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) && ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))))) {
			goto l343;
		}
		//assert(false);
		return;  			}
	l282: {
		if ((__context->DiagCode == 32774)) {
			goto l352;
		}
		if ((! (__context->DiagCode == 32774))) {
			goto l362;
		}
		//assert(false);
		return;  			}
	l343: {
			goto l69;
		//assert(false);
		return;  			}
	l352: {
		if ((__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) {
			__context->DiagCode = 32768;
			goto l422;
		}
		if (((! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) && ((! (__context->S_EnableSwitchCh1 || __context->S_EnableSwitchCh2)) || (__context->S_EnableSwitchCh1 && (! __context->S_EnableSwitchCh2))))) {
			__context->DiagCode = 32775;
			goto l422;
		}
		if (((! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) && (! ((! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) && ((! (__context->S_EnableSwitchCh1 || __context->S_EnableSwitchCh2)) || (__context->S_EnableSwitchCh1 && (! __context->S_EnableSwitchCh2))))))) {
			goto l422;
		}
		//assert(false);
		return;  			}
	l362: {
		if ((__context->DiagCode == 32775)) {
			goto l431;
		}
		if ((! (__context->DiagCode == 32775))) {
			goto l442;
		}
		//assert(false);
		return;  			}
	l422: {
			goto l69;
		//assert(false);
		return;  			}
	l431: {
		if ((__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) {
			__context->DiagCode = 49200;
			goto l504;
		}
		if (((! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) && ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) {
			__context->DiagCode = 32774;
			goto l504;
		}
		if (((! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) && (! ((! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) && ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))))) {
			goto l504;
		}
		//assert(false);
		return;  			}
	l442: {
		if ((__context->DiagCode == 49153)) {
			goto l513;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l522;
		}
		//assert(false);
		return;  			}
	l504: {
			goto l69;
		//assert(false);
		return;  			}
	l513: {
		if ((! __context->Reset)) {
			__context->DiagCode = 49184;
			goto l562;
		}
		if ((! (! __context->Reset))) {
			goto l562;
		}
		//assert(false);
		return;  			}
	l522: {
		if ((__context->DiagCode == 49154)) {
			goto l572;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l582;
		}
		//assert(false);
		return;  			}
	l562: {
			goto l69;
		//assert(false);
		return;  			}
	l572: {
		if ((! __context->Reset)) {
			__context->DiagCode = 49216;
			goto l623;
		}
		if ((! (! __context->Reset))) {
			goto l623;
		}
		//assert(false);
		return;  			}
	l582: {
		if ((__context->DiagCode == 49168)) {
			goto l631;
		}
		if ((! (__context->DiagCode == 49168))) {
			goto l641;
		}
		//assert(false);
		return;  			}
	l623: {
			goto l69;
		//assert(false);
		return;  			}
	l631: {
		if (((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2)) {
			__context->DiagCode = 49184;
			goto l681;
		}
		if ((! ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) {
			goto l681;
		}
		//assert(false);
		return;  			}
	l641: {
		if ((__context->DiagCode == 49184)) {
			goto l691;
		}
		if ((! (__context->DiagCode == 49184))) {
			goto l701;
		}
		//assert(false);
		return;  			}
	l681: {
			goto l69;
		//assert(false);
		return;  			}
	l691: {
		if ((! ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) {
			__context->DiagCode = 49168;
			goto l781;
		}
		if (((! (! ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) && (__context->Reset && (! __context->S_AutoReset)))) {
			__context->DiagCode = 49153;
			goto l781;
		}
		if ((((! (! ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) && (! (__context->Reset && (! __context->S_AutoReset)))) && __context->S_AutoReset)) {
			__context->DiagCode = 32774;
			goto l781;
		}
		if (((! (! ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) && ((! ((! (! ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) && (__context->Reset && (! __context->S_AutoReset)))) && (! (((! (! ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) && (! (__context->Reset && (! __context->S_AutoReset)))) && __context->S_AutoReset))))) {
			goto l781;
		}
		//assert(false);
		return;  			}
	l701: {
		if ((__context->DiagCode == 49200)) {
			goto l792;
		}
		if ((! (__context->DiagCode == 49200))) {
			goto l801;
		}
		//assert(false);
		return;  			}
	l781: {
			goto l69;
		//assert(false);
		return;  			}
	l792: {
		if ((! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2))) {
			__context->DiagCode = 49216;
			goto l841;
		}
		if ((! (! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)))) {
			goto l841;
		}
		//assert(false);
		return;  			}
	l801: {
		if ((__context->DiagCode == 49216)) {
			goto l851;
		}
		if ((! (__context->DiagCode == 49216))) {
			goto l69;
		}
		//assert(false);
		return;  			}
	l841: {
			goto l69;
		//assert(false);
		return;  			}
	l851: {
		if ((__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) {
			__context->DiagCode = 49200;
			goto l942;
		}
		if (((! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) && (__context->Reset && (! __context->S_AutoReset)))) {
			__context->DiagCode = 49154;
			goto l942;
		}
		if ((((! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) && (! (__context->Reset && (! __context->S_AutoReset)))) && __context->S_AutoReset)) {
			__context->DiagCode = 32775;
			goto l942;
		}
		if (((! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) && ((! ((! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) && (__context->Reset && (! __context->S_AutoReset)))) && (! (((! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) && (! (__context->Reset && (! __context->S_AutoReset)))) && __context->S_AutoReset))))) {
			goto l942;
		}
		//assert(false);
		return;  			}
	l942: {
			goto l69;
		//assert(false);
		return;  			}
	l95: {
		if ((__context->DiagCode == 49153)) {
			__context->Ready = true;
			__context->S_EnableSwitchOut = false;
			__context->Error = true;
			goto l96;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l981;
		}
		//assert(false);
		return;  			}
	l96: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l981: {
		if ((__context->DiagCode == 49154)) {
			__context->Ready = true;
			__context->S_EnableSwitchOut = false;
			__context->Error = true;
			goto l96;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l103;
		}
		//assert(false);
		return;  			}
	l103: {
		if ((__context->DiagCode == 49168)) {
			__context->Ready = true;
			__context->S_EnableSwitchOut = false;
			__context->Error = true;
			goto l96;
		}
		if ((! (__context->DiagCode == 49168))) {
			goto l108;
		}
		//assert(false);
		return;  			}
	l108: {
		if ((__context->DiagCode == 49184)) {
			__context->Ready = true;
			__context->S_EnableSwitchOut = false;
			__context->Error = true;
			goto l96;
		}
		if ((! (__context->DiagCode == 49184))) {
			goto l1131;
		}
		//assert(false);
		return;  			}
	l1131: {
		if ((__context->DiagCode == 49200)) {
			__context->Ready = true;
			__context->S_EnableSwitchOut = false;
			__context->Error = true;
			goto l96;
		}
		if ((! (__context->DiagCode == 49200))) {
			goto l1182;
		}
		//assert(false);
		return;  			}
	l1182: {
		if ((__context->DiagCode == 49216)) {
			__context->Ready = true;
			__context->S_EnableSwitchOut = false;
			__context->Error = true;
			goto l96;
		}
		if ((! (__context->DiagCode == 49216))) {
			goto l1231;
		}
		//assert(false);
		return;  			}
	l1231: {
		if ((__context->DiagCode == 0)) {
			__context->Ready = false;
			__context->S_EnableSwitchOut = false;
			__context->Error = false;
			goto l96;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l128;
		}
		//assert(false);
		return;  			}
	l128: {
		if ((__context->DiagCode == 32768)) {
			__context->Ready = true;
			__context->S_EnableSwitchOut = true;
			__context->Error = false;
			goto l96;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l133;
		}
		//assert(false);
		return;  			}
	l133: {
		if ((__context->DiagCode == 32772)) {
			__context->Ready = true;
			__context->S_EnableSwitchOut = false;
			__context->Error = false;
			goto l96;
		}
		if ((! (__context->DiagCode == 32772))) {
			goto l138;
		}
		//assert(false);
		return;  			}
	l138: {
		if ((__context->DiagCode == 32773)) {
			__context->Ready = true;
			__context->S_EnableSwitchOut = false;
			__context->Error = false;
			goto l96;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l143;
		}
		//assert(false);
		return;  			}
	l143: {
		if ((__context->DiagCode == 32774)) {
			__context->Ready = true;
			__context->S_EnableSwitchOut = false;
			__context->Error = false;
			goto l96;
		}
		if ((! (__context->DiagCode == 32774))) {
			goto l148;
		}
		//assert(false);
		return;  			}
	l148: {
		if ((__context->DiagCode == 32775)) {
			__context->Ready = true;
			__context->S_EnableSwitchOut = false;
			__context->Error = false;
			goto l96;
		}
		if ((! (__context->DiagCode == 32775))) {
			goto l96;
		}
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void VerificationLoop() {
	// Temporary variables
	
	// Start with initial location
	goto init6;
	init6: {
			goto loop_start;
		//assert(false);
		return;  			}
	end: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	loop_start: {
			instance.M1_S_AcknowledgeSS1 = nondet_bool();
			instance.M1_S_AcknowledgeSafeMotion = nondet_bool();
			instance.S0_Reset = nondet_bool();
			instance.S1_S_EStopIn = nondet_bool();
			instance.S2_S_AutoMode = nondet_bool();
			instance.S2_S_SetupMode = nondet_bool();
			instance.S4_S_EnableSwitchCh1 = nondet_bool();
			instance.S4_S_EnableSwitchCh2 = nondet_bool();
			instance.S5_S_GuardSwitch = nondet_bool();
			instance.S7_S_GuardLock = nondet_bool();
			instance.S8_UnlockGuard = nondet_bool();
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
		assert((!(EoC) || (((((! instance.S_SafeStop_M1) && (! instance.S_SafeMotion_M1)) && (! instance.S_Enable_M1)) && (! instance.S_UnlockGuard_K1)) && ((0 <= instance.CYCLE) && (instance.CYCLE <= 20)))));
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
	instance.S1_S_EStopIn = false;
	instance.S2_S_AutoMode = false;
	instance.S2_S_SetupMode = false;
	instance.S4_S_EnableSwitchCh1 = false;
	instance.S4_S_EnableSwitchCh2 = false;
	instance.S5_S_GuardSwitch = false;
	instance.S7_S_GuardLock = false;
	instance.S0_Reset = false;
	instance.S8_UnlockGuard = false;
	instance.M1_S_AcknowledgeSS1 = false;
	instance.M1_S_AcknowledgeSafeMotion = false;
	instance.S_SafeStop_M1 = false;
	instance.S_SafeMotion_M1 = false;
	instance.S_Enable_M1 = false;
	instance.S_UnlockGuard_K1 = false;
	instance.S_SetupMode = false;
	instance.S_AutoMode = false;
	instance.S_SafeStandstill = false;
	instance.S_SafeMotionActive = false;
	instance.SF_EmergencyStop_1.Activate = false;
	instance.SF_EmergencyStop_1.S_EStopIn = false;
	instance.SF_EmergencyStop_1.S_StartReset = false;
	instance.SF_EmergencyStop_1.S_AutoReset = false;
	instance.SF_EmergencyStop_1.Reset = false;
	instance.SF_EmergencyStop_1.Ready = false;
	instance.SF_EmergencyStop_1.S_EStopOut = false;
	instance.SF_EmergencyStop_1.Error = false;
	instance.SF_EmergencyStop_1.DiagCode = 0;
	instance.SF_SafetyRequest_1.Activate = false;
	instance.SF_SafetyRequest_1.S_OpMode = false;
	instance.SF_SafetyRequest_1.S_Acknowledge = false;
	instance.SF_SafetyRequest_1.MonitoringTime = 0;
	instance.SF_SafetyRequest_1.Reset = false;
	instance.SF_SafetyRequest_1.Ready = false;
	instance.SF_SafetyRequest_1.S_SafetyActive = false;
	instance.SF_SafetyRequest_1.S_SafetyRequest = false;
	instance.SF_SafetyRequest_1.Error = false;
	instance.SF_SafetyRequest_1.DiagCode = 0;
	instance.SF_SafetyRequest_2.Activate = false;
	instance.SF_SafetyRequest_2.S_OpMode = false;
	instance.SF_SafetyRequest_2.S_Acknowledge = false;
	instance.SF_SafetyRequest_2.MonitoringTime = 0;
	instance.SF_SafetyRequest_2.Reset = false;
	instance.SF_SafetyRequest_2.Ready = false;
	instance.SF_SafetyRequest_2.S_SafetyActive = false;
	instance.SF_SafetyRequest_2.S_SafetyRequest = false;
	instance.SF_SafetyRequest_2.Error = false;
	instance.SF_SafetyRequest_2.DiagCode = 0;
	instance.SF_ModeSelector_1.Activate = false;
	instance.SF_ModeSelector_1.S_Mode0 = false;
	instance.SF_ModeSelector_1.S_Mode1 = false;
	instance.SF_ModeSelector_1.S_Mode2 = false;
	instance.SF_ModeSelector_1.S_Mode3 = false;
	instance.SF_ModeSelector_1.S_Mode4 = false;
	instance.SF_ModeSelector_1.S_Mode5 = false;
	instance.SF_ModeSelector_1.S_Mode6 = false;
	instance.SF_ModeSelector_1.S_Mode7 = false;
	instance.SF_ModeSelector_1.S_Unlock = false;
	instance.SF_ModeSelector_1.Reset = false;
	instance.SF_ModeSelector_1.Ready = false;
	instance.SF_ModeSelector_1.S_Mode0Sel = false;
	instance.SF_ModeSelector_1.S_Mode1Sel = false;
	instance.SF_ModeSelector_1.S_Mode2Sel = false;
	instance.SF_ModeSelector_1.S_Mode3Sel = false;
	instance.SF_ModeSelector_1.S_Mode4Sel = false;
	instance.SF_ModeSelector_1.S_Mode5Sel = false;
	instance.SF_ModeSelector_1.S_Mode6Sel = false;
	instance.SF_ModeSelector_1.S_Mode7Sel = false;
	instance.SF_ModeSelector_1.S_AnyModeSel = false;
	instance.SF_ModeSelector_1.Error = false;
	instance.SF_ModeSelector_1.DiagCode = 0;
	instance.SF_ModeSelector_1.Error1 = false;
	instance.SF_ModeSelector_1.Error2 = false;
	instance.SF_GuardLocking_1.Activate = false;
	instance.SF_GuardLocking_1.S_GuardMonitoring = false;
	instance.SF_GuardLocking_1.S_SafetyActive = false;
	instance.SF_GuardLocking_1.S_GuardLock = false;
	instance.SF_GuardLocking_1.UnlockRequest = false;
	instance.SF_GuardLocking_1.S_StartReset = false;
	instance.SF_GuardLocking_1.S_AutoReset = false;
	instance.SF_GuardLocking_1.Reset = false;
	instance.SF_GuardLocking_1.Ready = false;
	instance.SF_GuardLocking_1.S_GuardLocked = false;
	instance.SF_GuardLocking_1.S_UnlockGuard = false;
	instance.SF_GuardLocking_1.Error = false;
	instance.SF_GuardLocking_1.DiagCode = 0;
	instance.SF_EnableSwitch_1.Activate = false;
	instance.SF_EnableSwitch_1.S_SafetyActive = false;
	instance.SF_EnableSwitch_1.S_EnableSwitchCh1 = false;
	instance.SF_EnableSwitch_1.S_EnableSwitchCh2 = false;
	instance.SF_EnableSwitch_1.S_AutoReset = false;
	instance.SF_EnableSwitch_1.Reset = false;
	instance.SF_EnableSwitch_1.Ready = false;
	instance.SF_EnableSwitch_1.S_EnableSwitchOut = false;
	instance.SF_EnableSwitch_1.Error = false;
	instance.SF_EnableSwitch_1.DiagCode = 0;
	instance.CYCLE = 0;
	EoC = false;
	
	VerificationLoop();
}

