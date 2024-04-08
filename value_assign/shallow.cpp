# include<iostream>
# include<bits/stdc++.h>
using namespace std;

class IntArray {
    int *a; 
    int n;
public:
    IntArray(int n=1):n(n) {
        a=new int[n];
        for (int i=0;i<n;++i) a[i]=i; 
    }
    ~IntArray() {
        cout << "release p=" << a <<endl;
        delete[] a;
    }
    void print() {
        for (int i=0;i<n;++i) 
            cout<<a[i]<<" ";
            cout<<endl;
    }
};

void test1()
{
    IntArray a(4), b;
    a.print();
    b=a; // default operator = is ok, but ... 
    b.print();
    a.print(); //a,b point to the same object
    // 1.内存泄漏
    // 2. b，a先后析构，资源二次释放
    // 内存段错误
}

int main() {
    test1();
    
    return 0;
}
