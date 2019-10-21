//Display.hpp

#ifndef DISPLAY_
#define DISPLAY_

#include "components.hpp"

using namespace std;

class Display : public Component {
  
private:
  int refresh;
  int counter;
  string source;
  
	
public:
  Component* psource;

  double get_size();
  Data_value get_data(double number = 0);
  void simulate();
  void info();
  void load_source(Component* ptr);
  string get_source();
  Display(string def);
  ~Display();
  		 
};

#endif
