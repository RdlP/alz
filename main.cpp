#include "CPU.hpp"
#include "Debug.hpp"
#include "IMemory.hpp"
#include "IROM.hpp"
#include "Test1KBMemory.hpp"
#include "ROM.hpp"

using namespace std; 

int main(int argc, char* argv[]) 
{
  if (!strcmp(argv[1], "-debug")){
    std::cout << "Depurador iniciado. Puede empezar la depuración con los siguientes comandos:" << std::endl;
    std::cout << "\t -run (ejecuta el programa hasta que encuentre un breakpoint)" << std::endl;
    std::cout << "\t -s|step (ejecuta una única instruccíon)" << std::endl;
    std::cout << "\t -d|disasm (desensambla el codigo)" << std::endl;
    std::cout << "\t -set register|breakpoint|bp value" << std::endl;
    std::cout << "\t -dump (dump de la memoria)" <<  std::endl;
    std::cout << "\t -print register|breakpoint|bp"<<  std::endl;
    std::cout << "\t -delete value (borrar breakpoint)"<<  std::endl;
    std::cout << "\t -quit|exit" << std::endl;
    IMemory *memory = new Test1KBMemory();
    CPU *cpu = new CPU(memory);
    IROM *rom = new ROM(argv[2]);
    rom->loadROM();
    cpu->setRom(rom);
    Debug *debug = new Debug(cpu);
    debug->runDebug();
  }
  return 0;
}
