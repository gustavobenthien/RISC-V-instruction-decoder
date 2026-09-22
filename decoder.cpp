#pragma once
#include <iostream>
#include "instruction-type.hpp"
#include "instruction-mnemonic.hpp"
#include "instruction-recomposition.hpp"
#include "file-interpreter.hpp"

using namespace std;


int main() {
  string values[5];

  cout << instructionReconstruction(lineReader(), values) << endl;  
  cout << instructionReconstruction(lineReader(), values);  

  return 0;
}