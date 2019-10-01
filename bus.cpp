#ifndef BUS
#define BUS

#include<iostream>

using namespace std;

class Bus : public Component {

	private:
		string label;
		string source;
		Component* psource;
		int width;
		int counter;
		vector<double> data;
		
		int pending();
		int ready();
		void read();
		void store();
	
	public:
		void simulate();
		int getCounter();
		Bus(string def);
		~Bus();

}


#endif
