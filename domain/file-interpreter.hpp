#pragma once
#include <iostream>
#include <fstream>
#include "pc-control.hpp"
using namespace std;

static ifstream file("./rom.txt");

string hexaBinaryConverter(string hexadecimal) {

  string table[16] = {
    "0000", "0001", "0010", "0011",
    "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011",
    "1100", "1101", "1110", "1111"
  };

  string binary = "";

  for(char c : hexadecimal.substr(2, 8)) {

    if(c >= 48 && c <= 57) {
      binary += table[c - 48];
    }
    else if(c >= 65 && c <= 70) {
      binary += table[(c - 65) + 10];
    }
  }

  return binary;
}

int binaryIntConverter(string binary) {
  
  int result = 0;

  if(binary[0] == '1') result = -1;

  for(char c : binary) {
    result = result * 2 + (c - 48);
  }

  return result;
}

string lineReader() {

  string line;

  if(!(file.is_open())) {
    file.open("./rom.txt");
  } 
  
  if(getline(file, line)) {
    incrementPC();

    if(line.substr(0,2) == "0x" || line.substr(0,2) == "0X") {
      return hexaBinaryConverter(line);
    } else {
      return line;
    }
  } else {
    return "end";
  } 
}

void resetFile() {
  file.close();
}