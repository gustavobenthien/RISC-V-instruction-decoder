#pragma once
#include <iostream>

using namespace std;

string mnemonicTypeR(string funct3, string funct7) {

  if(funct7 == "0000000") {

    if(funct3 == "000") return "add";
    else if(funct3 == "111") return "and";
    else if(funct3 == "110") return "or";
    else if(funct3 == "100") return "xor";
    else if(funct3 == "001") return "sll";
    else if(funct3 == "101") return "srl";
    else if(funct3 == "010") return "slt"; 
    
  } 
  else if (funct7 == "0100000") {

    if(funct3 == "000") return "sub";
    else if(funct3 == "101") return "sra";
    else if(funct3 == "010") return "sltu";
  }
}

string mnemonicTypeI(string opcode, string funct3, string funct7) {

  if(opcode == "0010011") {
    
    if(funct3 == "000") return "addi";
    else if(funct3 == "111") return "andi";
    else if(funct3 == "110") return "ori";
    else if(funct3 == "100") return "xori";
    else if(funct3 == "010") return "slti";
    else if(funct3 == "011") return "sltiu";
    
    if(funct7 == "0000000") {

      if(funct3 == "001") return "slli";
      else if(funct3 == "101") return "srli";

    }
    else if(funct7 == "0100000") {

      if(funct3 == "101") return "srai";
    }
        
  }
  else if(opcode == "0000011") {

    if(funct3 == "000") return "lb";
    else if(funct3 == "100") return "lbu";
    else if(funct3 == "001") return "lh";
    else if(funct3 == "101") return "lhu";
    else if(funct3 == "010") return "lw";
  }
  else if(opcode == "1100111") {
    
    if(funct3 == "000") return "jalr";
  }
}

string mnemonicTypeS(string funct3) {

  if(funct3 == "000") return "sb";
  else if(funct3 == "001") return "sh";
  else if(funct3 == "010") return "sw";
}

string mnemonicTypeB(string funct3) {

  if(funct3 == "000") return "beq";
  else if(funct3 == "001") return "bne";
  else if(funct3 == "100") return "blt";
  else if(funct3 == "110") return "bltu";
  else if(funct3 == "101") return "bge";
  else if(funct3 == "111") return "bgeu";
}

string mnemonicTypeJ() { return "jal"; }

string mnemonicTypeU(string opcode) { 
  if(opcode == "0110111") return "lui";
  else if(opcode == "0010111") return "auipc";
}