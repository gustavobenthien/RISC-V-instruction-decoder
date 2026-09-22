#pragma once
#include <iostream>
#include "instruction-type.hpp"
#include "instruction-mnemonic.hpp"
#include "instruction-type.hpp"
#include "file-interpreter.hpp"

using namespace std;

void detectType(string binary, string values[]) {

  // TIPO R
  if(opcode(binary) == "0110011") {

    typeR(binary, values);

    cout << "format: R" << endl; 
    cout << "funct7: " << binaryIntConverter(values[0]) << endl;
    cout << "rs2: " << binaryIntConverter(values[1]) << endl;
    cout << "rs1: " << binaryIntConverter(values[2]) << endl;
    cout << "funct3: " << binaryIntConverter(values[3]) << endl;
    cout << "rd: " << binaryIntConverter(values[4]) << endl;
  }
}

int main() {
  string values[5];

  detectType(lineReader(), values);
  detectType(lineReader(), values);

  return 0;
}