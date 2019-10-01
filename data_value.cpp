#ifndef DATA_VALUE
#define DATA_VALUE

#include<iostream>


class Data_value : public Component {

	private:
		double value;
		bool valid;
	
	public:
		bool isvalid();
		void write();
		void read();
		Data_value();
		~Data_value();
	
}

#endif
