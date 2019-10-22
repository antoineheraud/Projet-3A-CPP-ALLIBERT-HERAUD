#ifndef BUS_H_
#define BUS_H_

#include<iostream>
#include"components.hpp"
#include"FIFO.hpp"

using namespace std;

class Bus : public Component {

	private:
		string label;
		string source;
		Component* psource;
		int width;
		int counter;
		FIFO<Data_value> pending_data;
    FIFO<Data_value> ready_data;

		int pending();
		int ready();
		void read();
		void store();

	public:
		void simulate();
    void bind(Component* ptr);
    Data_value get_data(double number = 0);
		int getCounter();
		Bus(string def);
		~Bus();
    double get_size();
    void info();

};


#endif
