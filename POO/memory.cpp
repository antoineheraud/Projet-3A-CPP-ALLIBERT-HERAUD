#ifndef MEMORY
#define MEMORY

#include<iostream>

using namespace std;

class Memory : public Component {

	private:
		string label;
		string source;
		int counter;
		double size;
		int access_time;
		
		void read();
		void store();
		void erase();
	
	public:
		void simulate();
		Memory(FILE* def);
		~Memory();

}


#endif
