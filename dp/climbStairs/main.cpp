// https://leetcode-cn.com/problems/climbing-stairs/
# include<iostream>
# include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int climbStairs(int n) {
        //方法一：暴力递归
        //找边界
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

class Solution2 {
public:
    int climbStairs(int n) {
        //方法二:记忆化搜索（简单DP）
        //找边界
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        //定义一个大小为n+1的整型数组，并且初始化为0
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i < n+1; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};


