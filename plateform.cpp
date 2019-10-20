#include "component.hpp"
#include "display.hpp"

Plateform::Plateform(string def){
  string line;

  ifstream myfile(def);
  if (!myfile.is_open()){
    std::cout << "Error while trying to open the file : "<< def << std::endl;
  }
  else {
    while ( getline (myfile, line)){
      
    }
  }
}
