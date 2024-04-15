# include<iostream>
# include<bits/stdc++.h>
using namespace std;

struct Cmp
{
    bool operator()(const Integer& a, const Integer& b);
};


class Integer {
    int x;
public:
    Integer(int x=0):x(x) {}
    Integer operator- (const Integer& Int) 
    {
        return Integer(x-Int.x);
    }
    Integer operator - () 
    {
        return Integer(-x);
    }
    // ������Ԫ����
    friend Integer operator+(const Integer& lhs,const Integer& rhs);
    // ������Ԫ����
    friend bool Cmp::operator()(const Integer& a, const Integer& b);
    void print() 
    {
        cout<<x<<endl;
    }
};

// ��Ԫ��������������(����friend) ���ⶨ��
Integer operator+(const Integer& lhs,const Integer& 
rhs) { 
    return Integer(lhs.x+rhs.x);
}

// ������Ԫ����ʵ��
bool Cmp::operator()(const Integer& a, const Integer& b)
{
    return a.x < b.x;
}

void test1()
{
    Integer a=3,b,c;
    //����1������������ֵ��䣬��Щ����������
    b = a + 4;
    c = 5 + a;
    b.print();
    c.print(); 
    //����2���� struct �ؼ��ָ�Ϊ class 
}

int main() {
    
    test1();
    return 0;
}