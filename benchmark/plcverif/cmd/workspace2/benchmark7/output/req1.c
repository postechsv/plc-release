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
	int32_t IN1;
	int32_t IN2;
	bool LT;
	bool EQ;
	bool QT;
} __USER_CMP;
typedef struct {
	int32_t CYCLE;
	int32_t INPUT1;
	int32_t INPUT2;
	int32_t INPUT3;
	int32_t INPUT4;
	int32_t INPUT5;
	int32_t INPUT6;
	int32_t INPUT7;
	__USER_CMP CMP1;
	__USER_CMP CMP2;
	__USER_CMP CMP3;
	__USER_CMP CMP4;
	__USER_CMP CMP5;
	__USER_CMP CMP6;
	__USER_CMP CMP7;
	bool OUT;
} __Main;

// Global variables
__Main instance;
bool EoC;
bool __cbmc_eoc_marker;

// Automata declarations
void Main(__Main *__context);
void USER_CMP(__USER_CMP *__context);
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
			__context->CMP1.IN1 = __context->INPUT1;
			__context->CMP1.IN2 = __context->INPUT3;
			USER_CMP(&__context->CMP1);
			// Assign outputs
			goto l2;
		//assert(false);
		return;  			}
	l2: {
			// Assign inputs
			__context->CMP2.IN1 = __context->INPUT5;
			__context->CMP2.IN2 = __context->INPUT3;
			USER_CMP(&__context->CMP2);
			// Assign outputs
			goto l3;
		//assert(false);
		return;  			}
	l3: {
			// Assign inputs
			__context->CMP3.IN1 = __context->INPUT2;
			__context->CMP3.IN2 = __context->INPUT7;
			USER_CMP(&__context->CMP3);
			// Assign outputs
			goto l4;
		//assert(false);
		return;  			}
	l4: {
			// Assign inputs
			__context->CMP4.IN1 = __context->INPUT4;
			__context->CMP4.IN2 = __context->INPUT7;
			USER_CMP(&__context->CMP4);
			// Assign outputs
			goto l5;
		//assert(false);
		return;  			}
	l5: {
			// Assign inputs
			__context->CMP5.IN1 = __context->INPUT6;
			__context->CMP5.IN2 = __context->INPUT7;
			USER_CMP(&__context->CMP5);
			// Assign outputs
			goto l6;
		//assert(false);
		return;  			}
	l6: {
			// Assign inputs
			__context->CMP6.IN1 = __context->INPUT4;
			__context->CMP6.IN2 = __context->INPUT1;
			USER_CMP(&__context->CMP6);
			// Assign outputs
			goto l7;
		//assert(false);
		return;  			}
	l7: {
			// Assign inputs
			__context->CMP7.IN1 = __context->INPUT4;
			__context->CMP7.IN2 = __context->INPUT2;
			USER_CMP(&__context->CMP7);
			// Assign outputs
			goto l8;
		//assert(false);
		return;  			}
	l8: {
			__context->OUT = ((((((__context->CMP1.LT && __context->CMP2.EQ) && __context->CMP3.QT) && __context->CMP4.LT) && __context->CMP5.LT) && __context->CMP6.LT) && __context->CMP7.LT);
			goto l9;
		//assert(false);
		return;  			}
	l9: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void USER_CMP(__USER_CMP *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init1;
	init1: {
		if ((__context->IN1 < __context->IN2)) {
			__context->LT = true;
			goto l41;
		}
		if ((! (__context->IN1 < __context->IN2))) {
			goto l41;
		}
		//assert(false);
		return;  			}
	l41: {
		if ((__context->IN1 == __context->IN2)) {
			__context->EQ = true;
			goto l81;
		}
		if ((! (__context->IN1 == __context->IN2))) {
			goto l81;
		}
		//assert(false);
		return;  			}
	l81: {
		if ((__context->IN1 > __context->IN2)) {
			__context->QT = true;
			goto l12;
		}
		if ((! (__context->IN1 > __context->IN2))) {
			goto l12;
		}
		//assert(false);
		return;  			}
	l12: {
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
		assert((!(EoC) || (instance.OUT && ((0 <= instance.CYCLE) && (instance.CYCLE <= 20)))));
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
	instance.CYCLE = 0;
	instance.INPUT1 = 0;
	instance.INPUT2 = 0;
	instance.INPUT3 = 0;
	instance.INPUT4 = 0;
	instance.INPUT5 = 0;
	instance.INPUT6 = 0;
	instance.INPUT7 = 0;
	instance.CMP1.IN1 = 0;
	instance.CMP1.IN2 = 0;
	instance.CMP1.LT = false;
	instance.CMP1.EQ = false;
	instance.CMP1.QT = false;
	instance.CMP2.IN1 = 0;
	instance.CMP2.IN2 = 0;
	instance.CMP2.LT = false;
	instance.CMP2.EQ = false;
	instance.CMP2.QT = false;
	instance.CMP3.IN1 = 0;
	instance.CMP3.IN2 = 0;
	instance.CMP3.LT = false;
	instance.CMP3.EQ = false;
	instance.CMP3.QT = false;
	instance.CMP4.IN1 = 0;
	instance.CMP4.IN2 = 0;
	instance.CMP4.LT = false;
	instance.CMP4.EQ = false;
	instance.CMP4.QT = false;
	instance.CMP5.IN1 = 0;
	instance.CMP5.IN2 = 0;
	instance.CMP5.LT = false;
	instance.CMP5.EQ = false;
	instance.CMP5.QT = false;
	instance.CMP6.IN1 = 0;
	instance.CMP6.IN2 = 0;
	instance.CMP6.LT = false;
	instance.CMP6.EQ = false;
	instance.CMP6.QT = false;
	instance.CMP7.IN1 = 0;
	instance.CMP7.IN2 = 0;
	instance.CMP7.LT = false;
	instance.CMP7.EQ = false;
	instance.CMP7.QT = false;
	instance.OUT = false;
	EoC = false;
	
	VerificationLoop();
}

