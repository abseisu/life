#ifndef LIFE_H
#define LIFE_H

#include <stdbool.h>
#include <stdlib.h>
#include "life_dynamic.c"


bool isAlive(int array[], size_t index, size_t size);

bool shouldDie(int array[], size_t index, size_t size);

int numOfDigits (int n);

#endif
