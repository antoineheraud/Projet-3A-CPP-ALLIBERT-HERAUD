#ifndef CPU_REGISTER
#define CPU_REGISTER

#include<iostream>

class CPU_Register : public Component {

	private:
		queue<double> value;
		
	public:
		void write();
		void read();
		bool isempty();
		CPU_Register(fstream fichier );
		~CPU_Register();
		
}

#endif
