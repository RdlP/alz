#include "CPU.hpp"

CPU::CPU(IMemory *memory): memory(memory)
{
	memset(&bOps, 0, sizeof(bOps));
	memset(&eOps, 0, sizeof(eOps));
	//0x00
	bOps[0] = &CPU::NOP;
	bOps[1] = &CPU::LDbcnn;
	bOps[2] = &CPU::LD_bc_a;
	bOps[3] = &CPU::INCbc;
	bOps[4] = &CPU::INCb;
	bOps[5] = &CPU::DECb;
	bOps[6] = &CPU::LDbn;
	bOps[7] = &CPU::RLCa;
	bOps[8] = &CPU::LD_nn_sp;
	bOps[9] = &CPU::ADDhlbc;
	bOps[10] = &CPU::LDa_bc_;
	bOps[11] = &CPU::DECbc;
	bOps[12] = &CPU::INCc;
	bOps[13] = &CPU::DECc;
	bOps[14] = &CPU::LDcn;
	bOps[15] = &CPU::RRCa;
	//0x10
	bOps[16] = &CPU::DJNZn;
	bOps[17] = &CPU::LDdenn;
	bOps[18] = &CPU::LD_de_a;
	bOps[19] = &CPU::INCde;
	bOps[20] = &CPU::INCd;
	bOps[21] = &CPU::DECd;
	bOps[22] = &CPU::LDdn;
	bOps[23] = &CPU::RLa;
	bOps[24] = &CPU::JRn;
	bOps[25] = &CPU::ADDhlde;
	bOps[26] = &CPU::LDa_de_;
	bOps[27] = &CPU::DECde;
	bOps[28] = &CPU::INCe;
	bOps[29] = &CPU::DECe;
	bOps[30] = &CPU::LDen;
	bOps[31] = &CPU::RRa;
	//0x20
	bOps[32] = &CPU::JRNZn;
	bOps[33] = &CPU::LDhlnn;
	bOps[34] = &CPU::LDI_hl_a;
	bOps[35] = &CPU::INChl;
	bOps[36] = &CPU::INCh;
	bOps[37] = &CPU::DECh;
	bOps[38] = &CPU::LDhn;
	bOps[39] = &CPU::DAA;
	bOps[40] = &CPU::JRZn;
	bOps[41] = &CPU::ADDhlhl;
	bOps[42] = &CPU::LDIa_hl_;
	bOps[43] = &CPU::DEChl;
	bOps[44] = &CPU::INCl;
	bOps[45] = &CPU::DECl;
	bOps[46] = &CPU::LDln;
	bOps[47] = &CPU::CPL;
	//0x30
	bOps[48] = &CPU::JRNCn;
	bOps[49] = &CPU::LDspnn;
	bOps[50] = &CPU::LDD_hl_a;
	bOps[51] = &CPU::INCsp;
	bOps[52] = &CPU::INC_hl_;
	bOps[53] = &CPU::DEC_hl_;
	bOps[54] = &CPU::LD_hl_n;
	bOps[55] = &CPU::SCF;
	bOps[56] = &CPU::JRCn;
	bOps[57] = &CPU::ADDhlsp;
	bOps[58] = &CPU::LDDa_hl_;
	bOps[59] = &CPU::DECsp;
	bOps[60] = &CPU::INCa;
	bOps[61] = &CPU::DECa;
	bOps[62] = &CPU::LDan;
	bOps[63] = &CPU::CCF;
	//0x40
	bOps[64] = &CPU::LDbb;
	bOps[65] = &CPU::LDbc;
	bOps[66] = &CPU::LDbd;
	bOps[67] = &CPU::LDbe;
	bOps[68] = &CPU::LDbh;
	bOps[69] = &CPU::LDbl;
	bOps[70] = &CPU::LDb_hl_;
	bOps[71] = &CPU::LDba;
	bOps[72] = &CPU::LDcb;
	bOps[73] = &CPU::LDcc;
	bOps[74] = &CPU::LDcd;
	bOps[75] = &CPU::LDce;
	bOps[76] = &CPU::LDch;
	bOps[77] = &CPU::LDcl;
	bOps[78] = &CPU::LDc_hl_;
	bOps[79] = &CPU::LDca;
	//0x50
	bOps[80] = &CPU::LDdb;
	bOps[81] = &CPU::LDdc;
	bOps[82] = &CPU::LDdd;
	bOps[83] = &CPU::LDde;
	bOps[84] = &CPU::LDdh;
	bOps[85] = &CPU::LDdl;
	bOps[86] = &CPU::LDd_hl_;
	bOps[87] = &CPU::LDda;
	bOps[88] = &CPU::LDeb;
	bOps[89] = &CPU::LDec;
	bOps[90] = &CPU::LDed;
	bOps[91] = &CPU::LDee;
	bOps[92] = &CPU::LDeh;
	bOps[93] = &CPU::LDel;
	bOps[94] = &CPU::LDe_hl_;
	bOps[95] = &CPU::LDea;
	//0x60
	bOps[96] = &CPU::LDhb;
	bOps[97] = &CPU::LDhc;
	bOps[98] = &CPU::LDhd;
	bOps[99] = &CPU::LDhe;
	bOps[100] = &CPU::LDhh;
	bOps[101] = &CPU::LDhl;
	bOps[102] = &CPU::LDh_hl_;
	bOps[103] = &CPU::LDha;
	bOps[104] = &CPU::LDlb;
	bOps[105] = &CPU::LDlc;
	bOps[106] = &CPU::LDld;
	bOps[107] = &CPU::LDle;
	bOps[108] = &CPU::LDlh;
	bOps[109] = &CPU::LDll;
	bOps[110] = &CPU::LDl_hl_;
	bOps[111] = &CPU::LDla;
	//70
	bOps[112] = &CPU::LD_hl_b;
	bOps[113] = &CPU::LD_hl_c;
	bOps[114] = &CPU::LD_hl_d;
	bOps[115] = &CPU::LD_hl_e;
	bOps[116] = &CPU::LD_hl_h;
	bOps[117] = &CPU::LD_hl_l;
	bOps[118] = &CPU::HALT;
	bOps[119] = &CPU::LD_hl_a;
	bOps[120] = &CPU::LDab;
	bOps[121] = &CPU::LDac;
	bOps[122] = &CPU::LDad;
	bOps[123] = &CPU::LDae;
	bOps[124] = &CPU::LDah;
	bOps[125] = &CPU::LDal;
	bOps[126] = &CPU::LDa_hl_;
	bOps[127] = &CPU::LDaa;
	//0x80
	bOps[128] = &CPU::ADDab;
	bOps[129] = &CPU::ADDac;
	bOps[130] = &CPU::ADDad;
	bOps[131] = &CPU::ADDae;
	bOps[132] = &CPU::ADDah;
	bOps[133] = &CPU::ADDal;
	bOps[134] = &CPU::ADDa_hl_;
	bOps[135] = &CPU::ADDaa;
	bOps[136] = &CPU::ADCab;
	bOps[137] = &CPU::ADCac;
	bOps[138] = &CPU::ADCad;
	bOps[139] = &CPU::ADCae;
	bOps[140] = &CPU::ADCah;
	bOps[141] = &CPU::ADCal;
	bOps[142] = &CPU::ADCa_hl_;
	bOps[143] = &CPU::ADCaa;
	//0x90
	bOps[144] = &CPU::SUBab;
	bOps[145] = &CPU::SUBac;
	bOps[146] = &CPU::SUBad;
	bOps[147] = &CPU::SUBae;
	bOps[148] = &CPU::SUBah;
	bOps[149] = &CPU::SUBal;
	bOps[150] = &CPU::SUBa_hl_;
	bOps[151] = &CPU::SUBaa;
	bOps[152] = &CPU::SBCab;
	bOps[153] = &CPU::SBCac;
	bOps[154] = &CPU::SBCad;
	bOps[155] = &CPU::SBCae;
	bOps[156] = &CPU::SBCah;
	bOps[157] = &CPU::SBCal;
	bOps[158] = &CPU::SBCa_hl_;
	bOps[159] = &CPU::SBCaa;
	//0xA0
	bOps[160] = &CPU::ANDb;
	bOps[161] = &CPU::ANDc;
	bOps[162] = &CPU::ANDd;
	bOps[163] = &CPU::ANDe;
	bOps[164] = &CPU::ANDh;
	bOps[165] = &CPU::ANDl;
	bOps[166] = &CPU::AND_hl_;
	bOps[167] = &CPU::ANDa;
	bOps[168] = &CPU::XORb;
	bOps[169] = &CPU::XORc;
	bOps[170] = &CPU::XORd;
	bOps[171] = &CPU::XORe;
	bOps[172] = &CPU::XORh;
	bOps[173] = &CPU::XORl;
	bOps[174] = &CPU::XOR_hl_;
	bOps[175] = &CPU::XORa;
	//0xB0
	bOps[176] = &CPU::ORb;
	bOps[177] = &CPU::ORc;
	bOps[178] = &CPU::ORd;
	bOps[179] = &CPU::ORe;
	bOps[180] = &CPU::ORh;
	bOps[181] = &CPU::ORl;
	bOps[182] = &CPU::OR_hl_;
	bOps[183] = &CPU::ORa;
	bOps[184] = &CPU::CPb;
	bOps[185] = &CPU::CPc;
	bOps[186] = &CPU::CPd;
	bOps[187] = &CPU::CPe;
	bOps[188] = &CPU::CPh;
	bOps[189] = &CPU::CPl;
	bOps[190] = &CPU::CP_hl_;
	bOps[191] = &CPU::CPa;
	//0xC0
	bOps[192] = &CPU::RETNZ;
	bOps[193] = &CPU::POPbc;
	bOps[194] = &CPU::JPNZnn;
	bOps[195] = &CPU::JPnn;
	bOps[196] = &CPU::CALLNZnn;
	bOps[197] = &CPU::PUSHbc;
	bOps[198] = &CPU::ADDan;
	bOps[199] = &CPU::RST0;
	bOps[200] = &CPU::RETZ;
	bOps[201] = &CPU::RET;
	bOps[202] = &CPU::JPZnn;
	//bOps[203] = &CPU::; Extra Ops
	bOps[204] = &CPU::CALLZnn;
	bOps[205] = &CPU::CALLnn;
	bOps[206] = &CPU::ADCan;
	bOps[207] = &CPU::RST8;
	//0xD0
	bOps[208] = &CPU::RETNC;
	bOps[209] = &CPU::POPde;
	bOps[210] = &CPU::JPNCnn;
	//bOps[211] = &CPU::;
	bOps[212] = &CPU::CALLNCnn;
	bOps[213] = &CPU::PUSHde;
	bOps[214] = &CPU::SUBan;
	bOps[215] = &CPU::RST10;
	bOps[216] = &CPU::RETC;
	bOps[217] = &CPU::RETI;
	bOps[218] = &CPU::JPCnn;
	bOps[219] = &CPU::decodeCB; //Extra ops
	bOps[220] = &CPU::CALLCnn;
	//bOps[221] = &CPU::;
	bOps[222] = &CPU::SBCan;
	bOps[223] = &CPU::RST18;
	//0xE0
	bOps[224] = &CPU::LDH_n_a;
	bOps[225] = &CPU::POPhl;
	bOps[226] = &CPU::LDH_c_a;
	//bOps[227] = &CPU::;
	//bOps[228] = &CPU::;
	bOps[229] = &CPU::PUSHhl;
	bOps[230] = &CPU::ANDn;
	bOps[231] = &CPU::RST20;
	bOps[232] = &CPU::ADDspn;
	bOps[233] = &CPU::JPhl;
	bOps[234] = &CPU::LD_nn_a;
	//bOps[235] = &CPU::;
	//bOps[236] = &CPU::;
	//bOps[237] = &CPU::;
	bOps[238] = &CPU::XORn;
	bOps[239] = &CPU::RST28;
	//0xF0
	bOps[240] = &CPU::LDHa_n_;
	bOps[241] = &CPU::POPaf;
	//bOps[242] = &CPU::;
	bOps[243] = &CPU::DI;
	//bOps[244] = &CPU::;
	bOps[245] = &CPU::PUSHaf;
	bOps[246] = &CPU::ORn;
	bOps[247] = &CPU::RST30;
	bOps[248] = &CPU::LDHLspn;
	bOps[249] = &CPU::LDsphl;
	bOps[250] = &CPU::LDa_nn_;
	bOps[251] = &CPU::EI;
	//bOps[252] = &CPU::;
	//bOps[253] = &CPU::;
	bOps[254] = &CPU::CPn;
	bOps[255] = &CPU::RST38;


	eOps[0] = &CPU::RLCb;
	eOps[1] = &CPU::RLCc;
	eOps[2] = &CPU::RLCd;
	eOps[3] = &CPU::RLCe;
	eOps[4] = &CPU::RLCh;
	eOps[5] = &CPU::RLCl;
	eOps[6] = &CPU::RLC_hl_;
	eOps[7] = &CPU::RLCa;
	eOps[8] = &CPU::RRCb;
	eOps[9] = &CPU::RRCc;
	eOps[10] = &CPU::RRCd;
	eOps[11] = &CPU::RRCe;
	eOps[12] = &CPU::RRCh;
	eOps[13] = &CPU::RRCl;
	eOps[14] = &CPU::RRC_hl_;
	eOps[15] = &CPU::RRCa;
	//0x10
	eOps[16] = &CPU::RLb;
	eOps[17] = &CPU::RLc;
	eOps[18] = &CPU::RLd;
	eOps[19] = &CPU::RLe;
	eOps[20] = &CPU::RLh;
	eOps[21] = &CPU::RLl;
	eOps[22] = &CPU::RL_hl_;
	eOps[23] = &CPU::RLa;
	eOps[24] = &CPU::RRb;
	eOps[25] = &CPU::RRc;
	eOps[26] = &CPU::RRd;
	eOps[27] = &CPU::RRe;
	eOps[28] = &CPU::RRh;
	eOps[29] = &CPU::RRl;
	eOps[30] = &CPU::RR_hl_;
	eOps[31] = &CPU::RRa;
	//0x20
	eOps[32] = &CPU::SLAb;
	eOps[33] = &CPU::SLAc;
	eOps[34] = &CPU::SLAd;
	eOps[35] = &CPU::SLAe;
	eOps[36] = &CPU::SLAh;
	eOps[37] = &CPU::SLAl;
	eOps[38] = &CPU::SLA_hl_;
	eOps[39] = &CPU::SLAa;
	eOps[40] = &CPU::SRAb;
	eOps[41] = &CPU::SRAc;
	eOps[42] = &CPU::SRAd;
	eOps[43] = &CPU::SRAe;
	eOps[44] = &CPU::SRAh;
	eOps[45] = &CPU::SRAl;
	eOps[46] = &CPU::SRA_hl_;
	eOps[47] = &CPU::SRAa;
	//0x30
	eOps[48] = &CPU::SWAPb;
	eOps[49] = &CPU::SWAPc;
	eOps[50] = &CPU::SWAPd;
	eOps[51] = &CPU::SWAPe;
	eOps[52] = &CPU::SWAPh;
	eOps[53] = &CPU::SWAPl;
	eOps[54] = &CPU::SWAP_hl_;
	eOps[55] = &CPU::SWAPa;
	eOps[56] = &CPU::SLRb;
	eOps[57] = &CPU::SLRc;
	eOps[58] = &CPU::SLRd;
	eOps[59] = &CPU::SLRe;
	eOps[60] = &CPU::SLRh;
	eOps[61] = &CPU::SLRl;
	eOps[62] = &CPU::SLR_hl_;
	eOps[63] = &CPU::SLRa;
	//0x40
	eOps[64] = &CPU::BIT0b;
	eOps[65] = &CPU::BIT0c;
	eOps[66] = &CPU::BIT0d;
	eOps[67] = &CPU::BIT0e;
	eOps[68] = &CPU::BIT0h;
	eOps[69] = &CPU::BIT0l;
	eOps[70] = &CPU::BIT0_hl_;
	eOps[71] = &CPU::BIT0a;
	eOps[72] = &CPU::BIT1b;
	eOps[73] = &CPU::BIT1c;
	eOps[74] = &CPU::BIT1d;
	eOps[75] = &CPU::BIT1e;
	eOps[76] = &CPU::BIT1h;
	eOps[77] = &CPU::BIT1l;
	eOps[78] = &CPU::BIT1_hl_;
	eOps[79] = &CPU::BIT1a;
	//0x50
	eOps[80] = &CPU::BIT2b;
	eOps[81] = &CPU::BIT2c;
	eOps[82] = &CPU::BIT2d;
	eOps[83] = &CPU::BIT2e;
	eOps[84] = &CPU::BIT2h;
	eOps[85] = &CPU::BIT2l;
	eOps[86] = &CPU::BIT2_hl_;
	eOps[87] = &CPU::BIT2a;
	eOps[88] = &CPU::BIT3b;
	eOps[89] = &CPU::BIT3c;
	eOps[90] = &CPU::BIT3d;
	eOps[91] = &CPU::BIT3e;
	eOps[92] = &CPU::BIT3h;
	eOps[93] = &CPU::BIT3l;
	eOps[94] = &CPU::BIT3_hl_;
	eOps[95] = &CPU::BIT3a;
	//0x60
	eOps[96] = &CPU::BIT4b;
	eOps[97] = &CPU::BIT4c;
	eOps[98] = &CPU::BIT4d;
	eOps[99] = &CPU::BIT4e;
	eOps[100] = &CPU::BIT4h;
	eOps[101] = &CPU::BIT4l;
	eOps[102] = &CPU::BIT4_hl_;
	eOps[103] = &CPU::BIT4a;
	eOps[104] = &CPU::BIT5b;
	eOps[105] = &CPU::BIT5c;
	eOps[106] = &CPU::BIT5d;
	eOps[107] = &CPU::BIT5e;
	eOps[108] = &CPU::BIT5h;
	eOps[109] = &CPU::BIT5l;
	eOps[110] = &CPU::BIT5_hl_;
	eOps[111] = &CPU::BIT5a;
	//0x70
	eOps[112] = &CPU::BIT6b;
	eOps[113] = &CPU::BIT6c;
	eOps[114] = &CPU::BIT6d;
	eOps[115] = &CPU::BIT6e;
	eOps[116] = &CPU::BIT6h;
	eOps[117] = &CPU::BIT6l;
	eOps[118] = &CPU::BIT6_hl_;
	eOps[119] = &CPU::BIT6a;
	eOps[120] = &CPU::BIT7b;
	eOps[121] = &CPU::BIT7c;
	eOps[122] = &CPU::BIT7d;
	eOps[123] = &CPU::BIT7e;
	eOps[124] = &CPU::BIT7h;
	eOps[125] = &CPU::BIT7l;
	eOps[126] = &CPU::BIT7_hl_;
	eOps[127] = &CPU::BIT7a;
	//0x80
	eOps[128] = &CPU::RES0b;
	eOps[129] = &CPU::RES0c;
	eOps[130] = &CPU::RES0d;
	eOps[131] = &CPU::RES0e;
	eOps[132] = &CPU::RES0h;
	eOps[133] = &CPU::RES0l;
	eOps[134] = &CPU::RES0_hl_;
	eOps[135] = &CPU::RES0a;
	eOps[136] = &CPU::RES1b;
	eOps[137] = &CPU::RES1c;
	eOps[138] = &CPU::RES1d;
	eOps[139] = &CPU::RES1e;
	eOps[140] = &CPU::RES1h;
	eOps[141] = &CPU::RES1l;
	eOps[142] = &CPU::RES1_hl_;
	eOps[143] = &CPU::RES1a;
	//0x90
	eOps[144] = &CPU::RES2b;
	eOps[145] = &CPU::RES2c;
	eOps[146] = &CPU::RES2d;
	eOps[147] = &CPU::RES2e;
	eOps[148] = &CPU::RES2h;
	eOps[149] = &CPU::RES2l;
	eOps[150] = &CPU::RES2_hl_;
	eOps[151] = &CPU::RES2a;
	eOps[152] = &CPU::RES3b;
	eOps[153] = &CPU::RES3c;
	eOps[154] = &CPU::RES3d;
	eOps[155] = &CPU::RES3e;
	eOps[156] = &CPU::RES3h;
	eOps[157] = &CPU::RES3l;
	eOps[158] = &CPU::RES3_hl_;
	eOps[159] = &CPU::RES3a;
	//0xA0
	eOps[160] = &CPU::RES4b;
	eOps[161] = &CPU::RES4c;
	eOps[162] = &CPU::RES4d;
	eOps[163] = &CPU::RES4e;
	eOps[164] = &CPU::RES4h;
	eOps[165] = &CPU::RES4l;
	eOps[166] = &CPU::RES4_hl_;
	eOps[167] = &CPU::RES4a;
	eOps[168] = &CPU::RES5b;
	eOps[169] = &CPU::RES5c;
	eOps[170] = &CPU::RES5d;
	eOps[171] = &CPU::RES5e;
	eOps[172] = &CPU::RES5h;
	eOps[173] = &CPU::RES5l;
	eOps[174] = &CPU::RES5_hl_;
	eOps[175] = &CPU::RES5a;
	//0xB0
	eOps[176] = &CPU::RES6b;
	eOps[177] = &CPU::RES6c;
	eOps[178] = &CPU::RES6d;
	eOps[179] = &CPU::RES6e;
	eOps[180] = &CPU::RES6h;
	eOps[181] = &CPU::RES6l;
	eOps[182] = &CPU::RES6_hl_;
	eOps[183] = &CPU::RES6a;
	eOps[184] = &CPU::RES7b;
	eOps[185] = &CPU::RES7c;
	eOps[186] = &CPU::RES7d;
	eOps[187] = &CPU::RES7e;
	eOps[188] = &CPU::RES7h;
	eOps[189] = &CPU::RES7l;
	eOps[190] = &CPU::RES7_hl_;
	eOps[191] = &CPU::RES7a;
	//0xC0
	eOps[192] = &CPU::SET0b;
	eOps[193] = &CPU::SET0c;
	eOps[194] = &CPU::SET0d;
	eOps[195] = &CPU::SET0e;
	eOps[196] = &CPU::SET0h;
	eOps[197] = &CPU::SET0l;
	eOps[198] = &CPU::SET0_hl_;
	eOps[199] = &CPU::SET0a;
	eOps[200] = &CPU::SET1b;
	eOps[201] = &CPU::SET1c;
	eOps[202] = &CPU::SET1d;
	eOps[203] = &CPU::SET1e;
	eOps[204] = &CPU::SET1h;
	eOps[205] = &CPU::SET1l;
	eOps[206] = &CPU::SET1_hl_;
	eOps[207] = &CPU::SET1a;
	//0xD0
	eOps[208] = &CPU::SET2b;
	eOps[209] = &CPU::SET2c;
	eOps[210] = &CPU::SET2d;
	eOps[211] = &CPU::SET2e;
	eOps[212] = &CPU::SET2h;
	eOps[213] = &CPU::SET2l;
	eOps[214] = &CPU::SET2_hl_;
	eOps[215] = &CPU::SET2a;
	eOps[216] = &CPU::SET3b;
	eOps[217] = &CPU::SET3c;
	eOps[218] = &CPU::SET3d;
	eOps[219] = &CPU::SET3e;
	eOps[220] = &CPU::SET3h;
	eOps[221] = &CPU::SET3l;
	eOps[222] = &CPU::SET3_hl_;
	eOps[223] = &CPU::SET3a;
	//0xE0
	eOps[224] = &CPU::SET4b;
	eOps[225] = &CPU::SET4c;
	eOps[226] = &CPU::SET4d;
	eOps[227] = &CPU::SET4e;
	eOps[228] = &CPU::SET4h;
	eOps[229] = &CPU::SET4l;
	eOps[230] = &CPU::SET4_hl_;
	eOps[231] = &CPU::SET4a;
	eOps[232] = &CPU::SET5b;
	eOps[233] = &CPU::SET5c;
	eOps[234] = &CPU::SET5d;
	eOps[235] = &CPU::SET5e;
	eOps[236] = &CPU::SET5h;
	eOps[237] = &CPU::SET5l;
	eOps[238] = &CPU::SET5_hl_;
	eOps[239] = &CPU::SET5a;
	//0xF0
	eOps[240] = &CPU::SET6b;
	eOps[241] = &CPU::SET6c;
	eOps[242] = &CPU::SET6d;
	eOps[243] = &CPU::SET6e;
	eOps[244] = &CPU::SET6h;
	eOps[245] = &CPU::SET6l;
	eOps[246] = &CPU::SET6_hl_;
	eOps[247] = &CPU::SET6a;
	eOps[248] = &CPU::SET7b;
	eOps[249] = &CPU::SET7c;
	eOps[250] = &CPU::SET7d;
	eOps[251] = &CPU::SET7e;
	eOps[252] = &CPU::SET7h;
	eOps[253] = &CPU::SET7l;
	eOps[254] = &CPU::SET7_hl_;
	eOps[255] = &CPU::SET7a;
}

void CPU::setRom(IROM *rom)
{
	this->rom = rom;
	BYTE *data = rom->getRom();
	for(int i = 0; i < 0x100; i++){
		memory->writeByte(0x100+i, data[i]);
	}
}

IMemory *CPU::getMemory()
{
	return memory;
}

CPU::RegistersType *CPU::getRegisters()
{
	return &registers;
}

void CPU::step()
{
	BYTE instruction = fetch();
	registers.pc++; //TODO: &0xFF
	decode(instruction);
}

BYTE CPU::fetch()
{
	BYTE instruction = memory->readByte(registers.pc);
	return instruction;
}

void CPU::decode(BYTE instruction)
{
	(this->*bOps[instruction])();
}

void CPU::decodeCB()
{
	BYTE instruction = memory->readByte(registers.pc);
	registers.pc++;
	(this->*eOps[instruction])();
}

void CPU::updateFlags(WORD n, BYTE operation)
{
	registers.f = 0;
	if (n == 0){
		registers.f |= ZERO;
	}
	if (operation < 0){
		registers.f |= OPERATION;
	}
	if (n > 0xFFFF || n < 0){
		registers.f = CARRY;
	} else if (n > 0xFF || n < 0){
		registers.f = CARRY;
	}
}



void CPU::NOP()
{
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDbcnn()
{
	registers.c = memory->readByte(registers.pc);
	registers.b = memory->readByte(registers.pc+1);
	registers.pc += 2;
	registers.m = 3;
	registers.t = 12;
}

void CPU::LD_bc_a()
{
	memory->writeShort(registers.b<<8 | registers.c, registers.a);
	registers.m = 2;
	registers.t = 8;
}

void CPU::INCbc()
{
	WORD tmp = (registers.b << 8 | registers.c) + 1;
	registers.b = tmp>>8;
	registers.c = tmp&0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::INCb()
{
	WORD tmp = registers.b + 1;
	updateFlags(tmp, 1);
	registers.b = tmp&255;
	registers.m = 1;
	registers.t = 4;
}

void CPU::DECb()
{
	WORD tmp = registers.b - 1;
	updateFlags(tmp, -1);
	registers.b = tmp&255;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDbn()
{
	registers.b = memory->readByte(registers.pc);
	registers.pc++;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RLCa()
{
	BYTE bitMostSignificant = registers.a & 0x80;
	registers.f |= bitMostSignificant ? CARRY : 0x00;
	registers.a = registers.a << 1;
	registers.a |= bitMostSignificant ? 0x01 : 0x00;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LD_nn_sp()
{
	SHORT nn = memory->readShort(registers.pc << 8 | (registers.pc + 1));
	registers.pc+=2;
	registers.sp = nn;
	registers.m = 6;
	registers.t = 20;
}

void CPU::ADDhlbc()
{
	WORD tmp = registers.h << 8 | registers.l;
	tmp += registers.b << 8 | registers.c;
	updateFlags(tmp, 1);
	registers.h = tmp >> 8;
	registers.l = tmp & 0xFF;
	registers.m = 3;
	registers.t = 12;
}

void CPU::LDa_bc_()
{
	SHORT tmp = registers.b << 8 | registers.c;
	registers.a = memory->readByte(tmp);
	registers.m = 2;
	registers.t = 8;
}

void CPU::DECbc()
{
	WORD tmp = (registers.b << 8 | registers.c) - 1;
	registers.b = tmp >> 8;
	registers.c = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::INCc()
{
	WORD tmp = registers.c + 1;
	updateFlags(tmp, 1);
	registers.c = tmp;
	registers.m = 1;
	registers.t = 4;
}

void CPU::DECc()
{
	WORD tmp = registers.c - 1;
	updateFlags(tmp, -1);
	registers.c = tmp;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDcn()
{
	registers.c = memory->readByte(registers.pc);
	registers.pc++;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RRCa()
{
	BYTE bitLeastSignificant = registers.a & 0x01;
	registers.f |= bitLeastSignificant ? CARRY : 0x00;
	registers.a = registers.a >> 1;
	registers.a |= bitLeastSignificant ? 0x80 : 0x00;
	registers.m = 1;
	registers.t = 4;
}
// 0x1
//TODO: FIX
void CPU::DJNZn()
{
	WORD e = memory->readByte(registers.pc);
	registers.pc++;
	if (e > 129){
		e = (~e + 5) & 0xFF;
	}
	if (!(registers.b--)){
		registers.pc += e;
		registers.m = 3;
		registers.t = 13;
	}else{
		registers.m = 2;
		registers.t = 8;
	}
}

/////////////////////////////////////////

void CPU::LDdenn()
{
	registers.e = memory->readByte(registers.pc);
	registers.d = memory->readByte(registers.pc + 1);
	registers.pc += 2;
	registers.m = 3;
	registers.t = 12;
}

void CPU::LD_de_a()
{
	memory->writeShort(registers.d << 8 | registers.e, registers.a);
	registers.m = 2;
	registers.t = 8;
}

void CPU::INCde()
{
	WORD tmp = (registers.d << 8 | registers.e) + 1;
	registers.d = tmp >> 8;
	registers.e = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::INCd()
{
	WORD tmp = registers.d + 1;
	updateFlags(tmp, 1);
	registers.b = tmp & 255;
	registers.m = 1;
	registers.t = 4;
}

void CPU::DECd()
{
	WORD tmp = registers.d - 1;
	updateFlags(tmp, -1);
	registers.d = tmp & 255;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDdn()
{
	registers.d = memory->readByte(registers.pc);
	registers.pc++;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RLa()
{
	BYTE bitMostSignificant = registers.a & 0x80;
	BYTE tmpCarryFlag = registers.f & (~CARRY);
	registers.a = registers.a << 1;
	registers.f |= bitMostSignificant ? CARRY : 0x00;
	registers.a |= tmpCarryFlag ? 0x01 : 0x00;
	registers.m = 1;
	registers.t = 4;
}

void CPU::JRn()
{
	BYTE e = memory->readByte(registers.pc);
	registers.pc++;
	if (e > 129){
		e = (~e + 5) & 0xFF;
	}
	registers.pc += e;
	registers.m = 3;
	registers.t = 12;
}

void CPU::ADDhlde()
{
	WORD tmp = registers.h << 8 | registers.l;
	tmp += registers.d << 8 | registers.e;
	updateFlags(tmp, 1);
	registers.h = tmp >> 8;
	registers.l = tmp & 0xFF;
	registers.m = 3;
	registers.t = 12;
}

void CPU::LDa_de_()
{
	SHORT tmp = registers.d << 8 | registers.e;
	registers.a = memory->readByte(tmp);
	registers.m = 2;
	registers.t = 8;
}

void CPU::DECde()
{
	WORD tmp = (registers.d << 8 | registers.e) - 1;
	registers.d = tmp >> 8;
	registers.e = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::INCe()
{
	WORD tmp = registers.e + 1;
	updateFlags(tmp, 1);
	registers.e = tmp;
	registers.m = 1;
	registers.t = 4;
}

void CPU::DECe()
{
	WORD tmp = registers.e - 1;
	updateFlags(tmp, -1);
	registers.e = tmp;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDen()
{
	registers.e = memory->readByte(registers.pc);
	registers.pc++;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RRa()
{
	BYTE bitLeastSignificant = registers.a & 0x01;
	BYTE tmpCarryFlag = registers.f & (~CARRY);
	registers.f |= bitLeastSignificant ? CARRY : 0x00;
	registers.a = registers.a >> 1;
	registers.a |= tmpCarryFlag ? 0x80 : 0x00;
	registers.m = 1;
	registers.t = 4;
}

//0x2

void CPU::JRNZn()
{
	WORD e = memory->readByte(registers.pc);
	registers.pc++;
	if (e > 129){
		e = (~e + 5) & 0xFF;
	}
	if (registers.f & ~ZERO){
		registers.m = 2;
		registers.t = 7;
	}else{
		registers.pc += e;
		registers.m = 2;
		registers.t = 12;
	}
}

void CPU::LDhlnn()
{
	registers.l = memory->readByte(registers.pc);
	registers.h = memory->readByte(registers.pc + 1);
	registers.pc += 2;
	registers.m = 3;
	registers.t = 12;
}

void CPU::LDI_hl_a()
{
	WORD tmp = registers.h << 8 | registers.l;
	memory->writeShort(tmp, registers.a);
	tmp++;
	registers.h = tmp >> 8;
	registers.l = tmp & 0xFF;
	registers.m = 2;
	registers.t = 8;
}

void CPU::INChl()
{
	WORD tmp = (registers.h << 8 | registers.l) + 1;
	registers.d = tmp >> 8;
	registers.e = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::INCh()
{
	WORD tmp = registers.h + 1;
	updateFlags(tmp, 1);
	registers.b = tmp & 255;
	registers.m = 1;
	registers.t = 4;
}

void CPU::DECh()
{
	WORD tmp = registers.h - 1;
	updateFlags(tmp, -1);
	registers.d = tmp & 255;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDhn()
{
	registers.h = memory->readByte(registers.pc);
	registers.pc++;
	registers.m = 2;
	registers.t = 8;
}

void CPU::DAA()
{
	//Not implemented
}

void CPU::JRZn()
{
	BYTE e = memory->readByte(registers.pc);
	registers.pc++;
	if (e > 129){
		e = (~e + 5) & 0xFF;
	}
	if (registers.f & ZERO){
		registers.pc += e;
		registers.m = 3;
		registers.t = 12;
	}else{
		registers.m = 2;
		registers.t = 7;
	}
}

void CPU::ADDhlhl()
{
	WORD tmp = registers.h << 8 | registers.l;
	tmp += tmp;
	updateFlags(tmp, 1);
	registers.h = tmp >> 8;
	registers.l = tmp & 0xFF;
	registers.m = 3;
	registers.t = 12;
}

void CPU::LDIa_hl_()
{
	WORD tmp = registers.h << 8 | registers.l;
	registers.a = memory->readShort(tmp);
	tmp++;
	registers.h = tmp >> 8;
	registers.l = tmp & 0xFF;
	registers.m = 2;
	registers.t = 8;
}

void CPU::DEChl()
{
	WORD tmp = (registers.h << 8 | registers.l) - 1;
	registers.h = tmp >> 8;
	registers.l = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::INCl()
{
	WORD tmp = registers.l + 1;
	updateFlags(tmp, 1);
	registers.l = tmp;
	registers.m = 1;
	registers.t = 4;
}

void CPU::DECl()
{
	WORD tmp = registers.l - 1;
	updateFlags(tmp, -1);
	registers.l = tmp;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDln()
{
	registers.l = memory->readByte(registers.pc);
	registers.pc++;
	registers.m = 2;
	registers.t = 8;
}

void CPU::CPL()
{
	registers.a = ~registers.a;
	registers.m = 1;
	registers.t = 4;
}

//0x30

void CPU::JRNCn()
{
	WORD e = memory->readByte(registers.pc);
	registers.pc++;
	if (e > 129){
		e = (~e + 5) & 0xFF;
	}
	if (registers.f & ~CARRY){
		registers.m = 2;
		registers.t = 7;
	}else{
		registers.pc += e;
		registers.m = 2;
		registers.t = 12;
	}
}

void CPU::LDspnn()
{
	registers.sp = memory->readShort(registers.pc);
	registers.pc += 2;
	registers.m = 3;
	registers.t = 12;
}

void CPU::LDD_hl_a()
{
	WORD tmp = registers.h << 8 | registers.l;
	memory->writeShort(tmp, registers.a);
	tmp--;
	registers.h = tmp >> 8;
	registers.l = tmp & 0xFF;
	registers.m = 2;
	registers.t = 8;
}

void CPU::INCsp()
{
	WORD tmp = (registers.sp) + 1;
	registers.sp = tmp;
	registers.m = 1;
	registers.t = 4;
}

void CPU::INC_hl_()
{
	WORD tmp = memory->readShort(registers.h << 8 | registers.l) + 1;
	updateFlags(tmp, 1);
	memory->writeShort(registers.h << 8 | registers.l, tmp);
	registers.m = 3;
	registers.t = 11;
}

void CPU::DEC_hl_()
{
	WORD tmp = memory->readShort(registers.h << 8 | registers.l) - 1;
	updateFlags(tmp, 1);
	memory->writeShort(registers.h << 8 | registers.l, tmp);
	registers.m = 3;
	registers.t = 11;
}

void CPU::LD_hl_n()
{
	WORD e = memory->readByte(registers.pc);
	registers.pc++;
	memory->writeShort(registers.h << 8 | registers.l, e);
	registers.m = 3;
	registers.t = 10;
}

void CPU::SCF()
{
	registers.f |= CARRY;
	registers.m = 1;
	registers.t = 4;
}

void CPU::JRCn()
{
	BYTE e = memory->readByte(registers.pc);
	registers.pc++;
	if (e > 129){
		e = (~e + 5) & 0xFF;
	}
	if (registers.f & CARRY){
		registers.pc += e;
		registers.m = 3;
		registers.t = 12;
	}else{
		registers.m = 2;
		registers.t = 7;
	}
	
}

void CPU::ADDhlsp()
{
	WORD tmp = registers.h << 8 | registers.l;
	tmp += registers.sp;
	updateFlags(tmp, 1);
	registers.sp = tmp;
	registers.m = 3;
	registers.t = 12;
}

void CPU::LDDa_hl_()
{
	WORD tmp = registers.h << 8 | registers.l;
	registers.a = memory->readShort(tmp);
	tmp--;
	registers.h = tmp >> 8;
	registers.l = tmp & 0xFF;
	registers.m = 2;
	registers.t = 8;
}

void CPU::DECsp()
{
	WORD tmp = (registers.sp) - 1;
	registers.sp = tmp;
	registers.m = 1;
	registers.t = 4;
}

void CPU::INCa()
{
	WORD tmp = registers.a + 1;
	updateFlags(tmp, 1);
	registers.a = tmp;
	registers.m = 1;
	registers.t = 4;
}

void CPU::DECa()
{
	WORD tmp = registers.a - 1;
	updateFlags(tmp, -1);
	registers.a = tmp;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDan()
{
	registers.a = memory->readByte(registers.pc);
	registers.pc++;
	registers.m = 2;
	registers.t = 8;
}

void CPU::CCF()
{
	registers.f &= ~CARRY;
	registers.m = 1;
	registers.t = 4;
}

//0x40

void CPU::LDbb()
{
	registers.b = registers.b;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDbc()
{
	registers.b = registers.c;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDbd()
{
	registers.b = registers.d;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDbe()
{
	registers.b = registers.e;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDbh()
{
	registers.b = registers.h;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDbl()
{
	registers.b = registers.l;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDb_hl_()
{
	BYTE e = memory->readByte(registers.h << 8 | registers.l);
	registers.b = e;
	registers.m = 2;
	registers.t = 8;
}

void CPU::LDba()
{
	registers.b = registers.a;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDcb()
{
	registers.c = registers.b;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDcc()
{
	registers.c = registers.c;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDcd()
{
	registers.c = registers.d;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDce()
{
	registers.c = registers.e;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDch()
{
	registers.c = registers.h;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDcl()
{
	registers.c = registers.l;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDc_hl_()
{
	BYTE e = memory->readByte(registers.h << 8 | registers.l);
	registers.c = e;
	registers.m = 2;
	registers.t = 8;
}

void CPU::LDca()
{
	registers.c = registers.a;
	registers.m = 1;
	registers.t = 4;
}

// 0x50

void CPU::LDdb()
{
	registers.d = registers.b;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDdc()
{
	registers.d = registers.c;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDdd()
{
	registers.d = registers.d;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDde()
{
	registers.d = registers.e;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDdh()
{
	registers.d = registers.h;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDdl()
{
	registers.d = registers.l;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDd_hl_()
{
	BYTE e = memory->readByte(registers.h << 8 | registers.l);
	registers.d = e;
	registers.m = 2;
	registers.t = 8;
}

void CPU::LDda()
{
	registers.d = registers.a;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDeb()
{
	registers.e = registers.b;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDec()
{
	registers.e = registers.c;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDed()
{
	registers.e = registers.d;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDee()
{
	registers.e = registers.e;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDeh()
{
	registers.e = registers.h;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDel()
{
	registers.e = registers.l;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDe_hl_()
{
	BYTE e = memory->readByte(registers.h << 8 | registers.l);
	registers.e = e;
	registers.m = 2;
	registers.t = 8;
}

void CPU::LDea()
{
	registers.e = registers.a;
	registers.m = 1;
	registers.t = 4;
}

// 0x60

void CPU::LDhb()
{
	registers.h = registers.b;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDhc()
{
	registers.h = registers.c;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDhd()
{
	registers.h = registers.d;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDhe()
{
	registers.h = registers.e;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDhh()
{
	registers.h = registers.h;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDhl()
{
	registers.h = registers.l;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDh_hl_()
{
	BYTE e = memory->readByte(registers.h << 8 | registers.l);
	registers.h = e;
	registers.m = 2;
	registers.t = 8;
}

void CPU::LDha()
{
	registers.h = registers.a;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDlb()
{
	registers.l = registers.b;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDlc()
{
	registers.l = registers.c;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDld()
{
	registers.l = registers.d;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDle()
{
	registers.l = registers.e;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDlh()
{
	registers.l = registers.h;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDll()
{
	registers.l = registers.l;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDl_hl_()
{
	BYTE e = memory->readByte(registers.h << 8 | registers.l);
	registers.l = e;
	registers.m = 2;
	registers.t = 8;
}

void CPU::LDla()
{
	registers.l = registers.a;
	registers.m = 1;
	registers.t = 4;
}

//0x70

void CPU::LD_hl_b()
{
	memory->writeByte(registers.h << 8 | registers.l, registers.b);
	registers.m = 2;
	registers.t = 8;
}

void CPU::LD_hl_c()
{
	memory->writeByte(registers.h << 8 | registers.l, registers.c);
	registers.m = 2;
	registers.t = 8;
}

void CPU::LD_hl_d()
{
	memory->writeByte(registers.h << 8 | registers.l, registers.d);
	registers.m = 2;
	registers.t = 8;
}

void CPU::LD_hl_e()
{
	memory->writeByte(registers.h << 8 | registers.l, registers.e);
	registers.m = 2;
	registers.t = 8;
}

void CPU::LD_hl_h()
{
	memory->writeByte(registers.h << 8 | registers.l, registers.h);
	registers.m = 2;
	registers.t = 8;
}

void CPU::LD_hl_l()
{
	memory->writeByte(registers.h << 8 | registers.l, registers.l);
	registers.m = 2;
	registers.t = 8;
}

void CPU::HALT()
{
	halt = 1;
	registers.m = 2;
	registers.t = 8;
}

void CPU::LD_hl_a()
{
	memory->writeByte(registers.h << 8 | registers.l, registers.a);
	registers.m = 2;
	registers.t = 8;
}

void CPU::LDab()
{
	registers.a = registers.b;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDac()
{
	registers.a = registers.c;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDad()
{
	registers.a = registers.d;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDae()
{
	registers.a = registers.e;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDah()
{
	registers.a = registers.h;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDal()
{
	registers.a = registers.l;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDa_hl_()
{
	BYTE e = memory->readByte(registers.h << 8 | registers.l);
	registers.a = e;
	registers.m = 2;
	registers.t = 8;
}

void CPU::LDaa()
{
	registers.a = registers.a;
	registers.m = 1;
	registers.t = 4;
}

//0x80

void CPU::ADDab()
{
	WORD tmp = registers.a + registers.b;
	updateFlags(tmp, 1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ADDac()
{
	WORD tmp = registers.a + registers.c;
	updateFlags(tmp, 1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ADDad()
{
	WORD tmp = registers.a + registers.d;
	updateFlags(tmp, 1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ADDae()
{
	WORD tmp = registers.a + registers.e;
	updateFlags(tmp, 1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ADDah()
{
	WORD tmp = registers.a + registers.h;
	updateFlags(tmp, 1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ADDal()
{
	WORD tmp = registers.a + registers.l;
	updateFlags(tmp, 1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ADDa_hl_()
{

	WORD tmp = registers.a + memory->readByte(registers.h << 8 | registers.l);
	updateFlags(tmp, 1);
	registers.a = tmp & 0xFF;
	registers.m = 2;
	registers.t = 8;
}

void CPU::ADDaa()
{
	WORD tmp = registers.a + registers.a;
	updateFlags(tmp, 1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ADCab()
{
	WORD tmp = registers.a + registers.b;
	tmp += registers.f & CARRY ? 1 : 0;
	updateFlags(tmp, 1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ADCac()
{
	WORD tmp = registers.a + registers.c;
	tmp += registers.f & CARRY ? 1 : 0;
	updateFlags(tmp, 1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ADCad()
{
	WORD tmp = registers.a + registers.d;
	tmp += registers.f & CARRY ? 1 : 0;
	updateFlags(tmp, 1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ADCae()
{
	WORD tmp = registers.a + registers.e;
	tmp += registers.f & CARRY ? 1 : 0;
	updateFlags(tmp, 1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ADCah()
{
	WORD tmp = registers.a + registers.h;
	tmp += registers.f & CARRY ? 1 : 0;
	updateFlags(tmp, 1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ADCal()
{
	WORD tmp = registers.a + registers.l;
	tmp += registers.f & CARRY ? 1 : 0;
	updateFlags(tmp, 1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ADCa_hl_()
{
	WORD tmp = registers.a + memory->readByte(registers.h << 8 | registers.l);
	tmp += registers.f & CARRY ? 1 : 0;
	updateFlags(tmp, 1);
	registers.a = tmp & 0xFF;
	registers.m = 2;
	registers.t = 8;
}

void CPU::ADCaa()
{
	WORD tmp = registers.a + registers.a;
	tmp += registers.f & CARRY ? 1 : 0;
	updateFlags(tmp, 1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

//0x90

void CPU::SUBab()
{
	WORD tmp = registers.a - registers.b;
	updateFlags(tmp, -1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::SUBac()
{
	WORD tmp = registers.a - registers.c;
	updateFlags(tmp, -1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::SUBad()
{
	WORD tmp = registers.a - registers.d;
	updateFlags(tmp, -1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::SUBae()
{
	WORD tmp = registers.a - registers.e;
	updateFlags(tmp, -1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::SUBah()
{
	WORD tmp = registers.a - registers.h;
	updateFlags(tmp, -1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::SUBal()
{
	WORD tmp = registers.a - registers.l;
	updateFlags(tmp, -1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::SUBa_hl_()
{

	WORD tmp = registers.a - memory->readByte(registers.h << 8 | registers.l);
	updateFlags(tmp, -1);
	registers.a = tmp & 0xFF;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SUBaa()
{
	WORD tmp = registers.a - registers.a;
	updateFlags(tmp, -1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::SBCab()
{
	WORD tmp = registers.a - registers.b;
	tmp -= registers.f & CARRY ? 1 : 0;
	updateFlags(tmp, -1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::SBCac()
{
	WORD tmp = registers.a - registers.c;
	tmp -= registers.f & CARRY ? 1 : 0;
	updateFlags(tmp, -1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::SBCad()
{
	WORD tmp = registers.a - registers.d;
	tmp -= registers.f & CARRY ? 1 : 0;
	updateFlags(tmp, -1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::SBCae()
{
	WORD tmp = registers.a - registers.e;
	tmp -= registers.f & CARRY ? 1 : 0;
	updateFlags(tmp, -1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::SBCah()
{
	WORD tmp = registers.a - registers.h;
	tmp -= registers.f & CARRY ? 1 : 0;
	updateFlags(tmp, -1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::SBCal()
{
	WORD tmp = registers.a - registers.l;
	tmp -= registers.f & CARRY ? 1 : 0;
	updateFlags(tmp, -1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::SBCa_hl_()
{
	WORD tmp = registers.a - memory->readByte(registers.h << 8 | registers.l);
	tmp -= registers.f & CARRY ? 1 : 0;
	updateFlags(tmp, -1);
	registers.a = tmp & 0xFF;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SBCaa()
{
	WORD tmp = registers.a - registers.a;
	tmp -= registers.f & CARRY ? 1 : 0;
	updateFlags(tmp, -1);
	registers.a = tmp & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

//0xA0
void CPU::ANDb()
{
	WORD e = registers.a & registers.b;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ANDc()
{
	WORD e = registers.a & registers.c;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ANDd()
{
	WORD e = registers.a & registers.d;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ANDe()
{
	WORD e = registers.a & registers.e;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ANDh()
{
	WORD e = registers.a & registers.h;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ANDl()
{
	WORD e = registers.a & registers.l;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::AND_hl_()
{
	WORD e = registers.a & memory->readByte(registers.h << 8 | registers.l);
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 2;
	registers.t = 8;
}

void CPU::ANDa()
{
	WORD e = registers.a & registers.a;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::XORb()
{
	WORD e = registers.a ^ registers.b;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::XORc()
{
	WORD e = registers.a ^ registers.c;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::XORd()
{
	WORD e = registers.a ^ registers.d;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::XORe()
{
	WORD e = registers.a ^ registers.e;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::XORh()
{
	WORD e = registers.a ^ registers.h;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::XORl()
{
	WORD e = registers.a ^ registers.l;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::XOR_hl_()
{
	WORD e = registers.a ^ memory->readByte(registers.h << 8 | registers.l);
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 2;
	registers.t = 8;
}

void CPU::XORa()
{
	WORD e = registers.a ^ registers.a;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

// 0xB0

void CPU::ORb()
{
	WORD e = registers.a | registers.b;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ORc()
{
	WORD e = registers.a | registers.c;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ORd()
{
	WORD e = registers.a | registers.d;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ORe()
{
	WORD e = registers.a | registers.e;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ORh()
{
	WORD e = registers.a | registers.h;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::ORl()
{
	WORD e = registers.a | registers.l;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::OR_hl_()
{
	WORD e = registers.a | memory->readByte(registers.h << 8 | registers.l);
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 2;
	registers.t = 8;
}

void CPU::ORa()
{
	WORD e = registers.a | registers.a;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 1;
	registers.t = 4;
}

void CPU::CPb()
{
	WORD e = registers.a - registers.b;
	updateFlags(e, -1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::CPc()
{
	WORD e = registers.a - registers.c;
	updateFlags(e, -1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::CPd()
{
	WORD e = registers.a - registers.d;
	updateFlags(e, -1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::CPe()
{
	WORD e = registers.a - registers.e;
	updateFlags(e, -1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::CPh()
{
	WORD e = registers.a - registers.h;
	updateFlags(e, -1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::CPl()
{
	WORD e = registers.a - registers.l;
	updateFlags(e, -1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::CP_hl_()
{
	WORD e = registers.a - memory->readByte(registers.h << 8 | registers.l);
	updateFlags(e, -1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::CPa()
{
	WORD e = registers.a - registers.a;
	updateFlags(e, -1);
	registers.m = 1;
	registers.t = 4;
}

//0xC0

void CPU::RETNZ()
{
	if (registers.f & ZERO){
		registers.m = 1;
		registers.t = 5;
	}else{
		registers.pc = memory->readShort(registers.sp);
		registers.sp += 2;
		registers.m = 3;
		registers.t = 11;
	}
}

void CPU::POPbc()
{
	registers.c = memory->readByte(registers.sp);
	registers.sp++;
	registers.b = memory->readByte(registers.sp);
	registers.sp++;
	registers.m = 3;
	registers.t = 10;
}

void CPU::JPNZnn()
{
	// Posible error in m and t, because they are the same if the jump is taken and if the jump is not taken but datasheet say that
	if (registers.f & ZERO){
		registers.m = 3;
		registers.t = 10;
		registers.pc += 2;
	}else{
		registers.pc = memory->readShort(registers.pc);
		registers.m = 3;
		registers.t = 10;
	}
}

void CPU::JPnn()
{
	WORD e = memory->readShort(registers.pc);
	registers.pc = e;
	registers.m = 3;
	registers.t = 11;
}

void CPU::CALLNZnn()
{
	if (registers.f & ZERO){
		registers.pc += 2;
		registers.m = 3;
		registers.t = 10;
	}else{
		registers.sp -= 2;
		memory->writeShort(registers.sp, registers.pc+2);
		registers.pc = memory->readShort(registers.pc);
		registers.m = 5;
		registers.t = 17;
	}
}

void CPU::PUSHbc()
{
	registers.sp -= 2;
	memory->writeShort(registers.sp, registers.b << 8 | registers.c);
	registers.m = 3;
	registers.t = 10;
}

void CPU::ADDan()
{
	WORD e = registers.a + memory->readByte(registers.pc);
	registers.pc++;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RST0()
{
	registers.sp -= 2;
	memory->writeShort(registers.sp, registers.pc);
	registers.pc = 0x00;
	registers.m = 3;
	registers.t = 11;
}

void CPU::RETZ()
{
	if (registers.f & ZERO){
		registers.pc = memory->readShort(registers.sp);
		registers.sp += 2;
		registers.m = 3;
		registers.t = 11;
	}else{
		registers.m = 1;
		registers.t = 5;
	}
}

void CPU::RET()
{
	registers.pc = memory->readShort(registers.sp);
	registers.sp += 2;
	registers.m = 3;
	registers.t = 11;
}

void CPU::JPZnn()
{
	// Posible error in m and t, because they are the same if the jump is taken and if the jump is not taken but datasheet say that
	if (registers.f & ZERO){
		registers.pc = memory->readShort(registers.pc);
		registers.m = 3;
		registers.t = 10;
	}else{
		registers.m = 3;
		registers.t = 10;
		registers.pc += 2;
	}
}

//EXT OPS

void CPU::CALLZnn()
{
	if (registers.f & ZERO){
		registers.sp -= 2;
		memory->writeShort(registers.sp, registers.pc+2);
		registers.pc = memory->readShort(registers.pc);
		registers.m = 5;
		registers.t = 17;
	}else{
		registers.pc += 2;
		registers.m = 3;
		registers.t = 10;
	}
}

void CPU::CALLnn()
{
	registers.sp -= 2;
	memory->writeShort(registers.sp, registers.pc + 2);
	registers.pc = memory->readShort(registers.pc);
	registers.m = 5;
	registers.t = 17;
}

void CPU::ADCan()
{
	WORD tmp = registers.a + memory->readByte(registers.pc);
	registers.pc++;
	tmp += registers.f & CARRY ? 1 : 0;
	updateFlags(tmp, 1);
	registers.a = tmp & 0xFF;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RST8()
{
	registers.sp -= 2;
	memory->writeShort(registers.sp, registers.pc);
	registers.pc = 0x08;
	registers.m = 3;
	registers.t = 11;
}

//0xD0

void CPU::RETNC()
{
	if (registers.f & CARRY){
		registers.m = 1;
		registers.t = 5;
	}else{
		registers.pc = memory->readShort(registers.sp);
		registers.sp += 2;
		registers.m = 3;
		registers.t = 11;
	}
}

void CPU::POPde()
{
	registers.e = memory->readByte(registers.sp);
	registers.sp++;
	registers.d = memory->readByte(registers.sp);
	registers.sp++;
	registers.m = 3;
	registers.t = 10;
}

void CPU::JPNCnn()
{
	// Posible error in m and t, because they are the same if the jump is taken and if the jump is not taken but datasheet say that
	if (registers.f & CARRY){
		registers.m = 3;
		registers.t = 10;
		registers.pc += 2;
	}else{
		registers.pc = memory->readShort(registers.pc);
		registers.m = 3;
		registers.t = 10;
	}
}

// Not implemented

void CPU::CALLNCnn()
{
	if (registers.f & CARRY){
		registers.pc += 2;
		registers.m = 3;
		registers.t = 10;
	}else{
		registers.sp -= 2;
		memory->writeShort(registers.sp, registers.pc+2);
		registers.pc = memory->readShort(registers.pc);
		registers.m = 5;
		registers.t = 17;
	}
}

void CPU::PUSHde()
{
	registers.sp -= 2;
	memory->writeShort(registers.sp, registers.d << 8 | registers.e);
	registers.m = 3;
	registers.t = 10;
}

void CPU::SUBan()
{
	WORD e = registers.a - memory->readByte(registers.pc);
	registers.pc++;
	updateFlags(e, -1);
	registers.a = e & 0xFF;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RST10()
{
	registers.sp -= 2;
	memory->writeShort(registers.sp, registers.pc);
	registers.pc = 0x10;
	registers.m = 3;
	registers.t = 11;
}

void CPU::RETC()
{
	if (registers.f & CARRY){
		registers.pc = memory->readShort(registers.sp);
		registers.sp += 2;
		registers.m = 3;
		registers.t = 11;
	}else{
		registers.m = 1;
		registers.t = 5;
	}
}

void CPU::RETI()
{
	irq = 1;
	registers.pc = memory->readShort(registers.sp);
	registers.sp += 2;
	registers.m = 3;
	registers.t = 11;
}

void CPU::JPCnn()
{
	// Posible error in m and t, because they are the same if the jump is taken and if the jump is not taken but datasheet say that
	if (registers.f & CARRY){
		registers.pc = memory->readShort(registers.pc);
		registers.m = 3;
		registers.t = 10;
	}else{
		registers.m = 3;
		registers.t = 10;
		registers.pc += 2;
	}
}

//EXT OPS

void CPU::CALLCnn()
{
	if (registers.f & CARRY){
		registers.sp -= 2;
		memory->writeShort(registers.sp, registers.pc+2);
		registers.pc = memory->readShort(registers.pc);
		registers.m = 5;
		registers.t = 17;
	}else{
		registers.pc += 2;
		registers.m = 3;
		registers.t = 10;
	}
}

//Not implemented

void CPU::SBCan()
{
	WORD tmp = registers.a - memory->readByte(registers.pc);
	registers.pc++;
	tmp -= registers.f & CARRY ? 1 : 0;
	updateFlags(tmp, -1);
	registers.a = tmp & 0xFF;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RST18()
{
	registers.sp -= 2;
	memory->writeShort(registers.sp, registers.pc);
	registers.pc = 0x18;
	registers.m = 3;
	registers.t = 11;
}

//0xE0

void CPU::LDH_n_a()
{
	BYTE e = memory->readByte(registers.pc);
	registers.pc++;
	memory->writeByte(0xFF00 | e, registers.a);
	registers.m = 3;
	registers.t = 12;
}

void CPU::POPhl()
{
	registers.l = memory->readByte(registers.sp);
	registers.sp++;
	registers.h = memory->readByte(registers.sp);
	registers.sp++;
	registers.m = 3;
	registers.t = 10;
}

void CPU::LDH_c_a()
{
	memory->writeByte(0xFF00 | registers.c, registers.a);
	registers.m = 2;
	registers.t = 8;
}

// Not implemented

// Not implemented

void CPU::PUSHhl()
{
	registers.sp -= 2;
	memory->writeShort(registers.sp, registers.h << 8 | registers.l);
	registers.m = 3;
	registers.t = 10;
}

void CPU::ANDn()
{
	WORD e = registers.a & memory->readByte(registers.pc);
	registers.pc++;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RST20()
{
	registers.sp -= 2;
	memory->writeShort(registers.sp, registers.pc);
	registers.pc = 0x20;
	registers.m = 3;
	registers.t = 11;
}

void CPU::ADDspn()
{
	BYTE e = memory->readByte(registers.pc);
	registers.pc++;
	if (e > 129){
		e = (~e+5)&0xFF;
	}
	registers.sp += e;
	registers.m = 4;
	registers.t = 16;
}

void CPU::JPhl()
{
	registers.pc = registers.h << 8 | registers.l;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LD_nn_a()
{
	SHORT e = memory->readShort(registers.pc);
	memory->writeByte(e, registers.a);
	registers.pc += 2;	
	registers.m = 4;
	registers.t = 16;
}

// Not Implemented

// Not Implemented

// Not implemented

void CPU::XORn()
{
	WORD tmp = registers.a ^ memory->readByte(registers.pc);
	registers.pc++;
	updateFlags(tmp, 1);
	registers.a = tmp & 0xFF;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RST28()
{
	registers.sp -= 2;
	memory->writeShort(registers.sp, registers.pc);
	registers.pc = 0x28;
	registers.m = 3;
	registers.t = 11;
}

//0xF0

void CPU::LDHa_n_()
{
	BYTE e = memory->readByte(registers.pc);
	registers.pc++;
	registers.a = memory->readByte(0xFF00 | e);
	registers.m = 3;
	registers.t = 12;
}

void CPU::POPaf()
{
	registers.f = memory->readByte(registers.sp);
	registers.sp++;
	registers.a = memory->readByte(registers.sp);
	registers.sp++;
	registers.m = 3;
	registers.t = 10;
}

// Not implemented

void CPU::DI()
{
	irq = 0;
	registers.m = 1;
	registers.t = 4;
}

// Not implemented

void CPU::PUSHaf()
{
	registers.sp -= 2;
	memory->writeShort(registers.sp, registers.a << 8 | registers.f);
	registers.m = 3;
	registers.t = 10;
}

void CPU::ORn()
{
	WORD e = registers.a | memory->readByte(registers.pc);
	registers.pc++;
	updateFlags(e, 1);
	registers.a = e & 0xFF;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RST30()
{
	registers.sp -= 2;
	memory->writeShort(registers.sp, registers.pc);
	registers.pc = 0x30;
	registers.m = 3;
	registers.t = 11;
}

void CPU::LDHLspn()
{
	BYTE e = memory->readByte(registers.pc);
	registers.pc++;
	if (e > 129){
		e = (~e+5)&0xFF;
	}
	e += registers.sp;
	registers.h = e >> 8;
	registers.l = e & 0xFF;
	registers.m = 3;
	registers.t = 12;
}

void CPU::LDsphl()
{
	registers.sp = registers.h << 8 | registers.l;
	registers.m = 1;
	registers.t = 4;
}

void CPU::LDa_nn_()
{
	BYTE e = memory->readShort(registers.pc);
	registers.a = e;
	registers.pc += 2;	
	registers.m = 4;
	registers.t = 16;
}

void CPU::EI()
{
	irq = 1;
	registers.m = 1;
	registers.t = 4;
}

// Not Implemented

// Not implemented

void CPU::CPn()
{
	WORD tmp = registers.a - memory->readByte(registers.pc);
	registers.pc++;
	updateFlags(tmp, -1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::RST38()
{
	registers.sp -= 2;
	memory->writeShort(registers.sp, registers.pc);
	registers.pc = 0x38;
	registers.m = 3;
	registers.t = 11;
}

// Extended ISA

//0x00
void CPU::RLCb()
{
	BYTE bitMostSignificant = registers.b & 0x80;
	registers.f |= bitMostSignificant ? CARRY : 0x00;
	registers.b = registers.b << 1;
	registers.b |= bitMostSignificant ? 0x01 : 0x00;
	updateFlags(registers.b, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RLCc()
{
	BYTE bitMostSignificant = registers.c & 0x80;
	registers.f |= bitMostSignificant ? CARRY : 0x00;
	registers.c = registers.c << 1;
	registers.c |= bitMostSignificant ? 0x01 : 0x00;
	updateFlags(registers.c, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RLCd()
{
	BYTE bitMostSignificant = registers.d & 0x80;
	registers.f |= bitMostSignificant ? CARRY : 0x00;
	registers.d = registers.d << 1;
	registers.d |= bitMostSignificant ? 0x01 : 0x00;
	updateFlags(registers.d, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RLCe()
{
	BYTE bitMostSignificant = registers.e & 0x80;
	registers.f |= bitMostSignificant ? CARRY : 0x00;
	registers.e = registers.e << 1;
	registers.e |= bitMostSignificant ? 0x01 : 0x00;
	updateFlags(registers.e, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RLCh()
{
	BYTE bitMostSignificant = registers.h & 0x80;
	registers.f |= bitMostSignificant ? CARRY : 0x00;
	registers.h = registers.h << 1;
	registers.h |= bitMostSignificant ? 0x01 : 0x00;
	updateFlags(registers.h, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RLCl()
{
	BYTE bitMostSignificant = registers.l & 0x80;
	registers.f |= bitMostSignificant ? CARRY : 0x00;
	registers.l = registers.l << 1;
	registers.l |= bitMostSignificant ? 0x01 : 0x00;
	updateFlags(registers.l, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RLC_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	BYTE bitMostSignificant = n & 0x80;
	registers.f |= bitMostSignificant ? CARRY : 0x00;
	n = n << 1;
	n |= bitMostSignificant ? 0x01 : 0x00;
	updateFlags(n, 1);
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 1;
	registers.t = 4;
}

//RLCa ya esta definida en bOps

void CPU::RRCb()
{
	BYTE bitLeastSignificant = registers.b & 0x01;
	registers.f |= bitLeastSignificant ? CARRY : 0x00;
	registers.b = registers.b >> 1;
	registers.b |= bitLeastSignificant ? 0x80 : 0x00;
	updateFlags(registers.b, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RRCc()
{
	BYTE bitLeastSignificant = registers.c & 0x01;
	registers.f |= bitLeastSignificant ? CARRY : 0x00;
	registers.c = registers.c >> 1;
	registers.c |= bitLeastSignificant ? 0x80 : 0x00;
	updateFlags(registers.c, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RRCd()
{
	BYTE bitLeastSignificant = registers.d & 0x01;
	registers.f |= bitLeastSignificant ? CARRY : 0x00;
	registers.d = registers.d >> 1;
	registers.d |= bitLeastSignificant ? 0x80 : 0x00;
	updateFlags(registers.d, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RRCe()
{
	BYTE bitLeastSignificant = registers.e & 0x01;
	registers.f |= bitLeastSignificant ? CARRY : 0x00;
	registers.e = registers.e >> 1;
	registers.e |= bitLeastSignificant ? 0x80 : 0x00;
	updateFlags(registers.e, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RRCh()
{
	BYTE bitLeastSignificant = registers.h & 0x01;
	registers.f |= bitLeastSignificant ? CARRY : 0x00;
	registers.h = registers.h >> 1;
	registers.h |= bitLeastSignificant ? 0x80 : 0x00;
	updateFlags(registers.h, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RRCl()
{
	BYTE bitLeastSignificant = registers.l & 0x01;
	registers.f |= bitLeastSignificant ? CARRY : 0x00;
	registers.l = registers.l >> 1;
	registers.l |= bitLeastSignificant ? 0x80 : 0x00;
	updateFlags(registers.l, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RRC_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	BYTE bitLeastSignificant = n & 0x01;
	registers.f |= bitLeastSignificant ? CARRY : 0x00;
	n = n >> 1;
	n |= bitLeastSignificant ? 0x80 : 0x00;
	updateFlags(n, 1);
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 1;
	registers.t = 4;
}

// RRCa ya esta definido en bops

//0x10

void CPU::RLb()
{
	BYTE bitMostSignificant = registers.b & 0x80;
	BYTE tmpCarryFlag = registers.f & (~CARRY);
	registers.b = registers.b << 1;
	registers.f |= bitMostSignificant ? CARRY : 0x00;
	registers.b |= tmpCarryFlag ? 0x01 : 0x00;
	updateFlags(registers.b, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RLc()
{
	BYTE bitMostSignificant = registers.c & 0x80;
	BYTE tmpCarryFlag = registers.f & (~CARRY);
	registers.c = registers.c << 1;
	registers.f |= bitMostSignificant ? CARRY : 0x00;
	registers.c |= tmpCarryFlag ? 0x01 : 0x00;
	updateFlags(registers.c, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RLd()
{
	BYTE bitMostSignificant = registers.d & 0x80;
	BYTE tmpCarryFlag = registers.f & (~CARRY);
	registers.d = registers.d << 1;
	registers.f |= bitMostSignificant ? CARRY : 0x00;
	registers.d |= tmpCarryFlag ? 0x01 : 0x00;
	updateFlags(registers.d, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RLe()
{
	BYTE bitMostSignificant = registers.e & 0x80;
	BYTE tmpCarryFlag = registers.f & (~CARRY);
	registers.e = registers.e << 1;
	registers.f |= bitMostSignificant ? CARRY : 0x00;
	registers.e |= tmpCarryFlag ? 0x01 : 0x00;
	updateFlags(registers.e, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RLh()
{
	BYTE bitMostSignificant = registers.h & 0x80;
	BYTE tmpCarryFlag = registers.f & (~CARRY);
	registers.h = registers.h << 1;
	registers.f |= bitMostSignificant ? CARRY : 0x00;
	registers.h |= tmpCarryFlag ? 0x01 : 0x00;
	updateFlags(registers.h, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RLl()
{
	BYTE bitMostSignificant = registers.l & 0x80;
	BYTE tmpCarryFlag = registers.f & (~CARRY);
	registers.l = registers.l << 1;
	registers.f |= bitMostSignificant ? CARRY : 0x00;
	registers.l |= tmpCarryFlag ? 0x01 : 0x00;
	updateFlags(registers.l, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RL_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	BYTE bitMostSignificant = n & 0x80;
	BYTE tmpCarryFlag = registers.f & (~CARRY);
	n = n << 1;
	registers.f |= bitMostSignificant ? CARRY : 0x00;
	n |= tmpCarryFlag ? 0x01 : 0x00;
	updateFlags(n, 1);
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 1;
	registers.t = 4;
}

//RLa ya esta definida en bops

void CPU::RRb()
{
	BYTE bitLeastSignificant = registers.b & 0x01;
	BYTE tmpCarryFlag = registers.f & (~CARRY);
	registers.f |= bitLeastSignificant ? CARRY : 0x00;
	registers.b = registers.b >> 1;
	registers.b |= tmpCarryFlag ? 0x80 : 0x00;
	updateFlags(registers.b, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RRc()
{
	BYTE bitLeastSignificant = registers.c & 0x01;
	BYTE tmpCarryFlag = registers.f & (~CARRY);
	registers.f |= bitLeastSignificant ? CARRY : 0x00;
	registers.c = registers.c >> 1;
	registers.c |= tmpCarryFlag ? 0x80 : 0x00;
	updateFlags(registers.c, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RRd()
{
	BYTE bitLeastSignificant = registers.d & 0x01;
	BYTE tmpCarryFlag = registers.f & (~CARRY);
	registers.f |= bitLeastSignificant ? CARRY : 0x00;
	registers.d = registers.d >> 1;
	registers.d |= tmpCarryFlag ? 0x80 : 0x00;
	updateFlags(registers.d, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RRe()
{
	BYTE bitLeastSignificant = registers.e & 0x01;
	BYTE tmpCarryFlag = registers.f & (~CARRY);
	registers.f |= bitLeastSignificant ? CARRY : 0x00;
	registers.e = registers.e >> 1;
	registers.e |= tmpCarryFlag ? 0x80 : 0x00;
	updateFlags(registers.e, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RRh()
{
	BYTE bitLeastSignificant = registers.h & 0x01;
	BYTE tmpCarryFlag = registers.f & (~CARRY);
	registers.f |= bitLeastSignificant ? CARRY : 0x00;
	registers.h = registers.h >> 1;
	registers.h |= tmpCarryFlag ? 0x80 : 0x00;
	updateFlags(registers.h, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RRl()
{
	BYTE bitLeastSignificant = registers.l & 0x01;
	BYTE tmpCarryFlag = registers.f & (~CARRY);
	registers.f |= bitLeastSignificant ? CARRY : 0x00;
	registers.l = registers.l >> 1;
	registers.l |= tmpCarryFlag ? 0x80 : 0x00;
	updateFlags(registers.l, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::RR_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	BYTE bitLeastSignificant = n & 0x01;
	BYTE tmpCarryFlag = registers.f & (~CARRY);
	registers.f |= bitLeastSignificant ? CARRY : 0x00;
	n = n >> 1;
	n |= tmpCarryFlag ? 0x80 : 0x00;
	updateFlags(n, 1);
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 1;
	registers.t = 4;
}

// RRa ya esta definido en bOps

//0x20

void CPU::SLAb()
{
	BYTE bitMostSignificant = registers.b & 0x80;
	registers.b = registers.b << 1;
	registers.f |= bitMostSignificant?CARRY:0x00;
	updateFlags(registers.b, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SLAc()
{
	BYTE bitMostSignificant = registers.c & 0x80;
	registers.c = registers.c << 1;
	registers.f |= bitMostSignificant?CARRY:0x00;
	updateFlags(registers.c, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SLAd()
{
	BYTE bitMostSignificant = registers.d & 0x80;
	registers.d = registers.d << 1;
	registers.f |= bitMostSignificant?CARRY:0x00;
	updateFlags(registers.d, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SLAe()
{
	BYTE bitMostSignificant = registers.e & 0x80;
	registers.e = registers.e << 1;
	registers.f |= bitMostSignificant?CARRY:0x00;
	updateFlags(registers.e, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SLAh()
{
	BYTE bitMostSignificant = registers.h & 0x80;
	registers.h = registers.h << 1;
	registers.f |= bitMostSignificant?CARRY:0x00;
	updateFlags(registers.h, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SLAl()
{
	BYTE bitMostSignificant = registers.l & 0x80;
	registers.l = registers.l << 1;
	registers.f |= bitMostSignificant?CARRY:0x00;
	updateFlags(registers.l, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SLA_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	BYTE bitMostSignificant = n & 0x80;
	n = n << 1;
	registers.f |= bitMostSignificant?CARRY:0x00;
	memory->writeByte(registers.h << 8 | registers.l, n);
	updateFlags(n, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SLAa()
{
	BYTE bitMostSignificant = registers.a & 0x80;
	registers.a = registers.a << 1;
	registers.f |= bitMostSignificant?CARRY:0x00;
	updateFlags(registers.a, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SRAb()
{
	BYTE bitMostSignificant = registers.b & 0x80;
	BYTE bitLeastSignificant = registers.b & 0x01;
	registers.b = registers.b >> 1;
	registers.b |= bitMostSignificant?0x80:0x00;
	registers.f |= bitLeastSignificant?CARRY:0x00;
	updateFlags(registers.b, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SRAc()
{
	BYTE bitMostSignificant = registers.c & 0x80;
	BYTE bitLeastSignificant = registers.c & 0x01;
	registers.c = registers.c >> 1;
	registers.c |= bitMostSignificant?0x80:0x00;
	registers.f |= bitLeastSignificant?CARRY:0x00;
	updateFlags(registers.c, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SRAd()
{
	BYTE bitMostSignificant = registers.d & 0x80;
	BYTE bitLeastSignificant = registers.d & 0x01;
	registers.d = registers.d >> 1;
	registers.d |= bitMostSignificant?0x80:0x00;
	registers.f |= bitLeastSignificant?CARRY:0x00;
	updateFlags(registers.d, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SRAe()
{
	BYTE bitMostSignificant = registers.e & 0x80;
	BYTE bitLeastSignificant = registers.e & 0x01;
	registers.e = registers.e >> 1;
	registers.e |= bitMostSignificant?0x80:0x00;
	registers.f |= bitLeastSignificant?CARRY:0x00;
	updateFlags(registers.e, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SRAh()
{
	BYTE bitMostSignificant = registers.h & 0x80;
	BYTE bitLeastSignificant = registers.h & 0x01;
	registers.h = registers.h >> 1;
	registers.h |= bitMostSignificant?0x80:0x00;
	registers.f |= bitLeastSignificant?CARRY:0x00;
	updateFlags(registers.h, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SRAl()
{
	BYTE bitMostSignificant = registers.l & 0x80;
	BYTE bitLeastSignificant = registers.l & 0x01;
	registers.l = registers.l >> 1;
	registers.l |= bitMostSignificant?0x80:0x00;
	registers.f |= bitLeastSignificant?CARRY:0x00;
	updateFlags(registers.l, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SRA_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	BYTE bitMostSignificant = n & 0x80;
	BYTE bitLeastSignificant = n & 0x01;
	n = n >> 1;
	n |= bitMostSignificant?0x80:0x00;
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.f |= bitLeastSignificant?CARRY:0x00;
	updateFlags(n, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SRAa()
{
	BYTE bitMostSignificant = registers.a & 0x80;
	BYTE bitLeastSignificant = registers.a & 0x01;
	registers.a = registers.a >> 1;
	registers.a |= bitMostSignificant?0x80:0x00;
	registers.f |= bitLeastSignificant?CARRY:0x00;
	updateFlags(registers.a, 1);
	registers.m = 1;
	registers.t = 4;
}

//0x30

void CPU::SWAPb()
{
	BYTE upper = registers.b >> 4;
	BYTE lower = registers.b & 0x0F;
	registers.b = lower << 4 | upper;
	updateFlags(registers.b, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SWAPc()
{
	BYTE upper = registers.c >> 4;
	BYTE lower = registers.c & 0x0F;
	registers.c = lower << 4 | upper;
	updateFlags(registers.c, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SWAPd()
{
	BYTE upper = registers.d >> 4;
	BYTE lower = registers.d & 0x0F;
	registers.d = lower << 4 | upper;
	updateFlags(registers.d, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SWAPe()
{
	BYTE upper = registers.e >> 4;
	BYTE lower = registers.e & 0x0F;
	registers.e = lower << 4 | upper;
	updateFlags(registers.e, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SWAPh()
{
	BYTE upper = registers.h >> 4;
	BYTE lower = registers.h & 0x0F;
	registers.h = lower << 4 | upper;
	updateFlags(registers.h, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SWAPl()
{
	BYTE upper = registers.l >> 4;
	BYTE lower = registers.l & 0x0F;
	registers.l = lower << 4 | upper;
	updateFlags(registers.l, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SWAP_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	BYTE upper = n >> 4;
	BYTE lower = n & 0x0F;
	n = lower << 4 | upper;
	updateFlags(n, 1);
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SWAPa()
{
	BYTE upper = registers.a >> 4;
	BYTE lower = registers.a & 0x0F;
	registers.a = lower << 4 | upper;
	updateFlags(registers.a, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SLRb()
{
	BYTE bitLeastSignificant = registers.b & 0x01;
	registers.b = registers.b >> 1;
	registers.b &= 0xEF;
	registers.f |= bitLeastSignificant?CARRY:0x00;
	updateFlags(registers.b, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SLRc()
{
	BYTE bitLeastSignificant = registers.c & 0x01;
	registers.c = registers.c >> 1;
	registers.c &= 0xEF;
	registers.f |= bitLeastSignificant?CARRY:0x00;
	updateFlags(registers.c, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SLRd()
{
	BYTE bitLeastSignificant = registers.d & 0x01;
	registers.d = registers.d >> 1;
	registers.d &= 0xEF;
	registers.f |= bitLeastSignificant?CARRY:0x00;
	updateFlags(registers.d, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SLRe()
{
	BYTE bitLeastSignificant = registers.e & 0x01;
	registers.e = registers.e >> 1;
	registers.e &= 0xEF;
	registers.f |= bitLeastSignificant?CARRY:0x00;
	updateFlags(registers.e, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SLRh()
{
	BYTE bitLeastSignificant = registers.h & 0x01;
	registers.h = registers.h >> 1;
	registers.h &= 0xEF;
	registers.f |= bitLeastSignificant?CARRY:0x00;
	updateFlags(registers.h, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SLRl()
{
	BYTE bitLeastSignificant = registers.l & 0x01;
	registers.l = registers.l >> 1;
	registers.l &= 0xEF;
	registers.f |= bitLeastSignificant?CARRY:0x00;
	updateFlags(registers.l, 1);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SLR_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	BYTE bitLeastSignificant = n & 0x01;
	n = n >> 1;
	n &= 0xEF;
	registers.f |= bitLeastSignificant?CARRY:0x00;
	updateFlags(n, 1);
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 1;
	registers.t = 4;
}

void CPU::SLRa()
{
	BYTE bitLeastSignificant = registers.a & 0x01;
	registers.a = registers.a >> 1;
	registers.a &= 0xEF;
	registers.f |= bitLeastSignificant?CARRY:0x00;
	updateFlags(registers.a, 1);
	registers.m = 1;
	registers.t = 4;
}

//0x40

void CPU::BIT0b()
{
	updateFlags(registers.b&0x01, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT0c()
{
	updateFlags(registers.c&0x01, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT0d()
{
	updateFlags(registers.d&0x01, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT0e()
{
	updateFlags(registers.e&0x01, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT0h()
{
	updateFlags(registers.h&0x01, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT0l()
{
	updateFlags(registers.l&0x01, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT0_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	updateFlags(n&0x01, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT0a()
{
	updateFlags(registers.a&0x01, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT1b()
{
	updateFlags(registers.b&0x02, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT1c()
{
	updateFlags(registers.c&0x02, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT1d()
{
	updateFlags(registers.d&0x02, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT1e()
{
	updateFlags(registers.e&0x02, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT1h()
{
	updateFlags(registers.h&0x02, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT1l()
{
	updateFlags(registers.l&0x02, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT1_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	updateFlags(n&0x02, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT1a()
{
	updateFlags(registers.a&0x02, 1);
	registers.m = 2;
	registers.t = 8;
}

//0x50

void CPU::BIT2b()
{
	updateFlags(registers.b&0x04, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT2c()
{
	updateFlags(registers.c&0x04, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT2d()
{
	updateFlags(registers.d&0x04, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT2e()
{
	updateFlags(registers.e&0x04, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT2h()
{
	updateFlags(registers.h&0x04, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT2l()
{
	updateFlags(registers.l&0x04, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT2_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	updateFlags(n&0x04, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT2a()
{
	updateFlags(registers.a&0x04, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT3b()
{
	updateFlags(registers.b&0x08, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT3c()
{
	updateFlags(registers.c&0x08, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT3d()
{
	updateFlags(registers.d&0x08, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT3e()
{
	updateFlags(registers.e&0x08, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT3h()
{
	updateFlags(registers.h&0x08, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT3l()
{
	updateFlags(registers.l&0x08, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT3_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	updateFlags(n&0x08, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT3a()
{
	updateFlags(registers.a&0x08, 1);
	registers.m = 2;
	registers.t = 8;
}

//0x60

void CPU::BIT4b()
{
	updateFlags(registers.b&0x10, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT4c()
{
	updateFlags(registers.c&0x10, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT4d()
{
	updateFlags(registers.d&0x10, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT4e()
{
	updateFlags(registers.e&0x10, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT4h()
{
	updateFlags(registers.h&0x10, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT4l()
{
	updateFlags(registers.l&0x10, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT4_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	updateFlags(n&0x10, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT4a()
{
	updateFlags(registers.a&0x10, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT5b()
{
	updateFlags(registers.b&0x20, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT5c()
{
	updateFlags(registers.c&0x20, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT5d()
{
	updateFlags(registers.d&0x20, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT5e()
{
	updateFlags(registers.e&0x20, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT5h()
{
	updateFlags(registers.h&0x20, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT5l()
{
	updateFlags(registers.l&0x20, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT5_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	updateFlags(n&0x20, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT5a()
{
	updateFlags(registers.a&0x20, 1);
	registers.m = 2;
	registers.t = 8;
}

// 0x70

void CPU::BIT6b()
{
	updateFlags(registers.b&0x40, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT6c()
{
	updateFlags(registers.c&0x40, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT6d()
{
	updateFlags(registers.d&0x40, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT6e()
{
	updateFlags(registers.e&0x40, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT6h()
{
	updateFlags(registers.h&0x40, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT6l()
{
	updateFlags(registers.l&0x40, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT6_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	updateFlags(n&0x40, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT6a()
{
	updateFlags(registers.a&0x40, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT7b()
{
	updateFlags(registers.b&0x80, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT7c()
{
	updateFlags(registers.c&0x80, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT7d()
{
	updateFlags(registers.d&0x80, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT7e()
{
	updateFlags(registers.e&0x80, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT7h()
{
	updateFlags(registers.h&0x80, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT7l()
{
	updateFlags(registers.l&0x80, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT7_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	updateFlags(n&0x80, 1);
	registers.m = 2;
	registers.t = 8;
}

void CPU::BIT7a()
{
	updateFlags(registers.a&0x80, 1);
	registers.m = 2;
	registers.t = 8;
}

// 0x80

void CPU::RES0b()
{
	registers.b &= ~0x01;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES0c()
{
	registers.c &= ~0x01;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES0d()
{
	registers.d &= ~0x01;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES0e()
{
	registers.e &= ~0x01;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES0h()
{
	registers.h &= ~0x01;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES0l()
{
	registers.l &= ~0x01;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES0_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	registers.b &= ~0x01;
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES0a()
{
	registers.a &= ~0x01;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES1b()
{
	registers.b &= ~0x02;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES1c()
{
	registers.c &= ~0x02;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES1d()
{
	registers.d &= ~0x02;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES1e()
{
	registers.e &= ~0x02;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES1h()
{
	registers.h &= ~0x02;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES1l()
{
	registers.l &= ~0x02;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES1_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	registers.b &= ~0x02;
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES1a()
{
	registers.a &= ~0x02;
	registers.m = 2;
	registers.t = 8;
}

// 0x90

void CPU::RES2b()
{
	registers.b &= ~0x04;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES2c()
{
	registers.c &= ~0x04;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES2d()
{
	registers.d &= ~0x04;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES2e()
{
	registers.e &= ~0x04;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES2h()
{
	registers.h &= ~0x04;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES2l()
{
	registers.l &= ~0x04;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES2_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	registers.b &= ~0x04;
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES2a()
{
	registers.a &= ~0x04;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES3b()
{
	registers.b &= ~0x08;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES3c()
{
	registers.c &= ~0x08;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES3d()
{
	registers.d &= ~0x08;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES3e()
{
	registers.e &= ~0x08;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES3h()
{
	registers.h &= ~0x08;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES3l()
{
	registers.l &= ~0x08;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES3_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	registers.b &= ~0x08;
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES3a()
{
	registers.a &= ~0x08;
	registers.m = 2;
	registers.t = 8;
}

// 0xA0

void CPU::RES4b()
{
	registers.b &= ~0x10;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES4c()
{
	registers.c &= ~0x10;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES4d()
{
	registers.d &= ~0x10;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES4e()
{
	registers.e &= ~0x10;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES4h()
{
	registers.h &= ~0x10;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES4l()
{
	registers.l &= ~0x10;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES4_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	registers.b &= ~0x10;
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES4a()
{
	registers.a &= ~0x10;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES5b()
{
	registers.b &= ~0x20;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES5c()
{
	registers.c &= ~0x20;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES5d()
{
	registers.d &= ~0x20;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES5e()
{
	registers.e &= ~0x20;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES5h()
{
	registers.h &= ~0x20;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES5l()
{
	registers.l &= ~0x20;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES5_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	registers.b &= ~0x20;
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES5a()
{
	registers.a &= ~0x20;
	registers.m = 2;
	registers.t = 8;
}

// 0xB0

void CPU::RES6b()
{
	registers.b &= ~0x40;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES6c()
{
	registers.c &= ~0x40;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES6d()
{
	registers.d &= ~0x40;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES6e()
{
	registers.e &= ~0x40;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES6h()
{
	registers.h &= ~0x40;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES6l()
{
	registers.l &= ~0x40;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES6_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	registers.b &= ~0x40;
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES6a()
{
	registers.a &= ~0x40;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES7b()
{
	registers.b &= ~0x80;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES7c()
{
	registers.c &= ~0x80;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES7d()
{
	registers.d &= ~0x80;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES7e()
{
	registers.e &= ~0x80;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES7h()
{
	registers.h &= ~0x80;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES7l()
{
	registers.l &= ~0x80;
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES7_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	registers.b &= ~0x80;
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 2;
	registers.t = 8;
}

void CPU::RES7a()
{
	registers.a &= ~0x80;
	registers.m = 2;
	registers.t = 8;
}

// 0xC0

void CPU::SET0b()
{
	registers.b |= 0x01;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET0c()
{
	registers.c |= 0x01;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET0d()
{
	registers.d |= 0x01;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET0e()
{
	registers.e |= 0x01;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET0h()
{
	registers.h |= 0x01;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET0l()
{
	registers.l |= 0x01;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET0_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	n |= 0x01;
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET0a()
{
	registers.a |= 0x01;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET1b()
{
	registers.b |= 0x02;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET1c()
{
	registers.c |= 0x02;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET1d()
{
	registers.d |= 0x02;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET1e()
{
	registers.e |= 0x02;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET1h()
{
	registers.h |= 0x02;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET1l()
{
	registers.l |= 0x02;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET1_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	n |= 0x02;
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET1a()
{
	registers.a |= 0x02;
	registers.m = 2;
	registers.t = 8;
}

// 0xD0

void CPU::SET2b()
{
	registers.b |= 0x04;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET2c()
{
	registers.c |= 0x04;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET2d()
{
	registers.d |= 0x04;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET2e()
{
	registers.e |= 0x04;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET2h()
{
	registers.h |= 0x04;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET2l()
{
	registers.l |= 0x04;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET2_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	n |= 0x04;
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET2a()
{
	registers.a |= 0x04;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET3b()
{
	registers.b |= 0x08;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET3c()
{
	registers.c |= 0x08;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET3d()
{
	registers.d |= 0x08;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET3e()
{
	registers.e |= 0x08;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET3h()
{
	registers.h |= 0x08;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET3l()
{
	registers.l |= 0x08;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET3_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	n |= 0x08;
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET3a()
{
	registers.a |= 0x08;
	registers.m = 2;
	registers.t = 8;
}

// 0xE0

void CPU::SET4b()
{
	registers.b |= 0x10;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET4c()
{
	registers.c |= 0x10;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET4d()
{
	registers.d |= 0x10;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET4e()
{
	registers.e |= 0x10;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET4h()
{
	registers.h |= 0x10;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET4l()
{
	registers.l |= 0x10;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET4_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	n |= 0x10;
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET4a()
{
	registers.a |= 0x10;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET5b()
{
	registers.b |= 0x20;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET5c()
{
	registers.c |= 0x20;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET5d()
{
	registers.d |= 0x20;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET5e()
{
	registers.e |= 0x20;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET5h()
{
	registers.h |= 0x20;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET5l()
{
	registers.l |= 0x20;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET5_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	n |= 0x20;
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET5a()
{
	registers.a |= 0x20;
	registers.m = 2;
	registers.t = 8;
}

// 0xF0

void CPU::SET6b()
{
	registers.b |= 0x40;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET6c()
{
	registers.c |= 0x40;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET6d()
{
	registers.d |= 0x40;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET6e()
{
	registers.e |= 0x40;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET6h()
{
	registers.h |= 0x40;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET6l()
{
	registers.l |= 0x40;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET6_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	n |= 0x40;
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET6a()
{
	registers.a |= 0x40;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET7b()
{
	registers.b |= 0x80;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET7c()
{
	registers.c |= 0x80;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET7d()
{
	registers.d |= 0x80;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET7e()
{
	registers.e |= 0x80;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET7h()
{
	registers.h |= 0x80;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET7l()
{
	registers.l |= 0x80;
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET7_hl_()
{
	BYTE n = memory->readByte(registers.h << 8 | registers.l);
	n |= 0x80;
	memory->writeByte(registers.h << 8 | registers.l, n);
	registers.m = 2;
	registers.t = 8;
}

void CPU::SET7a()
{
	registers.a |= 0x80;
	registers.m = 2;
	registers.t = 8;
}