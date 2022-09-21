#include "Tree.h"
#include "struct.h"
#include <Windows.h>
#include <vector>

using namespace std;

void Tree::add(enterprise* D, int weight) {
	Vertex** p = &m_root;

	while (*p != nullptr) {
		if (D->number < (*p)->enterprise->number) {
			p = &((*p)->left);
		}
		else if (D->number > (*p)->enterprise->number) {
			p = &((*p)->right);
		}
		else {
			p = &((*p)->mid);
		}
	}

	if (*p == nullptr) {
		(*p) = new Vertex;
		(*p)->enterprise = D;
		(*p)->weight = weight;
	}
}

void Tree::search(int D) {
	Vertex** p = &m_root;
	cout << "\nРезультат: \n";
	SetConsoleOutputCP(866);

	while (*p != nullptr) {
		if (D < (*p)->enterprise->number) {
			p = &((*p)->left);
		}
		else if (D > (*p)->enterprise->number) {
			p = &((*p)->right);
		}
		else {
			cout << "\t" << (*p)->enterprise->fio << "\t" << (*p)->enterprise->number << "\t" << (*p)->enterprise->position << "\t" << (*p)->enterprise->date << "\n";
			p = &((*p)->mid);
		}
	}

	SetConsoleOutputCP(1251);
}

void Tree::traversalLeft(Vertex* p) {
	static int count = 1;

	if (p != nullptr) {
		traversalLeft(p->left);
		traversalLeft(p->mid);

		cout << count << ")\t" << p->enterprise->fio << "\t" << p->enterprise->number << "\t" << p->enterprise->position << "\t" << p->enterprise->date << "\n";
		count++;
		traversalLeft(p->right);
	}
}

void QuickSort(vector<enterprise*>& vec, vector<int>& weightVec, int L, int R) {
	int a = vec[L]->number, i = L, j = R, t;
	enterprise* vecTemp;

	while (i <= j) {
		while (vec[i]->number < a)i++;
		while (vec[j]->number > a)j--;

		if (i <= j) {
			vecTemp = vec[i];
			vec[i] = vec[j];
			vec[j] = vecTemp;
			t = weightVec[i];
			weightVec[i] = weightVec[j];
			weightVec[j] = t;

			i++;
			j--;
		}
	}

	if (L < j) QuickSort(vec, weightVec, L, j);
	if (i < R) QuickSort(vec, weightVec, i, R);
}

void Pyramid(vector<enterprise*>& vec, vector<int>& weightVec, int l, int r) {
	int i = l, j, temp;
	enterprise* t;
	t = vec[l];
	temp = weightVec[l];

	for (;;) {
		j = 2 * i;
		if (j > r) break;
		if (j < r&& vec[j]->number <= vec[j + 1]->number)j++;
		if (t->number >= vec[j]->number) break;

		weightVec[i] = weightVec[j];
		i = j;
	}

	weightVec[i] = temp;
}

void PyramidSort(vector<enterprise*>& vec, vector<int>& weightVec, int n) {
	int r = n, l, temp;
	enterprise* t;
	for (l = n / 2; l > 0; l--)Pyramid(vec, weightVec, l, n);

	while (r > 1) {
		t = vec[1];
		vec[1] = vec[r];
		vec[r] = t;
		temp = weightVec[1];
		weightVec[1] = weightVec[r];
		weightVec[r] = temp;
		r--;
		Pyramid(vec, weightVec, 1, r);
	}
}

void workWithTree(Tree sortBase) {
	SetConsoleOutputCP(866);
	sortBase.traversalLeft(sortBase.getRoot());
	SetConsoleOutputCP(1251);
	cout << "\n";

	int key;
	while (1) {
		cout << "Введите ключи (номер отдела) (число от 0 до 240, шаг 10): ";

		cin >> key;

		if (cin.fail()) {
			cin.clear();
			continue;
		}

		if (cin.gcount() > 1) {
			continue;
		}

		if (key < 0) {
			continue;
		}

		break;
	}

	sortBase.search(key);
}