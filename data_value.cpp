#include "data_value.hpp"


bool Data_value::isvalid(){
  return this->valid;
}

double Data_value::get_value(){
  return this->value;
}

void Data_value::update(double val, bool validity){
  this->value = val;
  this->valid = validity;
}

Data_value::Data_value(){
  this->value = 0;
  this->valid = false;
}

Data_value::Data_value(double val, bool validity){
  this->value = val;
  this->valid = validity;
}

Data_value::~Data_value(){
}
