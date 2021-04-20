#ifndef THISTLETHWAITE_H
#define THISTLETHWAITE_H

#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include "arm.h"

vector<int> solution;

typedef vector<int> rush;

rush movement(int move, rush state);
int inverse(int move);
rush pass(rush state);

#endif // THISTLETHWAITE_H
