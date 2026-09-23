#pragma once
#include <iostream>
using namespace std;

string opcode(string binary) {
  return binary.substr(25, 7);
}

void typeR(string binary, string values[]) {

  /*
    Opcode: 0110011 

    0 = funct7
    1 = rs2
    2 = rs1
    3 = funct3
    4 = rd
    5 = opcode
  */

  values[0] = binary.substr(0, 7);
  values[1] = binary.substr(7, 5);
  values[2] = binary.substr(12, 5);
  values[3] = binary.substr(17, 3);
  values[4] = binary.substr(20, 5);
}

void typeI(string binary, string values[]) {

  /*
    Tipo I ALU
    Opcode: 0010011
    
    Tipo I LOAD
    Opcode: 0000011

    0 = imediato/funct7 (7 bits)
    1 = imediato (5 bits)
    2 = rs1
    3 = funct3
    4 = rd
    5 = opcode
  */

  values[0] = binary.substr(0, 7);
  values[1] = binary.substr(7, 5);
  values[2] = binary.substr(12, 5);
  values[3] = binary.substr(17, 3);
  values[4] = binary.substr(20, 5);
}

void typeS(string binary, string values[]) {

  /*
    Opcode: 0100011

    0 = imediato (7 bits)
    1 = rs2
    2 = rs1
    3 = funct3
    4 = imediato (5 bits)
    5 = opcode
  */

  values[0] = binary.substr(0, 7);
  values[1] = binary.substr(7, 5);
  values[2] = binary.substr(12, 5);
  values[3] = binary.substr(17, 3);
  values[4] = binary.substr(20, 5);
}

void typeB(string binary, string values[]) {

  /*
    Opcode: 1100011

    0 = imediato (1 bit)
    1 = imediato (6 bits)
    2 = rs2
    3 = rs1
    4 = funct3
    5 = imediato (4 bits)
    6 = imediato (1 bit)
    7 = opcode
  */

  values[0] = binary.substr(0, 1);   
  values[1] = binary.substr(1, 6);   
  values[2] = binary.substr(7, 5);   
  values[3] = binary.substr(12, 5);  
  values[4] = binary.substr(17, 3);  
  values[5] = binary.substr(20, 4);  
  values[6] = binary.substr(24, 1);  
}

void typeJ(string binary, string values[]) {

  /*
    Opcode: 1101111

    0 = imediato (1 bit)
    1 = imediato (10 bits)
    2 = imediato (1 bit)
    3 = imediato (8 bits)
    4 = rd
    5 = opcode
  */

  values[0] = binary.substr(0, 1);
  values[1] = binary.substr(1, 10);
  values[2] = binary.substr(11, 1);
  values[3] = binary.substr(12, 8);
  values[4] = binary.substr(20, 5);
}