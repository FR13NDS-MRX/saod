#pragma once
#include <vector>
#include <iostream>

using namespace std;

struct symb {
	char smb;
	int sum = 0;
	double pr = 0;
	std::string code;
};

void sort(std::vector<symb>& charNumb, int L, int R);
float entropy(std::vector<symb>& charNumb);
float midLength(std::vector<symb>& charNumb);

vector<symb> probality();
void Shannon();