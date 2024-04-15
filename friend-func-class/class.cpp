# include<iostream>
# include<bits/stdc++.h>
using namespace std;

class Integer;

class Cmp
{
public:
    bool operator()(const Integer& a, const Integer& b);
    // bool operator()(const Integer& a, const Integer& b);
};


class Integer {
    int x;
public:
    friend Cmp;
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


bool Cmp::operator()(const Integer& a, const Integer& b)
{
    return a.x < b.x;
}


void test1()
{
    Integer a=3,b,c;
    Cmp temp;
    // ������Ԫ��
    bool ret = temp(a, 1);
    cout << ret << endl;
}

int main() {
    
    test1();
    return 0;
}