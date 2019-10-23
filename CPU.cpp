#include<iostream>
#include<fstream>
#include "CPU.hpp"

using namespace std;


void CPU::simulate(){
  double result = 0;
  for (int i = 0; i<freq; ++i){
    if (Prog->is_finished() == 1){
      
      if (active<cores){
	active += 1;
	Prog->reset();
      }
      break;
    }
    result = Prog->compute();
    reg->write(result);
  }
}


CPU::CPU(string def) {
  CPU_Register* regx = new CPU_Register();
  this->reg = regx;
  string line;
  string word;
  string parameter;
  string file;
  ifstream Fp;
  Fp.open(def);
  if (!Fp) {
    cerr << "Unable to Program file" << endl;
    exit(1);
  }
  Fp >> word >> parameter;
  if (word.compare("TYPE:")!= 0){
    cerr << "Wrong file TYPE" << endl;
  }
  if (parameter.compare("CPU") != 0 ){
    cerr << "Wrong file CPU" << endl;
  }
  Fp >> word;
  getline(Fp, parameter);
  if (word.compare("LABEL:") == 0){
    parameter.erase(parameter.begin());
    label = parameter;
  }
  else {
    cerr << "Wrong file LABEL" << endl;
  }
  Fp >> word >> parameter;
  if (word.compare("CORES:")==0){
    cores = stoi(parameter);
  }
  else {
    cerr << "Wrong file CORES" << endl;
  }
  Fp >> word >> parameter;
  if (word.compare("FREQUENCY:")==0){
    freq = stoi(parameter);
  }
  else {
    cerr << "Wrong file FREQ" << endl;
  }
  Fp >> word >> parameter;
  if (word.compare("PROGRAM:")==0){
    file = parameter;
  }
  
  Program* Progx = new Program(file);
  this->Prog = Progx;
  active = 1;
  cout << "\e[1mCPU\e[0m succesfully loaded" << endl;
}


CPU::~CPU(){
  delete this->reg;
  delete this->Prog;
}


double CPU::get_size(){
  printf("pas pour CPU\n");
  return 0;
}


Data_value CPU::read(double number){
  if (reg->isempty()){
    Data_value Wvalue(0,false);
    return Wvalue;
  }
  else {
    return reg->read();
  }
}

void CPU::info(){
  printf("TYPE         : CPU\n");
  char cstr[label.size()+1];
  strcpy(cstr, label.c_str());
  printf("LABEL        : %s\n", cstr);
  printf("CORES        : %d\n", cores);
  printf("ACTIVE CORES : %d\n", active);
  printf("FREQ         : %d\n", freq);
  
}


string CPU::get_source(){
  return "_CPU_";
}


string CPU::get_label(){
  return this->label;
}


void CPU::load_source(Component* ptr){
  printf("Ne pas utiliser Load_source sur un CPU");
}


Component* CPU::get_ptr(){
  printf("Le CPU n'a pas de source. NULL returned");
  return nullptr;
}
