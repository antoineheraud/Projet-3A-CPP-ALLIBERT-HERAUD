#include"CPU_register.hpp"


CPU_Register::CPU_Register(){
	FIFO<double> FIFO_value = FIFO<double>();
}
CPU_Register::~CPU_Register(){
	
}

void CPU_Register::write(double v){
	FIFO_value.enqueue(v);
}
Data_value CPU_Register::read(){
	Data_value D_V(FIFO_value.dequeue(),true);
	return D_V;
}
bool CPU_Register::isempty(){
	if (FIFO_value.isempty()){
		return true;
	}
	else {
		return false;
	}
}
