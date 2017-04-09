// Author: Sean Davis
#include "instruction.h"
#include <string.h>
using namespace std;

Instruction :: Instruction()
{
    info = NULL;
}
Instruction :: ~Instruction()
{
    if(info)
        delete [] info;
}

const char* Instruction::getInfo()
{
    return this->info;
}

int Instruction::getAddress()
{
    return this->address;
}

void Instruction::setInfo(const char* strinfo)
{
    if(strinfo)
    {
        info = new char[strlen(strinfo) + 1];
        strcpy(info, strinfo);
    }
}

void Instruction::setAddress(int straddr)
{
    this->address = straddr;
}
Instruction& Instruction :: operator = (const Instruction& rhs)
{
    this->address = rhs.address;
    if(rhs.info)
    {
        this->info = new char(strlen(rhs.info)+1);
        strcpy(this->info, rhs.info);
    }
    return *this;
}

void Instruction::setNull()
{
    this->info = NULL;
}