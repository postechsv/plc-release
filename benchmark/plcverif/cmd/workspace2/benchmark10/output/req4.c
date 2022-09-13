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
	bool Opened;
	bool Closed;
	bool SyncReq;
	bool SyncDone;
	float Current;
} __ExCBSt;
typedef struct {
	float SwbdFrequency;
	bool Connected;
	float AdjustedPower;
	bool IncPower;
	bool DecPower;
	float DGPF;
	float NominalVoltage;
	float DGCurrent;
} __ExDGSwbdSt;
typedef struct {
	bool BitPos0;
	bool BitPos1;
	bool BitPos2;
	bool BitPos3;
	bool BitPos4;
	bool BitPos5;
	bool BitPos6;
	bool BitPos7;
	bool BitPos8;
	bool BitPos9;
	bool BitPos10;
	bool BitPos11;
	bool BitPos12;
	bool BitPos13;
	bool BitPos14;
	bool BitPos15;
} __ModbusBits;
typedef struct {
	int32_t PEROID_CHECKER;
	bool FIRST_CHECKER;
	bool RUN;
	int32_t CYCLE;
	bool Q;
} __PLS;
typedef struct {
	bool Start;
	float Value;
	float NomValue;
	float DescendTime;
	float CurValue;
	__PLS Inst_PLS;
	float decVal;
	bool Done;
} __DecValOverTime;
typedef struct {
	bool Start;
	float Value;
	float RiseTime;
	float CurValue;
	__PLS Inst_PLS;
	float incVal;
	bool Done;
} __IncValOverTime;
typedef struct {
	bool CLK_PREV;
	bool CLK;
	bool Q;
} __R_TRIG;
typedef struct {
	bool IN;
	int32_t PT;
	int32_t NOW;
	bool Q;
	int32_t ET;
} __TP;
typedef struct {
	bool Open;
	bool Close;
	bool mRemote;
	bool mOpen;
	bool mClose;
	bool fcOpen;
	bool fcClose;
	bool fcTransient;
	bool fcEarthed;
	bool fcTrip;
	float pOpenTime;
	float pCloseTime;
	__ExCBSt exCBData;
	bool Remote;
	bool Opened;
	bool Closed;
	bool Earthed;
	bool Tripped;
	bool Available;
	float Current;
	float movingTime;
	bool openedPos;
	bool closedPos;
	bool closeAvail;
	__R_TRIG OpenCBRemote;
	__R_TRIG CloseCBRemote;
	__TP Timer1;
	int32_t delayTime;
	bool cmdType;
	bool openTrigger;
	bool closeTrigger;
	bool forcedCB;
} __SimCB;
typedef struct {
	bool StartReq;
	bool StopReq;
	bool ShutdownReq;
	bool ShutdownReset;
	bool mRemote;
	bool IncPower;
	bool DecPower;
	bool BackUpModeReq;
	float pNominalVoltage;
	float pNominalFrequency;
	float pNominalRPM;
	float pRunIdleLimit;
	float pRunRatedLimit;
	float pRPMRiseTime;
	float pVoltageRiseTime;
	float pStopTime;
	float pSyncTime;
	__ExCBSt exCBData;
	__ExDGSwbdSt exDGSwbdData;
	bool Remote;
	bool RunIdle;
	bool RunRated;
	float Power;
	float Voltage;
	float Current;
	float Frequency;
	float RPM;
	float FuelRackPos;
	bool ReadyToStart;
	bool BackUpMode;
	bool Shutdown;
	__R_TRIG StartDGRemote;
	__R_TRIG StopDGRemote;
	__IncValOverTime IncreaseVoltage;
	__IncValOverTime IncreaseRPM;
	__IncValOverTime IncreaseFrequency;
	__DecValOverTime DecreaseVoltage;
	__DecValOverTime DecreaseRPM;
	__DecValOverTime DecreaseFrequency;
	__TP Timer1;
	int32_t syncTime;
	float PF;
	__R_TRIG ActiveBackUpMode;
	float rpmRiseTime;
	float voltageRiseTime;
	__R_TRIG ShutdownDGRemote;
	__R_TRIG ShutdownResetDGRemote;
} __SimDG;
typedef struct {
	__SimCB Inst_SimCB1;
	__SimDG Inst_SimDG1;
	__SimCB Inst_SimCB2;
	__SimDG Inst_SimDG2;
	__ExCBSt CB1_exCBData;
	__ExCBSt CB2_exCBData;
	bool CB1_Open;
	bool CB1_Close;
	bool CB1_mRemote;
	bool CB1_mOpen;
	bool CB1_mClose;
	bool CB1_fcOpen;
	bool CB1_fcClose;
	bool CB1_fcTransient;
	bool CB1_fcEarthed;
	bool CB1_fcTrip;
	float CB1_pOpenTime;
	float CB1_pCloseTime;
	bool CB1_Remote;
	bool CB1_Opened;
	bool CB1_Closed;
	bool CB1_Earthed;
	bool CB1_Tripped;
	bool CB1_Available;
	bool CB2_Open;
	bool CB2_Close;
	bool CB2_mRemote;
	bool CB2_mOpen;
	bool CB2_mClose;
	bool CB2_fcOpen;
	bool CB2_fcClose;
	bool CB2_fcTransient;
	bool CB2_fcEarthed;
	bool CB2_fcTrip;
	float CB2_pOpenTime;
	float CB2_pCloseTime;
	bool CB2_Remote;
	bool CB2_Opened;
	bool CB2_Closed;
	bool CB2_Earthed;
	bool CB2_Tripped;
	bool CB2_Available;
	bool DG1_StartReq;
	bool DG1_StopReq;
	bool DG1_Shutdown;
	bool DG1_ShutdownReset;
	bool DG1_mRemote;
	bool DG1_IncLoad;
	bool DG1_DecLoad;
	bool DG1_BackupModeReq;
	float DG1_pNominalVoltage;
	float DG1_pNominalFrequency;
	float DG1_pNominalRPM;
	float DG1_pRunIdleLimit;
	float DG1_pRunRatedLimit;
	float DG1_pRPMRiseTime;
	float DG1_pVoltageRiseTime;
	float DG1_pStopTime;
	float DG1_pSyncTime;
	bool DG1_Remote;
	bool DG1_RunIdle;
	bool DG1_RunRated;
	float DG1_Power;
	float DG1_Voltage;
	float DG1_Current;
	float DG1_Frequency;
	float DG1_RPM;
	float DG1_FuelRackPos;
	bool DG1_BackupMode;
	bool DG2_StartReq;
	bool DG2_StopReq;
	bool DG2_Shutdown;
	bool DG2_ShutdownReset;
	bool DG2_mRemote;
	bool DG2_IncLoad;
	bool DG2_DecLoad;
	bool DG2_BackupMode;
	float DG2_pNominalVoltage;
	float DG2_pNominalFrequency;
	float DG2_pNominalRPM;
	float DG2_pRunIdleLimit;
	float DG2_pRunRatedLimit;
	float DG2_pRPMRiseTime;
	float DG2_pVoltageRiseTime;
	float DG2_pStopTime;
	float DG2_pSyncTime;
	bool DG2_Remote;
	bool DG2_RunIdle;
	bool DG2_RunRated;
	float DG2_Power;
	float DG2_Voltage;
	float DG2_Current;
	float DG2_Frequency;
	float DG2_RPM;
	float DG2_FuelRackPos;
	bool DG2_BackupModeReq;
	float CB1_Current;
	float CB2_Current;
	bool DG1_ReadyToStart;
	bool DG2_ReadyToStart;
	bool DG2_ShutdownReq;
	bool DG1_ShutdownReq;
	int32_t CYCLE;
} __DGSwbd1;

// Global variables
int32_t GLOBAL_TIME;
int32_t CYCLE_TIME;
__ModbusBits PMS1_Addr80;
__ExDGSwbdSt DG1_exDGSwbd1Data;
__ModbusBits PMS1_Addr30;
float PMS1_Addr9;
float PMS1_Addr3;
float PMS1_Addr1;
float PMS1_Addr6;
__ModbusBits PMS1_Addr81;
__ExDGSwbdSt DG2_exDGSwbd1Data;
__ModbusBits PMS1_Addr31;
float PMS1_Addr10;
float PMS1_Addr4;
float PMS1_Addr2;
float PMS1_Addr7;
__DGSwbd1 instance;
bool EoC;
bool __cbmc_eoc_marker;

// Automata declarations
void DGSwbd1(__DGSwbd1 *__context);
void SimCB(__SimCB *__context);
void R_TRIG(__R_TRIG *__context);
void TP(__TP *__context);
void SimDG(__SimDG *__context);
void IncValOverTime(__IncValOverTime *__context);
void PLS(__PLS *__context);
void DecValOverTime(__DecValOverTime *__context);
void VerificationLoop();

// Automata
void DGSwbd1(__DGSwbd1 *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init;
	init: {
			__context->CYCLE = (__context->CYCLE + 1);
			GLOBAL_TIME = (GLOBAL_TIME + CYCLE_TIME);
			__context->DG1_StartReq = PMS1_Addr80.BitPos4;
			__context->DG1_StopReq = PMS1_Addr80.BitPos5;
			__context->DG1_ShutdownReq = PMS1_Addr80.BitPos6;
			__context->DG1_ShutdownReset = PMS1_Addr80.BitPos7;
			__context->DG1_IncLoad = PMS1_Addr80.BitPos2;
			__context->DG1_DecLoad = PMS1_Addr80.BitPos3;
			goto l8;
		//assert(false);
		return;  			}
	l8: {
			// Assign inputs
			__context->Inst_SimDG1.StartReq = __context->DG1_StartReq;
			__context->Inst_SimDG1.StopReq = __context->DG1_StopReq;
			__context->Inst_SimDG1.ShutdownReq = __context->DG1_ShutdownReq;
			__context->Inst_SimDG1.ShutdownReset = __context->DG1_ShutdownReset;
			__context->Inst_SimDG1.mRemote = __context->DG1_mRemote;
			__context->Inst_SimDG1.IncPower = __context->DG1_IncLoad;
			__context->Inst_SimDG1.DecPower = __context->DG1_DecLoad;
			__context->Inst_SimDG1.BackUpModeReq = __context->DG1_BackupModeReq;
			__context->Inst_SimDG1.pNominalVoltage = __context->DG1_pNominalVoltage;
			__context->Inst_SimDG1.pNominalFrequency = __context->DG1_pNominalFrequency;
			__context->Inst_SimDG1.pNominalRPM = __context->DG1_pNominalRPM;
			__context->Inst_SimDG1.pRunIdleLimit = __context->DG1_pRunIdleLimit;
			__context->Inst_SimDG1.pRunRatedLimit = __context->DG1_pRunRatedLimit;
			__context->Inst_SimDG1.pRPMRiseTime = __context->DG1_pRPMRiseTime;
			__context->Inst_SimDG1.pVoltageRiseTime = __context->DG1_pVoltageRiseTime;
			__context->Inst_SimDG1.pStopTime = __context->DG1_pStopTime;
			__context->Inst_SimDG1.pSyncTime = __context->DG1_pSyncTime;
			__context->Inst_SimDG1.exCBData = __context->CB1_exCBData;
			__context->Inst_SimDG1.exDGSwbdData = DG1_exDGSwbd1Data;
			SimDG(&__context->Inst_SimDG1);
			// Assign outputs
			__context->CB1_exCBData = __context->Inst_SimDG1.exCBData;
			DG1_exDGSwbd1Data = __context->Inst_SimDG1.exDGSwbdData;
			goto l9;
		//assert(false);
		return;  			}
	l9: {
			__context->DG1_Remote = __context->Inst_SimDG1.Remote;
			goto l10;
		//assert(false);
		return;  			}
	l10: {
			PMS1_Addr30.BitPos13 = __context->DG1_Remote;
			__context->CB1_Open = PMS1_Addr80.BitPos1;
			__context->CB1_Close = PMS1_Addr80.BitPos0;
			goto l13;
		//assert(false);
		return;  			}
	l13: {
			// Assign inputs
			__context->Inst_SimCB1.Open = __context->CB1_Open;
			__context->Inst_SimCB1.Close = __context->CB1_Close;
			__context->Inst_SimCB1.mRemote = __context->CB1_mRemote;
			__context->Inst_SimCB1.mOpen = __context->CB1_mOpen;
			__context->Inst_SimCB1.mClose = __context->CB1_mClose;
			__context->Inst_SimCB1.fcOpen = __context->CB1_fcOpen;
			__context->Inst_SimCB1.fcClose = __context->CB1_fcClose;
			__context->Inst_SimCB1.fcTransient = __context->CB1_fcTransient;
			__context->Inst_SimCB1.fcEarthed = __context->CB1_fcEarthed;
			__context->Inst_SimCB1.fcTrip = __context->CB1_fcTrip;
			__context->Inst_SimCB1.pOpenTime = __context->CB1_pOpenTime;
			__context->Inst_SimCB1.pCloseTime = __context->CB1_pCloseTime;
			__context->Inst_SimCB1.exCBData = __context->CB1_exCBData;
			SimCB(&__context->Inst_SimCB1);
			// Assign outputs
			__context->CB1_exCBData = __context->Inst_SimCB1.exCBData;
			goto l14;
		//assert(false);
		return;  			}
	l14: {
			__context->DG1_RunIdle = __context->Inst_SimDG1.RunIdle;
			__context->DG1_RunRated = __context->Inst_SimDG1.RunRated;
			goto l16;
		//assert(false);
		return;  			}
	l16: {
			PMS1_Addr30.BitPos11 = __context->DG1_RunRated;
			__context->CB1_Remote = __context->Inst_SimCB1.Remote;
			goto l18;
		//assert(false);
		return;  			}
	l18: {
			PMS1_Addr30.BitPos8 = __context->CB1_Remote;
			__context->DG1_Power = __context->Inst_SimDG1.Power;
			goto l20;
		//assert(false);
		return;  			}
	l20: {
			PMS1_Addr9 = __context->DG1_Power;
			__context->CB1_Opened = __context->Inst_SimCB1.Opened;
			__context->DG1_Voltage = __context->Inst_SimDG1.Voltage;
			goto l23;
		//assert(false);
		return;  			}
	l23: {
			PMS1_Addr3 = __context->DG1_Voltage;
			__context->CB1_Closed = __context->Inst_SimCB1.Closed;
			goto l25;
		//assert(false);
		return;  			}
	l25: {
			PMS1_Addr30.BitPos2 = __context->CB1_Closed;
			__context->DG1_Current = __context->Inst_SimDG1.Current;
			goto l27;
		//assert(false);
		return;  			}
	l27: {
			PMS1_Addr1 = __context->DG1_Current;
			__context->CB1_Earthed = __context->Inst_SimCB1.Earthed;
			goto l29;
		//assert(false);
		return;  			}
	l29: {
			PMS1_Addr30.BitPos0 = __context->CB1_Earthed;
			__context->DG1_Frequency = __context->Inst_SimDG1.Frequency;
			goto l31;
		//assert(false);
		return;  			}
	l31: {
			PMS1_Addr6 = __context->DG1_Frequency;
			__context->CB1_Tripped = __context->Inst_SimCB1.Tripped;
			goto l33;
		//assert(false);
		return;  			}
	l33: {
			PMS1_Addr30.BitPos1 = __context->CB1_Tripped;
			__context->DG1_RPM = __context->Inst_SimDG1.RPM;
			__context->CB1_Available = __context->Inst_SimCB1.Available;
			goto l36;
		//assert(false);
		return;  			}
	l36: {
			PMS1_Addr30.BitPos10 = __context->CB1_Available;
			__context->DG1_FuelRackPos = __context->Inst_SimDG1.FuelRackPos;
			__context->CB1_Current = __context->Inst_SimCB1.Current;
			__context->DG1_ReadyToStart = __context->Inst_SimDG1.ReadyToStart;
			goto l40;
		//assert(false);
		return;  			}
	l40: {
			PMS1_Addr30.BitPos12 = __context->DG1_ReadyToStart;
			__context->DG1_BackupMode = __context->Inst_SimDG1.BackUpMode;
			goto l42;
		//assert(false);
		return;  			}
	l42: {
			PMS1_Addr30.BitPos14 = __context->DG1_BackupMode;
			__context->DG1_Shutdown = __context->Inst_SimDG1.Shutdown;
			goto l44;
		//assert(false);
		return;  			}
	l44: {
			PMS1_Addr30.BitPos6 = (! __context->DG1_Shutdown);
			__context->DG2_StartReq = PMS1_Addr81.BitPos1;
			__context->DG2_StopReq = PMS1_Addr81.BitPos2;
			__context->DG2_ShutdownReq = PMS1_Addr81.BitPos3;
			__context->DG2_ShutdownReset = PMS1_Addr81.BitPos4;
			__context->DG2_IncLoad = PMS1_Addr80.BitPos15;
			__context->DG2_DecLoad = PMS1_Addr81.BitPos0;
			goto l51;
		//assert(false);
		return;  			}
	l51: {
			// Assign inputs
			__context->Inst_SimDG2.StartReq = __context->DG2_StartReq;
			__context->Inst_SimDG2.StopReq = __context->DG2_StopReq;
			__context->Inst_SimDG2.ShutdownReq = __context->DG2_ShutdownReq;
			__context->Inst_SimDG2.ShutdownReset = __context->DG2_ShutdownReset;
			__context->Inst_SimDG2.mRemote = __context->DG2_mRemote;
			__context->Inst_SimDG2.IncPower = __context->DG2_IncLoad;
			__context->Inst_SimDG2.DecPower = __context->DG2_DecLoad;
			__context->Inst_SimDG2.BackUpModeReq = __context->DG2_BackupModeReq;
			__context->Inst_SimDG2.pNominalVoltage = __context->DG2_pNominalVoltage;
			__context->Inst_SimDG2.pNominalFrequency = __context->DG2_pNominalFrequency;
			__context->Inst_SimDG2.pNominalRPM = __context->DG2_pNominalRPM;
			__context->Inst_SimDG2.pRunIdleLimit = __context->DG2_pRunIdleLimit;
			__context->Inst_SimDG2.pRunRatedLimit = __context->DG2_pRunRatedLimit;
			__context->Inst_SimDG2.pRPMRiseTime = __context->DG2_pRPMRiseTime;
			__context->Inst_SimDG2.pVoltageRiseTime = __context->DG2_pVoltageRiseTime;
			__context->Inst_SimDG2.pStopTime = __context->DG2_pStopTime;
			__context->Inst_SimDG2.pSyncTime = __context->DG2_pSyncTime;
			__context->Inst_SimDG2.exCBData = __context->CB2_exCBData;
			__context->Inst_SimDG2.exDGSwbdData = DG2_exDGSwbd1Data;
			SimDG(&__context->Inst_SimDG2);
			// Assign outputs
			__context->CB2_exCBData = __context->Inst_SimDG2.exCBData;
			DG2_exDGSwbd1Data = __context->Inst_SimDG2.exDGSwbdData;
			goto l52;
		//assert(false);
		return;  			}
	l52: {
			__context->DG2_Remote = __context->Inst_SimDG2.Remote;
			goto l53;
		//assert(false);
		return;  			}
	l53: {
			PMS1_Addr31.BitPos4 = __context->DG2_Remote;
			__context->CB2_Open = PMS1_Addr80.BitPos14;
			__context->CB2_Close = PMS1_Addr80.BitPos13;
			goto l56;
		//assert(false);
		return;  			}
	l56: {
			// Assign inputs
			__context->Inst_SimCB2.Open = __context->CB2_Open;
			__context->Inst_SimCB2.Close = __context->CB2_Close;
			__context->Inst_SimCB2.mRemote = __context->CB2_mRemote;
			__context->Inst_SimCB2.mOpen = __context->CB2_mOpen;
			__context->Inst_SimCB2.mClose = __context->CB2_mClose;
			__context->Inst_SimCB2.fcOpen = __context->CB2_fcOpen;
			__context->Inst_SimCB2.fcClose = __context->CB2_fcClose;
			__context->Inst_SimCB2.fcTransient = __context->CB2_fcTransient;
			__context->Inst_SimCB2.fcEarthed = __context->CB2_fcEarthed;
			__context->Inst_SimCB2.fcTrip = __context->CB2_fcTrip;
			__context->Inst_SimCB2.pOpenTime = __context->CB2_pOpenTime;
			__context->Inst_SimCB2.pCloseTime = __context->CB2_pCloseTime;
			__context->Inst_SimCB2.exCBData = __context->CB2_exCBData;
			SimCB(&__context->Inst_SimCB2);
			// Assign outputs
			__context->CB2_exCBData = __context->Inst_SimCB2.exCBData;
			goto l57;
		//assert(false);
		return;  			}
	l57: {
			__context->DG2_RunIdle = __context->Inst_SimDG2.RunIdle;
			__context->DG2_RunRated = __context->Inst_SimDG2.RunRated;
			goto l59;
		//assert(false);
		return;  			}
	l59: {
			PMS1_Addr31.BitPos2 = __context->DG2_RunRated;
			__context->CB2_Remote = __context->Inst_SimCB2.Remote;
			goto l61;
		//assert(false);
		return;  			}
	l61: {
			PMS1_Addr30.BitPos15 = __context->CB2_Remote;
			__context->DG2_Power = __context->Inst_SimDG2.Power;
			goto l63;
		//assert(false);
		return;  			}
	l63: {
			PMS1_Addr10 = __context->DG2_Power;
			__context->CB2_Opened = __context->Inst_SimCB2.Opened;
			__context->DG2_Voltage = __context->Inst_SimDG2.Voltage;
			goto l66;
		//assert(false);
		return;  			}
	l66: {
			PMS1_Addr4 = __context->DG2_Voltage;
			__context->CB2_Closed = __context->Inst_SimCB2.Closed;
			goto l68;
		//assert(false);
		return;  			}
	l68: {
			PMS1_Addr30.BitPos5 = __context->CB2_Closed;
			__context->DG2_Current = __context->Inst_SimDG2.Current;
			goto l70;
		//assert(false);
		return;  			}
	l70: {
			PMS1_Addr2 = __context->DG2_Current;
			__context->CB2_Earthed = __context->Inst_SimCB2.Earthed;
			goto l72;
		//assert(false);
		return;  			}
	l72: {
			PMS1_Addr30.BitPos3 = __context->CB2_Earthed;
			__context->DG2_Frequency = __context->Inst_SimDG2.Frequency;
			goto l74;
		//assert(false);
		return;  			}
	l74: {
			PMS1_Addr7 = __context->DG2_Frequency;
			__context->CB2_Tripped = __context->Inst_SimCB2.Tripped;
			goto l76;
		//assert(false);
		return;  			}
	l76: {
			PMS1_Addr30.BitPos4 = __context->CB2_Tripped;
			__context->DG2_RPM = __context->Inst_SimDG2.RPM;
			__context->CB2_Available = __context->Inst_SimCB2.Available;
			goto l79;
		//assert(false);
		return;  			}
	l79: {
			PMS1_Addr31.BitPos1 = __context->CB2_Available;
			__context->DG2_FuelRackPos = __context->Inst_SimDG2.FuelRackPos;
			__context->CB2_Current = __context->Inst_SimCB2.Current;
			__context->DG2_ReadyToStart = __context->Inst_SimDG2.ReadyToStart;
			goto l83;
		//assert(false);
		return;  			}
	l83: {
			PMS1_Addr31.BitPos3 = __context->DG2_ReadyToStart;
			__context->DG2_BackupMode = __context->Inst_SimDG2.BackUpMode;
			goto l85;
		//assert(false);
		return;  			}
	l85: {
			PMS1_Addr31.BitPos5 = __context->DG2_BackupMode;
			__context->DG2_Shutdown = __context->Inst_SimDG2.Shutdown;
			goto l87;
		//assert(false);
		return;  			}
	l87: {
			PMS1_Addr30.BitPos7 = (! __context->DG2_Shutdown);
			goto l88;
		//assert(false);
		return;  			}
	l88: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void SimCB(__SimCB *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init1;
	init1: {
			__context->forcedCB = (((__context->fcOpen || __context->fcClose) || __context->fcEarthed) || __context->fcTrip);
			goto l1;
		//assert(false);
		return;  			}
	l1: {
		if ((! __context->forcedCB)) {
			goto l2;
		}
		if ((! (! __context->forcedCB))) {
			goto l24;
		}
		//assert(false);
		return;  			}
	l2: {
		if (__context->mRemote) {
			__context->openTrigger = __context->Open;
			__context->closeTrigger = __context->Close;
			goto l91;
		}
		if ((! __context->mRemote)) {
			__context->openTrigger = __context->mOpen;
			__context->closeTrigger = __context->mClose;
			goto l91;
		}
		//assert(false);
		return;  			}
	l91: {
			// Assign inputs
			__context->OpenCBRemote.CLK = __context->openTrigger;
			R_TRIG(&__context->OpenCBRemote);
			// Assign outputs
			goto l101;
		//assert(false);
		return;  			}
	l101: {
		if ((__context->OpenCBRemote.Q && (! __context->openedPos))) {
			goto l11;
		}
		if ((! (__context->OpenCBRemote.Q && (! __context->openedPos)))) {
			goto l161;
		}
		//assert(false);
		return;  			}
	l11: {
			// Assign inputs
			__context->Timer1.IN = false;
			__context->Timer1.PT = 0;
			TP(&__context->Timer1);
			// Assign outputs
			goto l12;
		//assert(false);
		return;  			}
	l12: {
			__context->cmdType = true;
			__context->closedPos = false;
			goto l161;
		//assert(false);
		return;  			}
	l161: {
			// Assign inputs
			__context->CloseCBRemote.CLK = __context->closeTrigger;
			R_TRIG(&__context->CloseCBRemote);
			// Assign outputs
			goto l17;
		//assert(false);
		return;  			}
	l17: {
		if ((__context->CloseCBRemote.Q && (! __context->closedPos))) {
			goto l181;
		}
		if ((! (__context->CloseCBRemote.Q && (! __context->closedPos)))) {
			goto l22;
		}
		//assert(false);
		return;  			}
	l181: {
			// Assign inputs
			__context->Timer1.IN = false;
			__context->Timer1.PT = 0;
			TP(&__context->Timer1);
			// Assign outputs
			goto l19;
		//assert(false);
		return;  			}
	l19: {
			__context->cmdType = false;
			goto l22;
		//assert(false);
		return;  			}
	l22: {
			__context->Available = true;
			goto l48;
		//assert(false);
		return;  			}
	l24: {
			// Assign inputs
			__context->Timer1.IN = false;
			__context->Timer1.PT = 0;
			TP(&__context->Timer1);
			// Assign outputs
			goto l251;
		//assert(false);
		return;  			}
	l251: {
			__context->delayTime = 0;
			goto l26;
		//assert(false);
		return;  			}
	l26: {
		if ((__context->fcEarthed || __context->fcTrip)) {
			__context->openedPos = true;
			__context->closedPos = false;
			__context->Available = false;
			goto l47;
		}
		if ((! (__context->fcEarthed || __context->fcTrip))) {
			__context->Available = true;
			goto l32;
		}
		//assert(false);
		return;  			}
	l32: {
		if ((__context->fcOpen || __context->fcClose)) {
			goto l331;
		}
		if ((! (__context->fcOpen || __context->fcClose))) {
			goto l46;
		}
		//assert(false);
		return;  			}
	l331: {
		if ((__context->fcOpen && __context->fcClose)) {
			__context->openedPos = true;
			__context->closedPos = true;
			goto l441;
		}
		if (((! (__context->fcOpen && __context->fcClose)) && __context->fcOpen)) {
			__context->openedPos = true;
			__context->closedPos = false;
			goto l441;
		}
		if ((((! (__context->fcOpen && __context->fcClose)) && (! __context->fcOpen)) && __context->fcClose)) {
			__context->openedPos = false;
			__context->closedPos = true;
			goto l441;
		}
		if (((! (__context->fcOpen && __context->fcClose)) && ((! ((! (__context->fcOpen && __context->fcClose)) && __context->fcOpen)) && (! (((! (__context->fcOpen && __context->fcClose)) && (! __context->fcOpen)) && __context->fcClose))))) {
			goto l441;
		}
		//assert(false);
		return;  			}
	l441: {
			goto l46;
		//assert(false);
		return;  			}
	l46: {
			goto l47;
		//assert(false);
		return;  			}
	l47: {
			goto l48;
		//assert(false);
		return;  			}
	l48: {
		if (((! __context->forcedCB) && __context->fcTransient)) {
			__context->Opened = false;
			__context->Closed = false;
			goto l55;
		}
		if ((! ((! __context->forcedCB) && __context->fcTransient))) {
			__context->Opened = __context->openedPos;
			__context->Closed = __context->closedPos;
			goto l55;
		}
		//assert(false);
		return;  			}
	l55: {
			__context->Remote = __context->mRemote;
			__context->Earthed = __context->fcEarthed;
			__context->Tripped = __context->fcTrip;
			__context->Current = __context->exCBData.Current;
			goto l591;
		//assert(false);
		return;  			}
	l591: {
			__context->exCBData.Opened = __context->Opened;
			goto l60;
		//assert(false);
		return;  			}
	l60: {
			__context->exCBData.Closed = __context->Closed;
			goto l611;
		//assert(false);
		return;  			}
	l611: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void R_TRIG(__R_TRIG *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init2;
	init2: {
		if (((! __context->CLK) && (! __context->CLK_PREV))) {
			__context->Q = false;
			goto l4;
		}
		if ((! ((! __context->CLK) && (! __context->CLK_PREV)))) {
			goto l4;
		}
		//assert(false);
		return;  			}
	l4: {
		if (((! __context->CLK) && __context->CLK_PREV)) {
			__context->Q = false;
			goto l81;
		}
		if ((! ((! __context->CLK) && __context->CLK_PREV))) {
			goto l81;
		}
		//assert(false);
		return;  			}
	l81: {
		if ((__context->CLK && (! __context->CLK_PREV))) {
			__context->Q = true;
			goto l121;
		}
		if ((! (__context->CLK && (! __context->CLK_PREV)))) {
			goto l121;
		}
		//assert(false);
		return;  			}
	l121: {
		if ((__context->CLK && __context->CLK_PREV)) {
			__context->Q = false;
			goto l162;
		}
		if ((! (__context->CLK && __context->CLK_PREV))) {
			goto l162;
		}
		//assert(false);
		return;  			}
	l162: {
			__context->CLK_PREV = __context->CLK;
			goto l171;
		//assert(false);
		return;  			}
	l171: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void TP(__TP *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init3;
	init3: {
		if (((! __context->IN) && (! __context->Q))) {
			__context->Q = false;
			__context->ET = 0;
			goto l5;
		}
		if ((! ((! __context->IN) && (! __context->Q)))) {
			goto l5;
		}
		//assert(false);
		return;  			}
	l5: {
		if (__context->IN) {
			__context->Q = true;
			__context->ET = GLOBAL_TIME;
			__context->NOW = GLOBAL_TIME;
			goto l111;
		}
		if ((! __context->IN)) {
			goto l111;
		}
		//assert(false);
		return;  			}
	l111: {
		if (((GLOBAL_TIME - __context->NOW) >= __context->PT)) {
			__context->ET = __context->PT;
			__context->Q = false;
			goto l163;
		}
		if ((! ((GLOBAL_TIME - __context->NOW) >= __context->PT))) {
			goto l163;
		}
		//assert(false);
		return;  			}
	l163: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void SimDG(__SimDG *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init4;
	init4: {
			// Assign inputs
			__context->StartDGRemote.CLK = __context->StartReq;
			R_TRIG(&__context->StartDGRemote);
			// Assign outputs
			goto l15;
		//assert(false);
		return;  			}
	l15: {
			// Assign inputs
			__context->StopDGRemote.CLK = __context->StopReq;
			R_TRIG(&__context->StopDGRemote);
			// Assign outputs
			goto l21;
		//assert(false);
		return;  			}
	l21: {
			// Assign inputs
			__context->ActiveBackUpMode.CLK = __context->BackUpModeReq;
			R_TRIG(&__context->ActiveBackUpMode);
			// Assign outputs
			goto l3;
		//assert(false);
		return;  			}
	l3: {
			// Assign inputs
			__context->ShutdownDGRemote.CLK = __context->ShutdownReq;
			R_TRIG(&__context->ShutdownDGRemote);
			// Assign outputs
			goto l41;
		//assert(false);
		return;  			}
	l41: {
			// Assign inputs
			__context->ShutdownResetDGRemote.CLK = __context->ShutdownReset;
			R_TRIG(&__context->ShutdownResetDGRemote);
			// Assign outputs
			goto l54;
		//assert(false);
		return;  			}
	l54: {
			__context->Remote = __context->mRemote;
			__context->exDGSwbdData.NominalVoltage = __context->pNominalVoltage;
			goto l7;
		//assert(false);
		return;  			}
	l7: {
			__context->exCBData.Current = __context->Current;
			__context->exDGSwbdData.DGCurrent = __context->Current;
			goto l92;
		//assert(false);
		return;  			}
	l92: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void IncValOverTime(__IncValOverTime *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init5;
	init5: {
			// Assign inputs
			__context->Inst_PLS.RUN = __context->Start;
			__context->Inst_PLS.CYCLE = 100;
			PLS(&__context->Inst_PLS);
			// Assign outputs
			goto l110;
		//assert(false);
		return;  			}
	l110: {
		if (__context->Start) {
			goto l28;
		}
		if ((! __context->Start)) {
			__context->CurValue = 0.0;
			__context->Done = false;
			goto l201;
		}
		//assert(false);
		return;  			}
	l28: {
		if ((__context->RiseTime < 100.0)) {
			__context->incVal = __context->Value;
			goto l71;
		}
		if ((! (__context->RiseTime < 100.0))) {
			__context->incVal = ((__context->Value * 100.0) / __context->RiseTime);
			goto l71;
		}
		//assert(false);
		return;  			}
	l71: {
		if (__context->Inst_PLS.Q) {
			__context->CurValue = (__context->CurValue + __context->incVal);
			goto l93;
		}
		if ((! __context->Inst_PLS.Q)) {
			goto l164;
		}
		//assert(false);
		return;  			}
	l93: {
		if ((__context->CurValue >= __context->Value)) {
			__context->CurValue = __context->Value;
			__context->Done = true;
			goto l141;
		}
		if ((! (__context->CurValue >= __context->Value))) {
			goto l141;
		}
		//assert(false);
		return;  			}
	l141: {
			goto l164;
		//assert(false);
		return;  			}
	l164: {
			goto l201;
		//assert(false);
		return;  			}
	l201: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void PLS(__PLS *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init6;
	init6: {
		if (__context->FIRST_CHECKER) {
			__context->FIRST_CHECKER = false;
			__context->PEROID_CHECKER = GLOBAL_TIME;
			goto l58;
		}
		if ((! __context->FIRST_CHECKER)) {
			goto l58;
		}
		//assert(false);
		return;  			}
	l58: {
		if ((__context->RUN && ((GLOBAL_TIME - __context->PEROID_CHECKER) >= __context->CYCLE))) {
			__context->PEROID_CHECKER = GLOBAL_TIME;
			goto l94;
		}
		if ((! (__context->RUN && ((GLOBAL_TIME - __context->PEROID_CHECKER) >= __context->CYCLE)))) {
			goto l94;
		}
		//assert(false);
		return;  			}
	l94: {
		if ((__context->RUN && ((GLOBAL_TIME - __context->PEROID_CHECKER) >= (__context->CYCLE - CYCLE_TIME)))) {
			__context->Q = true;
			goto l131;
		}
		if ((! (__context->RUN && ((GLOBAL_TIME - __context->PEROID_CHECKER) >= (__context->CYCLE - CYCLE_TIME))))) {
			goto l131;
		}
		//assert(false);
		return;  			}
	l131: {
		if ((! __context->RUN)) {
			__context->Q = false;
			goto l172;
		}
		if ((! (! __context->RUN))) {
			goto l172;
		}
		//assert(false);
		return;  			}
	l172: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void DecValOverTime(__DecValOverTime *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init7;
	init7: {
			// Assign inputs
			__context->Inst_PLS.RUN = __context->Start;
			__context->Inst_PLS.CYCLE = 100;
			PLS(&__context->Inst_PLS);
			// Assign outputs
			goto l112;
		//assert(false);
		return;  			}
	l112: {
		if (__context->Start) {
			__context->CurValue = __context->Value;
			goto l34;
		}
		if ((! __context->Start)) {
			__context->CurValue = 0.0;
			__context->Done = false;
			goto l211;
		}
		//assert(false);
		return;  			}
	l34: {
		if ((__context->DescendTime < 100.0)) {
			__context->decVal = __context->Value;
			goto l82;
		}
		if ((! (__context->DescendTime < 100.0))) {
			__context->decVal = ((__context->NomValue * 100.0) / __context->DescendTime);
			goto l82;
		}
		//assert(false);
		return;  			}
	l82: {
		if (__context->Inst_PLS.Q) {
			__context->CurValue = (__context->CurValue - __context->decVal);
			goto l102;
		}
		if ((! __context->Inst_PLS.Q)) {
			goto l173;
		}
		//assert(false);
		return;  			}
	l102: {
		if ((__context->CurValue <= 0.0)) {
			__context->CurValue = 0.0;
			__context->Done = true;
			goto l151;
		}
		if ((! (__context->CurValue <= 0.0))) {
			goto l151;
		}
		//assert(false);
		return;  			}
	l151: {
			goto l173;
		//assert(false);
		return;  			}
	l173: {
			goto l211;
		//assert(false);
		return;  			}
	l211: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void VerificationLoop() {
	// Temporary variables
	
	// Start with initial location
	goto init8;
	init8: {
			goto loop_start;
		//assert(false);
		return;  			}
	end: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	loop_start: {
			instance.CB1_Close = nondet_bool();
			instance.CB1_Open = nondet_bool();
			instance.CB1_pOpenTime = nondet_float();
			instance.CB2_pOpenTime = nondet_float();
			instance.DG1_StartReq = nondet_bool();
			goto l_main_call;
		if (false) {
			goto end;
		}
		//assert(false);
		return;  			}
	l_main_call: {
			// Assign inputs
			DGSwbd1(&instance);
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
		assert((!(EoC) || (((! (((instance.DG1_Remote && instance.CB1_Closed) && instance.DG1_RunRated) && instance.CB1_Open)) || instance.CB1_Opened) && ((0 <= instance.CYCLE) && (instance.CYCLE <= 20)))));
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
	CYCLE_TIME = 0;
	PMS1_Addr80.BitPos0 = false;
	PMS1_Addr80.BitPos1 = false;
	PMS1_Addr80.BitPos2 = false;
	PMS1_Addr80.BitPos3 = false;
	PMS1_Addr80.BitPos4 = false;
	PMS1_Addr80.BitPos5 = false;
	PMS1_Addr80.BitPos6 = false;
	PMS1_Addr80.BitPos7 = false;
	PMS1_Addr80.BitPos8 = false;
	PMS1_Addr80.BitPos9 = false;
	PMS1_Addr80.BitPos10 = false;
	PMS1_Addr80.BitPos11 = false;
	PMS1_Addr80.BitPos12 = false;
	PMS1_Addr80.BitPos13 = false;
	PMS1_Addr80.BitPos14 = false;
	PMS1_Addr80.BitPos15 = false;
	DG1_exDGSwbd1Data.SwbdFrequency = 0.0;
	DG1_exDGSwbd1Data.Connected = false;
	DG1_exDGSwbd1Data.AdjustedPower = 0.0;
	DG1_exDGSwbd1Data.IncPower = false;
	DG1_exDGSwbd1Data.DecPower = false;
	DG1_exDGSwbd1Data.DGPF = 0.0;
	DG1_exDGSwbd1Data.NominalVoltage = 0.0;
	DG1_exDGSwbd1Data.DGCurrent = 0.0;
	PMS1_Addr30.BitPos0 = false;
	PMS1_Addr30.BitPos1 = false;
	PMS1_Addr30.BitPos2 = false;
	PMS1_Addr30.BitPos3 = false;
	PMS1_Addr30.BitPos4 = false;
	PMS1_Addr30.BitPos5 = false;
	PMS1_Addr30.BitPos6 = false;
	PMS1_Addr30.BitPos7 = false;
	PMS1_Addr30.BitPos8 = false;
	PMS1_Addr30.BitPos9 = false;
	PMS1_Addr30.BitPos10 = false;
	PMS1_Addr30.BitPos11 = false;
	PMS1_Addr30.BitPos12 = false;
	PMS1_Addr30.BitPos13 = false;
	PMS1_Addr30.BitPos14 = false;
	PMS1_Addr30.BitPos15 = false;
	PMS1_Addr9 = 0.0;
	PMS1_Addr3 = 0.0;
	PMS1_Addr1 = 0.0;
	PMS1_Addr6 = 0.0;
	PMS1_Addr81.BitPos0 = false;
	PMS1_Addr81.BitPos1 = false;
	PMS1_Addr81.BitPos2 = false;
	PMS1_Addr81.BitPos3 = false;
	PMS1_Addr81.BitPos4 = false;
	PMS1_Addr81.BitPos5 = false;
	PMS1_Addr81.BitPos6 = false;
	PMS1_Addr81.BitPos7 = false;
	PMS1_Addr81.BitPos8 = false;
	PMS1_Addr81.BitPos9 = false;
	PMS1_Addr81.BitPos10 = false;
	PMS1_Addr81.BitPos11 = false;
	PMS1_Addr81.BitPos12 = false;
	PMS1_Addr81.BitPos13 = false;
	PMS1_Addr81.BitPos14 = false;
	PMS1_Addr81.BitPos15 = false;
	DG2_exDGSwbd1Data.SwbdFrequency = 0.0;
	DG2_exDGSwbd1Data.Connected = false;
	DG2_exDGSwbd1Data.AdjustedPower = 0.0;
	DG2_exDGSwbd1Data.IncPower = false;
	DG2_exDGSwbd1Data.DecPower = false;
	DG2_exDGSwbd1Data.DGPF = 0.0;
	DG2_exDGSwbd1Data.NominalVoltage = 0.0;
	DG2_exDGSwbd1Data.DGCurrent = 0.0;
	PMS1_Addr31.BitPos0 = false;
	PMS1_Addr31.BitPos1 = false;
	PMS1_Addr31.BitPos2 = false;
	PMS1_Addr31.BitPos3 = false;
	PMS1_Addr31.BitPos4 = false;
	PMS1_Addr31.BitPos5 = false;
	PMS1_Addr31.BitPos6 = false;
	PMS1_Addr31.BitPos7 = false;
	PMS1_Addr31.BitPos8 = false;
	PMS1_Addr31.BitPos9 = false;
	PMS1_Addr31.BitPos10 = false;
	PMS1_Addr31.BitPos11 = false;
	PMS1_Addr31.BitPos12 = false;
	PMS1_Addr31.BitPos13 = false;
	PMS1_Addr31.BitPos14 = false;
	PMS1_Addr31.BitPos15 = false;
	PMS1_Addr10 = 0.0;
	PMS1_Addr4 = 0.0;
	PMS1_Addr2 = 0.0;
	PMS1_Addr7 = 0.0;
	instance.Inst_SimCB1.Open = false;
	instance.Inst_SimCB1.Close = false;
	instance.Inst_SimCB1.mRemote = false;
	instance.Inst_SimCB1.mOpen = false;
	instance.Inst_SimCB1.mClose = false;
	instance.Inst_SimCB1.fcOpen = false;
	instance.Inst_SimCB1.fcClose = false;
	instance.Inst_SimCB1.fcTransient = false;
	instance.Inst_SimCB1.fcEarthed = false;
	instance.Inst_SimCB1.fcTrip = false;
	instance.Inst_SimCB1.pOpenTime = 0.0;
	instance.Inst_SimCB1.pCloseTime = 0.0;
	instance.Inst_SimCB1.exCBData.Opened = false;
	instance.Inst_SimCB1.exCBData.Closed = false;
	instance.Inst_SimCB1.exCBData.SyncReq = false;
	instance.Inst_SimCB1.exCBData.SyncDone = false;
	instance.Inst_SimCB1.exCBData.Current = 0.0;
	instance.Inst_SimCB1.Remote = false;
	instance.Inst_SimCB1.Opened = false;
	instance.Inst_SimCB1.Closed = false;
	instance.Inst_SimCB1.Earthed = false;
	instance.Inst_SimCB1.Tripped = false;
	instance.Inst_SimCB1.Available = false;
	instance.Inst_SimCB1.Current = 0.0;
	instance.Inst_SimCB1.movingTime = 0.0;
	instance.Inst_SimCB1.openedPos = true;
	instance.Inst_SimCB1.closedPos = false;
	instance.Inst_SimCB1.closeAvail = false;
	instance.Inst_SimCB1.OpenCBRemote.CLK_PREV = false;
	instance.Inst_SimCB1.OpenCBRemote.CLK = false;
	instance.Inst_SimCB1.OpenCBRemote.Q = false;
	instance.Inst_SimCB1.CloseCBRemote.CLK_PREV = false;
	instance.Inst_SimCB1.CloseCBRemote.CLK = false;
	instance.Inst_SimCB1.CloseCBRemote.Q = false;
	instance.Inst_SimCB1.Timer1.IN = false;
	instance.Inst_SimCB1.Timer1.PT = 0;
	instance.Inst_SimCB1.Timer1.NOW = 0;
	instance.Inst_SimCB1.Timer1.Q = false;
	instance.Inst_SimCB1.Timer1.ET = 0;
	instance.Inst_SimCB1.delayTime = 0;
	instance.Inst_SimCB1.cmdType = false;
	instance.Inst_SimCB1.openTrigger = false;
	instance.Inst_SimCB1.closeTrigger = false;
	instance.Inst_SimCB1.forcedCB = false;
	instance.Inst_SimDG1.StartReq = false;
	instance.Inst_SimDG1.StopReq = false;
	instance.Inst_SimDG1.ShutdownReq = false;
	instance.Inst_SimDG1.ShutdownReset = false;
	instance.Inst_SimDG1.mRemote = false;
	instance.Inst_SimDG1.IncPower = false;
	instance.Inst_SimDG1.DecPower = false;
	instance.Inst_SimDG1.BackUpModeReq = false;
	instance.Inst_SimDG1.pNominalVoltage = 0.0;
	instance.Inst_SimDG1.pNominalFrequency = 0.0;
	instance.Inst_SimDG1.pNominalRPM = 0.0;
	instance.Inst_SimDG1.pRunIdleLimit = 0.0;
	instance.Inst_SimDG1.pRunRatedLimit = 0.0;
	instance.Inst_SimDG1.pRPMRiseTime = 0.0;
	instance.Inst_SimDG1.pVoltageRiseTime = 0.0;
	instance.Inst_SimDG1.pStopTime = 0.0;
	instance.Inst_SimDG1.pSyncTime = 0.0;
	instance.Inst_SimDG1.exCBData.Opened = false;
	instance.Inst_SimDG1.exCBData.Closed = false;
	instance.Inst_SimDG1.exCBData.SyncReq = false;
	instance.Inst_SimDG1.exCBData.SyncDone = false;
	instance.Inst_SimDG1.exCBData.Current = 0.0;
	instance.Inst_SimDG1.exDGSwbdData.SwbdFrequency = 0.0;
	instance.Inst_SimDG1.exDGSwbdData.Connected = false;
	instance.Inst_SimDG1.exDGSwbdData.AdjustedPower = 0.0;
	instance.Inst_SimDG1.exDGSwbdData.IncPower = false;
	instance.Inst_SimDG1.exDGSwbdData.DecPower = false;
	instance.Inst_SimDG1.exDGSwbdData.DGPF = 0.0;
	instance.Inst_SimDG1.exDGSwbdData.NominalVoltage = 0.0;
	instance.Inst_SimDG1.exDGSwbdData.DGCurrent = 0.0;
	instance.Inst_SimDG1.Remote = false;
	instance.Inst_SimDG1.RunIdle = false;
	instance.Inst_SimDG1.RunRated = false;
	instance.Inst_SimDG1.Power = 0.0;
	instance.Inst_SimDG1.Voltage = 0.0;
	instance.Inst_SimDG1.Current = 0.0;
	instance.Inst_SimDG1.Frequency = 0.0;
	instance.Inst_SimDG1.RPM = 0.0;
	instance.Inst_SimDG1.FuelRackPos = 0.0;
	instance.Inst_SimDG1.ReadyToStart = false;
	instance.Inst_SimDG1.BackUpMode = false;
	instance.Inst_SimDG1.Shutdown = false;
	instance.Inst_SimDG1.StartDGRemote.CLK_PREV = false;
	instance.Inst_SimDG1.StartDGRemote.CLK = false;
	instance.Inst_SimDG1.StartDGRemote.Q = false;
	instance.Inst_SimDG1.StopDGRemote.CLK_PREV = false;
	instance.Inst_SimDG1.StopDGRemote.CLK = false;
	instance.Inst_SimDG1.StopDGRemote.Q = false;
	instance.Inst_SimDG1.IncreaseVoltage.Start = false;
	instance.Inst_SimDG1.IncreaseVoltage.Value = 0.0;
	instance.Inst_SimDG1.IncreaseVoltage.RiseTime = 0.0;
	instance.Inst_SimDG1.IncreaseVoltage.CurValue = 0.0;
	instance.Inst_SimDG1.IncreaseVoltage.Inst_PLS.PEROID_CHECKER = 0;
	instance.Inst_SimDG1.IncreaseVoltage.Inst_PLS.FIRST_CHECKER = true;
	instance.Inst_SimDG1.IncreaseVoltage.Inst_PLS.RUN = false;
	instance.Inst_SimDG1.IncreaseVoltage.Inst_PLS.CYCLE = 0;
	instance.Inst_SimDG1.IncreaseVoltage.Inst_PLS.Q = false;
	instance.Inst_SimDG1.IncreaseVoltage.incVal = 0.0;
	instance.Inst_SimDG1.IncreaseVoltage.Done = false;
	instance.Inst_SimDG1.IncreaseRPM.Start = false;
	instance.Inst_SimDG1.IncreaseRPM.Value = 0.0;
	instance.Inst_SimDG1.IncreaseRPM.RiseTime = 0.0;
	instance.Inst_SimDG1.IncreaseRPM.CurValue = 0.0;
	instance.Inst_SimDG1.IncreaseRPM.Inst_PLS.PEROID_CHECKER = 0;
	instance.Inst_SimDG1.IncreaseRPM.Inst_PLS.FIRST_CHECKER = true;
	instance.Inst_SimDG1.IncreaseRPM.Inst_PLS.RUN = false;
	instance.Inst_SimDG1.IncreaseRPM.Inst_PLS.CYCLE = 0;
	instance.Inst_SimDG1.IncreaseRPM.Inst_PLS.Q = false;
	instance.Inst_SimDG1.IncreaseRPM.incVal = 0.0;
	instance.Inst_SimDG1.IncreaseRPM.Done = false;
	instance.Inst_SimDG1.IncreaseFrequency.Start = false;
	instance.Inst_SimDG1.IncreaseFrequency.Value = 0.0;
	instance.Inst_SimDG1.IncreaseFrequency.RiseTime = 0.0;
	instance.Inst_SimDG1.IncreaseFrequency.CurValue = 0.0;
	instance.Inst_SimDG1.IncreaseFrequency.Inst_PLS.PEROID_CHECKER = 0;
	instance.Inst_SimDG1.IncreaseFrequency.Inst_PLS.FIRST_CHECKER = true;
	instance.Inst_SimDG1.IncreaseFrequency.Inst_PLS.RUN = false;
	instance.Inst_SimDG1.IncreaseFrequency.Inst_PLS.CYCLE = 0;
	instance.Inst_SimDG1.IncreaseFrequency.Inst_PLS.Q = false;
	instance.Inst_SimDG1.IncreaseFrequency.incVal = 0.0;
	instance.Inst_SimDG1.IncreaseFrequency.Done = false;
	instance.Inst_SimDG1.DecreaseVoltage.Start = false;
	instance.Inst_SimDG1.DecreaseVoltage.Value = 0.0;
	instance.Inst_SimDG1.DecreaseVoltage.NomValue = 0.0;
	instance.Inst_SimDG1.DecreaseVoltage.DescendTime = 0.0;
	instance.Inst_SimDG1.DecreaseVoltage.CurValue = 0.0;
	instance.Inst_SimDG1.DecreaseVoltage.Inst_PLS.PEROID_CHECKER = 0;
	instance.Inst_SimDG1.DecreaseVoltage.Inst_PLS.FIRST_CHECKER = true;
	instance.Inst_SimDG1.DecreaseVoltage.Inst_PLS.RUN = false;
	instance.Inst_SimDG1.DecreaseVoltage.Inst_PLS.CYCLE = 0;
	instance.Inst_SimDG1.DecreaseVoltage.Inst_PLS.Q = false;
	instance.Inst_SimDG1.DecreaseVoltage.decVal = 0.0;
	instance.Inst_SimDG1.DecreaseVoltage.Done = false;
	instance.Inst_SimDG1.DecreaseRPM.Start = false;
	instance.Inst_SimDG1.DecreaseRPM.Value = 0.0;
	instance.Inst_SimDG1.DecreaseRPM.NomValue = 0.0;
	instance.Inst_SimDG1.DecreaseRPM.DescendTime = 0.0;
	instance.Inst_SimDG1.DecreaseRPM.CurValue = 0.0;
	instance.Inst_SimDG1.DecreaseRPM.Inst_PLS.PEROID_CHECKER = 0;
	instance.Inst_SimDG1.DecreaseRPM.Inst_PLS.FIRST_CHECKER = true;
	instance.Inst_SimDG1.DecreaseRPM.Inst_PLS.RUN = false;
	instance.Inst_SimDG1.DecreaseRPM.Inst_PLS.CYCLE = 0;
	instance.Inst_SimDG1.DecreaseRPM.Inst_PLS.Q = false;
	instance.Inst_SimDG1.DecreaseRPM.decVal = 0.0;
	instance.Inst_SimDG1.DecreaseRPM.Done = false;
	instance.Inst_SimDG1.DecreaseFrequency.Start = false;
	instance.Inst_SimDG1.DecreaseFrequency.Value = 0.0;
	instance.Inst_SimDG1.DecreaseFrequency.NomValue = 0.0;
	instance.Inst_SimDG1.DecreaseFrequency.DescendTime = 0.0;
	instance.Inst_SimDG1.DecreaseFrequency.CurValue = 0.0;
	instance.Inst_SimDG1.DecreaseFrequency.Inst_PLS.PEROID_CHECKER = 0;
	instance.Inst_SimDG1.DecreaseFrequency.Inst_PLS.FIRST_CHECKER = true;
	instance.Inst_SimDG1.DecreaseFrequency.Inst_PLS.RUN = false;
	instance.Inst_SimDG1.DecreaseFrequency.Inst_PLS.CYCLE = 0;
	instance.Inst_SimDG1.DecreaseFrequency.Inst_PLS.Q = false;
	instance.Inst_SimDG1.DecreaseFrequency.decVal = 0.0;
	instance.Inst_SimDG1.DecreaseFrequency.Done = false;
	instance.Inst_SimDG1.Timer1.IN = false;
	instance.Inst_SimDG1.Timer1.PT = 0;
	instance.Inst_SimDG1.Timer1.NOW = 0;
	instance.Inst_SimDG1.Timer1.Q = false;
	instance.Inst_SimDG1.Timer1.ET = 0;
	instance.Inst_SimDG1.syncTime = 0;
	instance.Inst_SimDG1.PF = 0.0;
	instance.Inst_SimDG1.ActiveBackUpMode.CLK_PREV = false;
	instance.Inst_SimDG1.ActiveBackUpMode.CLK = false;
	instance.Inst_SimDG1.ActiveBackUpMode.Q = false;
	instance.Inst_SimDG1.rpmRiseTime = 0.0;
	instance.Inst_SimDG1.voltageRiseTime = 0.0;
	instance.Inst_SimDG1.ShutdownDGRemote.CLK_PREV = false;
	instance.Inst_SimDG1.ShutdownDGRemote.CLK = false;
	instance.Inst_SimDG1.ShutdownDGRemote.Q = false;
	instance.Inst_SimDG1.ShutdownResetDGRemote.CLK_PREV = false;
	instance.Inst_SimDG1.ShutdownResetDGRemote.CLK = false;
	instance.Inst_SimDG1.ShutdownResetDGRemote.Q = false;
	instance.Inst_SimCB2.Open = false;
	instance.Inst_SimCB2.Close = false;
	instance.Inst_SimCB2.mRemote = false;
	instance.Inst_SimCB2.mOpen = false;
	instance.Inst_SimCB2.mClose = false;
	instance.Inst_SimCB2.fcOpen = false;
	instance.Inst_SimCB2.fcClose = false;
	instance.Inst_SimCB2.fcTransient = false;
	instance.Inst_SimCB2.fcEarthed = false;
	instance.Inst_SimCB2.fcTrip = false;
	instance.Inst_SimCB2.pOpenTime = 0.0;
	instance.Inst_SimCB2.pCloseTime = 0.0;
	instance.Inst_SimCB2.exCBData.Opened = false;
	instance.Inst_SimCB2.exCBData.Closed = false;
	instance.Inst_SimCB2.exCBData.SyncReq = false;
	instance.Inst_SimCB2.exCBData.SyncDone = false;
	instance.Inst_SimCB2.exCBData.Current = 0.0;
	instance.Inst_SimCB2.Remote = false;
	instance.Inst_SimCB2.Opened = false;
	instance.Inst_SimCB2.Closed = false;
	instance.Inst_SimCB2.Earthed = false;
	instance.Inst_SimCB2.Tripped = false;
	instance.Inst_SimCB2.Available = false;
	instance.Inst_SimCB2.Current = 0.0;
	instance.Inst_SimCB2.movingTime = 0.0;
	instance.Inst_SimCB2.openedPos = true;
	instance.Inst_SimCB2.closedPos = false;
	instance.Inst_SimCB2.closeAvail = false;
	instance.Inst_SimCB2.OpenCBRemote.CLK_PREV = false;
	instance.Inst_SimCB2.OpenCBRemote.CLK = false;
	instance.Inst_SimCB2.OpenCBRemote.Q = false;
	instance.Inst_SimCB2.CloseCBRemote.CLK_PREV = false;
	instance.Inst_SimCB2.CloseCBRemote.CLK = false;
	instance.Inst_SimCB2.CloseCBRemote.Q = false;
	instance.Inst_SimCB2.Timer1.IN = false;
	instance.Inst_SimCB2.Timer1.PT = 0;
	instance.Inst_SimCB2.Timer1.NOW = 0;
	instance.Inst_SimCB2.Timer1.Q = false;
	instance.Inst_SimCB2.Timer1.ET = 0;
	instance.Inst_SimCB2.delayTime = 0;
	instance.Inst_SimCB2.cmdType = false;
	instance.Inst_SimCB2.openTrigger = false;
	instance.Inst_SimCB2.closeTrigger = false;
	instance.Inst_SimCB2.forcedCB = false;
	instance.Inst_SimDG2.StartReq = false;
	instance.Inst_SimDG2.StopReq = false;
	instance.Inst_SimDG2.ShutdownReq = false;
	instance.Inst_SimDG2.ShutdownReset = false;
	instance.Inst_SimDG2.mRemote = false;
	instance.Inst_SimDG2.IncPower = false;
	instance.Inst_SimDG2.DecPower = false;
	instance.Inst_SimDG2.BackUpModeReq = false;
	instance.Inst_SimDG2.pNominalVoltage = 0.0;
	instance.Inst_SimDG2.pNominalFrequency = 0.0;
	instance.Inst_SimDG2.pNominalRPM = 0.0;
	instance.Inst_SimDG2.pRunIdleLimit = 0.0;
	instance.Inst_SimDG2.pRunRatedLimit = 0.0;
	instance.Inst_SimDG2.pRPMRiseTime = 0.0;
	instance.Inst_SimDG2.pVoltageRiseTime = 0.0;
	instance.Inst_SimDG2.pStopTime = 0.0;
	instance.Inst_SimDG2.pSyncTime = 0.0;
	instance.Inst_SimDG2.exCBData.Opened = false;
	instance.Inst_SimDG2.exCBData.Closed = false;
	instance.Inst_SimDG2.exCBData.SyncReq = false;
	instance.Inst_SimDG2.exCBData.SyncDone = false;
	instance.Inst_SimDG2.exCBData.Current = 0.0;
	instance.Inst_SimDG2.exDGSwbdData.SwbdFrequency = 0.0;
	instance.Inst_SimDG2.exDGSwbdData.Connected = false;
	instance.Inst_SimDG2.exDGSwbdData.AdjustedPower = 0.0;
	instance.Inst_SimDG2.exDGSwbdData.IncPower = false;
	instance.Inst_SimDG2.exDGSwbdData.DecPower = false;
	instance.Inst_SimDG2.exDGSwbdData.DGPF = 0.0;
	instance.Inst_SimDG2.exDGSwbdData.NominalVoltage = 0.0;
	instance.Inst_SimDG2.exDGSwbdData.DGCurrent = 0.0;
	instance.Inst_SimDG2.Remote = false;
	instance.Inst_SimDG2.RunIdle = false;
	instance.Inst_SimDG2.RunRated = false;
	instance.Inst_SimDG2.Power = 0.0;
	instance.Inst_SimDG2.Voltage = 0.0;
	instance.Inst_SimDG2.Current = 0.0;
	instance.Inst_SimDG2.Frequency = 0.0;
	instance.Inst_SimDG2.RPM = 0.0;
	instance.Inst_SimDG2.FuelRackPos = 0.0;
	instance.Inst_SimDG2.ReadyToStart = false;
	instance.Inst_SimDG2.BackUpMode = false;
	instance.Inst_SimDG2.Shutdown = false;
	instance.Inst_SimDG2.StartDGRemote.CLK_PREV = false;
	instance.Inst_SimDG2.StartDGRemote.CLK = false;
	instance.Inst_SimDG2.StartDGRemote.Q = false;
	instance.Inst_SimDG2.StopDGRemote.CLK_PREV = false;
	instance.Inst_SimDG2.StopDGRemote.CLK = false;
	instance.Inst_SimDG2.StopDGRemote.Q = false;
	instance.Inst_SimDG2.IncreaseVoltage.Start = false;
	instance.Inst_SimDG2.IncreaseVoltage.Value = 0.0;
	instance.Inst_SimDG2.IncreaseVoltage.RiseTime = 0.0;
	instance.Inst_SimDG2.IncreaseVoltage.CurValue = 0.0;
	instance.Inst_SimDG2.IncreaseVoltage.Inst_PLS.PEROID_CHECKER = 0;
	instance.Inst_SimDG2.IncreaseVoltage.Inst_PLS.FIRST_CHECKER = true;
	instance.Inst_SimDG2.IncreaseVoltage.Inst_PLS.RUN = false;
	instance.Inst_SimDG2.IncreaseVoltage.Inst_PLS.CYCLE = 0;
	instance.Inst_SimDG2.IncreaseVoltage.Inst_PLS.Q = false;
	instance.Inst_SimDG2.IncreaseVoltage.incVal = 0.0;
	instance.Inst_SimDG2.IncreaseVoltage.Done = false;
	instance.Inst_SimDG2.IncreaseRPM.Start = false;
	instance.Inst_SimDG2.IncreaseRPM.Value = 0.0;
	instance.Inst_SimDG2.IncreaseRPM.RiseTime = 0.0;
	instance.Inst_SimDG2.IncreaseRPM.CurValue = 0.0;
	instance.Inst_SimDG2.IncreaseRPM.Inst_PLS.PEROID_CHECKER = 0;
	instance.Inst_SimDG2.IncreaseRPM.Inst_PLS.FIRST_CHECKER = true;
	instance.Inst_SimDG2.IncreaseRPM.Inst_PLS.RUN = false;
	instance.Inst_SimDG2.IncreaseRPM.Inst_PLS.CYCLE = 0;
	instance.Inst_SimDG2.IncreaseRPM.Inst_PLS.Q = false;
	instance.Inst_SimDG2.IncreaseRPM.incVal = 0.0;
	instance.Inst_SimDG2.IncreaseRPM.Done = false;
	instance.Inst_SimDG2.IncreaseFrequency.Start = false;
	instance.Inst_SimDG2.IncreaseFrequency.Value = 0.0;
	instance.Inst_SimDG2.IncreaseFrequency.RiseTime = 0.0;
	instance.Inst_SimDG2.IncreaseFrequency.CurValue = 0.0;
	instance.Inst_SimDG2.IncreaseFrequency.Inst_PLS.PEROID_CHECKER = 0;
	instance.Inst_SimDG2.IncreaseFrequency.Inst_PLS.FIRST_CHECKER = true;
	instance.Inst_SimDG2.IncreaseFrequency.Inst_PLS.RUN = false;
	instance.Inst_SimDG2.IncreaseFrequency.Inst_PLS.CYCLE = 0;
	instance.Inst_SimDG2.IncreaseFrequency.Inst_PLS.Q = false;
	instance.Inst_SimDG2.IncreaseFrequency.incVal = 0.0;
	instance.Inst_SimDG2.IncreaseFrequency.Done = false;
	instance.Inst_SimDG2.DecreaseVoltage.Start = false;
	instance.Inst_SimDG2.DecreaseVoltage.Value = 0.0;
	instance.Inst_SimDG2.DecreaseVoltage.NomValue = 0.0;
	instance.Inst_SimDG2.DecreaseVoltage.DescendTime = 0.0;
	instance.Inst_SimDG2.DecreaseVoltage.CurValue = 0.0;
	instance.Inst_SimDG2.DecreaseVoltage.Inst_PLS.PEROID_CHECKER = 0;
	instance.Inst_SimDG2.DecreaseVoltage.Inst_PLS.FIRST_CHECKER = true;
	instance.Inst_SimDG2.DecreaseVoltage.Inst_PLS.RUN = false;
	instance.Inst_SimDG2.DecreaseVoltage.Inst_PLS.CYCLE = 0;
	instance.Inst_SimDG2.DecreaseVoltage.Inst_PLS.Q = false;
	instance.Inst_SimDG2.DecreaseVoltage.decVal = 0.0;
	instance.Inst_SimDG2.DecreaseVoltage.Done = false;
	instance.Inst_SimDG2.DecreaseRPM.Start = false;
	instance.Inst_SimDG2.DecreaseRPM.Value = 0.0;
	instance.Inst_SimDG2.DecreaseRPM.NomValue = 0.0;
	instance.Inst_SimDG2.DecreaseRPM.DescendTime = 0.0;
	instance.Inst_SimDG2.DecreaseRPM.CurValue = 0.0;
	instance.Inst_SimDG2.DecreaseRPM.Inst_PLS.PEROID_CHECKER = 0;
	instance.Inst_SimDG2.DecreaseRPM.Inst_PLS.FIRST_CHECKER = true;
	instance.Inst_SimDG2.DecreaseRPM.Inst_PLS.RUN = false;
	instance.Inst_SimDG2.DecreaseRPM.Inst_PLS.CYCLE = 0;
	instance.Inst_SimDG2.DecreaseRPM.Inst_PLS.Q = false;
	instance.Inst_SimDG2.DecreaseRPM.decVal = 0.0;
	instance.Inst_SimDG2.DecreaseRPM.Done = false;
	instance.Inst_SimDG2.DecreaseFrequency.Start = false;
	instance.Inst_SimDG2.DecreaseFrequency.Value = 0.0;
	instance.Inst_SimDG2.DecreaseFrequency.NomValue = 0.0;
	instance.Inst_SimDG2.DecreaseFrequency.DescendTime = 0.0;
	instance.Inst_SimDG2.DecreaseFrequency.CurValue = 0.0;
	instance.Inst_SimDG2.DecreaseFrequency.Inst_PLS.PEROID_CHECKER = 0;
	instance.Inst_SimDG2.DecreaseFrequency.Inst_PLS.FIRST_CHECKER = true;
	instance.Inst_SimDG2.DecreaseFrequency.Inst_PLS.RUN = false;
	instance.Inst_SimDG2.DecreaseFrequency.Inst_PLS.CYCLE = 0;
	instance.Inst_SimDG2.DecreaseFrequency.Inst_PLS.Q = false;
	instance.Inst_SimDG2.DecreaseFrequency.decVal = 0.0;
	instance.Inst_SimDG2.DecreaseFrequency.Done = false;
	instance.Inst_SimDG2.Timer1.IN = false;
	instance.Inst_SimDG2.Timer1.PT = 0;
	instance.Inst_SimDG2.Timer1.NOW = 0;
	instance.Inst_SimDG2.Timer1.Q = false;
	instance.Inst_SimDG2.Timer1.ET = 0;
	instance.Inst_SimDG2.syncTime = 0;
	instance.Inst_SimDG2.PF = 0.0;
	instance.Inst_SimDG2.ActiveBackUpMode.CLK_PREV = false;
	instance.Inst_SimDG2.ActiveBackUpMode.CLK = false;
	instance.Inst_SimDG2.ActiveBackUpMode.Q = false;
	instance.Inst_SimDG2.rpmRiseTime = 0.0;
	instance.Inst_SimDG2.voltageRiseTime = 0.0;
	instance.Inst_SimDG2.ShutdownDGRemote.CLK_PREV = false;
	instance.Inst_SimDG2.ShutdownDGRemote.CLK = false;
	instance.Inst_SimDG2.ShutdownDGRemote.Q = false;
	instance.Inst_SimDG2.ShutdownResetDGRemote.CLK_PREV = false;
	instance.Inst_SimDG2.ShutdownResetDGRemote.CLK = false;
	instance.Inst_SimDG2.ShutdownResetDGRemote.Q = false;
	instance.CB1_exCBData.Opened = false;
	instance.CB1_exCBData.Closed = false;
	instance.CB1_exCBData.SyncReq = false;
	instance.CB1_exCBData.SyncDone = false;
	instance.CB1_exCBData.Current = 0.0;
	instance.CB2_exCBData.Opened = false;
	instance.CB2_exCBData.Closed = false;
	instance.CB2_exCBData.SyncReq = false;
	instance.CB2_exCBData.SyncDone = false;
	instance.CB2_exCBData.Current = 0.0;
	instance.CB1_Open = false;
	instance.CB1_Close = false;
	instance.CB1_mRemote = true;
	instance.CB1_mOpen = false;
	instance.CB1_mClose = false;
	instance.CB1_fcOpen = false;
	instance.CB1_fcClose = false;
	instance.CB1_fcTransient = false;
	instance.CB1_fcEarthed = false;
	instance.CB1_fcTrip = false;
	instance.CB1_pOpenTime = 1000.0;
	instance.CB1_pCloseTime = 1000.0;
	instance.CB1_Remote = false;
	instance.CB1_Opened = false;
	instance.CB1_Closed = false;
	instance.CB1_Earthed = false;
	instance.CB1_Tripped = false;
	instance.CB1_Available = false;
	instance.CB2_Open = false;
	instance.CB2_Close = false;
	instance.CB2_mRemote = true;
	instance.CB2_mOpen = false;
	instance.CB2_mClose = false;
	instance.CB2_fcOpen = false;
	instance.CB2_fcClose = false;
	instance.CB2_fcTransient = false;
	instance.CB2_fcEarthed = false;
	instance.CB2_fcTrip = false;
	instance.CB2_pOpenTime = 1000.0;
	instance.CB2_pCloseTime = 1000.0;
	instance.CB2_Remote = false;
	instance.CB2_Opened = false;
	instance.CB2_Closed = false;
	instance.CB2_Earthed = false;
	instance.CB2_Tripped = false;
	instance.CB2_Available = false;
	instance.DG1_StartReq = false;
	instance.DG1_StopReq = false;
	instance.DG1_Shutdown = false;
	instance.DG1_ShutdownReset = false;
	instance.DG1_mRemote = true;
	instance.DG1_IncLoad = false;
	instance.DG1_DecLoad = false;
	instance.DG1_BackupModeReq = false;
	instance.DG1_pNominalVoltage = 6600.0;
	instance.DG1_pNominalFrequency = 60.0;
	instance.DG1_pNominalRPM = 720.0;
	instance.DG1_pRunIdleLimit = 60.0;
	instance.DG1_pRunRatedLimit = 90.0;
	instance.DG1_pRPMRiseTime = 4000.0;
	instance.DG1_pVoltageRiseTime = 5000.0;
	instance.DG1_pStopTime = 5000.0;
	instance.DG1_pSyncTime = 3000.0;
	instance.DG1_Remote = false;
	instance.DG1_RunIdle = false;
	instance.DG1_RunRated = false;
	instance.DG1_Power = 0.0;
	instance.DG1_Voltage = 0.0;
	instance.DG1_Current = 0.0;
	instance.DG1_Frequency = 0.0;
	instance.DG1_RPM = 0.0;
	instance.DG1_FuelRackPos = 0.0;
	instance.DG1_BackupMode = false;
	instance.DG2_StartReq = false;
	instance.DG2_StopReq = false;
	instance.DG2_Shutdown = false;
	instance.DG2_ShutdownReset = false;
	instance.DG2_mRemote = true;
	instance.DG2_IncLoad = false;
	instance.DG2_DecLoad = false;
	instance.DG2_BackupMode = false;
	instance.DG2_pNominalVoltage = 6600.0;
	instance.DG2_pNominalFrequency = 60.0;
	instance.DG2_pNominalRPM = 720.0;
	instance.DG2_pRunIdleLimit = 60.0;
	instance.DG2_pRunRatedLimit = 90.0;
	instance.DG2_pRPMRiseTime = 4000.0;
	instance.DG2_pVoltageRiseTime = 5000.0;
	instance.DG2_pStopTime = 5000.0;
	instance.DG2_pSyncTime = 3000.0;
	instance.DG2_Remote = false;
	instance.DG2_RunIdle = false;
	instance.DG2_RunRated = false;
	instance.DG2_Power = 0.0;
	instance.DG2_Voltage = 0.0;
	instance.DG2_Current = 0.0;
	instance.DG2_Frequency = 0.0;
	instance.DG2_RPM = 0.0;
	instance.DG2_FuelRackPos = 0.0;
	instance.DG2_BackupModeReq = false;
	instance.CB1_Current = 0.0;
	instance.CB2_Current = 0.0;
	instance.DG1_ReadyToStart = false;
	instance.DG2_ReadyToStart = false;
	instance.DG2_ShutdownReq = false;
	instance.DG1_ShutdownReq = false;
	instance.CYCLE = 0;
	EoC = false;
	
	VerificationLoop();
}

