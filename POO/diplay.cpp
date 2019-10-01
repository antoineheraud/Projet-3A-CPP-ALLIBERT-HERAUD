#ifndef DISPLAY
#define DISPLAY

#include<iostream>

using namespace std;

class Display : public Component {

	private:
		int refresh;
		int counter;
		string source;
		
		void read();
		void print();
	
	public:
		void simulate();
		Display(FILE* def);
		~Display();
		 
}


#endif
