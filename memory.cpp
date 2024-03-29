#include "memory.hpp"
//Meomry.cpp

Memory::Memory(string def) {
  string line;
  string word;
  string parameter;
  int i;
  
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
	  std::cout << "The type of the loaded file is not accurate for a MEMORYY" << std::endl;
	  exit(1);
	}
      }
      else if(word.compare("LABEL:") == 0){
	this->label = "";
	while(!s.eof()){
	  s >> parameter;
	  this->label.append(parameter);
	  this->label.append(" ");
	}
	this->label.erase(this->label.size()-1, 1);
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
	this->source = "";
	while(!s.eof()){
	  s >> parameter;
	  this->source.append(parameter);
	  this->source.append(" ");
	}
	this->source.erase(this->source.size()-1, 1);
      }
      else {
	cout << "Error : wrong file" << endl;
      }
    }
  }
  this->storage = new Data_value[(int) this->size];
  Data_value init;
  for(i=0; i<this->size; ++i){
    this->storage[i] = init;
  }
  this->current_address = 0;
  this->counter = 0;
  this->psource = 0;
  cout << "\e[1mMemory\e[0m succesfully loaded" << endl;
}

Memory::~Memory(){
  delete [] this->storage;
}

void Memory::info(){
  std::cout << "TYPE         : MEMORY" << std::endl;
  std::cout << "LABEL        : " << this->label << std::endl;
  std::cout << "SIZE         : " << this->size << std::endl;
  std::cout << "COUNTER      : " << this->counter << std::endl;
  std::cout << "SOURCE       : " << this->source << std::endl;
  std::cout << "ACCESS_TIME  : " << this->access_time << std::endl;
}


void Memory::load_source(Component* ptr){
  this->psource = ptr;
}

Component* Memory::get_ptr(){
  return this->psource;
}


string Memory::get_source(){
  return this->source;
}

string Memory::get_label(){
  return this->label;
}


double Memory::get_size(){
  return this->size;
} 

void Memory::erase(){
  int i;
  for(i=0; i<this->size; ++i){
    this->storage[i].update(0, false);
  }
}

Data_value Memory::read(double number){
  return this->storage[(int) number% (int) this->size];
}

void Memory::simulate(){
  Data_value donnee;
  int i;
  if(this->counter % access_time == 0){
    this->counter = 0;
    for(i = 0; i<(int)psource->get_size(); ++i){
      donnee = this->psource->read(i);
      if(donnee.isvalid()){
	this->storage[this->current_address].update(donnee.get_value(), donnee.isvalid());
	this->current_address = (this->current_address+1)%(int)this->size;
      }
      else{
	break;
      }
    }
  } 
  this->counter +=1;
}
