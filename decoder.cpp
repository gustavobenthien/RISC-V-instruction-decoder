#include <iostream>
#include <fstream>
#include "operation-type.hpp"
using namespace std;

int pc = 0;

string hexaToBinary(string hexadecimal) {

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

string lineReader() {

  /*
    O modificador estatico mantem o arquivo aberto
    na ultima linha que fora consultado.
  */

  static ifstream file("./rom.txt");
  string line;

  if(file.is_open()) {

    getline(file, line);
    pc += 4;

    if(line.substr(0,2) == "0x" || line.substr(0,2) == "0X") {
      return hexaToBinary(line);
    } else {
      return line;
    }
  }

  return "ERROR";
}

int main() {
  string aux[5];
  string value = hexaToBinary("0x00500413"); 
}