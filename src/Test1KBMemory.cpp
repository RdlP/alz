#include "Test1KBMemory.hpp"

Test1KBMemory::Test1KBMemory()
{
	// Load BIOS
	memset(&memory, 0, sizeof(memory));
	memory[0] = 0x06;
	memory[1] = 0x00;
	memory[2] = 0x0E;
	memory[3] = 0x00;
	memory[4] = 0x16;
	memory[5] = 0x00;
	memory[6] = 0x1E;
	memory[7] = 0x00;
	memory[8] = 0x26;
	memory[9] = 0x00;
	memory[10] = 0x2E;
	memory[11] = 0x00;
	memory[12] = 0x3E;
	memory[13] = 0x00;
	memory[14] = 0x31;
	memory[15] = 0x00;
	memory[16] = 0x04;
	memory[17] = 0xC3;
	memory[18] = 0x00;
	memory[19] = 0x01;

	memory[20] = 0x41;
	memory[21] = 0x6E;
	memory[22] = 0x67;
	memory[23] = 0x65;
	memory[24] = 0x6C;
	memory[25] = 0x20;
	memory[26] = 0x4C;
	memory[27] = 0x75;
	memory[28] = 0x69;
	memory[29] = 0x73;
}

BYTE Test1KBMemory::readByte(SHORT address)
{
	return memory[address];
}

SHORT Test1KBMemory::readShort(SHORT address)
{
	return memory[address+1] << 8 | memory[address];
}

bool Test1KBMemory::writeByte(SHORT address, BYTE data)
{
	memory[address] = data;
}

bool Test1KBMemory::writeShort(SHORT address, SHORT data)
{
	memory[address+1] = (data >> 8) & 0xFF;
	memory[address] = data & 0xFF;
}
