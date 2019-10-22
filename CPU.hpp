#ifndef CPU_H
#define CPU_H
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<list>
#include<vector>
#include<string.h>
#include"components.hpp"
#include"program.hpp"
#include "CPU_register.hpp"

using namespace std;

class CPU : public Component {

	private:
		CPU_Register* reg;
		double freq;
		int cores;
		int active;
		string label;
		Program* Prog;


	public:
		void simulate();
		CPU(string def);
		~CPU();
		double get_size();
		Data_value read();
		Data_value get_data(double number = 0);
		void info();

};
#endif
