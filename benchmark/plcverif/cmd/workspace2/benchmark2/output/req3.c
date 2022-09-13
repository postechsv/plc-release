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
	int32_t in1;
	int32_t in2;
	int32_t OUT;
} __USER_MAX;
typedef struct {
	int32_t in1;
	int32_t in2;
	int32_t OUT;
} __USER_MIN;
typedef struct {
	int32_t input1;
	int32_t input2;
	int32_t input3;
	int32_t input4;
	int32_t input5;
	int32_t M;
	int32_t N;
	int32_t CYCLE;
	__USER_MAX INSTANCE_MAX;
	__USER_MIN INSTANCE_MIN;
	__USER_MAX TEMP_MAX;
	int32_t TEMP_MAX_OUT;
	__USER_MIN TEMP_MIN_2;
	int32_t TEMP_MIN_2_OUT;
	__USER_MIN TEMP_MIN_3;
	int32_t TEMP_MIN_3_OUT;
} __Main;

// Global variables
__Main instance;
bool EoC;
bool __cbmc_eoc_marker;

// Automata declarations
void Main(__Main *__context);
void USER_MAX(__USER_MAX *__context);
void USER_MIN(__USER_MIN *__context);
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
			__context->TEMP_MAX.in1 = __context->input2;
			__context->TEMP_MAX.in2 = __context->input3;
			USER_MAX(&__context->TEMP_MAX);
			// Assign outputs
			goto l2;
		//assert(false);
		return;  			}
	l2: {
			__context->TEMP_MAX_OUT = __context->TEMP_MAX.OUT;
			goto l3;
		//assert(false);
		return;  			}
	l3: {
			// Assign inputs
			__context->INSTANCE_MAX.in1 = __context->input1;
			__context->INSTANCE_MAX.in2 = __context->TEMP_MAX_OUT;
			USER_MAX(&__context->INSTANCE_MAX);
			// Assign outputs
			goto l4;
		//assert(false);
		return;  			}
	l4: {
			__context->M = __context->INSTANCE_MAX.OUT;
			goto l5;
		//assert(false);
		return;  			}
	l5: {
			// Assign inputs
			__context->TEMP_MIN_2.in1 = __context->input4;
			__context->TEMP_MIN_2.in2 = __context->input5;
			USER_MIN(&__context->TEMP_MIN_2);
			// Assign outputs
			goto l6;
		//assert(false);
		return;  			}
	l6: {
			__context->TEMP_MIN_2_OUT = __context->TEMP_MIN_2.OUT;
			goto l7;
		//assert(false);
		return;  			}
	l7: {
			// Assign inputs
			__context->TEMP_MIN_3.in1 = __context->input2;
			__context->TEMP_MIN_3.in2 = ((__context->input3 * __context->TEMP_MIN_2_OUT) + __context->input2);
			USER_MIN(&__context->TEMP_MIN_3);
			// Assign outputs
			goto l8;
		//assert(false);
		return;  			}
	l8: {
			__context->TEMP_MIN_3_OUT = __context->TEMP_MIN_3.OUT;
			goto l9;
		//assert(false);
		return;  			}
	l9: {
			// Assign inputs
			__context->INSTANCE_MIN.in1 = __context->input1;
			__context->INSTANCE_MIN.in2 = (__context->TEMP_MIN_3_OUT + __context->input3);
			USER_MIN(&__context->INSTANCE_MIN);
			// Assign outputs
			goto l10;
		//assert(false);
		return;  			}
	l10: {
			__context->N = __context->INSTANCE_MIN.OUT;
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
void USER_MAX(__USER_MAX *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init1;
	init1: {
		if ((__context->in1 > __context->in2)) {
			__context->OUT = __context->in1;
			goto l51;
		}
		if ((! (__context->in1 > __context->in2))) {
			__context->OUT = __context->in2;
			goto l51;
		}
		//assert(false);
		return;  			}
	l51: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void USER_MIN(__USER_MIN *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init2;
	init2: {
		if ((__context->in1 < __context->in2)) {
			__context->OUT = __context->in1;
			goto l52;
		}
		if ((! (__context->in1 < __context->in2))) {
			__context->OUT = __context->in2;
			goto l52;
		}
		//assert(false);
		return;  			}
	l52: {
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
		assert((!(EoC) || ((instance.M == instance.N) && ((0 <= instance.CYCLE) && (instance.CYCLE <= 20)))));
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
	instance.input1 = 0;
	instance.input2 = 0;
	instance.input3 = 0;
	instance.input4 = 0;
	instance.input5 = 0;
	instance.M = 0;
	instance.N = 0;
	instance.CYCLE = 0;
	instance.INSTANCE_MAX.in1 = 0;
	instance.INSTANCE_MAX.in2 = 0;
	instance.INSTANCE_MAX.OUT = 0;
	instance.INSTANCE_MIN.in1 = 0;
	instance.INSTANCE_MIN.in2 = 0;
	instance.INSTANCE_MIN.OUT = 0;
	instance.TEMP_MAX.in1 = 0;
	instance.TEMP_MAX.in2 = 0;
	instance.TEMP_MAX.OUT = 0;
	instance.TEMP_MAX_OUT = 0;
	instance.TEMP_MIN_2.in1 = 0;
	instance.TEMP_MIN_2.in2 = 0;
	instance.TEMP_MIN_2.OUT = 0;
	instance.TEMP_MIN_2_OUT = 0;
	instance.TEMP_MIN_3.in1 = 0;
	instance.TEMP_MIN_3.in2 = 0;
	instance.TEMP_MIN_3.OUT = 0;
	instance.TEMP_MIN_3_OUT = 0;
	EoC = false;
	
	VerificationLoop();
}

