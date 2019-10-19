#include "memory.hpp"
//Meomry.cpp

Memory::Memory(string def) {
  string line;
  string word;
  string parameter;
  
  ifstream myfile (def);
  if (!myfile.is_open()){
    cout << "Error while trying to open the file : "<< def << endl;
  }
  else {
    while ( getline (myfile, line)){
      stringstream s(line);
      s >> word;
      if(word.compare("TYPE:") == 0){
	s >> parameter;
	if(parameter.compare("MEMORY") != 0) {
	  cout << "The type of the loaded file is not accurate for a MEMORYY" << endl;
	  exit(1);
	}
      }
      else if(word.compare("LABEL:") == 0){
	this->label = line;
      }
      else if(word.compare("SIZE:") == 0){
        s >> parameter;
	this->size = stoi(parameter, nullptr, 10);
      }
      else if(word.compare("ACCESS:") == 0){
        s >> parameter;
	this->access_time = stoi(parameter, nullptr, 10);
      }
      else if(word.compare("SOURCE:") == 0){
	this->source = line;
      }
      else {
	cout << "Error : wrong file" << endl;
      }
    }
  }
  this->storage = new Data_value[(int) this->size];
  cout << "Memory succesfully loaded" << endl;
}

void Memory::load_source(){

}

double Memory::get_size(){
  return this->size;
}

void Memory::erase(){
  int i;
  for(i=0; i<this->size; ++i){
    this->storage[i].value = 0;
    this->storage[i].valid = false;
  }
}

Data_value Memory::get_data(double number){
  return this->storage[(int) number% (int) this->size];
}

void Memory::simulate(){
  Data_value donnee;
  int i;
  if(this->counter % access_time == 0){
    this->counter = 0;
    for(i = 0; i<psource->get_width(); ++i){
      donnee = psource->get_data(i);
      if(donnee.isvalid()){
	this->storage[current_address].value = donnee.get_value();
	this->storage[current_address].valid = donnee.isvalid();
      }
      else{
	break;
      }
    }
  } 
  this->counter +=1;
}
