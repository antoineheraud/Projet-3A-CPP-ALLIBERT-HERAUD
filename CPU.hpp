#ifndef CPU_
#define CPU_

#include "components.hpp"

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
	
};


#endif
