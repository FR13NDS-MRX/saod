#pragma once
#include "struct.h"
#include "List.h"
#include <iostream>
#include <vector>

using namespace std;

struct Vertex {
    enterprise* enterprise = NULL;
    Vertex* left = NULL;
    Vertex* mid = NULL;
    Vertex* right = NULL;
    int weight = 0;
};

void Pyramid(vector<enterprise*>& vec, vector<int>& weightVec, int l, int r);
void PyramidSort(vector<enterprise*>& vec, vector<int>& weightVec, int n);

class Tree {
    Vertex* m_root;
    void add(enterprise* vec, int weight);
public:
    Tree(Queue<enterprise*>& sortData) {
        vector<enterprise*> vec(sortData.size());
        vector<int> vecWeight(sortData.size());
        vec.resize(0);
        vecWeight.resize(0);

        int i(0);

        while (!sortData.empty()) {
            vec.push_back(sortData.top());
            vecWeight.push_back(rand() % 10 + 1);
            sortData.pop();
        }

        PyramidSort(vec, vecWeight, vec.size() - 1);

        for (unsigned int i(0); i < vec.size(); i++) {
            add(vec[i], vecWeight[i]);
        }
    }

    void search(int D);
    void traversalLeft(Vertex* p);

    Vertex* getRoot() {
        return m_root;
    }

    Vertex*& getRootPtr() {
        return m_root;
    }

};

void workWithTree(Tree sortBase);