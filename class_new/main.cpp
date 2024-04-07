# include<iostream>
# include<bits/stdc++.h>
using namespace std;

class Student
{
private:
    int data;
public:
    Student()
    {
        data = 0;
        cout << "default" << endl;
    }
    Student(int n) : data(n)
    {
        cout << "value" << endl;
    }
    Student(const Student& other) : data(other.data)
    {
        cout << "copy" << endl;
    }
    ~Student()
    {
        cout << "~Student(): " <<  endl;
    }
};

Student& func(Student& a)
{
    return a;
}

void func2(Student a)
{
    // 传入类对象 则函数结束立刻析构
    cout << "func2" << endl;
}

Student func3()
{
    // 返回类对象 之前是立刻析构 由于编译优化 现在会在main函数结束后才析构
    Student c(2);
    return c;
}

Student func4(Student a)
{
    // 传入类对象 则函数结束立刻析构
    cout << "func4" << endl;
    return a;
}


int main()
{
    Student s(20);
    Student ret(func(s));
    func2(s);
    Student obj(func3());
    Student new_obj(func4(s));
    cout << "end" << endl;
    return 0;
}