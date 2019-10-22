
#include "CPU.hpp"
using namespace std;
int main(){
  // Program Prog("testdata/program.txt");
  // if (Prog.is_finished()){
  //   cout << "fin" << endl;
  // }
  // cout << "On compute" << endl ;
  // for (int i = 0; i<51; ++i){
  //   cout << Prog.compute() << endl;
  // }
  // cout << Prog.compute() << endl;
  // cout << "finished ? " << Prog.is_finished() << endl;
  // cout << Prog.compute() << endl;
  // Prog.reset();
  // cout << "really? " << Prog.is_finished() << endl;
  // cout << Prog.compute() << endl;
  //return 0;

  // Test CPU

  CPU cpu1("testdata/cpu1.txt");
  cpu1.info();
  Data_value DV = cpu1.read();
  for (int i = 0;i<46;++i){
    cpu1.simulate();
    for (int j = 0;j<4;++j){
      DV = cpu1.read();
      double result = DV.get_value();
      cout << result << endl;
      //cout << "validité ? " << DV.isvalid() << endl;
    }
  }
  // cpu1.simulate();
  // cout << "get_data" << endl;
  // Data_value DV = cpu1.read();
  // double result = DV.get_value();
  //cout << result << endl;
  // cout << "validité ? " << DV.isvalid() << endl;
  // cpu1.simulate();
  //DV = cpu1.get_data();
  //cout << DV.get_value() << endl;
  //cout << "validité ? " << DV.isvalid() << endl;
  //cpu1.simulate();
  // DV = cpu1.get_data();
  // cout << DV.get_value() << endl;
  // cout << "validité ? " << DV.isvalid() << endl;
  // cpu1.simulate();
  // DV = cpu1.get_data();
  // cout << DV.get_value() << endl;
  // cout << "validité ? " << DV.isvalid() << endl;
  // DV = cpu1.get_data();
  // cout << DV.get_value() << endl;
  // cout << "validité ? " << DV.isvalid() << endl;
  // DV = cpu1.get_data();
  // cout << DV.get_value() << endl;
  // cout << "validité ? " << DV.isvalid() << endl;
  // DV = cpu1.get_data();
  // cout << DV.get_value() << endl;
  // cout << "validité ? " << DV.isvalid() << endl;
  // DV = cpu1.get_data();
  // cout << DV.get_value() << endl;
  // cout << "validité ? " << DV.isvalid() << endl;
  // DV = cpu1.get_data();
  // cout << DV.get_value() << endl;
  // cout << "validité ? " << DV.isvalid() << endl;


  //for (int i = 0; i < 7; i++){
  //cpu1.simulate();
  //DV = cpu1.get_data();
  //cout << "Pute" << endl;
  //cout << DV.get_value() << endl;
  //cout << DV.isvalid() << endl;
  //}

}
