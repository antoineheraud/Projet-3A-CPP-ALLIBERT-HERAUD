#ifndef CPU_REGISTER_
#define CPU_REGISTER_

#include<stdio.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<stdexcept>
#include"data_value.hpp"
#include<queue>

using namespace std;

class CPU_Register {

private:
  queue<double> FIFO_value;

public:
  void write(double v);
  Data_value read();
  bool isempty();
  CPU_Register();
  ~CPU_Register();

};
#endif
