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
        // sum -> ��������
        int sum = 0;
        while(n > 0)
        {
            // ���²���: ÿ�ν����λ��1��0
            // ��n==0ʱ������sum��Ϊ����������1������
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
        // highbitΪ��λ��(������1������Ϊ1)
        // ��0010 0100 1000...
        int highbit = 0;
        for(int i=1;i<n+1;i++)
        {
            if((i & (i-1)) == 0)
            {
                highbit = i;
            }
            // ÿ������highbit����ѭ��
            ret[i] = ret[i - highbit] + 1;
        }
        
        return ret;
    }
    
    vector<int> countBits_2(int n)
    {
        // ʹ��cpp���еĺ���__builtin_popcount(unsigned int n)����n��������ʽ��1������
        vector<int> ret(n + 1);
        for(int i=0;i<n+1;i++)
            ret[i] = __builtin_popcount(i);
        return ret;
    }
};


