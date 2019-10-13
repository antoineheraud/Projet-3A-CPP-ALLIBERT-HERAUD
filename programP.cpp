#ifndef PROGRAM
#define PROGRAM
#include<iostream>
using namespace std;

class Program {

  private:
    int inst_pointer;
    list<Instructions> L_instructions[];
    int L_length;


  public:
    Program(string def){
      
    }
		~Program();
    Instruction compute(){
      if (inst_pointer<L_length) {
        return L_instructions[inst_pointer];
      } else {
        return NOP
      }
    }
};

class Instruction{
  private :
    string op_code;
    int op_A;
    int op_B;


  public :
  Instruction(string opc, int A, int B){
    op_code = opc;
    op_A = A;
    op_B = B;
  }
  ~Instruction();

}
