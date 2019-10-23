#ifndef PLATEFORM
#define PLATEFORM

#include<vector>
#include<iostream>

using namespace std;

class Plateform {
  
private:
  int counter;
  vector<Component*> tableau;
  int nb_obj;

public:
  vector<Component*> get_tab();
  int get_nb_obj();
  void simulate();
  Plateform(string def);
  Component* create(string def);
  ~Plateform();

};


#endif
