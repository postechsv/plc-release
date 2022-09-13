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
	int32_t PERIOD;
	bool PASSED;
	bool FIRST;
	int32_t INIT;
} __WAIT_TIME;
typedef struct {
	int32_t CYCLE;
	__WAIT_TIME WAITTIME;
} __Main1;
typedef struct {
	int32_t CYCLE;
	__WAIT_TIME WAITTIME;
} __Main2;
typedef struct {
	int32_t CYCLE;
	__WAIT_TIME WAITTIME;
	int32_t MOUT;
} __Main3;
typedef struct {
	__Main1 M1;
	__Main2 M2;
	__Main3 M3;
} __Main;

// Global variables
int32_t GLOBAL_TIME;
int32_t OUT;
int32_t CYCLE_TIME;
__Main instance;
bool EoC;
bool __cbmc_eoc_marker;

// Automata declarations
void WAIT_TIME(__WAIT_TIME *__context);
void Main1(__Main1 *__context);
void Main2(__Main2 *__context);
void Main3(__Main3 *__context);
void Main(__Main *__context);
void VerificationLoop();

// Automata
void WAIT_TIME(__WAIT_TIME *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init;
	init: {
		if (__context->FIRST) {
			__context->FIRST = false;
			__context->INIT = GLOBAL_TIME;
			__context->PASSED = false;
			goto l12;
		}
		if ((! __context->FIRST)) {
			goto l5;
		}
		//assert(false);
		return;  			}
	l5: {
		if (((GLOBAL_TIME - __context->INIT) >= __context->PERIOD)) {
			__context->PASSED = true;
			__context->FIRST = true;
			goto l11;
		}
		if ((! ((GLOBAL_TIME - __context->INIT) >= __context->PERIOD))) {
			__context->PASSED = false;
			goto l11;
		}
		//assert(false);
		return;  			}
	l11: {
			goto l12;
		//assert(false);
		return;  			}
	l12: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void Main1(__Main1 *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init1;
	init1: {
		if (__context->WAITTIME.PASSED) {
			__context->CYCLE = (__context->CYCLE + 1);
			OUT = (OUT + 2);
			goto l51;
		}
		if ((! __context->WAITTIME.PASSED)) {
			goto l51;
		}
		//assert(false);
		return;  			}
	l51: {
			// Assign inputs
			__context->WAITTIME.PERIOD = 4000;
			WAIT_TIME(&__context->WAITTIME);
			// Assign outputs
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
void Main2(__Main2 *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init2;
	init2: {
		if (__context->WAITTIME.PASSED) {
			__context->CYCLE = (__context->CYCLE + 1);
			OUT = (OUT - 1);
			goto l52;
		}
		if ((! __context->WAITTIME.PASSED)) {
			goto l52;
		}
		//assert(false);
		return;  			}
	l52: {
			// Assign inputs
			__context->WAITTIME.PERIOD = 2000;
			WAIT_TIME(&__context->WAITTIME);
			// Assign outputs
			goto l61;
		//assert(false);
		return;  			}
	l61: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void Main3(__Main3 *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init3;
	init3: {
		if (__context->WAITTIME.PASSED) {
			__context->CYCLE = (__context->CYCLE + 1);
			OUT = (OUT + 3);
			goto l3;
		}
		if ((! __context->WAITTIME.PASSED)) {
			goto l62;
		}
		//assert(false);
		return;  			}
	l3: {
			__context->MOUT = OUT;
			goto l62;
		//assert(false);
		return;  			}
	l62: {
			// Assign inputs
			__context->WAITTIME.PERIOD = 1000;
			WAIT_TIME(&__context->WAITTIME);
			// Assign outputs
			goto l7;
		//assert(false);
		return;  			}
	l7: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void Main(__Main *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init4;
	init4: {
			GLOBAL_TIME = (GLOBAL_TIME + CYCLE_TIME);
			goto l1;
		//assert(false);
		return;  			}
	l1: {
			// Assign inputs
			Main1(&__context->M1);
			// Assign outputs
			goto l2;
		//assert(false);
		return;  			}
	l2: {
			// Assign inputs
			Main2(&__context->M2);
			// Assign outputs
			goto l31;
		//assert(false);
		return;  			}
	l31: {
			// Assign inputs
			Main3(&__context->M3);
			// Assign outputs
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
	goto init5;
	init5: {
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
		assert((!(EoC) || (((instance.M3.CYCLE >= instance.M2.CYCLE) && (instance.M2.CYCLE >= instance.M1.CYCLE)) && ((0 <= instance.M3.CYCLE) && (instance.M3.CYCLE <= 20)))));
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
	GLOBAL_TIME = 0;
	OUT = 0;
	CYCLE_TIME = 1000;
	instance.M1.CYCLE = 0;
	instance.M1.WAITTIME.PERIOD = 0;
	instance.M1.WAITTIME.PASSED = true;
	instance.M1.WAITTIME.FIRST = true;
	instance.M1.WAITTIME.INIT = 0;
	instance.M2.CYCLE = 0;
	instance.M2.WAITTIME.PERIOD = 0;
	instance.M2.WAITTIME.PASSED = true;
	instance.M2.WAITTIME.FIRST = true;
	instance.M2.WAITTIME.INIT = 0;
	instance.M3.CYCLE = 0;
	instance.M3.WAITTIME.PERIOD = 0;
	instance.M3.WAITTIME.PASSED = true;
	instance.M3.WAITTIME.FIRST = true;
	instance.M3.WAITTIME.INIT = 0;
	instance.M3.MOUT = 0;
	EoC = false;
	
	VerificationLoop();
}

