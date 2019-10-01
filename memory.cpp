#ifndef MEMORY
#define MEMORY

#include<iostream>

using namespace std;

class Memory : public Component {

	private:
		string label;
		string source;
		Component* psource;
		int counter;
		double size;
		int access_time;
		
		void read();
		void store();
		void erase();
	
	public:
		void simulate();
		Memory(string def);
		~Memory();

}

Memory(string def) {
	FILE* f;
	f = fopen(def, "r");
	if (f == NULL) {
    	cout << "Impossible d'ouvrir le fichier en écriture !" << endl;
	}
	else {
	
	
	}


#endif
