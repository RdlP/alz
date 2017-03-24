#ifndef _ROM_HEADER
#define _ROM_HEADER

#include "IROM.hpp"
#include "types.h"
#include <iostream>
#include <fstream>

class ROM : public IROM{
	public:
		ROM(std::string filename);
		void loadROM();
		BYTE readByte(SHORT address);
		SHORT readShort(SHORT address);
		BYTE *getRom();
	private:
		BYTE rom[0x100];
		std::string filename;
};
#endif