#pragma once
#include <iostream>
#include "file-interpreter.hpp"
#include "instruction-type.hpp"
#include "instruction-mnemonic.hpp"

using namespace std;

string instructionReconstruction(string binary, string values[]) {

  // TIPO R
  if(opcode(binary) == "0110011") {

    typeR(binary, values);

    return mnemonicTypeR(values[3], values[0]) + 
           " x" + to_string(binaryIntConverter(values[4])) +
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
    
    typeI(binary, values);

    return mnemonicTypeI(opcode(binary), values[3], values[0]) +
               " x" + to_string(binaryIntConverter(values[4])) +
               ", " + to_string(binaryIntConverter(values[0] + values[1])) +
               "(x" + to_string(binaryIntConverter(values[2])) + ")";
  }

  // TIPO I JALR
  else if(opcode(binary) == "1100111") {
    typeI(binary, values);

    return mnemonicTypeI(opcode(binary), values[3], values[0]) +
               " x" + to_string(binaryIntConverter(values[4])) +
              ", x" + to_string(binaryIntConverter(values[2])) +
              ", " + to_string(getPC() + binaryIntConverter(values[0] + values[1]));
  }

  // TIPO S
  else if(opcode(binary) == "0100011") {

    typeS(binary, values);

    return mnemonicTypeS(values[3]) +
               " x" + to_string(binaryIntConverter(values[1])) +
               ", " + to_string(binaryIntConverter(values[0] + values[4])) +
               "(x" + to_string(binaryIntConverter(values[2])) + ")";
  }

  // TIPO B
  else if(opcode(binary) == "1100011") {

    typeB(binary, values);

    return mnemonicTypeB(values[4]) + 
           " x" + to_string(binaryIntConverter(values[3])) +
           ", x" + to_string(binaryIntConverter(values[2])) +
           ", " + to_string(getPC() + 
           binaryIntConverter(values[0] + values[1] + values[5] + values[6]));
  } 
  
  // TIPO J
  else if(opcode(binary) == "1101111") {
    
    typeJ(binary, values);

    return mnemonicTypeJ() +
           " x" + to_string(binaryIntConverter(values[4])) +
           " x" + to_string(getPC() + 
           binaryIntConverter(values[0] + values[1] + values[2] + values[3]));
  }

  // TIPO U
  else if(opcode(binary) == "0110111" || opcode(binary) == "0010111") {

    typeU(binary, values);

    return mnemonicTypeU(opcode(binary)) +
           " x" + to_string(binaryIntConverter(values[0])) +
           ", " + to_string(getPC() + binaryIntConverter(values[1]));
  }
}