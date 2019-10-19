#include "display.hpp"
//Display.cpp


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
      s >> word;;
      if (word.compare("TYPE:") == 0){
        s >> parameter;
	if(parameter.compare("DISPLAY") != 0) {
	  cout << "The type of the loaded file is not accurate for a DISPLAY" << endl;
	  exit(1);
	}
      }
      else if(word.compare("REFRESH:") == 0){
        s >> parameter;
	this->refresh = stoi(parameter, nullptr, 10);
      }
      else if(word.compare("SOURCE:") == 0){
	this->source = line;
      }
      else {
	std::cout << "Error : wrong file" << std::endl;
      }
    }
  }
  std::cout << "Display succesfully loaded" <<std:: endl;
}


void Display::load_source(){
  

}


void Display::simulate(){
  double i;
  Data_value donnee;
  
  if(this->counter % this->refresh == 0){
    this->counter = 0;
    for(i=0; i<psource->get_size(); ++i){
      donnee = psource->get_data(i);
      if(donnee.isvalid()){
	std::cout << donnee.get_value() << std::endl;
      }
      else {
	break;
      }
    }
  }
  this->counter += 1;
  std::cout << "-------------" << std::endl;
}

