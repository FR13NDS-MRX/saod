#include "Coding.h"
#include "Tree.h"
#include "BSearch.h"
#include "List.h"
#include <iostream>
#include "struct.h"
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <Windows.h>

using namespace std;

void AddingData(enterprise* base[]) {
	ifstream binFile("testBase2.dat", ios::binary);

	for (int i = 0; i < 4000; ++i) {
		base[i] = new enterprise;
		binFile.read((char*)base[i], sizeof(enterprise));
	}

	binFile.close();
}

void PrintingBase(enterprise* base[]) {
	SetConsoleOutputCP(866);
	int key;
	int k = 0;
	puts("press \n      '1' to print 20 lines\n      '2' to print all list");
	int a;
	scanf_s("%d", &a);

	if (a == 1) {
		do
		{
			for (int i = 0; i < 20; i++)
			{
				printf(" %-6i %s %3i %s %s\n", k + 1, base[k]->fio, base[k]->number, base[k]->position, base[k]->date);
				k++;
			}
			puts("\npress ""0"" to stop printing or any button to continue then press ENTER");
			scanf_s("%d", &key);
			if (key == 0)
				break;
		} while (1);
	}
	else if (a == 2) {
		for (int i = 0; i < 4000; i++) {
			printf(" %-6i %s %3i %s %s\n", k + 1, base[k]->fio, base[k]->number, base[k]->position, base[k]->date);
			k++;
		}
	}

	SetConsoleOutputCP(1251);
}

int Less(enterprise* X, enterprise* Y) {
	int KDI[6] = { 6, 7, 3, 4, 0, 1 };

	for (int i = 0; i < 6; i++) {
		if (X->date[KDI[i]] < Y->date[KDI[i]]) {
			return 0;
		}

		if (X->date[KDI[i]] > Y->date[KDI[i]]) {
			return 1;
		}
	}

	return 2;
}

void QuickSort(enterprise* a[], int L, int R) {
	int i, j;
	enterprise* x;
	x = a[(R + L) / 2];

	i = L;
	j = R;

	while (i < j) {
		while (Less(a[i], x) == 0) {
			i++;
		}
		while (Less(a[j], x) == 1) {
			j--;
		}
		if (i <= j) {
			enterprise* temp;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}

	if (L < j) QuickSort(a, L, j);
	if (i < R) QuickSort(a, i, R);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int size(4000);
	enterprise* base[size];
	AddingData(base);
	QuickSort(base, 0, size - 1);
	PrintingBase(base);

	Queue<enterprise*> sortData;
	string year("");

	while (year.size() != 2) {
		cout << "Введите ключ, год рождения: ";
		cin >> year;
	}

	BSearch(base, year.c_str(), 0, size - 1, year.size(), sortData);

	Tree sortBase(sortData);
	workWithTree(sortBase);

	for (int i = 0; i < 4000; i++) {
		delete base[i];
	}

	Shannon();

	return 0;
}