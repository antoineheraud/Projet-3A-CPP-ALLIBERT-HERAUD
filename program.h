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
    double op_A;
    double op_B;


  public :
  Instruction(char* opc, int A, int B);
  ~Instruction();
  double getA();
  double getB();
};
class Program{
  private:
    int inst_pointer;
    vector<Instruction> L_instructions;
    int L_length;
  public:
    Program(string file);
    ~Program();
    double compute();
    void ask(int F);
};
