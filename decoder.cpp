#include <iostream>
#include <fstream>
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

void divideBinary(string binary, string list[]) {

  /*
  0 = imediato
  1 = rs1
  2 = funct3
  3 = rd
  4 = opcode
  */

  list[0] = binary.substr(0, 12);
  list[1] = binary.substr(12, 5);
  list[2] = binary.substr(17, 3);
  list[3] = binary.substr(20, 5);
  list[4] = binary.substr(25, 7);
}

int main() {
  string aux[5];
  string value = hexaToBinary("0x00500413");

  cout << value << endl;

  divideBinary(value, aux);

  for(int i = 0; i < 5; i++) {
    cout << aux[i] << endl;
  }
 
}