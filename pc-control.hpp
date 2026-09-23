#pragma once
#include <iostream>
using namespace std;

static int pc = 0;


int getPC() {
  return pc;
}

void setPC(int value) {
  pc = value;
}

void incrementPC() {
  pc += 4;
}

void resetPC() {
  pc = 0;
}
