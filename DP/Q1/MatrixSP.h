#ifndef MATRIXSP_H
#define MATRIXSP_H
#include <iostream>
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

void MatrixSP::Solve(){
    path = new int[r+c-1];
    path[0] = m[0][0];
    int t=1;
    int i=1,j=1;
    while(!(i==r-1&&j==c-1)){
        if(m[i][j+1]<m[i+1][j]){
            path[t]=m[i][j+1];
            j++;
        }else{
            path[t]=m[i+1][j];
            i++;
        }
        t++;
    }
    path[r+c-2]=m[r-1][c-1];
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