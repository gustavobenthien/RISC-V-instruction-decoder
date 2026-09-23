#pragma once
#include <iostream>
using namespace std;

static int pc = 0;

int getPC() {
  return pc;
}

void incrementPC() {
  pc += 4;
}