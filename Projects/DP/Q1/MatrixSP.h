#ifndef MATRIXSP_H
#define MATRIXSP_H
#include <iostream>
#include <algorithm>
#include <vector>

class MatrixSP{
    public:
        int **m=nullptr;
        int r, c;
        int **dp;
        vector<vector<std::pair<int,int>>> pre;
        vector<std::pair<int,int>> path;
        MatrixSP(int **m_, int r_, int c_);
        void Solve();
        int GetMinSum();
        void ShowPath();
        void get_path(int x, int y);
};


MatrixSP::MatrixSP(int **m_, int r_, int c_){
    this->m = m_;
    this->r = r_;
    this->c = c_;
}



//一共经过r+c-1个点，共r+c-2条路径,其中最后一条一定是走到右下角，所以只需要控制r+c-3条路径
void MatrixSP::Solve(){
    dp = new int*[r];
    for(int i=0;i<r;i++){
        dp[i] = new int[c];
    }
    pre = vector<vector<std::pair<int,int>>>(r,vector<std::pair<int,int>>(c,std::pair<int,int>(0,0)));
    //先填充dp二维列表，得到从[0,0]到其余所有点的最短路径长度
    dp[0][0] = m[0][0];
    //第一行单独处理
    for(int i = 1; i < r ;i++){
        dp[0][i] = dp[0][i-1] + m[0][i];
        pre[0][i] = std::pair<int,int>(0,i-1);
    }
    //第一列单独处理
    for(int i = 1;i<c;i++){
        dp[i][0] = dp[i-1][0] + m[i][0];
        pre[i][0] = std::pair<int,int>(i-1,0);
    }
    //其余点
    for(int i =1;i<r;i++){
        for(int j =1;j<c;j++){
            dp[i][j] = std::min(dp[i][j-1],dp[i-1][j]) + m[i][j];
            if (dp[i][j-1] < dp[i-1][j])
            {
                pre[i][j] = std::pair<int,int>(i,j-1);
            }
            else{
                pre[i][j] = std::pair<int,int>(i-1,j);
            }
        }
    }
    //这时其实已经得到了终点（右下点的最短路径长度，但是不知道具体怎么过去的）

    //这时开始构建path
    get_path(r-1,c-1);
    
}


int MatrixSP::GetMinSum(){
    return dp[r-1][c-1];
}

void MatrixSP::ShowPath(){
    // for(int i = path.size()-1;i>=0;i--){
    //     cout<<"["<<path[i].first<<","<<path[i].second<<"]"<<endl;
    // }
    if(path.size() == 0){
        return;
    }
        
    for(int i = path.size()-1;i>=0;i--){
        int x = path[i].first;
        int y = path[i].second;
        std::cout<<m[x][y]<<" ";
        // std::cout<<x<<","<<y<<" "<<std::endl;
    }
}

void MatrixSP::get_path(int x,int y){
    path.push_back({x,y});
    if(x==0 && y==0){
        return;
    }
    int pre_x = pre[x][y].first;
    int pre_y = pre[x][y].second;
    get_path(pre_x,pre_y);
}
#endif