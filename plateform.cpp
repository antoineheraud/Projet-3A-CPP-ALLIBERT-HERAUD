#include "components.hpp"
#include "plateform.hpp"
#include "memory.hpp"
#include "display.hpp"
#include "bus.hpp"
#include "CPU.hpp"


Component& Plateform::create(string def){
  string line;
  string word;
  string parameter;
  ifstream myfile(def);
  if (!myfile.is_open()){
    std::cout << "Error while trying to open the file : "<< def << std::endl;
  }
  else {
    getline (myfile, line);
    stringstream s(line);
    s >> word;
    if(word.compare("TYPE:") != 0){
      std::cout << "Error wrong file !" << std::endl;
    }
    else {
      s >> parameter;
      if(parameter.compare("MEMORY") == 0){
	Memory mem1(def);
	return mem1;
      }
      else if(parameter.compare("DISPLAY") == 0){
      	Display disp1(def);
	return disp1;
      }
      else if(parameter.compare("CPU") == 0){
	Display cpu1(def);
	return cpu1;
      }
      else if(parameter.compare("BUS") == 0){
	Display bus1(def);
	return bus1;
      }
      else{
	std::cout << "Error wrong file !" << std::endl;	
      }
    }
  }
  exit(1);
}



Plateform::Plateform(string def){
  string line;
  string source;
  int i = 0;
  int j = 0;
  int size = 0;
  Component* tabl = new Component[10];
  ifstream myfile(def);
  if (!myfile.is_open()){
    std::cout << "Error while trying to open the file : "<< def << std::endl;
  }
  else {
    while ( getline (myfile, line)){
      tabl[size] = create(line);
      ++size;
    }
    for(i=0; i<size; ++i){
      source = tabl[i].get_source();
      for(j=0; j<size; ++j){
	
      }
      tabl[i].load_source();
    }
  }
  this->tableau = tabl;
  this->nb_obj = size;
}


Component* Plateform::get_tab(){
  return this->tableau;
}


int Plateform::get_nb_obj(){
  return this->nb_obj;
}
