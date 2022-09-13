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
	int32_t In;
	int32_t Out;
} __USER_DEC;
typedef struct {
	int32_t In;
	int32_t Out;
} __USER_INC;
typedef struct {
	int32_t A;
	int32_t Counter1;
	__USER_INC INCFUN;
	__USER_DEC DECFUN;
	int32_t CYCLE;
} __Main;

// Global variables
__Main instance;
bool EoC;
bool __cbmc_eoc_marker;

// Automata declarations
void USER_INC(__USER_INC *__context);
void USER_DEC(__USER_DEC *__context);
void Main(__Main *__context);
void VerificationLoop();

// Automata
void USER_INC(__USER_INC *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init;
	init: {
			__context->Out = (__context->In + 1);
			goto l1;
		//assert(false);
		return;  			}
	l1: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void USER_DEC(__USER_DEC *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init1;
	init1: {
			__context->Out = (__context->In - 1);
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
void Main(__Main *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init2;
	init2: {
			__context->CYCLE = (__context->CYCLE + 1);
			goto l12;
		//assert(false);
		return;  			}
	l12: {
			// Assign inputs
			__context->INCFUN.In = __context->Counter1;
			USER_INC(&__context->INCFUN);
			// Assign outputs
			goto l2;
		//assert(false);
		return;  			}
	l2: {
			// Assign inputs
			__context->DECFUN.In = __context->Counter1;
			USER_DEC(&__context->DECFUN);
			// Assign outputs
			goto l3;
		//assert(false);
		return;  			}
	l3: {
			__context->A = (__context->INCFUN.Out - __context->DECFUN.Out);
			goto l4;
		//assert(false);
		return;  			}
	l4: {
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
			instance.Counter1 = nondet_int32_t();
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
		assert((!(EoC) || ((instance.A != 2) && ((0 <= instance.CYCLE) && (instance.CYCLE <= 20)))));
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
	instance.A = 0;
	instance.Counter1 = 5;
	instance.INCFUN.In = 0;
	instance.INCFUN.Out = 0;
	instance.DECFUN.In = 0;
	instance.DECFUN.Out = 0;
	instance.CYCLE = 0;
	EoC = false;
	
	VerificationLoop();
}

