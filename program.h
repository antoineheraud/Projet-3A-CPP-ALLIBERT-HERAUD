#include<stdio.h>
#include<iostream>
#include<fstream>
#include<list>
#include<vector>
#include<string.h>
using namespace std;
class Instruction{
  private :
    string op_code;
    double op_A;
    double op_B;


  public :
  Instruction(string opc, double A, double B);
  ~Instruction();
  double getA();
  double getB();
  string getopc();
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
    int is_finished();           //return 1 when finched, 0 if not
    void reset();
};
