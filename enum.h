#pragma once
//Format of instruction
enum InstructionFormat
{
	MNEMONICS,
	OPERAND_1,
	OPERAND_2,
	OPERAND_3
};

//FU max size
enum FU_MAXSIZE
{
	FU_MAXSIZE_LOADSTORE = 5,
	FU_MAXSIZE_FPADDSUB = 3,
	FU_MAXSIZE_FPMULDIV = 2,
	FU_MAXSIZE_INT = 2,
};

// FU Status
enum FU_STATUS
{
	FU_AVAILABLE,
	FU_BUSY
};

// Cost of operation in cycles
enum COST_OPS_CYCLES
{
	CYCLES_LOAD = 1,
	CYCLES_STR = 3,
	CYCLES_FPADD = 3,
	CYCLES_FPMUL = 5,
	CYCLES_FPDIV = 8,
	CYCLES_ADD = 1,
	CYCLES_BRANCH = 1
};

// All mnemonics in enum
enum E_MNEMONICS
{
	E_LOAD,
	E_STR,
	E_MOV,
	E_FPADD,
	E_FPSUB,
	E_FPMULT,
	E_FPDIV,
	E_ADD,
	E_SUB,
	E_BR,
	E_BGT,
	E_BLT,
	E_BLE,
	E_BGE,
	E_BNEZ,
	E_BZ,
	E_HALT,
};

// opcode 3, select option
enum OP4_SELECT
{
	NUMBER,
	MEMORY,
	REGISTER
};

//Register Status
enum E_BUSY_STATUS
{
	STATUS_BUSY,
	STATUS_FREE
};

//Prediction status
enum E_PREDICTION
{
	STATIC_ALWAYS_TAKEN,
	STATIC_ALWAYS_NOT_TAKEN,
	ONEBIT_START_TAKEN,
	ONEBIT_START_NOT_TAKEN,
	PREDICT_STRONGLY_TAKEN,
	PREDICT_WEAKLY_TAKEN,
	PREDICT_WEAKLY_NOT_TAKEN,
	PREDICT_STRONGLY_NOT_TAKEN
};
