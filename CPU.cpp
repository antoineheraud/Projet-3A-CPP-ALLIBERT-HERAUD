#include<iostream>
#include<fstream>
#include "CPU.hpp"

using namespace std;


void CPU::simulate(){
  cout << "Un" << endl;
  double result = 0;
  for (double i = 0; i<freq; ++i){cout << "Loop" << endl;
    if (Prog->is_finished() == 1){cout << "fin" << endl;
      
      if (active<cores){
	active += 1;
	Prog->reset();
	
      }
      break;
    }
    cout << "Deux" << endl;
    result = Prog->compute();
    cout << "Trois" << endl;
    reg->write(result);
  }
}


CPU::CPU(string def) {
  CPU_Register regX = CPU_Register();
  reg = &regX;
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
    freq = stod(parameter);
  }
  else {
    cerr << "Wrong file FREQ" << endl;
  }
  Fp >> word >> parameter;
  if (word.compare("PROGRAM:")==0){
    file = parameter;
  }
  
  Program ProgX(file);
  cout << "Length" << ProgX.get_L() << endl;
  Prog = &ProgX;
  active = 1;
}


CPU::~CPU(){
}


double CPU::get_size(){
  cout << "pas pour CPU" << endl;
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
  cout << "TYPE         : CPU" << endl;
  cout << "LABEL        : " << label << endl;
  cout << "CORES        : " << cores << endl;
  cout << "ACTIVE CORES : " << active << endl;
  cout << "FREQ         : " << freq << endl;
  
}


string CPU::get_source(){
  return "_CPU_";
}


string CPU::get_label(){
  return this->label;
}


void CPU::load_source(Component* ptr){
  cout << "Ne pas utiliser Load_source sur un CPU" << endl;
}


Component* CPU::get_ptr(){
  cout << "Le CPU n'a pas de source. NULL returned" << endl;
  return nullptr;
}
