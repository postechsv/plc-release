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
	int32_t N;
	int32_t O;
	int32_t F1;
	int32_t F2;
	int32_t CNT;
} __fibonacci;
typedef struct {
	__fibonacci FIB;
	int32_t OUT1;
	int32_t INDEX;
	int32_t OUT2;
	int32_t OUT3;
	int32_t CYCLE;
} __Main;

// Global variables
__Main instance;
bool EoC;
bool __cbmc_eoc_marker;

// Automata declarations
void Main(__Main *__context);
void fibonacci(__fibonacci *__context);
void VerificationLoop();

// Automata
void Main(__Main *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init;
	init: {
			__context->CYCLE = (__context->CYCLE + 1);
			__context->INDEX = (__context->INDEX + 1);
			goto l2;
		//assert(false);
		return;  			}
	l2: {
			// Assign inputs
			__context->FIB.N = __context->INDEX;
			fibonacci(&__context->FIB);
			// Assign outputs
			goto l3;
		//assert(false);
		return;  			}
	l3: {
			__context->OUT3 = __context->FIB.O;
			goto l4;
		//assert(false);
		return;  			}
	l4: {
			// Assign inputs
			__context->FIB.N = (__context->INDEX - 1);
			fibonacci(&__context->FIB);
			// Assign outputs
			goto l5;
		//assert(false);
		return;  			}
	l5: {
			__context->OUT1 = __context->FIB.O;
			goto l6;
		//assert(false);
		return;  			}
	l6: {
			// Assign inputs
			__context->FIB.N = (__context->INDEX - 2);
			fibonacci(&__context->FIB);
			// Assign outputs
			goto l7;
		//assert(false);
		return;  			}
	l7: {
			__context->OUT2 = __context->FIB.O;
			goto l8;
		//assert(false);
		return;  			}
	l8: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void fibonacci(__fibonacci *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init1;
	init1: {
			__context->F1 = 1;
			__context->F2 = 1;
			__context->CNT = 2;
			goto l31;
		//assert(false);
		return;  			}
	l31: {
		if ((__context->N <= __context->CNT)) {
			__context->O = 1;
			goto l13;
		}
		if ((! (__context->N <= __context->CNT))) {
			goto l61;
		}
		//assert(false);
		return;  			}
	l61: {
		if ((__context->CNT < __context->N)) {
			__context->O = (__context->F1 + __context->F2);
			goto l81;
		}
		if ((! (__context->CNT < __context->N))) {
			goto l13;
		}
		//assert(false);
		return;  			}
	l81: {
			__context->F1 = __context->F2;
			goto l9;
		//assert(false);
		return;  			}
	l9: {
			__context->F2 = __context->O;
			__context->CNT = (__context->CNT + 1);
			goto l61;
		//assert(false);
		return;  			}
	l13: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void VerificationLoop() {
	// Temporary variables
	
	// Start with initial location
	goto init2;
	init2: {
			goto loop_start;
		//assert(false);
		return;  			}
	end: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	loop_start: {
			instance.INDEX = nondet_int32_t();
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
		assert((!(EoC) || (((instance.OUT1 < instance.OUT3) && (instance.OUT2 < instance.OUT3)) && ((0 <= instance.CYCLE) && (instance.CYCLE <= 20)))));
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
	instance.FIB.N = 0;
	instance.FIB.O = 0;
	instance.FIB.F1 = 0;
	instance.FIB.F2 = 0;
	instance.FIB.CNT = 0;
	instance.OUT1 = 0;
	instance.INDEX = 0;
	instance.OUT2 = 0;
	instance.OUT3 = 0;
	instance.CYCLE = 0;
	EoC = false;
	
	VerificationLoop();
}

