#include<iostream>
#include<fstream>
#include<cstring>
#include"bus.hpp"

using namespace std;


void Bus::simulate(){
  double number = 0;
  printf("SIM\n" );
  while(!pending_data.isempty()){
    printf("READY\n" );
    ready_data.enqueue(pending_data.dequeue());
  }
  for (int k =0;k<width;++k){
    printf("READ\n" );
    Data_value DV = psource->read(number);
    printf("Yes\n" );
    if(DV.isvalid() ){
      pending_data.enqueue(DV);
    }
  }
}


void Bus::bind(Component* ptr){
  this->psource = ptr;
}


Data_value Bus::read(double number){
  counter += 1;
  if(!ready_data.isempty()){
    return ready_data.dequeue();
  }
  else{
    Data_value DV(0,false);
    return DV;
  }
}


int Bus::getCounter(){
  return counter;
}


Bus::Bus(string def){
  counter = 0;
  psource = NULL;
  FIFO<Data_value> pending_data = FIFO<Data_value>();
  FIFO<Data_value> ready_data = FIFO<Data_value>();
  string word;
  string parameter;
  ifstream Fp;
  Fp.open(def);
  if (!Fp) {
    cerr << "Unable to Program file" << endl;
    exit(1);
  }
  Fp >> word >> parameter;
  if (word.compare("TYPE:")!= 0){
    cerr << "BUS, Wrong file TYPE" << endl;
  }
  if (parameter.compare("BUS") != 0 ){
    cerr << "BUS, Wrong file CPU" << endl;
  }
  Fp >> word;
  getline(Fp, parameter);
  if (word.compare("LABEL:") == 0){
    parameter.erase(parameter.begin());
    label = parameter;
  }
  else {
    cerr << "BUS, Wrong file LABEL" << endl;
  }
  Fp >> word >> parameter;
  if (word.compare("WIDTH:")==0){
    width = stoi(parameter);
  }
  else {
    cerr << "BUS, Wrong file WIDTH" << endl;
  }
  Fp >> word;
  getline(Fp, parameter);
  if (word.compare("SOURCE:") == 0){
    parameter.erase(parameter.begin());
    source = parameter;
  }
  else {
    cerr << "BUS, Wrong file SOURCE" << endl;
  }
  //a finir
  
  
}
Bus::~Bus(){
  
}
double Bus::get_size(){
  return width;
}
void Bus::info(){
  printf("TYPE         : BUS\n");
  char cstr[label.size()+1];
  strcpy(cstr, label.c_str());
  printf("LABEL        : %s\n",cstr);
  char cstr1[source.size()+1];
  strcpy(cstr1, source.c_str());
  printf("WIDTH        : %d\n",width);
  printf("SOURCE       : %s\n",cstr1);
  printf("COUNTER      : %d\n",counter);
}


string Bus::get_source(){
  return this->source;
}


string Bus::get_label(){
  return this->label;
}


void Bus::load_source(Component* ptr){
  this->psource = ptr;
}


Component* Bus::get_ptr(){
  return this->psource;
}
