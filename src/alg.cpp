// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
   double step = 1;
  if (!n) return 1;
    while (n) {
    if (n % 2 == 0){
      n /= 2;
      value *= value;
      } 
      else
      {
      n--;
      step *= value;
     }
     }
     return step;
}

uint64_t fact(uint16_t n) {
    if(n < 0)
        return 0;
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1); 
}

double calcItem(double x, uint16_t n) {
  double slag = 0;
    slag = pown(x, n) / fact(n);
    return slag;
}

double expn(double x, uint16_t count) {
  double e = 1;
    for (uint16_t i = 1; i <= count; i++) {
        e += calcItem(x, i);
    }
    return e;
}

double sinn(double x, uint16_t count) {
  double sin = x;
  double slag = 0;
    if (count == 1) {
        return sin;
    }
    for (uint16_t i = 2; i <= count ; i ++) {
        slag = (pown(-1, i - 1) * calcItem(x, 2 * i - 1));
        sin += slag;
    }
    return sin;
}

double cosn(double x, uint16_t count) {
  double cos = 1;
  double slag = 0;
    if (count == 1) {
        return cos;
    }
    for (uint16_t i = 2; i <= count; i ++) {
        slag = pown(-1, i - 1) * calcItem(x, 2 * i - 1);
        cos += slag;
    }
    return cos;
}
