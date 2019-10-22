#ifndef PROGRAM_H
#define PROGRAM_H
#include<iostream>
#include<fstream>
#include<list>
#include<vector>
#include<string>
using namespace std;

class Instruction{
  private :
    string op_code;
    double op_A;
    double op_B;
  public :
  Instruction(string opc, double A, double B);
  ~Instruction();
  string getopc();
  double getA();
  double getB();
};

class Program{
  private:
    int F_pointer;
    vector<Instruction> L_instructions;
    int L_length;
  public:
    Program(string file);
    ~Program();
    double compute();
    int is_finished();           //return true when finched, false if not
    void reset();
    int get_L();
    int get_pointer();
};

#endif
