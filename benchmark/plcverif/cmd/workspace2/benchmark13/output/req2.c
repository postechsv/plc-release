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
	bool S_ChannelNC;
	bool S_ChannelNO;
	bool Ready;
	bool S_AntivalentOut;
	bool Error;
	int32_t DiagCode;
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
			goto l76;
		}
		if ((! (! __context->Activate))) {
			goto l4;
		}
		//assert(false);
		return;  			}
	l4: {
		if ((__context->DiagCode == 0)) {
			goto l6;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l7;
		}
		//assert(false);
		return;  			}
	l5: {
			goto l76;
		//assert(false);
		return;  			}
	l6: {
		if (__context->Activate) {
			__context->DiagCode = 32769;
			goto l11;
		}
		if ((! __context->Activate)) {
			goto l11;
		}
		//assert(false);
		return;  			}
	l7: {
		if ((__context->DiagCode == 32769)) {
			goto l12;
		}
		if ((! (__context->DiagCode == 32769))) {
			goto l13;
		}
		//assert(false);
		return;  			}
	l11: {
			goto l5;
		//assert(false);
		return;  			}
	l12: {
		if ((__context->S_ChannelNC && __context->S_ChannelNO)) {
			__context->DiagCode = 32772;
			goto l21;
		}
		if (((! (__context->S_ChannelNC && __context->S_ChannelNO)) && ((! __context->S_ChannelNC) && (! __context->S_ChannelNO)))) {
			__context->DiagCode = 32788;
			goto l21;
		}
		if ((((! (__context->S_ChannelNC && __context->S_ChannelNO)) && (! ((! __context->S_ChannelNC) && (! __context->S_ChannelNO)))) && (__context->S_ChannelNC && (! __context->S_ChannelNO)))) {
			__context->DiagCode = 32768;
			goto l21;
		}
		if (((! (__context->S_ChannelNC && __context->S_ChannelNO)) && ((! ((! (__context->S_ChannelNC && __context->S_ChannelNO)) && ((! __context->S_ChannelNC) && (! __context->S_ChannelNO)))) && (! (((! (__context->S_ChannelNC && __context->S_ChannelNO)) && (! ((! __context->S_ChannelNC) && (! __context->S_ChannelNO)))) && (__context->S_ChannelNC && (! __context->S_ChannelNO))))))) {
			goto l21;
		}
		//assert(false);
		return;  			}
	l13: {
		if ((__context->DiagCode == 32772)) {
			goto l22;
		}
		if ((! (__context->DiagCode == 32772))) {
			goto l23;
		}
		//assert(false);
		return;  			}
	l21: {
			goto l5;
		//assert(false);
		return;  			}
	l22: {
		if (__context->Activate) {
			__context->DiagCode = 49153;
			goto l31;
		}
		if (((! __context->Activate) && (! __context->S_ChannelNC))) {
			__context->DiagCode = 32769;
			goto l31;
		}
		if ((((! __context->Activate) && (! (! __context->S_ChannelNC))) && (! __context->S_ChannelNO))) {
			__context->DiagCode = 32768;
			goto l31;
		}
		if (((! __context->Activate) && ((! ((! __context->Activate) && (! __context->S_ChannelNC))) && (! (((! __context->Activate) && (! (! __context->S_ChannelNC))) && (! __context->S_ChannelNO)))))) {
			goto l31;
		}
		//assert(false);
		return;  			}
	l23: {
		if ((__context->DiagCode == 49153)) {
			goto l32;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l33;
		}
		//assert(false);
		return;  			}
	l31: {
			goto l5;
		//assert(false);
		return;  			}
	l32: {
		if (((! __context->S_ChannelNC) && __context->S_ChannelNO)) {
			__context->DiagCode = 32769;
			goto l37;
		}
		if ((! ((! __context->S_ChannelNC) && __context->S_ChannelNO))) {
			goto l37;
		}
		//assert(false);
		return;  			}
	l33: {
		if ((__context->DiagCode == 49154)) {
			goto l38;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l39;
		}
		//assert(false);
		return;  			}
	l37: {
			goto l5;
		//assert(false);
		return;  			}
	l38: {
		if (((! __context->S_ChannelNC) && __context->S_ChannelNO)) {
			__context->DiagCode = 32769;
			goto l43;
		}
		if ((! ((! __context->S_ChannelNC) && __context->S_ChannelNO))) {
			goto l43;
		}
		//assert(false);
		return;  			}
	l39: {
		if ((__context->DiagCode == 32788)) {
			goto l44;
		}
		if ((! (__context->DiagCode == 32788))) {
			goto l45;
		}
		//assert(false);
		return;  			}
	l43: {
			goto l5;
		//assert(false);
		return;  			}
	l44: {
		if (__context->Activate) {
			__context->DiagCode = 49154;
			goto l53;
		}
		if (((! __context->Activate) && __context->S_ChannelNO)) {
			__context->DiagCode = 32769;
			goto l53;
		}
		if ((((! __context->Activate) && (! __context->S_ChannelNO)) && __context->S_ChannelNC)) {
			__context->DiagCode = 32768;
			goto l53;
		}
		if (((! __context->Activate) && ((! ((! __context->Activate) && __context->S_ChannelNO)) && (! (((! __context->Activate) && (! __context->S_ChannelNO)) && __context->S_ChannelNC))))) {
			goto l53;
		}
		//assert(false);
		return;  			}
	l45: {
		if ((__context->DiagCode == 49155)) {
			goto l54;
		}
		if ((! (__context->DiagCode == 49155))) {
			goto l55;
		}
		//assert(false);
		return;  			}
	l53: {
			goto l5;
		//assert(false);
		return;  			}
	l54: {
		if (((! __context->S_ChannelNC) && __context->S_ChannelNO)) {
			__context->DiagCode = 32769;
			goto l59;
		}
		if ((! ((! __context->S_ChannelNC) && __context->S_ChannelNO))) {
			goto l59;
		}
		//assert(false);
		return;  			}
	l55: {
		if ((__context->DiagCode == 32773)) {
			goto l60;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l61;
		}
		//assert(false);
		return;  			}
	l59: {
			goto l5;
		//assert(false);
		return;  			}
	l60: {
		if (__context->Activate) {
			__context->DiagCode = 49155;
			goto l67;
		}
		if (((! __context->Activate) && ((! __context->S_ChannelNC) && __context->S_ChannelNO))) {
			__context->DiagCode = 32773;
			goto l67;
		}
		if (((! __context->Activate) && (! ((! __context->Activate) && ((! __context->S_ChannelNC) && __context->S_ChannelNO))))) {
			goto l67;
		}
		//assert(false);
		return;  			}
	l61: {
		if ((__context->DiagCode == 32768)) {
			goto l68;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l5;
		}
		//assert(false);
		return;  			}
	l67: {
			goto l5;
		//assert(false);
		return;  			}
	l68: {
		if (((! __context->S_ChannelNC) || __context->S_ChannelNO)) {
			__context->DiagCode = 32773;
			goto l75;
		}
		if (((! ((! __context->S_ChannelNC) || __context->S_ChannelNO)) && ((! __context->S_ChannelNC) && __context->S_ChannelNO))) {
			__context->DiagCode = 32769;
			goto l75;
		}
		if (((! ((! __context->S_ChannelNC) || __context->S_ChannelNO)) && (! ((! ((! __context->S_ChannelNC) || __context->S_ChannelNO)) && ((! __context->S_ChannelNC) && __context->S_ChannelNO))))) {
			goto l75;
		}
		//assert(false);
		return;  			}
	l75: {
			goto l5;
		//assert(false);
		return;  			}
	l76: {
		if ((__context->DiagCode == 0)) {
			__context->Ready = false;
			__context->Error = false;
			__context->S_AntivalentOut = false;
			goto l77;
		}
		if ((! (__context->DiagCode == 0))) {
			goto l79;
		}
		//assert(false);
		return;  			}
	l77: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l79: {
		if ((__context->DiagCode == 32768)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_AntivalentOut = true;
			goto l77;
		}
		if ((! (__context->DiagCode == 32768))) {
			goto l84;
		}
		//assert(false);
		return;  			}
	l84: {
		if ((__context->DiagCode == 32769)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_AntivalentOut = false;
			goto l77;
		}
		if ((! (__context->DiagCode == 32769))) {
			goto l89;
		}
		//assert(false);
		return;  			}
	l89: {
		if ((__context->DiagCode == 32772)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_AntivalentOut = false;
			goto l77;
		}
		if ((! (__context->DiagCode == 32772))) {
			goto l94;
		}
		//assert(false);
		return;  			}
	l94: {
		if ((__context->DiagCode == 32788)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_AntivalentOut = false;
			goto l77;
		}
		if ((! (__context->DiagCode == 32788))) {
			goto l99;
		}
		//assert(false);
		return;  			}
	l99: {
		if ((__context->DiagCode == 32773)) {
			__context->Ready = true;
			__context->Error = false;
			__context->S_AntivalentOut = false;
			goto l77;
		}
		if ((! (__context->DiagCode == 32773))) {
			goto l104;
		}
		//assert(false);
		return;  			}
	l104: {
		if ((__context->DiagCode == 49153)) {
			__context->Ready = true;
			__context->Error = true;
			__context->S_AntivalentOut = false;
			goto l77;
		}
		if ((! (__context->DiagCode == 49153))) {
			goto l109;
		}
		//assert(false);
		return;  			}
	l109: {
		if ((__context->DiagCode == 49154)) {
			__context->Ready = true;
			__context->Error = true;
			__context->S_AntivalentOut = false;
			goto l77;
		}
		if ((! (__context->DiagCode == 49154))) {
			goto l114;
		}
		//assert(false);
		return;  			}
	l114: {
		if ((__context->DiagCode == 49155)) {
			__context->Ready = true;
			__context->Error = true;
			__context->S_AntivalentOut = false;
			goto l77;
		}
		if ((! (__context->DiagCode == 49155))) {
			goto l77;
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
			instance.S_ChannelNC = nondet_bool();
			instance.S_ChannelNO = nondet_bool();
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
		assert((!(EoC) || ((instance.DiagCode != 32773) && ((0 <= instance.CYCLE) && (instance.CYCLE <= 20)))));
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
	instance.S_ChannelNC = false;
	instance.S_ChannelNO = false;
	instance.Ready = false;
	instance.S_AntivalentOut = false;
	instance.Error = false;
	instance.DiagCode = 0;
	instance.CYCLE = 0;
	EoC = false;
	
	VerificationLoop();
}

