#pragma once
#include <iostream>
#include "file-interpreter.hpp"
#include "instruction-type.hpp"
#include "instruction-mnemonic.hpp"
#include "instruction-recomposition.hpp"
#include "pc-control.hpp"

using namespace std;

void instructionDecoder(string binary, string fields[]) {
  cout << "PC: " << getPC() << endl;
  cout << "-------------------" << endl;
  cout << "Format: " << typeIdentification(opcode(binary)) << endl;
  
  if(typeIdentification(opcode(binary)) == 'R') {
    typeR(binary, fields);
    cout << "Mnemonic: " << mnemonicTypeR(fields[3], fields[0]) << endl;
    cout << "RD: " << binaryIntConverter(fields[4]) << endl;
    cout << "RS1: " << binaryIntConverter(fields[2]) << endl;
    cout << "RS2: " << binaryIntConverter(fields[1]) << endl;
    cout << "FUNCT3: " << fields[3] << endl;
    cout << "FUNCT7: " << fields[0] << endl; 
  }

  else if(typeIdentification(opcode(binary)) == 'I') {
    typeI(binary, fields);
    cout << "Mnemonic: " << mnemonicTypeI(opcode(binary), fields[3], fields[0]) << endl;
    cout << "RD: " << binaryIntConverter(fields[4]) << endl;
    cout << "RS1: " << binaryIntConverter(fields[2]) << endl;
    cout << "IMM: " << binaryIntConverter(fields[0] + fields[1]) << endl;
    cout << "FUNCT3: " << fields[3] << endl;
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

  else if(typeIdentification(opcode(binary)) == 'J') {
    typeJ(binary, fields);
    cout << "Mnemonic: " << mnemonicTypeJ() << endl;
    cout << "RD: " << binaryIntConverter(fields[4]) << endl;
    cout << "IMM: " << binaryIntConverter(fields[0] + fields[1] + fields[2] + fields[3]) << endl;
  }

  
  else if(typeIdentification(opcode(binary)) == 'U') {
    typeU(binary, fields);
    cout << "Mnemonic: " << mnemonicTypeU(opcode(binary)) << endl;
    cout << "RD: " << binaryIntConverter(fields[1]) << endl;
    cout << "IMM: " << binaryIntConverter(fields[0]) << endl;
  }

  cout << "-------------------" << endl;
  cout << "Assembly instruction: " << endl;
  cout << "-------------------" << endl;
  cout << instructionReconstruction(binary, fields) << endl;
  cout << "-------------------" << endl << endl;
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

  // maximo de campos que o tipo pode ter
  string fields[7];
  
  while(running) {

    cout << endl;
    menu();
    cin >> choice;

    switch(choice) {

      case 1 : 
        while(1) {
          string line = lineReader();
          if(line == "end") break;
          
          instructionDecoder(line, fields);
        }
        break;

      case 2 :
        instructionDecoder(lineReader(), fields);
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