#pragma once
#include <iostream>
#include <fstream>
#include "pc-control.hpp"
using namespace std;

static ifstream file("./rom.txt");

string binaryHexaConverter(string binary) {

  string hexadecimal = "0x";

  string binaryTable[16] = {
    "0000", "0001", "0010", "0011",
    "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011",
    "1100", "1101", "1110", "1111"
  };

  string hexaTable[16] = {
    "0", "1", "2", "3",
    "4", "5", "6", "7",
    "8", "9", "A", "B",
    "C", "D", "E", "F"
  };

  for(int i = 0; i < 32; i += 4) {
    string tableIndex = binary.substr(i, 4);

    for(int j = 0; j < 16; j++) {
      if(tableIndex == binaryTable[j]) {
        hexadecimal += hexaTable[j];
      }
    }
  }

  return hexadecimal;
}

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

bool isHexadecimal(string line) {

    if (line.size() < 3 || line[0] != '0' ||
       (line[1] != 'x' && line[1] != 'X')) {

        return false;
    }

    for (int i = 2; i < line.size(); i++) {

        if (!isxdigit(line[i])) return false;
    }

    return true;
}

string lineReader() {

  static ifstream file("./rom.txt");
  string line;

  while (getline(file, line)) {

    int first = line.find_first_not_of(" \t");

    if (first == string::npos) continue;

    if (line[first] == '#' || line.substr(first, 2) == "//") continue;

    line = line.substr(first);

    if (line.substr(0, 2) == "0x" || line.substr(0, 2) == "0X") {

      if (!isHexadecimal(line)) {
        cout << "Invalid hexadecimal: " << line << endl;
        continue;
      }

      incrementPC();
      return hexaBinaryConverter(line);
    }

    incrementPC();
    return line;
  }

  return "end";
}

void resetFile() {
  file.close();
}