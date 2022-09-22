#pragma once
#include <vector>
#include <iostream>

using namespace std;

struct symb {
	char smb;
	int sum = 0;
	double pr = 0;
	string code;
};

void sort(vector<symb>& charNumb, int L, int R);
float entropy(vector<symb>& charNumb);
float midLength(vector<symb>& charNumb);

vector<symb> probality();
void Shannon();