#ifndef _IROM_HEADER
#define _IROM_HEADER

#include "types.h"
#include <string>

class IROM{
public:
	virtual BYTE readByte(SHORT address) = 0;
	virtual SHORT readShort(SHORT address) = 0;
	virtual void loadROM() = 0;
	virtual BYTE *getRom() = 0;
};
#endif