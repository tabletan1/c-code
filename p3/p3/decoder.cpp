// Author: Sean Davis
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "decoder.h"
#include "instruction.h"
#include "registers.h"
#include "main.h"

using namespace std;

typedef enum {eax, ebp, esp, eip}RegName;

void Decoder::addl()
{
    *operand2 = *operand1 + *operand2;
}  // addl()

void Decoder::andl()
{
    *operand2 = *operand1 & *operand2;
}  // andl()

void Decoder::execute(Registers *registers, int memory[1001])
{
    cout << "iii" << endl;
    const char *opcodes[] = { "addl", "andl", "leave", "movl", "pushl", "ret",
        "subl"};
    enum OpcodeNum {ADDL, ANDL, LEAVE, MOVL, PUSHL, RET, SUBL};
    int opcodeNum;
    opcodeNum = ADDL;
    cout << opcode << endl;
    // cout << opcodeNum << endl;
    // cout << opcodes[opcodeNum] << endl;
    while(strcmp(opcode, opcodes[opcodeNum]) != 0)
    {
        opcodeNum++;
        if(opcodeNum > 6)
            break;
    }
    cout << opcodeNum << endl;
    switch (opcodeNum)
    {
        case ADDL: addl(); cout << 1 << endl; break;
        case ANDL: andl(); cout << 2 << endl; break;
        case LEAVE: leave(registers, memory); cout << 3 << endl;break;
        case MOVL: movl(); cout << 4 << endl;break;
        case PUSHL: pushl(registers, memory);cout << 5 << endl; break;
        case RET: ret(registers, memory); cout << 6 << endl;break;
        case SUBL: subl(); cout << 7 << endl;break;
        default: cout << "Invalid opcode!" << endl;
    } // switch on oncodeNum
    
}  // execute()

void Decoder::leave(Registers *registers, int memory[1001])
{
    RegName esp1 = esp, ebp1 = ebp;
    registers->set(esp1, registers->get(ebp1));
    registers->set(ebp1, memory[registers->get(esp1)]);
    registers->set(esp1, registers->get(esp1) + 4);
}  // leave()


void Decoder::movl()
{
    *operand2 = *operand1;
}  // movl()


void Decoder::parse(Instruction *instruction, Registers *registers,
                    int memory[1001])
{
    char *ptr, info[1000];
    
    strcpy(info, instruction->getInfo());
    //cout << info << endl;
    
    strcpy(opcode, strtok(info, " "));
    //cout << opcode << endl;
    ptr = strtok(NULL, " ");
    
    if(ptr)
    {
        operand1 = registers->address(ptr, memory);
        //  cout << operand1 << endl;
        ptr = strtok(NULL, " ");
        
        if(ptr)
            operand2 =registers->address(ptr, memory);
        //	cout << operand2 << endl;
    } // if there is at least one operand
}  // parse()





void Decoder::pushl(Registers *registers, int memory[1001])
{
    RegName esp1 = esp;
    registers->set(esp1, registers->get(esp1)-4);
    memory[registers->get(esp1)] = *operand1;
}  // pushl()


void Decoder::ret(Registers *registers, int memory[1001])
{
    RegName eip1 = eip, esp1 = esp;
    registers->set(eip1, memory[registers->get(esp1)]);
    registers->set(esp1, registers->get(esp1) + 4);
}  // ret()


void Decoder::subl()
{
    *operand2 = *operand2 - *operand1;
}  // subl()