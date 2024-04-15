# include<iostream>
# include<bits/stdc++.h>
using namespace std;

class A
{
private:
    int data;
public:
    // ȱʡ����
    A() = default;
    A(int n) : data(n)
    {
        cout << "value!" << endl;
    }
    A(const A& other) : data(other.data)
    {
        cout << "copy!" << endl;
    }
    // �޲��� -> �Ա������
    A operator-()
    {
        cout << "self - used!" << endl;
        // ���ظ���
        return A(-data);
    }
    A operator+()
    {
        cout << "self + used!" << endl;
        // ���ظ���
        return A(+data);
    }
    // �в��� otherΪ�Ҳ�����
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
    // ���õ���
    A operator++(int)
    {
        cout << "++ pos!" << endl;
        A temp(*this);
        ++data;
        // ����������
        // ��Ϊ�ȷ��غ����
        return temp;
    }
    // ǰ�õ���
    A& operator++()
    {
        // �������� ������ʽ���� ͬʱ��ʡ�ڴ�
        cout << "++ pre!" << endl;
        ++data;
        return *this;
    }
    // ��ֵ
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
    // ���㸳ֵ
    A& operator+=(const A& other)
    {
        if(other.data != 0)
        {
            cout << "+= used!" << endl;
            // ���߷���
            // ��һ�ַ�����
            // ģ�黯 �����ڴ�ռ��
            // 1. *this = this->+(other);
            // ���·��������� �������+=���������ڳ�Ա���򲻷���
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
    // 5��default�����β���
    // Ȼ��=���ظ�ֵb
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