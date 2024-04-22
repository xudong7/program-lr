# include<iostream>
using namespace std;

class C {
public:
    C( ); //构造函数
    ~C( ); //析构函数
};

class BASE {
public:
    BASE( ); // 构造函数
    ~BASE( ); // 析构函数
};


C::C( ) //构造函数
{ cout << "Constructing C object.\n"; }
C:: ~C( ) //析构函数
{ cout << "Destructing C object.\n"; }
BASE::BASE( ) // 构造函数
{ cout << "Constructing BASE object.\n"; }
BASE:: ~BASE( ) // 析构函数
{ cout << "Destructing BASE object.\n";}


class DERIVED: public BASE { // Derived.h
public:
    DERIVED(); // 构造函数
    ~DERIVED(); // 析构函数
private:
    C mOBJ;
};


DERIVED::DERIVED() // 构造函数
{ cout << "Constructing derived object.\n"; }
DERIVED:: ~DERIVED() // 析构函数
{ cout << "Destructing derived object.\n"; }


/*
构造顺序：
1.首先调用其基类的构造函数（多重继承：调用顺序按照基类被继承时的
声明顺序（从左向右））
2.然后调用本类对象成员的构造函数（调用顺序按照对象成员在类中的声
明顺序）
3.最后调用本类的构造函数
析构顺序：
与构造顺序相反
*/


int main()
{
    DERIVED obj; // 声明一个派生类的对象
    // 什么也不做，仅完成对象obj的构造与析构
    return 0;
}