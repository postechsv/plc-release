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
	int32_t x;
	int32_t y;
	int32_t tank;
	bool collision;
	bool sinking;
} __ALERT;
typedef struct {
	int32_t x;
	int32_t y;
	__ALERT INSTALERT;
	int32_t tank;
	bool collision;
	bool sinking;
	int32_t CYCLE;
} __Main;

// Global variables
__Main instance;
bool EoC;
bool __cbmc_eoc_marker;

// Automata declarations
void ALERT(__ALERT *__context);
void Main(__Main *__context);
void VerificationLoop();

// Automata
void ALERT(__ALERT *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init;
	init: {
		if (((__context->x < 5) && (__context->y < 5))) {
			__context->collision = true;
			goto l5;
		}
		if ((! ((__context->x < 5) && (__context->y < 5)))) {
			__context->collision = false;
			goto l5;
		}
		//assert(false);
		return;  			}
	l5: {
		if ((__context->tank > 5)) {
			__context->sinking = true;
			goto l10;
		}
		if ((! (__context->tank > 5))) {
			__context->sinking = false;
			goto l10;
		}
		//assert(false);
		return;  			}
	l10: {
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
			__context->INSTALERT.x = __context->x;
			__context->INSTALERT.y = __context->y;
			__context->INSTALERT.tank = __context->tank;
			ALERT(&__context->INSTALERT);
			// Assign outputs
			goto l2;
		//assert(false);
		return;  			}
	l2: {
			__context->collision = __context->INSTALERT.collision;
			__context->sinking = __context->INSTALERT.sinking;
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
			instance.tank = nondet_int32_t();
			instance.x = nondet_int32_t();
			instance.y = nondet_int32_t();
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
		assert((!(EoC) || ((! (instance.collision && instance.sinking)) && ((0 <= instance.CYCLE) && (instance.CYCLE <= 20)))));
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
	instance.x = 4;
	instance.y = 3;
	instance.INSTALERT.x = 0;
	instance.INSTALERT.y = 0;
	instance.INSTALERT.tank = 0;
	instance.INSTALERT.collision = false;
	instance.INSTALERT.sinking = false;
	instance.tank = 777;
	instance.collision = false;
	instance.sinking = false;
	instance.CYCLE = 0;
	EoC = false;
	
	VerificationLoop();
}

