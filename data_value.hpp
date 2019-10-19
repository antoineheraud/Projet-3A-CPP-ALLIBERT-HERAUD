#ifndef DATA_VALUE
#define DATA_VALUE

#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>


class Data_value {

private:
  double value;
  bool valid;
	
public:
  bool isvalid();
  double get_value();
  void update(double val, bool validity);
  Data_value();
  Data_value(double val, bool validity);
  ~Data_value();
	
};

#endif
