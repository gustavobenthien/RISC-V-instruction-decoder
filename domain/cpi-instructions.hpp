#pragma once
#include <iostream>

using namespace std;

static int amountR = 0;
static int amountI = 0;
static int amountS = 0;
static int amountB = 0;
static int amountJ = 0;
static int amountU = 0;

void incrementCount(char type) {

  switch(type) {
    case 'R': amountR++;
      break;
      
    case 'I': amountI++;
      break;

    case 'S': amountS++;
      break;

    case 'B': amountB++;
      break;

    case 'J': amountJ++;
      break;

    case 'U': amountU++;
      break;
  }
}

float avarageCPI(char type) {

  int total = amountR + amountI + amountS + amountB + amountJ + amountU;

  switch(type) {
    case 'R': 
      return 100 * amountR / total;   

    case 'I': 
      return 100 * amountI / total;  

    case 'S': 
      return 100 * amountS / total;

    case 'B': 
      return 100 * amountB / total;  

    case 'J': 
      return 100 * amountJ / total;  

    case 'U': 
      return 100 * amountU / total;  
  }
}  

void resetCount() {
  amountR = 0;
  amountI = 0;
  amountS = 0;
  amountB = 0;
  amountJ = 0;
  amountU = 0;
}

int getAmountR() {
  return amountR;
}

int getAmountI() {
  return amountI;
}

int getAmountS() {
  return amountS;
}

int getAmountB() {
  return amountB;
}

int getAmountJ() {
  return amountJ;
}

int getAmountU() {
  return amountU;
}
