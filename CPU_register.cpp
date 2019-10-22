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
	if (FIFO_value.isempty()){
		Data_value F_V(0,false);
		return F_V;
	}
	double val;
	val = FIFO_value.dequeue();
	Data_value D_REG(val,true);
	return D_REG;
}
bool CPU_Register::isempty(){
	if (FIFO_value.isempty()){
		return true;
	}
	else {
		return false;
	}
}
