#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include"program.hpp"
using namespace std;

Instruction::Instruction(string opc, double A, double B){
  op_code = opc;
  op_A = A;
  op_B = B;
  /*cout << op_code <<endl;
  cout << op_A << endl;
  cout << op_B << endl;*/
}
Instruction::~Instruction(){
}
string Instruction::getopc(){
  return op_code;
}
double Instruction::getA(){
  return op_A;
}
double Instruction::getB(){
  return op_B;
}


Program::Program(string def){
  F_pointer = 0;
  L_length = 0;
  ifstream Fp;
  string sA,sB;
  string temp;
  double A,B;
  Fp.open(def);
  if (!Fp) {
    cerr << "Unable to Programm file" << endl;
    exit(1);
  }
  while(!Fp.eof()){

  //  cout << "L" <<endl;
    L_length += 1;
    Fp >> temp >> sA >> sB;
  //  cout << "stringA" << sA << endl;
  //  cout << "stringB" << sB << endl;
    A = stod(sA);
    B = stod(sB);
//    cout << A << endl;
//    cout << B << endl;
    //char opc1[temp.size()+1];
    //strcpy(opc1, temp.c_str());
    //cout << "char" <<endl;
    Instruction In = Instruction(temp,A,B);
    L_instructions.push_back(In);
    //delete In;
  }
  Fp.close();
  L_instructions.pop_back();
  F_pointer = 0;
}
Program::~Program(){
}

double Program::compute(){
  //cout << "inst_pointer " << F_pointer << endl;
  Instruction inst =   L_instructions[F_pointer];
  F_pointer = F_pointer+1;
  //cout << inst.getopc() << endl;
  //cout << inst.getA() << endl;
  //cout << inst.getB() << endl;
  if (F_pointer>L_length) {
    return 0;
  }
  string temp = inst.getopc();
  char cstr[temp.size()+1];
  strcpy(cstr, temp.c_str());
  if (!strcmp("NOP",cstr)){
    return 0;
  }
  else if(!strcmp("ADD",cstr)){
    return inst.getA() + inst.getB();
  }
  else if(!strcmp("SUB",cstr)){
    return inst.getA() - inst.getB();
  }
  else if(!strcmp("MUL",cstr)){
    return inst.getA() * inst.getB();
  }
  else if(!strcmp("DIV",cstr)){
    return inst.getA() / inst.getB();
  }
  else {
    cerr << "Unvalid instruction" << endl;
    return 0;
  }
}
int Program::is_finished(){
  if (F_pointer < L_length){
    return 0;
  }
  else {
    return 1;
  }
}
void Program::reset(){
  F_pointer = 0;
}
int Program::get_L(){
  return L_length;
}
int Program::get_pointer(){
  return F_pointer;
}
