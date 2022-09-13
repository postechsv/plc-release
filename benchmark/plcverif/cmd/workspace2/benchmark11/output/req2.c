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
	int32_t Output;
	int32_t Variable;
} __USER_CONSTANT;
typedef struct {
	int32_t Output;
	__USER_CONSTANT NewVar1;
	bool NewVar;
	int32_t CYCLE;
} __Main;

// Global variables
__Main instance;
bool EoC;
bool __cbmc_eoc_marker;

// Automata declarations
void USER_CONSTANT(__USER_CONSTANT *__context);
void Main(__Main *__context);
void VerificationLoop();

// Automata
void USER_CONSTANT(__USER_CONSTANT *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init;
	init: {
		if (__context->Activate) {
			__context->Output = __context->Variable;
			goto l5;
		}
		if ((! __context->Activate)) {
			__context->Output = 7;
			goto l5;
		}
		//assert(false);
		return;  			}
	l5: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void Main(__Main *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init1;
	init1: {
			__context->CYCLE = (__context->CYCLE + 1);
			goto l1;
		//assert(false);
		return;  			}
	l1: {
			// Assign inputs
			__context->NewVar1.Activate = __context->NewVar;
			USER_CONSTANT(&__context->NewVar1);
			// Assign outputs
			goto l2;
		//assert(false);
		return;  			}
	l2: {
			__context->Output = __context->NewVar1.Output;
			goto l3;
		//assert(false);
		return;  			}
	l3: {
			// Assign inputs
			__context->NewVar1.Activate = __context->NewVar;
			USER_CONSTANT(&__context->NewVar1);
			// Assign outputs
			goto l4;
		//assert(false);
		return;  			}
	l4: {
			__context->Output = __context->NewVar1.Output;
			goto l51;
		//assert(false);
		return;  			}
	l51: {
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
			instance.NewVar = nondet_bool();
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
		assert((!(EoC) || ((instance.Output == 7) && ((0 <= instance.CYCLE) && (instance.CYCLE <= 20)))));
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
	instance.Output = 0;
	instance.NewVar1.Activate = false;
	instance.NewVar1.Output = 0;
	instance.NewVar1.Variable = 10;
	instance.NewVar = true;
	instance.CYCLE = 0;
	EoC = false;
	
	VerificationLoop();
}

