#ifndef PROGRAM
#define PROGRAM
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<list>
#include<vector>
#include<string.h>
using namespace std;

class Instruction{
  private :
    char* op_code;
    int op_A;
    int op_B;


  public :
  Instruction(char* opc, int A, int B){
    op_code = opc;
    op_A = A;
    op_B = B;
  }
  ~Instruction();
  char* getopc(){
    return op_code;
  }
  double getA(){
    return op_A;
  }
  double getB(){
    return op_B;
  }
};

class Program {

  private:
    int inst_pointer;
    vector<Instruction> L_instructions[];
    int L_length;


  public:
    Program(string def){
      inst_pointer = 0;
      int len = 0;
      ifstream Fp;
      string line;
      char* opc;
      double A,B;
      Fp.open(def);
      if (!Fp) {
        cerr << "Unable to Programm file" << endl;
        exit(1);
      }

      while(!Fp.eof()){
        len += 1;
        Fp >> opc >> A >> B;
        Instruction I(opc,A,B);
        L_instructions.push_back(I);
        delete(&I);
      }
      Fp.close();
    }
		~Program();
    Instruction compute(){
      char* inst = L_instructions[inst_pointer];
      if (inst_pointer<L_length) {
        return L_instructions[inst_pointer];
      } else {
        return 0
      }
      if (!strcmp("NOP",inst.getopc())){
        return 0;
      }
      else if(!strcmp("ADD",inst.getopc())){
        return inst.getA() + inst.getB();
      }
      else if(!strcmp("SUB",inst.getopc())){
        return inst.getA() - inst.getB();
      }
      else if(!strcmp("MUL",inst.getopc())){
        return inst.getA() * inst.getB();
      }
      else if(!strcmp("DIV",inst.getopc())){
        return inst.getA() / inst.getB();
      }
      else {
        cerr << "Unvalid instruction" << endl;
        return 0;
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
