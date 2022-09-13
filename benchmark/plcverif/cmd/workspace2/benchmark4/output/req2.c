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
	int32_t MN;
	int32_t IN;
	int32_t MX;
	int32_t RET_VAL;
} __LIMIT;
typedef struct {
	bool PUSH;
	bool POP;
	bool R1;
	int32_t IN;
	int32_t N;
	bool EMPTY;
	bool OFLO;
	int32_t OUT;
	int32_t SIZE;
	int32_t STK[10];
	int32_t NI;
	int32_t PTR;
} __STACK_DINT;
typedef struct {
	int32_t I1;
	int32_t I2;
	int32_t I3;
	int32_t I4;
	bool B1;
	bool B2;
	bool B3;
	__STACK_DINT STACK_INT_FB;
	int32_t STACKOUT;
	bool STACKEMPTY;
	bool STACKFULL;
	int32_t STACKSIZE;
	int32_t CYCLE;
} __Main;

// Global variables
__LIMIT LIMIT1;
__Main instance;
bool EoC;
bool __cbmc_eoc_marker;

// Automata declarations
void LIMIT(__LIMIT *__context);
void STACK_DINT(__STACK_DINT *__context);
void Main(__Main *__context);
void VerificationLoop();

// Automata
void LIMIT(__LIMIT *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init;
	init: {
		if ((__context->IN < __context->MN)) {
			__context->RET_VAL = __context->MN;
			goto l7;
		}
		if (((! (__context->IN < __context->MN)) && (__context->IN > __context->MX))) {
			__context->RET_VAL = __context->MX;
			goto l7;
		}
		if (((! (__context->IN < __context->MN)) && (! ((! (__context->IN < __context->MN)) && (__context->IN > __context->MX))))) {
			__context->RET_VAL = __context->MN;
			goto l7;
		}
		//assert(false);
		return;  			}
	l7: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void STACK_DINT(__STACK_DINT *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init1;
	init1: {
		if (__context->R1) {
			__context->OFLO = false;
			__context->EMPTY = true;
			__context->PTR = (- 1);
			goto l4;
		}
		if (((! __context->R1) && (__context->POP && (! __context->EMPTY)))) {
			__context->OFLO = false;
			__context->PTR = (__context->PTR - 1);
			goto l9;
		}
		if ((((! __context->R1) && (! (__context->POP && (! __context->EMPTY)))) && (__context->PUSH && (! __context->OFLO)))) {
			__context->EMPTY = false;
			__context->PTR = (__context->PTR + 1);
			goto l48;
		}
		if (((! __context->R1) && ((! ((! __context->R1) && (__context->POP && (! __context->EMPTY)))) && (! (((! __context->R1) && (! (__context->POP && (! __context->EMPTY)))) && (__context->PUSH && (! __context->OFLO))))))) {
			goto l87;
		}
		//assert(false);
		return;  			}
	l4: {
			// Assign inputs
			LIMIT1.MN = 1;
			LIMIT1.IN = __context->N;
			LIMIT1.MX = 128;
			LIMIT(&LIMIT1);
			// Assign outputs
			__context->NI = LIMIT1.RET_VAL;
			goto l5;
		//assert(false);
		return;  			}
	l5: {
			__context->OUT = 0;
			goto l87;
		//assert(false);
		return;  			}
	l9: {
			__context->EMPTY = (__context->PTR < 0);
			goto l10;
		//assert(false);
		return;  			}
	l10: {
		if (__context->EMPTY) {
			__context->OUT = 0;
			goto l45;
		}
		if ((! __context->EMPTY)) {
			goto l13;
		}
		//assert(false);
		return;  			}
	l13: {
		if ((__context->PTR == 0)) {
			__context->OUT = __context->STK[0];
			goto l14;
		}
		if ((! (__context->PTR == 0))) {
			goto l16;
		}
		//assert(false);
		return;  			}
	l14: {
			goto l45;
		//assert(false);
		return;  			}
	l16: {
		if ((__context->PTR == 1)) {
			__context->OUT = __context->STK[1];
			goto l14;
		}
		if ((! (__context->PTR == 1))) {
			goto l19;
		}
		//assert(false);
		return;  			}
	l19: {
		if ((__context->PTR == 2)) {
			__context->OUT = __context->STK[2];
			goto l14;
		}
		if ((! (__context->PTR == 2))) {
			goto l22;
		}
		//assert(false);
		return;  			}
	l22: {
		if ((__context->PTR == 3)) {
			__context->OUT = __context->STK[3];
			goto l14;
		}
		if ((! (__context->PTR == 3))) {
			goto l25;
		}
		//assert(false);
		return;  			}
	l25: {
		if ((__context->PTR == 4)) {
			__context->OUT = __context->STK[4];
			goto l14;
		}
		if ((! (__context->PTR == 4))) {
			goto l28;
		}
		//assert(false);
		return;  			}
	l28: {
		if ((__context->PTR == 5)) {
			__context->OUT = __context->STK[5];
			goto l14;
		}
		if ((! (__context->PTR == 5))) {
			goto l31;
		}
		//assert(false);
		return;  			}
	l31: {
		if ((__context->PTR == 6)) {
			__context->OUT = __context->STK[6];
			goto l14;
		}
		if ((! (__context->PTR == 6))) {
			goto l34;
		}
		//assert(false);
		return;  			}
	l34: {
		if ((__context->PTR == 7)) {
			__context->OUT = __context->STK[7];
			goto l14;
		}
		if ((! (__context->PTR == 7))) {
			goto l37;
		}
		//assert(false);
		return;  			}
	l37: {
		if ((__context->PTR == 8)) {
			__context->OUT = __context->STK[8];
			goto l14;
		}
		if ((! (__context->PTR == 8))) {
			goto l40;
		}
		//assert(false);
		return;  			}
	l40: {
		if ((__context->PTR == 9)) {
			__context->OUT = __context->STK[9];
			goto l14;
		}
		if ((! (__context->PTR == 9))) {
			goto l14;
		}
		//assert(false);
		return;  			}
	l45: {
			goto l87;
		//assert(false);
		return;  			}
	l48: {
			__context->OFLO = (__context->PTR == __context->NI);
			goto l49;
		//assert(false);
		return;  			}
	l49: {
		if ((! __context->OFLO)) {
			__context->OUT = __context->IN;
			goto l51;
		}
		if ((! (! __context->OFLO))) {
			__context->OUT = 0;
			goto l85;
		}
		//assert(false);
		return;  			}
	l51: {
		if ((__context->PTR == 0)) {
			__context->STK[0] = __context->IN;
			goto l52;
		}
		if ((! (__context->PTR == 0))) {
			goto l54;
		}
		//assert(false);
		return;  			}
	l52: {
			goto l85;
		//assert(false);
		return;  			}
	l54: {
		if ((__context->PTR == 1)) {
			__context->STK[1] = __context->IN;
			goto l52;
		}
		if ((! (__context->PTR == 1))) {
			goto l57;
		}
		//assert(false);
		return;  			}
	l57: {
		if ((__context->PTR == 2)) {
			__context->STK[2] = __context->IN;
			goto l52;
		}
		if ((! (__context->PTR == 2))) {
			goto l60;
		}
		//assert(false);
		return;  			}
	l60: {
		if ((__context->PTR == 3)) {
			__context->STK[3] = __context->IN;
			goto l52;
		}
		if ((! (__context->PTR == 3))) {
			goto l63;
		}
		//assert(false);
		return;  			}
	l63: {
		if ((__context->PTR == 4)) {
			__context->STK[4] = __context->IN;
			goto l52;
		}
		if ((! (__context->PTR == 4))) {
			goto l66;
		}
		//assert(false);
		return;  			}
	l66: {
		if ((__context->PTR == 5)) {
			__context->STK[5] = __context->IN;
			goto l52;
		}
		if ((! (__context->PTR == 5))) {
			goto l69;
		}
		//assert(false);
		return;  			}
	l69: {
		if ((__context->PTR == 6)) {
			__context->STK[6] = __context->IN;
			goto l52;
		}
		if ((! (__context->PTR == 6))) {
			goto l72;
		}
		//assert(false);
		return;  			}
	l72: {
		if ((__context->PTR == 7)) {
			__context->STK[7] = __context->IN;
			goto l52;
		}
		if ((! (__context->PTR == 7))) {
			goto l75;
		}
		//assert(false);
		return;  			}
	l75: {
		if ((__context->PTR == 8)) {
			__context->STK[8] = __context->IN;
			goto l52;
		}
		if ((! (__context->PTR == 8))) {
			goto l78;
		}
		//assert(false);
		return;  			}
	l78: {
		if ((__context->PTR == 9)) {
			__context->STK[9] = __context->IN;
			goto l52;
		}
		if ((! (__context->PTR == 9))) {
			goto l52;
		}
		//assert(false);
		return;  			}
	l85: {
			goto l87;
		//assert(false);
		return;  			}
	l87: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void Main(__Main *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init2;
	init2: {
			__context->CYCLE = (__context->CYCLE + 1);
			goto l1;
		//assert(false);
		return;  			}
	l1: {
			// Assign inputs
			__context->STACK_INT_FB.PUSH = __context->B1;
			__context->STACK_INT_FB.POP = __context->B2;
			__context->STACK_INT_FB.R1 = __context->B3;
			__context->STACK_INT_FB.IN = __context->I1;
			__context->STACK_INT_FB.N = __context->I2;
			STACK_DINT(&__context->STACK_INT_FB);
			// Assign outputs
			goto l2;
		//assert(false);
		return;  			}
	l2: {
			__context->STACKOUT = __context->STACK_INT_FB.OUT;
			__context->STACKEMPTY = __context->STACK_INT_FB.EMPTY;
			__context->STACKFULL = __context->STACK_INT_FB.OFLO;
			__context->STACKSIZE = __context->STACK_INT_FB.SIZE;
			goto l6;
		//assert(false);
		return;  			}
	l6: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void VerificationLoop() {
	// Temporary variables
	
	// Start with initial location
	goto init3;
	init3: {
			goto loop_start;
		//assert(false);
		return;  			}
	end: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	loop_start: {
			instance.B1 = nondet_bool();
			instance.B2 = nondet_bool();
			instance.B3 = nondet_bool();
			instance.I1 = nondet_int32_t();
			instance.I2 = nondet_int32_t();
			instance.I3 = nondet_int32_t();
			instance.I4 = nondet_int32_t();
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
		assert((!(EoC) || ((! (instance.STACKEMPTY && instance.STACKFULL)) && ((0 <= instance.CYCLE) && (instance.CYCLE <= 20)))));
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
	LIMIT1.MN = 0;
	LIMIT1.IN = 0;
	LIMIT1.MX = 0;
	LIMIT1.RET_VAL = 0;
	instance.I1 = 0;
	instance.I2 = 0;
	instance.I3 = 0;
	instance.I4 = 0;
	instance.B1 = false;
	instance.B2 = false;
	instance.B3 = false;
	instance.STACK_INT_FB.PUSH = false;
	instance.STACK_INT_FB.POP = false;
	instance.STACK_INT_FB.R1 = false;
	instance.STACK_INT_FB.IN = 0;
	instance.STACK_INT_FB.N = 0;
	instance.STACK_INT_FB.EMPTY = true;
	instance.STACK_INT_FB.OFLO = false;
	instance.STACK_INT_FB.OUT = 0;
	instance.STACK_INT_FB.SIZE = 0;
	instance.STACK_INT_FB.STK[0] = 0;
	instance.STACK_INT_FB.STK[1] = 0;
	instance.STACK_INT_FB.STK[2] = 0;
	instance.STACK_INT_FB.STK[3] = 0;
	instance.STACK_INT_FB.STK[4] = 0;
	instance.STACK_INT_FB.STK[5] = 0;
	instance.STACK_INT_FB.STK[6] = 0;
	instance.STACK_INT_FB.STK[7] = 0;
	instance.STACK_INT_FB.STK[8] = 0;
	instance.STACK_INT_FB.STK[9] = 0;
	instance.STACK_INT_FB.NI = 10;
	instance.STACK_INT_FB.PTR = -1;
	instance.STACKOUT = 0;
	instance.STACKEMPTY = false;
	instance.STACKFULL = false;
	instance.STACKSIZE = 0;
	instance.CYCLE = 0;
	EoC = false;
	
	VerificationLoop();
}

