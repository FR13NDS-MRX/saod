#include "Coding.h"
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

void Shannon() {
	vector<symb> charNumb = probality();
	sort(charNumb, 0, charNumb.size() - 1);
	double* Q = new double[charNumb.size() + 1];
	Q[0] = 0;
	int* L = new int[charNumb.size()];
	float H(0), Length(0);

	for (int i = 1; i < charNumb.size(); i++) {
		Q[i] = Q[i - 1] + charNumb[i - 1].pr;
		L[i] = ceil(-log2(charNumb[i - 1].pr));

		H += charNumb[i - 1].pr * -log2(charNumb[i - 1].pr);
		Length += charNumb[i - 1].pr * L[i];
	}

	for (int i = 0; i < charNumb.size(); i++) {
		for (int j = 1; j < L[i]; j++) {
			Q[i - 1] *= 2;

			if (Q[i - 1] > 1) {
				Q[i - 1]--;
				charNumb[i].code += "1";
			}
			else charNumb[i].code += "0";
		}
	}

	double k = 0;

	for (int i = 0; i < charNumb.size(); i++) {
		k += charNumb[i].pr;
		cout << i << ")" << charNumb[i].smb << " =\t" << charNumb[i].sum << "\t" << charNumb[i].pr << "\t" << charNumb[i].code << "\n";
	}

	cout << "Sum of all probabilities: " << k << endl;
	cout << "Average symbol length < Entropy \n";
	cout << "" << Length << " < " << H << " + 1\n";

	delete Q;
	delete L;
}