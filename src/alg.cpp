// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
 double step = 1;
    for (uint16_t i = 1; i <= n; i++) {
        step = step * value;
}
    return step;
}

uint64_t fact(uint16_t n) {
 uint64_t fac = 1;
    for (uint16_t i = 1; i <= n; i++) {
        fac = fac * i;
    }
    return fac;
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
    uint16_t n = 1;
    for (uint16_t i = 2; i <= count ; i + 1) {
        n = 2 * i - 1;
        sin += pown(-1, i - 1) * calcItem(x, n);
    }
    return sin;
}

double cosn(double x, uint16_t count) {
 double cos = 1;
    uint16_t n = 1;
    for (uint16_t i = 2; i <= count; i + 1) {
        n = 2 * i - 1;
        cos += pown(-1, i - 1) * calcItem(x, n);
    }
    return cos;
}
