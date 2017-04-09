// Author: Sean Davis
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <cstdlib>
#include "main.h"
#include "reader.h"
#include "registers.h"
#include "instruction.h"

typedef enum {eax, ebp, esp, eip}RegName;
using namespace std;

void Reader::fetch(Instruction *instruction, Registers *registers)
{
    RegName eip1 = eip;
    int pos;
    //int temp1 = lines[pos].getAddress();
    // cout << temp1 << endl;
    //int temp2 = registers->get(eip1);
    //	cout << temp2 <<  endl;
    for(pos = 0; lines[pos].getAddress() != registers->get(eip1); pos++);
    // cout << pos << endl;
    //instruction->setInfo(lines[pos].getInfo());
    //instruction->setAddress(lines[pos].getAddress());
    *instruction = lines[pos];
    // cout << instruction->getInfo() << endl;
    registers->set(eip1, registers->get(eip1) + 4);
} // fetch()

void Reader::read(Registers *registers)
{
    char line[256], *ptr;
    int address = 100, instructionCount = 0;
    //  FILE *fp;
    //  fp = fopen(filename, "r");
    ifstream inf("test1.s");
    //inf.open(filename);
    inf.getline(line, 256);
    //cout << line << endl;
    while(! inf.eof())
    {
        //  cout << line << endl;
        for(ptr = strchr(line, '\t'); ptr; ptr = strchr(line, '\t'))
            *ptr = ' ';  // replace all tabs with space characters
        //  cout << line << endl;
        //*strchr(line, '\n') = '\0';  // eliminate \n;
        //cout << line << endl;
        for(ptr = line; *ptr == ' '; ptr++);  // get past leading spaces
        //	  cout << line << endl;
        if(*ptr != '.' && !strstr(line, "main:"))
        {
            lines[instructionCount].setAddress(address);
            address += 4;
            //cout << lines[instructionCount].getAddress()<< endl;
            lines[instructionCount].setInfo(ptr);
          //   cout << lines[instructionCount].getInfo() << endl;
            instructionCount ++; 
        }
        inf.getline(line, 256);
        // if not directive, nor main:
    } // while more in file
}  // read()