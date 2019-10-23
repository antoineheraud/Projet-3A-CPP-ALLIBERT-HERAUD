#include "display.hpp"
//Display.cpp



double Display::get_size(){
  std::cout << "This function cannot be used in Display" << std::endl;
  return 0;
}


Data_value Display::read(double number){
  std::cout << "This function cannot be used in Display" << std::endl;
  Data_value donnee(number, false);
  return donnee;
}


void Display::load_source(Component* ptr){
  this->psource = ptr;
}

Component* Display::get_ptr(){
  return this->psource;
}

void Display::simulate(){
  double i;
  Data_value donnee;
  
   if(this->counter % this->refresh == 0){
    this->counter = 0;
    for(i=0; i<this->psource->get_size(); ++i){
      donnee = this->psource->read(i);
      if(donnee.isvalid()){
	std::cout << i << " : " << donnee.get_value() << std::endl;
      }
      else {
	break;
      }
    }
  }
  this->counter += 1;
}


void Display::info(){
  std::cout << "TYPE         : DISPLAY" << std::endl;
  std::cout << "REFRESH      : " << this->refresh << std::endl;
  std::cout << "COUNTER      : " << this->counter << std::endl;
  std::cout << "SOURCE       : " << this->source << std::endl;
}


string Display::get_source(){
  return this->source;
}


string Display::get_label(){
  return this->label;
}



Display::Display(string def){
  string line;
  string word;
  string parameter;
  
  ifstream myfile (def);
  if (!myfile.is_open()){
    std::cout << "Error while trying to open the file : "<< def << std::endl;
  }
  else {
    while ( getline (myfile, line)){
      stringstream s(line);
      s >> word;
      if (word.compare("TYPE:") == 0){
        s >> parameter;
	if(parameter.compare("DISPLAY") != 0) {
	  std::cout << "The type of the loaded file is not accurate for a DISPLAY" << std::endl;
	  exit(1);
	}
      }
      else if(word.compare("REFRESH:") == 0){
        s >> parameter;
	this->refresh = stoi(parameter, nullptr, 10);
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
	std::cout << "Error : wrong file" << std::endl;
      }
      this->counter = 0;
      this->psource = 0;
      this->label = "_Display_";
    }
  }
  std::cout << "\e[1mDisplay\e[0m succesfully loaded" << std::endl;
}


Display::~Display(){}



