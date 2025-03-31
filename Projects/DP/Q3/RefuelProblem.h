#ifndef REFUELPROBLEM_H
#define REFUELPROBLEM_H

class RefuelProblem {
private:
    int m;  // 汽车加满油可以行驶的里程
    int n;  // 加油站的数目
    int* d; // 各加油站之间的距离
    int minValue; // 最少加油次数
    int* solution; // 停靠的加油站编号

public:
    RefuelProblem(int m, int n, int* d);
    ~RefuelProblem();
    bool Solve();
    int* GetSolution();
    int GetMinValue();
};

#endif