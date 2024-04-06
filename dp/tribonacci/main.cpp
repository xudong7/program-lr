// https://leetcode-cn.com/problems/n-th-tribonacci-number/
# include<iostream>
# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        //找边界
        if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
        //定义一个大小为n+1的整形数组，并将其初始为0
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i < n+1;i++)
        {
            dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];//递推公式
        }
        return dp[n];
    }
 
};