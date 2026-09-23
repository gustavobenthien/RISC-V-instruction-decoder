#pragma once
#include <iostream>
#include "instruction-type.hpp"
#include "instruction-mnemonic.hpp"
#include "file-interpreter.hpp"

using namespace std;

string instructionReconstruction(string binary, string values[]) {

  // TIPO R
  if(opcode(binary) == "0110011") {
    typeR(binary, values);

    string mnemonic = mnemonicTypeI(opcode(binary), values[3], values[0]); 

    return mnemonic + " x" + to_string(binaryIntConverter(values[4])) +
                     ", x" + to_string(binaryIntConverter(values[2])) +
                     ", x" + to_string(binaryIntConverter(values[1]));

  }
  // TIPO I ALU
  else if(opcode(binary) == "0010011") {

    typeI(binary, values);

    string mnemonic = mnemonicTypeI(opcode(binary), values[3], values[0]); 

    /*
      Para a operação de deslocamento o imediato é dividido no meio,
      caso seja este tipo de operação, ele utiliza apenas os 5 bits
      restante, de contrapartida, caso não seja, utiliza todos os 12
      bits.
    */
   
    if(mnemonic == "slli" || mnemonic == "srli" || mnemonic == "srai") {

         return mnemonicTypeI(opcode(binary), values[3], values[0]) +
                " x" + to_string(binaryIntConverter(values[4])) +
                ", x" + to_string(binaryIntConverter(values[2])) +
                ", " + to_string(binaryIntConverter(values[1]));
    } 
    else {

         return mnemonicTypeI(opcode(binary), values[3], values[0]) +
                " x" + to_string(binaryIntConverter(values[4])) +
                ", x" + to_string(binaryIntConverter(values[2])) +
                ", " + to_string(binaryIntConverter(values[0] + values[1]));
    } 

  }
  // TIPO I LOAD
  else if(opcode(binary) == "0000011") {

  }
  // TIPO S
  else if(opcode(binary) == "0100011") {

  }
  // TIPO B
  else if(opcode(binary) == "1100011") {

  }
  // TIPO J
  else if(opcode(binary) == "1101111") {

  }
}