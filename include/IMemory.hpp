#ifndef _IMEMORY_HEADER
#define _IMEMORY_HEADER

#include "types.h"


class IMemory{
public:
	virtual BYTE readByte(SHORT address) = 0;
	virtual SHORT readShort(SHORT address) = 0;
	virtual bool writeByte(SHORT address, BYTE data) = 0;
	virtual bool writeShort(SHORT address, SHORT data) = 0;
};

#endif