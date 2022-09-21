#include "Coding.h"
#include <fstream>
#include "struct.h"

using namespace std;

ofstream& operator << (ofstream& output, enterprise* data) {
	output << data->fio << " " << data->number << " " << data->position << " " << data->date << "\n";
	return output;
}

std::vector<symb>  probality() {
	char ch;
	int numberOfsymb = 0;
	vector<symb> charNumb(256);
	vector<float> P(256);
	P.resize(0);
	std::ifstream binFile("testBase2.dat", std::ios::binary);

	while (binFile.read(&ch, 1)) {
		charNumb[static_cast<int>(ch) + 128].smb = ch;
		charNumb[static_cast<int>(ch) + 128].sum++;
		numberOfsymb++;
	}

	for (int i = 0; i < charNumb.size(); i++) {
		if (charNumb[i].sum == 0) {
			charNumb.erase(charNumb.begin() + i);
			i--;
		}
		else {
			charNumb[i].pr = static_cast<float>(charNumb[i].sum) / numberOfsymb;
			P.push_back(charNumb[i].pr);
		}

	}

	cout << "\nВсего: " << numberOfsymb << "\n\n";

	return charNumb;
}

float midLength(vector<symb>& charNumb) {
	float sumLen = 0;
	for (int i = 1; i < charNumb.size(); i++)
		sumLen += charNumb[i].pr * charNumb[i].code.size();
	return sumLen;
}

float entropy(vector<symb>& charNumb) {
	float entrop = 0;
	for (int i = 0; i < charNumb.size(); i++)
		entrop += charNumb[i].pr * -log2(charNumb[i].pr);
	return entrop;
}

void sort(vector<symb>& charNumb, int L, int R) {
	float a = charNumb[L].pr;
	int i = L, j = R;

	while (i <= j) {
		while (charNumb[i].pr > a) i++;
		while (charNumb[j].pr < a) j--;
		if (i <= j) {
			swap(charNumb[i], charNumb[j]);

			i++;
			j--;
		}
	}
	if (L < j) sort(charNumb, L, j);
	if (i < R) sort(charNumb, i, R);
}

void sort1(vector<symb>& charNumb, int L, int R) {
	int a = charNumb[R / 2].pr, i = L, j = R;

	while (i <= j) {
		while (charNumb[i].sum < a)i++;
		while (charNumb[j].sum > a)j--;
		if (i <= j) {

			swap(charNumb[i], charNumb[j]);

			i++;
			j--;
		}
	}
	if (L < j) sort(charNumb, L, j);
	if (i < R) sort(charNumb, i, R);
}
