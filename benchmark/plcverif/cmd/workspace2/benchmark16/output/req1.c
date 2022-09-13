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
	bool S_GuardSwitch1;
	bool S_GuardSwitch2;
	int32_t DiscrepancyTime;
	bool S_StartReset;
	bool S_AutoReset;
	bool Reset;
	bool Ready;
	bool S_GuardMonitoring;
	bool Error;
	int32_t DiagCode;
} __SF_GuardMonitoring;
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
	bool Activate;
	bool S_OpMode;
	bool S_Enabled;
	int32_t AxisID;
	int32_t MonitoringTime;
	bool Reset;
	bool Acknowledge;
	bool Ready;
	bool S_SafetyActive;
	bool Error;
	int32_t DiagCode;
} __SF_SafelyLimitSpeed;
typedef struct {
	bool S1_S_EStopIn;
	bool S2_S_Mode0;
	bool S2_S_Mode1;
	bool S4_S_EnableSwitchCh1;
	bool S4_S_EnableSwitchCh2;
	bool S5_S_GuardSwitch1;
	bool S6_S_GuardSwitch2;
	bool S7_S_GuardLock;
	bool S0_Reset;
	bool S8_UnlockGuard;
	bool SF_SafeStop1_1ACK;
	bool SF_SafeStop1_2ACK;
	bool SF_SLS1_ACK;
	bool SF_SLS2_ACK;
	bool S_UnlockGuard_K1;
	bool S_SafeStopAxis1;
	bool S_SafeStopAxis2;
	bool S_SafeMoveAxis1;
	bool S_SafeMoveAxis2;
	bool S_SafetyActive;
	bool S_ModeAutoActive;
	bool S_ModeSetSel;
	bool S_SLS_Enable;
	bool S_GuardLocked;
	__SF_EmergencyStop SF_EmergencyStop_1;
	__SF_SafeStop1 SF_SafeStop1_1;
	__SF_SafeStop1 SF_SafeStop1_2;
	__SF_ModeSelector SF_ModeSelector_1;
	__SF_GuardMonitoring SF_GuardMonitoring_1;
	__SF_GuardLocking SF_GuardLocking_1;
	__SF_EnableSwitch SF_EnableSwitch_1;
	__SF_SafelyLimitSpeed SF_SafelyLimitedSpeed_1;
	__SF_SafelyLimitSpeed SF_SafelyLimitedSpeed_2;
	int32_t CYCLE;
} __Main;

// Global variables
__Main instance;
bool EoC;
bool __cbmc_eoc_marker;

// Automata declarations
void Main(__Main *__context);
void SF_EmergencyStop(__SF_EmergencyStop *__context);
void SF_SafeStop1(__SF_SafeStop1 *__context);
void SF_ModeSelector(__SF_ModeSelector *__context);
void SF_GuardMonitoring(__SF_GuardMonitoring *__context);
void SF_GuardLocking(__SF_GuardLocking *__context);
void SF_EnableSwitch(__SF_EnableSwitch *__context);
void SF_SafelyLimitSpeed(__SF_SafelyLimitSpeed *__context);
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
			__context->SF_SafeStop1_1.Activate = true;
			__context->SF_SafeStop1_1.S_StopIn = __context->SF_EmergencyStop_1.S_EStopOut;
			__context->SF_SafeStop1_1.AxisID = 1;
			__context->SF_SafeStop1_1.MonitoringTime = 1000;
			__context->SF_SafeStop1_1.Reset = __context->S0_Reset;
			__context->SF_SafeStop1_1.Acknowledge = __context->SF_SafeStop1_1ACK;
			SF_SafeStop1(&__context->SF_SafeStop1_1);
			// Assign outputs
			goto l3;
		//assert(false);
		return;  			}
	l3: {
			__context->S_SafeStopAxis1 = __context->SF_SafeStop1_1.S_Stopped;
			goto l4;
		//assert(false);
		return;  			}
	l4: {
			// Assign inputs
			__context->SF_SafeStop1_2.Activate = true;
			__context->SF_SafeStop1_2.S_StopIn = __context->SF_EmergencyStop_1.S_EStopOut;
			__context->SF_SafeStop1_2.AxisID = 2;
			__context->SF_SafeStop1_2.MonitoringTime = 1000;
			__context->SF_SafeStop1_2.Reset = __context->S0_Reset;
			__context->SF_SafeStop1_2.Acknowledge = __context->SF_SafeStop1_2ACK;
			SF_SafeStop1(&__context->SF_SafeStop1_2);
			// Assign outputs
			goto l5;
		//assert(false);
		return;  			}
	l5: {
			__context->S_SafeStopAxis2 = __context->SF_SafeStop1_2.S_Stopped;
			goto l6;
		//assert(false);
		return;  			}
	l6: {
			// Assign inputs
			__context->SF_ModeSelector_1.Activate = true;
			__context->SF_ModeSelector_1.S_Mode0 = __context->S2_S_Mode0;
			__context->SF_ModeSelector_1.S_Mode1 = __context->S2_S_Mode1;
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
			goto l7;
		//assert(false);
		return;  			}
	l7: {
			__context->S_ModeSetSel = __context->SF_ModeSelector_1.S_Mode1Sel;
			__context->S_ModeAutoActive = (__context->SF_ModeSelector_1.S_Mode0Sel && __context->S_GuardLocked);
			goto l9;
		//assert(false);
		return;  			}
	l9: {
			// Assign inputs
			__context->SF_GuardMonitoring_1.Activate = true;
			__context->SF_GuardMonitoring_1.S_GuardSwitch1 = __context->S5_S_GuardSwitch1;
			__context->SF_GuardMonitoring_1.S_GuardSwitch2 = __context->S6_S_GuardSwitch2;
			__context->SF_GuardMonitoring_1.DiscrepancyTime = 50;
			__context->SF_GuardMonitoring_1.S_StartReset = false;
			__context->SF_GuardMonitoring_1.S_AutoReset = false;
			__context->SF_GuardMonitoring_1.Reset = __context->S0_Reset;
			SF_GuardMonitoring(&__context->SF_GuardMonitoring_1);
			// Assign outputs
			goto l10;
		//assert(false);
		return;  			}
	l10: {
			__context->S_SafetyActive = ((__context->S_SafeStopAxis1 && __context->S_SafeStopAxis2) || (__context->SF_SafelyLimitedSpeed_1.S_SafetyActive && __context->SF_SafelyLimitedSpeed_2.S_SafetyActive));
			goto l11;
		//assert(false);
		return;  			}
	l11: {
			// Assign inputs
			__context->SF_GuardLocking_1.Activate = true;
			__context->SF_GuardLocking_1.S_GuardMonitoring = __context->SF_GuardMonitoring_1.S_GuardMonitoring;
			__context->SF_GuardLocking_1.S_SafetyActive = __context->S_SafetyActive;
			__context->SF_GuardLocking_1.S_GuardLock = __context->S7_S_GuardLock;
			__context->SF_GuardLocking_1.UnlockRequest = __context->S8_UnlockGuard;
			__context->SF_GuardLocking_1.S_StartReset = false;
			__context->SF_GuardLocking_1.S_AutoReset = false;
			__context->SF_GuardLocking_1.Reset = __context->S0_Reset;
			SF_GuardLocking(&__context->SF_GuardLocking_1);
			// Assign outputs
			goto l12;
		//assert(false);
		return;  			}
	l12: {
			__context->S_GuardLocked = __context->SF_GuardLocking_1.S_GuardLocked;
			__context->S_UnlockGuard_K1 = __context->SF_GuardLocking_1.S_UnlockGuard;
			goto l14;
		//assert(false);
		return;  			}
	l14: {
			// Assign inputs
			__context->SF_EnableSwitch_1.Activate = true;
			__context->SF_EnableSwitch_1.S_SafetyActive = (__context->S_SafetyActive && __context->S_ModeSetSel);
			__context->SF_EnableSwitch_1.S_EnableSwitchCh1 = __context->S4_S_EnableSwitchCh1;
			__context->SF_EnableSwitch_1.S_EnableSwitchCh2 = __context->S4_S_EnableSwitchCh2;
			__context->SF_EnableSwitch_1.S_AutoReset = false;
			__context->SF_EnableSwitch_1.Reset = __context->S0_Reset;
			SF_EnableSwitch(&__context->SF_EnableSwitch_1);
			// Assign outputs
			goto l15;
		//assert(false);
		return;  			}
	l15: {
			__context->S_SLS_Enable = __context->SF_EnableSwitch_1.S_EnableSwitchOut;
			goto l16;
		//assert(false);
		return;  			}
	l16: {
			// Assign inputs
			__context->SF_SafelyLimitedSpeed_1.Activate = true;
			__context->SF_SafelyLimitedSpeed_1.S_OpMode = (__context->SF_ModeSelector_1.S_Mode0Sel && __context->S_GuardLocked);
			__context->SF_SafelyLimitedSpeed_1.S_Enabled = __context->S_SLS_Enable;
			__context->SF_SafelyLimitedSpeed_1.AxisID = 1;
			__context->SF_SafelyLimitedSpeed_1.MonitoringTime = 1000;
			__context->SF_SafelyLimitedSpeed_1.Reset = __context->S0_Reset;
			__context->SF_SafelyLimitedSpeed_1.Acknowledge = __context->SF_SLS1_ACK;
			SF_SafelyLimitSpeed(&__context->SF_SafelyLimitedSpeed_1);
			// Assign outputs
			goto l17;
		//assert(false);
		return;  			}
	l17: {
			__context->S_SafeMoveAxis1 = __context->SF_SafelyLimitedSpeed_1.S_SafetyActive;
			goto l18;
		//assert(false);
		return;  			}
	l18: {
			// Assign inputs
			__context->SF_SafelyLimitedSpeed_2.Activate = true;
			__context->SF_SafelyLimitedSpeed_2.S_OpMode = (__context->SF_ModeSelector_1.S_Mode0Sel && __context->S_GuardLocked);
			__context->SF_SafelyLimitedSpeed_2.S_Enabled = __context->S_SLS_Enable;
			__context->SF_SafelyLimitedSpeed_2.AxisID = 2;
			__context->SF_SafelyLimitedSpeed_2.MonitoringTime = 1000;
			__context->SF_SafelyLimitedSpeed_2.Reset = __context->S0_Reset;
			__context->SF_SafelyLimitedSpeed_2.Acknowledge = __context->SF_SLS2_ACK;
			SF_SafelyLimitSpeed(&__context->SF_SafelyLimitedSpeed_2);
			// Assign outputs
			goto l19;
		//assert(false);
		return;  			}
	l19: {
			__context->S_SafeMoveAxis2 = __context->SF_SafelyLimitedSpeed_2.S_SafetyActive;
			goto l20;
		//assert(false);
		return;  			}
	l20: {
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
			goto l41;
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
			goto l21;
		}
		if ((! (__context->DiagCode == 32770))) {
			goto l22;
		}
		//assert(false);
		return;  			}
	l201: {
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
void SF_SafeStop1(__SF_SafeStop1 *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init2;
	init2: {
		if ((! __context->Activate)) {
			__context->DiagCode = 0;
			goto l83;
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
			goto l83;
		//assert(false);
		return;  			}
	l52: {
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
		if ((__context->DiagCode == 32768)) {
			goto l112;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l122;
		}
		//assert(false);
		return;  			}
	l102: {
			goto l43;
		//assert(false);
		return;  			}
	l112: {
		if ((! __context->Acknowledge)) {
			__context->DiagCode = 49154;
			goto l181;
		}
		if (((! (! __context->Acknowledge)) && __context->S_StopIn)) {
			__context->DiagCode = 32786;
			goto l181;
		}
		if (((! (! __context->Acknowledge)) && (! ((! (! __context->Acknowledge)) && __context->S_StopIn)))) {
			goto l181;
		}
		//assert(false);
		return;  			}
	l122: {
		if ((__context->DiagCode == 32769)) {
			goto l191;
		}
		if ((! (__context->DiagCode == 32769))) {
			goto l202;
		}
		//assert(false);
		return;  			}
	l181: {
			goto l43;
		//assert(false);
		return;  			}
	l191: {
		if ((! __context->Acknowledge)) {
			__context->DiagCode = 32770;
			goto l261;
		}
		if (((! (! __context->Acknowledge)) && __context->Acknowledge)) {
			__context->DiagCode = 32786;
			goto l261;
		}
		if (((! (! __context->Acknowledge)) && (! ((! (! __context->Acknowledge)) && __context->Acknowledge)))) {
			goto l261;
		}
		//assert(false);
		return;  			}
	l202: {
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
		if ((! __context->S_StopIn)) {
			__context->DiagCode = 32771;
			goto l341;
		}
		if (((! (! __context->S_StopIn)) && __context->Acknowledge)) {
			__context->DiagCode = 32786;
			goto l341;
		}
		if (((! (! __context->S_StopIn)) && (! ((! (! __context->S_StopIn)) && __context->Acknowledge)))) {
			goto l341;
		}
		//assert(false);
		return;  			}
	l281: {
		if ((__context->DiagCode == 32771)) {
			goto l351;
		}
		if ((! (__context->DiagCode == 32771))) {
			goto l361;
		}
		//assert(false);
		return;  			}
	l341: {
			goto l43;
		//assert(false);
		return;  			}
	l351: {
		if (__context->S_StopIn) {
			__context->DiagCode = 32786;
			goto l421;
		}
		if (((! __context->S_StopIn) && __context->Acknowledge)) {
			__context->DiagCode = 32768;
			goto l421;
		}
		if (((! __context->S_StopIn) && (! ((! __context->S_StopIn) && __context->Acknowledge)))) {
			goto l421;
		}
		//assert(false);
		return;  			}
	l361: {
		if ((__context->DiagCode == 32773)) {
			goto l431;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l44;
		}
		//assert(false);
		return;  			}
	l421: {
			goto l43;
		//assert(false);
		return;  			}
	l431: {
		if (__context->S_StopIn) {
			__context->DiagCode = 32786;
			goto l481;
		}
		if ((! __context->S_StopIn)) {
			goto l481;
		}
		//assert(false);
		return;  			}
	l44: {
		if ((__context->DiagCode == 32786)) {
			goto l491;
		}
		if ((! (__context->DiagCode == 32786))) {
			goto l501;
		}
		//assert(false);
		return;  			}
	l481: {
			goto l43;
		//assert(false);
		return;  			}
	l491: {
		if ((! __context->Acknowledge)) {
			__context->DiagCode = 32770;
			goto l581;
		}
		if (((! (! __context->Acknowledge)) && (! __context->S_StopIn))) {
			__context->DiagCode = 32771;
			goto l581;
		}
		if ((((! (! __context->Acknowledge)) && (! (! __context->S_StopIn))) && __context->Acknowledge)) {
			__context->DiagCode = 32768;
			goto l581;
		}
		if (((! (! __context->Acknowledge)) && ((! ((! (! __context->Acknowledge)) && (! __context->S_StopIn))) && (! (((! (! __context->Acknowledge)) && (! (! __context->S_StopIn))) && __context->Acknowledge))))) {
			goto l581;
		}
		//assert(false);
		return;  			}
	l501: {
		if ((__context->DiagCode == 49154)) {
			goto l591;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l601;
		}
		//assert(false);
		return;  			}
	l581: {
			goto l43;
		//assert(false);
		return;  			}
	l591: {
		if (__context->Reset) {
			__context->DiagCode = 49156;
			goto l641;
		}
		if ((! __context->Reset)) {
			goto l641;
		}
		//assert(false);
		return;  			}
	l601: {
		if ((__context->DiagCode == 49155)) {
			goto l651;
		}
		if ((! (__context->DiagCode == 49155))) {
			goto l66;
		}
		//assert(false);
		return;  			}
	l641: {
			goto l43;
		//assert(false);
		return;  			}
	l651: {
		if (__context->Reset) {
			__context->DiagCode = 49157;
			goto l701;
		}
		if ((! __context->Reset)) {
			goto l701;
		}
		//assert(false);
		return;  			}
	l66: {
		if ((__context->DiagCode == 49156)) {
			goto l711;
		}
		if ((! (__context->DiagCode == 49156))) {
			goto l721;
		}
		//assert(false);
		return;  			}
	l701: {
			goto l43;
		//assert(false);
		return;  			}
	l711: {
		if ((! __context->Reset)) {
			__context->DiagCode = 49154;
			goto l76;
		}
		if ((! (! __context->Reset))) {
			goto l76;
		}
		//assert(false);
		return;  			}
	l721: {
		if ((__context->DiagCode == 49157)) {
			goto l77;
		}
		if ((! (__context->DiagCode == 49157))) {
			goto l43;
		}
		//assert(false);
		return;  			}
	l76: {
			goto l43;
		//assert(false);
		return;  			}
	l77: {
		if ((! __context->Reset)) {
			__context->DiagCode = 49155;
			goto l82;
		}
		if ((! (! __context->Reset))) {
			goto l82;
		}
		//assert(false);
		return;  			}
	l82: {
			goto l43;
		//assert(false);
		return;  			}
	l83: {
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
void SF_ModeSelector(__SF_ModeSelector *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init3;
	init3: {
		if ((! __context->Activate)) {
			__context->DiagCode = 0;
			goto l45;
		}
		if ((! (! __context->Activate))) {
			goto l45;
		}
		//assert(false);
		return;  			}
	l45: {
		if ((((((((__context->S_Mode0 || __context->S_Mode1) || __context->S_Mode2) || __context->S_Mode3) || __context->S_Mode4) || __context->S_Mode5) || __context->S_Mode6) || (__context->S_Mode7 == true))) {
			__context->Error1 = true;
			goto l92;
		}
		if ((! (((((((__context->S_Mode0 || __context->S_Mode1) || __context->S_Mode2) || __context->S_Mode3) || __context->S_Mode4) || __context->S_Mode5) || __context->S_Mode6) || (__context->S_Mode7 == true)))) {
			__context->Error1 = false;
			goto l92;
		}
		//assert(false);
		return;  			}
	l92: {
		if ((__context->DiagCode == 0)) {
			goto l113;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l123;
		}
		//assert(false);
		return;  			}
	l103: {
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
			goto l652;
		}
		//assert(false);
		return;  			}
	l113: {
		if (__context->Activate) {
			__context->DiagCode = 32773;
			goto l161;
		}
		if ((! __context->Activate)) {
			goto l161;
		}
		//assert(false);
		return;  			}
	l123: {
		if ((__context->DiagCode == 32768)) {
			goto l23;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l24;
		}
		//assert(false);
		return;  			}
	l161: {
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
			goto l103;
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
			goto l103;
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
			goto l401;
		}
		//assert(false);
		return;  			}
	l38: {
			goto l103;
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
	l401: {
		if ((__context->DiagCode == 49154)) {
			goto l451;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l46;
		}
		//assert(false);
		return;  			}
	l441: {
			goto l103;
		//assert(false);
		return;  			}
	l451: {
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
			goto l103;
		//assert(false);
		return;  			}
	l511: {
		if ((! __context->Reset)) {
			__context->DiagCode = 49153;
			goto l56;
		}
		if ((! (! __context->Reset))) {
			goto l56;
		}
		//assert(false);
		return;  			}
	l521: {
		if ((__context->DiagCode == 49156)) {
			goto l57;
		}
		if ((! (__context->DiagCode == 49156))) {
			goto l103;
		}
		//assert(false);
		return;  			}
	l56: {
			goto l103;
		//assert(false);
		return;  			}
	l57: {
		if ((! __context->Reset)) {
			__context->DiagCode = 49154;
			goto l621;
		}
		if ((! (! __context->Reset))) {
			goto l621;
		}
		//assert(false);
		return;  			}
	l621: {
			goto l103;
		//assert(false);
		return;  			}
	l63: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l652: {
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
			goto l911;
		}
		//assert(false);
		return;  			}
	l911: {
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
void SF_GuardMonitoring(__SF_GuardMonitoring *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init4;
	init4: {
		if ((! __context->Activate)) {
			__context->DiagCode = 0;
			goto l93;
		}
		if ((! (! __context->Activate))) {
			goto l37;
		}
		//assert(false);
		return;  			}
	l37: {
		if ((__context->DiagCode == 0)) {
			goto l53;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l67;
		}
		//assert(false);
		return;  			}
	l47: {
			goto l93;
		//assert(false);
		return;  			}
	l53: {
		if (__context->Activate) {
			__context->DiagCode = 32769;
			goto l105;
		}
		if ((! __context->Activate)) {
			goto l105;
		}
		//assert(false);
		return;  			}
	l67: {
		if ((__context->DiagCode == 32769)) {
			goto l114;
		}
		if ((! (__context->DiagCode == 32769))) {
			goto l124;
		}
		//assert(false);
		return;  			}
	l105: {
			goto l47;
		//assert(false);
		return;  			}
	l114: {
		if (((! __context->S_GuardSwitch1) || (! __context->S_GuardSwitch2))) {
			__context->DiagCode = 32770;
			goto l203;
		}
		if (((! ((! __context->S_GuardSwitch1) || (! __context->S_GuardSwitch2))) && ((__context->S_GuardSwitch1 && __context->S_GuardSwitch2) && (! __context->S_StartReset)))) {
			__context->DiagCode = 32771;
			goto l203;
		}
		if ((((! ((! __context->S_GuardSwitch1) || (! __context->S_GuardSwitch2))) && (! ((__context->S_GuardSwitch1 && __context->S_GuardSwitch2) && (! __context->S_StartReset)))) && ((__context->S_GuardSwitch1 && __context->S_GuardSwitch2) && __context->S_StartReset))) {
			__context->DiagCode = 32768;
			goto l203;
		}
		if (((! ((! __context->S_GuardSwitch1) || (! __context->S_GuardSwitch2))) && ((! ((! ((! __context->S_GuardSwitch1) || (! __context->S_GuardSwitch2))) && ((__context->S_GuardSwitch1 && __context->S_GuardSwitch2) && (! __context->S_StartReset)))) && (! (((! ((! __context->S_GuardSwitch1) || (! __context->S_GuardSwitch2))) && (! ((__context->S_GuardSwitch1 && __context->S_GuardSwitch2) && (! __context->S_StartReset)))) && ((__context->S_GuardSwitch1 && __context->S_GuardSwitch2) && __context->S_StartReset)))))) {
			goto l203;
		}
		//assert(false);
		return;  			}
	l124: {
		if ((__context->DiagCode == 32770)) {
			goto l211;
		}
		if ((! (__context->DiagCode == 32770))) {
			goto l222;
		}
		//assert(false);
		return;  			}
	l203: {
			goto l47;
		//assert(false);
		return;  			}
	l211: {
		if (((! __context->S_GuardSwitch1) && (! __context->S_GuardSwitch2))) {
			__context->DiagCode = 32786;
			goto l262;
		}
		if ((! ((! __context->S_GuardSwitch1) && (! __context->S_GuardSwitch2)))) {
			goto l262;
		}
		//assert(false);
		return;  			}
	l222: {
		if ((__context->DiagCode == 32771)) {
			goto l272;
		}
		if ((! (__context->DiagCode == 32771))) {
			goto l282;
		}
		//assert(false);
		return;  			}
	l262: {
			goto l47;
		//assert(false);
		return;  			}
	l272: {
		if (__context->Reset) {
			__context->DiagCode = 49153;
			goto l343;
		}
		if (((! __context->Reset) && ((! __context->S_GuardSwitch1) || (! __context->S_GuardSwitch2)))) {
			__context->DiagCode = 32770;
			goto l343;
		}
		if (((! __context->Reset) && (! ((! __context->Reset) && ((! __context->S_GuardSwitch1) || (! __context->S_GuardSwitch2)))))) {
			goto l343;
		}
		//assert(false);
		return;  			}
	l282: {
		if ((__context->DiagCode == 32786)) {
			goto l352;
		}
		if ((! (__context->DiagCode == 32786))) {
			goto l362;
		}
		//assert(false);
		return;  			}
	l343: {
			goto l47;
		//assert(false);
		return;  			}
	l352: {
		if (__context->S_GuardSwitch1) {
			__context->DiagCode = 32772;
			goto l422;
		}
		if (((! __context->S_GuardSwitch1) && __context->S_GuardSwitch2)) {
			__context->DiagCode = 32788;
			goto l422;
		}
		if (((! __context->S_GuardSwitch1) && (! ((! __context->S_GuardSwitch1) && __context->S_GuardSwitch2)))) {
			goto l422;
		}
		//assert(false);
		return;  			}
	l362: {
		if ((__context->DiagCode == 32772)) {
			goto l432;
		}
		if ((! (__context->DiagCode == 32772))) {
			goto l442;
		}
		//assert(false);
		return;  			}
	l422: {
			goto l47;
		//assert(false);
		return;  			}
	l432: {
		if ((! __context->S_GuardSwitch1)) {
			__context->DiagCode = 32770;
			goto l503;
		}
		if (((! (! __context->S_GuardSwitch1)) && __context->S_GuardSwitch2)) {
			__context->DiagCode = 32773;
			goto l503;
		}
		if (((! (! __context->S_GuardSwitch1)) && (! ((! (! __context->S_GuardSwitch1)) && __context->S_GuardSwitch2)))) {
			goto l503;
		}
		//assert(false);
		return;  			}
	l442: {
		if ((__context->DiagCode == 32788)) {
			goto l512;
		}
		if ((! (__context->DiagCode == 32788))) {
			goto l522;
		}
		//assert(false);
		return;  			}
	l503: {
			goto l47;
		//assert(false);
		return;  			}
	l512: {
		if ((! __context->S_GuardSwitch2)) {
			__context->DiagCode = 32770;
			goto l582;
		}
		if (((! (! __context->S_GuardSwitch2)) && __context->S_GuardSwitch1)) {
			__context->DiagCode = 32773;
			goto l582;
		}
		if (((! (! __context->S_GuardSwitch2)) && (! ((! (! __context->S_GuardSwitch2)) && __context->S_GuardSwitch1)))) {
			goto l582;
		}
		//assert(false);
		return;  			}
	l522: {
		if ((__context->DiagCode == 32773)) {
			goto l592;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l602;
		}
		//assert(false);
		return;  			}
	l582: {
			goto l47;
		//assert(false);
		return;  			}
	l592: {
		if (((! __context->S_GuardSwitch1) || (! __context->S_GuardSwitch2))) {
			__context->DiagCode = 32770;
			goto l68;
		}
		if (((! ((! __context->S_GuardSwitch1) || (! __context->S_GuardSwitch2))) && (! __context->S_AutoReset))) {
			__context->DiagCode = 32771;
			goto l68;
		}
		if ((((! ((! __context->S_GuardSwitch1) || (! __context->S_GuardSwitch2))) && (! (! __context->S_AutoReset))) && __context->S_AutoReset)) {
			__context->DiagCode = 32768;
			goto l68;
		}
		if (((! ((! __context->S_GuardSwitch1) || (! __context->S_GuardSwitch2))) && ((! ((! ((! __context->S_GuardSwitch1) || (! __context->S_GuardSwitch2))) && (! __context->S_AutoReset))) && (! (((! ((! __context->S_GuardSwitch1) || (! __context->S_GuardSwitch2))) && (! (! __context->S_AutoReset))) && __context->S_AutoReset))))) {
			goto l68;
		}
		//assert(false);
		return;  			}
	l602: {
		if ((__context->DiagCode == 32768)) {
			goto l69;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l702;
		}
		//assert(false);
		return;  			}
	l68: {
			goto l47;
		//assert(false);
		return;  			}
	l69: {
		if (((! __context->S_GuardSwitch1) || (! __context->S_GuardSwitch2))) {
			__context->DiagCode = 32770;
			goto l741;
		}
		if ((! ((! __context->S_GuardSwitch1) || (! __context->S_GuardSwitch2)))) {
			goto l741;
		}
		//assert(false);
		return;  			}
	l702: {
		if ((__context->DiagCode == 49153)) {
			goto l75;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l761;
		}
		//assert(false);
		return;  			}
	l741: {
			goto l47;
		//assert(false);
		return;  			}
	l75: {
		if ((! __context->Reset)) {
			__context->DiagCode = 32771;
			goto l80;
		}
		if ((! (! __context->Reset))) {
			goto l80;
		}
		//assert(false);
		return;  			}
	l761: {
		if ((__context->DiagCode == 49169)) {
			goto l81;
		}
		if ((! (__context->DiagCode == 49169))) {
			goto l821;
		}
		//assert(false);
		return;  			}
	l80: {
			goto l47;
		//assert(false);
		return;  			}
	l81: {
		if (((! __context->S_GuardSwitch1) && (! __context->S_GuardSwitch2))) {
			__context->DiagCode = 32786;
			goto l861;
		}
		if ((! ((! __context->S_GuardSwitch1) && (! __context->S_GuardSwitch2)))) {
			goto l861;
		}
		//assert(false);
		return;  			}
	l821: {
		if ((__context->DiagCode == 49170)) {
			goto l87;
		}
		if ((! (__context->DiagCode == 49170))) {
			goto l47;
		}
		//assert(false);
		return;  			}
	l861: {
			goto l47;
		//assert(false);
		return;  			}
	l87: {
		if (((! __context->S_GuardSwitch1) && (! __context->S_GuardSwitch2))) {
			__context->DiagCode = 32786;
			goto l921;
		}
		if ((! ((! __context->S_GuardSwitch1) && (! __context->S_GuardSwitch2)))) {
			goto l921;
		}
		//assert(false);
		return;  			}
	l921: {
			goto l47;
		//assert(false);
		return;  			}
	l93: {
		if ((__context->DiagCode == 0)) {
			__context->Ready = false;
			__context->Error = false;
			__context->S_GuardMonitoring = false;
			goto l941;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l961;
		}
		//assert(false);
		return;  			}
	l941: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l961: {
		if ((__context->DiagCode == 32768)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_GuardMonitoring = true;
			goto l941;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l1012;
		}
		//assert(false);
		return;  			}
	l1012: {
		if ((__context->DiagCode == 32769)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_GuardMonitoring = false;
			goto l941;
		}
		if ((! (__context->DiagCode == 32769))) {
			goto l1061;
		}
		//assert(false);
		return;  			}
	l1061: {
		if ((__context->DiagCode == 32770)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_GuardMonitoring = false;
			goto l941;
		}
		if ((! (__context->DiagCode == 32770))) {
			goto l1112;
		}
		//assert(false);
		return;  			}
	l1112: {
		if ((__context->DiagCode == 32771)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_GuardMonitoring = false;
			goto l941;
		}
		if ((! (__context->DiagCode == 32771))) {
			goto l1161;
		}
		//assert(false);
		return;  			}
	l1161: {
		if ((__context->DiagCode == 32786)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_GuardMonitoring = false;
			goto l941;
		}
		if ((! (__context->DiagCode == 32786))) {
			goto l1212;
		}
		//assert(false);
		return;  			}
	l1212: {
		if ((__context->DiagCode == 32773)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_GuardMonitoring = false;
			goto l941;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l1261;
		}
		//assert(false);
		return;  			}
	l1261: {
		if ((__context->DiagCode == 32772)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_GuardMonitoring = false;
			goto l941;
		}
		if ((! (__context->DiagCode == 32772))) {
			goto l1311;
		}
		//assert(false);
		return;  			}
	l1311: {
		if ((__context->DiagCode == 32788)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_GuardMonitoring = false;
			goto l941;
		}
		if ((! (__context->DiagCode == 32788))) {
			goto l136;
		}
		//assert(false);
		return;  			}
	l136: {
		if ((__context->DiagCode == 49153)) {
			__context->Ready = true;
			__context->Error = true;
			__context->S_GuardMonitoring = false;
			goto l941;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l141;
		}
		//assert(false);
		return;  			}
	l141: {
		if ((__context->DiagCode == 49169)) {
			__context->Ready = true;
			__context->Error = true;
			__context->S_GuardMonitoring = false;
			goto l941;
		}
		if ((! (__context->DiagCode == 49169))) {
			goto l146;
		}
		//assert(false);
		return;  			}
	l146: {
		if ((__context->DiagCode == 49170)) {
			__context->Ready = true;
			__context->Error = true;
			__context->S_GuardMonitoring = false;
			goto l941;
		}
		if ((! (__context->DiagCode == 49170))) {
			goto l941;
		}
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void SF_GuardLocking(__SF_GuardLocking *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init5;
	init5: {
		if ((! __context->Activate)) {
			__context->DiagCode = 0;
			goto l410;
		}
		if ((! (! __context->Activate))) {
			goto l410;
		}
		//assert(false);
		return;  			}
	l410: {
		if ((__context->DiagCode == 0)) {
			goto l610;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l73;
		}
		//assert(false);
		return;  			}
	l54: {
		if ((__context->DiagCode == 0)) {
			__context->Ready = false;
			__context->S_GuardLocked = false;
			__context->S_UnlockGuard = false;
			__context->Error = false;
			goto l98;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l100;
		}
		//assert(false);
		return;  			}
	l610: {
		if (__context->Activate) {
			__context->DiagCode = 32769;
			goto l115;
		}
		if ((! __context->Activate)) {
			goto l115;
		}
		//assert(false);
		return;  			}
	l73: {
		if ((__context->DiagCode == 32768)) {
			goto l125;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l13;
		}
		//assert(false);
		return;  			}
	l115: {
			goto l54;
		//assert(false);
		return;  			}
	l125: {
		if (((! __context->S_GuardLock) || (! __context->S_GuardMonitoring))) {
			__context->DiagCode = 49156;
			goto l192;
		}
		if (((! ((! __context->S_GuardLock) || (! __context->S_GuardMonitoring))) && __context->S_SafetyActive)) {
			__context->DiagCode = 32787;
			goto l192;
		}
		if (((! ((! __context->S_GuardLock) || (! __context->S_GuardMonitoring))) && (! ((! ((! __context->S_GuardLock) || (! __context->S_GuardMonitoring))) && __context->S_SafetyActive)))) {
			goto l192;
		}
		//assert(false);
		return;  			}
	l13: {
		if ((__context->DiagCode == 32769)) {
			goto l204;
		}
		if ((! (__context->DiagCode == 32769))) {
			goto l212;
		}
		//assert(false);
		return;  			}
	l192: {
			goto l54;
		//assert(false);
		return;  			}
	l204: {
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
	l212: {
		if ((__context->DiagCode == 32771)) {
			goto l30;
		}
		if ((! (__context->DiagCode == 32771))) {
			goto l311;
		}
		//assert(false);
		return;  			}
	l29: {
			goto l54;
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
			goto l402;
		}
		if ((! (__context->DiagCode == 32785))) {
			goto l412;
		}
		//assert(false);
		return;  			}
	l391: {
			goto l54;
		//assert(false);
		return;  			}
	l402: {
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
	l412: {
		if ((__context->DiagCode == 32786)) {
			goto l504;
		}
		if ((! (__context->DiagCode == 32786))) {
			goto l513;
		}
		//assert(false);
		return;  			}
	l492: {
			goto l54;
		//assert(false);
		return;  			}
	l504: {
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
	l513: {
		if ((__context->DiagCode == 32787)) {
			goto l583;
		}
		if ((! (__context->DiagCode == 32787))) {
			goto l593;
		}
		//assert(false);
		return;  			}
	l571: {
			goto l54;
		//assert(false);
		return;  			}
	l583: {
		if ((! __context->S_GuardMonitoring)) {
			__context->DiagCode = 32786;
			goto l653;
		}
		if (((! (! __context->S_GuardMonitoring)) && (! __context->UnlockRequest))) {
			__context->DiagCode = 32785;
			goto l653;
		}
		if (((! (! __context->S_GuardMonitoring)) && (! ((! (! __context->S_GuardMonitoring)) && (! __context->UnlockRequest))))) {
			goto l653;
		}
		//assert(false);
		return;  			}
	l593: {
		if ((__context->DiagCode == 32788)) {
			goto l661;
		}
		if ((! (__context->DiagCode == 32788))) {
			goto l671;
		}
		//assert(false);
		return;  			}
	l653: {
			goto l54;
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
			goto l54;
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
			goto l801;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l811;
		}
		//assert(false);
		return;  			}
	l791: {
			goto l54;
		//assert(false);
		return;  			}
	l801: {
		if ((! __context->Reset)) {
			__context->DiagCode = 32788;
			goto l85;
		}
		if ((! (! __context->Reset))) {
			goto l85;
		}
		//assert(false);
		return;  			}
	l811: {
		if ((__context->DiagCode == 49155)) {
			goto l862;
		}
		if ((! (__context->DiagCode == 49155))) {
			goto l871;
		}
		//assert(false);
		return;  			}
	l85: {
			goto l54;
		//assert(false);
		return;  			}
	l862: {
		if ((! __context->Reset)) {
			__context->DiagCode = 32771;
			goto l912;
		}
		if ((! (! __context->Reset))) {
			goto l912;
		}
		//assert(false);
		return;  			}
	l871: {
		if ((__context->DiagCode == 49156)) {
			goto l922;
		}
		if ((! (__context->DiagCode == 49156))) {
			goto l54;
		}
		//assert(false);
		return;  			}
	l912: {
			goto l54;
		//assert(false);
		return;  			}
	l922: {
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
			goto l54;
		//assert(false);
		return;  			}
	l98: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l100: {
		if ((__context->DiagCode == 32768)) {
			__context->Ready = true;
			__context->S_GuardLocked = true;
			__context->S_UnlockGuard = false;
			__context->Error = false;
			goto l98;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l1062;
		}
		//assert(false);
		return;  			}
	l1062: {
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
			goto l118;
		}
		//assert(false);
		return;  			}
	l118: {
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
			goto l130;
		}
		//assert(false);
		return;  			}
	l130: {
		if (((__context->DiagCode == 32786) || (__context->DiagCode == 32787))) {
			__context->Ready = true;
			__context->S_GuardLocked = false;
			__context->S_UnlockGuard = true;
			__context->Error = false;
			goto l98;
		}
		if ((! ((__context->DiagCode == 32786) || (__context->DiagCode == 32787)))) {
			goto l1361;
		}
		//assert(false);
		return;  			}
	l1361: {
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
	goto init6;
	init6: {
		if ((! __context->Activate)) {
			__context->DiagCode = 0;
			goto l95;
		}
		if (((! (! __context->Activate)) && (! __context->S_SafetyActive))) {
			__context->DiagCode = 32772;
			goto l95;
		}
		if (((! (! __context->Activate)) && (! ((! (! __context->Activate)) && (! __context->S_SafetyActive))))) {
			goto l55;
		}
		//assert(false);
		return;  			}
	l55: {
		if ((__context->DiagCode == 0)) {
			goto l710;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l8;
		}
		//assert(false);
		return;  			}
	l611: {
			goto l95;
		//assert(false);
		return;  			}
	l710: {
		if (__context->Activate) {
			__context->DiagCode = 32772;
			goto l127;
		}
		if ((! __context->Activate)) {
			goto l127;
		}
		//assert(false);
		return;  			}
	l8: {
		if ((__context->DiagCode == 32768)) {
			goto l132;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l142;
		}
		//assert(false);
		return;  			}
	l127: {
			goto l611;
		//assert(false);
		return;  			}
	l132: {
		if (((! (__context->S_EnableSwitchCh1 || __context->S_EnableSwitchCh2)) || (__context->S_EnableSwitchCh1 && (! __context->S_EnableSwitchCh2)))) {
			__context->DiagCode = 32775;
			goto l205;
		}
		if (((! ((! (__context->S_EnableSwitchCh1 || __context->S_EnableSwitchCh2)) || (__context->S_EnableSwitchCh1 && (! __context->S_EnableSwitchCh2)))) && ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) {
			__context->DiagCode = 32774;
			goto l205;
		}
		if (((! ((! (__context->S_EnableSwitchCh1 || __context->S_EnableSwitchCh2)) || (__context->S_EnableSwitchCh1 && (! __context->S_EnableSwitchCh2)))) && (! ((! ((! (__context->S_EnableSwitchCh1 || __context->S_EnableSwitchCh2)) || (__context->S_EnableSwitchCh1 && (! __context->S_EnableSwitchCh2)))) && ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))))) {
			goto l205;
		}
		//assert(false);
		return;  			}
	l142: {
		if ((__context->DiagCode == 32772)) {
			goto l213;
		}
		if ((! (__context->DiagCode == 32772))) {
			goto l223;
		}
		//assert(false);
		return;  			}
	l205: {
			goto l611;
		//assert(false);
		return;  			}
	l213: {
		if (__context->S_SafetyActive) {
			__context->DiagCode = 32773;
			goto l263;
		}
		if ((! __context->S_SafetyActive)) {
			goto l263;
		}
		//assert(false);
		return;  			}
	l223: {
		if ((__context->DiagCode == 32773)) {
			goto l273;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l283;
		}
		//assert(false);
		return;  			}
	l263: {
			goto l611;
		//assert(false);
		return;  			}
	l273: {
		if ((! ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) {
			__context->DiagCode = 49168;
			goto l344;
		}
		if (((! (! ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) && ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) {
			__context->DiagCode = 32774;
			goto l344;
		}
		if (((! (! ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) && (! ((! (! ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) && ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))))) {
			goto l344;
		}
		//assert(false);
		return;  			}
	l283: {
		if ((__context->DiagCode == 32774)) {
			goto l353;
		}
		if ((! (__context->DiagCode == 32774))) {
			goto l363;
		}
		//assert(false);
		return;  			}
	l344: {
			goto l611;
		//assert(false);
		return;  			}
	l353: {
		if ((__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) {
			__context->DiagCode = 32768;
			goto l423;
		}
		if (((! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) && ((! (__context->S_EnableSwitchCh1 || __context->S_EnableSwitchCh2)) || (__context->S_EnableSwitchCh1 && (! __context->S_EnableSwitchCh2))))) {
			__context->DiagCode = 32775;
			goto l423;
		}
		if (((! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) && (! ((! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) && ((! (__context->S_EnableSwitchCh1 || __context->S_EnableSwitchCh2)) || (__context->S_EnableSwitchCh1 && (! __context->S_EnableSwitchCh2))))))) {
			goto l423;
		}
		//assert(false);
		return;  			}
	l363: {
		if ((__context->DiagCode == 32775)) {
			goto l433;
		}
		if ((! (__context->DiagCode == 32775))) {
			goto l443;
		}
		//assert(false);
		return;  			}
	l423: {
			goto l611;
		//assert(false);
		return;  			}
	l433: {
		if ((__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) {
			__context->DiagCode = 49200;
			goto l505;
		}
		if (((! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) && ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))) {
			__context->DiagCode = 32774;
			goto l505;
		}
		if (((! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) && (! ((! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)) && ((! __context->S_EnableSwitchCh1) && __context->S_EnableSwitchCh2))))) {
			goto l505;
		}
		//assert(false);
		return;  			}
	l443: {
		if ((__context->DiagCode == 49153)) {
			goto l514;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l523;
		}
		//assert(false);
		return;  			}
	l505: {
			goto l611;
		//assert(false);
		return;  			}
	l514: {
		if ((! __context->Reset)) {
			__context->DiagCode = 49184;
			goto l561;
		}
		if ((! (! __context->Reset))) {
			goto l561;
		}
		//assert(false);
		return;  			}
	l523: {
		if ((__context->DiagCode == 49154)) {
			goto l572;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l584;
		}
		//assert(false);
		return;  			}
	l561: {
			goto l611;
		//assert(false);
		return;  			}
	l572: {
		if ((! __context->Reset)) {
			__context->DiagCode = 49216;
			goto l622;
		}
		if ((! (! __context->Reset))) {
			goto l622;
		}
		//assert(false);
		return;  			}
	l584: {
		if ((__context->DiagCode == 49168)) {
			goto l631;
		}
		if ((! (__context->DiagCode == 49168))) {
			goto l642;
		}
		//assert(false);
		return;  			}
	l622: {
			goto l611;
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
	l642: {
		if ((__context->DiagCode == 49184)) {
			goto l691;
		}
		if ((! (__context->DiagCode == 49184))) {
			goto l703;
		}
		//assert(false);
		return;  			}
	l681: {
			goto l611;
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
	l703: {
		if ((__context->DiagCode == 49200)) {
			goto l792;
		}
		if ((! (__context->DiagCode == 49200))) {
			goto l802;
		}
		//assert(false);
		return;  			}
	l781: {
			goto l611;
		//assert(false);
		return;  			}
	l792: {
		if ((! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2))) {
			__context->DiagCode = 49216;
			goto l842;
		}
		if ((! (! (__context->S_EnableSwitchCh1 && __context->S_EnableSwitchCh2)))) {
			goto l842;
		}
		//assert(false);
		return;  			}
	l802: {
		if ((__context->DiagCode == 49216)) {
			goto l851;
		}
		if ((! (__context->DiagCode == 49216))) {
			goto l611;
		}
		//assert(false);
		return;  			}
	l842: {
			goto l611;
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
			goto l611;
		//assert(false);
		return;  			}
	l95: {
		if ((__context->DiagCode == 49153)) {
			__context->Ready = true;
			__context->S_EnableSwitchOut = false;
			__context->Error = true;
			goto l962;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l981;
		}
		//assert(false);
		return;  			}
	l962: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l981: {
		if ((__context->DiagCode == 49154)) {
			__context->Ready = true;
			__context->S_EnableSwitchOut = false;
			__context->Error = true;
			goto l962;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l1031;
		}
		//assert(false);
		return;  			}
	l1031: {
		if ((__context->DiagCode == 49168)) {
			__context->Ready = true;
			__context->S_EnableSwitchOut = false;
			__context->Error = true;
			goto l962;
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
			goto l962;
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
			goto l962;
		}
		if ((! (__context->DiagCode == 49200))) {
			goto l1181;
		}
		//assert(false);
		return;  			}
	l1181: {
		if ((__context->DiagCode == 49216)) {
			__context->Ready = true;
			__context->S_EnableSwitchOut = false;
			__context->Error = true;
			goto l962;
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
			goto l962;
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
			goto l962;
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
			goto l962;
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
			goto l962;
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
			goto l962;
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
			goto l962;
		}
		if ((! (__context->DiagCode == 32775))) {
			goto l962;
		}
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void SF_SafelyLimitSpeed(__SF_SafelyLimitSpeed *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init7;
	init7: {
		if ((! __context->Activate)) {
			__context->DiagCode = 0;
			goto l413;
		}
		if ((! (! __context->Activate))) {
			goto l413;
		}
		//assert(false);
		return;  			}
	l413: {
		if ((__context->DiagCode == 0)) {
			goto l612;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l712;
		}
		//assert(false);
		return;  			}
	l510: {
		if ((__context->DiagCode == 0)) {
			__context->Ready = false;
			__context->S_SafetyActive = false;
			__context->Error = false;
			goto l1042;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l1063;
		}
		//assert(false);
		return;  			}
	l612: {
		if (__context->Activate) {
			__context->DiagCode = 32769;
			goto l117;
		}
		if ((! __context->Activate)) {
			goto l117;
		}
		//assert(false);
		return;  			}
	l712: {
		if ((__context->DiagCode == 32768)) {
			goto l129;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l134;
		}
		//assert(false);
		return;  			}
	l117: {
			goto l510;
		//assert(false);
		return;  			}
	l129: {
		if ((! __context->Acknowledge)) {
			__context->DiagCode = 49154;
			goto l214;
		}
		if (((! (! __context->Acknowledge)) && __context->S_OpMode)) {
			__context->DiagCode = 32786;
			goto l214;
		}
		if ((((! (! __context->Acknowledge)) && (! __context->S_OpMode)) && __context->S_Enabled)) {
			__context->DiagCode = 32772;
			goto l214;
		}
		if (((! (! __context->Acknowledge)) && ((! ((! (! __context->Acknowledge)) && __context->S_OpMode)) && (! (((! (! __context->Acknowledge)) && (! __context->S_OpMode)) && __context->S_Enabled))))) {
			goto l214;
		}
		//assert(false);
		return;  			}
	l134: {
		if ((__context->DiagCode == 32769)) {
			goto l224;
		}
		if ((! (__context->DiagCode == 32769))) {
			goto l231;
		}
		//assert(false);
		return;  			}
	l214: {
			goto l510;
		//assert(false);
		return;  			}
	l224: {
		if (__context->Reset) {
			__context->DiagCode = 49153;
			goto l312;
		}
		if (((! __context->Reset) && (! __context->Acknowledge))) {
			__context->DiagCode = 32770;
			goto l312;
		}
		if ((((! __context->Reset) && (! (! __context->Acknowledge))) && __context->Acknowledge)) {
			__context->DiagCode = 32786;
			goto l312;
		}
		if (((! __context->Reset) && ((! ((! __context->Reset) && (! __context->Acknowledge))) && (! (((! __context->Reset) && (! (! __context->Acknowledge))) && __context->Acknowledge))))) {
			goto l312;
		}
		//assert(false);
		return;  			}
	l231: {
		if ((__context->DiagCode == 32770)) {
			goto l322;
		}
		if ((! (__context->DiagCode == 32770))) {
			goto l331;
		}
		//assert(false);
		return;  			}
	l312: {
			goto l510;
		//assert(false);
		return;  			}
	l322: {
		if ((! __context->S_OpMode)) {
			__context->DiagCode = 32771;
			goto l392;
		}
		if (((! (! __context->S_OpMode)) && __context->Acknowledge)) {
			__context->DiagCode = 32786;
			goto l392;
		}
		if (((! (! __context->S_OpMode)) && (! ((! (! __context->S_OpMode)) && __context->Acknowledge)))) {
			goto l392;
		}
		//assert(false);
		return;  			}
	l331: {
		if ((__context->DiagCode == 32771)) {
			goto l403;
		}
		if ((! (__context->DiagCode == 32771))) {
			goto l414;
		}
		//assert(false);
		return;  			}
	l392: {
			goto l510;
		//assert(false);
		return;  			}
	l403: {
		if (__context->S_OpMode) {
			__context->DiagCode = 32786;
			goto l493;
		}
		if (((! __context->S_OpMode) && (__context->Acknowledge && (! __context->S_Enabled)))) {
			__context->DiagCode = 32768;
			goto l493;
		}
		if ((((! __context->S_OpMode) && (! (__context->Acknowledge && (! __context->S_Enabled)))) && (__context->Acknowledge && __context->S_Enabled))) {
			__context->DiagCode = 32772;
			goto l493;
		}
		if (((! __context->S_OpMode) && ((! ((! __context->S_OpMode) && (__context->Acknowledge && (! __context->S_Enabled)))) && (! (((! __context->S_OpMode) && (! (__context->Acknowledge && (! __context->S_Enabled)))) && (__context->Acknowledge && __context->S_Enabled)))))) {
			goto l493;
		}
		//assert(false);
		return;  			}
	l414: {
		if ((__context->DiagCode == 32772)) {
			goto l506;
		}
		if ((! (__context->DiagCode == 32772))) {
			goto l515;
		}
		//assert(false);
		return;  			}
	l493: {
			goto l510;
		//assert(false);
		return;  			}
	l506: {
		if ((! __context->Acknowledge)) {
			__context->DiagCode = 49154;
			goto l594;
		}
		if (((! (! __context->Acknowledge)) && __context->S_OpMode)) {
			__context->DiagCode = 32786;
			goto l594;
		}
		if ((((! (! __context->Acknowledge)) && (! __context->S_OpMode)) && (! __context->S_Enabled))) {
			__context->DiagCode = 32768;
			goto l594;
		}
		if (((! (! __context->Acknowledge)) && ((! ((! (! __context->Acknowledge)) && __context->S_OpMode)) && (! (((! (! __context->Acknowledge)) && (! __context->S_OpMode)) && (! __context->S_Enabled)))))) {
			goto l594;
		}
		//assert(false);
		return;  			}
	l515: {
		if ((__context->DiagCode == 32773)) {
			goto l603;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l613;
		}
		//assert(false);
		return;  			}
	l594: {
			goto l510;
		//assert(false);
		return;  			}
	l603: {
		if (__context->S_OpMode) {
			__context->DiagCode = 32786;
			goto l654;
		}
		if ((! __context->S_OpMode)) {
			goto l654;
		}
		//assert(false);
		return;  			}
	l613: {
		if ((__context->DiagCode == 32786)) {
			goto l662;
		}
		if ((! (__context->DiagCode == 32786))) {
			goto l672;
		}
		//assert(false);
		return;  			}
	l654: {
			goto l510;
		//assert(false);
		return;  			}
	l662: {
		if ((! __context->Acknowledge)) {
			__context->DiagCode = 32770;
			goto l732;
		}
		if (((! (! __context->Acknowledge)) && (! __context->S_OpMode))) {
			__context->DiagCode = 32771;
			goto l732;
		}
		if (((! (! __context->Acknowledge)) && (! ((! (! __context->Acknowledge)) && (! __context->S_OpMode))))) {
			goto l732;
		}
		//assert(false);
		return;  			}
	l672: {
		if ((__context->DiagCode == 49153)) {
			goto l743;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l752;
		}
		//assert(false);
		return;  			}
	l732: {
			goto l510;
		//assert(false);
		return;  			}
	l743: {
		if ((! __context->Reset)) {
			__context->DiagCode = 32769;
			goto l793;
		}
		if ((! (! __context->Reset))) {
			goto l793;
		}
		//assert(false);
		return;  			}
	l752: {
		if ((__context->DiagCode == 49154)) {
			goto l803;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l812;
		}
		//assert(false);
		return;  			}
	l793: {
			goto l510;
		//assert(false);
		return;  			}
	l803: {
		if (__context->Reset) {
			__context->DiagCode = 49156;
			goto l852;
		}
		if ((! __context->Reset)) {
			goto l852;
		}
		//assert(false);
		return;  			}
	l812: {
		if ((__context->DiagCode == 49155)) {
			goto l863;
		}
		if ((! (__context->DiagCode == 49155))) {
			goto l872;
		}
		//assert(false);
		return;  			}
	l852: {
			goto l510;
		//assert(false);
		return;  			}
	l863: {
		if (__context->Reset) {
			__context->DiagCode = 49157;
			goto l913;
		}
		if ((! __context->Reset)) {
			goto l913;
		}
		//assert(false);
		return;  			}
	l872: {
		if ((__context->DiagCode == 49156)) {
			goto l923;
		}
		if ((! (__context->DiagCode == 49156))) {
			goto l931;
		}
		//assert(false);
		return;  			}
	l913: {
			goto l510;
		//assert(false);
		return;  			}
	l923: {
		if ((! __context->Reset)) {
			__context->DiagCode = 49154;
			goto l971;
		}
		if ((! (! __context->Reset))) {
			goto l971;
		}
		//assert(false);
		return;  			}
	l931: {
		if ((__context->DiagCode == 49157)) {
			goto l982;
		}
		if ((! (__context->DiagCode == 49157))) {
			goto l510;
		}
		//assert(false);
		return;  			}
	l971: {
			goto l510;
		//assert(false);
		return;  			}
	l982: {
		if ((! __context->Reset)) {
			__context->DiagCode = 49155;
			goto l1032;
		}
		if ((! (! __context->Reset))) {
			goto l1032;
		}
		//assert(false);
		return;  			}
	l1032: {
			goto l510;
		//assert(false);
		return;  			}
	l1042: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l1063: {
		if (((__context->DiagCode == 32768) || (__context->DiagCode == 32772))) {
			__context->Ready = true;
			__context->S_SafetyActive = true;
			__context->Error = false;
			goto l1042;
		}
		if ((! ((__context->DiagCode == 32768) || (__context->DiagCode == 32772)))) {
			goto l1113;
		}
		//assert(false);
		return;  			}
	l1113: {
		if (((__context->DiagCode == 32769) || ((__context->DiagCode == 32770) || ((__context->DiagCode == 32771) || ((__context->DiagCode == 32773) || (__context->DiagCode == 32786)))))) {
			__context->Ready = true;
			__context->S_SafetyActive = false;
			__context->Error = false;
			goto l1042;
		}
		if ((! ((__context->DiagCode == 32769) || ((__context->DiagCode == 32770) || ((__context->DiagCode == 32771) || ((__context->DiagCode == 32773) || (__context->DiagCode == 32786))))))) {
			goto l1162;
		}
		//assert(false);
		return;  			}
	l1162: {
		if (((__context->DiagCode == 49153) || ((__context->DiagCode == 49154) || ((__context->DiagCode == 49155) || ((__context->DiagCode == 49156) || (__context->DiagCode == 49157)))))) {
			__context->Ready = true;
			__context->S_SafetyActive = false;
			__context->Error = true;
			goto l1042;
		}
		if ((! ((__context->DiagCode == 49153) || ((__context->DiagCode == 49154) || ((__context->DiagCode == 49155) || ((__context->DiagCode == 49156) || (__context->DiagCode == 49157))))))) {
			goto l1042;
		}
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void VerificationLoop() {
	// Temporary variables
	
	// Start with initial location
	goto init8;
	init8: {
			goto loop_start;
		//assert(false);
		return;  			}
	end: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	loop_start: {
			instance.S0_Reset = nondet_bool();
			instance.S1_S_EStopIn = nondet_bool();
			instance.S2_S_Mode0 = nondet_bool();
			instance.S2_S_Mode1 = nondet_bool();
			instance.S4_S_EnableSwitchCh1 = nondet_bool();
			instance.S4_S_EnableSwitchCh2 = nondet_bool();
			instance.S5_S_GuardSwitch1 = nondet_bool();
			instance.S6_S_GuardSwitch2 = nondet_bool();
			instance.S7_S_GuardLock = nondet_bool();
			instance.S8_UnlockGuard = nondet_bool();
			instance.SF_SLS1_ACK = nondet_bool();
			instance.SF_SLS2_ACK = nondet_bool();
			instance.SF_SafeStop1_1ACK = nondet_bool();
			instance.SF_SafeStop1_2ACK = nondet_bool();
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
		assert((!(EoC) || ((instance.S_SafeStopAxis1 && instance.S_SafeStopAxis2) && ((0 <= instance.CYCLE) && (instance.CYCLE <= 20)))));
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
	instance.S2_S_Mode0 = false;
	instance.S2_S_Mode1 = false;
	instance.S4_S_EnableSwitchCh1 = false;
	instance.S4_S_EnableSwitchCh2 = false;
	instance.S5_S_GuardSwitch1 = false;
	instance.S6_S_GuardSwitch2 = false;
	instance.S7_S_GuardLock = false;
	instance.S0_Reset = false;
	instance.S8_UnlockGuard = false;
	instance.SF_SafeStop1_1ACK = false;
	instance.SF_SafeStop1_2ACK = false;
	instance.SF_SLS1_ACK = false;
	instance.SF_SLS2_ACK = false;
	instance.S_UnlockGuard_K1 = false;
	instance.S_SafeStopAxis1 = false;
	instance.S_SafeStopAxis2 = false;
	instance.S_SafeMoveAxis1 = false;
	instance.S_SafeMoveAxis2 = false;
	instance.S_SafetyActive = false;
	instance.S_ModeAutoActive = false;
	instance.S_ModeSetSel = false;
	instance.S_SLS_Enable = false;
	instance.S_GuardLocked = false;
	instance.SF_EmergencyStop_1.Activate = false;
	instance.SF_EmergencyStop_1.S_EStopIn = false;
	instance.SF_EmergencyStop_1.S_StartReset = false;
	instance.SF_EmergencyStop_1.S_AutoReset = false;
	instance.SF_EmergencyStop_1.Reset = false;
	instance.SF_EmergencyStop_1.Ready = false;
	instance.SF_EmergencyStop_1.S_EStopOut = false;
	instance.SF_EmergencyStop_1.Error = false;
	instance.SF_EmergencyStop_1.DiagCode = 0;
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
	instance.SF_SafeStop1_2.Activate = false;
	instance.SF_SafeStop1_2.S_StopIn = false;
	instance.SF_SafeStop1_2.AxisID = 0;
	instance.SF_SafeStop1_2.MonitoringTime = 0;
	instance.SF_SafeStop1_2.Reset = false;
	instance.SF_SafeStop1_2.Acknowledge = false;
	instance.SF_SafeStop1_2.Ready = false;
	instance.SF_SafeStop1_2.S_Stopped = false;
	instance.SF_SafeStop1_2.Error = false;
	instance.SF_SafeStop1_2.DiagCode = 0;
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
	instance.SF_GuardMonitoring_1.Activate = false;
	instance.SF_GuardMonitoring_1.S_GuardSwitch1 = false;
	instance.SF_GuardMonitoring_1.S_GuardSwitch2 = false;
	instance.SF_GuardMonitoring_1.DiscrepancyTime = 0;
	instance.SF_GuardMonitoring_1.S_StartReset = false;
	instance.SF_GuardMonitoring_1.S_AutoReset = false;
	instance.SF_GuardMonitoring_1.Reset = false;
	instance.SF_GuardMonitoring_1.Ready = false;
	instance.SF_GuardMonitoring_1.S_GuardMonitoring = false;
	instance.SF_GuardMonitoring_1.Error = false;
	instance.SF_GuardMonitoring_1.DiagCode = 0;
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
	instance.SF_SafelyLimitedSpeed_1.Activate = false;
	instance.SF_SafelyLimitedSpeed_1.S_OpMode = false;
	instance.SF_SafelyLimitedSpeed_1.S_Enabled = false;
	instance.SF_SafelyLimitedSpeed_1.AxisID = 0;
	instance.SF_SafelyLimitedSpeed_1.MonitoringTime = 0;
	instance.SF_SafelyLimitedSpeed_1.Reset = false;
	instance.SF_SafelyLimitedSpeed_1.Acknowledge = false;
	instance.SF_SafelyLimitedSpeed_1.Ready = false;
	instance.SF_SafelyLimitedSpeed_1.S_SafetyActive = false;
	instance.SF_SafelyLimitedSpeed_1.Error = false;
	instance.SF_SafelyLimitedSpeed_1.DiagCode = 0;
	instance.SF_SafelyLimitedSpeed_2.Activate = false;
	instance.SF_SafelyLimitedSpeed_2.S_OpMode = false;
	instance.SF_SafelyLimitedSpeed_2.S_Enabled = false;
	instance.SF_SafelyLimitedSpeed_2.AxisID = 0;
	instance.SF_SafelyLimitedSpeed_2.MonitoringTime = 0;
	instance.SF_SafelyLimitedSpeed_2.Reset = false;
	instance.SF_SafelyLimitedSpeed_2.Acknowledge = false;
	instance.SF_SafelyLimitedSpeed_2.Ready = false;
	instance.SF_SafelyLimitedSpeed_2.S_SafetyActive = false;
	instance.SF_SafelyLimitedSpeed_2.Error = false;
	instance.SF_SafelyLimitedSpeed_2.DiagCode = 0;
	instance.CYCLE = 0;
	EoC = false;
	
	VerificationLoop();
}

