#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include"program.hpp"
using namespace std;

Instruction::Instruction(string opc, double A, double B){
  this->op_code = opc;
  this->op_A = A;
  this->op_B = B;

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

    this->L_length += 1;
    Fp >> temp >> sA >> sB;
    A = stod(sA);
    B = stod(sB);
    Instruction* In = new Instruction(temp,A,B);
    L_instructions.push_back(In);
  }
  Fp.close();
  L_instructions.pop_back();
  this->F_pointer = 0;
}


Program::~Program(){
}


double Program::compute(){
  Instruction* inst =   L_instructions[F_pointer];
  F_pointer = F_pointer+1;
  if (F_pointer > L_length) {
    return 0;
  }
  string temp = inst->getopc();
  char cstr[temp.size()+1];
  strcpy(cstr, temp.c_str());
  if (!strcmp("NOP",cstr)){
    return 0;
  }
  else if(!strcmp("ADD",cstr)){
    return inst->getA() + inst->getB();
  }
  else if(!strcmp("SUB",cstr)){
    return inst->getA() - inst->getB();
  }
  else if(!strcmp("MUL",cstr)){
    return inst->getA() * inst->getB();
  }
  else if(!strcmp("DIV",cstr)){
    return inst->getA() / inst->getB();
  }
  else {
    cerr << "Unvalid instruction" << endl;
    return 0;
  }
}


int Program::is_finished(){
  if (this->F_pointer < this->L_length){
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
