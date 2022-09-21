#pragma once
#include <iostream>

using namespace std;

struct enterprise
{
	char fio[30];
	short int number;
	char position[22];
	char date[10];

};

ofstream& operator << (ofstream& output, enterprise data);