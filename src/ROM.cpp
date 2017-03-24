#include "ROM.hpp"

ROM::ROM(std::string filename): filename(filename)
{

}

void ROM::loadROM()
{
	std::ifstream file (filename, std::ios::in | std::ios::binary | std::ios::ate);
	std::ifstream::pos_type fileSize;
	//char* fileContents;
	if(file.is_open())
	{
	    fileSize = file.tellg();
	    //fileContents = new char[fileSize];
	    file.seekg(0, std::ios::beg);
	    if(!file.read(reinterpret_cast<char*>(&rom), fileSize))
	    {
	        std::cout << "fail to read" << std::endl;
	    }
	    file.close();

	    /*cout << "size: " << fileSize << endl;
	    cout << "sizeof: " << sizeof(fileContents) << endl;
	    cout << "length: " << strlen(fileContents) << endl;
	    cout << "random: " << fileContents[55] << endl;
	    cout << fileContents << endl;*/
	}
}

BYTE ROM::readByte(SHORT address)
{
	return rom[address];
}

SHORT ROM::readShort(SHORT address)
{
	return rom[address] << 8 | rom[address + 1];
}

BYTE* ROM::getRom()
{
	return rom;
}