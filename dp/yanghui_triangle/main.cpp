// https://leetcode-cn.com/problems/pascals-triangle/
# include<iostream>
# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> >ret(numRows);//定义一个二维数组用于存放结果
        //首先将第一列和最后一列元素全部赋值为1
        for(int i = 0; i < numRows; i++)
        {
            ret[i].resize(i+1);//resize()的作用就是为一维数组分配空间
            ret[i][0] = ret[i][i] = 1;
            //从第三行第二列开始有递推关系：ret[i][j] = ret[i+1][j]+ret[i+1][j+1];
            for(int j = 1; j < i; j++)
            {
                ret[i][j] = ret[i-1][j] + ret[i-1][j-1];
            }
        }
        return ret;
    }
};