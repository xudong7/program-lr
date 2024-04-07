// https://www.luogu.com.cn/problem/P1216
#include<stdio.h>
#include<algorithm>
using namespace std;
 
int func[1005][1005] = {0};
 
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int j = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j <= i; j++)
        {
            scanf("%d", &func[i][j]);
        }
    }
    //假设func[i][j]表示的是从i, j到最后一层的最大路径之和
    //找出递推关系：func[i][j]+=max(func[i+1][j],func[i+1][j+1]);
    //func[i][j]表示当前数字的值，func[i+1][j]和func[i+1][j+1]分别表示从i+1,j、i+1,j+1到最后一层的最大路径之和
    //最终func[0][0]就是所求
    for(i = n - 2; i >= 0; i--)
    {
        for(j = 0; j <= i; j++)
        {
            func[i][j] += max(func[i+1][j], func[i+1][j+1]);
        }
    }
    printf("%d\n", func[0][0]);
    return 0;
}