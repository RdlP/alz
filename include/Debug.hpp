#ifndef _DEBUG_HEADER
#define _DEBUG_HEADER

#include "types.h"
#include "string.h"
#include "CPU.hpp"
#include <list>
#include <string>
#include <iostream>     // std::cout
#include <sstream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <iomanip>
#include <sstream>

class Debug
{
public:
	Debug(CPU *cpu);
	void runDebug();
	void runProgram();
	void step();
	char* showRegister(BYTE reg);
	void setRegister(BYTE reg, SHORT value);
	void disasm(SHORT address, WORD count);
	void setBreakpoint(SHORT address);
	void removeBreakpoint(SHORT address, bool isAddress);
	char* showBreakpoints();
	void dumpRAM(SHORT address, SHORT count);
	void extraOPDecode();



	//0x00
	void NOP();
	void LDbcnn();
	void LD_bc_a();
	void INCbc();
	void INCb();
	void DECb();
	void LDbn();
	void RLCa();
	void LD_nn_sp();
	void ADDhlbc();
	void LDa_bc_();
	void DECbc();
	void INCc();
	void DECc();
	void LDcn();
	void RRCa();
	//0x10
	void DJNZn();
	void LDdenn();
	void LD_de_a();
	void INCde();
	void INCd();
	void DECd();
	void LDdn();
	void RLa();
	void JRn();
	void ADDhlde();
	void LDa_de_();
	void DECde();
	void INCe();
	void DECe();
	void LDen();
	void RRa();
	//0x20
	void JRNZn();
	void LDhlnn();
	void LDI_hl_a();
	void INChl();
	void INCh();
	void DECh();
	void LDhn();
	void DAA();
	void JRZn();
	void ADDhlhl();
	void LDIa_hl_();
	void DEChl();
	void INCl();
	void DECl();
	void LDln();
	void CPL();
	//0x30
	void JRNCn();
	void LDspnn();
	void LDD_hl_a();
	void INCsp();
	void INC_hl_();
	void DEC_hl_();
	void LD_hl_n();
	void SCF();
	void JRCn();
	void ADDhlsp();
	void LDDa_hl_();
	void DECsp();
	void INCa();
	void DECa();
	void LDan();
	void CCF();
	//0x40
	void LDbb();
	void LDbc();
	void LDbd();
	void LDbe();
	void LDbh();
	void LDbl();
	void LDb_hl_();
	void LDba();
	void LDcb();
	void LDcc();
	void LDcd();
	void LDce();
	void LDch();
	void LDcl();
	void LDc_hl_();
	void LDca();
	//0x50
	void LDdb();
	void LDdc();
	void LDdd();
	void LDde();
	void LDdh();
	void LDdl();
	void LDd_hl_();
	void LDda();
	void LDeb();
	void LDec();
	void LDed();
	void LDee();
	void LDeh();
	void LDel();
	void LDe_hl_();
	void LDea();
	//0x60
	void LDhb();
	void LDhc();
	void LDhd();
	void LDhe();
	void LDhh();
	void LDhl();
	void LDh_hl_();
	void LDha();
	void LDlb();
	void LDlc();
	void LDld();
	void LDle();
	void LDlh();
	void LDll();
	void LDl_hl_();
	void LDla();
	//0x70
	void LD_hl_b();
	void LD_hl_c();
	void LD_hl_d();
	void LD_hl_e();
	void LD_hl_h();
	void LD_hl_l();
	void HALT();
	void LD_hl_a();
	void LDab();
	void LDac();
	void LDad();
	void LDae();
	void LDah();
	void LDal();
	void LDa_hl_();
	void LDaa();
	//0x80
	void ADDab();
	void ADDac();
	void ADDad();
	void ADDae();
	void ADDah();
	void ADDal();
	void ADDa_hl_();
	void ADDaa();
	void ADCab();
	void ADCac();
	void ADCad();
	void ADCae();
	void ADCah();
	void ADCal();
	void ADCa_hl_();
	void ADCaa();
	//0x90
	void SUBab();
	void SUBac();
	void SUBad();
	void SUBae();
	void SUBah();
	void SUBal();
	void SUBa_hl_();
	void SUBaa();
	void SBCab();
	void SBCac();
	void SBCad();
	void SBCae();
	void SBCah();
	void SBCal();
	void SBCa_hl_();
	void SBCaa();
	//0xA0
	void ANDb();
	void ANDc();
	void ANDd();
	void ANDe();
	void ANDh();
	void ANDl();
	void AND_hl_();
	void ANDa();
	void XORb();
	void XORc();
	void XORd();
	void XORe();
	void XORh();
	void XORl();
	void XOR_hl_();
	void XORa();
	//0xB0
	void ORb();
	void ORc();
	void ORd();
	void ORe();
	void ORh();
	void ORl();
	void OR_hl_();
	void ORa();
	void CPb();
	void CPc();
	void CPd();
	void CPe();
	void CPh();
	void CPl();
	void CP_hl_();
	void CPa();
	//0xC0
	void RETNZ();
	void POPbc();
	void JPNZnn();
	void JPnn();
	void CALLNZnn();
	void PUSHbc();
	void ADDan();
	void RST0();
	void RETZ();
	void RET();
	void JPZnn();
	// Extra Ops
	void CALLZnn();
	void CALLnn();
	void ADCan();
	void RST8();
	//0xD0
	void RETNC();
	void POPde();
	void JPNCnn();
	//Not implemented
	void CALLNCnn();
	void PUSHde();
	void SUBan();
	void RST10();
	void RETC();
	void RETI();
	void JPCnn();
	// Not implemented
	void CALLCnn();
	//Not implemented
	void SBCan();
	void RST18();
	//0xE0
	void LDH_n_a();
	void POPhl();
	void LDH_c_a();
	//Not implemented
	//Not implemented
	void PUSHhl();
	void ANDn();
	void RST20();
	void ADDspn();
	void JPhl();
	void LD_nn_a();
	// Not Implemented
	// Not Implemented
	// Not Implemented
	void XORn();
	void RST28();
	//0xF0
	void LDHa_n_();
	void POPaf();
	// Not implemented
	void DI();
	// Not implemented
	void PUSHaf();
	void ORn();
	void RST30();
	void LDHLspn();
	void LDsphl();
	void LDa_nn_();
	void EI();
	// Not implemented
	// Not implemented
	void CPn();
	void RST38();

	// Extended ISA
	void RLCb();
	void RLCc();
	void RLCd();
	void RLCe();
	void RLCh();
	void RLCl();
	void RLC_hl_();
	//RLCa
	void RRCb();
	void RRCc();
	void RRCd();
	void RRCe();
	void RRCh();
	void RRCl();
	void RRC_hl_();
	// RRCa
	//0x10
	void RLb();
	void RLc();
	void RLd();
	void RLe();
	void RLh();
	void RLl();
	void RL_hl_();
	// RLa
	void RRb();
	void RRc();
	void RRd();
	void RRe();
	void RRh();
	void RRl();
	void RR_hl_();
	//RRa
	//0x20
	void SLAb();
	void SLAc();
	void SLAd();
	void SLAe();
	void SLAh();
	void SLAl();
	void SLA_hl_();
	void SLAa();
	void SRAb();
	void SRAc();
	void SRAd();
	void SRAe();
	void SRAh();
	void SRAl();
	void SRA_hl_();
	void SRAa();
	//0x30
	void SWAPb();
	void SWAPc();
	void SWAPd();
	void SWAPe();
	void SWAPh();
	void SWAPl();
	void SWAP_hl_();
	void SWAPa();
	void SLRb();
	void SLRc();
	void SLRd();
	void SLRe();
	void SLRh();
	void SLRl();
	void SLR_hl_();
	void SLRa();
	//0x40
	void BIT0b();
	void BIT0c();
	void BIT0d();
	void BIT0e();
	void BIT0h();
	void BIT0l();
	void BIT0_hl_();
	void BIT0a();
	void BIT1b();
	void BIT1c();
	void BIT1d();
	void BIT1e();
	void BIT1h();
	void BIT1l();
	void BIT1_hl_();
	void BIT1a();
	//0x50
	void BIT2b();
	void BIT2c();
	void BIT2d();
	void BIT2e();
	void BIT2h();
	void BIT2l();
	void BIT2_hl_();
	void BIT2a();
	void BIT3b();
	void BIT3c();
	void BIT3d();
	void BIT3e();
	void BIT3h();
	void BIT3l();
	void BIT3_hl_();
	void BIT3a();
	//0x60
	void BIT4b();
	void BIT4c();
	void BIT4d();
	void BIT4e();
	void BIT4h();
	void BIT4l();
	void BIT4_hl_();
	void BIT4a();
	void BIT5b();
	void BIT5c();
	void BIT5d();
	void BIT5e();
	void BIT5h();
	void BIT5l();
	void BIT5_hl_();
	void BIT5a();
	//0x70
	void BIT6b();
	void BIT6c();
	void BIT6d();
	void BIT6e();
	void BIT6h();
	void BIT6l();
	void BIT6_hl_();
	void BIT6a();
	void BIT7b();
	void BIT7c();
	void BIT7d();
	void BIT7e();
	void BIT7h();
	void BIT7l();
	void BIT7_hl_();
	void BIT7a();
	//0x80
	void RES0b();
	void RES0c();
	void RES0d();
	void RES0e();
	void RES0h();
	void RES0l();
	void RES0_hl_();
	void RES0a();
	void RES1b();
	void RES1c();
	void RES1d();
	void RES1e();
	void RES1h();
	void RES1l();
	void RES1_hl_();
	void RES1a();
	//0x90
	void RES2b();
	void RES2c();
	void RES2d();
	void RES2e();
	void RES2h();
	void RES2l();
	void RES2_hl_();
	void RES2a();
	void RES3b();
	void RES3c();
	void RES3d();
	void RES3e();
	void RES3h();
	void RES3l();
	void RES3_hl_();
	void RES3a();
	//0xA0
	void RES4b();
	void RES4c();
	void RES4d();
	void RES4e();
	void RES4h();
	void RES4l();
	void RES4_hl_();
	void RES4a();
	void RES5b();
	void RES5c();
	void RES5d();
	void RES5e();
	void RES5h();
	void RES5l();
	void RES5_hl_();
	void RES5a();
	//0xB0
	void RES6b();
	void RES6c();
	void RES6d();
	void RES6e();
	void RES6h();
	void RES6l();
	void RES6_hl_();
	void RES6a();
	void RES7b();
	void RES7c();
	void RES7d();
	void RES7e();
	void RES7h();
	void RES7l();
	void RES7_hl_();
	void RES7a();
	//0xC0
	void SET0b();
	void SET0c();
	void SET0d();
	void SET0e();
	void SET0h();
	void SET0l();
	void SET0_hl_();
	void SET0a();
	void SET1b();
	void SET1c();
	void SET1d();
	void SET1e();
	void SET1h();
	void SET1l();
	void SET1_hl_();
	void SET1a();
	//0xD0
	void SET2b();
	void SET2c();
	void SET2d();
	void SET2e();
	void SET2h();
	void SET2l();
	void SET2_hl_();
	void SET2a();
	void SET3b();
	void SET3c();
	void SET3d();
	void SET3e();
	void SET3h();
	void SET3l();
	void SET3_hl_();
	void SET3a();
	//0xE0
	void SET4b();
	void SET4c();
	void SET4d();
	void SET4e();
	void SET4h();
	void SET4l();
	void SET4_hl_();
	void SET4a();
	void SET5b();
	void SET5c();
	void SET5d();
	void SET5e();
	void SET5h();
	void SET5l();
	void SET5_hl_();
	void SET5a();
	//0xF0
	void SET6b();
	void SET6c();
	void SET6d();
	void SET6e();
	void SET6h();
	void SET6l();
	void SET6_hl_();
	void SET6a();
	void SET7b();
	void SET7c();
	void SET7d();
	void SET7e();
	void SET7h();
	void SET7l();
	void SET7_hl_();
	void SET7a();
	
private:
	std::string intToHex(int n, BYTE bits);
	std::string intToHexWithout0x(int n, BYTE bits);
	void IncFakePC();
	std::vector<SHORT> breakpoints;
	CPU *cpu;
	bool finish;
	void (Debug::*bOps[256])();
	void (Debug::*eOps[256])();
	SHORT fakePC;
	IMemory * memory;
	SHORT lastStoppedAddress;
};
#endif