 #include "Debug.hpp"

Debug::Debug(CPU *cpu): cpu(cpu)
{
	finish = false;
	memory = cpu->getMemory();


	memset(&bOps, 0, sizeof(bOps));
	memset(&eOps, 0, sizeof(eOps));
	//0x00
	bOps[0] = &Debug::NOP;
	bOps[1] = &Debug::LDbcnn;
	bOps[2] = &Debug::LD_bc_a;
	bOps[3] = &Debug::INCbc;
	bOps[4] = &Debug::INCb;
	bOps[5] = &Debug::DECb;
	bOps[6] = &Debug::LDbn;
	bOps[7] = &Debug::RLCa;
	bOps[8] = &Debug::LD_nn_sp;
	bOps[9] = &Debug::ADDhlbc;
	bOps[10] = &Debug::LDa_bc_;
	bOps[11] = &Debug::DECbc;
	bOps[12] = &Debug::INCc;
	bOps[13] = &Debug::DECc;
	bOps[14] = &Debug::LDcn;
	bOps[15] = &Debug::RRCa;
	//0x10
	bOps[16] = &Debug::DJNZn;
	bOps[17] = &Debug::LDdenn;
	bOps[18] = &Debug::LD_de_a;
	bOps[19] = &Debug::INCde;
	bOps[20] = &Debug::INCd;
	bOps[21] = &Debug::DECd;
	bOps[22] = &Debug::LDdn;
	bOps[23] = &Debug::RLa;
	bOps[24] = &Debug::JRn;
	bOps[25] = &Debug::ADDhlde;
	bOps[26] = &Debug::LDa_de_;
	bOps[27] = &Debug::DECde;
	bOps[28] = &Debug::INCe;
	bOps[29] = &Debug::DECe;
	bOps[30] = &Debug::LDen;
	bOps[31] = &Debug::RRa;
	//0x20
	bOps[32] = &Debug::JRNZn;
	bOps[33] = &Debug::LDhlnn;
	bOps[34] = &Debug::LDI_hl_a;
	bOps[35] = &Debug::INChl;
	bOps[36] = &Debug::INCh;
	bOps[37] = &Debug::DECh;
	bOps[38] = &Debug::LDhn;
	bOps[39] = &Debug::DAA;
	bOps[40] = &Debug::JRZn;
	bOps[41] = &Debug::ADDhlhl;
	bOps[42] = &Debug::LDIa_hl_;
	bOps[43] = &Debug::DEChl;
	bOps[44] = &Debug::INCl;
	bOps[45] = &Debug::DECl;
	bOps[46] = &Debug::LDln;
	bOps[47] = &Debug::CPL;
	//0x30
	bOps[48] = &Debug::JRNCn;
	bOps[49] = &Debug::LDspnn;
	bOps[50] = &Debug::LDD_hl_a;
	bOps[51] = &Debug::INCsp;
	bOps[52] = &Debug::INC_hl_;
	bOps[53] = &Debug::DEC_hl_;
	bOps[54] = &Debug::LD_hl_n;
	bOps[55] = &Debug::SCF;
	bOps[56] = &Debug::JRCn;
	bOps[57] = &Debug::ADDhlsp;
	bOps[58] = &Debug::LDDa_hl_;
	bOps[59] = &Debug::DECsp;
	bOps[60] = &Debug::INCa;
	bOps[61] = &Debug::DECa;
	bOps[62] = &Debug::LDan;
	bOps[63] = &Debug::CCF;
	//0x40
	bOps[64] = &Debug::LDbb;
	bOps[65] = &Debug::LDbc;
	bOps[66] = &Debug::LDbd;
	bOps[67] = &Debug::LDbe;
	bOps[68] = &Debug::LDbh;
	bOps[69] = &Debug::LDbl;
	bOps[70] = &Debug::LDb_hl_;
	bOps[71] = &Debug::LDba;
	bOps[72] = &Debug::LDcb;
	bOps[73] = &Debug::LDcc;
	bOps[74] = &Debug::LDcd;
	bOps[75] = &Debug::LDce;
	bOps[76] = &Debug::LDch;
	bOps[77] = &Debug::LDcl;
	bOps[78] = &Debug::LDc_hl_;
	bOps[79] = &Debug::LDca;
	//0x50
	bOps[80] = &Debug::LDdb;
	bOps[81] = &Debug::LDdc;
	bOps[82] = &Debug::LDdd;
	bOps[83] = &Debug::LDde;
	bOps[84] = &Debug::LDdh;
	bOps[85] = &Debug::LDdl;
	bOps[86] = &Debug::LDd_hl_;
	bOps[87] = &Debug::LDda;
	bOps[88] = &Debug::LDeb;
	bOps[89] = &Debug::LDec;
	bOps[90] = &Debug::LDed;
	bOps[91] = &Debug::LDee;
	bOps[92] = &Debug::LDeh;
	bOps[93] = &Debug::LDel;
	bOps[94] = &Debug::LDe_hl_;
	bOps[95] = &Debug::LDea;
	//0x60
	bOps[96] = &Debug::LDhb;
	bOps[97] = &Debug::LDhc;
	bOps[98] = &Debug::LDhd;
	bOps[99] = &Debug::LDhe;
	bOps[100] = &Debug::LDhh;
	bOps[101] = &Debug::LDhl;
	bOps[102] = &Debug::LDh_hl_;
	bOps[103] = &Debug::LDha;
	bOps[104] = &Debug::LDlb;
	bOps[105] = &Debug::LDlc;
	bOps[106] = &Debug::LDld;
	bOps[107] = &Debug::LDle;
	bOps[108] = &Debug::LDlh;
	bOps[109] = &Debug::LDll;
	bOps[110] = &Debug::LDl_hl_;
	bOps[111] = &Debug::LDla;
	//70
	bOps[112] = &Debug::LD_hl_b;
	bOps[113] = &Debug::LD_hl_c;
	bOps[114] = &Debug::LD_hl_d;
	bOps[115] = &Debug::LD_hl_e;
	bOps[116] = &Debug::LD_hl_h;
	bOps[117] = &Debug::LD_hl_l;
	bOps[118] = &Debug::HALT;
	bOps[119] = &Debug::LD_hl_a;
	bOps[120] = &Debug::LDab;
	bOps[121] = &Debug::LDac;
	bOps[122] = &Debug::LDad;
	bOps[123] = &Debug::LDae;
	bOps[124] = &Debug::LDah;
	bOps[125] = &Debug::LDal;
	bOps[126] = &Debug::LDa_hl_;
	bOps[127] = &Debug::LDaa;
	//0x80
	bOps[128] = &Debug::ADDab;
	bOps[129] = &Debug::ADDac;
	bOps[130] = &Debug::ADDad;
	bOps[131] = &Debug::ADDae;
	bOps[132] = &Debug::ADDah;
	bOps[133] = &Debug::ADDal;
	bOps[134] = &Debug::ADDa_hl_;
	bOps[135] = &Debug::ADDaa;
	bOps[136] = &Debug::ADCab;
	bOps[137] = &Debug::ADCac;
	bOps[138] = &Debug::ADCad;
	bOps[139] = &Debug::ADCae;
	bOps[140] = &Debug::ADCah;
	bOps[141] = &Debug::ADCal;
	bOps[142] = &Debug::ADCa_hl_;
	bOps[143] = &Debug::ADCaa;
	//0x90
	bOps[144] = &Debug::SUBab;
	bOps[145] = &Debug::SUBac;
	bOps[146] = &Debug::SUBad;
	bOps[147] = &Debug::SUBae;
	bOps[148] = &Debug::SUBah;
	bOps[149] = &Debug::SUBal;
	bOps[150] = &Debug::SUBa_hl_;
	bOps[151] = &Debug::SUBaa;
	bOps[152] = &Debug::SBCab;
	bOps[153] = &Debug::SBCac;
	bOps[154] = &Debug::SBCad;
	bOps[155] = &Debug::SBCae;
	bOps[156] = &Debug::SBCah;
	bOps[157] = &Debug::SBCal;
	bOps[158] = &Debug::SBCa_hl_;
	bOps[159] = &Debug::SBCaa;
	//0xA0
	bOps[160] = &Debug::ANDb;
	bOps[161] = &Debug::ANDc;
	bOps[162] = &Debug::ANDd;
	bOps[163] = &Debug::ANDe;
	bOps[164] = &Debug::ANDh;
	bOps[165] = &Debug::ANDl;
	bOps[166] = &Debug::AND_hl_;
	bOps[167] = &Debug::ANDa;
	bOps[168] = &Debug::XORb;
	bOps[169] = &Debug::XORc;
	bOps[170] = &Debug::XORd;
	bOps[171] = &Debug::XORe;
	bOps[172] = &Debug::XORh;
	bOps[173] = &Debug::XORl;
	bOps[174] = &Debug::XOR_hl_;
	bOps[175] = &Debug::XORa;
	//0xB0
	bOps[176] = &Debug::ORb;
	bOps[177] = &Debug::ORc;
	bOps[178] = &Debug::ORd;
	bOps[179] = &Debug::ORe;
	bOps[180] = &Debug::ORh;
	bOps[181] = &Debug::ORl;
	bOps[182] = &Debug::OR_hl_;
	bOps[183] = &Debug::ORa;
	bOps[184] = &Debug::CPb;
	bOps[185] = &Debug::CPc;
	bOps[186] = &Debug::CPd;
	bOps[187] = &Debug::CPe;
	bOps[188] = &Debug::CPh;
	bOps[189] = &Debug::CPl;
	bOps[190] = &Debug::CP_hl_;
	bOps[191] = &Debug::CPa;
	//0xC0
	bOps[192] = &Debug::RETNZ;
	bOps[193] = &Debug::POPbc;
	bOps[194] = &Debug::JPNZnn;
	bOps[195] = &Debug::JPnn;
	bOps[196] = &Debug::CALLNZnn;
	bOps[197] = &Debug::PUSHbc;
	bOps[198] = &Debug::ADDan;
	bOps[199] = &Debug::RST0;
	bOps[200] = &Debug::RETZ;
	bOps[201] = &Debug::RET;
	bOps[202] = &Debug::JPZnn;
	//bOps[203] = &Debug::; Extra Ops
	bOps[204] = &Debug::CALLZnn;
	bOps[205] = &Debug::CALLnn;
	bOps[206] = &Debug::ADCan;
	bOps[207] = &Debug::RST8;
	//0xD0
	bOps[208] = &Debug::RETNC;
	bOps[209] = &Debug::POPde;
	bOps[210] = &Debug::JPNCnn;
	//bOps[211] = &Debug::;
	bOps[212] = &Debug::CALLNCnn;
	bOps[213] = &Debug::PUSHde;
	bOps[214] = &Debug::SUBan;
	bOps[215] = &Debug::RST10;
	bOps[216] = &Debug::RETC;
	bOps[217] = &Debug::RETI;
	bOps[218] = &Debug::JPCnn;
	bOps[219] = &Debug::extraOPDecode; //Extra ops
	bOps[220] = &Debug::CALLCnn;
	//bOps[221] = &Debug::;
	bOps[222] = &Debug::SBCan;
	bOps[223] = &Debug::RST18;
	//0xE0
	bOps[224] = &Debug::LDH_n_a;
	bOps[225] = &Debug::POPhl;
	bOps[226] = &Debug::LDH_c_a;
	//bOps[227] = &Debug::;
	//bOps[228] = &Debug::;
	bOps[229] = &Debug::PUSHhl;
	bOps[230] = &Debug::ANDn;
	bOps[231] = &Debug::RST20;
	bOps[232] = &Debug::ADDspn;
	bOps[233] = &Debug::JPhl;
	bOps[234] = &Debug::LD_nn_a;
	//bOps[235] = &Debug::;
	//bOps[236] = &Debug::;
	//bOps[237] = &Debug::;
	bOps[238] = &Debug::XORn;
	bOps[239] = &Debug::RST28;
	//0xF0
	bOps[240] = &Debug::LDHa_n_;
	bOps[241] = &Debug::POPaf;
	//bOps[242] = &Debug::;
	bOps[243] = &Debug::DI;
	//bOps[244] = &Debug::;
	bOps[245] = &Debug::PUSHaf;
	bOps[246] = &Debug::ORn;
	bOps[247] = &Debug::RST30;
	bOps[248] = &Debug::LDHLspn;
	bOps[249] = &Debug::LDsphl;
	bOps[250] = &Debug::LDa_nn_;
	bOps[251] = &Debug::EI;
	//bOps[252] = &Debug::;
	//bOps[253] = &Debug::;
	bOps[254] = &Debug::CPn;
	bOps[255] = &Debug::RST38;




	eOps[0] = &Debug::RLCb;
	eOps[1] = &Debug::RLCc;
	eOps[2] = &Debug::RLCd;
	eOps[3] = &Debug::RLCe;
	eOps[4] = &Debug::RLCh;
	eOps[5] = &Debug::RLCl;
	eOps[6] = &Debug::RLC_hl_;
	eOps[7] = &Debug::RLCa;
	eOps[8] = &Debug::RRCb;
	eOps[9] = &Debug::RRCc;
	eOps[10] = &Debug::RRCd;
	eOps[11] = &Debug::RRCe;
	eOps[12] = &Debug::RRCh;
	eOps[13] = &Debug::RRCl;
	eOps[14] = &Debug::RRC_hl_;
	eOps[15] = &Debug::RRCa;
	//0x10
	eOps[16] = &Debug::RLb;
	eOps[17] = &Debug::RLc;
	eOps[18] = &Debug::RLd;
	eOps[19] = &Debug::RLe;
	eOps[20] = &Debug::RLh;
	eOps[21] = &Debug::RLl;
	eOps[22] = &Debug::RL_hl_;
	eOps[23] = &Debug::RLa;
	eOps[24] = &Debug::RRb;
	eOps[25] = &Debug::RRc;
	eOps[26] = &Debug::RRd;
	eOps[27] = &Debug::RRe;
	eOps[28] = &Debug::RRh;
	eOps[29] = &Debug::RRl;
	eOps[30] = &Debug::RR_hl_;
	eOps[31] = &Debug::RRa;
	//0x20
	eOps[32] = &Debug::SLAb;
	eOps[33] = &Debug::SLAc;
	eOps[34] = &Debug::SLAd;
	eOps[35] = &Debug::SLAe;
	eOps[36] = &Debug::SLAh;
	eOps[37] = &Debug::SLAl;
	eOps[38] = &Debug::SLA_hl_;
	eOps[39] = &Debug::SLAa;
	eOps[40] = &Debug::SRAb;
	eOps[41] = &Debug::SRAc;
	eOps[42] = &Debug::SRAd;
	eOps[43] = &Debug::SRAe;
	eOps[44] = &Debug::SRAh;
	eOps[45] = &Debug::SRAl;
	eOps[46] = &Debug::SRA_hl_;
	eOps[47] = &Debug::SRAa;
	//0x30
	eOps[48] = &Debug::SWAPb;
	eOps[49] = &Debug::SWAPc;
	eOps[50] = &Debug::SWAPd;
	eOps[51] = &Debug::SWAPe;
	eOps[52] = &Debug::SWAPh;
	eOps[53] = &Debug::SWAPl;
	eOps[54] = &Debug::SWAP_hl_;
	eOps[55] = &Debug::SWAPa;
	eOps[56] = &Debug::SLRb;
	eOps[57] = &Debug::SLRc;
	eOps[58] = &Debug::SLRd;
	eOps[59] = &Debug::SLRe;
	eOps[60] = &Debug::SLRh;
	eOps[61] = &Debug::SLRl;
	eOps[62] = &Debug::SLR_hl_;
	eOps[63] = &Debug::SLRa;
	//0x40
	eOps[64] = &Debug::BIT0b;
	eOps[65] = &Debug::BIT0c;
	eOps[66] = &Debug::BIT0d;
	eOps[67] = &Debug::BIT0e;
	eOps[68] = &Debug::BIT0h;
	eOps[69] = &Debug::BIT0l;
	eOps[70] = &Debug::BIT0_hl_;
	eOps[71] = &Debug::BIT0a;
	eOps[72] = &Debug::BIT1b;
	eOps[73] = &Debug::BIT1c;
	eOps[74] = &Debug::BIT1d;
	eOps[75] = &Debug::BIT1e;
	eOps[76] = &Debug::BIT1h;
	eOps[77] = &Debug::BIT1l;
	eOps[78] = &Debug::BIT1_hl_;
	eOps[79] = &Debug::BIT1a;
	//0x50
	eOps[80] = &Debug::BIT2b;
	eOps[81] = &Debug::BIT2c;
	eOps[82] = &Debug::BIT2d;
	eOps[83] = &Debug::BIT2e;
	eOps[84] = &Debug::BIT2h;
	eOps[85] = &Debug::BIT2l;
	eOps[86] = &Debug::BIT2_hl_;
	eOps[87] = &Debug::BIT2a;
	eOps[88] = &Debug::BIT3b;
	eOps[89] = &Debug::BIT3c;
	eOps[90] = &Debug::BIT3d;
	eOps[91] = &Debug::BIT3e;
	eOps[92] = &Debug::BIT3h;
	eOps[93] = &Debug::BIT3l;
	eOps[94] = &Debug::BIT3_hl_;
	eOps[95] = &Debug::BIT3a;
	//0x60
	eOps[96] = &Debug::BIT4b;
	eOps[97] = &Debug::BIT4c;
	eOps[98] = &Debug::BIT4d;
	eOps[99] = &Debug::BIT4e;
	eOps[100] = &Debug::BIT4h;
	eOps[101] = &Debug::BIT4l;
	eOps[102] = &Debug::BIT4_hl_;
	eOps[103] = &Debug::BIT4a;
	eOps[104] = &Debug::BIT5b;
	eOps[105] = &Debug::BIT5c;
	eOps[106] = &Debug::BIT5d;
	eOps[107] = &Debug::BIT5e;
	eOps[108] = &Debug::BIT5h;
	eOps[109] = &Debug::BIT5l;
	eOps[110] = &Debug::BIT5_hl_;
	eOps[111] = &Debug::BIT5a;
	//0x70
	eOps[112] = &Debug::BIT6b;
	eOps[113] = &Debug::BIT6c;
	eOps[114] = &Debug::BIT6d;
	eOps[115] = &Debug::BIT6e;
	eOps[116] = &Debug::BIT6h;
	eOps[117] = &Debug::BIT6l;
	eOps[118] = &Debug::BIT6_hl_;
	eOps[119] = &Debug::BIT6a;
	eOps[120] = &Debug::BIT7b;
	eOps[121] = &Debug::BIT7c;
	eOps[122] = &Debug::BIT7d;
	eOps[123] = &Debug::BIT7e;
	eOps[124] = &Debug::BIT7h;
	eOps[125] = &Debug::BIT7l;
	eOps[126] = &Debug::BIT7_hl_;
	eOps[127] = &Debug::BIT7a;
	//0x80
	eOps[128] = &Debug::RES0b;
	eOps[129] = &Debug::RES0c;
	eOps[130] = &Debug::RES0d;
	eOps[131] = &Debug::RES0e;
	eOps[132] = &Debug::RES0h;
	eOps[133] = &Debug::RES0l;
	eOps[134] = &Debug::RES0_hl_;
	eOps[135] = &Debug::RES0a;
	eOps[136] = &Debug::RES1b;
	eOps[137] = &Debug::RES1c;
	eOps[138] = &Debug::RES1d;
	eOps[139] = &Debug::RES1e;
	eOps[140] = &Debug::RES1h;
	eOps[141] = &Debug::RES1l;
	eOps[142] = &Debug::RES1_hl_;
	eOps[143] = &Debug::RES1a;
	//0x90
	eOps[144] = &Debug::RES2b;
	eOps[145] = &Debug::RES2c;
	eOps[146] = &Debug::RES2d;
	eOps[147] = &Debug::RES2e;
	eOps[148] = &Debug::RES2h;
	eOps[149] = &Debug::RES2l;
	eOps[150] = &Debug::RES2_hl_;
	eOps[151] = &Debug::RES2a;
	eOps[152] = &Debug::RES3b;
	eOps[153] = &Debug::RES3c;
	eOps[154] = &Debug::RES3d;
	eOps[155] = &Debug::RES3e;
	eOps[156] = &Debug::RES3h;
	eOps[157] = &Debug::RES3l;
	eOps[158] = &Debug::RES3_hl_;
	eOps[159] = &Debug::RES3a;
	//0xA0
	eOps[160] = &Debug::RES4b;
	eOps[161] = &Debug::RES4c;
	eOps[162] = &Debug::RES4d;
	eOps[163] = &Debug::RES4e;
	eOps[164] = &Debug::RES4h;
	eOps[165] = &Debug::RES4l;
	eOps[166] = &Debug::RES4_hl_;
	eOps[167] = &Debug::RES4a;
	eOps[168] = &Debug::RES5b;
	eOps[169] = &Debug::RES5c;
	eOps[170] = &Debug::RES5d;
	eOps[171] = &Debug::RES5e;
	eOps[172] = &Debug::RES5h;
	eOps[173] = &Debug::RES5l;
	eOps[174] = &Debug::RES5_hl_;
	eOps[175] = &Debug::RES5a;
	//0xB0
	eOps[176] = &Debug::RES6b;
	eOps[177] = &Debug::RES6c;
	eOps[178] = &Debug::RES6d;
	eOps[179] = &Debug::RES6e;
	eOps[180] = &Debug::RES6h;
	eOps[181] = &Debug::RES6l;
	eOps[182] = &Debug::RES6_hl_;
	eOps[183] = &Debug::RES6a;
	eOps[184] = &Debug::RES7b;
	eOps[185] = &Debug::RES7c;
	eOps[186] = &Debug::RES7d;
	eOps[187] = &Debug::RES7e;
	eOps[188] = &Debug::RES7h;
	eOps[189] = &Debug::RES7l;
	eOps[190] = &Debug::RES7_hl_;
	eOps[191] = &Debug::RES7a;
	//0xC0
	eOps[192] = &Debug::SET0b;
	eOps[193] = &Debug::SET0c;
	eOps[194] = &Debug::SET0d;
	eOps[195] = &Debug::SET0e;
	eOps[196] = &Debug::SET0h;
	eOps[197] = &Debug::SET0l;
	eOps[198] = &Debug::SET0_hl_;
	eOps[199] = &Debug::SET0a;
	eOps[200] = &Debug::SET1b;
	eOps[201] = &Debug::SET1c;
	eOps[202] = &Debug::SET1d;
	eOps[203] = &Debug::SET1e;
	eOps[204] = &Debug::SET1h;
	eOps[205] = &Debug::SET1l;
	eOps[206] = &Debug::SET1_hl_;
	eOps[207] = &Debug::SET1a;
	//0xD0
	eOps[208] = &Debug::SET2b;
	eOps[209] = &Debug::SET2c;
	eOps[210] = &Debug::SET2d;
	eOps[211] = &Debug::SET2e;
	eOps[212] = &Debug::SET2h;
	eOps[213] = &Debug::SET2l;
	eOps[214] = &Debug::SET2_hl_;
	eOps[215] = &Debug::SET2a;
	eOps[216] = &Debug::SET3b;
	eOps[217] = &Debug::SET3c;
	eOps[218] = &Debug::SET3d;
	eOps[219] = &Debug::SET3e;
	eOps[220] = &Debug::SET3h;
	eOps[221] = &Debug::SET3l;
	eOps[222] = &Debug::SET3_hl_;
	eOps[223] = &Debug::SET3a;
	//0xE0
	eOps[224] = &Debug::SET4b;
	eOps[225] = &Debug::SET4c;
	eOps[226] = &Debug::SET4d;
	eOps[227] = &Debug::SET4e;
	eOps[228] = &Debug::SET4h;
	eOps[229] = &Debug::SET4l;
	eOps[230] = &Debug::SET4_hl_;
	eOps[231] = &Debug::SET4a;
	eOps[232] = &Debug::SET5b;
	eOps[233] = &Debug::SET5c;
	eOps[234] = &Debug::SET5d;
	eOps[235] = &Debug::SET5e;
	eOps[236] = &Debug::SET5h;
	eOps[237] = &Debug::SET5l;
	eOps[238] = &Debug::SET5_hl_;
	eOps[239] = &Debug::SET5a;
	//0xF0
	eOps[240] = &Debug::SET6b;
	eOps[241] = &Debug::SET6c;
	eOps[242] = &Debug::SET6d;
	eOps[243] = &Debug::SET6e;
	eOps[244] = &Debug::SET6h;
	eOps[245] = &Debug::SET6l;
	eOps[246] = &Debug::SET6_hl_;
	eOps[247] = &Debug::SET6a;
	eOps[248] = &Debug::SET7b;
	eOps[249] = &Debug::SET7c;
	eOps[250] = &Debug::SET7d;
	eOps[251] = &Debug::SET7e;
	eOps[252] = &Debug::SET7h;
	eOps[253] = &Debug::SET7l;
	eOps[254] = &Debug::SET7_hl_;
	eOps[255] = &Debug::SET7a;
}

void Debug::runDebug()
{
	while(!finish)
	{
		std::vector<std::string> arguments;
		std::string command, line, argument;
		std::cout << "debug> ";

		getline(std::cin, line);
		std::istringstream iss(line);
	    iss >> command;
	    while(iss >> argument) {
	        arguments.push_back(argument);
	    }
	    if (command == "exit" || command == "quit"){
	    	finish = true;
	    }else if(command == "run"){
	    	runProgram();
	    }else if(command == "step" || command == "s"){
	    	step();
	    }else if(command == "disasm" || command == "d"){
	    	WORD count = 0;
	    	WORD address = 0;
	    	if (arguments.size() != 0)
	    	{
	    		if (arguments.size() == 1){
	    			count = atoi(arguments.at(0).c_str());
	    		}else{
	    			//std::string str_address = arguments.at(0);
	    			//str_address.erase(0,2);
	    			address = std::stoul(arguments.at(0), nullptr, 16);
	    			count = atoi(arguments.at(1).c_str());
	    		}	    		
	    	}
	    	disasm(address, count);
	    }else if(command == "print" || command == "p"){
	    	if (!arguments.size()){
	    		std::cout << "Lista de argumentos vacia." << std::endl;
	    	}
	    	for (std::vector<std::string>::iterator it = arguments.begin(); it != arguments.end(); it++){
	    		char * result;
	    		if (*it=="a"){
	    			result = showRegister(6);
	    		}else if (*it == "b"){
	    			result = showRegister(0);
	    		}else if (*it == "c"){
	    			result = showRegister(1);
	    		}else if (*it == "d"){
	    			result = showRegister(2);
	    		}else if (*it == "e"){
	    			result = showRegister(3);
	    		}else if (*it == "h"){
	    			result = showRegister(4);
	    		}else if (*it == "l"){
	    			result = showRegister(5);
	    		}else if (*it == "a"){
	    			result = showRegister(6);
	    		}else if (*it == "f"){
	    			result = showRegister(7);
	    		}else if (*it == "sp"){
	    			result = showRegister(8);
	    		}else if (*it == "pc"){
	    			result = showRegister(9);
	    		}else if (*it == "af"){
	    			result = showRegister(10);
	    		}else if (*it == "bc"){
	    			result = showRegister(11);
	    		}else if (*it == "de"){
	    			result = showRegister(12);
	    		}else if (*it == "hl"){
	    			result = showRegister(13);
	    		}else if (*it == "breakpoints" || *it == "bp"){
	    			result = showBreakpoints();
	    		}
	    		std::cout << result << std::endl;
	    	}
	    }else if(command == "set"){
	    	if (!arguments.size()){
	    		std::cout << "Lista de argumentos vacia." << std::endl;
	    	}else{
		    	if (arguments.size() < 2){
					std::cout << "No se ha especificado el nuevo valor" << std::endl;
		    	}else{
		    		if (arguments.at(1).at(0) == '0' && arguments.at(1).at(1) == 'x'){
		    			if (arguments.at(0) =="a"){
			    			setRegister(6, std::stoul(arguments.at(1), nullptr, 16));
			    		}else if (arguments.at(0) == "b"){
			    			setRegister(0, std::stoul(arguments.at(1), nullptr, 16));
			    		}else if (arguments.at(0) == "c"){
			    			setRegister(1, std::stoul(arguments.at(1), nullptr, 16));
			    		}else if (arguments.at(0) == "d"){
			    			setRegister(2, std::stoul(arguments.at(1), nullptr, 16));
			    		}else if (arguments.at(0) == "e"){
			    			setRegister(3, std::stoul(arguments.at(1), nullptr, 16));
			    		}else if (arguments.at(0) == "h"){
			    			setRegister(4, std::stoul(arguments.at(1), nullptr, 16));
			    		}else if (arguments.at(0) == "l"){
			    			setRegister(5, std::stoul(arguments.at(1), nullptr, 16));
			    		}else if (arguments.at(0) == "a"){
			    			setRegister(6, std::stoul(arguments.at(1), nullptr, 16));
			    		}else if (arguments.at(0) == "f"){
			    			setRegister(7, std::stoul(arguments.at(1), nullptr, 16));
			    		}else if (arguments.at(0) == "sp"){
			    			setRegister(8, std::stoul(arguments.at(1), nullptr, 16));
			    		}else if (arguments.at(0) == "pc"){
			    			setRegister(9, std::stoul(arguments.at(1), nullptr, 16));
			    		}else if (arguments.at(0) == "af"){
			    			setRegister(10, std::stoul(arguments.at(1), nullptr, 16));
			    		}else if (arguments.at(0) == "bc"){
			    			setRegister(11, std::stoul(arguments.at(1), nullptr, 16));
			    		}else if (arguments.at(0) == "de"){
			    			setRegister(12, std::stoul(arguments.at(1), nullptr, 16));
			    		}else if (arguments.at(0) == "hl"){
			    			setRegister(13, std::stoul(arguments.at(1), nullptr, 16));
			    		}else if (arguments.at(0) == "breakpoints" || arguments.at(0) == "bp"){
			    			setBreakpoint(std::stoul(arguments.at(1), nullptr, 16));
			    		}else{
			    			std::cout << "Opción no reconocida: " << arguments.at(0) << std::endl;
			    		}
		    		}else{
			    		if (arguments.at(0) =="a"){
			    			setRegister(6, atoi(arguments.at(1).c_str()));
			    		}else if (arguments.at(0) == "b"){
			    			setRegister(0, atoi(arguments.at(1).c_str()));
			    		}else if (arguments.at(0) == "c"){
			    			setRegister(1, atoi(arguments.at(1).c_str()));
			    		}else if (arguments.at(0) == "d"){
			    			setRegister(2, atoi(arguments.at(1).c_str()));
			    		}else if (arguments.at(0) == "e"){
			    			setRegister(3, atoi(arguments.at(1).c_str()));
			    		}else if (arguments.at(0) == "h"){
			    			setRegister(4, atoi(arguments.at(1).c_str()));
			    		}else if (arguments.at(0) == "l"){
			    			setRegister(5, atoi(arguments.at(1).c_str()));
			    		}else if (arguments.at(0) == "a"){
			    			setRegister(6, atoi(arguments.at(1).c_str()));
			    		}else if (arguments.at(0) == "f"){
			    			setRegister(7, atoi(arguments.at(1).c_str()));
			    		}else if (arguments.at(0) == "sp"){
			    			setRegister(8, atoi(arguments.at(1).c_str()));
			    		}else if (arguments.at(0) == "pc"){
			    			setRegister(9, atoi(arguments.at(1).c_str()));
			    		}else if (arguments.at(0) == "af"){
			    			setRegister(10, atoi(arguments.at(1).c_str()));
			    		}else if (arguments.at(0) == "bc"){
			    			setRegister(11, atoi(arguments.at(1).c_str()));
			    		}else if (arguments.at(0) == "de"){
			    			setRegister(12, atoi(arguments.at(1).c_str()));
			    		}else if (arguments.at(0) == "hl"){
			    			setRegister(13, atoi(arguments.at(1).c_str()));
			    		}else if (arguments.at(0) == "breakpoints" || arguments.at(0) == "bp"){
			    			setBreakpoint(atoi(arguments.at(1).c_str()));
			    		}else{
			    			std::cout << "Opción no reconocida: " << arguments.at(0) << std::endl;
			    		}
		    		}
		    	}
		    }

	    }else if(command == "delete"){
	    	if (!arguments.size()){
	    		std::cout << "No ha especificado que desea eliminar" << std::endl;
	    	}else{
	    		if (arguments.at(0) == "breakpoint" || arguments.at(0) == "bp"){
	    			if (arguments.size() <= 1){
	    				std::cout << "No has indicado que breakpoint deseas eliminar" << std::endl;
	    			}else{
	    				for (std::vector<std::string>::iterator it = arguments.begin()+1; it != arguments.end(); it++){
	    					if ((*it).length() > 2){
	    						if ((*it).at(0) == '0' && (*it).at(1) == 'x'){
	    							removeBreakpoint(std::stoul(*it, nullptr, 16), true);
	    						}else{
	    							removeBreakpoint(atoi((*it).c_str()), false);
	    						}
	    					}else{
	    						removeBreakpoint(atoi((*it).c_str()), false);
	    					}
	    				}
	    			}
	    		}
	    	}
	    }else if (command == "dump"){
	    	if (arguments.empty()){
	    		dumpRAM(0,0);
	    	}else{
	    		dumpRAM(std::stoul(arguments.at(0), nullptr, 16), atoi(arguments.at(1).c_str()));
	    	}
	    	
	    }else{
	    	std::cout << "Comando no reconocido: " << command << std::endl;
	    }
	}
}

void Debug::runProgram()
{
	bool finish = false;
	while(!finish){
		std::vector<SHORT>::iterator it;
		it = std::find(breakpoints.begin(), breakpoints.end(), cpu->getRegisters()->pc);
		if (it != breakpoints.end() && lastStoppedAddress != *it)
		{
			finish=true;
			std::cout << "Programa detenido en un breakpoint: " << intToHex(*it, 16) << std::endl;
			lastStoppedAddress = *it;
		}else{
			cpu->step();
			lastStoppedAddress = 0;
		}
	}
}

void Debug::step()
{
	// Eliminamos la comprobacion de breakpoints en un paso puesto que en un
	// solo paso no tiene sentido.
	/*std::vector<SHORT>::iterator it;
	it = std::find(breakpoints.begin(), breakpoints.end(), cpu->getRegisters()->pc);
	if (it != breakpoints.end())
	{
		finish=true;
		std::cout << "Programa detenido en un breakpoint: " << intToHex(*it, 16) << std::endl;
	}else{*/
		cpu->step();
	//}
}

void Debug::dumpRAM(SHORT address, SHORT count){
	if (count == 0){
		count = 10;
	}
	if (address == 0){
		address = cpu->getRegisters()->pc;
	}
	std::cout << "\t" << "00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F" <<std::endl;
	std::cout << "\t" << "-----------------------------------------------" <<std::endl;
	for (int i = 0; i < count; i++){
		if ((address+i*16) >= 1024){
			break;
 		}
		std::cout << intToHex(address+ i*16, 16) << "\t";
		
		for (int j = 0; j < 16; j++){
			std::cout << intToHexWithout0x(memory->readByte(address + i*16 + j), 8) << " ";
		}
		std::cout << "| ";
		for (int j = 0; j < 16; j++){
			BYTE rep = (memory->readByte(address + i*16 + j));
			if (rep < 32){
				std::cout << ".";
			}else{
				std::cout << (BYTE)rep;
			}
			
		}
		std::cout << std::endl;
	}
}

char* Debug::showRegister(BYTE reg)
{
	char *result = (char*)malloc(50*sizeof(char));
	if (reg == 0){
		sprintf(result, "$b: %d (0x%02x)", cpu->getRegisters()->b, cpu->getRegisters()->b);
	}else if(reg == 1){
		sprintf(result, "$c: %d (0x%02x)", cpu->getRegisters()->c, cpu->getRegisters()->c);
	}else if(reg == 2){
		sprintf(result, "$d: %d (0x%02x)", cpu->getRegisters()->d, cpu->getRegisters()->d);
	}else if(reg == 3){
		sprintf(result, "$e: %d (0x%02x)", cpu->getRegisters()->e, cpu->getRegisters()->e);
	}else if(reg == 4){
		sprintf(result, "$h: %d (0x%02x)", cpu->getRegisters()->h, cpu->getRegisters()->h);
	}else if(reg == 5){
		sprintf(result, "$l: %d (0x%02x)", cpu->getRegisters()->l, cpu->getRegisters()->l);
	}else if(reg == 6){
		sprintf(result, "$a: %d (0x%02x)", cpu->getRegisters()->a, cpu->getRegisters()->a);
	}else if(reg == 7){
		BYTE f = cpu->getRegisters()->f;
		BYTE zero = f & 0x80;
		BYTE sub = f & 0x40;
		BYTE hcarry = f & 0x20;
		BYTE carry = f & 0x10;
		sprintf(result, "$f: %d (0x%02x) %s %s %s %s", f, f, zero?"ZERO":"",sub?"SUB":"",hcarry?"HALF_CARRY":"",carry?"CARRY":"");
	}else if(reg == 8){
		sprintf(result, "$sp: %d (0x%02x)", cpu->getRegisters()->sp, cpu->getRegisters()->sp);
	}else if(reg == 9){
		sprintf(result, "$pc: %d (0x%02x)", cpu->getRegisters()->pc, cpu->getRegisters()->pc);
	}else if(reg == 10){
		SHORT tmp = cpu->getRegisters()->a << 8 | cpu->getRegisters()->f;
		sprintf(result, "$af: %d (0x%04x)",tmp, tmp);
	}else if(reg == 11){
		SHORT tmp = cpu->getRegisters()->b << 8 | cpu->getRegisters()->c;
		sprintf(result, "$bc: %d (0x%04x)",tmp, tmp);
	}else if(reg == 12){
		SHORT tmp = cpu->getRegisters()->d << 8 | cpu->getRegisters()->e;
		sprintf(result, "$de: %d (0x%04x)",tmp, tmp);
	}else if(reg == 13){
		SHORT tmp = cpu->getRegisters()->h << 8 | cpu->getRegisters()->l;
		sprintf(result, "$hl: %d (0x%04x)",tmp, tmp);
	}

	return result;
}

void Debug::setRegister(BYTE reg, SHORT value)
{
	if (reg == 0){
		cpu->getRegisters()->b = value & 0xFF;
	}else if(reg == 1){
		cpu->getRegisters()->c = value & 0xFF;
	}else if(reg == 2){
		cpu->getRegisters()->d = value & 0xFF;
	}else if(reg == 3){
		cpu->getRegisters()->e = value & 0xFF;
	}else if(reg == 4){
		cpu->getRegisters()->h = value & 0xFF;
	}else if(reg == 5){
		cpu->getRegisters()->l = value & 0xFF;
	}else if(reg == 6){
		cpu->getRegisters()->a = value & 0xFF;
	}else if(reg == 7){
		cpu->getRegisters()->f = value & 0xFF;
	}else if(reg == 8){
		cpu->getRegisters()->sp = value;
	}else if(reg == 9){
		cpu->getRegisters()->pc = value;
	}else if(reg == 10){
		cpu->getRegisters()->a = value >> 8;
		cpu->getRegisters()->f = value & 0xFF;
	}else if(reg == 11){
		cpu->getRegisters()->b = value >> 8;
		cpu->getRegisters()->c = value & 0xFF;
	}else if(reg == 12){
		cpu->getRegisters()->d = value >> 8;
		cpu->getRegisters()->e = value & 0xFF;
	}else if(reg == 13){
		cpu->getRegisters()->h = value >> 8;
		cpu->getRegisters()->l = value & 0xFF;
	}
}

void Debug::disasm(SHORT address, WORD count)
{
	if (count == 0){
		count = 8;
	}
	if (address == 0){
		//std::cout << "PC es: " << std::to_string(cpu->getRegisters()->pc) << std::endl;
		fakePC = cpu->getRegisters()->pc;
	}else{
		fakePC = address;
	}	
	while (count > 0){
		BYTE instruction = memory->readByte(fakePC);
		fakePC++;
		(this->*bOps[instruction])();
		count--;
	}
}

void Debug::extraOPDecode()
{
	BYTE instruction = memory->readByte(fakePC);
	fakePC++;
	(this->*eOps[instruction])();
}

void Debug::setBreakpoint(SHORT address)
{
	breakpoints.push_back(address);
}

void Debug::removeBreakpoint(SHORT n, bool isAddress)
{
	if (isAddress){
		std::vector<SHORT>::iterator it;
		it = std::find(breakpoints.begin(), breakpoints.end(), n);
		if (it != breakpoints.end())
		{
			std::cout << "Breakpoint en la direccion " << intToHex(*it, 16) << " eliminado." << std::endl;
			breakpoints.erase(it);
		}else{
			std::cout << "No hay ningun breakpoint en la dirección " << intToHex(n, 16) << std::endl;
		}
	}else{
		if (n > breakpoints.size()){
			std::cout << "El breakpoint numero " << std::to_string(n) << " no existe" << std::endl;
		}else{
			breakpoints.erase(breakpoints.begin()+n);
		}
	}
}

char* Debug::showBreakpoints()
{
	int number = 0;
	std::stringstream ss;
	for (std::vector<SHORT>::iterator it = breakpoints.begin(); it != breakpoints.end(); it++)
	{
		if (it == breakpoints.end()-1){
			ss << number << "\tbreakpoint en la direccion " << intToHex(*it, 16) << " " << *it;
		}else{
			ss << number << "\tbreakpoint en la direccion " << intToHex(*it, 16) << " " << *it << std::endl;
		}
		number++;
	}
	if (breakpoints.empty()){
		ss << "No hay ningún breakpoint establecido";
	}
	return (char*)ss.str().c_str();
}

std::string Debug::intToHex(int n, BYTE bits){
	std::stringstream stream;
	if (bits == 16){
  		stream << "0x" 
         << std::setfill ('0') << std::setw(4) 
         << std::hex << n;
    }else if (bits == 8){
    	stream << "0x" 
         << std::setfill ('0') << std::setw(2) 
         << std::hex << n;
    }
  	return stream.str();
}

std::string Debug::intToHexWithout0x(int n, BYTE bits){
	std::stringstream stream;
	if (bits == 16){
  		stream
         << std::setfill ('0') << std::setw(4) 
         << std::hex << n;
    }else if (bits == 8){
    	stream
         << std::setfill ('0') << std::setw(2) 
         << std::hex << n;
    }
  	return stream.str();
}


void Debug::NOP()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "NOP" << std::endl;
}

void Debug::LDbcnn()
{
	SHORT pFakePC = fakePC-1;
	SHORT c = memory->readByte(fakePC+1);
	SHORT b = memory->readByte(fakePC);
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \t(bc), " << intToHex((c << 8 | b), 16) << std::endl;
	fakePC += 2;
}

void Debug::LD_bc_a()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tbc, a" << std::endl;
}

void Debug::INCbc()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "INC \tbc" << std::endl;
}

void Debug::INCb()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "INC \tb" << std::endl;	
}

void Debug::DECb()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "DEC \tb" << std::endl;	
}

void Debug::LDbn()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tb, " << intToHex(memory->readByte(fakePC), 8) << std::endl;
	fakePC++;
}

void Debug::RLCa()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RLC \ta" << std::endl;	
}

void Debug::LD_nn_sp()
{
	SHORT pFakePC = fakePC-1;
	SHORT nn = memory->readShort(fakePC << 8 | (fakePC+1));
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \t(" << intToHex(nn, 16) << ") , sp" << std::endl;
	fakePC += 2;
}

void Debug::ADDhlbc()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADD \thl, bc" << std::endl;	
}

void Debug::LDa_bc_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \ta, (bc)" << std::endl;	
}

void Debug::DECbc()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "DEC \tbc" << std::endl;	
}

void Debug::INCc()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "INC \tc" << std::endl;	
}

void Debug::DECc()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "DEC \tc" << std::endl;	
}

void Debug::LDcn()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tc, " << intToHex(memory->readByte(fakePC), 8) << std::endl;	
	fakePC++;
}

void Debug::RRCa()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RRC \ta" << std::endl;	
}
// 0x1
//TODO: FIX
void Debug::DJNZn()
{
	SHORT pFakePC = fakePC-1;
	WORD e = memory->readByte(fakePC);
	
	if (e > 129){
		e = (~e+5)&0xFF;
	}
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "DJNZ \t" << std::to_string(e) << std::endl;	
	fakePC++;
	
	
}

/////////////////////////////////////////

void Debug::LDdenn()
{
	SHORT pFakePC = fakePC-1;
	SHORT nn = memory->readByte(fakePC) << 8;
	nn  |= memory->readByte(fakePC+1);
	fakePC += 2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tde, " << intToHex(nn, 16) << std::endl;	
	
}

void Debug::LD_de_a()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tde, a" << std::endl;	
}

void Debug::INCde()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "INC \tde" << std::endl;	
}

void Debug::INCd()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "INC \td" << std::endl;
}

void Debug::DECd()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "DEC \td" << std::endl;	
}

void Debug::LDdn()
{
	SHORT pFakePC = fakePC-1;
	BYTE n = memory->readByte(fakePC);
	fakePC++;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \td, " << intToHex(n, 8) << std::endl;
}

void Debug::RLa()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RL \ta" << std::endl;	
}

void Debug::JRn()
{
	SHORT pFakePC = fakePC-1;
	BYTE e = memory->readByte(fakePC);
	fakePC++;
	if (e > 129){
		e = (~e+5)&0xFF;
	}
	fakePC += e;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "JR \t" << std::to_string(e) << std::endl;	
}

void Debug::ADDhlde()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADD \thl, de" << std::endl;	
}

void Debug::LDa_de_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \ta, (de)" << std::endl;	
}

void Debug::DECde()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "DEC \tde" << std::endl;
}

void Debug::INCe()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "INC \te" << std::endl;
}

void Debug::DECe()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "DEC \te" << std::endl;
}

void Debug::LDen()
{
	SHORT pFakePC = fakePC-1;
	BYTE n = memory->readByte(fakePC);
	fakePC++;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \te, " << intToHex(n, 8) << std::endl;
}

void Debug::RRa()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RR \ta" << std::endl;
}

//0x2

void Debug::JRNZn()
{
	SHORT pFakePC = fakePC-1;
	WORD e = memory->readByte(fakePC);
	fakePC++;
	if (e > 129){
		e = (~e+5)&0xFF;
	}
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "JRNZ \t" << std::to_string(e) << std::endl;
}

void Debug::LDhlnn()
{
	SHORT pFakePC = fakePC-1;
	SHORT nn = memory->readByte(fakePC) << 8;
	nn |= memory->readByte(fakePC+1);
	fakePC += 2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \thl, " << intToHex(nn, 16) << std::endl;
}

void Debug::LDI_hl_a()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LDI \t(hl), a" << std::endl;
}

void Debug::INChl()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "INC \thl" << std::endl;
}

void Debug::INCh()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "INC \th" << std::endl;
}

void Debug::DECh()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "DEC \th" << std::endl;
}

void Debug::LDhn()
{
	SHORT pFakePC = fakePC-1;
	BYTE n = memory->readByte(fakePC);
	fakePC++;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \th, " << intToHex(n, 8) << std::endl;
}

void Debug::DAA()
{
	SHORT pFakePC = fakePC-1;
	//Not implemented
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "DAA" << std::endl;
}

void Debug::JRZn()
{
	SHORT pFakePC = fakePC-1;
	WORD e = memory->readByte(fakePC);
	fakePC++;
	if (e > 129){
		e = (~e+5)&0xFF;
	}
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "JRZ \t" << std::to_string(e) << std::endl;
}

void Debug::ADDhlhl()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADD \thl, hl" << std::endl;
}

void Debug::LDIa_hl_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LDI \ta, (hl)" << std::endl;
}

void Debug::DEChl()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "DEC \thl" << std::endl;
}

void Debug::INCl()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "INC \tl" << std::endl;
}

void Debug::DECl()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "DEC \tl" << std::endl;
}

void Debug::LDln()
{
	SHORT pFakePC = fakePC-1;
	BYTE n = memory->readByte(fakePC);
	fakePC++;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tl, " << intToHex(n, 8) << std::endl;
	
}

void Debug::CPL()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "CPL" << std::endl;
}

//0x30

void Debug::JRNCn()
{
	SHORT pFakePC = fakePC-1;
	WORD e = memory->readByte(fakePC);
	if (e > 129){
		e = (~e+5)&0xFF;
	}
	fakePC++;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "JRNC \t" << std::to_string(e) << std::endl;
}

void Debug::LDspnn()
{
	SHORT pFakePC = fakePC-1;
	SHORT nn = memory->readShort(fakePC);
	fakePC += 2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tsp, " << intToHex(nn, 16) << std::endl;	
}

void Debug::LDD_hl_a()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LDD \t(hl), a" << std::endl;
}

void Debug::INCsp()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "INC \tsp" << std::endl;
}

void Debug::INC_hl_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "INC \t(hl)" << std::endl;
}

void Debug::DEC_hl_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "DEC \t(hl)" << std::endl;
}

void Debug::LD_hl_n()
{
	SHORT pFakePC = fakePC-1;
	BYTE n = memory->readByte(fakePC);
	fakePC++;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \t(hl), " << intToHex(n, 8) << std::endl;
}

void Debug::SCF()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SCF" << std::endl;
}

void Debug::JRCn()
{
	SHORT pFakePC = fakePC-1;
	WORD e = memory->readByte(fakePC);
	fakePC++;
	if (e > 129){
		e = (~e+5)&0xFF;
	}
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "JRC \t" << std::to_string(e) << std::endl;
	
}

void Debug::ADDhlsp()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADD \thl, sp" << std::endl;
}

void Debug::LDDa_hl_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LDD \ta, (hl)" << std::endl;
}

void Debug::DECsp()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "DEC \tsp" << std::endl;
}

void Debug::INCa()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "INC \ta" << std::endl;
}

void Debug::DECa()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "DEC \ta" << std::endl;
}

void Debug::LDan()
{
	SHORT pFakePC = fakePC-1;
	BYTE n = memory->readByte(fakePC);
	fakePC++;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \ta, " << intToHex(n, 8) << std::endl;
}

void Debug::CCF()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "CCF" << std::endl;
}

//0x40

void Debug::LDbb()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tb, b" << std::endl;
}

void Debug::LDbc()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tb, c" << std::endl;
}

void Debug::LDbd()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tb, d" << std::endl;
}

void Debug::LDbe()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tb, e" << std::endl;
}

void Debug::LDbh()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tb, h" << std::endl;
}

void Debug::LDbl()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tb, l" << std::endl;
}

void Debug::LDb_hl_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tb, (hl)" << std::endl;
}

void Debug::LDba()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tb, a" << std::endl;
}

void Debug::LDcb()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tc, b" << std::endl;
}

void Debug::LDcc()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tc, c" << std::endl;
}

void Debug::LDcd()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tc, d" << std::endl;
}

void Debug::LDce()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tc, e" << std::endl;
}

void Debug::LDch()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tc, h" << std::endl;
}

void Debug::LDcl()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tc, l" << std::endl;
}

void Debug::LDc_hl_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tc, (hl)" << std::endl;
}

void Debug::LDca()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tc, a" << std::endl;
}

// 0x50

void Debug::LDdb()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \td, b" << std::endl;
}

void Debug::LDdc()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \td, c" << std::endl;
}

void Debug::LDdd()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \td, d" << std::endl;
}

void Debug::LDde()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \td, e" << std::endl;
}

void Debug::LDdh()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \td, h" << std::endl;
}

void Debug::LDdl()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \td, l" << std::endl;
}

void Debug::LDd_hl_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \td, (hl)" << std::endl;
}

void Debug::LDda()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \td, a" << std::endl;
}

void Debug::LDeb()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \te, b" << std::endl;
}

void Debug::LDec()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \te, c" << std::endl;
}

void Debug::LDed()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \te, d" << std::endl;
}

void Debug::LDee()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \te, e" << std::endl;
}

void Debug::LDeh()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \te, h" << std::endl;
}

void Debug::LDel()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \te, l" << std::endl;
}

void Debug::LDe_hl_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \te, (hl)" << std::endl;
}

void Debug::LDea()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \te, a" << std::endl;
}

// 0x60

void Debug::LDhb()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \th, b" << std::endl;
}

void Debug::LDhc()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \th, c" << std::endl;
}

void Debug::LDhd()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \th, d" << std::endl;
}

void Debug::LDhe()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \th, e" << std::endl;
}

void Debug::LDhh()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \th, h" << std::endl;
}

void Debug::LDhl()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \th, l" << std::endl;
}

void Debug::LDh_hl_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \th, (hl)" << std::endl;
}

void Debug::LDha()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \th, a" << std::endl;
}

void Debug::LDlb()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tl, b" << std::endl;
}

void Debug::LDlc()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tl, c" << std::endl;
}

void Debug::LDld()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tl, d" << std::endl;
}

void Debug::LDle()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tl, e" << std::endl;
}

void Debug::LDlh()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tl, h" << std::endl;
}

void Debug::LDll()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tl, l" << std::endl;
}

void Debug::LDl_hl_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tl, (hl)" << std::endl;
}

void Debug::LDla()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tl, a" << std::endl;
}

//0x70

void Debug::LD_hl_b()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \t(hl), b" << std::endl;
}

void Debug::LD_hl_c()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \t(hl), c" << std::endl;
}

void Debug::LD_hl_d()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \t(hl), d" << std::endl;
}

void Debug::LD_hl_e()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \t(hl), e" << std::endl;
}

void Debug::LD_hl_h()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \t(hl), h" << std::endl;
}

void Debug::LD_hl_l()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \t(hl), l" << std::endl;
}

void Debug::HALT()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "HALT" << std::endl;
}

void Debug::LD_hl_a()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \t(hl), a" << std::endl;
}

void Debug::LDab()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \ta, b" << std::endl;
}

void Debug::LDac()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \ta, c" << std::endl;
}

void Debug::LDad()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \ta, d" << std::endl;
}

void Debug::LDae()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \ta, e" << std::endl;
}

void Debug::LDah()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \ta, h" << std::endl;
}

void Debug::LDal()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \ta, l" << std::endl;
}

void Debug::LDa_hl_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \ta, (hl)" << std::endl;
}

void Debug::LDaa()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \ta, a" << std::endl;
}

//0x80

void Debug::ADDab()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADD \ta, b" << std::endl;
}

void Debug::ADDac()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADD \ta, c" << std::endl;
}

void Debug::ADDad()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADD \ta, d" << std::endl;
}

void Debug::ADDae()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADD \ta, e" << std::endl;
}

void Debug::ADDah()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADD \ta, h" << std::endl;
}

void Debug::ADDal()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADD \ta, l" << std::endl;
}

void Debug::ADDa_hl_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADD \ta, (hl)" << std::endl;
}

void Debug::ADDaa()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADD \ta, a" << std::endl;
}

void Debug::ADCab()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADC \ta, b" << std::endl;
}

void Debug::ADCac()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADC \ta, c" << std::endl;
}

void Debug::ADCad()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADC \ta, d" << std::endl;
}

void Debug::ADCae()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADC \ta, e" << std::endl;
}

void Debug::ADCah()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADC \ta, h" << std::endl;
}

void Debug::ADCal()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADC \ta, l" << std::endl;
}

void Debug::ADCa_hl_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADC \ta, (hl)" << std::endl;
}

void Debug::ADCaa()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADC \ta, a" << std::endl;
}

//0x90

void Debug::SUBab()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SUB \ta, b" << std::endl;
}

void Debug::SUBac()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SUB \ta, c" << std::endl;
}

void Debug::SUBad()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SUB \ta, d" << std::endl;
}

void Debug::SUBae()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SUB \ta, e" << std::endl;
}

void Debug::SUBah()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SUB \ta, h" << std::endl;
}

void Debug::SUBal()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SUB \ta, l" << std::endl;
}

void Debug::SUBa_hl_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SUB \ta, (hl)" << std::endl;
}

void Debug::SUBaa()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SUB \ta, a" << std::endl;
}

void Debug::SBCab()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SBC \ta, b" << std::endl;
}

void Debug::SBCac()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SBC \ta, c" << std::endl;
}

void Debug::SBCad()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SBC \ta, d" << std::endl;
}

void Debug::SBCae()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SBC \ta, e" << std::endl;
}

void Debug::SBCah()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SBC \ta, h" << std::endl;
}

void Debug::SBCal()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SBC \ta, l" << std::endl;
}

void Debug::SBCa_hl_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SBC \ta, (hl)" << std::endl;
}

void Debug::SBCaa()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SBC \ta, a" << std::endl;
}

//0xA0
void Debug::ANDb()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "AND \tb" << std::endl;
}

void Debug::ANDc()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "AND \tc" << std::endl;
}

void Debug::ANDd()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "AND \td" << std::endl;
}

void Debug::ANDe()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "AND \te" << std::endl;
}

void Debug::ANDh()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "AND \th" << std::endl;
}

void Debug::ANDl()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "AND \tl" << std::endl;
}

void Debug::AND_hl_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "AND \t(hl)" << std::endl;
}

void Debug::ANDa()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "AND \ta" << std::endl;
}

void Debug::XORb()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "XOR \tb" << std::endl;
}

void Debug::XORc()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "XOR \tc" << std::endl;
}

void Debug::XORd()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "XOR \td" << std::endl;
}

void Debug::XORe()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "XOR \te" << std::endl;
}

void Debug::XORh()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "XOR \th" << std::endl;
}

void Debug::XORl()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "XOR \tl" << std::endl;
}

void Debug::XOR_hl_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "XOR \t(hl)" << std::endl;
}

void Debug::XORa()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "XOR \ta" << std::endl;
}

// 0xB0

void Debug::ORb()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "OR \tb" << std::endl;
}

void Debug::ORc()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "OR \tc" << std::endl;
}

void Debug::ORd()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "OR \td" << std::endl;
}

void Debug::ORe()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "OR \te" << std::endl;
}

void Debug::ORh()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "OR \th" << std::endl;
}

void Debug::ORl()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "OR \tl" << std::endl;
}

void Debug::OR_hl_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "OR \t(hl)" << std::endl;
}

void Debug::ORa()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "OR \ta" << std::endl;
}

void Debug::CPb()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "CP \tb" << std::endl;

}

void Debug::CPc()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "CP \tc" << std::endl;
}

void Debug::CPd()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "CP \td" << std::endl;
}

void Debug::CPe()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "CP \te" << std::endl;
}

void Debug::CPh()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "CP \th" << std::endl;
}

void Debug::CPl()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "CP \tl" << std::endl;
}

void Debug::CP_hl_()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "CP \t(hl)" << std::endl;
}

void Debug::CPa()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "CP \ta" << std::endl;
}

//0xC0

void Debug::RETNZ()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RETNZ" << std::endl;
}

void Debug::POPbc()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "POP \tbc" << std::endl;
}

void Debug::JPNZnn()
{
	SHORT pFakePC = fakePC-1;
	SHORT nn = memory->readShort(fakePC);
	fakePC += 2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "JPNZ \t" << intToHex(nn, 16) << std::endl;
}

void Debug::JPnn()
{
	SHORT pFakePC = fakePC-1;
	SHORT nn = memory->readShort(fakePC);
	fakePC += 2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "JP \t" << intToHex(nn, 16) << std::endl;
}

void Debug::CALLNZnn()
{
	SHORT pFakePC = fakePC-1;
	SHORT nn = memory->readShort(fakePC);
	fakePC += 2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "CALLNZ \t" << intToHex(nn, 16) << std::endl;
}

void Debug::PUSHbc()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "PUSH \tbc" << std::endl;
}

void Debug::ADDan()
{
	SHORT pFakePC = fakePC-1;
	BYTE n = memory->readByte(fakePC);
	fakePC++;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADD \ta, " << intToHex(n, 8) << std::endl;	
}

void Debug::RST0()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RST \t0x00" << std::endl;
}

void Debug::RETZ()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RETZ" << std::endl;
}

void Debug::RET()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RET" << std::endl;
}

void Debug::JPZnn()
{
	SHORT pFakePC = fakePC-1;
	SHORT nn = memory->readShort(fakePC);
	fakePC += 2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "JPZ \t" << intToHex(nn, 16) << std::endl;
}

//EXT OPS

void Debug::CALLZnn()
{
	SHORT pFakePC = fakePC-1;
	SHORT nn = memory->readShort(fakePC);
	fakePC += 2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "CALLZ \t" << intToHex(nn,16) << std::endl;
}

void Debug::CALLnn()
{
	SHORT pFakePC = fakePC-1;
	SHORT nn = memory->readShort(fakePC);
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "CALL \t" << intToHex(nn,16) << std::endl;
}

void Debug::ADCan()
{
	SHORT pFakePC = fakePC-1;
	BYTE n = memory->readByte(fakePC);
	fakePC++;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADC \ta, " << intToHex(n,8) << std::endl;
}

void Debug::RST8()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RST \t0x08" << std::endl;
}

//0xD0

void Debug::RETNC()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RETNC" << std::endl;
}

void Debug::POPde()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "POP \tde" << std::endl;
}

void Debug::JPNCnn()
{
	SHORT pFakePC = fakePC-1;
	SHORT nn = memory->readShort(fakePC);
	fakePC += 2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "JPNC \t" << intToHex(nn, 16) << std::endl;
}

// Not implemented

void Debug::CALLNCnn()
{
	SHORT pFakePC = fakePC-1;
	SHORT nn = memory->readShort(fakePC);
	fakePC += 2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "CALLNC \t" << intToHex(nn, 16) << std::endl;
}

void Debug::PUSHde()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "PUSH \tde" << std::endl;
}

void Debug::SUBan()
{
	SHORT pFakePC = fakePC-1;
	BYTE n = memory->readByte(fakePC);
	fakePC++;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SUB \ta, " << intToHex(n,8) << std::endl;
}

void Debug::RST10()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RST \t0x10" << std::endl;
}

void Debug::RETC()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RETC" << std::endl;
}

void Debug::RETI()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RETI" << std::endl;
}

void Debug::JPCnn()
{
	SHORT pFakePC = fakePC-1;
	SHORT nn = memory->readShort(fakePC);
	fakePC += 2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "JPC \t" << intToHex(nn, 16) << std::endl;
}

//EXT OPS

void Debug::CALLCnn()
{
	SHORT pFakePC = fakePC-1;
	SHORT nn = memory->readShort(fakePC);
	fakePC += 2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "CALLC \t" << intToHex(nn, 16) << std::endl;
}

//Not implemented

void Debug::SBCan()
{
	SHORT pFakePC = fakePC-1;
	BYTE n = memory->readByte(fakePC);
	fakePC++;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SBC \ta, " << intToHex(n, 8) << std::endl;
}

void Debug::RST18()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RST \t0x18" << std::endl;
}

//0xE0

void Debug::LDH_n_a()
{
	SHORT pFakePC = fakePC-1;
	BYTE n = memory->readByte(fakePC);
	fakePC++;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LDH \t(" << intToHex(n, 8) << "), a" << std::endl;
}

void Debug::POPhl()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "POP \thl" << std::endl;
}

void Debug::LDH_c_a()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LDH \t(c), a" << std::endl;
}

// Not implemented

// Not implemented

void Debug::PUSHhl()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "PUSH \thl" << std::endl;
}

void Debug::ANDn()
{
	SHORT pFakePC = fakePC-1;
	BYTE n = memory->readByte(fakePC);
	fakePC++;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "AND \t" << intToHex(n, 8) << std::endl;
}

void Debug::RST20()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RST \t0x20" << std::endl;
}

void Debug::ADDspn()
{
	SHORT pFakePC = fakePC-1;
	BYTE e = memory->readByte(fakePC);
	fakePC++;
	if (e > 129){
		e = (~e+5)&0xFF;
	}
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "ADD \tsp, " << std::to_string(e) << std::endl;
}

void Debug::JPhl()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "JP \thl" << std::endl;
}

void Debug::LD_nn_a()
{
	SHORT pFakePC = fakePC-1;
	SHORT nn = memory->readShort(fakePC);
	fakePC += 2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \t(" << intToHex(nn, 16) << "), a" << std::endl;
	
	
}

// Not Implemented

// Not Implemented

// Not implemented

void Debug::XORn()
{
	SHORT pFakePC = fakePC-1;
	BYTE n = memory->readByte(fakePC);
	fakePC++;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "XOR \t" << intToHex(n, 8) << std::endl;
}

void Debug::RST28()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RST \t0x28" << std::endl;
}

//0xF0

void Debug::LDHa_n_()
{
	SHORT pFakePC = fakePC-1;
	BYTE n = memory->readByte(fakePC);
	fakePC++;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LDH \ta, (" << intToHex(n, 8) << ")" << std::endl;
}

void Debug::POPaf()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "POP \taf" << std::endl;
}

// Not implemented

void Debug::DI()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "DI" << std::endl;
}

// Not implemented

void Debug::PUSHaf()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "PUSH \taf" << std::endl;
}

void Debug::ORn()
{
	SHORT pFakePC = fakePC-1;
	BYTE n = memory->readByte(fakePC);
	fakePC++;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "OR \t(" << intToHex(n,8) << ")" << std::endl;
}

void Debug::RST30()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RST \t0x30" << std::endl;
}

void Debug::LDHLspn()
{
	SHORT pFakePC = fakePC-1;
	BYTE e = memory->readByte(fakePC);
	fakePC++;
	if (e > 129){
		e = (~e+5)&0xFF;
	}
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LDHL \tsp, " << std::to_string(e) << std::endl;
}

void Debug::LDsphl()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \tsp, hl" << std::endl;
}

void Debug::LDa_nn_()
{
	SHORT pFakePC = fakePC-1;
	SHORT nn = memory->readShort(fakePC);
	fakePC += 2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "LD \ta, (" << intToHex(nn, 16) << ")" << std::endl;
}

void Debug::EI()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "EI" << std::endl;
}

// Not Implemented

// Not implemented

void Debug::CPn()
{
	SHORT pFakePC = fakePC-1;
	SHORT n = memory->readByte(fakePC);
	fakePC++;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "CP \t" << intToHex(n, 8) << std::endl;
}

void Debug::RST38()
{
	SHORT pFakePC = fakePC-1;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RST \t0x38" << std::endl;
}

// Extended ISA

//0x00
void Debug::RLCb()
{	
	SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RLC \tb" << std::endl;	
}

void Debug::RLCc()
{	
	SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RLC \tc" << std::endl;
}

void Debug::RLCd()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RLC \td" << std::endl;
	
	
}

void Debug::RLCe()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RLC \te" << std::endl;
	
	
}

void Debug::RLCh()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RLC \th" << std::endl;
	
	
}

void Debug::RLCl()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RLC \tl" << std::endl;
	
	
}

void Debug::RLC_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RLC \t(hl)" << std::endl;
	
	
}

//RLCa ya esta definida en bOps

void Debug::RRCb()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RRC \tb" << std::endl;
	
	
}

void Debug::RRCc()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RRC \tc" << std::endl;
	
	
}

void Debug::RRCd()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RRC \td" << std::endl;
	
	
}

void Debug::RRCe()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RRC \te" << std::endl;
	
	
}

void Debug::RRCh()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RRC \th" << std::endl;
	
	
}

void Debug::RRCl()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RRC \tl" << std::endl;
	
}

void Debug::RRC_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RRC \t(hl)" << std::endl;
}

// RRCa ya esta definido en bops

//0x10

void Debug::RLb()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RL \tb" << std::endl;
}

void Debug::RLc()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RL \tc" << std::endl;
}

void Debug::RLd()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RL \td" << std::endl;
}

void Debug::RLe()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RL \te" << std::endl;
}

void Debug::RLh()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RL \th" << std::endl;
}

void Debug::RLl()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RL \tl" << std::endl;
}

void Debug::RL_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RL \t(hl)" << std::endl;
}

//RLa ya esta definida en bops

void Debug::RRb()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RR \tb" << std::endl;
}

void Debug::RRc()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RR \tc" << std::endl;	
}

void Debug::RRd()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RR \td" << std::endl;
}

void Debug::RRe()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RR \te" << std::endl;
}

void Debug::RRh()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RR \th" << std::endl;
}

void Debug::RRl()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RR \tl" << std::endl;
}

void Debug::RR_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RR \t(hl)" << std::endl;
}

// RRa ya esta definido en bOps

//0x20

void Debug::SLAb()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SLA \tb" << std::endl;
}

void Debug::SLAc()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SLA \tc" << std::endl;
}

void Debug::SLAd()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SLA \td" << std::endl;
}

void Debug::SLAe()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SLA \te" << std::endl;
}

void Debug::SLAh()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SLA \th" << std::endl;
}

void Debug::SLAl()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SLA \tl" << std::endl;
}

void Debug::SLA_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SLA \t(hl)" << std::endl;
}

void Debug::SLAa()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SLA \ta" << std::endl;
}

void Debug::SRAb()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SRA \tb" << std::endl;
	
	
}

void Debug::SRAc()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SRA \tc" << std::endl;
	
	
}

void Debug::SRAd()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SRA \td" << std::endl;	
}

void Debug::SRAe()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SRA \te" << std::endl;	
}

void Debug::SRAh()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SRA \th" << std::endl;
}

void Debug::SRAl()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SRA \tl" << std::endl;
}

void Debug::SRA_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SRA \t(hl)" << std::endl;
}

void Debug::SRAa()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SRA \ta" << std::endl;
}

//0x30

void Debug::SWAPb()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SWAP \tb" << std::endl;
}

void Debug::SWAPc()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SWAP \tc" << std::endl;
}

void Debug::SWAPd()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SWAP \td" << std::endl;
}

void Debug::SWAPe()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SWAP \te" << std::endl;
}

void Debug::SWAPh()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SWAP \th" << std::endl;
}

void Debug::SWAPl()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SWAP \tl" << std::endl;
}

void Debug::SWAP_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SWAP \t(hl)" << std::endl;
}

void Debug::SWAPa()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SWAP \ta" << std::endl;
}

void Debug::SLRb()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SLR \tb" << std::endl;
}

void Debug::SLRc()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SLR \tc" << std::endl;
}

void Debug::SLRd()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SLR \td" << std::endl;
}

void Debug::SLRe()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SLR \te" << std::endl;
}

void Debug::SLRh()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SLR \th" << std::endl;
}

void Debug::SLRl()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SLR \tl" << std::endl;
}

void Debug::SLR_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SLR \t(hl)" << std::endl;
}

void Debug::SLRa()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SLR \ta" << std::endl;
}

//0x40

void Debug::BIT0b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT0 \tb" << std::endl;
	
	
}

void Debug::BIT0c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT0 \tc" << std::endl;
	
	
}

void Debug::BIT0d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT0 \td" << std::endl;
	
	
}

void Debug::BIT0e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT0 \tb" << std::endl;
	
	
}

void Debug::BIT0h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT0 \tb" << std::endl;
	
	
}

void Debug::BIT0l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT0 \tb" << std::endl;
	
	
}

void Debug::BIT0_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT0 \tb" << std::endl;
}

void Debug::BIT0a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT0 \tb" << std::endl;
}

void Debug::BIT1b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT1 \tb" << std::endl;
}

void Debug::BIT1c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT1 \tc" << std::endl;
	
	
}

void Debug::BIT1d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT1 \td" << std::endl;
	
	
}

void Debug::BIT1e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT1 \te" << std::endl;
	
	
}

void Debug::BIT1h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT1 \th" << std::endl;
	
	
}

void Debug::BIT1l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT1 \tl" << std::endl;
	
	
}

void Debug::BIT1_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT1 \t(hl)" << std::endl;
	
	
}

void Debug::BIT1a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT1 \ta" << std::endl;
	
	
}

//0x50

void Debug::BIT2b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT2 \tb" << std::endl;
	
	
}

void Debug::BIT2c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT2 \tc" << std::endl;
	
	
}

void Debug::BIT2d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT2 \td" << std::endl;
	
	
}

void Debug::BIT2e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT2 \te" << std::endl;
	
	
}

void Debug::BIT2h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT2 \th" << std::endl;
	
	
}

void Debug::BIT2l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT2 \tl" << std::endl;
	
	
}

void Debug::BIT2_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT2 \t(hl)" << std::endl;
	
	
}

void Debug::BIT2a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT2 \ta" << std::endl;
	
	
}

void Debug::BIT3b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT3 \tb" << std::endl;
	
	
}

void Debug::BIT3c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT3 \tc" << std::endl;
	
	
}

void Debug::BIT3d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT3 \td" << std::endl;
	
	
}

void Debug::BIT3e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT3 \te" << std::endl;
	
	
}

void Debug::BIT3h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT3 \th" << std::endl;
	
	
}

void Debug::BIT3l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT3 \tl" << std::endl;
	
	
}

void Debug::BIT3_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT3 \t(hl)" << std::endl;
	
	
}

void Debug::BIT3a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT3 \ta" << std::endl;
	
	
}

//0x60

void Debug::BIT4b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT4 \tb" << std::endl;
	
	
}

void Debug::BIT4c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT4 \tc" << std::endl;
	
	
}

void Debug::BIT4d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT4 \td" << std::endl;
	
	
}

void Debug::BIT4e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT4 \te" << std::endl;
	
	
}

void Debug::BIT4h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT4 \th" << std::endl;
	
	
}

void Debug::BIT4l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT4 \tl" << std::endl;
	
	
}

void Debug::BIT4_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT4 \t(hl)" << std::endl;
	
	
}

void Debug::BIT4a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT4 \ta" << std::endl;
	
	
}

void Debug::BIT5b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT5 \tb" << std::endl;
	
	
}

void Debug::BIT5c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT5 \tc" << std::endl;
	
	
}

void Debug::BIT5d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT5 \td" << std::endl;
	
	
}

void Debug::BIT5e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT5 \te" << std::endl;
	
	
}

void Debug::BIT5h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT5 \th" << std::endl;
	
	
}

void Debug::BIT5l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT5 \tl" << std::endl;
	
	
}

void Debug::BIT5_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT5 \t(hl)" << std::endl;
	
	
}

void Debug::BIT5a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT5 \ta" << std::endl;
	
	
}

// 0x70

void Debug::BIT6b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT6 \tb" << std::endl;
	
	
}

void Debug::BIT6c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT6 \tc" << std::endl;
	
	
}

void Debug::BIT6d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT6 \td" << std::endl;
	
	
}

void Debug::BIT6e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT6 \te" << std::endl;
	
	
}

void Debug::BIT6h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT6 \th" << std::endl;
	
	
}

void Debug::BIT6l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT6 \tl" << std::endl;
	
	
}

void Debug::BIT6_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT6 \t(hl)" << std::endl;
	
	
}

void Debug::BIT6a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT6 \ta" << std::endl;
	
	
}

void Debug::BIT7b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT7 \tb" << std::endl;
	
	
}

void Debug::BIT7c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT7 \tc" << std::endl;
	
	
}

void Debug::BIT7d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT7 \td" << std::endl;
	
	
}

void Debug::BIT7e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT7 \te" << std::endl;
	
	
}

void Debug::BIT7h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT7 \th" << std::endl;
	
	
}

void Debug::BIT7l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT7 \tl" << std::endl;
	
	
}

void Debug::BIT7_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT7 \t(hl)" << std::endl;
	
	
}

void Debug::BIT7a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "BIT7 \ta" << std::endl;
	
	
}

// 0x80

void Debug::RES0b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES0 \tb" << std::endl;
	
	
}

void Debug::RES0c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES0 \tc" << std::endl;
	
	
}

void Debug::RES0d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES0 \td" << std::endl;
	
	
}

void Debug::RES0e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES0 \te" << std::endl;
	
	
}

void Debug::RES0h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES0 \th" << std::endl;
	
	
}

void Debug::RES0l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES0 \tl" << std::endl;
	
	
}

void Debug::RES0_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES0 \t(hl)" << std::endl;
	
	
}

void Debug::RES0a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES0 \ta" << std::endl;
	
	
}

void Debug::RES1b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES1 \tb" << std::endl;
	
	
}

void Debug::RES1c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES1 \tc" << std::endl;
	
	
}

void Debug::RES1d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES1 \td" << std::endl;
	
	
}

void Debug::RES1e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES1 \te" << std::endl;
	
	
}

void Debug::RES1h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES1 \th" << std::endl;
	
	
}

void Debug::RES1l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES1 \tl" << std::endl;
	
	
}

void Debug::RES1_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES1 \t(hl)" << std::endl;
	
	
}

void Debug::RES1a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES1 \ta" << std::endl;
	
	
}

// 0x90

void Debug::RES2b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES2 \tb" << std::endl;
	
	
}

void Debug::RES2c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES2 \tc" << std::endl;
	
	
}

void Debug::RES2d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES2 \td" << std::endl;
	
	
}

void Debug::RES2e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES2 \te" << std::endl;
	
	
}

void Debug::RES2h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES2 \th" << std::endl;
	
	
}

void Debug::RES2l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES2 \tl" << std::endl;
	
	
}

void Debug::RES2_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES2 \t(hl)" << std::endl;
	
	
}

void Debug::RES2a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES2 \ta" << std::endl;
	
	
}

void Debug::RES3b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES3 \tb" << std::endl;
	
	
}

void Debug::RES3c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES3 \tc" << std::endl;
	
	
}

void Debug::RES3d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES3 \td" << std::endl;
	
	
}

void Debug::RES3e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES3 \te" << std::endl;
	
	
}

void Debug::RES3h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES3 \th" << std::endl;
	
	
}

void Debug::RES3l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES3 \tl" << std::endl;
	
	
}

void Debug::RES3_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES3 \t(hl)" << std::endl;
	
	
}

void Debug::RES3a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES3 \ta" << std::endl;
	
	
}

// 0xA0

void Debug::RES4b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES4 \tb" << std::endl;
	
	
}

void Debug::RES4c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES4 \tc" << std::endl;
	
	
}

void Debug::RES4d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES4 \td" << std::endl;
	
	
}

void Debug::RES4e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES4 \te" << std::endl;
	
	
}

void Debug::RES4h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES4 \th" << std::endl;
	
	
}

void Debug::RES4l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES4 \tl" << std::endl;
	
	
}

void Debug::RES4_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES4 \t(hl)" << std::endl;
	
	
}

void Debug::RES4a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES4 \ta" << std::endl;
	
	
}

void Debug::RES5b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES5 \tb" << std::endl;
	
	
}

void Debug::RES5c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES5 \tc" << std::endl;
	
	
}

void Debug::RES5d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES5 \td" << std::endl;
	
	
}

void Debug::RES5e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES5 \te" << std::endl;
	
	
}

void Debug::RES5h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES5 \th" << std::endl;
	
	
}

void Debug::RES5l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES5 \tl" << std::endl;
	
	
}

void Debug::RES5_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES5 \t(hl)" << std::endl;
	
	
}

void Debug::RES5a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES5 \ta" << std::endl;
	
	
}

// 0xB0

void Debug::RES6b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES6 \tb" << std::endl;
	
	
}

void Debug::RES6c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES6 \tc" << std::endl;
	
	
}

void Debug::RES6d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES6 \td" << std::endl;
	
	
}

void Debug::RES6e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES6 \te" << std::endl;
	
	
}

void Debug::RES6h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES6 \th" << std::endl;
	
	
}

void Debug::RES6l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES6 \tl" << std::endl;
	
	
}

void Debug::RES6_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES6 \t(hl)" << std::endl;
	
	
}

void Debug::RES6a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES6 \ta" << std::endl;
	
	
}

void Debug::RES7b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES7 \tb" << std::endl;
	
	
}

void Debug::RES7c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES7 \tc" << std::endl;
	
	
}

void Debug::RES7d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES7 \td" << std::endl;
	
	
}

void Debug::RES7e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES7 \te" << std::endl;
	
	
}

void Debug::RES7h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES7 \th" << std::endl;
	
	
}

void Debug::RES7l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES7 \tl" << std::endl;
	
	
}

void Debug::RES7_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES7 \t(hl)" << std::endl;
	
	
}

void Debug::RES7a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "RES7 \ta" << std::endl;
	
	
}

// 0xC0

void Debug::SET0b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET0 \tb" << std::endl;
	
	
}

void Debug::SET0c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET0 \tc" << std::endl;
	
	
}

void Debug::SET0d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET0 \td" << std::endl;
	
	
}

void Debug::SET0e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET0 \te" << std::endl;
	
	
}

void Debug::SET0h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET0 \th" << std::endl;
	
	
}

void Debug::SET0l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET0 \tl" << std::endl;
	
	
}

void Debug::SET0_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET0 \t(hl)" << std::endl;
	
	
}

void Debug::SET0a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET0 \ta" << std::endl;
	
	
}

void Debug::SET1b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET1 \tb" << std::endl;
	
	
}

void Debug::SET1c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET1 \tc" << std::endl;
	
	
}

void Debug::SET1d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET1 \td" << std::endl;
	
	
}

void Debug::SET1e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET1 \te" << std::endl;
	
	
}

void Debug::SET1h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET1 \th" << std::endl;
	
	
}

void Debug::SET1l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET1 \tl" << std::endl;
	
	
}

void Debug::SET1_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET1 \t(hl)" << std::endl;
	
	
}

void Debug::SET1a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET1 \ta" << std::endl;
	
	
}

// 0xD0

void Debug::SET2b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET2 \tb" << std::endl;
	
	
}

void Debug::SET2c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET2 \tc" << std::endl;
	
	
}

void Debug::SET2d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET2 \td" << std::endl;
	
	
}

void Debug::SET2e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET2 \te" << std::endl;
	
	
}

void Debug::SET2h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET2 \th" << std::endl;
	
	
}

void Debug::SET2l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET2 \tl" << std::endl;
	
	
}

void Debug::SET2_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET2 \t(hl)" << std::endl;
	
	
}

void Debug::SET2a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET2 \ta" << std::endl;
	
	
}

void Debug::SET3b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET3 \tb" << std::endl;
	
	
}

void Debug::SET3c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET3 \tc" << std::endl;
	
	
}

void Debug::SET3d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET3 \td" << std::endl;
	
	
}

void Debug::SET3e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET3 \te" << std::endl;
	
	
}

void Debug::SET3h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET3 \th" << std::endl;
	
	
}

void Debug::SET3l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET3 \tl" << std::endl;
	
	
}

void Debug::SET3_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET3 \t(hl)" << std::endl;
	
	
}

void Debug::SET3a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET3 \ta" << std::endl;
	
	
}

// 0xE0

void Debug::SET4b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET4 \tb" << std::endl;
	
	
}

void Debug::SET4c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET4 \tc" << std::endl;
	
	
}

void Debug::SET4d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET4 \td" << std::endl;
	
	
}

void Debug::SET4e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET4 \te" << std::endl;
	
	
}

void Debug::SET4h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET4 \th" << std::endl;
	
	
}

void Debug::SET4l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET4 \tl" << std::endl;
	
	
}

void Debug::SET4_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET4 \t(hl)" << std::endl;
	
	
}

void Debug::SET4a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET4 \ta" << std::endl;
	
	
}

void Debug::SET5b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET5 \tb" << std::endl;
	
	
}

void Debug::SET5c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET5 \tc" << std::endl;
	
	
}

void Debug::SET5d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET5 \td" << std::endl;
	
	
}

void Debug::SET5e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET5 \te" << std::endl;
	
	
}

void Debug::SET5h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET5 \th" << std::endl;
	
	
}

void Debug::SET5l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET5 \tl" << std::endl;
	
	
}

void Debug::SET5_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET5 \t(hl)" << std::endl;
	
	
}

void Debug::SET5a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET5 \ta" << std::endl;
	
	
}

// 0xF0

void Debug::SET6b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET6 \tb" << std::endl;
	
	
}

void Debug::SET6c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET6 \tc" << std::endl;
	
	
}

void Debug::SET6d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET6 \td" << std::endl;
	
	
}

void Debug::SET6e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET6 \te" << std::endl;
	
	
}

void Debug::SET6h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET6 \th" << std::endl;
	
	
}

void Debug::SET6l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET6 \tl" << std::endl;
	
	
}

void Debug::SET6_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET6 \t(hl)" << std::endl;
	
	
}

void Debug::SET6a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET6 \ta" << std::endl;
	
	
}

void Debug::SET7b()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET7 \tb" << std::endl;
	
	
}

void Debug::SET7c()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET7 \tc" << std::endl;
	
	
}

void Debug::SET7d()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET7 \td" << std::endl;
	
	
}

void Debug::SET7e()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET7 \te" << std::endl;
	
	
}

void Debug::SET7h()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET7 \th" << std::endl;
	
	
}

void Debug::SET7l()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET7 \tl" << std::endl;
	
	
}

void Debug::SET7_hl_()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET7 \t(hl)" << std::endl;
	
	
}

void Debug::SET7a()
{	
SHORT pFakePC = fakePC-2;
	std::cout << intToHex(pFakePC, 16) << ":" << "\t\t" << "SET7 \ta" << std::endl;
	
	
}