#ifndef PLATEFORM
#define PLATEFORM

#include<iostream>

using namespace std;

class Plateform {
  
private:
  int counter;
   Component* tableau;
  int nb_obj;

public:
  Component* get_tab();
  int get_nb_obj();
  void simulate();
  Plateform(string def);
  Component& create(string def);
  ~Plateform();

};


#endif
