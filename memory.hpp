//Memory.hpp

#ifndef MEMORY
#define MEMORY

#include "components.hpp"

using namespace std;

class Memory : public Component {

private:
  string label;
  string source;
  Component* psource;
  int counter;
  double size;
  int access_time;
  Data_value* storage;
  int current_address;
		
  void erase();
       
public:
  void simulate();
  double get_size();
  void load_source(Component* ptr);
  Data_value get_data(double number);
  void info();
  Memory(string def);
  ~Memory();

};


#endif
