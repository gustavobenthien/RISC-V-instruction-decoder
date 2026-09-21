#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;


string lineReader() {

  /*
  O modificador estatico mantem o arquivo aberto
  na ultima linha que fora consultado.
*/

  static ifstream file("./rom.txt");
  string line;

  if(file.is_open()) {
    getline(file, line);
    return line;
  }

  return "ERROR";
}

int main() {
  string aux;

  for(int i = 0; i < 6; i++) {
    cout << "Next line: ";
    cin >> aux;
    cout << lineReader() << endl;
  }
}