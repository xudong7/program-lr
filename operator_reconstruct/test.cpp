# include<iostream>
# include<bits/stdc++.h>
using namespace std;

class Student
{
private:
    int *a;
    int n;
public:
    Student(int n = 1) : n(n)
    {
        a = new int[n];
    }
    Student(const Student& other) : n(other.n)
    {
        if(this != &other)
        {
            a = new int[n];
            for(int i=0;i<n;i++)
                a[i] = other.a[i];
        }
    }
    ~Student(){}
    int& operator[](int i)
    {
        if(i >= 0 && i < n)
            return a[i];
        throw out_of_range("out of range");
    }
    const int& operator[](int i) const
    {
        if(i >= 0 && i < n)
            return a[i];
        throw out_of_range("out of range");
    }
    void Print() const
    {
        cout << "n: " << n << endl;
        for(int i=0;i<n;i++)
            // cout << (*this)[i] << " ";
            cout << a[i] << " ";
        cout << endl;
    }
};


void test1()
{
    cout << "----test1 begin----" << endl;
    Student a(4);
    for (int i=0;i<4;i++) a[i]=i+1;
    a.Print();
    //任务1：以下两个语句，b的哪些成员函数被调用
    const Student b=a;
    cout << "b[0] = " << b[0] <<endl;
    //任务2：Print函数去除 const会如何？
    //有const后缀才能访问const变量
    b.Print();
    //任务3:以下语句错误性质一样吗？
    // const函数 不可修改
    // b[5]=10;
    // out of range
    // a[5]=10;
    cout << "----test1 end----" << endl;
}

class GreaterThan {
    int baseline;
public:
    GreaterThan(int x):baseline(x) {}
    bool operator () (const int& x) {
        return x>baseline;
    }
};
bool GreaterThan10(const int& x) {
    return x>10;
}
bool GreaterThan20(const int& x) {
    return x>20;
}


struct Integer {
    int x;
public:
    Integer(int x=0):x(x) {}
    Integer operator- (const Integer& Int) {
        return Integer(x-Int.x);
    }
    Integer operator - () {
        return Integer(-x);
    }
    // Integer operator+(const Integer& lhs)
    // {
    //     return Integer(x + lhs.x);
    // }
    void print() {
        cout<<x<<endl;
    }
    friend ostream& operator<<(ostream& o, const Integer &hs) {
        o << "const " << hs.x;
        return o;
    } 
    friend ostream& operator<<(ostream& o, Integer &hs) {
        o << "no_const " << hs.x ;
        return o;
    }
    int getX() const
    {
        return x;
    }
};

// 左操作数不是类对象 需要类外定义
Integer operator+(const Integer& lhs,const Integer& 
rhs) { 
    // 当为class且在类外定义时 若想访问private 需要调用public函数得到
    // lhs.getX()+rhs.getX()
    // 若想真正直接得到private 需要使用friend
    return Integer(lhs.x + rhs.x);
}


void test2()
{
    cout << "----test2 begin----" << endl;
    vector<int> a={5,10,15,20,25};
    // find_id return a iterator
    cout<<*find_if(a.begin(),a.end(),GreaterThan(10))<<endl;
    cout<<*find_if(a.begin(),a.end(),GreaterThan(20))<<endl;
    cout<<*find_if(a.begin(),a.end(),GreaterThan10)<<endl;
    cout<<*find_if(a.begin(),a.end(),GreaterThan20)<<endl;
    cout << "----test2 end----" << endl;
}

void test3()
{
    cout << "----test3 begin----" << endl;
    Integer a=3,b,c;
    //任务1：解释两个赋值语句，哪些函数被调用
    b = a + 4;
    // 左操作数不是类对象 需要类外定义
    c = 5 + a;
    b.print();
    c.print(); 
    //任务2：将 struct 关键字改为 class
    cout << "----test3 end----" << endl;
}

void test4()
{
    Integer i1(1);
    const Integer i2(2);
    cout << i1 << "," << 3 << "," << i2 << endl;
}

int main()
{

    // test1();
    // test2();
    // test3();
    test4();

    return 0;
}