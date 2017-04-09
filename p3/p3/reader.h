#ifndef READER_H
#define	READER_H
// Author: Sean Davis

#include "instruction.h"
#include "registers.h"
class Reader{
    Instruction lines[1000];
    public :
    void fetch(Instruction *instruction, Registers *registers);
    void read(Registers *registers);
};

//typedef struct
//{
//  Instruction lines[1000];
//} Reader;

//void fetch(Reader *reader, Instruction *instruction, Registers *registers);
//void read(Reader *reader, Registers *registers, const char *filename);
#endif	// READER_H

