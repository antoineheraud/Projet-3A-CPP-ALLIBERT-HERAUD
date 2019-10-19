//Display.hpp

#ifndef DISPLAY
#define DISPLAY

#include "components.hpp"

using namespace std;

class Display : public Component {

private:
  int refresh;
  int counter;
  string source;
  Component* psource;
	
public:
  void simulate();
  void load_source();
  Display(string def);
  ~Display();
		 
};

#endif
