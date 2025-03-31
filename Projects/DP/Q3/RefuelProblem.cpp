#include "RefuelProblem.h"
#include <iostream>

// 构造函数
RefuelProblem::RefuelProblem(int m, int n, int* d) {
    this->m = m;
    this->n = n;
    this->d = new int[n];
    for (int i = 0; i < n; i++) {
        this->d[i] = d[i];
    }
    minValue = 0;
    solution = nullptr;
}

// 析构函数
RefuelProblem::~RefuelProblem() {
    delete[] d;
    if (solution != nullptr) {
        delete[] solution;
    }
}

// 贪心法求解最少加油次数
bool RefuelProblem::Solve() {
    int currentDistance = 0; // 当前剩余油量可行驶的距离
    int* tempSolution = new int[n];
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (d[i] > m) {
            // 如果某两个加油站之间的距离大于汽车加满油可行驶的距离，无解
            delete[] tempSolution;
            return false;
        }
        currentDistance += d[i];
        if (currentDistance > m) {
            // 需要加油
            tempSolution[count++] = i - 1;
            currentDistance = d[i];
        }
    }

    minValue = count;
    solution = new int[minValue];
    for (int i = 0; i < minValue; i++) {
        solution[i] = tempSolution[i];
    }
    delete[] tempSolution;
    return true;
}

// 返回停靠的加油站编号
int* RefuelProblem::GetSolution() {
    return solution;
}

// 返回最少加油次数
int RefuelProblem::GetMinValue() {
    return minValue;
}    