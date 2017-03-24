#ifndef _TEST_1KB_MEMORY_HEADER
#define _TEST_1KB_MEMORY_HEADER

#include "IMemory.hpp"
#include "types.h"
#include <string.h>

class Test1KBMemory : public IMemory{
	public:
		Test1KBMemory();
		BYTE readByte(SHORT address);
		SHORT readShort(SHORT address);
		bool writeByte(SHORT address, BYTE data);
		bool writeShort(SHORT address, SHORT data);

	private:
		BYTE memory[1024];
};
#endif