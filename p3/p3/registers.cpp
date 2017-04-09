//
//  registers.cpp
//  p3
//
//  Created by Rencheng Tan on 2/3/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

// Author: Sean Davis
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include "registers.h"
#include "main.h"
using namespace std;

void Registers::set(int regs_name, int value )
{
    switch(regs_name)
    {
        case eax: regs[0] = value; break;
        case ebp: regs[1] = value; break;
        case esp: regs[2] = value; break;
        case eip: regs[3] = value; break;
        default: break;
    }
}
int Registers::get(int regs_name)
{
    switch(regs_name)
    {
        case eax: return regs[0]; break;
        case ebp: return regs[1]; break;
        case esp: return regs[2]; break;
        case eip: return regs[3]; break;
        default: return 0;
    }
}
int* Registers::address(char *operand, int memory[])
{
    static int value;
    char regNames[4][7] = {"eax", "ebp", "esp", "eip"};
    char *ptr;
    int regNum, index;
    
    if(operand == NULL)
        return NULL;
    
    if(operand[0] == '$') // immediate mode
    {
        value = atoi(&operand[1]);
        return &value;
    } // if immediate mode
    
    for(regNum = eax; regNum <= eip; regNum++)
        if(strstr(operand, regNames[regNum]))
            break;
    
    ptr = strchr(operand, '(');
    
    if(ptr) // some form of indirect addressing
    {
        *ptr = '\0';  // terminate operand string at first '('
        index = atoi(operand);  // will return 0 if no number there!
        return  &memory[regs[regNum] + index];
    } // if ptr
    else  // direct addressing
        return &(regs[regNum]);
}

void Registers::initialize(int memory[1001])
{
    regs[esp] = 1000;
    regs[ebp] = 996;
    regs[eip] = 100;
    regs[eax] = 0;
    memory[1000] = 0;
}  // initialize()

void Registers::print(const char *instruction)
{
    cout << setw(20) << instruction << "eip:" << setw(3) << eip << "eax" << setw(3) << eax << "ebp:" << setw(3) << ebp << "esp:" << setw(3) << esp << left << endl;
    //  printf("%-20s eip: %3d eax: %3d ebp: %3d esp: %3d\n", instruction,
    //    registers->regs[eip], registers->regs[eax], registers->regs[ebp],
    //    registers->regs[esp]);
}  // print()