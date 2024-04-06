// https://leetcode-cn.com/problems/fibonacci-number/
# include<iostream>
# include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int fib(int n){
        //方法一：暴力递归
        //找边界
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        return fib(n - 1) + fib(n - 2);
    }
};

class Solution2 {
public:
    int fib(int n){
        class Solution {
public:
    int fib(int n){
        //方法二：记忆化搜索（简单DP）
        //找边界
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        //需要定义一个大小为(n+1)的整形数组，并且初始化为0
        //之所以是n+1,是因为要使用到n这个下标
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i < n+1; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
    }
};