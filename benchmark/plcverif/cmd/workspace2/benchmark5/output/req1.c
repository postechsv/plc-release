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
	bool RUN;
	float XIN;
	float CYCLE;
	float XOUT;
	float X1;
	float X2;
	float X3;
} __USER_DERIVATIVE;
typedef struct {
	bool RUN;
	bool R1;
	float XIN;
	float X0;
	float CYCLE;
	bool Q;
	float XOUT;
} __USER_INTEGRAL;
typedef struct {
	bool AUTO;
	float PV;
	float SP;
	float X0;
	float KP;
	float TR;
	float TD;
	float CYCLE;
	float XOUT;
	float ERROR;
	__USER_INTEGRAL ITERM;
	__USER_DERIVATIVE DTERM;
} __USER_PID;
typedef struct {
	bool B1;
	float R1;
	float R2;
	float R3;
	float R4;
	float R5;
	float R6;
	float R7;
	__USER_PID PIDHANDLER;
	float PIDOUT;
	int32_t CYCLE;
} __Main;

// Global variables
__Main instance;
uint16_t __assertion_error;
bool __cbmc_eoc_marker;

// Automata declarations
void Main(__Main *__context);
void USER_PID(__USER_PID *__context);
void USER_INTEGRAL(__USER_INTEGRAL *__context);
void USER_DERIVATIVE(__USER_DERIVATIVE *__context);
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
			__context->PIDHANDLER.AUTO = __context->B1;
			__context->PIDHANDLER.PV = __context->R1;
			__context->PIDHANDLER.SP = __context->R2;
			__context->PIDHANDLER.X0 = __context->R3;
			__context->PIDHANDLER.KP = __context->R4;
			__context->PIDHANDLER.TR = __context->R5;
			__context->PIDHANDLER.TD = __context->R6;
			__context->PIDHANDLER.CYCLE = __context->R7;
			USER_PID(&__context->PIDHANDLER);
			// Assign outputs
			goto l2;
		//assert(false);
		return;  			}
	l2: {
			__context->PIDOUT = __context->PIDHANDLER.XOUT;
			goto l3;
		//assert(false);
		return;  			}
	l3: {
		if ((! ((__context->PIDOUT == 1.0) && ((0 <= __context->CYCLE) && (__context->CYCLE <= 20))))) {
			__assertion_error = 1;
			goto end;
		}
		if ((! (! ((__context->PIDOUT == 1.0) && ((0 <= __context->CYCLE) && (__context->CYCLE <= 20)))))) {
			goto end;
		}
		//assert(false);
		return;  			}
	end: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void USER_PID(__USER_PID *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init1;
	init1: {
			__context->ERROR = (__context->PV - __context->SP);
			goto l11;
		//assert(false);
		return;  			}
	l11: {
			// Assign inputs
			__context->ITERM.RUN = __context->AUTO;
			__context->ITERM.R1 = (! __context->AUTO);
			__context->ITERM.XIN = __context->ERROR;
			__context->ITERM.X0 = (__context->TR * (__context->X0 - __context->ERROR));
			__context->ITERM.CYCLE = __context->CYCLE;
			USER_INTEGRAL(&__context->ITERM);
			// Assign outputs
			goto l21;
		//assert(false);
		return;  			}
	l21: {
			// Assign inputs
			__context->DTERM.RUN = __context->AUTO;
			__context->DTERM.XIN = __context->ERROR;
			__context->DTERM.CYCLE = __context->CYCLE;
			USER_DERIVATIVE(&__context->DTERM);
			// Assign outputs
			goto l31;
		//assert(false);
		return;  			}
	l31: {
			__context->XOUT = (__context->KP * ((__context->ERROR + (__context->ITERM.XOUT / __context->TR)) + (__context->DTERM.XOUT * __context->TD)));
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
void USER_INTEGRAL(__USER_INTEGRAL *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init2;
	init2: {
			__context->Q = (! __context->R1);
			goto l12;
		//assert(false);
		return;  			}
	l12: {
		if (__context->R1) {
			__context->XOUT = __context->X0;
			goto l7;
		}
		if (((! __context->R1) && __context->RUN)) {
			__context->XOUT = (__context->XOUT + (__context->XIN * __context->CYCLE));
			goto l7;
		}
		if (((! __context->R1) && (! ((! __context->R1) && __context->RUN)))) {
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
void USER_DERIVATIVE(__USER_DERIVATIVE *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init3;
	init3: {
		if (__context->RUN) {
			__context->XOUT = ((((3.0 * (__context->XIN - __context->X3)) + __context->X1) - __context->X2) / (10.0 * __context->CYCLE));
			goto l22;
		}
		if ((! __context->RUN)) {
			__context->XOUT = 0.0;
			__context->X1 = __context->XIN;
			__context->X2 = __context->XIN;
			__context->X3 = __context->XIN;
			goto l111;
		}
		//assert(false);
		return;  			}
	l22: {
			__context->X3 = __context->X2;
			goto l32;
		//assert(false);
		return;  			}
	l32: {
			__context->X2 = __context->X1;
			goto l41;
		//assert(false);
		return;  			}
	l41: {
			__context->X1 = __context->XIN;
			goto l111;
		//assert(false);
		return;  			}
	l111: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void VerificationLoop() {
	// Temporary variables
	
	// Start with initial location
	goto init4;
	init4: {
			goto loop_start;
		//assert(false);
		return;  			}
	end1: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	loop_start: {
			instance.B1 = nondet_bool();
			instance.R1 = nondet_float();
			instance.R2 = nondet_float();
			instance.R3 = nondet_float();
			instance.R4 = nondet_float();
			instance.R5 = nondet_float();
			instance.R6 = nondet_float();
			instance.R7 = nondet_float();
			goto l_main_call;
		if (false) {
			goto end1;
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
			goto prepare_EoC;
		//assert(false);
		return;  			}
	prepare_EoC: {
		assert((__assertion_error == 0));
		__cbmc_eoc_marker = true; // to indicate the end of the loop for the counterexample parser
		__cbmc_eoc_marker = false;
			goto loop_start;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}

// Main
void main() {
	// Initial values
	instance.B1 = false;
	instance.R1 = 0.0;
	instance.R2 = 0.0;
	instance.R3 = 0.0;
	instance.R4 = 0.0;
	instance.R5 = 0.0;
	instance.R6 = 0.0;
	instance.R7 = 0.0;
	instance.PIDHANDLER.AUTO = false;
	instance.PIDHANDLER.PV = 0.0;
	instance.PIDHANDLER.SP = 0.0;
	instance.PIDHANDLER.X0 = 0.0;
	instance.PIDHANDLER.KP = 0.0;
	instance.PIDHANDLER.TR = 0.0;
	instance.PIDHANDLER.TD = 0.0;
	instance.PIDHANDLER.CYCLE = 0.0;
	instance.PIDHANDLER.XOUT = 0.0;
	instance.PIDHANDLER.ERROR = 0.0;
	instance.PIDHANDLER.ITERM.RUN = false;
	instance.PIDHANDLER.ITERM.R1 = false;
	instance.PIDHANDLER.ITERM.XIN = 0.0;
	instance.PIDHANDLER.ITERM.X0 = 0.0;
	instance.PIDHANDLER.ITERM.CYCLE = 0.0;
	instance.PIDHANDLER.ITERM.Q = false;
	instance.PIDHANDLER.ITERM.XOUT = 0.0;
	instance.PIDHANDLER.DTERM.RUN = false;
	instance.PIDHANDLER.DTERM.XIN = 0.0;
	instance.PIDHANDLER.DTERM.CYCLE = 0.0;
	instance.PIDHANDLER.DTERM.XOUT = 0.0;
	instance.PIDHANDLER.DTERM.X1 = 0.0;
	instance.PIDHANDLER.DTERM.X2 = 0.0;
	instance.PIDHANDLER.DTERM.X3 = 0.0;
	instance.PIDOUT = 0.0;
	instance.CYCLE = 0;
	__assertion_error = 0;
	
	VerificationLoop();
}

