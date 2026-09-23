#pragma once
#include <iostream>
#include "instruction-type.hpp"
#include "instruction-mnemonic.hpp"
#include "instruction-recomposition.hpp"
#include "file-interpreter.hpp"

using namespace std;

int PC = 0;

void instructionFields(string binary, string fields[]) {
  cout << "-------------------" << endl;
  cout << "Format: " << typeIdentification(opcode(binary)) << endl;
  
  if(typeIdentification(opcode(binary)) == 'R') {
    typeR(binary, fields);
    cout << "Mnemonic: " << mnemonicTypeR(fields[3], fields[0]) << endl;
    cout << "RD: " << binaryIntConverter(fields[4]) << endl;
    cout << "RS1: " << binaryIntConverter(fields[2]) << endl;
    cout << "RS2: " << binaryIntConverter(fields[1]) << endl;
    cout << "FUNCT3: " << binaryIntConverter(fields[3]) << endl;
    cout << "FUNCT7: " << binaryIntConverter(fields[0]) << endl; 
  }

  else if(typeIdentification(opcode(binary)) == 'I') {
    typeI(binary, fields);
    cout << "Mnemonic: " << mnemonicTypeI(opcode(binary), fields[3], fields[0]) << endl;
    cout << "RD: " << binaryIntConverter(fields[4]) << endl;
    cout << "RS1: " << binaryIntConverter(fields[2]) << endl;
    cout << "IMM: " << binaryIntConverter(fields[0] + fields[1]) << endl;
    cout << "FUNCT3: " << binaryIntConverter(fields[3]) << endl;
  }

  else if(typeIdentification(opcode(binary)) == 'S') {
    typeS(binary, fields);
    cout << "Mnemonic: " << mnemonicTypeS(fields[3]) << endl;
    cout << "RS1: " << binaryIntConverter(fields[2]) << endl;
    cout << "RS2: " << binaryIntConverter(fields[1]) << endl;
    cout << "IMM: " << binaryIntConverter(fields[0] + fields[4]) << endl;
  }

  else if(typeIdentification(opcode(binary)) == 'B') {
    typeB(binary, fields);
    cout << "Mnemonic: " << mnemonicTypeB(fields[4]) << endl;
    cout << "RS1: " << binaryIntConverter(fields[3]) << endl;
    cout << "RS2: " << binaryIntConverter(fields[2]) << endl;
    cout << "IMM: " << binaryIntConverter(fields[0] + fields[1] + fields[5] + fields[6]) << endl;
  }

  cout << "-------------------" << endl;
  cout << "Assembly instruction: " << endl;
  cout << "-------------------" << endl;
  cout << instructionReconstruction(binary, fields) << endl;
  cout << "-------------------" << endl << endl;
}

int main() {
  string fields[10];


  for(int i = 0; i < 10; i++) {
    instructionFields(lineReader(), fields);
  }

  return 0;
}