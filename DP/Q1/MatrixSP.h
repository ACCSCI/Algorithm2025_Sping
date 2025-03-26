#ifndef MATRIXSP_H
#define MATRIXSP_H
#include <iostream>
#include <algorithm>
class MatrixSP{
    public:
        int **m=nullptr;
        int r, c;
        int *path=nullptr;
        MatrixSP(int **m, int r, int c);
        void Solve();
        int GetMinSum();
        void ShowPath();
};

MatrixSP::MatrixSP(int **m, int r, int c){
    this->m = m;
    this->r = r;
    this->c = c;
}


//一共经过r+c-1个点，共r+c-2条路径,其中最后一条一定是走到右下角，所以只需要控制r+c-3条路径
void MatrixSP::Solve(){
    path = new int[r+c-1];
    int **dp = new int*[r];
    for(int i=0;i<c;i++){
        dp[i] = new int[c];
    }
    path[0] = m[0][0];
    //先填充dp二维列表，得到从[0,0]到其余所有点的最短路径长度
    dp[0][0] = m[0][0];
    //第一行
    for(int i = 1; i <= r-1 ;i++){
        dp[0][i] = dp[0][i-1] + m[0][i];
    }
    //第一列
    for(int i = 1;i<c-1;i++){
        dp[i][0] = dp[i][0] + m[i][0];
    }
    for(int i =1;i<r-1;i++){
        for(int j =1;j<c-1;j++){
            dp[i][j] = std::min(dp[i][j-1],dp[i-1][j]);
        }
    }
    //这时其实已经得到了终点（右下点的最短路径长度，但是不知道具体怎么过去的）
    //这时从头
    
}

int MatrixSP::GetMinSum(){
    int sum=0;
    for(int i =0;i<r+c-1;i++){
        sum+=path[i];
    }
    return sum;
}

void MatrixSP::ShowPath(){
    for(int i =0;i<r+c-1;i++){
        std::cout<<path[i]<<" ";
    }
    std::cout<<std::endl;
}



#endif