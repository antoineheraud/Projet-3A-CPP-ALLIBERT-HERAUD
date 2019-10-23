//Display.hpp

#ifndef DISPLAY_
#define DISPLAY_

#include "components.hpp"

using namespace std;

class Display : public Component {
  
private:
  string label;
  int refresh;
  int counter;
  string source;
  Component* psource;
	
public:
  
  Component* get_ptr();
  double get_size();
  Data_value read(double number = 0);
  void simulate();
  void info();
  void load_source(Component* ptr);
  string get_source();
  string get_label();
  Display(string def);
  ~Display();
  		 
};

#endif
