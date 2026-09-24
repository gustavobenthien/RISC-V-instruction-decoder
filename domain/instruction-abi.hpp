#include <iostream>

using namespace std;

string registerABI(int name) {

  if(name == 0) return "zero";
  else if(name == 1) return "ra";
  else if(name == 2) return "sp";
  else if(name == 3) return "gp";
  else if(name == 4) return "tp";
  else if(name >= 5 && name <= 7) return "t" + to_string(name - 5);
  else if(name == 8 || name == 9) return "s" + to_string(name - 8);
  else if(name >= 10 && name <= 17) return "a" + to_string(name - 10);
  else if(name >= 18 && name <= 27) return "s" + to_string(name - 16);
  else if(name >= 28 && name <= 31) return "t" + to_string(name - 25);
}