# include<iostream>
# include<bits/stdc++.h>
using namespace std;

class A
{
private:
    int data;
public:
    // 缺省构造
    A() = default;
    A(int n) : data(n)
    {
        cout << "value!" << endl;
    }
    A(const A& other) : data(other.data)
    {
        cout << "copy!" << endl;
    }
    // 无参数 -> 对本身操作
    A operator-()
    {
        cout << "self - used!" << endl;
        // 返回副本
        return A(-data);
    }
    A operator+()
    {
        cout << "self + used!" << endl;
        // 返回副本
        return A(+data);
    }
    // 有参数 other为右操作数
    A operator-(const A& other)
    {
        cout << "obj - used!" << endl;
        return A(data-other.data);
    }
    A operator+(const A& other)
    {
        cout << "obj + used!" << endl;
        return A(data+other.data);
    }
    // 后置递增
    A operator++(int)
    {
        cout << "++ pos!" << endl;
        A temp(*this);
        ++data;
        // 不返回引用
        // 因为先返回后递增
        return temp;
    }
    // 前置递增
    A& operator++()
    {
        // 返回引用 便于链式调用 同时节省内存
        cout << "++ pre!" << endl;
        ++data;
        return *this;
    }
    // 赋值
    A& operator=(const A& other)
    {
        // if not return A&
        // we still need to update parameter like this:
        // data = other.data;
        if(this != &other)
        {
            cout << "= used!" << endl;
            data = other.data;
        }
        return *this;
    }
    // 运算赋值
    A& operator+=(const A& other)
    {
        if(other.data != 0)
        {
            cout << "+= used!" << endl;
            // 两者方法
            // 第一种方法：
            // 模块化 但是内存占用
            // 1. *this = this->+(other);
            // 以下方法：快速 但是如果+=不能运用在成员上则不方便
            data += other.data;
        }
        return *this;
    }
    void show()
    {
        cout << "show!" << endl;
        cout << data << endl;
    }
    int get()
    {
        return data;
    }
    ~A()
    {
        cout << "destroy!" << endl;
    }
};

void test1()
{
    cout << "\'+\'and\'-\':" << endl;
    A a(10);
    cout << "a: "; 
    a.show();
    A b(a);
    cout << "b: ";
    b.show();
    A c(20);
    cout << "c: ";
    c.show();
    A d(30);
    cout << "d: ";
    d.show();
    d = -a;
    cout << "d: ";
    d.show();
}

void test2()
{
    cout << "pre add and post add:" << endl;
    A a(10);
    cout << "a: ";
    a.show();
    A b = ++a;
    cout << "b: ";
    b.show();
    cout << "a: ";
    a.show();
    A c = a++;
    cout << "c: ";
    c.show();
    cout << "a: ";
    a.show();
}

void test3()
{
    cout << "= operator:" << endl;
    A a(20);
    A b;
    a.show();
    b = a;
    a.show();
    b.show();
}

void test4()
{
    cout << "+= operator:" << endl;
    A a=3, b;
    // 5先default构造形参类
    // 然后=重载赋值b
    b=5;
    b=a;
    b+=b;
}

int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    return 0;
}