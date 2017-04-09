#ifndef REGISTERS_H
#define	REGISTERS_H
// Author: Sean Davis

class Registers{
    
    int regs[4];
    
    typedef enum {eax, ebp, esp, eip}RegName;
    //enum {eax, ebp, esp, eip};
    
public:
    
    void initialize(int memory[1001]);
    void print(const char *instruction);
    int* address(char *ptr, int memory[]);
    int get(int regs_name);
    void set(int regs_name, int regs_name2);
};
//typedef struct
//{
//  int regs[4];
//} Registers;

//void initialize(Registers *registers, int memory[1001]);
//void print(Registers *registers, const char *instruction);


#endif	// REGISTERS_H 

