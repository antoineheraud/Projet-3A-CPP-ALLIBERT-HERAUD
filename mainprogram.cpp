
#include "program.h"

int main(){
  Program Prog("testdata/program.txt");
  cout << "On compute" << endl ;
  for (int i = 0; i<10; ++i){
    cout << Prog.compute() << endl;
  }
  cout << Prog.compute() << endl;
  cout << "finished ? " << Prog.is_finished() << endl;
  Prog.reset();
  cout << "really? " << Prog.is_finished() << endl;
  cout << Prog.compute() << endl;
  return 0;
}
