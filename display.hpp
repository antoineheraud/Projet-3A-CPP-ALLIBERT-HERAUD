//Display.hpp

#ifndef DISPLAY
#define DISPLAY

#include "components.hpp"

using namespace std;

class Display {

private:
  int refresh;
  int counter;
  string source;
  
	
public:
Component* psource;
  double get_size();
  Data_value get_data(double number);
  void simulate();
  void load_source(Component* ptr);
  void info();
  Display(string def);
		 
};

#endif
