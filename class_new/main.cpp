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
    // ��������� ����������������
    cout << "func2" << endl;
}

Student func3()
{
    // ��������� ֮ǰ���������� ���ڱ����Ż� ���ڻ���main���������������
    Student c(2);
    return c;
}

Student func4(Student a)
{
    // ��������� ����������������
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