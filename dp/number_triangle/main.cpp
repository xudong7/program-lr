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
    //����func[i][j]��ʾ���Ǵ�i, j�����һ������·��֮��
    //�ҳ����ƹ�ϵ��func[i][j]+=max(func[i+1][j],func[i+1][j+1]);
    //func[i][j]��ʾ��ǰ���ֵ�ֵ��func[i+1][j]��func[i+1][j+1]�ֱ��ʾ��i+1,j��i+1,j+1�����һ������·��֮��
    //����func[0][0]��������
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