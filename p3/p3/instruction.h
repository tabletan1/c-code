#ifndef INSTRUCTION_H
#define	INSTRUCTION_H
// Author: Sean Davis
#include <iostream>

class Instruction
{
    int address;
    char *info;
public:
    void setAddress(int straddr);
    void setInfo(const char* strinfo);
    const char* getInfo();
    int getAddress();
    Instruction();//constructor
    ~Instruction();//destructor
    Instruction& operator = (const Instruction& rhs);
    void setNull();
};

//typedef struct
//{
//  int address;
//  char * info;
//} Instruction;

#endif	// INSTRUCTION_H

