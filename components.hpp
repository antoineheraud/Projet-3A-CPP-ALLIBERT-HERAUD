#ifndef COMPONENTS
#define COMPONENTS

#include "data_value.hpp"

using namespace std;

class Component {

public:
  virtual double get_size() = 0;
  virtual Data_value get_data(double number) = 0;
  virtual void simulate() = 0;
  virtual void info() = 0;
		
};


#endif
