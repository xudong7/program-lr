// https://leetcode.cn/problems/counting-bits/description/
# include<iostream>
# include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /* data */
public:
    int func(int n)
    {
        // sum -> 操作次数
        int sum = 0;
        while(n > 0)
        {
            // 以下操作: 每次将最高位的1置0
            // 当n==0时，次数sum即为二进制数中1的数量
            n &= (n - 1);
            sum++;
        }
        return sum;
    }

    vector<int> countBits_1(int n)
    {
        vector<int> ret(n + 1);
        for(int i=0;i<n+1;i++)
            ret[i] = func(i);
        return ret;
    }

    vector<int> countBits_2(int n)
    {
        vector<int> ret(n + 1);
        // highbit为进位数(该数的1的数量为1)
        // 如0010 0100 1000...
        int highbit = 0;
        for(int i=1;i<n+1;i++)
        {
            if((i & (i-1)) == 0)
            {
                highbit = i;
            }
            // 每次碰到highbit重新循环
            ret[i] = ret[i - highbit] + 1;
        }
        
        return ret;
    }
    
    vector<int> countBits_2(int n)
    {
        // 使用cpp库中的函数__builtin_popcount(unsigned int n)返回n二进制形式中1的数量
        vector<int> ret(n + 1);
        for(int i=0;i<n+1;i++)
            ret[i] = __builtin_popcount(i);
        return ret;
    }
};


