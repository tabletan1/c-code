// Author: Sean Davis

#include "registers.h"
#include "decoder.h"
#include "reader.h"
#include "instruction.h"
#include <cstdlib>
#include <cstring>
using namespace std;

typedef enum {eax, ebp, esp, eip}RegName;
int main(int argc, char* argv[])
{
    Reader reader;
    Decoder decoder;
    Registers registers;
    Instruction instruction;
    int memory [1001];
    registers.initialize(memory);
    reader.read(&registers);
    RegName eip1= eip;
    
    while(registers.get(eip1) != 0)
    {
        reader.fetch(&instruction, &registers);
        decoder.parse(&instruction, &registers, memory);
        decoder.execute(&registers, memory);
        registers.print( instruction.getInfo());
        
    } // while eip not zero
    instruction.setNull();
    
    return 0;
}  // main()

