#include "BSearch.h"
#include "List.h"
#include <Windows.h>

using namespace std;
int compare(const char* a, const char* b, int keySize) {
	for (int i = 6; i < 2 + 6; i++) {
		if (a[i] > b[i - 6]) return 1;
		else if (a[i] < b[i - 6]) return -1;
	}

	return 0;
}

void BSearch(enterprise** Q, const char* x, int L, int R, int keySize, Queue<enterprise*>& data) {
	int m;
	int size(R + 1);

	while (L < R) {
		m = (L + R) / 2;

		if (compare(Q[m]->date, x, keySize) == -1) {
			L = m + 1;
		}
		else R = m;
	}

	cout << "\nРезультат \n";

	while (compare(Q[R]->date, x, keySize) == 0) {
		data.push(Q[R]);
		R++;
		if (R == size)
			break;
	}
}