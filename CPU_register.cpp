#include"CPU_register.hpp"


CPU_Register::CPU_Register(){
}
CPU_Register::~CPU_Register(){
  
}

void CPU_Register::write(double v){
  FIFO_value.push(v);
}
Data_value CPU_Register::read(){
  Data_value D_V(0, false);
  if(!FIFO_value.empty()){
	D_V.update(FIFO_value.front(),true);
	FIFO_value.pop();
  }
  return D_V;
}
bool CPU_Register::isempty(){
	if (FIFO_value.empty()){
		return true;
	}
	else {
		return false;
	}
}
