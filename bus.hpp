#ifndef BUS_H_
#define BUS_H_

#include<iostream>
#include"components.hpp"
#include<queue>

using namespace std;

class Bus : public Component {
  
private:
  string label;
  string source;
  Component* psource;
  int width;
  int counter;
  queue<Data_value> pending_data;
  queue<Data_value> ready_data;
  
  int pending();
  int ready();
  void read();
  void store();
  
public:
  void simulate();
  void bind(Component* ptr);
  Data_value read(double number = 0);
  int getCounter();
  Bus(string def);
  ~Bus();
  double get_size();
  void info();
  string get_source();
  string get_label();
  void load_source(Component* ptr);
  Component* get_ptr();
};


#endif
