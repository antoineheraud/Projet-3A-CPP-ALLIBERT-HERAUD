#ifndef CPU
#define CPU

#include<iostream>

using namespace std;

class CPU : public Component {

	private:
		CPU_Register reg;
		double freq;
		const int cores;
		int active;
		string label;
		FILE* code;
		
		void write();
		void read();
		void activate();
		void desactivate();

	public:
		void simulate();
		CPU(string def);
		~CPU();
	
}


#endif
