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
	bool in;
	int32_t RET_VAL;
} __BOOL_TO_DINT;
typedef struct {
	int32_t ssMethodType;
	bool OSB;
	bool BB;
	int32_t blk_mode;
	int32_t is_active_c8_mylib;
	int32_t is_Block_Mode;
} __Block;
typedef struct {
	bool IN;
	bool INprevious;
	bool OUT;
} __NEGATIVEEdge;
typedef struct {
	int16_t timerAction;
	bool done;
	bool plcTimerExpired;
} __PLC_CODER_TIMER;
typedef struct {
	int32_t ssMethodType;
	bool b_En;
	float Duration;
	bool Out;
	int32_t is_active_c10_mylib;
	int32_t is_c10_mylib;
	__PLC_CODER_TIMER temporalCounter_i1;
} __AlarmwithDelay;
typedef struct {
	bool IN;
	bool INprevious;
	bool OUT;
} __POSITIVEEdge;
typedef struct {
	int32_t ssMethodType;
	float X;
	bool XF;
	bool FB;
	bool FUHH;
	bool FUWH;
	bool FUWL;
	bool FULL;
	bool FUA;
	bool HFB;
	bool HFUHH;
	bool HFUWH;
	bool HFUWL;
	bool HFULL;
	bool HFUA;
	bool HFO;
	float HFV;
	float PLAHH;
	float PLAH;
	float PLAL;
	float PLALL;
	float PLEHH;
	float PLEH;
	float PLEL;
	float PLELL;
	float PTDAA;
	float PTDWA;
	float PHYS;
	float PEUH;
	float PEUL;
	bool PEUR;
	int32_t PLV;
	float PFBV;
	float PDB;
	bool PCLAM;
	float PRH;
	float PRL;
	float PIH;
	float PIL;
	float PSFH;
	float PSFL;
	float PROC;
	bool PAHH;
	bool PAH;
	bool PAL;
	bool PALL;
	bool PEHH;
	bool PEH;
	bool PEL;
	bool PELL;
	bool BF;
	float Y;
	float YIR;
	bool YF;
	bool AHH;
	bool BHH;
	bool WH;
	bool WL;
	bool ALL;
	bool BLL;
	bool EHH;
	bool EH;
	bool EL;
	bool ELL;
	bool BB;
	bool BUHH;
	bool BUWH;
	bool BUWL;
	bool BULL;
	bool BU;
	float VER;
	bool Memory_PreviousInput;
	bool Memory;
	bool FUArise;
	bool RelationalOperator1_f;
	bool LogicalOperator19;
	bool FUAdec;
	bool RelationalOperator1_e1;
	bool LogicalOperator18;
	bool Memory_PreviousInput_o;
	bool Memory_l;
	bool FBrise;
	bool RelationalOperator1_l;
	bool LogicalOperator21;
	bool FBdec;
	bool RelationalOperator1_j;
	bool LogicalOperator20;
	float Gain4;
	float Product2;
	float Gain5;
	float Product3;
	float DIFFTIME;
	float out_a;
	bool LowerRelop1;
	bool UpperRelop;
	bool Memory_PreviousInput_k;
	bool Memory_m;
	bool FUHHrise;
	bool RelationalOperator1_i;
	bool LogicalOperator8;
	bool FUHHdec;
	bool RelationalOperator1_g;
	bool LogicalOperator6;
	float Gain3;
	float Subtract;
	float Product;
	float Sum3;
	float b_y;
	bool RelationalOperator10;
	bool LogicalOperator1;
	bool LogicalOperator;
	bool RelationalOperator9;
	bool Memory_PreviousInput_a;
	bool Memory_j;
	bool Memory_PreviousInput_a5;
	bool Memory_i;
	bool FUWHrise;
	bool RelationalOperator1_e;
	bool LogicalOperator15;
	bool FUWHdec;
	bool RelationalOperator1_o;
	bool LogicalOperator14;
	bool RelationalOperator9_c;
	float Sum3_o;
	bool RelationalOperator10_g;
	bool LogicalOperator1_c;
	bool LogicalOperator_g;
	bool Memory_PreviousInput_d;
	bool Memory_o;
	bool Memory_PreviousInput_dl;
	bool Memory_b;
	bool FUWLrise;
	bool RelationalOperator1_d;
	bool LogicalOperator17;
	bool FUWLdec;
	bool RelationalOperator1_fv;
	bool LogicalOperator16;
	bool RelationalOperator10_m;
	float Sum2;
	bool RelationalOperator9_m;
	bool LogicalOperator1_o;
	bool LogicalOperator_f;
	bool Memory_PreviousInput_n;
	bool Memory_mx;
	bool b_BB;
	bool LogicalOperator13;
	bool RelationalOperator;
	bool RelationalOperator1;
	bool RelationalOperator2;
	bool Memory_PreviousInput_nz;
	bool Memory_lu;
	bool FULLrise;
	bool RelationalOperator1_b;
	bool LogicalOperator10;
	bool FULLdec;
	bool RelationalOperator1_a;
	bool LogicalOperator9;
	float Sum2_d;
	bool RelationalOperator9_a;
	bool LogicalOperator1_f;
	bool LogicalOperator_j;
	bool RelationalOperator10_j;
	bool Memory_PreviousInput_g;
	bool Memory_a;
	bool LogicalOperator11;
	bool LogicalOperator12;
	bool LogicalOperator3;
	bool LogicalOperator4;
	float Sum3_e;
	bool RelationalOperator10_jk;
	bool LogicalOperator1_k;
	bool LogicalOperator_h;
	bool RelationalOperator9_g;
	bool Memory_PreviousInput_p;
	bool Memory_d;
	float Sum3_l;
	bool RelationalOperator10_a;
	bool LogicalOperator1_l;
	bool LogicalOperator_c;
	bool RelationalOperator9_j;
	bool Memory_PreviousInput_j;
	bool Memory_c;
	float Sum2_h;
	bool RelationalOperator9_o;
	bool LogicalOperator1_d;
	bool LogicalOperator_n;
	bool RelationalOperator10_go;
	bool Memory_PreviousInput_kk;
	bool Memory_jp;
	float Sum2_n;
	bool RelationalOperator9_l;
	bool LogicalOperator1_lj;
	bool LogicalOperator_d;
	bool RelationalOperator10_c;
	bool Memory_PreviousInput_dld;
	bool Memory_la;
	bool UnitDelay_DSTATE_i;
	bool UnitDelay_n;
	bool UnitDelay_DSTATE_id;
	bool UnitDelay_c;
	bool UnitDelay_DSTATE_j;
	bool UnitDelay_h;
	bool UnitDelay_DSTATE_k;
	bool UnitDelay_nm;
	bool UnitDelay_DSTATE_c;
	bool UnitDelay_g;
	bool UnitDelay_DSTATE_l;
	bool UnitDelay_nz;
	bool UnitDelay_DSTATE_d;
	bool UnitDelay_o;
	bool UnitDelay_DSTATE_h;
	bool UnitDelay_ho;
	float Delay5_DSTATE;
	float Delay5;
	float Delay4_DSTATE;
	float Delay4;
	float UnitDelay_DSTATE;
	float UnitDelay;
	float Switch;
	float Switch2;
	bool UnitDelay_DSTATE_m;
	bool UnitDelay_nk;
	bool UnitDelay_DSTATE_a;
	bool UnitDelay_f;
	bool UnitDelay_DSTATE_aw;
	bool UnitDelay_p;
	bool UnitDelay_DSTATE_jb;
	bool UnitDelay_l;
	bool UnitDelay_DSTATE_p;
	bool UnitDelay_b;
	bool UnitDelay_DSTATE_jl;
	bool UnitDelay_pj;
	bool UnitDelay_DSTATE_f;
	bool UnitDelay_oq;
	bool UnitDelay_DSTATE_ft;
	bool UnitDelay_oc;
	bool UnitDelay_DSTATE_o;
	bool UnitDelay_gx;
	bool UnitDelay_DSTATE_g;
	bool UnitDelay_cr;
	bool UnitDelay_DSTATE_c3;
	bool UnitDelay_h3;
	bool UnitDelay_DSTATE_ax;
	bool UnitDelay_ct;
	bool LogicalOperator7;
	float Switch12;
	float Delay1_DSTATE;
	float Delay1;
	bool UnitDelay_DSTATE_ll;
	bool UnitDelay_k;
	bool UnitDelay_DSTATE_mz;
	bool UnitDelay_fu;
	bool UnitDelay_DSTATE_cs;
	bool UnitDelay_m;
	bool UnitDelay_DSTATE_dx;
	bool UnitDelay_px;
	bool alarm_k;
	bool alarm;
	bool Out_d;
	bool out;
	float b_ir;
	float b_x;
	int32_t is_active_c1_MA;
	int32_t is_Force_Mode;
	int32_t blk_mode_p;
	float b_out;
	float egu;
	float Add1;
	bool RelationalOperator3;
	float b_Add;
	bool RelationalOperator4;
	int32_t blk_mode;
	int32_t blk_mode_mz;
	int32_t blk_mode_m;
	int32_t blk_mode_l;
	int32_t blk_mode_j;
	int32_t blk_mode_n;
	bool Logic_d[2];
	bool Logic_k[2];
	bool Logic[2];
	bool Logic_i[2];
	bool Logic_g[2];
	bool Logic_c[2];
	bool Logic_e[2];
	bool Logic_n[2];
	bool Logic_a[2];
	bool Logic_m[2];
	bool Logic_iq[2];
	bool Logic_ap[2];
	bool Logic_m4[2];
	bool Logic_p[2];
	bool Logic_table[16];
	bool Logic_table_i[16];
	bool Logic_table_d[16];
	bool Logic_table_e[16];
	bool Logic_table_et[16];
	bool Logic_table_ie[16];
	bool Logic_table_p[16];
	bool Logic_table_c[16];
	bool Logic_table_j[16];
	bool Logic_table_do[16];
	bool Logic_table_g[16];
	bool Logic_table_iy[16];
	bool Logic_table_m[16];
	bool Logic_table_n[16];
	__AlarmwithDelay i0_AlarmwithDelay1;
	__AlarmwithDelay i1_AlarmwithDelay1;
	__Block i5_Block;
	__Block i0_Block;
	__Block i3_Block;
	__Block i4_Block;
	__Block i1_Block;
	__Block i2_Block;
	__POSITIVEEdge i10_POSITIVEEdge;
	__POSITIVEEdge i9_POSITIVEEdge;
	__NEGATIVEEdge i11_NEGATIVEEdge;
	__NEGATIVEEdge i1_NEGATIVEEdge;
	__POSITIVEEdge i1_POSITIVEEdge;
	__POSITIVEEdge i11_POSITIVEEdge;
	__NEGATIVEEdge i2_NEGATIVEEdge;
	__NEGATIVEEdge i3_NEGATIVEEdge;
	__POSITIVEEdge i3_POSITIVEEdge;
	__POSITIVEEdge i2_POSITIVEEdge;
	__NEGATIVEEdge i9_NEGATIVEEdge;
	__NEGATIVEEdge i10_NEGATIVEEdge;
	__POSITIVEEdge i6_POSITIVEEdge;
	__POSITIVEEdge i5_POSITIVEEdge;
	__NEGATIVEEdge i5_NEGATIVEEdge;
	__NEGATIVEEdge i6_NEGATIVEEdge;
	__POSITIVEEdge i8_POSITIVEEdge;
	__POSITIVEEdge i7_POSITIVEEdge;
	__NEGATIVEEdge i7_NEGATIVEEdge;
	__NEGATIVEEdge i8_NEGATIVEEdge;
	__POSITIVEEdge i4_POSITIVEEdge;
	__POSITIVEEdge i0_POSITIVEEdge;
	__NEGATIVEEdge i0_NEGATIVEEdge;
	__NEGATIVEEdge i4_NEGATIVEEdge;
	int32_t rowIdx;
	float ir;
	float incrate;
	float decrate;
	bool ramp_inc_off;
	bool ramp_dcr_off;
	int32_t tmp;
	bool temp1;
} __MA;
typedef struct {
	__MA Inst_MA;
	int32_t MA_Method;
	float MA_X;
	bool MA_XF;
	bool MA_FB;
	bool MA_FUHH;
	bool MA_FUWH;
	bool MA_FUWL;
	bool MA_FULL;
	bool MA_FUA;
	bool MA_HFB;
	bool MA_HFUHH;
	bool MA_HFUWH;
	bool MA_HFUWL;
	bool MA_HFULL;
	bool MA_HFUA;
	bool MA_HFO;
	float MA_HFV;
	float MA_PLAHH;
	float MA_PLAH;
	float MA_PLAL;
	float MA_PLALL;
	float MA_PLEHH;
	float MA_PLEH;
	float MA_PLEL;
	float MA_PLELL;
	float MA_PTDAA;
	float MA_PTDWA;
	float MA_PHYS;
	float MA_PEUH;
	float MA_PEUL;
	bool MA_PEUR;
	int32_t MA_PLV;
	float MA_PFBV;
	float MA_PDB;
	bool MA_PCLAM;
	float MA_PRH;
	float MA_PRL;
	float MA_PIH;
	float MA_PIL;
	float MA_PSFH;
	float MA_PSFL;
	float MA_PROC;
	bool MA_PAHH;
	bool MA_PAH;
	bool MA_PAL;
	bool MA_PALL;
	bool MA_PEHH;
	bool MA_PEH;
	bool MA_PEL;
	bool MA_PELL;
	bool MA_BF;
	float MA_Y;
	float MA_YIR;
	bool MA_YF;
	bool MA_AHH;
	bool MA_BHH;
	bool MA_WH;
	bool MA_WL;
	bool MA_ALL;
	bool MA_BLL;
	bool MA_EHH;
	bool MA_EH;
	bool MA_EL;
	bool MA_ELL;
	bool MA_BB;
	bool MA_BUHH;
	bool MA_BUWH;
	bool MA_BUWL;
	bool MA_BULL;
	bool MA_BU;
	float MA_VER;
	int32_t CYCLE;
} __Main;

// Global variables
__BOOL_TO_DINT BOOL_TO_DINT1;
__Main instance;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_1;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_2;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_3;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_4;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_5;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_6;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_7;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_8;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_9;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_10;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_11;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_12;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_13;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_14;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_15;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_16;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_17;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_18;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_19;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_20;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_21;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_22;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_23;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_24;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_25;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_26;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_27;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_28;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_29;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_30;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_31;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_32;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_33;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_34;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_35;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_36;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_37;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_38;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_39;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_40;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_41;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_42;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_43;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_44;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_45;
__BOOL_TO_DINT BOOL_TO_DINT1_inlined_46;
bool EoC;
bool __cbmc_eoc_marker;

// Automata declarations
void Main(__Main *__context);
void MA(__MA *__context);
void AlarmwithDelay(__AlarmwithDelay *__context);
void PLC_CODER_TIMER(__PLC_CODER_TIMER *__context);
void Block(__Block *__context);
void POSITIVEEdge(__POSITIVEEdge *__context);
void NEGATIVEEdge(__NEGATIVEEdge *__context);
void BOOL_TO_DINT(__BOOL_TO_DINT *__context);
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
			__context->Inst_MA.ssMethodType = __context->MA_Method;
			__context->Inst_MA.X = __context->MA_X;
			__context->Inst_MA.XF = __context->MA_XF;
			__context->Inst_MA.FB = __context->MA_FB;
			__context->Inst_MA.FUHH = __context->MA_FUHH;
			__context->Inst_MA.FUWH = __context->MA_FUWH;
			__context->Inst_MA.FUWL = __context->MA_FUWL;
			__context->Inst_MA.FULL = __context->MA_FULL;
			__context->Inst_MA.FUA = __context->MA_FUA;
			__context->Inst_MA.HFB = __context->MA_HFB;
			__context->Inst_MA.HFUHH = __context->MA_HFUHH;
			__context->Inst_MA.HFUWH = __context->MA_HFUWH;
			__context->Inst_MA.HFUWL = __context->MA_HFUWL;
			__context->Inst_MA.HFULL = __context->MA_HFULL;
			__context->Inst_MA.HFUA = __context->MA_HFUA;
			__context->Inst_MA.HFO = __context->MA_HFO;
			__context->Inst_MA.HFV = __context->MA_HFV;
			__context->Inst_MA.PLAHH = __context->MA_PLAHH;
			__context->Inst_MA.PLAH = __context->MA_PLAH;
			__context->Inst_MA.PLAL = __context->MA_PLAL;
			__context->Inst_MA.PLALL = __context->MA_PLALL;
			__context->Inst_MA.PLEHH = __context->MA_PLEHH;
			__context->Inst_MA.PLEH = __context->MA_PLEH;
			__context->Inst_MA.PLEL = __context->MA_PLEL;
			__context->Inst_MA.PLELL = __context->MA_PLELL;
			__context->Inst_MA.PTDAA = __context->MA_PTDAA;
			__context->Inst_MA.PTDWA = __context->MA_PTDWA;
			__context->Inst_MA.PHYS = __context->MA_PHYS;
			__context->Inst_MA.PEUH = __context->MA_PEUH;
			__context->Inst_MA.PEUL = __context->MA_PEUL;
			__context->Inst_MA.PEUR = __context->MA_PEUR;
			__context->Inst_MA.PLV = __context->MA_PLV;
			__context->Inst_MA.PFBV = __context->MA_PFBV;
			__context->Inst_MA.PDB = __context->MA_PDB;
			__context->Inst_MA.PCLAM = __context->MA_PCLAM;
			__context->Inst_MA.PRH = __context->MA_PRH;
			__context->Inst_MA.PRL = __context->MA_PRL;
			__context->Inst_MA.PIH = __context->MA_PIH;
			__context->Inst_MA.PIL = __context->MA_PIL;
			__context->Inst_MA.PSFH = __context->MA_PSFH;
			__context->Inst_MA.PSFL = __context->MA_PSFL;
			__context->Inst_MA.PROC = __context->MA_PROC;
			__context->Inst_MA.PAHH = __context->MA_PAHH;
			__context->Inst_MA.PAH = __context->MA_PAH;
			__context->Inst_MA.PAL = __context->MA_PAL;
			__context->Inst_MA.PALL = __context->MA_PALL;
			__context->Inst_MA.PEHH = __context->MA_PEHH;
			__context->Inst_MA.PEH = __context->MA_PEH;
			__context->Inst_MA.PEL = __context->MA_PEL;
			__context->Inst_MA.PELL = __context->MA_PELL;
			MA(&__context->Inst_MA);
			// Assign outputs
			__context->MA_HFB = __context->Inst_MA.HFB;
			__context->MA_HFUHH = __context->Inst_MA.HFUHH;
			__context->MA_HFUWH = __context->Inst_MA.HFUWH;
			__context->MA_HFUWL = __context->Inst_MA.HFUWL;
			__context->MA_HFULL = __context->Inst_MA.HFULL;
			__context->MA_HFUA = __context->Inst_MA.HFUA;
			__context->MA_HFV = __context->Inst_MA.HFV;
			goto l2;
		//assert(false);
		return;  			}
	l2: {
			__context->MA_BF = __context->Inst_MA.BF;
			__context->MA_Y = __context->Inst_MA.Y;
			__context->MA_YIR = __context->Inst_MA.YIR;
			__context->MA_YF = __context->Inst_MA.YF;
			__context->MA_AHH = __context->Inst_MA.AHH;
			__context->MA_BHH = __context->Inst_MA.BHH;
			__context->MA_WH = __context->Inst_MA.WH;
			__context->MA_WL = __context->Inst_MA.WL;
			__context->MA_ALL = __context->Inst_MA.ALL;
			__context->MA_BLL = __context->Inst_MA.BLL;
			__context->MA_EHH = __context->Inst_MA.EHH;
			__context->MA_EH = __context->Inst_MA.EH;
			__context->MA_EL = __context->Inst_MA.EL;
			__context->MA_ELL = __context->Inst_MA.ELL;
			__context->MA_BB = __context->Inst_MA.BB;
			__context->MA_BUHH = __context->Inst_MA.BUHH;
			__context->MA_BUWH = __context->Inst_MA.BUWH;
			__context->MA_BUWL = __context->Inst_MA.BUWL;
			__context->MA_BULL = __context->Inst_MA.BULL;
			__context->MA_BU = __context->Inst_MA.BU;
			__context->MA_VER = __context->Inst_MA.VER;
			goto l23;
		//assert(false);
		return;  			}
	l23: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void MA(__MA *__context) {
	// Temporary variables
	int32_t ___nested_ret_val1;
	int32_t ___nested_ret_val2;
	int32_t ___nested_ret_val3;
	int32_t ___nested_ret_val4;
	int32_t ___nested_ret_val5;
	int32_t ___nested_ret_val6;
	int32_t ___nested_ret_val7;
	int32_t ___nested_ret_val8;
	int32_t ___nested_ret_val9;
	int32_t ___nested_ret_val10;
	int32_t ___nested_ret_val11;
	int32_t ___nested_ret_val12;
	int32_t ___nested_ret_val13;
	int32_t ___nested_ret_val14;
	int32_t ___nested_ret_val15;
	int32_t ___nested_ret_val16;
	int32_t ___nested_ret_val17;
	int32_t ___nested_ret_val18;
	int32_t ___nested_ret_val19;
	int32_t ___nested_ret_val20;
	int32_t ___nested_ret_val21;
	int32_t ___nested_ret_val22;
	int32_t ___nested_ret_val23;
	int32_t ___nested_ret_val24;
	int32_t ___nested_ret_val25;
	int32_t ___nested_ret_val26;
	int32_t ___nested_ret_val27;
	int32_t ___nested_ret_val28;
	
	// Start with initial location
	goto init1;
	init1: {
			___nested_ret_val1 = 0;
			___nested_ret_val10 = 0;
			___nested_ret_val11 = 0;
			___nested_ret_val12 = 0;
			___nested_ret_val13 = 0;
			___nested_ret_val14 = 0;
			___nested_ret_val15 = 0;
			___nested_ret_val16 = 0;
			___nested_ret_val17 = 0;
			___nested_ret_val18 = 0;
			___nested_ret_val19 = 0;
			___nested_ret_val2 = 0;
			___nested_ret_val20 = 0;
			___nested_ret_val21 = 0;
			___nested_ret_val22 = 0;
			___nested_ret_val23 = 0;
			___nested_ret_val24 = 0;
			___nested_ret_val25 = 0;
			___nested_ret_val26 = 0;
			___nested_ret_val27 = 0;
			___nested_ret_val28 = 0;
			___nested_ret_val3 = 0;
			___nested_ret_val4 = 0;
			___nested_ret_val5 = 0;
			___nested_ret_val6 = 0;
			___nested_ret_val7 = 0;
			___nested_ret_val8 = 0;
			___nested_ret_val9 = 0;
			goto l11;
		//assert(false);
		return;  			}
	l11: {
		if ((__context->ssMethodType == 0)) {
			__context->DIFFTIME = 0.1;
			__context->UnitDelay_DSTATE_i = false;
			__context->UnitDelay_DSTATE_id = false;
			__context->UnitDelay_DSTATE_j = false;
			__context->UnitDelay_DSTATE_k = false;
			__context->Memory_PreviousInput = false;
			__context->UnitDelay_DSTATE_c = false;
			__context->UnitDelay_DSTATE_l = false;
			__context->UnitDelay_DSTATE_d = false;
			__context->UnitDelay_DSTATE_h = false;
			__context->Memory_PreviousInput_o = false;
			__context->Delay5_DSTATE = 0.0;
			__context->Delay4_DSTATE = 0.0;
			__context->UnitDelay_DSTATE = 0.0;
			__context->UnitDelay_DSTATE_m = false;
			__context->UnitDelay_DSTATE_a = false;
			__context->UnitDelay_DSTATE_aw = false;
			__context->UnitDelay_DSTATE_jb = false;
			__context->Memory_PreviousInput_k = false;
			__context->Memory_PreviousInput_a = false;
			__context->UnitDelay_DSTATE_p = false;
			__context->UnitDelay_DSTATE_jl = false;
			__context->UnitDelay_DSTATE_f = false;
			__context->UnitDelay_DSTATE_ft = false;
			__context->Memory_PreviousInput_a5 = false;
			__context->Memory_PreviousInput_d = false;
			__context->UnitDelay_DSTATE_o = false;
			__context->UnitDelay_DSTATE_g = false;
			__context->UnitDelay_DSTATE_c3 = false;
			__context->UnitDelay_DSTATE_ax = false;
			__context->Memory_PreviousInput_dl = false;
			__context->Memory_PreviousInput_n = false;
			__context->Delay1_DSTATE = 0.0;
			__context->UnitDelay_DSTATE_ll = false;
			__context->UnitDelay_DSTATE_mz = false;
			__context->UnitDelay_DSTATE_cs = false;
			__context->UnitDelay_DSTATE_dx = false;
			__context->Memory_PreviousInput_nz = false;
			__context->Memory_PreviousInput_g = false;
			__context->Memory_PreviousInput_p = false;
			__context->Memory_PreviousInput_j = false;
			__context->Memory_PreviousInput_kk = false;
			__context->Memory_PreviousInput_dld = false;
			__context->is_Force_Mode = 0;
			__context->is_active_c1_MA = 0;
			goto l49;
		}
		if ((! (__context->ssMethodType == 0))) {
			goto l4;
		}
		//assert(false);
		return;  			}
	l21: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l4: {
		if ((__context->ssMethodType == 1)) {
			goto l69;
		}
		if ((! (__context->ssMethodType == 1))) {
			goto l21;
		}
		//assert(false);
		return;  			}
	l49: {
			// Assign inputs
			__context->i0_AlarmwithDelay1.ssMethodType = 0;
			__context->i0_AlarmwithDelay1.b_En = __context->Logic_d[0];
			__context->i0_AlarmwithDelay1.Duration = __context->PTDWA;
			AlarmwithDelay(&__context->i0_AlarmwithDelay1);
			// Assign outputs
			goto l50;
		//assert(false);
		return;  			}
	l50: {
			__context->Out_d = __context->temp1;
			goto l51;
		//assert(false);
		return;  			}
	l51: {
			// Assign inputs
			__context->i1_AlarmwithDelay1.ssMethodType = 0;
			__context->i1_AlarmwithDelay1.b_En = __context->Logic_k[0];
			__context->i1_AlarmwithDelay1.Duration = __context->PTDWA;
			AlarmwithDelay(&__context->i1_AlarmwithDelay1);
			// Assign outputs
			goto l52;
		//assert(false);
		return;  			}
	l52: {
			__context->out = __context->temp1;
			goto l53;
		//assert(false);
		return;  			}
	l53: {
			// Assign inputs
			__context->i5_Block.ssMethodType = 0;
			__context->i5_Block.OSB = __context->Logic[0];
			Block(&__context->i5_Block);
			// Assign outputs
			goto l54;
		//assert(false);
		return;  			}
	l54: {
			__context->blk_mode = __context->tmp;
			__context->b_BB = __context->temp1;
			goto l56;
		//assert(false);
		return;  			}
	l56: {
			// Assign inputs
			__context->i0_Block.ssMethodType = 0;
			__context->i0_Block.OSB = __context->Logic_i[0];
			Block(&__context->i0_Block);
			// Assign outputs
			goto l57;
		//assert(false);
		return;  			}
	l57: {
			__context->blk_mode_mz = __context->tmp;
			goto l58;
		//assert(false);
		return;  			}
	l58: {
			// Assign inputs
			__context->i3_Block.ssMethodType = 0;
			__context->i3_Block.OSB = __context->Logic_g[0];
			Block(&__context->i3_Block);
			// Assign outputs
			goto l59;
		//assert(false);
		return;  			}
	l59: {
			__context->blk_mode_m = __context->tmp;
			goto l60;
		//assert(false);
		return;  			}
	l60: {
			// Assign inputs
			__context->i4_Block.ssMethodType = 0;
			__context->i4_Block.OSB = __context->Logic_c[0];
			Block(&__context->i4_Block);
			// Assign outputs
			goto l61;
		//assert(false);
		return;  			}
	l61: {
			__context->blk_mode_l = __context->tmp;
			goto l62;
		//assert(false);
		return;  			}
	l62: {
			// Assign inputs
			__context->i1_Block.ssMethodType = 0;
			__context->i1_Block.OSB = __context->Logic_e[0];
			Block(&__context->i1_Block);
			// Assign outputs
			goto l63;
		//assert(false);
		return;  			}
	l63: {
			__context->blk_mode_j = __context->tmp;
			goto l64;
		//assert(false);
		return;  			}
	l64: {
			// Assign inputs
			__context->i2_Block.ssMethodType = 0;
			__context->i2_Block.OSB = __context->Logic_n[0];
			Block(&__context->i2_Block);
			// Assign outputs
			goto l65;
		//assert(false);
		return;  			}
	l65: {
			__context->blk_mode_n = __context->tmp;
			__context->alarm_k = __context->temp1;
			__context->alarm = __context->temp1;
			goto l21;
		//assert(false);
		return;  			}
	l69: {
		if ((! __context->BF)) {
			__context->HFV = __context->Y;
			goto l74;
		}
		if ((! (! __context->BF))) {
			goto l74;
		}
		//assert(false);
		return;  			}
	l74: {
		if (__context->FUHHrise) {
			__context->HFUHH = true;
			goto l78;
		}
		if ((! __context->FUHHrise)) {
			goto l78;
		}
		//assert(false);
		return;  			}
	l78: {
		if (__context->FUHHdec) {
			__context->HFUHH = false;
			goto l82;
		}
		if ((! __context->FUHHdec)) {
			goto l82;
		}
		//assert(false);
		return;  			}
	l82: {
		if (__context->FUWHrise) {
			__context->HFUWH = true;
			goto l86;
		}
		if ((! __context->FUWHrise)) {
			goto l86;
		}
		//assert(false);
		return;  			}
	l86: {
		if (__context->FUWHdec) {
			__context->HFUWH = false;
			goto l90;
		}
		if ((! __context->FUWHdec)) {
			goto l90;
		}
		//assert(false);
		return;  			}
	l90: {
		if (__context->FULLrise) {
			__context->HFULL = true;
			goto l94;
		}
		if ((! __context->FULLrise)) {
			goto l94;
		}
		//assert(false);
		return;  			}
	l94: {
		if (__context->FULLdec) {
			__context->HFULL = false;
			goto l98;
		}
		if ((! __context->FULLdec)) {
			goto l98;
		}
		//assert(false);
		return;  			}
	l98: {
		if (__context->FUWLrise) {
			__context->HFUWL = true;
			goto l102;
		}
		if ((! __context->FUWLrise)) {
			goto l102;
		}
		//assert(false);
		return;  			}
	l102: {
		if (__context->FUWLdec) {
			__context->HFUWL = false;
			goto l106;
		}
		if ((! __context->FUWLdec)) {
			goto l106;
		}
		//assert(false);
		return;  			}
	l106: {
		if (__context->FUArise) {
			__context->HFUA = true;
			goto l110;
		}
		if ((! __context->FUArise)) {
			goto l110;
		}
		//assert(false);
		return;  			}
	l110: {
		if (__context->FUAdec) {
			__context->HFUA = false;
			goto l114;
		}
		if ((! __context->FUAdec)) {
			goto l114;
		}
		//assert(false);
		return;  			}
	l114: {
		if (__context->FBrise) {
			__context->HFB = true;
			goto l118;
		}
		if ((! __context->FBrise)) {
			goto l118;
		}
		//assert(false);
		return;  			}
	l118: {
		if (__context->FBdec) {
			__context->HFB = false;
			goto l122;
		}
		if ((! __context->FBdec)) {
			goto l122;
		}
		//assert(false);
		return;  			}
	l122: {
			__context->UnitDelay_n = __context->UnitDelay_DSTATE_i;
			goto l123;
		//assert(false);
		return;  			}
	l123: {
			// Assign inputs
			__context->i10_POSITIVEEdge.IN = __context->FUA;
			__context->i10_POSITIVEEdge.INprevious = __context->UnitDelay_n;
			POSITIVEEdge(&__context->i10_POSITIVEEdge);
			// Assign outputs
			goto l124;
		//assert(false);
		return;  			}
	l124: {
			__context->temp1 = __context->i10_POSITIVEEdge.OUT;
			goto l125;
		//assert(false);
		return;  			}
	l125: {
			__context->FUArise = __context->temp1;
			__context->UnitDelay_c = __context->UnitDelay_DSTATE_id;
			goto l127;
		//assert(false);
		return;  			}
	l127: {
			// Assign inputs
			__context->i9_POSITIVEEdge.IN = __context->HFUA;
			__context->i9_POSITIVEEdge.INprevious = __context->UnitDelay_c;
			POSITIVEEdge(&__context->i9_POSITIVEEdge);
			// Assign outputs
			goto l128;
		//assert(false);
		return;  			}
	l128: {
			__context->temp1 = __context->i9_POSITIVEEdge.OUT;
			goto l129;
		//assert(false);
		return;  			}
	l129: {
			__context->RelationalOperator1_f = __context->temp1;
			__context->UnitDelay_h = __context->UnitDelay_DSTATE_j;
			goto l131;
		//assert(false);
		return;  			}
	l131: {
			// Assign inputs
			__context->i11_NEGATIVEEdge.IN = __context->FUA;
			__context->i11_NEGATIVEEdge.INprevious = __context->UnitDelay_h;
			NEGATIVEEdge(&__context->i11_NEGATIVEEdge);
			// Assign outputs
			goto l132;
		//assert(false);
		return;  			}
	l132: {
			__context->temp1 = __context->i11_NEGATIVEEdge.OUT;
			goto l133;
		//assert(false);
		return;  			}
	l133: {
			__context->FUAdec = __context->temp1;
			__context->UnitDelay_nm = __context->UnitDelay_DSTATE_k;
			goto l135;
		//assert(false);
		return;  			}
	l135: {
			// Assign inputs
			__context->i1_NEGATIVEEdge.IN = __context->HFUA;
			__context->i1_NEGATIVEEdge.INprevious = __context->UnitDelay_nm;
			NEGATIVEEdge(&__context->i1_NEGATIVEEdge);
			// Assign outputs
			goto l136;
		//assert(false);
		return;  			}
	l136: {
			__context->temp1 = __context->i1_NEGATIVEEdge.OUT;
			goto l137;
		//assert(false);
		return;  			}
	l137: {
			__context->RelationalOperator1_e1 = __context->temp1;
			__context->Memory = __context->Memory_PreviousInput;
			goto l139;
		//assert(false);
		return;  			}
	l139: {
			__context->LogicalOperator19 = (__context->FUArise || __context->RelationalOperator1_f);
			__context->LogicalOperator18 = (__context->FUAdec || __context->RelationalOperator1_e1);
			goto l141;
		//assert(false);
		return;  			}
	l141: {
			__context->temp1 = __context->LogicalOperator19;
			goto l142;
		//assert(false);
		return;  			}
	l142: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_1.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_1);
			// Assign outputs
			__context->rowIdx = BOOL_TO_DINT1_inlined_1.RET_VAL;
			goto l143;
		//assert(false);
		return;  			}
	l143: {
			__context->temp1 = __context->LogicalOperator18;
			goto l144;
		//assert(false);
		return;  			}
	l144: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_2.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_2);
			// Assign outputs
			___nested_ret_val1 = BOOL_TO_DINT1_inlined_2.RET_VAL;
			goto l145;
		//assert(false);
		return;  			}
	l145: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val1);
			__context->temp1 = __context->Memory;
			goto l147;
		//assert(false);
		return;  			}
	l147: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_3.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_3);
			// Assign outputs
			___nested_ret_val2 = BOOL_TO_DINT1_inlined_3.RET_VAL;
			goto l148;
		//assert(false);
		return;  			}
	l148: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val2);
			__context->UnitDelay_g = __context->UnitDelay_DSTATE_c;
			goto l150;
		//assert(false);
		return;  			}
	l150: {
			// Assign inputs
			__context->i1_POSITIVEEdge.IN = __context->FB;
			__context->i1_POSITIVEEdge.INprevious = __context->UnitDelay_g;
			POSITIVEEdge(&__context->i1_POSITIVEEdge);
			// Assign outputs
			goto l151;
		//assert(false);
		return;  			}
	l151: {
			__context->temp1 = __context->i1_POSITIVEEdge.OUT;
			goto l152;
		//assert(false);
		return;  			}
	l152: {
			__context->FBrise = __context->temp1;
			__context->UnitDelay_nz = __context->UnitDelay_DSTATE_l;
			goto l154;
		//assert(false);
		return;  			}
	l154: {
			// Assign inputs
			__context->i11_POSITIVEEdge.IN = __context->HFB;
			__context->i11_POSITIVEEdge.INprevious = __context->UnitDelay_nz;
			POSITIVEEdge(&__context->i11_POSITIVEEdge);
			// Assign outputs
			goto l155;
		//assert(false);
		return;  			}
	l155: {
			__context->temp1 = __context->i11_POSITIVEEdge.OUT;
			goto l156;
		//assert(false);
		return;  			}
	l156: {
			__context->RelationalOperator1_l = __context->temp1;
			__context->UnitDelay_o = __context->UnitDelay_DSTATE_d;
			goto l158;
		//assert(false);
		return;  			}
	l158: {
			// Assign inputs
			__context->i2_NEGATIVEEdge.IN = __context->FB;
			__context->i2_NEGATIVEEdge.INprevious = __context->UnitDelay_o;
			NEGATIVEEdge(&__context->i2_NEGATIVEEdge);
			// Assign outputs
			goto l159;
		//assert(false);
		return;  			}
	l159: {
			__context->temp1 = __context->i2_NEGATIVEEdge.OUT;
			goto l160;
		//assert(false);
		return;  			}
	l160: {
			__context->FBdec = __context->temp1;
			__context->UnitDelay_ho = __context->UnitDelay_DSTATE_h;
			goto l162;
		//assert(false);
		return;  			}
	l162: {
			// Assign inputs
			__context->i3_NEGATIVEEdge.IN = __context->HFB;
			__context->i3_NEGATIVEEdge.INprevious = __context->UnitDelay_ho;
			NEGATIVEEdge(&__context->i3_NEGATIVEEdge);
			// Assign outputs
			goto l163;
		//assert(false);
		return;  			}
	l163: {
			__context->temp1 = __context->i3_NEGATIVEEdge.OUT;
			goto l164;
		//assert(false);
		return;  			}
	l164: {
			__context->RelationalOperator1_j = __context->temp1;
			__context->Memory_l = __context->Memory_PreviousInput_o;
			goto l166;
		//assert(false);
		return;  			}
	l166: {
			__context->LogicalOperator21 = (__context->FBrise || __context->RelationalOperator1_l);
			__context->LogicalOperator20 = (__context->FBdec || __context->RelationalOperator1_j);
			goto l168;
		//assert(false);
		return;  			}
	l168: {
			__context->temp1 = __context->LogicalOperator21;
			goto l169;
		//assert(false);
		return;  			}
	l169: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_4.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_4);
			// Assign outputs
			__context->rowIdx = BOOL_TO_DINT1_inlined_4.RET_VAL;
			goto l170;
		//assert(false);
		return;  			}
	l170: {
			__context->temp1 = __context->LogicalOperator20;
			goto l171;
		//assert(false);
		return;  			}
	l171: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_5.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_5);
			// Assign outputs
			___nested_ret_val3 = BOOL_TO_DINT1_inlined_5.RET_VAL;
			goto l172;
		//assert(false);
		return;  			}
	l172: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val3);
			__context->temp1 = __context->Memory_l;
			goto l174;
		//assert(false);
		return;  			}
	l174: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_6.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_6);
			// Assign outputs
			___nested_ret_val4 = BOOL_TO_DINT1_inlined_6.RET_VAL;
			goto l175;
		//assert(false);
		return;  			}
	l175: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val4);
			goto l176;
		//assert(false);
		return;  			}
	l176: {
		if (__context->PEUR) {
			goto l177;
		}
		if ((! __context->PEUR)) {
			goto l183;
		}
		//assert(false);
		return;  			}
	l177: {
		if ((__context->PEUH > __context->PEUL)) {
			__context->ir = ((((- (__context->HFV - __context->PEUL)) * (__context->PIH - __context->PIL)) / (__context->PEUH - __context->PEUL)) + __context->PIH);
			goto l182;
		}
		if ((! (__context->PEUH > __context->PEUL))) {
			__context->ir = __context->PIH;
			goto l182;
		}
		//assert(false);
		return;  			}
	l182: {
			goto l189;
		//assert(false);
		return;  			}
	l183: {
		if ((__context->PEUH > __context->PEUL)) {
			__context->ir = ((((__context->HFV - __context->PEUL) * (__context->PIH - __context->PIL)) / (__context->PEUH - __context->PEUL)) + __context->PIL);
			goto l188;
		}
		if ((! (__context->PEUH > __context->PEUL))) {
			__context->ir = __context->PIL;
			goto l188;
		}
		//assert(false);
		return;  			}
	l188: {
			goto l189;
		//assert(false);
		return;  			}
	l189: {
		if ((__context->PIH > __context->PIL)) {
			__context->b_x = ((((__context->ir - __context->PIL) * (__context->PRH - __context->PRL)) / (__context->PIH - __context->PIL)) + __context->PRL);
			goto l194;
		}
		if ((! (__context->PIH > __context->PIL))) {
			__context->b_x = __context->PRL;
			goto l194;
		}
		//assert(false);
		return;  			}
	l194: {
			__context->b_ir = __context->ir;
			__context->Delay5 = __context->Delay5_DSTATE;
			goto l196;
		//assert(false);
		return;  			}
	l196: {
		if ((__context->is_active_c1_MA == 0)) {
			__context->is_active_c1_MA = 1;
			__context->is_Force_Mode = 1;
			__context->blk_mode_p = 1;
			goto l219;
		}
		if ((! (__context->is_active_c1_MA == 0))) {
			goto l201;
		}
		//assert(false);
		return;  			}
	l201: {
		if ((__context->is_Force_Mode == 1)) {
			__context->blk_mode_p = 1;
			goto l205;
		}
		if ((! (__context->is_Force_Mode == 1))) {
			__context->blk_mode_p = 2;
			goto l212;
		}
		//assert(false);
		return;  			}
	l202: {
			goto l219;
		//assert(false);
		return;  			}
	l205: {
		if (__context->HFO) {
			__context->is_Force_Mode = 2;
			__context->blk_mode_p = 2;
			goto l211;
		}
		if ((! __context->HFO)) {
			__context->BF = false;
			goto l211;
		}
		//assert(false);
		return;  			}
	l211: {
			goto l202;
		//assert(false);
		return;  			}
	l212: {
		if ((! __context->HFO)) {
			__context->is_Force_Mode = 1;
			__context->blk_mode_p = 1;
			goto l218;
		}
		if ((! (! __context->HFO))) {
			__context->BF = true;
			goto l218;
		}
		//assert(false);
		return;  			}
	l218: {
			goto l202;
		//assert(false);
		return;  			}
	l219: {
			__context->Delay4 = __context->Delay4_DSTATE;
			goto l220;
		//assert(false);
		return;  			}
	l220: {
		if (__context->BF) {
			goto l221;
		}
		if ((! __context->BF)) {
			__context->b_out = __context->X;
			goto l229;
		}
		//assert(false);
		return;  			}
	l221: {
		if ((__context->b_x != __context->Delay5)) {
			__context->b_out = __context->b_x;
			goto l226;
		}
		if ((! (__context->b_x != __context->Delay5))) {
			__context->b_out = __context->Delay4;
			goto l226;
		}
		//assert(false);
		return;  			}
	l226: {
			goto l229;
		//assert(false);
		return;  			}
	l229: {
		if ((__context->PRH > __context->PRL)) {
			__context->YIR = ((((__context->b_out - __context->PRL) * (__context->PIH - __context->PIL)) / (__context->PRH - __context->PRL)) + __context->PIL);
			goto l234;
		}
		if ((! (__context->PRH > __context->PRL))) {
			__context->YIR = __context->PIL;
			goto l234;
		}
		//assert(false);
		return;  			}
	l234: {
		if (__context->PEUR) {
			goto l235;
		}
		if ((! __context->PEUR)) {
			goto l241;
		}
		//assert(false);
		return;  			}
	l235: {
		if ((__context->PIH > __context->PIL)) {
			__context->egu = ((((- (__context->YIR - __context->PIL)) * (__context->PEUH - __context->PEUL)) / (__context->PIH - __context->PIL)) + __context->PEUH);
			goto l240;
		}
		if ((! (__context->PIH > __context->PIL))) {
			__context->egu = __context->PEUH;
			goto l240;
		}
		//assert(false);
		return;  			}
	l240: {
			goto l247;
		//assert(false);
		return;  			}
	l241: {
		if ((__context->PIH > __context->PIL)) {
			__context->egu = ((((__context->YIR - __context->PIL) * (__context->PEUH - __context->PEUL)) / (__context->PIH - __context->PIL)) + __context->PEUL);
			goto l246;
		}
		if ((! (__context->PIH > __context->PIL))) {
			__context->egu = __context->PEUL;
			goto l246;
		}
		//assert(false);
		return;  			}
	l246: {
			goto l247;
		//assert(false);
		return;  			}
	l247: {
			__context->Gain4 = (0.01 * __context->PSFH);
			goto l248;
		//assert(false);
		return;  			}
	l248: {
			__context->Product2 = (__context->PIH * __context->Gain4);
			goto l249;
		//assert(false);
		return;  			}
	l249: {
			__context->b_Add = (__context->PIH + __context->Product2);
			__context->Gain5 = ((- 0.01) * __context->PSFL);
			goto l251;
		//assert(false);
		return;  			}
	l251: {
			__context->Product3 = (__context->PIL * __context->Gain5);
			goto l252;
		//assert(false);
		return;  			}
	l252: {
			__context->Add1 = (__context->PIL + __context->Product3);
			__context->DIFFTIME = 0.1;
			__context->UnitDelay = __context->UnitDelay_DSTATE;
			goto l255;
		//assert(false);
		return;  			}
	l255: {
		if (((__context->PROC >= (__context->PEUH - __context->PEUL)) || (__context->PROC <= 0.0))) {
			__context->ramp_inc_off = true;
			goto l260;
		}
		if ((! ((__context->PROC >= (__context->PEUH - __context->PEUL)) || (__context->PROC <= 0.0)))) {
			__context->ramp_inc_off = false;
			goto l260;
		}
		//assert(false);
		return;  			}
	l260: {
		if (((__context->PROC >= (__context->PEUH - __context->PEUL)) || (__context->PROC <= 0.0))) {
			__context->ramp_dcr_off = true;
			goto l265;
		}
		if ((! ((__context->PROC >= (__context->PEUH - __context->PEUL)) || (__context->PROC <= 0.0)))) {
			__context->ramp_dcr_off = false;
			goto l265;
		}
		//assert(false);
		return;  			}
	l265: {
		if (__context->ramp_inc_off) {
			__context->incrate = (__context->PEUH - __context->PEUL);
			goto l270;
		}
		if ((! __context->ramp_inc_off)) {
			__context->incrate = (__context->PROC * __context->DIFFTIME);
			goto l270;
		}
		//assert(false);
		return;  			}
	l270: {
		if (__context->ramp_dcr_off) {
			__context->decrate = (__context->PEUH - __context->PEUL);
			goto l275;
		}
		if ((! __context->ramp_dcr_off)) {
			__context->decrate = (__context->PROC * __context->DIFFTIME);
			goto l275;
		}
		//assert(false);
		return;  			}
	l275: {
		if ((__context->egu > __context->UnitDelay)) {
			goto l276;
		}
		if ((! (__context->egu > __context->UnitDelay))) {
			goto l282;
		}
		//assert(false);
		return;  			}
	l276: {
		if ((__context->egu > (__context->UnitDelay + __context->incrate))) {
			__context->b_y = (__context->UnitDelay + __context->incrate);
			goto l281;
		}
		if ((! (__context->egu > (__context->UnitDelay + __context->incrate)))) {
			__context->b_y = __context->egu;
			goto l281;
		}
		//assert(false);
		return;  			}
	l281: {
			goto l288;
		//assert(false);
		return;  			}
	l282: {
		if ((__context->egu < (__context->UnitDelay - __context->decrate))) {
			__context->b_y = (__context->UnitDelay - __context->decrate);
			goto l287;
		}
		if ((! (__context->egu < (__context->UnitDelay - __context->decrate)))) {
			__context->b_y = __context->egu;
			goto l287;
		}
		//assert(false);
		return;  			}
	l287: {
			goto l288;
		//assert(false);
		return;  			}
	l288: {
		if (((__context->b_y < ((((__context->PEUH - __context->PEUL) * 0.01) * __context->PDB) + __context->PEUL)) && (__context->b_y > __context->PEUL))) {
			__context->out_a = __context->PEUL;
			goto l295;
		}
		if (((! ((__context->b_y < ((((__context->PEUH - __context->PEUL) * 0.01) * __context->PDB) + __context->PEUL)) && (__context->b_y > __context->PEUL))) && ((__context->b_y > (__context->PEUH - (((__context->PEUH - __context->PEUL) * 0.01) * __context->PDB))) && (__context->b_y < __context->PEUH)))) {
			__context->out_a = __context->PEUH;
			goto l295;
		}
		if (((! ((__context->b_y < ((((__context->PEUH - __context->PEUL) * 0.01) * __context->PDB) + __context->PEUL)) && (__context->b_y > __context->PEUL))) && (! ((! ((__context->b_y < ((((__context->PEUH - __context->PEUL) * 0.01) * __context->PDB) + __context->PEUL)) && (__context->b_y > __context->PEUL))) && ((__context->b_y > (__context->PEUH - (((__context->PEUH - __context->PEUL) * 0.01) * __context->PDB))) && (__context->b_y < __context->PEUH)))))) {
			__context->out_a = __context->b_y;
			goto l295;
		}
		//assert(false);
		return;  			}
	l295: {
			__context->LowerRelop1 = (__context->out_a > __context->PEUH);
			__context->UpperRelop = (__context->out_a < __context->PEUL);
			goto l297;
		//assert(false);
		return;  			}
	l297: {
		if (__context->UpperRelop) {
			__context->Switch = __context->PEUL;
			goto l302;
		}
		if ((! __context->UpperRelop)) {
			__context->Switch = __context->out_a;
			goto l302;
		}
		//assert(false);
		return;  			}
	l302: {
		if (__context->LowerRelop1) {
			__context->Switch2 = __context->PEUH;
			goto l307;
		}
		if ((! __context->LowerRelop1)) {
			__context->Switch2 = __context->Switch;
			goto l307;
		}
		//assert(false);
		return;  			}
	l307: {
			__context->UnitDelay_nk = __context->UnitDelay_DSTATE_m;
			goto l308;
		//assert(false);
		return;  			}
	l308: {
			// Assign inputs
			__context->i3_POSITIVEEdge.IN = __context->FUHH;
			__context->i3_POSITIVEEdge.INprevious = __context->UnitDelay_nk;
			POSITIVEEdge(&__context->i3_POSITIVEEdge);
			// Assign outputs
			goto l309;
		//assert(false);
		return;  			}
	l309: {
			__context->temp1 = __context->i3_POSITIVEEdge.OUT;
			goto l310;
		//assert(false);
		return;  			}
	l310: {
			__context->FUHHrise = __context->temp1;
			__context->UnitDelay_f = __context->UnitDelay_DSTATE_a;
			goto l312;
		//assert(false);
		return;  			}
	l312: {
			// Assign inputs
			__context->i2_POSITIVEEdge.IN = __context->HFUHH;
			__context->i2_POSITIVEEdge.INprevious = __context->UnitDelay_f;
			POSITIVEEdge(&__context->i2_POSITIVEEdge);
			// Assign outputs
			goto l313;
		//assert(false);
		return;  			}
	l313: {
			__context->temp1 = __context->i2_POSITIVEEdge.OUT;
			goto l314;
		//assert(false);
		return;  			}
	l314: {
			__context->RelationalOperator1_i = __context->temp1;
			__context->UnitDelay_p = __context->UnitDelay_DSTATE_aw;
			goto l316;
		//assert(false);
		return;  			}
	l316: {
			// Assign inputs
			__context->i9_NEGATIVEEdge.IN = __context->FUHH;
			__context->i9_NEGATIVEEdge.INprevious = __context->UnitDelay_p;
			NEGATIVEEdge(&__context->i9_NEGATIVEEdge);
			// Assign outputs
			goto l317;
		//assert(false);
		return;  			}
	l317: {
			__context->temp1 = __context->i9_NEGATIVEEdge.OUT;
			goto l318;
		//assert(false);
		return;  			}
	l318: {
			__context->FUHHdec = __context->temp1;
			__context->UnitDelay_l = __context->UnitDelay_DSTATE_jb;
			goto l320;
		//assert(false);
		return;  			}
	l320: {
			// Assign inputs
			__context->i10_NEGATIVEEdge.IN = __context->HFUHH;
			__context->i10_NEGATIVEEdge.INprevious = __context->UnitDelay_l;
			NEGATIVEEdge(&__context->i10_NEGATIVEEdge);
			// Assign outputs
			goto l321;
		//assert(false);
		return;  			}
	l321: {
			__context->temp1 = __context->i10_NEGATIVEEdge.OUT;
			goto l322;
		//assert(false);
		return;  			}
	l322: {
			__context->RelationalOperator1_g = __context->temp1;
			__context->Memory_m = __context->Memory_PreviousInput_k;
			goto l324;
		//assert(false);
		return;  			}
	l324: {
			__context->LogicalOperator8 = (__context->FUHHrise || __context->RelationalOperator1_i);
			__context->LogicalOperator6 = (__context->FUHHdec || __context->RelationalOperator1_g);
			goto l326;
		//assert(false);
		return;  			}
	l326: {
			__context->temp1 = __context->LogicalOperator8;
			goto l327;
		//assert(false);
		return;  			}
	l327: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_7.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_7);
			// Assign outputs
			__context->rowIdx = BOOL_TO_DINT1_inlined_7.RET_VAL;
			goto l328;
		//assert(false);
		return;  			}
	l328: {
			__context->temp1 = __context->LogicalOperator6;
			goto l329;
		//assert(false);
		return;  			}
	l329: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_8.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_8);
			// Assign outputs
			___nested_ret_val5 = BOOL_TO_DINT1_inlined_8.RET_VAL;
			goto l330;
		//assert(false);
		return;  			}
	l330: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val5);
			__context->temp1 = __context->Memory_m;
			goto l332;
		//assert(false);
		return;  			}
	l332: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_9.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_9);
			// Assign outputs
			___nested_ret_val6 = BOOL_TO_DINT1_inlined_9.RET_VAL;
			goto l333;
		//assert(false);
		return;  			}
	l333: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val6);
			__context->Subtract = (__context->PEUH - __context->PEUL);
			__context->Gain3 = (0.01 * __context->PHYS);
			goto l336;
		//assert(false);
		return;  			}
	l336: {
			__context->Product = (__context->Subtract * __context->Gain3);
			goto l337;
		//assert(false);
		return;  			}
	l337: {
			__context->Sum3 = (__context->PLAHH - __context->Product);
			goto l338;
		//assert(false);
		return;  			}
	l338: {
			__context->RelationalOperator10 = (__context->b_y < __context->Sum3);
			__context->LogicalOperator1 = (! __context->PAHH);
			goto l340;
		//assert(false);
		return;  			}
	l340: {
			__context->LogicalOperator = (__context->RelationalOperator10 || __context->LogicalOperator1);
			__context->RelationalOperator9 = (__context->b_y > __context->PLAHH);
			goto l342;
		//assert(false);
		return;  			}
	l342: {
			__context->Memory_j = __context->Memory_PreviousInput_a;
			__context->temp1 = __context->RelationalOperator9;
			goto l344;
		//assert(false);
		return;  			}
	l344: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_10.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_10);
			// Assign outputs
			__context->rowIdx = BOOL_TO_DINT1_inlined_10.RET_VAL;
			goto l345;
		//assert(false);
		return;  			}
	l345: {
			__context->temp1 = __context->LogicalOperator;
			goto l346;
		//assert(false);
		return;  			}
	l346: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_11.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_11);
			// Assign outputs
			___nested_ret_val7 = BOOL_TO_DINT1_inlined_11.RET_VAL;
			goto l347;
		//assert(false);
		return;  			}
	l347: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val7);
			__context->temp1 = __context->Memory_j;
			goto l349;
		//assert(false);
		return;  			}
	l349: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_12.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_12);
			// Assign outputs
			___nested_ret_val8 = BOOL_TO_DINT1_inlined_12.RET_VAL;
			goto l350;
		//assert(false);
		return;  			}
	l350: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val8);
			__context->UnitDelay_b = __context->UnitDelay_DSTATE_p;
			goto l352;
		//assert(false);
		return;  			}
	l352: {
			// Assign inputs
			__context->i6_POSITIVEEdge.IN = __context->FUWH;
			__context->i6_POSITIVEEdge.INprevious = __context->UnitDelay_b;
			POSITIVEEdge(&__context->i6_POSITIVEEdge);
			// Assign outputs
			goto l353;
		//assert(false);
		return;  			}
	l353: {
			__context->temp1 = __context->i6_POSITIVEEdge.OUT;
			goto l354;
		//assert(false);
		return;  			}
	l354: {
			__context->FUWHrise = __context->temp1;
			__context->UnitDelay_pj = __context->UnitDelay_DSTATE_jl;
			goto l356;
		//assert(false);
		return;  			}
	l356: {
			// Assign inputs
			__context->i5_POSITIVEEdge.IN = __context->HFUWH;
			__context->i5_POSITIVEEdge.INprevious = __context->UnitDelay_pj;
			POSITIVEEdge(&__context->i5_POSITIVEEdge);
			// Assign outputs
			goto l357;
		//assert(false);
		return;  			}
	l357: {
			__context->temp1 = __context->i5_POSITIVEEdge.OUT;
			goto l358;
		//assert(false);
		return;  			}
	l358: {
			__context->RelationalOperator1_e = __context->temp1;
			__context->UnitDelay_oq = __context->UnitDelay_DSTATE_f;
			goto l360;
		//assert(false);
		return;  			}
	l360: {
			// Assign inputs
			__context->i5_NEGATIVEEdge.IN = __context->FUWH;
			__context->i5_NEGATIVEEdge.INprevious = __context->UnitDelay_oq;
			NEGATIVEEdge(&__context->i5_NEGATIVEEdge);
			// Assign outputs
			goto l361;
		//assert(false);
		return;  			}
	l361: {
			__context->temp1 = __context->i5_NEGATIVEEdge.OUT;
			goto l362;
		//assert(false);
		return;  			}
	l362: {
			__context->FUWHdec = __context->temp1;
			__context->UnitDelay_oc = __context->UnitDelay_DSTATE_ft;
			goto l364;
		//assert(false);
		return;  			}
	l364: {
			// Assign inputs
			__context->i6_NEGATIVEEdge.IN = __context->HFUWH;
			__context->i6_NEGATIVEEdge.INprevious = __context->UnitDelay_oc;
			NEGATIVEEdge(&__context->i6_NEGATIVEEdge);
			// Assign outputs
			goto l365;
		//assert(false);
		return;  			}
	l365: {
			__context->temp1 = __context->i6_NEGATIVEEdge.OUT;
			goto l366;
		//assert(false);
		return;  			}
	l366: {
			__context->RelationalOperator1_o = __context->temp1;
			__context->Memory_i = __context->Memory_PreviousInput_a5;
			goto l368;
		//assert(false);
		return;  			}
	l368: {
			__context->LogicalOperator15 = (__context->FUWHrise || __context->RelationalOperator1_e);
			__context->LogicalOperator14 = (__context->FUWHdec || __context->RelationalOperator1_o);
			goto l370;
		//assert(false);
		return;  			}
	l370: {
			__context->temp1 = __context->LogicalOperator15;
			goto l371;
		//assert(false);
		return;  			}
	l371: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_13.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_13);
			// Assign outputs
			__context->rowIdx = BOOL_TO_DINT1_inlined_13.RET_VAL;
			goto l372;
		//assert(false);
		return;  			}
	l372: {
			__context->temp1 = __context->LogicalOperator14;
			goto l373;
		//assert(false);
		return;  			}
	l373: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_14.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_14);
			// Assign outputs
			___nested_ret_val9 = BOOL_TO_DINT1_inlined_14.RET_VAL;
			goto l374;
		//assert(false);
		return;  			}
	l374: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val9);
			__context->temp1 = __context->Memory_i;
			goto l376;
		//assert(false);
		return;  			}
	l376: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_15.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_15);
			// Assign outputs
			___nested_ret_val10 = BOOL_TO_DINT1_inlined_15.RET_VAL;
			goto l377;
		//assert(false);
		return;  			}
	l377: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val10);
			__context->RelationalOperator9_c = (__context->b_y > __context->PLAH);
			__context->Sum3_o = (__context->PLAH - __context->Product);
			goto l380;
		//assert(false);
		return;  			}
	l380: {
			__context->RelationalOperator10_g = (__context->b_y < __context->Sum3_o);
			__context->LogicalOperator1_c = (! __context->PAH);
			goto l382;
		//assert(false);
		return;  			}
	l382: {
			__context->LogicalOperator_g = (__context->RelationalOperator10_g || __context->LogicalOperator1_c);
			__context->Memory_o = __context->Memory_PreviousInput_d;
			__context->temp1 = __context->RelationalOperator9_c;
			goto l385;
		//assert(false);
		return;  			}
	l385: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_16.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_16);
			// Assign outputs
			__context->rowIdx = BOOL_TO_DINT1_inlined_16.RET_VAL;
			goto l386;
		//assert(false);
		return;  			}
	l386: {
			__context->temp1 = __context->LogicalOperator_g;
			goto l387;
		//assert(false);
		return;  			}
	l387: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_17.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_17);
			// Assign outputs
			___nested_ret_val11 = BOOL_TO_DINT1_inlined_17.RET_VAL;
			goto l388;
		//assert(false);
		return;  			}
	l388: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val11);
			__context->temp1 = __context->Memory_o;
			goto l390;
		//assert(false);
		return;  			}
	l390: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_18.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_18);
			// Assign outputs
			___nested_ret_val12 = BOOL_TO_DINT1_inlined_18.RET_VAL;
			goto l391;
		//assert(false);
		return;  			}
	l391: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val12);
			goto l392;
		//assert(false);
		return;  			}
	l392: {
			// Assign inputs
			__context->i0_AlarmwithDelay1.ssMethodType = 3;
			__context->i0_AlarmwithDelay1.b_En = __context->Logic_d[0];
			__context->i0_AlarmwithDelay1.Duration = __context->PTDWA;
			AlarmwithDelay(&__context->i0_AlarmwithDelay1);
			// Assign outputs
			goto l393;
		//assert(false);
		return;  			}
	l393: {
			__context->temp1 = __context->i0_AlarmwithDelay1.Out;
			goto l394;
		//assert(false);
		return;  			}
	l394: {
			__context->Out_d = __context->temp1;
			__context->UnitDelay_gx = __context->UnitDelay_DSTATE_o;
			goto l396;
		//assert(false);
		return;  			}
	l396: {
			// Assign inputs
			__context->i8_POSITIVEEdge.IN = __context->FUWL;
			__context->i8_POSITIVEEdge.INprevious = __context->UnitDelay_gx;
			POSITIVEEdge(&__context->i8_POSITIVEEdge);
			// Assign outputs
			goto l397;
		//assert(false);
		return;  			}
	l397: {
			__context->temp1 = __context->i8_POSITIVEEdge.OUT;
			goto l398;
		//assert(false);
		return;  			}
	l398: {
			__context->FUWLrise = __context->temp1;
			__context->UnitDelay_cr = __context->UnitDelay_DSTATE_g;
			goto l400;
		//assert(false);
		return;  			}
	l400: {
			// Assign inputs
			__context->i7_POSITIVEEdge.IN = __context->HFUWL;
			__context->i7_POSITIVEEdge.INprevious = __context->UnitDelay_cr;
			POSITIVEEdge(&__context->i7_POSITIVEEdge);
			// Assign outputs
			goto l401;
		//assert(false);
		return;  			}
	l401: {
			__context->temp1 = __context->i7_POSITIVEEdge.OUT;
			goto l402;
		//assert(false);
		return;  			}
	l402: {
			__context->RelationalOperator1_d = __context->temp1;
			__context->UnitDelay_h3 = __context->UnitDelay_DSTATE_c3;
			goto l404;
		//assert(false);
		return;  			}
	l404: {
			// Assign inputs
			__context->i7_NEGATIVEEdge.IN = __context->FUWL;
			__context->i7_NEGATIVEEdge.INprevious = __context->UnitDelay_h3;
			NEGATIVEEdge(&__context->i7_NEGATIVEEdge);
			// Assign outputs
			goto l405;
		//assert(false);
		return;  			}
	l405: {
			__context->temp1 = __context->i7_NEGATIVEEdge.OUT;
			goto l406;
		//assert(false);
		return;  			}
	l406: {
			__context->FUWLdec = __context->temp1;
			__context->UnitDelay_ct = __context->UnitDelay_DSTATE_ax;
			goto l408;
		//assert(false);
		return;  			}
	l408: {
			// Assign inputs
			__context->i8_NEGATIVEEdge.IN = __context->HFUWL;
			__context->i8_NEGATIVEEdge.INprevious = __context->UnitDelay_ct;
			NEGATIVEEdge(&__context->i8_NEGATIVEEdge);
			// Assign outputs
			goto l409;
		//assert(false);
		return;  			}
	l409: {
			__context->temp1 = __context->i8_NEGATIVEEdge.OUT;
			goto l410;
		//assert(false);
		return;  			}
	l410: {
			__context->RelationalOperator1_fv = __context->temp1;
			__context->Memory_b = __context->Memory_PreviousInput_dl;
			goto l412;
		//assert(false);
		return;  			}
	l412: {
			__context->LogicalOperator17 = (__context->FUWLrise || __context->RelationalOperator1_d);
			__context->LogicalOperator16 = (__context->FUWLdec || __context->RelationalOperator1_fv);
			goto l414;
		//assert(false);
		return;  			}
	l414: {
			__context->temp1 = __context->LogicalOperator17;
			goto l415;
		//assert(false);
		return;  			}
	l415: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_19.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_19);
			// Assign outputs
			__context->rowIdx = BOOL_TO_DINT1_inlined_19.RET_VAL;
			goto l416;
		//assert(false);
		return;  			}
	l416: {
			__context->temp1 = __context->LogicalOperator16;
			goto l417;
		//assert(false);
		return;  			}
	l417: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_20.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_20);
			// Assign outputs
			___nested_ret_val13 = BOOL_TO_DINT1_inlined_20.RET_VAL;
			goto l418;
		//assert(false);
		return;  			}
	l418: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val13);
			__context->temp1 = __context->Memory_b;
			goto l420;
		//assert(false);
		return;  			}
	l420: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_21.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_21);
			// Assign outputs
			___nested_ret_val14 = BOOL_TO_DINT1_inlined_21.RET_VAL;
			goto l421;
		//assert(false);
		return;  			}
	l421: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val14);
			__context->RelationalOperator10_m = (__context->b_y < __context->PLAL);
			__context->Sum2 = (__context->PLAL + __context->Product);
			goto l424;
		//assert(false);
		return;  			}
	l424: {
			__context->RelationalOperator9_m = (__context->b_y > __context->Sum2);
			__context->LogicalOperator1_o = (! __context->PAL);
			goto l426;
		//assert(false);
		return;  			}
	l426: {
			__context->LogicalOperator_f = (__context->RelationalOperator9_m || __context->LogicalOperator1_o);
			__context->Memory_mx = __context->Memory_PreviousInput_n;
			__context->temp1 = __context->RelationalOperator10_m;
			goto l429;
		//assert(false);
		return;  			}
	l429: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_22.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_22);
			// Assign outputs
			__context->rowIdx = BOOL_TO_DINT1_inlined_22.RET_VAL;
			goto l430;
		//assert(false);
		return;  			}
	l430: {
			__context->temp1 = __context->LogicalOperator_f;
			goto l431;
		//assert(false);
		return;  			}
	l431: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_23.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_23);
			// Assign outputs
			___nested_ret_val15 = BOOL_TO_DINT1_inlined_23.RET_VAL;
			goto l432;
		//assert(false);
		return;  			}
	l432: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val15);
			__context->temp1 = __context->Memory_mx;
			goto l434;
		//assert(false);
		return;  			}
	l434: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_24.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_24);
			// Assign outputs
			___nested_ret_val16 = BOOL_TO_DINT1_inlined_24.RET_VAL;
			goto l435;
		//assert(false);
		return;  			}
	l435: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val16);
			goto l436;
		//assert(false);
		return;  			}
	l436: {
			// Assign inputs
			__context->i1_AlarmwithDelay1.ssMethodType = 3;
			__context->i1_AlarmwithDelay1.b_En = __context->Logic_k[0];
			__context->i1_AlarmwithDelay1.Duration = __context->PTDWA;
			AlarmwithDelay(&__context->i1_AlarmwithDelay1);
			// Assign outputs
			goto l437;
		//assert(false);
		return;  			}
	l437: {
			__context->temp1 = __context->i1_AlarmwithDelay1.Out;
			goto l438;
		//assert(false);
		return;  			}
	l438: {
			__context->out = __context->temp1;
			goto l439;
		//assert(false);
		return;  			}
	l439: {
			// Assign inputs
			__context->i5_Block.ssMethodType = 3;
			__context->i5_Block.OSB = __context->Logic[0];
			Block(&__context->i5_Block);
			// Assign outputs
			goto l440;
		//assert(false);
		return;  			}
	l440: {
			__context->temp1 = __context->i5_Block.BB;
			__context->tmp = __context->i5_Block.blk_mode;
			goto l442;
		//assert(false);
		return;  			}
	l442: {
			__context->blk_mode = __context->tmp;
			__context->b_BB = __context->temp1;
			goto l444;
		//assert(false);
		return;  			}
	l444: {
			// Assign inputs
			__context->i0_Block.ssMethodType = 3;
			__context->i0_Block.OSB = __context->Logic_i[0];
			Block(&__context->i0_Block);
			// Assign outputs
			goto l445;
		//assert(false);
		return;  			}
	l445: {
			__context->BB = __context->i0_Block.BB;
			__context->tmp = __context->i0_Block.blk_mode;
			goto l447;
		//assert(false);
		return;  			}
	l447: {
			__context->blk_mode_mz = __context->tmp;
			__context->LogicalOperator13 = (__context->b_BB || __context->BB);
			__context->RelationalOperator = (__context->PIL >= __context->PIH);
			__context->RelationalOperator1 = (__context->PRL >= __context->PRH);
			__context->RelationalOperator2 = (__context->PEUL >= __context->PEUH);
			goto l452;
		//assert(false);
		return;  			}
	l452: {
		if (__context->LogicalOperator13) {
			__context->YF = false;
			goto l460;
		}
		if ((! __context->LogicalOperator13)) {
			__context->RelationalOperator3 = (__context->YIR < __context->Add1);
			__context->RelationalOperator4 = (__context->YIR > __context->b_Add);
			goto l457;
		}
		//assert(false);
		return;  			}
	l457: {
			__context->LogicalOperator7 = (((((__context->RelationalOperator4 || __context->RelationalOperator3) || __context->XF) || __context->RelationalOperator) || __context->RelationalOperator1) || __context->RelationalOperator2);
			goto l458;
		//assert(false);
		return;  			}
	l458: {
			__context->YF = __context->LogicalOperator7;
			goto l460;
		//assert(false);
		return;  			}
	l460: {
		if (__context->PCLAM) {
			__context->Switch12 = __context->Switch2;
			goto l465;
		}
		if ((! __context->PCLAM)) {
			__context->Switch12 = __context->out_a;
			goto l465;
		}
		//assert(false);
		return;  			}
	l465: {
			__context->Delay1 = __context->Delay1_DSTATE;
			goto l466;
		//assert(false);
		return;  			}
	l466: {
		if (__context->YF) {
			goto l467;
		}
		if ((! __context->YF)) {
			__context->Y = __context->Switch12;
			goto l487;
		}
		//assert(false);
		return;  			}
	l467: {
		if ((__context->PLV == 1)) {
			__context->Y = __context->Delay1;
			goto l468;
		}
		if ((! (__context->PLV == 1))) {
			goto l470;
		}
		//assert(false);
		return;  			}
	l468: {
			goto l487;
		//assert(false);
		return;  			}
	l470: {
		if ((__context->PLV == 2)) {
			__context->Y = __context->PEUH;
			goto l468;
		}
		if ((! (__context->PLV == 2))) {
			goto l473;
		}
		//assert(false);
		return;  			}
	l473: {
		if ((__context->PLV == 3)) {
			__context->Y = __context->PEUL;
			goto l468;
		}
		if ((! (__context->PLV == 3))) {
			goto l476;
		}
		//assert(false);
		return;  			}
	l476: {
		if ((__context->PLV == 4)) {
			__context->Y = __context->Switch12;
			goto l468;
		}
		if ((! (__context->PLV == 4))) {
			goto l479;
		}
		//assert(false);
		return;  			}
	l479: {
		if ((__context->PLV == 5)) {
			__context->Y = __context->PFBV;
			goto l468;
		}
		if ((! (__context->PLV == 5))) {
			__context->Y = __context->Switch12;
			goto l468;
		}
		//assert(false);
		return;  			}
	l487: {
			__context->UnitDelay_k = __context->UnitDelay_DSTATE_ll;
			goto l488;
		//assert(false);
		return;  			}
	l488: {
			// Assign inputs
			__context->i4_POSITIVEEdge.IN = __context->FULL;
			__context->i4_POSITIVEEdge.INprevious = __context->UnitDelay_k;
			POSITIVEEdge(&__context->i4_POSITIVEEdge);
			// Assign outputs
			goto l489;
		//assert(false);
		return;  			}
	l489: {
			__context->temp1 = __context->i4_POSITIVEEdge.OUT;
			goto l490;
		//assert(false);
		return;  			}
	l490: {
			__context->FULLrise = __context->temp1;
			__context->UnitDelay_fu = __context->UnitDelay_DSTATE_mz;
			goto l492;
		//assert(false);
		return;  			}
	l492: {
			// Assign inputs
			__context->i0_POSITIVEEdge.IN = __context->HFULL;
			__context->i0_POSITIVEEdge.INprevious = __context->UnitDelay_fu;
			POSITIVEEdge(&__context->i0_POSITIVEEdge);
			// Assign outputs
			goto l493;
		//assert(false);
		return;  			}
	l493: {
			__context->temp1 = __context->i0_POSITIVEEdge.OUT;
			goto l494;
		//assert(false);
		return;  			}
	l494: {
			__context->RelationalOperator1_b = __context->temp1;
			__context->UnitDelay_m = __context->UnitDelay_DSTATE_cs;
			goto l496;
		//assert(false);
		return;  			}
	l496: {
			// Assign inputs
			__context->i0_NEGATIVEEdge.IN = __context->FULL;
			__context->i0_NEGATIVEEdge.INprevious = __context->UnitDelay_m;
			NEGATIVEEdge(&__context->i0_NEGATIVEEdge);
			// Assign outputs
			goto l497;
		//assert(false);
		return;  			}
	l497: {
			__context->temp1 = __context->i0_NEGATIVEEdge.OUT;
			goto l498;
		//assert(false);
		return;  			}
	l498: {
			__context->FULLdec = __context->temp1;
			__context->UnitDelay_px = __context->UnitDelay_DSTATE_dx;
			goto l500;
		//assert(false);
		return;  			}
	l500: {
			// Assign inputs
			__context->i4_NEGATIVEEdge.IN = __context->HFULL;
			__context->i4_NEGATIVEEdge.INprevious = __context->UnitDelay_px;
			NEGATIVEEdge(&__context->i4_NEGATIVEEdge);
			// Assign outputs
			goto l501;
		//assert(false);
		return;  			}
	l501: {
			__context->temp1 = __context->i4_NEGATIVEEdge.OUT;
			goto l502;
		//assert(false);
		return;  			}
	l502: {
			__context->RelationalOperator1_a = __context->temp1;
			__context->Memory_lu = __context->Memory_PreviousInput_nz;
			goto l504;
		//assert(false);
		return;  			}
	l504: {
			__context->LogicalOperator10 = (__context->FULLrise || __context->RelationalOperator1_b);
			__context->LogicalOperator9 = (__context->FULLdec || __context->RelationalOperator1_a);
			goto l506;
		//assert(false);
		return;  			}
	l506: {
			__context->temp1 = __context->LogicalOperator10;
			goto l507;
		//assert(false);
		return;  			}
	l507: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_25.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_25);
			// Assign outputs
			__context->rowIdx = BOOL_TO_DINT1_inlined_25.RET_VAL;
			goto l508;
		//assert(false);
		return;  			}
	l508: {
			__context->temp1 = __context->LogicalOperator9;
			goto l509;
		//assert(false);
		return;  			}
	l509: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_26.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_26);
			// Assign outputs
			___nested_ret_val17 = BOOL_TO_DINT1_inlined_26.RET_VAL;
			goto l510;
		//assert(false);
		return;  			}
	l510: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val17);
			__context->temp1 = __context->Memory_lu;
			goto l512;
		//assert(false);
		return;  			}
	l512: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_27.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_27);
			// Assign outputs
			___nested_ret_val18 = BOOL_TO_DINT1_inlined_27.RET_VAL;
			goto l513;
		//assert(false);
		return;  			}
	l513: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val18);
			__context->Sum2_d = (__context->PLALL + __context->Product);
			goto l515;
		//assert(false);
		return;  			}
	l515: {
			__context->RelationalOperator9_a = (__context->b_y > __context->Sum2_d);
			__context->LogicalOperator1_f = (! __context->PALL);
			goto l517;
		//assert(false);
		return;  			}
	l517: {
			__context->LogicalOperator_j = (__context->RelationalOperator9_a || __context->LogicalOperator1_f);
			__context->RelationalOperator10_j = (__context->b_y < __context->PLALL);
			goto l519;
		//assert(false);
		return;  			}
	l519: {
			__context->Memory_a = __context->Memory_PreviousInput_g;
			__context->temp1 = __context->RelationalOperator10_j;
			goto l521;
		//assert(false);
		return;  			}
	l521: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_28.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_28);
			// Assign outputs
			__context->rowIdx = BOOL_TO_DINT1_inlined_28.RET_VAL;
			goto l522;
		//assert(false);
		return;  			}
	l522: {
			__context->temp1 = __context->LogicalOperator_j;
			goto l523;
		//assert(false);
		return;  			}
	l523: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_29.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_29);
			// Assign outputs
			___nested_ret_val19 = BOOL_TO_DINT1_inlined_29.RET_VAL;
			goto l524;
		//assert(false);
		return;  			}
	l524: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val19);
			__context->temp1 = __context->Memory_a;
			goto l526;
		//assert(false);
		return;  			}
	l526: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_30.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_30);
			// Assign outputs
			___nested_ret_val20 = BOOL_TO_DINT1_inlined_30.RET_VAL;
			goto l527;
		//assert(false);
		return;  			}
	l527: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val20);
			goto l528;
		//assert(false);
		return;  			}
	l528: {
			// Assign inputs
			__context->i3_Block.ssMethodType = 3;
			__context->i3_Block.OSB = __context->Logic_g[0];
			Block(&__context->i3_Block);
			// Assign outputs
			goto l529;
		//assert(false);
		return;  			}
	l529: {
			__context->BUWH = __context->i3_Block.BB;
			__context->tmp = __context->i3_Block.blk_mode;
			goto l531;
		//assert(false);
		return;  			}
	l531: {
			__context->blk_mode_m = __context->tmp;
			__context->LogicalOperator11 = (__context->BUWH || __context->b_BB);
			goto l533;
		//assert(false);
		return;  			}
	l533: {
			// Assign inputs
			__context->i4_Block.ssMethodType = 3;
			__context->i4_Block.OSB = __context->Logic_c[0];
			Block(&__context->i4_Block);
			// Assign outputs
			goto l534;
		//assert(false);
		return;  			}
	l534: {
			__context->BUWL = __context->i4_Block.BB;
			__context->tmp = __context->i4_Block.blk_mode;
			goto l536;
		//assert(false);
		return;  			}
	l536: {
			__context->blk_mode_l = __context->tmp;
			__context->LogicalOperator12 = (__context->BUWL || __context->b_BB);
			goto l538;
		//assert(false);
		return;  			}
	l538: {
			// Assign inputs
			__context->i1_Block.ssMethodType = 3;
			__context->i1_Block.OSB = __context->Logic_e[0];
			Block(&__context->i1_Block);
			// Assign outputs
			goto l539;
		//assert(false);
		return;  			}
	l539: {
			__context->BUHH = __context->i1_Block.BB;
			__context->tmp = __context->i1_Block.blk_mode;
			goto l541;
		//assert(false);
		return;  			}
	l541: {
			__context->blk_mode_j = __context->tmp;
			__context->LogicalOperator3 = (__context->BUHH || __context->b_BB);
			goto l543;
		//assert(false);
		return;  			}
	l543: {
			// Assign inputs
			__context->i2_Block.ssMethodType = 3;
			__context->i2_Block.OSB = __context->Logic_n[0];
			Block(&__context->i2_Block);
			// Assign outputs
			goto l544;
		//assert(false);
		return;  			}
	l544: {
			__context->BULL = __context->i2_Block.BB;
			__context->tmp = __context->i2_Block.blk_mode;
			goto l546;
		//assert(false);
		return;  			}
	l546: {
			__context->blk_mode_n = __context->tmp;
			__context->LogicalOperator4 = (__context->BULL || __context->b_BB);
			__context->Sum3_e = (__context->PLEHH - __context->Product);
			goto l549;
		//assert(false);
		return;  			}
	l549: {
			__context->RelationalOperator10_jk = (__context->b_y < __context->Sum3_e);
			__context->LogicalOperator1_k = (! __context->PEHH);
			goto l551;
		//assert(false);
		return;  			}
	l551: {
			__context->LogicalOperator_h = (__context->RelationalOperator10_jk || __context->LogicalOperator1_k);
			__context->RelationalOperator9_g = (__context->b_y > __context->PLEHH);
			goto l553;
		//assert(false);
		return;  			}
	l553: {
			__context->Memory_d = __context->Memory_PreviousInput_p;
			__context->temp1 = __context->RelationalOperator9_g;
			goto l555;
		//assert(false);
		return;  			}
	l555: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_31.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_31);
			// Assign outputs
			__context->rowIdx = BOOL_TO_DINT1_inlined_31.RET_VAL;
			goto l556;
		//assert(false);
		return;  			}
	l556: {
			__context->temp1 = __context->LogicalOperator_h;
			goto l557;
		//assert(false);
		return;  			}
	l557: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_32.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_32);
			// Assign outputs
			___nested_ret_val21 = BOOL_TO_DINT1_inlined_32.RET_VAL;
			goto l558;
		//assert(false);
		return;  			}
	l558: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val21);
			__context->temp1 = __context->Memory_d;
			goto l560;
		//assert(false);
		return;  			}
	l560: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_33.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_33);
			// Assign outputs
			___nested_ret_val22 = BOOL_TO_DINT1_inlined_33.RET_VAL;
			goto l561;
		//assert(false);
		return;  			}
	l561: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val22);
			__context->Sum3_l = (__context->PLEH - __context->Product);
			goto l563;
		//assert(false);
		return;  			}
	l563: {
			__context->RelationalOperator10_a = (__context->b_y < __context->Sum3_l);
			__context->LogicalOperator1_l = (! __context->PEH);
			goto l565;
		//assert(false);
		return;  			}
	l565: {
			__context->LogicalOperator_c = (__context->RelationalOperator10_a || __context->LogicalOperator1_l);
			__context->RelationalOperator9_j = (__context->b_y > __context->PLEH);
			goto l567;
		//assert(false);
		return;  			}
	l567: {
			__context->Memory_c = __context->Memory_PreviousInput_j;
			__context->temp1 = __context->RelationalOperator9_j;
			goto l569;
		//assert(false);
		return;  			}
	l569: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_34.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_34);
			// Assign outputs
			__context->rowIdx = BOOL_TO_DINT1_inlined_34.RET_VAL;
			goto l570;
		//assert(false);
		return;  			}
	l570: {
			__context->temp1 = __context->LogicalOperator_c;
			goto l571;
		//assert(false);
		return;  			}
	l571: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_35.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_35);
			// Assign outputs
			___nested_ret_val23 = BOOL_TO_DINT1_inlined_35.RET_VAL;
			goto l572;
		//assert(false);
		return;  			}
	l572: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val23);
			__context->temp1 = __context->Memory_c;
			goto l574;
		//assert(false);
		return;  			}
	l574: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_36.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_36);
			// Assign outputs
			___nested_ret_val24 = BOOL_TO_DINT1_inlined_36.RET_VAL;
			goto l575;
		//assert(false);
		return;  			}
	l575: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val24);
			__context->Sum2_h = (__context->PLEL + __context->Product);
			goto l577;
		//assert(false);
		return;  			}
	l577: {
			__context->RelationalOperator9_o = (__context->b_y > __context->Sum2_h);
			__context->LogicalOperator1_d = (! __context->PEL);
			goto l579;
		//assert(false);
		return;  			}
	l579: {
			__context->LogicalOperator_n = (__context->RelationalOperator9_o || __context->LogicalOperator1_d);
			__context->RelationalOperator10_go = (__context->b_y < __context->PLEL);
			goto l581;
		//assert(false);
		return;  			}
	l581: {
			__context->Memory_jp = __context->Memory_PreviousInput_kk;
			__context->temp1 = __context->RelationalOperator10_go;
			goto l583;
		//assert(false);
		return;  			}
	l583: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_37.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_37);
			// Assign outputs
			__context->rowIdx = BOOL_TO_DINT1_inlined_37.RET_VAL;
			goto l584;
		//assert(false);
		return;  			}
	l584: {
			__context->temp1 = __context->LogicalOperator_n;
			goto l585;
		//assert(false);
		return;  			}
	l585: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_38.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_38);
			// Assign outputs
			___nested_ret_val25 = BOOL_TO_DINT1_inlined_38.RET_VAL;
			goto l586;
		//assert(false);
		return;  			}
	l586: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val25);
			__context->temp1 = __context->Memory_jp;
			goto l588;
		//assert(false);
		return;  			}
	l588: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_39.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_39);
			// Assign outputs
			___nested_ret_val26 = BOOL_TO_DINT1_inlined_39.RET_VAL;
			goto l589;
		//assert(false);
		return;  			}
	l589: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val26);
			__context->Sum2_n = (__context->PLELL + __context->Product);
			goto l591;
		//assert(false);
		return;  			}
	l591: {
			__context->RelationalOperator9_l = (__context->b_y > __context->Sum2_n);
			__context->LogicalOperator1_lj = (! __context->PELL);
			goto l593;
		//assert(false);
		return;  			}
	l593: {
			__context->LogicalOperator_d = (__context->RelationalOperator9_l || __context->LogicalOperator1_lj);
			__context->RelationalOperator10_c = (__context->b_y < __context->PLELL);
			goto l595;
		//assert(false);
		return;  			}
	l595: {
			__context->Memory_la = __context->Memory_PreviousInput_dld;
			__context->temp1 = __context->RelationalOperator10_c;
			goto l597;
		//assert(false);
		return;  			}
	l597: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_40.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_40);
			// Assign outputs
			__context->rowIdx = BOOL_TO_DINT1_inlined_40.RET_VAL;
			goto l598;
		//assert(false);
		return;  			}
	l598: {
			__context->temp1 = __context->LogicalOperator_d;
			goto l599;
		//assert(false);
		return;  			}
	l599: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_41.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_41);
			// Assign outputs
			___nested_ret_val27 = BOOL_TO_DINT1_inlined_41.RET_VAL;
			goto l600;
		//assert(false);
		return;  			}
	l600: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val27);
			__context->temp1 = __context->Memory_la;
			goto l602;
		//assert(false);
		return;  			}
	l602: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_42.in = __context->temp1;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_42);
			// Assign outputs
			___nested_ret_val28 = BOOL_TO_DINT1_inlined_42.RET_VAL;
			goto l603;
		//assert(false);
		return;  			}
	l603: {
			__context->rowIdx = ((__context->rowIdx * 2) + ___nested_ret_val28);
			__context->BU = ((((__context->BUHH || __context->BUWH) || __context->BUWL) || __context->BULL) || __context->b_BB);
			__context->alarm_k = __context->temp1;
			goto l606;
		//assert(false);
		return;  			}
	l606: {
		if (__context->LogicalOperator3) {
			__context->AHH = false;
			goto l611;
		}
		if ((! __context->LogicalOperator3)) {
			__context->AHH = __context->alarm_k;
			goto l611;
		}
		//assert(false);
		return;  			}
	l611: {
			__context->alarm = __context->temp1;
			goto l612;
		//assert(false);
		return;  			}
	l612: {
		if (__context->LogicalOperator4) {
			__context->ALL = false;
			goto l617;
		}
		if ((! __context->LogicalOperator4)) {
			__context->ALL = __context->alarm;
			goto l617;
		}
		//assert(false);
		return;  			}
	l617: {
		if (__context->BB) {
			__context->BHH = false;
			__context->BLL = false;
			goto l624;
		}
		if ((! __context->BB)) {
			__context->BHH = __context->AHH;
			__context->BLL = __context->ALL;
			goto l624;
		}
		//assert(false);
		return;  			}
	l624: {
		if (__context->LogicalOperator11) {
			__context->WH = false;
			goto l629;
		}
		if ((! __context->LogicalOperator11)) {
			__context->WH = __context->Out_d;
			goto l629;
		}
		//assert(false);
		return;  			}
	l629: {
		if (__context->LogicalOperator12) {
			__context->WL = false;
			goto l634;
		}
		if ((! __context->LogicalOperator12)) {
			__context->WL = __context->out;
			goto l634;
		}
		//assert(false);
		return;  			}
	l634: {
			__context->EHH = __context->Logic_iq[0];
			__context->EH = __context->Logic_ap[0];
			__context->EL = __context->Logic_m4[0];
			__context->ELL = __context->Logic_p[0];
			__context->VER = 1001.0;
			__context->UnitDelay_DSTATE_i = __context->FUA;
			__context->UnitDelay_DSTATE_id = __context->HFUA;
			__context->UnitDelay_DSTATE_j = __context->FUA;
			__context->UnitDelay_DSTATE_k = __context->HFUA;
			__context->Memory_PreviousInput = __context->Logic[0];
			__context->UnitDelay_DSTATE_c = __context->FB;
			__context->UnitDelay_DSTATE_l = __context->HFB;
			__context->UnitDelay_DSTATE_d = __context->FB;
			__context->UnitDelay_DSTATE_h = __context->HFB;
			__context->Memory_PreviousInput_o = __context->Logic_i[0];
			__context->Delay5_DSTATE = __context->b_x;
			__context->Delay4_DSTATE = __context->b_out;
			__context->UnitDelay_DSTATE = __context->b_y;
			__context->UnitDelay_DSTATE_m = __context->FUHH;
			__context->UnitDelay_DSTATE_a = __context->HFUHH;
			__context->UnitDelay_DSTATE_aw = __context->FUHH;
			__context->UnitDelay_DSTATE_jb = __context->HFUHH;
			__context->Memory_PreviousInput_k = __context->Logic_e[0];
			__context->Memory_PreviousInput_a = __context->Logic_a[0];
			__context->UnitDelay_DSTATE_p = __context->FUWH;
			__context->UnitDelay_DSTATE_jl = __context->HFUWH;
			__context->UnitDelay_DSTATE_f = __context->FUWH;
			__context->UnitDelay_DSTATE_ft = __context->HFUWH;
			__context->Memory_PreviousInput_a5 = __context->Logic_g[0];
			__context->Memory_PreviousInput_d = __context->Logic_d[0];
			__context->UnitDelay_DSTATE_o = __context->FUWL;
			__context->UnitDelay_DSTATE_g = __context->HFUWL;
			__context->UnitDelay_DSTATE_c3 = __context->FUWL;
			__context->UnitDelay_DSTATE_ax = __context->HFUWL;
			__context->Memory_PreviousInput_dl = __context->Logic_c[0];
			__context->Memory_PreviousInput_n = __context->Logic_k[0];
			__context->Delay1_DSTATE = __context->Y;
			__context->UnitDelay_DSTATE_ll = __context->FULL;
			__context->UnitDelay_DSTATE_mz = __context->HFULL;
			__context->UnitDelay_DSTATE_cs = __context->FULL;
			__context->UnitDelay_DSTATE_dx = __context->HFULL;
			__context->Memory_PreviousInput_nz = __context->Logic_n[0];
			__context->Memory_PreviousInput_g = __context->Logic_m[0];
			__context->Memory_PreviousInput_p = __context->Logic_iq[0];
			__context->Memory_PreviousInput_j = __context->Logic_ap[0];
			__context->Memory_PreviousInput_kk = __context->Logic_m4[0];
			__context->Memory_PreviousInput_dld = __context->Logic_p[0];
			goto l21;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void AlarmwithDelay(__AlarmwithDelay *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init2;
	init2: {
		if ((__context->ssMethodType == 0)) {
			goto l22;
		}
		if ((! (__context->ssMethodType == 0))) {
			goto l3;
		}
		//assert(false);
		return;  			}
	l12: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l22: {
			// Assign inputs
			__context->temporalCounter_i1.timerAction = 1;
			PLC_CODER_TIMER(&__context->temporalCounter_i1);
			// Assign outputs
			goto l41;
		//assert(false);
		return;  			}
	l3: {
		if ((__context->ssMethodType == 3)) {
			goto l7;
		}
		if ((! (__context->ssMethodType == 3))) {
			goto l12;
		}
		//assert(false);
		return;  			}
	l41: {
			__context->is_active_c10_mylib = 0;
			__context->is_c10_mylib = 0;
			goto l12;
		//assert(false);
		return;  			}
	l7: {
		if ((__context->is_active_c10_mylib == 0)) {
			__context->is_active_c10_mylib = 1;
			__context->is_c10_mylib = 1;
			__context->Out = false;
			goto l503;
		}
		if ((! (__context->is_active_c10_mylib == 0))) {
			goto l13;
		}
		//assert(false);
		return;  			}
	l13: {
		if ((__context->is_c10_mylib == 1)) {
			__context->Out = false;
			goto l17;
		}
		if ((! (__context->is_c10_mylib == 1))) {
			goto l16;
		}
		//assert(false);
		return;  			}
	l14: {
			goto l503;
		//assert(false);
		return;  			}
	l16: {
		if ((__context->is_c10_mylib == 2)) {
			__context->Out = false;
			goto l25;
		}
		if ((! (__context->is_c10_mylib == 2))) {
			goto l24;
		}
		//assert(false);
		return;  			}
	l17: {
		if (__context->b_En) {
			__context->is_c10_mylib = 3;
			goto l19;
		}
		if ((! __context->b_En)) {
			goto l222;
		}
		//assert(false);
		return;  			}
	l19: {
			// Assign inputs
			__context->temporalCounter_i1.timerAction = 1;
			PLC_CODER_TIMER(&__context->temporalCounter_i1);
			// Assign outputs
			goto l20;
		//assert(false);
		return;  			}
	l20: {
			goto l222;
		//assert(false);
		return;  			}
	l222: {
			goto l14;
		//assert(false);
		return;  			}
	l24: {
		if ((__context->is_c10_mylib == 3)) {
			__context->Out = false;
			goto l33;
		}
		if ((! (__context->is_c10_mylib == 3))) {
			__context->Out = true;
			goto l44;
		}
		//assert(false);
		return;  			}
	l25: {
		if (__context->b_En) {
			__context->is_c10_mylib = 3;
			goto l27;
		}
		if ((! __context->b_En)) {
			goto l30;
		}
		//assert(false);
		return;  			}
	l27: {
			// Assign inputs
			__context->temporalCounter_i1.timerAction = 1;
			PLC_CODER_TIMER(&__context->temporalCounter_i1);
			// Assign outputs
			goto l28;
		//assert(false);
		return;  			}
	l28: {
			goto l30;
		//assert(false);
		return;  			}
	l30: {
			goto l14;
		//assert(false);
		return;  			}
	l33: {
		if ((! __context->b_En)) {
			__context->is_c10_mylib = 2;
			goto l43;
		}
		if ((! (! __context->b_En))) {
			goto l36;
		}
		//assert(false);
		return;  			}
	l36: {
			// Assign inputs
			__context->temporalCounter_i1.timerAction = 2;
			PLC_CODER_TIMER(&__context->temporalCounter_i1);
			// Assign outputs
			goto l37;
		//assert(false);
		return;  			}
	l37: {
		if (__context->temporalCounter_i1.done) {
			__context->is_c10_mylib = 4;
			__context->Out = true;
			goto l42;
		}
		if ((! __context->temporalCounter_i1.done)) {
			goto l42;
		}
		//assert(false);
		return;  			}
	l42: {
			goto l43;
		//assert(false);
		return;  			}
	l43: {
			goto l14;
		//assert(false);
		return;  			}
	l44: {
		if ((! __context->b_En)) {
			__context->is_c10_mylib = 2;
			__context->Out = false;
			goto l491;
		}
		if ((! (! __context->b_En))) {
			goto l491;
		}
		//assert(false);
		return;  			}
	l491: {
			goto l14;
		//assert(false);
		return;  			}
	l503: {
			goto l12;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void PLC_CODER_TIMER(__PLC_CODER_TIMER *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init3;
	init3: {
		if ((__context->timerAction == 1)) {
			__context->plcTimerExpired = false;
			__context->done = false;
			goto l15;
		}
		if ((! (__context->timerAction == 1))) {
			goto l31;
		}
		//assert(false);
		return;  			}
	l15: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l31: {
		if ((__context->timerAction == 2)) {
			__context->done = __context->plcTimerExpired;
			goto l15;
		}
		if ((! (__context->timerAction == 2))) {
			goto l71;
		}
		//assert(false);
		return;  			}
	l71: {
		if ((__context->timerAction == 3)) {
			__context->done = (! __context->plcTimerExpired);
			goto l15;
		}
		if ((! (__context->timerAction == 3))) {
			goto l15;
		}
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void Block(__Block *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init4;
	init4: {
		if ((__context->ssMethodType == 0)) {
			__context->is_Block_Mode = 0;
			__context->is_active_c8_mylib = 0;
			goto l18;
		}
		if ((! (__context->ssMethodType == 0))) {
			goto l32;
		}
		//assert(false);
		return;  			}
	l18: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	l32: {
		if ((__context->ssMethodType == 3)) {
			goto l6;
		}
		if ((! (__context->ssMethodType == 3))) {
			goto l18;
		}
		//assert(false);
		return;  			}
	l6: {
		if ((__context->is_active_c8_mylib == 0)) {
			__context->is_active_c8_mylib = 1;
			__context->is_Block_Mode = 2;
			__context->blk_mode = 1;
			goto l301;
		}
		if ((! (__context->is_active_c8_mylib == 0))) {
			goto l121;
		}
		//assert(false);
		return;  			}
	l121: {
		if ((__context->is_Block_Mode == 1)) {
			__context->blk_mode = 2;
			goto l161;
		}
		if ((! (__context->is_Block_Mode == 1))) {
			__context->blk_mode = 1;
			goto l231;
		}
		//assert(false);
		return;  			}
	l134: {
			goto l301;
		//assert(false);
		return;  			}
	l161: {
		if ((! __context->OSB)) {
			__context->is_Block_Mode = 2;
			__context->blk_mode = 1;
			goto l223;
		}
		if ((! (! __context->OSB))) {
			__context->BB = true;
			goto l223;
		}
		//assert(false);
		return;  			}
	l223: {
			goto l134;
		//assert(false);
		return;  			}
	l231: {
		if (__context->OSB) {
			__context->is_Block_Mode = 1;
			__context->blk_mode = 2;
			goto l29;
		}
		if ((! __context->OSB)) {
			__context->BB = false;
			goto l29;
		}
		//assert(false);
		return;  			}
	l29: {
			goto l134;
		//assert(false);
		return;  			}
	l301: {
			goto l18;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void POSITIVEEdge(__POSITIVEEdge *__context) {
	// Temporary variables
	int32_t ___nested_ret_val32;
	int32_t ___nested_ret_val33;
	int32_t ___nested_ret_val34;
	
	// Start with initial location
	goto init5;
	init5: {
			___nested_ret_val32 = 0;
			___nested_ret_val33 = 0;
			___nested_ret_val34 = 0;
			goto l111;
		//assert(false);
		return;  			}
	l111: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_43.in = __context->IN;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_43);
			// Assign outputs
			___nested_ret_val32 = BOOL_TO_DINT1_inlined_43.RET_VAL;
			goto l26;
		//assert(false);
		return;  			}
	l26: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_44.in = __context->INprevious;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_44);
			// Assign outputs
			___nested_ret_val34 = BOOL_TO_DINT1_inlined_44.RET_VAL;
			goto l34;
		//assert(false);
		return;  			}
	l34: {
			___nested_ret_val33 = ___nested_ret_val34;
			goto l45;
		//assert(false);
		return;  			}
	l45: {
			__context->OUT = (___nested_ret_val32 > ___nested_ret_val33);
			goto l5;
		//assert(false);
		return;  			}
	l5: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void NEGATIVEEdge(__NEGATIVEEdge *__context) {
	// Temporary variables
	int32_t ___nested_ret_val29;
	int32_t ___nested_ret_val30;
	int32_t ___nested_ret_val31;
	
	// Start with initial location
	goto init6;
	init6: {
			___nested_ret_val29 = 0;
			___nested_ret_val30 = 0;
			___nested_ret_val31 = 0;
			goto l112;
		//assert(false);
		return;  			}
	l112: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_45.in = __context->IN;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_45);
			// Assign outputs
			___nested_ret_val29 = BOOL_TO_DINT1_inlined_45.RET_VAL;
			goto l210;
		//assert(false);
		return;  			}
	l210: {
			// Assign inputs
			BOOL_TO_DINT1_inlined_46.in = __context->INprevious;
			BOOL_TO_DINT(&BOOL_TO_DINT1_inlined_46);
			// Assign outputs
			___nested_ret_val31 = BOOL_TO_DINT1_inlined_46.RET_VAL;
			goto l35;
		//assert(false);
		return;  			}
	l35: {
			___nested_ret_val30 = ___nested_ret_val31;
			goto l46;
		//assert(false);
		return;  			}
	l46: {
			__context->OUT = (___nested_ret_val29 < ___nested_ret_val30);
			goto l55;
		//assert(false);
		return;  			}
	l55: {
		goto __end_of_automaton;
		//assert(false);
		return;  			}
	
	// End of automaton
	__end_of_automaton: ;
}
void BOOL_TO_DINT(__BOOL_TO_DINT *__context) {
	// Temporary variables
	
	// Start with initial location
	goto init7;
	init7: {
		if ((__context->in == true)) {
			__context->RET_VAL = 1;
			goto l511;
		}
		if ((! (__context->in == true))) {
			__context->RET_VAL = 0;
			goto l511;
		}
		//assert(false);
		return;  			}
	l511: {
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
			instance.MA_Method = nondet_int32_t();
			instance.MA_XF = nondet_bool();
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
		assert((!(EoC) || (instance.MA_HFB && ((0 <= instance.CYCLE) && (instance.CYCLE <= 20)))));
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
	BOOL_TO_DINT1.in = false;
	BOOL_TO_DINT1.RET_VAL = 0;
	instance.Inst_MA.ssMethodType = 0;
	instance.Inst_MA.X = 0.0;
	instance.Inst_MA.XF = false;
	instance.Inst_MA.FB = false;
	instance.Inst_MA.FUHH = false;
	instance.Inst_MA.FUWH = false;
	instance.Inst_MA.FUWL = false;
	instance.Inst_MA.FULL = false;
	instance.Inst_MA.FUA = false;
	instance.Inst_MA.HFB = false;
	instance.Inst_MA.HFUHH = false;
	instance.Inst_MA.HFUWH = false;
	instance.Inst_MA.HFUWL = false;
	instance.Inst_MA.HFULL = false;
	instance.Inst_MA.HFUA = false;
	instance.Inst_MA.HFO = false;
	instance.Inst_MA.HFV = 0.0;
	instance.Inst_MA.PLAHH = 0.0;
	instance.Inst_MA.PLAH = 0.0;
	instance.Inst_MA.PLAL = 0.0;
	instance.Inst_MA.PLALL = 0.0;
	instance.Inst_MA.PLEHH = 0.0;
	instance.Inst_MA.PLEH = 0.0;
	instance.Inst_MA.PLEL = 0.0;
	instance.Inst_MA.PLELL = 0.0;
	instance.Inst_MA.PTDAA = 0.0;
	instance.Inst_MA.PTDWA = 0.0;
	instance.Inst_MA.PHYS = 0.0;
	instance.Inst_MA.PEUH = 0.0;
	instance.Inst_MA.PEUL = 0.0;
	instance.Inst_MA.PEUR = false;
	instance.Inst_MA.PLV = 0;
	instance.Inst_MA.PFBV = 0.0;
	instance.Inst_MA.PDB = 0.0;
	instance.Inst_MA.PCLAM = false;
	instance.Inst_MA.PRH = 0.0;
	instance.Inst_MA.PRL = 0.0;
	instance.Inst_MA.PIH = 0.0;
	instance.Inst_MA.PIL = 0.0;
	instance.Inst_MA.PSFH = 0.0;
	instance.Inst_MA.PSFL = 0.0;
	instance.Inst_MA.PROC = 0.0;
	instance.Inst_MA.PAHH = false;
	instance.Inst_MA.PAH = false;
	instance.Inst_MA.PAL = false;
	instance.Inst_MA.PALL = false;
	instance.Inst_MA.PEHH = false;
	instance.Inst_MA.PEH = false;
	instance.Inst_MA.PEL = false;
	instance.Inst_MA.PELL = false;
	instance.Inst_MA.BF = false;
	instance.Inst_MA.Y = 0.0;
	instance.Inst_MA.YIR = 0.0;
	instance.Inst_MA.YF = false;
	instance.Inst_MA.AHH = false;
	instance.Inst_MA.BHH = false;
	instance.Inst_MA.WH = false;
	instance.Inst_MA.WL = false;
	instance.Inst_MA.ALL = false;
	instance.Inst_MA.BLL = false;
	instance.Inst_MA.EHH = false;
	instance.Inst_MA.EH = false;
	instance.Inst_MA.EL = false;
	instance.Inst_MA.ELL = false;
	instance.Inst_MA.BB = false;
	instance.Inst_MA.BUHH = false;
	instance.Inst_MA.BUWH = false;
	instance.Inst_MA.BUWL = false;
	instance.Inst_MA.BULL = false;
	instance.Inst_MA.BU = false;
	instance.Inst_MA.VER = 0.0;
	instance.Inst_MA.Memory_PreviousInput = false;
	instance.Inst_MA.Memory = false;
	instance.Inst_MA.FUArise = false;
	instance.Inst_MA.RelationalOperator1_f = false;
	instance.Inst_MA.LogicalOperator19 = false;
	instance.Inst_MA.FUAdec = false;
	instance.Inst_MA.RelationalOperator1_e1 = false;
	instance.Inst_MA.LogicalOperator18 = false;
	instance.Inst_MA.Memory_PreviousInput_o = false;
	instance.Inst_MA.Memory_l = false;
	instance.Inst_MA.FBrise = false;
	instance.Inst_MA.RelationalOperator1_l = false;
	instance.Inst_MA.LogicalOperator21 = false;
	instance.Inst_MA.FBdec = false;
	instance.Inst_MA.RelationalOperator1_j = false;
	instance.Inst_MA.LogicalOperator20 = false;
	instance.Inst_MA.Gain4 = 0.0;
	instance.Inst_MA.Product2 = 0.0;
	instance.Inst_MA.Gain5 = 0.0;
	instance.Inst_MA.Product3 = 0.0;
	instance.Inst_MA.DIFFTIME = 0.0;
	instance.Inst_MA.out_a = 0.0;
	instance.Inst_MA.LowerRelop1 = false;
	instance.Inst_MA.UpperRelop = false;
	instance.Inst_MA.Memory_PreviousInput_k = false;
	instance.Inst_MA.Memory_m = false;
	instance.Inst_MA.FUHHrise = false;
	instance.Inst_MA.RelationalOperator1_i = false;
	instance.Inst_MA.LogicalOperator8 = false;
	instance.Inst_MA.FUHHdec = false;
	instance.Inst_MA.RelationalOperator1_g = false;
	instance.Inst_MA.LogicalOperator6 = false;
	instance.Inst_MA.Gain3 = 0.0;
	instance.Inst_MA.Subtract = 0.0;
	instance.Inst_MA.Product = 0.0;
	instance.Inst_MA.Sum3 = 0.0;
	instance.Inst_MA.b_y = 0.0;
	instance.Inst_MA.RelationalOperator10 = false;
	instance.Inst_MA.LogicalOperator1 = false;
	instance.Inst_MA.LogicalOperator = false;
	instance.Inst_MA.RelationalOperator9 = false;
	instance.Inst_MA.Memory_PreviousInput_a = false;
	instance.Inst_MA.Memory_j = false;
	instance.Inst_MA.Memory_PreviousInput_a5 = false;
	instance.Inst_MA.Memory_i = false;
	instance.Inst_MA.FUWHrise = false;
	instance.Inst_MA.RelationalOperator1_e = false;
	instance.Inst_MA.LogicalOperator15 = false;
	instance.Inst_MA.FUWHdec = false;
	instance.Inst_MA.RelationalOperator1_o = false;
	instance.Inst_MA.LogicalOperator14 = false;
	instance.Inst_MA.RelationalOperator9_c = false;
	instance.Inst_MA.Sum3_o = 0.0;
	instance.Inst_MA.RelationalOperator10_g = false;
	instance.Inst_MA.LogicalOperator1_c = false;
	instance.Inst_MA.LogicalOperator_g = false;
	instance.Inst_MA.Memory_PreviousInput_d = false;
	instance.Inst_MA.Memory_o = false;
	instance.Inst_MA.Memory_PreviousInput_dl = false;
	instance.Inst_MA.Memory_b = false;
	instance.Inst_MA.FUWLrise = false;
	instance.Inst_MA.RelationalOperator1_d = false;
	instance.Inst_MA.LogicalOperator17 = false;
	instance.Inst_MA.FUWLdec = false;
	instance.Inst_MA.RelationalOperator1_fv = false;
	instance.Inst_MA.LogicalOperator16 = false;
	instance.Inst_MA.RelationalOperator10_m = false;
	instance.Inst_MA.Sum2 = 0.0;
	instance.Inst_MA.RelationalOperator9_m = false;
	instance.Inst_MA.LogicalOperator1_o = false;
	instance.Inst_MA.LogicalOperator_f = false;
	instance.Inst_MA.Memory_PreviousInput_n = false;
	instance.Inst_MA.Memory_mx = false;
	instance.Inst_MA.b_BB = false;
	instance.Inst_MA.LogicalOperator13 = false;
	instance.Inst_MA.RelationalOperator = false;
	instance.Inst_MA.RelationalOperator1 = false;
	instance.Inst_MA.RelationalOperator2 = false;
	instance.Inst_MA.Memory_PreviousInput_nz = false;
	instance.Inst_MA.Memory_lu = false;
	instance.Inst_MA.FULLrise = false;
	instance.Inst_MA.RelationalOperator1_b = false;
	instance.Inst_MA.LogicalOperator10 = false;
	instance.Inst_MA.FULLdec = false;
	instance.Inst_MA.RelationalOperator1_a = false;
	instance.Inst_MA.LogicalOperator9 = false;
	instance.Inst_MA.Sum2_d = 0.0;
	instance.Inst_MA.RelationalOperator9_a = false;
	instance.Inst_MA.LogicalOperator1_f = false;
	instance.Inst_MA.LogicalOperator_j = false;
	instance.Inst_MA.RelationalOperator10_j = false;
	instance.Inst_MA.Memory_PreviousInput_g = false;
	instance.Inst_MA.Memory_a = false;
	instance.Inst_MA.LogicalOperator11 = false;
	instance.Inst_MA.LogicalOperator12 = false;
	instance.Inst_MA.LogicalOperator3 = false;
	instance.Inst_MA.LogicalOperator4 = false;
	instance.Inst_MA.Sum3_e = 0.0;
	instance.Inst_MA.RelationalOperator10_jk = false;
	instance.Inst_MA.LogicalOperator1_k = false;
	instance.Inst_MA.LogicalOperator_h = false;
	instance.Inst_MA.RelationalOperator9_g = false;
	instance.Inst_MA.Memory_PreviousInput_p = false;
	instance.Inst_MA.Memory_d = false;
	instance.Inst_MA.Sum3_l = 0.0;
	instance.Inst_MA.RelationalOperator10_a = false;
	instance.Inst_MA.LogicalOperator1_l = false;
	instance.Inst_MA.LogicalOperator_c = false;
	instance.Inst_MA.RelationalOperator9_j = false;
	instance.Inst_MA.Memory_PreviousInput_j = false;
	instance.Inst_MA.Memory_c = false;
	instance.Inst_MA.Sum2_h = 0.0;
	instance.Inst_MA.RelationalOperator9_o = false;
	instance.Inst_MA.LogicalOperator1_d = false;
	instance.Inst_MA.LogicalOperator_n = false;
	instance.Inst_MA.RelationalOperator10_go = false;
	instance.Inst_MA.Memory_PreviousInput_kk = false;
	instance.Inst_MA.Memory_jp = false;
	instance.Inst_MA.Sum2_n = 0.0;
	instance.Inst_MA.RelationalOperator9_l = false;
	instance.Inst_MA.LogicalOperator1_lj = false;
	instance.Inst_MA.LogicalOperator_d = false;
	instance.Inst_MA.RelationalOperator10_c = false;
	instance.Inst_MA.Memory_PreviousInput_dld = false;
	instance.Inst_MA.Memory_la = false;
	instance.Inst_MA.UnitDelay_DSTATE_i = false;
	instance.Inst_MA.UnitDelay_n = false;
	instance.Inst_MA.UnitDelay_DSTATE_id = false;
	instance.Inst_MA.UnitDelay_c = false;
	instance.Inst_MA.UnitDelay_DSTATE_j = false;
	instance.Inst_MA.UnitDelay_h = false;
	instance.Inst_MA.UnitDelay_DSTATE_k = false;
	instance.Inst_MA.UnitDelay_nm = false;
	instance.Inst_MA.UnitDelay_DSTATE_c = false;
	instance.Inst_MA.UnitDelay_g = false;
	instance.Inst_MA.UnitDelay_DSTATE_l = false;
	instance.Inst_MA.UnitDelay_nz = false;
	instance.Inst_MA.UnitDelay_DSTATE_d = false;
	instance.Inst_MA.UnitDelay_o = false;
	instance.Inst_MA.UnitDelay_DSTATE_h = false;
	instance.Inst_MA.UnitDelay_ho = false;
	instance.Inst_MA.Delay5_DSTATE = 0.0;
	instance.Inst_MA.Delay5 = 0.0;
	instance.Inst_MA.Delay4_DSTATE = 0.0;
	instance.Inst_MA.Delay4 = 0.0;
	instance.Inst_MA.UnitDelay_DSTATE = 0.0;
	instance.Inst_MA.UnitDelay = 0.0;
	instance.Inst_MA.Switch = 0.0;
	instance.Inst_MA.Switch2 = 0.0;
	instance.Inst_MA.UnitDelay_DSTATE_m = false;
	instance.Inst_MA.UnitDelay_nk = false;
	instance.Inst_MA.UnitDelay_DSTATE_a = false;
	instance.Inst_MA.UnitDelay_f = false;
	instance.Inst_MA.UnitDelay_DSTATE_aw = false;
	instance.Inst_MA.UnitDelay_p = false;
	instance.Inst_MA.UnitDelay_DSTATE_jb = false;
	instance.Inst_MA.UnitDelay_l = false;
	instance.Inst_MA.UnitDelay_DSTATE_p = false;
	instance.Inst_MA.UnitDelay_b = false;
	instance.Inst_MA.UnitDelay_DSTATE_jl = false;
	instance.Inst_MA.UnitDelay_pj = false;
	instance.Inst_MA.UnitDelay_DSTATE_f = false;
	instance.Inst_MA.UnitDelay_oq = false;
	instance.Inst_MA.UnitDelay_DSTATE_ft = false;
	instance.Inst_MA.UnitDelay_oc = false;
	instance.Inst_MA.UnitDelay_DSTATE_o = false;
	instance.Inst_MA.UnitDelay_gx = false;
	instance.Inst_MA.UnitDelay_DSTATE_g = false;
	instance.Inst_MA.UnitDelay_cr = false;
	instance.Inst_MA.UnitDelay_DSTATE_c3 = false;
	instance.Inst_MA.UnitDelay_h3 = false;
	instance.Inst_MA.UnitDelay_DSTATE_ax = false;
	instance.Inst_MA.UnitDelay_ct = false;
	instance.Inst_MA.LogicalOperator7 = false;
	instance.Inst_MA.Switch12 = 0.0;
	instance.Inst_MA.Delay1_DSTATE = 0.0;
	instance.Inst_MA.Delay1 = 0.0;
	instance.Inst_MA.UnitDelay_DSTATE_ll = false;
	instance.Inst_MA.UnitDelay_k = false;
	instance.Inst_MA.UnitDelay_DSTATE_mz = false;
	instance.Inst_MA.UnitDelay_fu = false;
	instance.Inst_MA.UnitDelay_DSTATE_cs = false;
	instance.Inst_MA.UnitDelay_m = false;
	instance.Inst_MA.UnitDelay_DSTATE_dx = false;
	instance.Inst_MA.UnitDelay_px = false;
	instance.Inst_MA.alarm_k = false;
	instance.Inst_MA.alarm = false;
	instance.Inst_MA.Out_d = false;
	instance.Inst_MA.out = false;
	instance.Inst_MA.b_ir = 0.0;
	instance.Inst_MA.b_x = 0.0;
	instance.Inst_MA.is_active_c1_MA = 0;
	instance.Inst_MA.is_Force_Mode = 0;
	instance.Inst_MA.blk_mode_p = 0;
	instance.Inst_MA.b_out = 0.0;
	instance.Inst_MA.egu = 0.0;
	instance.Inst_MA.Add1 = 0.0;
	instance.Inst_MA.RelationalOperator3 = false;
	instance.Inst_MA.b_Add = 0.0;
	instance.Inst_MA.RelationalOperator4 = false;
	instance.Inst_MA.blk_mode = 0;
	instance.Inst_MA.blk_mode_mz = 0;
	instance.Inst_MA.blk_mode_m = 0;
	instance.Inst_MA.blk_mode_l = 0;
	instance.Inst_MA.blk_mode_j = 0;
	instance.Inst_MA.blk_mode_n = 0;
	instance.Inst_MA.Logic_d[0] = false;
	instance.Inst_MA.Logic_d[1] = false;
	instance.Inst_MA.Logic_k[0] = false;
	instance.Inst_MA.Logic_k[1] = false;
	instance.Inst_MA.Logic[0] = false;
	instance.Inst_MA.Logic[1] = false;
	instance.Inst_MA.Logic_i[0] = false;
	instance.Inst_MA.Logic_i[1] = false;
	instance.Inst_MA.Logic_g[0] = false;
	instance.Inst_MA.Logic_g[1] = false;
	instance.Inst_MA.Logic_c[0] = false;
	instance.Inst_MA.Logic_c[1] = false;
	instance.Inst_MA.Logic_e[0] = false;
	instance.Inst_MA.Logic_e[1] = false;
	instance.Inst_MA.Logic_n[0] = false;
	instance.Inst_MA.Logic_n[1] = false;
	instance.Inst_MA.Logic_a[0] = false;
	instance.Inst_MA.Logic_a[1] = false;
	instance.Inst_MA.Logic_m[0] = false;
	instance.Inst_MA.Logic_m[1] = false;
	instance.Inst_MA.Logic_iq[0] = false;
	instance.Inst_MA.Logic_iq[1] = false;
	instance.Inst_MA.Logic_ap[0] = false;
	instance.Inst_MA.Logic_ap[1] = false;
	instance.Inst_MA.Logic_m4[0] = false;
	instance.Inst_MA.Logic_m4[1] = false;
	instance.Inst_MA.Logic_p[0] = false;
	instance.Inst_MA.Logic_p[1] = false;
	instance.Inst_MA.Logic_table[0] = false;
	instance.Inst_MA.Logic_table[1] = true;
	instance.Inst_MA.Logic_table[2] = false;
	instance.Inst_MA.Logic_table[3] = false;
	instance.Inst_MA.Logic_table[4] = true;
	instance.Inst_MA.Logic_table[5] = true;
	instance.Inst_MA.Logic_table[6] = false;
	instance.Inst_MA.Logic_table[7] = false;
	instance.Inst_MA.Logic_table[8] = true;
	instance.Inst_MA.Logic_table[9] = false;
	instance.Inst_MA.Logic_table[10] = true;
	instance.Inst_MA.Logic_table[11] = true;
	instance.Inst_MA.Logic_table[12] = false;
	instance.Inst_MA.Logic_table[13] = false;
	instance.Inst_MA.Logic_table[14] = false;
	instance.Inst_MA.Logic_table[15] = false;
	instance.Inst_MA.Logic_table_i[0] = false;
	instance.Inst_MA.Logic_table_i[1] = true;
	instance.Inst_MA.Logic_table_i[2] = false;
	instance.Inst_MA.Logic_table_i[3] = false;
	instance.Inst_MA.Logic_table_i[4] = true;
	instance.Inst_MA.Logic_table_i[5] = true;
	instance.Inst_MA.Logic_table_i[6] = false;
	instance.Inst_MA.Logic_table_i[7] = false;
	instance.Inst_MA.Logic_table_i[8] = true;
	instance.Inst_MA.Logic_table_i[9] = false;
	instance.Inst_MA.Logic_table_i[10] = true;
	instance.Inst_MA.Logic_table_i[11] = true;
	instance.Inst_MA.Logic_table_i[12] = false;
	instance.Inst_MA.Logic_table_i[13] = false;
	instance.Inst_MA.Logic_table_i[14] = false;
	instance.Inst_MA.Logic_table_i[15] = false;
	instance.Inst_MA.Logic_table_d[0] = false;
	instance.Inst_MA.Logic_table_d[1] = true;
	instance.Inst_MA.Logic_table_d[2] = false;
	instance.Inst_MA.Logic_table_d[3] = false;
	instance.Inst_MA.Logic_table_d[4] = true;
	instance.Inst_MA.Logic_table_d[5] = true;
	instance.Inst_MA.Logic_table_d[6] = false;
	instance.Inst_MA.Logic_table_d[7] = false;
	instance.Inst_MA.Logic_table_d[8] = true;
	instance.Inst_MA.Logic_table_d[9] = false;
	instance.Inst_MA.Logic_table_d[10] = true;
	instance.Inst_MA.Logic_table_d[11] = true;
	instance.Inst_MA.Logic_table_d[12] = false;
	instance.Inst_MA.Logic_table_d[13] = false;
	instance.Inst_MA.Logic_table_d[14] = false;
	instance.Inst_MA.Logic_table_d[15] = false;
	instance.Inst_MA.Logic_table_e[0] = false;
	instance.Inst_MA.Logic_table_e[1] = true;
	instance.Inst_MA.Logic_table_e[2] = false;
	instance.Inst_MA.Logic_table_e[3] = false;
	instance.Inst_MA.Logic_table_e[4] = true;
	instance.Inst_MA.Logic_table_e[5] = true;
	instance.Inst_MA.Logic_table_e[6] = false;
	instance.Inst_MA.Logic_table_e[7] = false;
	instance.Inst_MA.Logic_table_e[8] = true;
	instance.Inst_MA.Logic_table_e[9] = false;
	instance.Inst_MA.Logic_table_e[10] = true;
	instance.Inst_MA.Logic_table_e[11] = true;
	instance.Inst_MA.Logic_table_e[12] = false;
	instance.Inst_MA.Logic_table_e[13] = false;
	instance.Inst_MA.Logic_table_e[14] = false;
	instance.Inst_MA.Logic_table_e[15] = false;
	instance.Inst_MA.Logic_table_et[0] = false;
	instance.Inst_MA.Logic_table_et[1] = true;
	instance.Inst_MA.Logic_table_et[2] = false;
	instance.Inst_MA.Logic_table_et[3] = false;
	instance.Inst_MA.Logic_table_et[4] = true;
	instance.Inst_MA.Logic_table_et[5] = true;
	instance.Inst_MA.Logic_table_et[6] = false;
	instance.Inst_MA.Logic_table_et[7] = false;
	instance.Inst_MA.Logic_table_et[8] = true;
	instance.Inst_MA.Logic_table_et[9] = false;
	instance.Inst_MA.Logic_table_et[10] = true;
	instance.Inst_MA.Logic_table_et[11] = true;
	instance.Inst_MA.Logic_table_et[12] = false;
	instance.Inst_MA.Logic_table_et[13] = false;
	instance.Inst_MA.Logic_table_et[14] = false;
	instance.Inst_MA.Logic_table_et[15] = false;
	instance.Inst_MA.Logic_table_ie[0] = false;
	instance.Inst_MA.Logic_table_ie[1] = true;
	instance.Inst_MA.Logic_table_ie[2] = false;
	instance.Inst_MA.Logic_table_ie[3] = false;
	instance.Inst_MA.Logic_table_ie[4] = true;
	instance.Inst_MA.Logic_table_ie[5] = true;
	instance.Inst_MA.Logic_table_ie[6] = false;
	instance.Inst_MA.Logic_table_ie[7] = false;
	instance.Inst_MA.Logic_table_ie[8] = true;
	instance.Inst_MA.Logic_table_ie[9] = false;
	instance.Inst_MA.Logic_table_ie[10] = true;
	instance.Inst_MA.Logic_table_ie[11] = true;
	instance.Inst_MA.Logic_table_ie[12] = false;
	instance.Inst_MA.Logic_table_ie[13] = false;
	instance.Inst_MA.Logic_table_ie[14] = false;
	instance.Inst_MA.Logic_table_ie[15] = false;
	instance.Inst_MA.Logic_table_p[0] = false;
	instance.Inst_MA.Logic_table_p[1] = true;
	instance.Inst_MA.Logic_table_p[2] = false;
	instance.Inst_MA.Logic_table_p[3] = false;
	instance.Inst_MA.Logic_table_p[4] = true;
	instance.Inst_MA.Logic_table_p[5] = true;
	instance.Inst_MA.Logic_table_p[6] = false;
	instance.Inst_MA.Logic_table_p[7] = false;
	instance.Inst_MA.Logic_table_p[8] = true;
	instance.Inst_MA.Logic_table_p[9] = false;
	instance.Inst_MA.Logic_table_p[10] = true;
	instance.Inst_MA.Logic_table_p[11] = true;
	instance.Inst_MA.Logic_table_p[12] = false;
	instance.Inst_MA.Logic_table_p[13] = false;
	instance.Inst_MA.Logic_table_p[14] = false;
	instance.Inst_MA.Logic_table_p[15] = false;
	instance.Inst_MA.Logic_table_c[0] = false;
	instance.Inst_MA.Logic_table_c[1] = true;
	instance.Inst_MA.Logic_table_c[2] = false;
	instance.Inst_MA.Logic_table_c[3] = false;
	instance.Inst_MA.Logic_table_c[4] = true;
	instance.Inst_MA.Logic_table_c[5] = true;
	instance.Inst_MA.Logic_table_c[6] = false;
	instance.Inst_MA.Logic_table_c[7] = false;
	instance.Inst_MA.Logic_table_c[8] = true;
	instance.Inst_MA.Logic_table_c[9] = false;
	instance.Inst_MA.Logic_table_c[10] = true;
	instance.Inst_MA.Logic_table_c[11] = true;
	instance.Inst_MA.Logic_table_c[12] = false;
	instance.Inst_MA.Logic_table_c[13] = false;
	instance.Inst_MA.Logic_table_c[14] = false;
	instance.Inst_MA.Logic_table_c[15] = false;
	instance.Inst_MA.Logic_table_j[0] = false;
	instance.Inst_MA.Logic_table_j[1] = true;
	instance.Inst_MA.Logic_table_j[2] = false;
	instance.Inst_MA.Logic_table_j[3] = false;
	instance.Inst_MA.Logic_table_j[4] = true;
	instance.Inst_MA.Logic_table_j[5] = true;
	instance.Inst_MA.Logic_table_j[6] = false;
	instance.Inst_MA.Logic_table_j[7] = false;
	instance.Inst_MA.Logic_table_j[8] = true;
	instance.Inst_MA.Logic_table_j[9] = false;
	instance.Inst_MA.Logic_table_j[10] = true;
	instance.Inst_MA.Logic_table_j[11] = true;
	instance.Inst_MA.Logic_table_j[12] = false;
	instance.Inst_MA.Logic_table_j[13] = false;
	instance.Inst_MA.Logic_table_j[14] = false;
	instance.Inst_MA.Logic_table_j[15] = false;
	instance.Inst_MA.Logic_table_do[0] = false;
	instance.Inst_MA.Logic_table_do[1] = true;
	instance.Inst_MA.Logic_table_do[2] = false;
	instance.Inst_MA.Logic_table_do[3] = false;
	instance.Inst_MA.Logic_table_do[4] = true;
	instance.Inst_MA.Logic_table_do[5] = true;
	instance.Inst_MA.Logic_table_do[6] = false;
	instance.Inst_MA.Logic_table_do[7] = false;
	instance.Inst_MA.Logic_table_do[8] = true;
	instance.Inst_MA.Logic_table_do[9] = false;
	instance.Inst_MA.Logic_table_do[10] = true;
	instance.Inst_MA.Logic_table_do[11] = true;
	instance.Inst_MA.Logic_table_do[12] = false;
	instance.Inst_MA.Logic_table_do[13] = false;
	instance.Inst_MA.Logic_table_do[14] = false;
	instance.Inst_MA.Logic_table_do[15] = false;
	instance.Inst_MA.Logic_table_g[0] = false;
	instance.Inst_MA.Logic_table_g[1] = true;
	instance.Inst_MA.Logic_table_g[2] = false;
	instance.Inst_MA.Logic_table_g[3] = false;
	instance.Inst_MA.Logic_table_g[4] = true;
	instance.Inst_MA.Logic_table_g[5] = true;
	instance.Inst_MA.Logic_table_g[6] = false;
	instance.Inst_MA.Logic_table_g[7] = false;
	instance.Inst_MA.Logic_table_g[8] = true;
	instance.Inst_MA.Logic_table_g[9] = false;
	instance.Inst_MA.Logic_table_g[10] = true;
	instance.Inst_MA.Logic_table_g[11] = true;
	instance.Inst_MA.Logic_table_g[12] = false;
	instance.Inst_MA.Logic_table_g[13] = false;
	instance.Inst_MA.Logic_table_g[14] = false;
	instance.Inst_MA.Logic_table_g[15] = false;
	instance.Inst_MA.Logic_table_iy[0] = false;
	instance.Inst_MA.Logic_table_iy[1] = true;
	instance.Inst_MA.Logic_table_iy[2] = false;
	instance.Inst_MA.Logic_table_iy[3] = false;
	instance.Inst_MA.Logic_table_iy[4] = true;
	instance.Inst_MA.Logic_table_iy[5] = true;
	instance.Inst_MA.Logic_table_iy[6] = false;
	instance.Inst_MA.Logic_table_iy[7] = false;
	instance.Inst_MA.Logic_table_iy[8] = true;
	instance.Inst_MA.Logic_table_iy[9] = false;
	instance.Inst_MA.Logic_table_iy[10] = true;
	instance.Inst_MA.Logic_table_iy[11] = true;
	instance.Inst_MA.Logic_table_iy[12] = false;
	instance.Inst_MA.Logic_table_iy[13] = false;
	instance.Inst_MA.Logic_table_iy[14] = false;
	instance.Inst_MA.Logic_table_iy[15] = false;
	instance.Inst_MA.Logic_table_m[0] = false;
	instance.Inst_MA.Logic_table_m[1] = true;
	instance.Inst_MA.Logic_table_m[2] = false;
	instance.Inst_MA.Logic_table_m[3] = false;
	instance.Inst_MA.Logic_table_m[4] = true;
	instance.Inst_MA.Logic_table_m[5] = true;
	instance.Inst_MA.Logic_table_m[6] = false;
	instance.Inst_MA.Logic_table_m[7] = false;
	instance.Inst_MA.Logic_table_m[8] = true;
	instance.Inst_MA.Logic_table_m[9] = false;
	instance.Inst_MA.Logic_table_m[10] = true;
	instance.Inst_MA.Logic_table_m[11] = true;
	instance.Inst_MA.Logic_table_m[12] = false;
	instance.Inst_MA.Logic_table_m[13] = false;
	instance.Inst_MA.Logic_table_m[14] = false;
	instance.Inst_MA.Logic_table_m[15] = false;
	instance.Inst_MA.Logic_table_n[0] = false;
	instance.Inst_MA.Logic_table_n[1] = true;
	instance.Inst_MA.Logic_table_n[2] = false;
	instance.Inst_MA.Logic_table_n[3] = false;
	instance.Inst_MA.Logic_table_n[4] = true;
	instance.Inst_MA.Logic_table_n[5] = true;
	instance.Inst_MA.Logic_table_n[6] = false;
	instance.Inst_MA.Logic_table_n[7] = false;
	instance.Inst_MA.Logic_table_n[8] = true;
	instance.Inst_MA.Logic_table_n[9] = false;
	instance.Inst_MA.Logic_table_n[10] = true;
	instance.Inst_MA.Logic_table_n[11] = true;
	instance.Inst_MA.Logic_table_n[12] = false;
	instance.Inst_MA.Logic_table_n[13] = false;
	instance.Inst_MA.Logic_table_n[14] = false;
	instance.Inst_MA.Logic_table_n[15] = false;
	instance.Inst_MA.i0_AlarmwithDelay1.ssMethodType = 0;
	instance.Inst_MA.i0_AlarmwithDelay1.b_En = false;
	instance.Inst_MA.i0_AlarmwithDelay1.Duration = 0.0;
	instance.Inst_MA.i0_AlarmwithDelay1.Out = false;
	instance.Inst_MA.i0_AlarmwithDelay1.is_active_c10_mylib = 0;
	instance.Inst_MA.i0_AlarmwithDelay1.is_c10_mylib = 0;
	instance.Inst_MA.i0_AlarmwithDelay1.temporalCounter_i1.timerAction = 0;
	instance.Inst_MA.i0_AlarmwithDelay1.temporalCounter_i1.done = false;
	instance.Inst_MA.i0_AlarmwithDelay1.temporalCounter_i1.plcTimerExpired = false;
	instance.Inst_MA.i1_AlarmwithDelay1.ssMethodType = 0;
	instance.Inst_MA.i1_AlarmwithDelay1.b_En = false;
	instance.Inst_MA.i1_AlarmwithDelay1.Duration = 0.0;
	instance.Inst_MA.i1_AlarmwithDelay1.Out = false;
	instance.Inst_MA.i1_AlarmwithDelay1.is_active_c10_mylib = 0;
	instance.Inst_MA.i1_AlarmwithDelay1.is_c10_mylib = 0;
	instance.Inst_MA.i1_AlarmwithDelay1.temporalCounter_i1.timerAction = 0;
	instance.Inst_MA.i1_AlarmwithDelay1.temporalCounter_i1.done = false;
	instance.Inst_MA.i1_AlarmwithDelay1.temporalCounter_i1.plcTimerExpired = false;
	instance.Inst_MA.i5_Block.ssMethodType = 0;
	instance.Inst_MA.i5_Block.OSB = false;
	instance.Inst_MA.i5_Block.BB = false;
	instance.Inst_MA.i5_Block.blk_mode = 0;
	instance.Inst_MA.i5_Block.is_active_c8_mylib = 0;
	instance.Inst_MA.i5_Block.is_Block_Mode = 0;
	instance.Inst_MA.i0_Block.ssMethodType = 0;
	instance.Inst_MA.i0_Block.OSB = false;
	instance.Inst_MA.i0_Block.BB = false;
	instance.Inst_MA.i0_Block.blk_mode = 0;
	instance.Inst_MA.i0_Block.is_active_c8_mylib = 0;
	instance.Inst_MA.i0_Block.is_Block_Mode = 0;
	instance.Inst_MA.i3_Block.ssMethodType = 0;
	instance.Inst_MA.i3_Block.OSB = false;
	instance.Inst_MA.i3_Block.BB = false;
	instance.Inst_MA.i3_Block.blk_mode = 0;
	instance.Inst_MA.i3_Block.is_active_c8_mylib = 0;
	instance.Inst_MA.i3_Block.is_Block_Mode = 0;
	instance.Inst_MA.i4_Block.ssMethodType = 0;
	instance.Inst_MA.i4_Block.OSB = false;
	instance.Inst_MA.i4_Block.BB = false;
	instance.Inst_MA.i4_Block.blk_mode = 0;
	instance.Inst_MA.i4_Block.is_active_c8_mylib = 0;
	instance.Inst_MA.i4_Block.is_Block_Mode = 0;
	instance.Inst_MA.i1_Block.ssMethodType = 0;
	instance.Inst_MA.i1_Block.OSB = false;
	instance.Inst_MA.i1_Block.BB = false;
	instance.Inst_MA.i1_Block.blk_mode = 0;
	instance.Inst_MA.i1_Block.is_active_c8_mylib = 0;
	instance.Inst_MA.i1_Block.is_Block_Mode = 0;
	instance.Inst_MA.i2_Block.ssMethodType = 0;
	instance.Inst_MA.i2_Block.OSB = false;
	instance.Inst_MA.i2_Block.BB = false;
	instance.Inst_MA.i2_Block.blk_mode = 0;
	instance.Inst_MA.i2_Block.is_active_c8_mylib = 0;
	instance.Inst_MA.i2_Block.is_Block_Mode = 0;
	instance.Inst_MA.i10_POSITIVEEdge.IN = false;
	instance.Inst_MA.i10_POSITIVEEdge.INprevious = false;
	instance.Inst_MA.i10_POSITIVEEdge.OUT = false;
	instance.Inst_MA.i9_POSITIVEEdge.IN = false;
	instance.Inst_MA.i9_POSITIVEEdge.INprevious = false;
	instance.Inst_MA.i9_POSITIVEEdge.OUT = false;
	instance.Inst_MA.i11_NEGATIVEEdge.IN = false;
	instance.Inst_MA.i11_NEGATIVEEdge.INprevious = false;
	instance.Inst_MA.i11_NEGATIVEEdge.OUT = false;
	instance.Inst_MA.i1_NEGATIVEEdge.IN = false;
	instance.Inst_MA.i1_NEGATIVEEdge.INprevious = false;
	instance.Inst_MA.i1_NEGATIVEEdge.OUT = false;
	instance.Inst_MA.i1_POSITIVEEdge.IN = false;
	instance.Inst_MA.i1_POSITIVEEdge.INprevious = false;
	instance.Inst_MA.i1_POSITIVEEdge.OUT = false;
	instance.Inst_MA.i11_POSITIVEEdge.IN = false;
	instance.Inst_MA.i11_POSITIVEEdge.INprevious = false;
	instance.Inst_MA.i11_POSITIVEEdge.OUT = false;
	instance.Inst_MA.i2_NEGATIVEEdge.IN = false;
	instance.Inst_MA.i2_NEGATIVEEdge.INprevious = false;
	instance.Inst_MA.i2_NEGATIVEEdge.OUT = false;
	instance.Inst_MA.i3_NEGATIVEEdge.IN = false;
	instance.Inst_MA.i3_NEGATIVEEdge.INprevious = false;
	instance.Inst_MA.i3_NEGATIVEEdge.OUT = false;
	instance.Inst_MA.i3_POSITIVEEdge.IN = false;
	instance.Inst_MA.i3_POSITIVEEdge.INprevious = false;
	instance.Inst_MA.i3_POSITIVEEdge.OUT = false;
	instance.Inst_MA.i2_POSITIVEEdge.IN = false;
	instance.Inst_MA.i2_POSITIVEEdge.INprevious = false;
	instance.Inst_MA.i2_POSITIVEEdge.OUT = false;
	instance.Inst_MA.i9_NEGATIVEEdge.IN = false;
	instance.Inst_MA.i9_NEGATIVEEdge.INprevious = false;
	instance.Inst_MA.i9_NEGATIVEEdge.OUT = false;
	instance.Inst_MA.i10_NEGATIVEEdge.IN = false;
	instance.Inst_MA.i10_NEGATIVEEdge.INprevious = false;
	instance.Inst_MA.i10_NEGATIVEEdge.OUT = false;
	instance.Inst_MA.i6_POSITIVEEdge.IN = false;
	instance.Inst_MA.i6_POSITIVEEdge.INprevious = false;
	instance.Inst_MA.i6_POSITIVEEdge.OUT = false;
	instance.Inst_MA.i5_POSITIVEEdge.IN = false;
	instance.Inst_MA.i5_POSITIVEEdge.INprevious = false;
	instance.Inst_MA.i5_POSITIVEEdge.OUT = false;
	instance.Inst_MA.i5_NEGATIVEEdge.IN = false;
	instance.Inst_MA.i5_NEGATIVEEdge.INprevious = false;
	instance.Inst_MA.i5_NEGATIVEEdge.OUT = false;
	instance.Inst_MA.i6_NEGATIVEEdge.IN = false;
	instance.Inst_MA.i6_NEGATIVEEdge.INprevious = false;
	instance.Inst_MA.i6_NEGATIVEEdge.OUT = false;
	instance.Inst_MA.i8_POSITIVEEdge.IN = false;
	instance.Inst_MA.i8_POSITIVEEdge.INprevious = false;
	instance.Inst_MA.i8_POSITIVEEdge.OUT = false;
	instance.Inst_MA.i7_POSITIVEEdge.IN = false;
	instance.Inst_MA.i7_POSITIVEEdge.INprevious = false;
	instance.Inst_MA.i7_POSITIVEEdge.OUT = false;
	instance.Inst_MA.i7_NEGATIVEEdge.IN = false;
	instance.Inst_MA.i7_NEGATIVEEdge.INprevious = false;
	instance.Inst_MA.i7_NEGATIVEEdge.OUT = false;
	instance.Inst_MA.i8_NEGATIVEEdge.IN = false;
	instance.Inst_MA.i8_NEGATIVEEdge.INprevious = false;
	instance.Inst_MA.i8_NEGATIVEEdge.OUT = false;
	instance.Inst_MA.i4_POSITIVEEdge.IN = false;
	instance.Inst_MA.i4_POSITIVEEdge.INprevious = false;
	instance.Inst_MA.i4_POSITIVEEdge.OUT = false;
	instance.Inst_MA.i0_POSITIVEEdge.IN = false;
	instance.Inst_MA.i0_POSITIVEEdge.INprevious = false;
	instance.Inst_MA.i0_POSITIVEEdge.OUT = false;
	instance.Inst_MA.i0_NEGATIVEEdge.IN = false;
	instance.Inst_MA.i0_NEGATIVEEdge.INprevious = false;
	instance.Inst_MA.i0_NEGATIVEEdge.OUT = false;
	instance.Inst_MA.i4_NEGATIVEEdge.IN = false;
	instance.Inst_MA.i4_NEGATIVEEdge.INprevious = false;
	instance.Inst_MA.i4_NEGATIVEEdge.OUT = false;
	instance.Inst_MA.rowIdx = 0;
	instance.Inst_MA.ir = 0.0;
	instance.Inst_MA.incrate = 0.0;
	instance.Inst_MA.decrate = 0.0;
	instance.Inst_MA.ramp_inc_off = false;
	instance.Inst_MA.ramp_dcr_off = false;
	instance.Inst_MA.tmp = 0;
	instance.Inst_MA.temp1 = false;
	instance.MA_Method = 0;
	instance.MA_X = 0.0;
	instance.MA_XF = false;
	instance.MA_FB = false;
	instance.MA_FUHH = false;
	instance.MA_FUWH = false;
	instance.MA_FUWL = false;
	instance.MA_FULL = false;
	instance.MA_FUA = false;
	instance.MA_HFB = false;
	instance.MA_HFUHH = false;
	instance.MA_HFUWH = false;
	instance.MA_HFUWL = false;
	instance.MA_HFULL = false;
	instance.MA_HFUA = false;
	instance.MA_HFO = false;
	instance.MA_HFV = 0.0;
	instance.MA_PLAHH = 0.0;
	instance.MA_PLAH = 0.0;
	instance.MA_PLAL = 0.0;
	instance.MA_PLALL = 0.0;
	instance.MA_PLEHH = 0.0;
	instance.MA_PLEH = 0.0;
	instance.MA_PLEL = 0.0;
	instance.MA_PLELL = 0.0;
	instance.MA_PTDAA = 0.0;
	instance.MA_PTDWA = 0.0;
	instance.MA_PHYS = 0.0;
	instance.MA_PEUH = 0.0;
	instance.MA_PEUL = 0.0;
	instance.MA_PEUR = false;
	instance.MA_PLV = 0;
	instance.MA_PFBV = 0.0;
	instance.MA_PDB = 0.0;
	instance.MA_PCLAM = false;
	instance.MA_PRH = 0.0;
	instance.MA_PRL = 0.0;
	instance.MA_PIH = 0.0;
	instance.MA_PIL = 0.0;
	instance.MA_PSFH = 0.0;
	instance.MA_PSFL = 0.0;
	instance.MA_PROC = 0.0;
	instance.MA_PAHH = false;
	instance.MA_PAH = false;
	instance.MA_PAL = false;
	instance.MA_PALL = false;
	instance.MA_PEHH = false;
	instance.MA_PEH = false;
	instance.MA_PEL = false;
	instance.MA_PELL = false;
	instance.MA_BF = false;
	instance.MA_Y = 0.0;
	instance.MA_YIR = 0.0;
	instance.MA_YF = false;
	instance.MA_AHH = false;
	instance.MA_BHH = false;
	instance.MA_WH = false;
	instance.MA_WL = false;
	instance.MA_ALL = false;
	instance.MA_BLL = false;
	instance.MA_EHH = false;
	instance.MA_EH = false;
	instance.MA_EL = false;
	instance.MA_ELL = false;
	instance.MA_BB = false;
	instance.MA_BUHH = false;
	instance.MA_BUWH = false;
	instance.MA_BUWL = false;
	instance.MA_BULL = false;
	instance.MA_BU = false;
	instance.MA_VER = 0.0;
	instance.CYCLE = 0;
	BOOL_TO_DINT1_inlined_1.in = false;
	BOOL_TO_DINT1_inlined_1.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_2.in = false;
	BOOL_TO_DINT1_inlined_2.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_3.in = false;
	BOOL_TO_DINT1_inlined_3.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_4.in = false;
	BOOL_TO_DINT1_inlined_4.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_5.in = false;
	BOOL_TO_DINT1_inlined_5.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_6.in = false;
	BOOL_TO_DINT1_inlined_6.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_7.in = false;
	BOOL_TO_DINT1_inlined_7.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_8.in = false;
	BOOL_TO_DINT1_inlined_8.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_9.in = false;
	BOOL_TO_DINT1_inlined_9.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_10.in = false;
	BOOL_TO_DINT1_inlined_10.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_11.in = false;
	BOOL_TO_DINT1_inlined_11.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_12.in = false;
	BOOL_TO_DINT1_inlined_12.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_13.in = false;
	BOOL_TO_DINT1_inlined_13.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_14.in = false;
	BOOL_TO_DINT1_inlined_14.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_15.in = false;
	BOOL_TO_DINT1_inlined_15.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_16.in = false;
	BOOL_TO_DINT1_inlined_16.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_17.in = false;
	BOOL_TO_DINT1_inlined_17.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_18.in = false;
	BOOL_TO_DINT1_inlined_18.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_19.in = false;
	BOOL_TO_DINT1_inlined_19.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_20.in = false;
	BOOL_TO_DINT1_inlined_20.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_21.in = false;
	BOOL_TO_DINT1_inlined_21.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_22.in = false;
	BOOL_TO_DINT1_inlined_22.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_23.in = false;
	BOOL_TO_DINT1_inlined_23.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_24.in = false;
	BOOL_TO_DINT1_inlined_24.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_25.in = false;
	BOOL_TO_DINT1_inlined_25.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_26.in = false;
	BOOL_TO_DINT1_inlined_26.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_27.in = false;
	BOOL_TO_DINT1_inlined_27.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_28.in = false;
	BOOL_TO_DINT1_inlined_28.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_29.in = false;
	BOOL_TO_DINT1_inlined_29.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_30.in = false;
	BOOL_TO_DINT1_inlined_30.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_31.in = false;
	BOOL_TO_DINT1_inlined_31.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_32.in = false;
	BOOL_TO_DINT1_inlined_32.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_33.in = false;
	BOOL_TO_DINT1_inlined_33.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_34.in = false;
	BOOL_TO_DINT1_inlined_34.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_35.in = false;
	BOOL_TO_DINT1_inlined_35.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_36.in = false;
	BOOL_TO_DINT1_inlined_36.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_37.in = false;
	BOOL_TO_DINT1_inlined_37.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_38.in = false;
	BOOL_TO_DINT1_inlined_38.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_39.in = false;
	BOOL_TO_DINT1_inlined_39.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_40.in = false;
	BOOL_TO_DINT1_inlined_40.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_41.in = false;
	BOOL_TO_DINT1_inlined_41.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_42.in = false;
	BOOL_TO_DINT1_inlined_42.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_43.in = false;
	BOOL_TO_DINT1_inlined_43.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_44.in = false;
	BOOL_TO_DINT1_inlined_44.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_45.in = false;
	BOOL_TO_DINT1_inlined_45.RET_VAL = 0;
	BOOL_TO_DINT1_inlined_46.in = false;
	BOOL_TO_DINT1_inlined_46.RET_VAL = 0;
	EoC = false;
	
	VerificationLoop();
}

