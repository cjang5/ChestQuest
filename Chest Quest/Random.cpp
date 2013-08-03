#include "stdafx.h"
#include <cstdlib> //for srand and rand

int Random(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}