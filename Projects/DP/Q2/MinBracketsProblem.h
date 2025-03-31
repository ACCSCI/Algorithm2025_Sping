#ifndef MinBracketsProblem_H
#define MinBracketsProblem_H //--------------防止头文件被重复包含

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
class MinBracketsProblem
{
public:
    string str;
    int min;
    MinBracketsProblem(string str) : str(str) {} // 构造函数，初始化括号序列
    bool isMatching(char left, char right);//检测两个字符是否匹配
    int minInsertionsToMakeValid(string s);//最少括号添加数
    int GetMinBrackets() const { return min; } // 返回需要添加的最少的括号数目
    void Solve();                              // 使用动态规划方法计算需要添加的最少的括号数目
    void Print();
};

bool MinBracketsProblem::isMatching(char left, char right)
{
    return (left == '(' and right == ')') or
           (left == '[' and right == ']') or
           (left == '{' and right == '}');
}

int MinBracketsProblem::minInsertionsToMakeValid(string s){
    int n = s.length();
    if (n==0)return 0;
    //dp[i][j]表示使s[i...j]变成合法括号序列所需的最少括号数
    vector<vector<int>> dp(n,vector<int>(n,0));

    //处理单字符情况
    for(int i =0;i<n;i++){
        dp[i][i] =1;//单个字符至少需要一个括号
    }

    //逐步增加区间长度
    for(int len =2;len<=n;len++){
        for(int i =0;i+len-1<n;i++){
            int j = i + len -1;
            dp[i][j] = 99999;

            //如果i和j可以匹配
            if(isMatching(s[i],s[j])){
                dp[i][j] = dp[i+1][j-1];//直接继承内部区间
            }

            //尝试拆分两个子区间
            for(int k = i;k<j;k++){
                dp[i][j]=std::min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }
    return dp[0][n-1];
}
void MinBracketsProblem::Print()
{
    std::cout << str << std::endl;
}
void MinBracketsProblem::Solve()
{
    // Print();
    int ans = 0;
    ans = minInsertionsToMakeValid(str);
    min = ans;
}



#endif