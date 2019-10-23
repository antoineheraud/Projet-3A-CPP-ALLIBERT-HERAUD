#include "display.hpp"
#include "memory.hpp"
#include "data_value.hpp"
#include "plateform.hpp"
#include "CPU.hpp"
#include "bus.hpp"


int main(){

  Plateform plt1("testdata/platform.txt");
  vector<Component*> tabl = plt1.get_tab();
  int i;

  Memory &Mem1  = (* dynamic_cast <Memory*>  (tabl[0]));
  Memory &Mem2  = (* dynamic_cast <Memory*>  (tabl[1]));
  Bus &Bus1     = (* dynamic_cast <Bus*>     (tabl[2]));
  Bus &Bus2     = (* dynamic_cast <Bus*>     (tabl[3]));
  CPU &CPU1     = (* dynamic_cast <CPU*>     (tabl[5]));
  CPU &CPU2     = (* dynamic_cast <CPU*>     (tabl[6]));
  Display &Disp = (* dynamic_cast <Display*> (tabl[4]));


  
  std::cout << "-------------------" << std::endl;
  std::cout << "  TEST CHARGEMENT  " << std::endl;
  std::cout << "-------------------" << std::endl;
  
  Mem1.info();
  
  std::cout << "-------------------" << std::endl;
  
  Mem2.info();
  
  std::cout << "-------------------" << std::endl;
  
  Bus1.info();
  
  std::cout << "-------------------" << std::endl;

  Bus2.info();
  
  std::cout << "-------------------" << std::endl;
  
  CPU1.info();
  
  std::cout << "-------------------" << std::endl;
  
  CPU2.info();
  
  std::cout << "-------------------" << std::endl;
  
  Disp.info();
  
  std::cout << "-------------------" << std::endl;
  std::cout << "     TEST LINK     " << std::endl;
  std::cout << "-------------------" << std::endl;
  
  dynamic_cast <CPU*>(  Disp.get_ptr()->get_ptr()->get_ptr() )->info();

  std::cout << "-------------------" << std::endl;
  std::cout << "  TEST SIMULATION  " << std::endl;
  std::cout << "-------------------" << std::endl;

  
  for(i=0; i<50; ++i){
    CPU1.simulate();
    CPU2.simulate();
    Bus1.simulate();
    Bus2.simulate();
    Mem1.simulate();
    Mem2.simulate();
    Disp.simulate();
    std::cout << "------------- " << i << std::endl;
  }


  return 1;
  


}
