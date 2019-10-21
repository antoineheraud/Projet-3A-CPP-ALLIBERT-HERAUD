#include "display.hpp"
#include "memory.hpp"
#include "data_value.hpp"

int main(){


  Memory mem1("testdata/mem1.txt");
  Display disp1("testdata/display.txt");

  disp1.load_source(&mem1);

  std::cout << "------------------" << endl;
  
  disp1.info();
  
  std::cout << "------------------" << endl;

  disp1.psource->info();

  std::cout << "------------------" << endl;

  
  
  return 1;
  


}
