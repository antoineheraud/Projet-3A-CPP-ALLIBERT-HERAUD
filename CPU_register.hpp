#ifndef CPU_REGISTER
#define CPU_REGISTER

#include "components.hpp"

class CPU_Register : public Component {

	private:
		queue<double> value;
		
	public:
		void write();
		void read();
		bool isempty();
		CPU_Register();
		~CPU_Register();
		
};

#endif
