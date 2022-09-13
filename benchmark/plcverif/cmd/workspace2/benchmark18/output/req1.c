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
	bool S_Mode0;
	bool S_Mode1;
	bool S_Mode2;
	bool S_Mode3;
	bool S_Mode4;
	bool S_Mode5;
	bool S_Mode6;
	bool S_Mode7;
	bool S_Unlock;
	bool S_SetMode;
	bool AutoSetMode;
	int32_t ModeMonitorTime;
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
	int32_t CYCLE;
} __Main;

// Global variables
__Main instance;
bool EoC;
bool __cbmc_eoc_marker;

// Automata declarations
void Main(__Main *__context);
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
		if ((! __context->Activate)) {
			__context->DiagCode = 0;
			goto l5;
		}
		if ((! (! __context->Activate))) {
			goto l5;
		}
		//assert(false);
		return;  			}
	l5: {
		if ((((((__context->S_Mode0 || __context->S_Mode1) || __context->S_Mode2) || __context->S_Mode3) || __context->S_Mode4) && (((__context->S_Mode5 || __context->S_Mode6) || __context->S_Mode7) == true))) {
			__context->Error1 = true;
			goto l10;
		}
		if ((! (((((__context->S_Mode0 || __context->S_Mode1) || __context->S_Mode2) || __context->S_Mode3) || __context->S_Mode4) && (((__context->S_Mode5 || __context->S_Mode6) || __context->S_Mode7) == true)))) {
			__context->Error1 = false;
			goto l10;
		}
		//assert(false);
		return;  			}
	l10: {
		if ((__context->DiagCode == 0)) {
			goto l12;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l13;
		}
		//assert(false);
		return;  			}
	l11: {
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
			goto l76;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l78;
		}
		//assert(false);
		return;  			}
	l12: {
		if (__context->Activate) {
			__context->DiagCode = 32773;
			goto l17;
		}
		if ((! __context->Activate)) {
			goto l17;
		}
		//assert(false);
		return;  			}
	l13: {
		if ((__context->DiagCode == 32773)) {
			goto l18;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l19;
		}
		//assert(false);
		return;  			}
	l17: {
			goto l11;
		//assert(false);
		return;  			}
	l18: {
		if (__context->Error1) {
			__context->DiagCode = 49153;
			goto l35;
		}
		if (((! __context->Error1) && __context->Error2)) {
			__context->DiagCode = 49154;
			goto l35;
		}
		if ((((! __context->Error1) && (! __context->Error2)) && ((__context->AutoSetMode && __context->S_Unlock) && (((((((__context->S_Mode0 || __context->S_Mode1) || __context->S_Mode2) || __context->S_Mode3) || __context->S_Mode4) || __context->S_Mode5) || __context->S_Mode6) || (__context->S_Mode7 == true))))) {
			__context->DiagCode = 32768;
			__context->S_Mode0Sel = __context->S_Mode0;
			__context->S_Mode1Sel = __context->S_Mode1;
			__context->S_Mode2Sel = __context->S_Mode2;
			__context->S_Mode3Sel = __context->S_Mode3;
			__context->S_Mode4Sel = __context->S_Mode4;
			__context->S_Mode5Sel = __context->S_Mode5;
			__context->S_Mode6Sel = __context->S_Mode6;
			__context->S_Mode7Sel = __context->S_Mode7;
			goto l35;
		}
		if (((! __context->Error1) && ((! ((! __context->Error1) && __context->Error2)) && (! (((! __context->Error1) && (! __context->Error2)) && ((__context->AutoSetMode && __context->S_Unlock) && (((((((__context->S_Mode0 || __context->S_Mode1) || __context->S_Mode2) || __context->S_Mode3) || __context->S_Mode4) || __context->S_Mode5) || __context->S_Mode6) || (__context->S_Mode7 == true)))))))) {
			goto l35;
		}
		//assert(false);
		return;  			}
	l19: {
		if ((__context->DiagCode == 32768)) {
			goto l36;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l37;
		}
		//assert(false);
		return;  			}
	l35: {
			goto l11;
		//assert(false);
		return;  			}
	l36: {
		if (__context->Error1) {
			__context->DiagCode = 49153;
			goto l45;
		}
		if (((! __context->Error1) && ((((((((__context->S_Mode0 != __context->S_Mode0Sel) || (__context->S_Mode1 != __context->S_Mode1Sel)) || (__context->S_Mode2 != __context->S_Mode2Sel)) || (__context->S_Mode3 != __context->S_Mode3Sel)) || (__context->S_Mode4 != __context->S_Mode4Sel)) || (__context->S_Mode5 != __context->S_Mode5Sel)) || (__context->S_Mode6 != __context->S_Mode6Sel)) || (__context->S_Mode7 != __context->S_Mode7Sel)))) {
			__context->DiagCode = 32773;
			goto l45;
		}
		if ((((! __context->Error1) && (! ((((((((__context->S_Mode0 != __context->S_Mode0Sel) || (__context->S_Mode1 != __context->S_Mode1Sel)) || (__context->S_Mode2 != __context->S_Mode2Sel)) || (__context->S_Mode3 != __context->S_Mode3Sel)) || (__context->S_Mode4 != __context->S_Mode4Sel)) || (__context->S_Mode5 != __context->S_Mode5Sel)) || (__context->S_Mode6 != __context->S_Mode6Sel)) || (__context->S_Mode7 != __context->S_Mode7Sel)))) && (! __context->S_Unlock))) {
			__context->DiagCode = 32772;
			goto l45;
		}
		if (((! __context->Error1) && ((! ((! __context->Error1) && ((((((((__context->S_Mode0 != __context->S_Mode0Sel) || (__context->S_Mode1 != __context->S_Mode1Sel)) || (__context->S_Mode2 != __context->S_Mode2Sel)) || (__context->S_Mode3 != __context->S_Mode3Sel)) || (__context->S_Mode4 != __context->S_Mode4Sel)) || (__context->S_Mode5 != __context->S_Mode5Sel)) || (__context->S_Mode6 != __context->S_Mode6Sel)) || (__context->S_Mode7 != __context->S_Mode7Sel)))) && (! (((! __context->Error1) && (! ((((((((__context->S_Mode0 != __context->S_Mode0Sel) || (__context->S_Mode1 != __context->S_Mode1Sel)) || (__context->S_Mode2 != __context->S_Mode2Sel)) || (__context->S_Mode3 != __context->S_Mode3Sel)) || (__context->S_Mode4 != __context->S_Mode4Sel)) || (__context->S_Mode5 != __context->S_Mode5Sel)) || (__context->S_Mode6 != __context->S_Mode6Sel)) || (__context->S_Mode7 != __context->S_Mode7Sel)))) && (! __context->S_Unlock)))))) {
			goto l45;
		}
		//assert(false);
		return;  			}
	l37: {
		if ((__context->DiagCode == 32772)) {
			goto l46;
		}
		if ((! (__context->DiagCode == 32772))) {
			goto l47;
		}
		//assert(false);
		return;  			}
	l45: {
			goto l11;
		//assert(false);
		return;  			}
	l46: {
		if (__context->S_Unlock) {
			__context->DiagCode = 32768;
			goto l51;
		}
		if ((! __context->S_Unlock)) {
			goto l51;
		}
		//assert(false);
		return;  			}
	l47: {
		if ((__context->DiagCode == 49153)) {
			goto l52;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l53;
		}
		//assert(false);
		return;  			}
	l51: {
			goto l11;
		//assert(false);
		return;  			}
	l52: {
		if (__context->Reset) {
			__context->DiagCode = 49155;
			goto l57;
		}
		if ((! __context->Reset)) {
			goto l57;
		}
		//assert(false);
		return;  			}
	l53: {
		if ((__context->DiagCode == 49154)) {
			goto l58;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l59;
		}
		//assert(false);
		return;  			}
	l57: {
			goto l11;
		//assert(false);
		return;  			}
	l58: {
		if (__context->Reset) {
			__context->DiagCode = 49156;
			goto l63;
		}
		if ((! __context->Reset)) {
			goto l63;
		}
		//assert(false);
		return;  			}
	l59: {
		if ((__context->DiagCode == 49155)) {
			goto l64;
		}
		if ((! (__context->DiagCode == 49155))) {
			goto l65;
		}
		//assert(false);
		return;  			}
	l63: {
			goto l11;
		//assert(false);
		return;  			}
	l64: {
		if ((! __context->Reset)) {
			__context->DiagCode = 49153;
			goto l69;
		}
		if ((! (! __context->Reset))) {
			goto l69;
		}
		//assert(false);
		return;  			}
	l65: {
		if ((__context->DiagCode == 49156)) {
			goto l70;
		}
		if ((! (__context->DiagCode == 49156))) {
			goto l11;
		}
		//assert(false);
		return;  			}
	l69: {
			goto l11;
		//assert(false);
		return;  			}
	l70: {
		if ((! __context->Reset)) {
			__context->DiagCode = 49154;
			goto l75;
		}
		if ((! (! __context->Reset))) {
			goto l75;
		}
		//assert(false);
		return;  			}
	l75: {
			goto l11;
		//assert(false);
		return;  			}
	l76: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l78: {
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
			goto l76;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l91;
		}
		//assert(false);
		return;  			}
	l91: {
		if ((__context->DiagCode == 32768)) {
			__context->Ready = true;
			__context->S_AnyModeSel = true;
			__context->Error = false;
			goto l76;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l104;
		}
		//assert(false);
		return;  			}
	l104: {
		if ((__context->DiagCode == 32772)) {
			__context->Ready = true;
			__context->S_AnyModeSel = true;
			__context->Error = false;
			goto l76;
		}
		if ((! (__context->DiagCode == 32772))) {
			goto l109;
		}
		//assert(false);
		return;  			}
	l109: {
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
			goto l76;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l114;
		}
		//assert(false);
		return;  			}
	l114: {
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
			goto l76;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l127;
		}
		//assert(false);
		return;  			}
	l127: {
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
			goto l76;
		}
		if ((! (__context->DiagCode == 49155))) {
			goto l140;
		}
		//assert(false);
		return;  			}
	l140: {
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
			goto l76;
		}
		if ((! (__context->DiagCode == 49156))) {
			goto l76;
		}
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void VerificationLoop() {
	// Temporary variables
	
	// Start with initial location
	goto init1;
	init1: {
			goto loop_start;
		//assert(false);
		return;  			}
	end: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	loop_start: {
			instance.Activate = nondet_bool();
			instance.AutoSetMode = nondet_bool();
			instance.DiagCode = nondet_int32_t();
			instance.Error = nondet_bool();
			instance.ModeMonitorTime = nondet_int32_t();
			instance.Ready = nondet_bool();
			instance.Reset = nondet_bool();
			instance.S_Mode0 = nondet_bool();
			instance.S_Mode1 = nondet_bool();
			instance.S_Mode2 = nondet_bool();
			instance.S_Mode3 = nondet_bool();
			instance.S_Mode4 = nondet_bool();
			instance.S_Mode5 = nondet_bool();
			instance.S_Mode6 = nondet_bool();
			instance.S_Mode7 = nondet_bool();
			instance.S_SetMode = nondet_bool();
			instance.S_Unlock = nondet_bool();
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
		assert((!(EoC) || ((! instance.Error) && ((0 <= instance.CYCLE) && (instance.CYCLE <= 20)))));
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
	instance.Activate = false;
	instance.S_Mode0 = false;
	instance.S_Mode1 = false;
	instance.S_Mode2 = false;
	instance.S_Mode3 = false;
	instance.S_Mode4 = false;
	instance.S_Mode5 = false;
	instance.S_Mode6 = false;
	instance.S_Mode7 = false;
	instance.S_Unlock = false;
	instance.S_SetMode = false;
	instance.AutoSetMode = false;
	instance.ModeMonitorTime = 0;
	instance.Reset = false;
	instance.Ready = false;
	instance.S_Mode0Sel = false;
	instance.S_Mode1Sel = false;
	instance.S_Mode2Sel = false;
	instance.S_Mode3Sel = false;
	instance.S_Mode4Sel = false;
	instance.S_Mode5Sel = false;
	instance.S_Mode6Sel = false;
	instance.S_Mode7Sel = false;
	instance.S_AnyModeSel = false;
	instance.Error = false;
	instance.DiagCode = 0;
	instance.Error1 = false;
	instance.Error2 = false;
	instance.CYCLE = 0;
	EoC = false;
	
	VerificationLoop();
}

