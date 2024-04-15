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
    // 本类友元函数
    friend Integer operator+(const Integer& lhs,const Integer& rhs);
    // 他类友元函数
    friend bool Cmp::operator()(const Integer& a, const Integer& b);
    void print() 
    {
        cout<<x<<endl;
    }
};

// 友元函数在类内声明(声明friend) 类外定义
Integer operator+(const Integer& lhs,const Integer& 
rhs) { 
    return Integer(lhs.x+rhs.x);
}

// 他类友元函数实现
bool Cmp::operator()(const Integer& a, const Integer& b)
{
    return a.x < b.x;
}

void test1()
{
    Integer a=3,b,c;
    //任务1：解释两个赋值语句，哪些函数被调用
    b = a + 4;
    c = 5 + a;
    b.print();
    c.print(); 
    //任务2：将 struct 关键字改为 class 
}

int main() {
    
    test1();
    return 0;
}