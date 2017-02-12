#pragma once

#include <vector>
#include <string>
#include <list>
#include <map>

#include "enum.h"

using namespace std;

#define NO_ISSUE -1
#define ERROR -1
#define INVALID_REG -1
#define SUCCESS 0
#define PRINT(x) std::cout << x << std::endl;


class SuperScalar
{
	//Instruction Queue
	struct Instruction
	{
		E_MNEMONICS eMne;
		int op1;
		int op2;
		OP4_SELECT select;
		float op3;
	};
	vector<Instruction> InstQueue;

	vector<float> Memory;
	int m_iProgramCounter;
	int m_iCurrentIssue;
	int m_iPCMax;
	int m_iCycles;
	bool m_bExeComplete;

	struct stROB 
	{
		Instruction Inst;
		int remainingCycles;
		bool hazard;
		float src1;
		bool bsrc1Avail;
		float src2;
		bool bsrc2Avail;
		int PCindex;
		stROB(Instruction l_inst, int l_cycle, bool l_bhazard, int l_pcIndex):Inst(l_inst),remainingCycles(l_cycle),hazard(l_bhazard), PCindex(l_pcIndex)
		{
			bsrc2Avail = false;
			bsrc1Avail = false;
		} 
	};
	list<stROB> listROB;

	map<int, E_PREDICTION> mapBranchPredict;

	struct Reg
	{
		E_BUSY_STATUS eStatus;
		float value;

		Reg() :eStatus(STATUS_FREE), value(0) {}
	};
	vector<Reg> Register;
	
	int m_iCDB;
	//Functional unit  buffers
	int m_iLoadStoreFU;
	int m_iIntFU;
	int m_iFPAdderFU;
	int m_iFPMultiplierFU;
	int m_iMisPrediction;
	E_PREDICTION m_predictType;

public:
	SuperScalar() :Memory(1024), m_iProgramCounter(0), m_iCurrentIssue(NO_ISSUE),
		m_iPCMax(0), Register(16), m_iMisPrediction(0) {}
	int ReadInputFile(string path);
	void Simulate();
	void AddInstruction(string line);
	int issue();
	int Execute();
	int CheckFU(int iPCIndex);
	void IssueToFU();
	void AddMemory(string strLine);
};