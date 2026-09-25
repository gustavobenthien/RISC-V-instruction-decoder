#pragma once
#include <iostream>
#include "file-interpreter.hpp"
#include "instruction-type.hpp"
#include "instruction-mnemonic.hpp"
#include "instruction-recomposition.hpp"
#include "cpi-instructions.hpp"
#include "pc-control.hpp"

using namespace std;

void instructionDecoder(string binary) {
  string values[7];

  cout << "PC: " << getPC() << endl;
  cout << "-------------------" << endl;
  cout << "Format: " << typeIdentification(opcode(binary)) << endl;
  
  if(typeIdentification(opcode(binary)) == 'R') {
    typeR(binary, values);
    cout << "Mnemonic: " << mnemonicTypeR(values[3], values[0]) << endl;
    cout << "RD: " << binaryIntConverter(values[4]) << endl;
    cout << "RS1: " << binaryIntConverter(values[2]) << endl;
    cout << "RS2: " << binaryIntConverter(values[1]) << endl;
    cout << "FUNCT3: " << values[3] << endl;
    cout << "FUNCT7: " << values[0] << endl; 
  }

  else if(typeIdentification(opcode(binary)) == 'I') {
    typeI(binary, values);
    cout << "Mnemonic: " << mnemonicTypeI(opcode(binary), values[3], values[0]) << endl;
    cout << "RD: " << binaryIntConverter(values[4]) << endl;
    cout << "RS1: " << binaryIntConverter(values[2]) << endl;
    cout << "IMM: " << binaryIntConverter(values[0] + values[1]) << endl;
    cout << "FUNCT3: " << values[3] << endl;
  }

  else if(typeIdentification(opcode(binary)) == 'S') {
    typeS(binary, values);
    cout << "Mnemonic: " << mnemonicTypeS(values[3]) << endl;
    cout << "RS1: " << binaryIntConverter(values[2]) << endl;
    cout << "RS2: " << binaryIntConverter(values[1]) << endl;
    cout << "IMM: " << binaryIntConverter(values[0] + values[4]) << endl;
  }

  else if(typeIdentification(opcode(binary)) == 'B') {
    typeB(binary, values);
    cout << "Mnemonic: " << mnemonicTypeB(values[4]) << endl;
    cout << "RS1: " << binaryIntConverter(values[3]) << endl;
    cout << "RS2: " << binaryIntConverter(values[2]) << endl;
    cout << "IMM: " << binaryIntConverter(values[0] + values[1] + values[5] + values[6]) << endl;
  }

  else if(typeIdentification(opcode(binary)) == 'J') {
    typeJ(binary, values);
    cout << "Mnemonic: " << mnemonicTypeJ() << endl;
    cout << "RD: " << binaryIntConverter(values[4]) << endl;
    cout << "IMM: " << binaryIntConverter(values[0] + values[1] + values[2] + values[3]) << endl;
  }

  
  else if(typeIdentification(opcode(binary)) == 'U') {
    typeU(binary, values);
    cout << "Mnemonic: " << mnemonicTypeU(opcode(binary)) << endl;
    cout << "RD: " << binaryIntConverter(values[1]) << endl;
    cout << "IMM: " << binaryIntConverter(values[0]) << endl;
  }

  cout << "-------------------" << endl;  
  cout << "Hexadecimal instruction: " << endl;
  cout << "-------------------" << endl;
  cout << binaryHexaConverter(binary) << endl;
  cout << "-------------------" << endl;
  cout << "Assembly instruction: " << endl;
  cout << "-------------------" << endl;
  cout << instructionReconstruction(binary) << endl;
  cout << "-------------------" << endl << endl;
}

void instructionsCPI() {
  cout << "Instruction type count:" << endl; 
  cout << "-------------------" << endl;
  cout << "R: " << getAmountR() << endl;
  cout << "I: " << getAmountI() << endl;
  cout << "S: " << getAmountS() << endl;
  cout << "B: " << getAmountB() << endl;
  cout << "J: " << getAmountJ() << endl;
  cout << "U: " << getAmountU() << endl;
  cout << "-------------------" << endl;

  cout << "Avarage percentage per type:" << endl;
  cout << "-------------------" << endl;
  cout << "R: " << avarageCPI('R') << "%" << endl;
  cout << "I: " << avarageCPI('I') << "%" << endl;
  cout << "S: " << avarageCPI('S') << "%" << endl;
  cout << "B: " << avarageCPI('B') << "%" << endl;
  cout << "J: " << avarageCPI('J') << "%" << endl;
  cout << "U: " << avarageCPI('U') << "%" << endl;
  cout << "-------------------" << endl;
}

void menu() {
  cout << "RISC-V DECODER: " << endl;
  cout << "1 ) Decode entire file" << endl;
  cout << "2 ) Decode next line" << endl;
  cout << "3 ) set PC" << endl;
  cout << "4 ) reset PC" << endl;
  cout << "5 ) reset file" << endl;
  cout << "6 ) exit" << endl;
  cout << ">: ";
}

void usableMenu() {
  int choice;
  int pcValue;

  bool running = true;

  while(running) {

    cout << endl;
    menu();
    cin >> choice;

    switch(choice) {

      case 1 : 
        while(1) {
          string line = lineReader();
          if(line == "end") {
            instructionsCPI();
            resetCount();
            break;
          }
          
          instructionDecoder(line);
        }
        break;

      case 2 :
        instructionDecoder(lineReader());
        break;

      case 3 :
        cout << "Enter PC value: ";
        cin >> pcValue;
        setPC(pcValue);
        break;

      case 4 :
        cout << "PC reseted!";
        resetPC();
        break;

      case 5 :
        cout << "file reseted!";
        resetFile();
        break;

      case 6 : 
        running = false;
        break;

      default :
        cout << "Invalid" << endl << endl;
        break;
    }
  }
}