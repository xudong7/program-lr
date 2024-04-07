// https://leetcode-cn.com/problems/pascals-triangle/
# include<iostream>
# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> >ret(numRows);//����һ����ά�������ڴ�Ž��
        //���Ƚ���һ�к����һ��Ԫ��ȫ����ֵΪ1
        for(int i = 0; i < numRows; i++)
        {
            ret[i].resize(i+1);//resize()�����þ���Ϊһά�������ռ�
            ret[i][0] = ret[i][i] = 1;
            //�ӵ����еڶ��п�ʼ�е��ƹ�ϵ��ret[i][j] = ret[i+1][j]+ret[i+1][j+1];
            for(int j = 1; j < i; j++)
            {
                ret[i][j] = ret[i-1][j] + ret[i-1][j-1];
            }
        }
        return ret;
    }
};