#ifndef CPU_REGISTER_
#define CPU_REGISTER_

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
