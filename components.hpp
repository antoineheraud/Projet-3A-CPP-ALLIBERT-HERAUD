#ifndef COMPONENTS_
#define COMPONENTS_

#include "data_value.hpp"

using namespace std;

class Component {

public:

  virtual double get_size() = 0;
  virtual Data_value read(double number = 0) = 0;
  virtual void simulate() = 0;
  virtual string get_source() = 0;
  virtual string get_label() = 0;
  virtual void load_source(Component* ptr) = 0;
  virtual Component* get_ptr() = 0;

		
};


#endif
