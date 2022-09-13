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
	int32_t stateAfterBoot;
	int32_t stateInit;
	int32_t stateWaitForItem;
	int32_t stateWaitForCompressor1;
	int32_t stateExtractItem1;
	int32_t stateWaitForCompressor2;
	int32_t stateExtractItem2;
	int32_t stateRotateTable1;
	int32_t statePunchItem;
	int32_t stateWaitForCompressor3;
	int32_t stateRotateTable2;
	int32_t stateWaitForCompressor4;
	int32_t stateMoveToConveyer1;
	int32_t stateWaitForCompressor5;
	int32_t stateMoveToConveyer2;
	int32_t stateRunConveyer;
	int32_t stateMoveToRobot;
	int32_t stateTurnToItem;
	int32_t stateTakeItem;
	int32_t stateTurnToMagazin;
	int32_t pickPosTurn;
	int32_t pickPosVert;
	int32_t pickPosArm;
	int32_t pickPosClaw;
	int32_t dropPosTurn;
	int32_t dropPosArm;
	int32_t moveThreshold;
	int32_t compressorDelay;
	int32_t extractionDelay;
	int32_t conveyerDelay;
	int32_t turnDestPos;
	int32_t turnCurrPos;
	int32_t vertDestPos;
	int32_t vertCurrPos;
	int32_t armDestPos;
	int32_t armCurrPos;
	int32_t clawDestPos;
	int32_t clawCurrPos;
	int32_t compressor;
	int32_t tableMotPow;
	int32_t tableMotDir;
	int32_t magazinLed;
	int32_t magazinPhoto;
	int32_t magazinPusherOn;
	int32_t magazinPusherOff;
	int32_t conveyerMotPow;
	int32_t conveyerMotDir;
	int32_t conveyerLed;
	int32_t conveyerPhoto;
	int32_t conveyerButton;
	int32_t conveyerPusherOn;
	int32_t conveyerPusherOff;
	int32_t puncherButton;
	int32_t puncher;
	int32_t flagDelay;
	int32_t flagState;
	int32_t outState;
	bool outError;
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
		if ((__context->flagState == __context->stateAfterBoot)) {
			__context->compressor = 0;
			__context->tableMotPow = 0;
			__context->tableMotDir = 0;
			__context->magazinLed = 0;
			__context->magazinPusherOn = 0;
			__context->magazinPusherOff = 0;
			__context->conveyerMotPow = 0;
			__context->conveyerMotDir = 0;
			__context->conveyerLed = 0;
			__context->conveyerPusherOn = 0;
			__context->conveyerPusherOff = 0;
			__context->turnDestPos = 0;
			__context->vertDestPos = 0;
			__context->armDestPos = 0;
			__context->clawDestPos = 0;
			goto l17;
		}
		if (((! (__context->flagState == __context->stateAfterBoot)) && (__context->flagState == __context->stateInit))) {
			__context->flagDelay = 0;
			__context->conveyerLed = 1;
			__context->magazinLed = 1;
			__context->turnDestPos = __context->dropPosTurn;
			__context->armDestPos = __context->dropPosArm;
			goto l27;
		}
		if ((((! (__context->flagState == __context->stateAfterBoot)) && (! (__context->flagState == __context->stateInit))) && (__context->flagState == __context->stateWaitForItem))) {
			goto l36;
		}
		if ((((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && (! (__context->flagState == __context->stateWaitForItem)))) && (__context->flagState == __context->stateWaitForCompressor1))) {
			__context->compressor = 1;
			__context->flagDelay = (__context->flagDelay + 1);
			goto l44;
		}
		if ((((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && (! (__context->flagState == __context->stateWaitForCompressor1))))) && (__context->flagState == __context->stateExtractItem1))) {
			__context->magazinPusherOn = 1;
			__context->flagDelay = (__context->flagDelay + 1);
			goto l53;
		}
		if ((((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && (! (__context->flagState == __context->stateExtractItem1)))))) && (__context->flagState == __context->stateWaitForCompressor2))) {
			__context->compressor = 1;
			__context->flagDelay = (__context->flagDelay + 1);
			goto l62;
		}
		if ((((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && (! (__context->flagState == __context->stateWaitForCompressor2))))))) && (__context->flagState == __context->stateExtractItem2))) {
			__context->magazinPusherOff = 1;
			__context->flagDelay = (__context->flagDelay + 1);
			goto l71;
		}
		if ((((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && (! (__context->flagState == __context->stateExtractItem2)))))))) && (__context->flagState == __context->stateRotateTable1))) {
			__context->tableMotPow = 200;
			goto l79;
		}
		if ((((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && (! (__context->flagState == __context->stateRotateTable1))))))))) && (__context->flagState == __context->stateWaitForCompressor3))) {
			__context->compressor = 1;
			__context->flagDelay = (__context->flagDelay + 1);
			goto l87;
		}
		if ((((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && (! (__context->flagState == __context->stateWaitForCompressor3)))))))))) && (__context->flagState == __context->statePunchItem))) {
			__context->puncher = 1;
			__context->flagDelay = (__context->flagDelay + 1);
			goto l96;
		}
		if ((((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && (! (__context->flagState == __context->statePunchItem))))))))))) && (__context->flagState == __context->stateRotateTable2))) {
			__context->tableMotPow = 200;
			goto l104;
		}
		if ((((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && ((! (__context->flagState == __context->statePunchItem)) && (! (__context->flagState == __context->stateRotateTable2)))))))))))) && (__context->flagState == __context->stateWaitForCompressor4))) {
			__context->compressor = 1;
			__context->flagDelay = (__context->flagDelay + 1);
			goto l112;
		}
		if ((((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && ((! (__context->flagState == __context->statePunchItem)) && ((! (__context->flagState == __context->stateRotateTable2)) && (! (__context->flagState == __context->stateWaitForCompressor4))))))))))))) && (__context->flagState == __context->stateMoveToConveyer1))) {
			__context->conveyerPusherOn = 1;
			__context->flagDelay = (__context->flagDelay + 1);
			goto l121;
		}
		if ((((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && ((! (__context->flagState == __context->statePunchItem)) && ((! (__context->flagState == __context->stateRotateTable2)) && ((! (__context->flagState == __context->stateWaitForCompressor4)) && (! (__context->flagState == __context->stateMoveToConveyer1)))))))))))))) && (__context->flagState == __context->stateWaitForCompressor5))) {
			__context->compressor = 1;
			__context->flagDelay = (__context->flagDelay + 1);
			goto l130;
		}
		if ((((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && ((! (__context->flagState == __context->statePunchItem)) && ((! (__context->flagState == __context->stateRotateTable2)) && ((! (__context->flagState == __context->stateWaitForCompressor4)) && ((! (__context->flagState == __context->stateMoveToConveyer1)) && (! (__context->flagState == __context->stateWaitForCompressor5))))))))))))))) && (__context->flagState == __context->stateMoveToConveyer2))) {
			__context->conveyerPusherOff = 1;
			__context->flagDelay = (__context->flagDelay + 1);
			goto l139;
		}
		if ((((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && ((! (__context->flagState == __context->statePunchItem)) && ((! (__context->flagState == __context->stateRotateTable2)) && ((! (__context->flagState == __context->stateWaitForCompressor4)) && ((! (__context->flagState == __context->stateMoveToConveyer1)) && ((! (__context->flagState == __context->stateWaitForCompressor5)) && (! (__context->flagState == __context->stateMoveToConveyer2)))))))))))))))) && (__context->flagState == __context->stateRunConveyer))) {
			__context->conveyerMotPow = 200;
			goto l147;
		}
		if ((((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && ((! (__context->flagState == __context->statePunchItem)) && ((! (__context->flagState == __context->stateRotateTable2)) && ((! (__context->flagState == __context->stateWaitForCompressor4)) && ((! (__context->flagState == __context->stateMoveToConveyer1)) && ((! (__context->flagState == __context->stateWaitForCompressor5)) && ((! (__context->flagState == __context->stateMoveToConveyer2)) && (! (__context->flagState == __context->stateRunConveyer))))))))))))))))) && (__context->flagState == __context->stateMoveToRobot))) {
			__context->flagDelay = (__context->flagDelay + 1);
			goto l155;
		}
		if ((((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && ((! (__context->flagState == __context->statePunchItem)) && ((! (__context->flagState == __context->stateRotateTable2)) && ((! (__context->flagState == __context->stateWaitForCompressor4)) && ((! (__context->flagState == __context->stateMoveToConveyer1)) && ((! (__context->flagState == __context->stateWaitForCompressor5)) && ((! (__context->flagState == __context->stateMoveToConveyer2)) && ((! (__context->flagState == __context->stateRunConveyer)) && (! (__context->flagState == __context->stateMoveToRobot)))))))))))))))))) && (__context->flagState == __context->stateTurnToItem))) {
			__context->turnDestPos = __context->pickPosTurn;
			__context->vertDestPos = __context->pickPosVert;
			__context->armDestPos = __context->pickPosArm;
			goto l165;
		}
		if ((((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && ((! (__context->flagState == __context->statePunchItem)) && ((! (__context->flagState == __context->stateRotateTable2)) && ((! (__context->flagState == __context->stateWaitForCompressor4)) && ((! (__context->flagState == __context->stateMoveToConveyer1)) && ((! (__context->flagState == __context->stateWaitForCompressor5)) && ((! (__context->flagState == __context->stateMoveToConveyer2)) && ((! (__context->flagState == __context->stateRunConveyer)) && ((! (__context->flagState == __context->stateMoveToRobot)) && (! (__context->flagState == __context->stateTurnToItem))))))))))))))))))) && (__context->flagState == __context->stateTakeItem))) {
			__context->clawDestPos = __context->pickPosClaw;
			goto l171;
		}
		if ((((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && ((! (__context->flagState == __context->statePunchItem)) && ((! (__context->flagState == __context->stateRotateTable2)) && ((! (__context->flagState == __context->stateWaitForCompressor4)) && ((! (__context->flagState == __context->stateMoveToConveyer1)) && ((! (__context->flagState == __context->stateWaitForCompressor5)) && ((! (__context->flagState == __context->stateMoveToConveyer2)) && ((! (__context->flagState == __context->stateRunConveyer)) && ((! (__context->flagState == __context->stateMoveToRobot)) && ((! (__context->flagState == __context->stateTurnToItem)) && (! (__context->flagState == __context->stateTakeItem)))))))))))))))))))) && (__context->flagState == __context->stateTurnToMagazin))) {
			__context->vertDestPos = 0;
			goto l177;
		}
		if (((! (__context->flagState == __context->stateAfterBoot)) && ((! ((! (__context->flagState == __context->stateAfterBoot)) && (__context->flagState == __context->stateInit))) && ((! (((! (__context->flagState == __context->stateAfterBoot)) && (! (__context->flagState == __context->stateInit))) && (__context->flagState == __context->stateWaitForItem))) && ((! (((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && (! (__context->flagState == __context->stateWaitForItem)))) && (__context->flagState == __context->stateWaitForCompressor1))) && ((! (((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && (! (__context->flagState == __context->stateWaitForCompressor1))))) && (__context->flagState == __context->stateExtractItem1))) && ((! (((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && (! (__context->flagState == __context->stateExtractItem1)))))) && (__context->flagState == __context->stateWaitForCompressor2))) && ((! (((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && (! (__context->flagState == __context->stateWaitForCompressor2))))))) && (__context->flagState == __context->stateExtractItem2))) && ((! (((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && (! (__context->flagState == __context->stateExtractItem2)))))))) && (__context->flagState == __context->stateRotateTable1))) && ((! (((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && (! (__context->flagState == __context->stateRotateTable1))))))))) && (__context->flagState == __context->stateWaitForCompressor3))) && ((! (((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && (! (__context->flagState == __context->stateWaitForCompressor3)))))))))) && (__context->flagState == __context->statePunchItem))) && ((! (((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && (! (__context->flagState == __context->statePunchItem))))))))))) && (__context->flagState == __context->stateRotateTable2))) && ((! (((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && ((! (__context->flagState == __context->statePunchItem)) && (! (__context->flagState == __context->stateRotateTable2)))))))))))) && (__context->flagState == __context->stateWaitForCompressor4))) && ((! (((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && ((! (__context->flagState == __context->statePunchItem)) && ((! (__context->flagState == __context->stateRotateTable2)) && (! (__context->flagState == __context->stateWaitForCompressor4))))))))))))) && (__context->flagState == __context->stateMoveToConveyer1))) && ((! (((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && ((! (__context->flagState == __context->statePunchItem)) && ((! (__context->flagState == __context->stateRotateTable2)) && ((! (__context->flagState == __context->stateWaitForCompressor4)) && (! (__context->flagState == __context->stateMoveToConveyer1)))))))))))))) && (__context->flagState == __context->stateWaitForCompressor5))) && ((! (((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && ((! (__context->flagState == __context->statePunchItem)) && ((! (__context->flagState == __context->stateRotateTable2)) && ((! (__context->flagState == __context->stateWaitForCompressor4)) && ((! (__context->flagState == __context->stateMoveToConveyer1)) && (! (__context->flagState == __context->stateWaitForCompressor5))))))))))))))) && (__context->flagState == __context->stateMoveToConveyer2))) && ((! (((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && ((! (__context->flagState == __context->statePunchItem)) && ((! (__context->flagState == __context->stateRotateTable2)) && ((! (__context->flagState == __context->stateWaitForCompressor4)) && ((! (__context->flagState == __context->stateMoveToConveyer1)) && ((! (__context->flagState == __context->stateWaitForCompressor5)) && (! (__context->flagState == __context->stateMoveToConveyer2)))))))))))))))) && (__context->flagState == __context->stateRunConveyer))) && ((! (((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && ((! (__context->flagState == __context->statePunchItem)) && ((! (__context->flagState == __context->stateRotateTable2)) && ((! (__context->flagState == __context->stateWaitForCompressor4)) && ((! (__context->flagState == __context->stateMoveToConveyer1)) && ((! (__context->flagState == __context->stateWaitForCompressor5)) && ((! (__context->flagState == __context->stateMoveToConveyer2)) && (! (__context->flagState == __context->stateRunConveyer))))))))))))))))) && (__context->flagState == __context->stateMoveToRobot))) && ((! (((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && ((! (__context->flagState == __context->statePunchItem)) && ((! (__context->flagState == __context->stateRotateTable2)) && ((! (__context->flagState == __context->stateWaitForCompressor4)) && ((! (__context->flagState == __context->stateMoveToConveyer1)) && ((! (__context->flagState == __context->stateWaitForCompressor5)) && ((! (__context->flagState == __context->stateMoveToConveyer2)) && ((! (__context->flagState == __context->stateRunConveyer)) && (! (__context->flagState == __context->stateMoveToRobot)))))))))))))))))) && (__context->flagState == __context->stateTurnToItem))) && ((! (((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && ((! (__context->flagState == __context->statePunchItem)) && ((! (__context->flagState == __context->stateRotateTable2)) && ((! (__context->flagState == __context->stateWaitForCompressor4)) && ((! (__context->flagState == __context->stateMoveToConveyer1)) && ((! (__context->flagState == __context->stateWaitForCompressor5)) && ((! (__context->flagState == __context->stateMoveToConveyer2)) && ((! (__context->flagState == __context->stateRunConveyer)) && ((! (__context->flagState == __context->stateMoveToRobot)) && (! (__context->flagState == __context->stateTurnToItem))))))))))))))))))) && (__context->flagState == __context->stateTakeItem))) && (! (((! (__context->flagState == __context->stateAfterBoot)) && ((! (__context->flagState == __context->stateInit)) && ((! (__context->flagState == __context->stateWaitForItem)) && ((! (__context->flagState == __context->stateWaitForCompressor1)) && ((! (__context->flagState == __context->stateExtractItem1)) && ((! (__context->flagState == __context->stateWaitForCompressor2)) && ((! (__context->flagState == __context->stateExtractItem2)) && ((! (__context->flagState == __context->stateRotateTable1)) && ((! (__context->flagState == __context->stateWaitForCompressor3)) && ((! (__context->flagState == __context->statePunchItem)) && ((! (__context->flagState == __context->stateRotateTable2)) && ((! (__context->flagState == __context->stateWaitForCompressor4)) && ((! (__context->flagState == __context->stateMoveToConveyer1)) && ((! (__context->flagState == __context->stateWaitForCompressor5)) && ((! (__context->flagState == __context->stateMoveToConveyer2)) && ((! (__context->flagState == __context->stateRunConveyer)) && ((! (__context->flagState == __context->stateMoveToRobot)) && ((! (__context->flagState == __context->stateTurnToItem)) && (! (__context->flagState == __context->stateTakeItem)))))))))))))))))))) && (__context->flagState == __context->stateTurnToMagazin))))))))))))))))))))))) {
			__context->outError = true;
			__context->compressor = 0;
			__context->puncher = 0;
			__context->tableMotPow = 0;
			__context->tableMotDir = 2;
			__context->conveyerMotPow = 0;
			__context->conveyerMotDir = 2;
			goto l190;
		}
		//assert(false);
		return;  			}
	l17: {
		if ((((__context->turnCurrPos == 0) && (__context->armCurrPos == 0)) && (__context->clawCurrPos == 0))) {
			__context->flagState = __context->stateInit;
			goto l21;
		}
		if ((! (((__context->turnCurrPos == 0) && (__context->armCurrPos == 0)) && (__context->clawCurrPos == 0)))) {
			goto l21;
		}
		//assert(false);
		return;  			}
	l21: {
			goto l190;
		//assert(false);
		return;  			}
	l27: {
		if ((((__context->turnCurrPos == __context->dropPosTurn) && (__context->armCurrPos == __context->dropPosArm)) && (__context->vertCurrPos == 0))) {
			goto l28;
		}
		if ((! (((__context->turnCurrPos == __context->dropPosTurn) && (__context->armCurrPos == __context->dropPosArm)) && (__context->vertCurrPos == 0)))) {
			goto l35;
		}
		//assert(false);
		return;  			}
	l28: {
		if ((__context->clawCurrPos == 0)) {
			__context->flagState = __context->stateWaitForItem;
			goto l33;
		}
		if ((! (__context->clawCurrPos == 0))) {
			__context->clawDestPos = 0;
			goto l33;
		}
		//assert(false);
		return;  			}
	l33: {
			goto l35;
		//assert(false);
		return;  			}
	l35: {
			goto l190;
		//assert(false);
		return;  			}
	l36: {
		if ((__context->magazinPhoto == 1)) {
			__context->magazinLed = 0;
			__context->flagState = __context->stateWaitForCompressor1;
			goto l41;
		}
		if ((! (__context->magazinPhoto == 1))) {
			goto l41;
		}
		//assert(false);
		return;  			}
	l41: {
			goto l190;
		//assert(false);
		return;  			}
	l44: {
		if ((__context->flagDelay >= __context->compressorDelay)) {
			__context->compressor = 0;
			__context->flagDelay = 0;
			__context->flagState = __context->stateExtractItem1;
			goto l50;
		}
		if ((! (__context->flagDelay >= __context->compressorDelay))) {
			goto l50;
		}
		//assert(false);
		return;  			}
	l50: {
			goto l190;
		//assert(false);
		return;  			}
	l53: {
		if ((__context->flagDelay >= __context->extractionDelay)) {
			__context->magazinPusherOn = 0;
			__context->flagDelay = 0;
			__context->flagState = __context->stateWaitForCompressor2;
			goto l59;
		}
		if ((! (__context->flagDelay >= __context->extractionDelay))) {
			goto l59;
		}
		//assert(false);
		return;  			}
	l59: {
			goto l190;
		//assert(false);
		return;  			}
	l62: {
		if ((__context->flagDelay >= __context->compressorDelay)) {
			__context->compressor = 0;
			__context->flagDelay = 0;
			__context->flagState = __context->stateExtractItem2;
			goto l68;
		}
		if ((! (__context->flagDelay >= __context->compressorDelay))) {
			goto l68;
		}
		//assert(false);
		return;  			}
	l68: {
			goto l190;
		//assert(false);
		return;  			}
	l71: {
		if ((__context->flagDelay >= __context->extractionDelay)) {
			__context->magazinPusherOff = 0;
			__context->flagDelay = 0;
			__context->flagState = __context->stateRotateTable1;
			goto l77;
		}
		if ((! (__context->flagDelay >= __context->extractionDelay))) {
			goto l77;
		}
		//assert(false);
		return;  			}
	l77: {
			goto l190;
		//assert(false);
		return;  			}
	l79: {
		if ((__context->puncherButton == 0)) {
			__context->tableMotPow = 0;
			__context->flagState = __context->stateWaitForCompressor3;
			goto l84;
		}
		if ((! (__context->puncherButton == 0))) {
			goto l84;
		}
		//assert(false);
		return;  			}
	l84: {
			goto l190;
		//assert(false);
		return;  			}
	l87: {
		if ((__context->flagDelay >= __context->compressorDelay)) {
			__context->compressor = 0;
			__context->flagDelay = 0;
			__context->flagState = __context->statePunchItem;
			goto l93;
		}
		if ((! (__context->flagDelay >= __context->compressorDelay))) {
			goto l93;
		}
		//assert(false);
		return;  			}
	l93: {
			goto l190;
		//assert(false);
		return;  			}
	l96: {
		if ((__context->flagDelay >= __context->extractionDelay)) {
			__context->puncher = 0;
			__context->flagDelay = 0;
			__context->flagState = __context->stateRotateTable2;
			goto l102;
		}
		if ((! (__context->flagDelay >= __context->extractionDelay))) {
			goto l102;
		}
		//assert(false);
		return;  			}
	l102: {
			goto l190;
		//assert(false);
		return;  			}
	l104: {
		if ((__context->conveyerButton == 0)) {
			__context->tableMotPow = 0;
			__context->flagState = __context->stateWaitForCompressor4;
			goto l109;
		}
		if ((! (__context->conveyerButton == 0))) {
			goto l109;
		}
		//assert(false);
		return;  			}
	l109: {
			goto l190;
		//assert(false);
		return;  			}
	l112: {
		if ((__context->flagDelay >= __context->compressorDelay)) {
			__context->compressor = 0;
			__context->flagDelay = 0;
			__context->flagState = __context->stateMoveToConveyer1;
			goto l118;
		}
		if ((! (__context->flagDelay >= __context->compressorDelay))) {
			goto l118;
		}
		//assert(false);
		return;  			}
	l118: {
			goto l190;
		//assert(false);
		return;  			}
	l121: {
		if ((__context->flagDelay >= __context->extractionDelay)) {
			__context->conveyerPusherOn = 0;
			__context->flagDelay = 0;
			__context->flagState = __context->stateWaitForCompressor5;
			goto l127;
		}
		if ((! (__context->flagDelay >= __context->extractionDelay))) {
			goto l127;
		}
		//assert(false);
		return;  			}
	l127: {
			goto l190;
		//assert(false);
		return;  			}
	l130: {
		if ((__context->flagDelay >= __context->compressorDelay)) {
			__context->compressor = 0;
			__context->flagDelay = 0;
			__context->flagState = __context->stateMoveToConveyer2;
			goto l136;
		}
		if ((! (__context->flagDelay >= __context->compressorDelay))) {
			goto l136;
		}
		//assert(false);
		return;  			}
	l136: {
			goto l190;
		//assert(false);
		return;  			}
	l139: {
		if ((__context->flagDelay >= __context->extractionDelay)) {
			__context->conveyerPusherOff = 0;
			__context->flagDelay = 0;
			__context->flagState = __context->stateRunConveyer;
			goto l145;
		}
		if ((! (__context->flagDelay >= __context->extractionDelay))) {
			goto l145;
		}
		//assert(false);
		return;  			}
	l145: {
			goto l190;
		//assert(false);
		return;  			}
	l147: {
		if ((__context->conveyerPhoto == 1)) {
			__context->conveyerLed = 0;
			__context->flagDelay = 0;
			__context->flagState = __context->stateMoveToRobot;
			goto l153;
		}
		if ((! (__context->conveyerPhoto == 1))) {
			goto l153;
		}
		//assert(false);
		return;  			}
	l153: {
			goto l190;
		//assert(false);
		return;  			}
	l155: {
		if ((__context->flagDelay > __context->conveyerDelay)) {
			__context->conveyerMotPow = 0;
			__context->flagDelay = 0;
			__context->flagState = __context->stateTurnToItem;
			goto l161;
		}
		if ((! (__context->flagDelay > __context->conveyerDelay))) {
			goto l161;
		}
		//assert(false);
		return;  			}
	l161: {
			goto l190;
		//assert(false);
		return;  			}
	l165: {
		if ((((__context->turnCurrPos == __context->pickPosTurn) && (__context->vertCurrPos == __context->pickPosVert)) && (__context->armCurrPos == __context->pickPosArm))) {
			__context->flagState = __context->stateTakeItem;
			goto l169;
		}
		if ((! (((__context->turnCurrPos == __context->pickPosTurn) && (__context->vertCurrPos == __context->pickPosVert)) && (__context->armCurrPos == __context->pickPosArm)))) {
			goto l169;
		}
		//assert(false);
		return;  			}
	l169: {
			goto l190;
		//assert(false);
		return;  			}
	l171: {
		if ((__context->clawCurrPos == __context->pickPosClaw)) {
			__context->flagState = __context->stateTurnToMagazin;
			goto l175;
		}
		if ((! (__context->clawCurrPos == __context->pickPosClaw))) {
			goto l175;
		}
		//assert(false);
		return;  			}
	l175: {
			goto l190;
		//assert(false);
		return;  			}
	l177: {
		if ((__context->vertCurrPos < __context->moveThreshold)) {
			__context->flagState = __context->stateInit;
			goto l181;
		}
		if ((! (__context->vertCurrPos < __context->moveThreshold))) {
			goto l181;
		}
		//assert(false);
		return;  			}
	l181: {
			goto l190;
		//assert(false);
		return;  			}
	l190: {
			__context->outState = __context->flagState;
			goto l191;
		//assert(false);
		return;  			}
	l191: {
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
			instance.armCurrPos = nondet_int32_t();
			instance.armDestPos = nondet_int32_t();
			instance.clawCurrPos = nondet_int32_t();
			instance.clawDestPos = nondet_int32_t();
			instance.compressor = nondet_int32_t();
			instance.compressorDelay = nondet_int32_t();
			instance.conveyerButton = nondet_int32_t();
			instance.conveyerDelay = nondet_int32_t();
			instance.conveyerLed = nondet_int32_t();
			instance.conveyerMotDir = nondet_int32_t();
			instance.conveyerMotPow = nondet_int32_t();
			instance.conveyerPhoto = nondet_int32_t();
			instance.conveyerPusherOff = nondet_int32_t();
			instance.conveyerPusherOn = nondet_int32_t();
			instance.dropPosArm = nondet_int32_t();
			instance.dropPosTurn = nondet_int32_t();
			instance.extractionDelay = nondet_int32_t();
			instance.flagDelay = nondet_int32_t();
			instance.flagState = nondet_int32_t();
			instance.magazinLed = nondet_int32_t();
			instance.magazinPhoto = nondet_int32_t();
			instance.magazinPusherOff = nondet_int32_t();
			instance.magazinPusherOn = nondet_int32_t();
			instance.moveThreshold = nondet_int32_t();
			instance.pickPosArm = nondet_int32_t();
			instance.pickPosClaw = nondet_int32_t();
			instance.pickPosTurn = nondet_int32_t();
			instance.pickPosVert = nondet_int32_t();
			instance.puncher = nondet_int32_t();
			instance.puncherButton = nondet_int32_t();
			instance.stateAfterBoot = nondet_int32_t();
			instance.stateExtractItem1 = nondet_int32_t();
			instance.stateExtractItem2 = nondet_int32_t();
			instance.stateInit = nondet_int32_t();
			instance.stateMoveToConveyer1 = nondet_int32_t();
			instance.stateMoveToConveyer2 = nondet_int32_t();
			instance.stateMoveToRobot = nondet_int32_t();
			instance.statePunchItem = nondet_int32_t();
			instance.stateRotateTable1 = nondet_int32_t();
			instance.stateRotateTable2 = nondet_int32_t();
			instance.stateRunConveyer = nondet_int32_t();
			instance.stateTakeItem = nondet_int32_t();
			instance.stateTurnToItem = nondet_int32_t();
			instance.stateTurnToMagazin = nondet_int32_t();
			instance.stateWaitForCompressor1 = nondet_int32_t();
			instance.stateWaitForCompressor2 = nondet_int32_t();
			instance.stateWaitForCompressor3 = nondet_int32_t();
			instance.stateWaitForCompressor4 = nondet_int32_t();
			instance.stateWaitForCompressor5 = nondet_int32_t();
			instance.stateWaitForItem = nondet_int32_t();
			instance.tableMotDir = nondet_int32_t();
			instance.tableMotPow = nondet_int32_t();
			instance.turnCurrPos = nondet_int32_t();
			instance.turnDestPos = nondet_int32_t();
			instance.vertCurrPos = nondet_int32_t();
			instance.vertDestPos = nondet_int32_t();
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
		assert((!(EoC) || ((instance.outError == false) && ((0 <= instance.CYCLE) && (instance.CYCLE <= 20)))));
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
	instance.stateAfterBoot = 0;
	instance.stateInit = 1;
	instance.stateWaitForItem = 2;
	instance.stateWaitForCompressor1 = 3;
	instance.stateExtractItem1 = 4;
	instance.stateWaitForCompressor2 = 5;
	instance.stateExtractItem2 = 6;
	instance.stateRotateTable1 = 7;
	instance.statePunchItem = 8;
	instance.stateWaitForCompressor3 = 9;
	instance.stateRotateTable2 = 10;
	instance.stateWaitForCompressor4 = 11;
	instance.stateMoveToConveyer1 = 12;
	instance.stateWaitForCompressor5 = 13;
	instance.stateMoveToConveyer2 = 14;
	instance.stateRunConveyer = 15;
	instance.stateMoveToRobot = 16;
	instance.stateTurnToItem = 17;
	instance.stateTakeItem = 18;
	instance.stateTurnToMagazin = 19;
	instance.pickPosTurn = 111;
	instance.pickPosVert = 80;
	instance.pickPosArm = 28;
	instance.pickPosClaw = 19;
	instance.dropPosTurn = 71;
	instance.dropPosArm = 37;
	instance.moveThreshold = 36;
	instance.compressorDelay = 60000;
	instance.extractionDelay = 15000;
	instance.conveyerDelay = 42200;
	instance.turnDestPos = 0;
	instance.turnCurrPos = 0;
	instance.vertDestPos = 0;
	instance.vertCurrPos = 0;
	instance.armDestPos = 0;
	instance.armCurrPos = 0;
	instance.clawDestPos = 0;
	instance.clawCurrPos = 0;
	instance.compressor = 0;
	instance.tableMotPow = 0;
	instance.tableMotDir = 0;
	instance.magazinLed = 0;
	instance.magazinPhoto = 0;
	instance.magazinPusherOn = 0;
	instance.magazinPusherOff = 0;
	instance.conveyerMotPow = 0;
	instance.conveyerMotDir = 0;
	instance.conveyerLed = 0;
	instance.conveyerPhoto = 0;
	instance.conveyerButton = 0;
	instance.conveyerPusherOn = 0;
	instance.conveyerPusherOff = 0;
	instance.puncherButton = 0;
	instance.puncher = 0;
	instance.flagDelay = 0;
	instance.flagState = 0;
	instance.outState = 0;
	instance.outError = false;
	instance.CYCLE = 0;
	EoC = false;
	
	VerificationLoop();
}

