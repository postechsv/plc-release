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
	int32_t aaa;
	int32_t bbb;
	int32_t OUT;
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
		if ((__context->aaa == __context->bbb)) {
			goto l10;
		}
		if (((! (__context->aaa == __context->bbb)) && (__context->aaa > __context->bbb))) {
			__context->bbb = (__context->bbb + 1);
			goto l10;
		}
		if ((((! (__context->aaa == __context->bbb)) && (! (__context->aaa > __context->bbb))) && (__context->aaa < __context->bbb))) {
			goto l10;
		}
		if (((! (__context->aaa == __context->bbb)) && ((! ((! (__context->aaa == __context->bbb)) && (__context->aaa > __context->bbb))) && (! (((! (__context->aaa == __context->bbb)) && (! (__context->aaa > __context->bbb))) && (__context->aaa < __context->bbb)))))) {
			goto l10;
		}
		//assert(false);
		return;  			}
	l10: {
			__context->OUT = (__context->aaa - __context->bbb);
			goto l11;
		//assert(false);
		return;  			}
	l11: {
		goto __end_of_automaton;
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
			instance.aaa = 2;
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
		assert((!(EoC) || ((instance.OUT > 0) && ((0 <= instance.CYCLE) && (instance.CYCLE <= 20)))));
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
	instance.aaa = 1;
	instance.bbb = 0;
	instance.OUT = 0;
	instance.CYCLE = 0;
	EoC = false;
	
	VerificationLoop();
}

