#pragma once
#include "struct.h"
#include "List.h"
#include <iostream>

using sortQueue = Queue<enterprise*>;

void BSearch(enterprise** Q, const char* x, int L, int R, int keySize, Queue<enterprise*>& data);