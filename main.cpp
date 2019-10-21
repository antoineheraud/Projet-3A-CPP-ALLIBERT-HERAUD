#include "display.hpp"
#include "memory.hpp"
#include "data_value.hpp"
#include "plateform.hpp"

int main(){

  Plateform plt1("testdata/platform.txt");
  Component* tabl = plt1.get_tab();


  tabl[2].load_source(&tabl[0]);

  std::cout << "------------------" << endl;
  
  tabl[2].psource->info();
  
  std::cout << "------------------" << endl;
  
  tabl[1].info();
  
  std::cout << "------------------" << endl;

  tabl[2].info();

  std::cout << "------------------" << endl;

  
  
  return 1;
  


}
