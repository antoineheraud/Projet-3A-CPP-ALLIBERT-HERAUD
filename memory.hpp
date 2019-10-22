//Memory.hpp

#ifndef MEMORY_
#define MEMORY_

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
  Component* get_ptr();
  void simulate();
  double get_size();
  string get_source();
  string get_label();
  void load_source(Component* ptr);
  Data_value read(double number = 0);
  void info();
  Memory(string def);
  ~Memory();

};


#endif
