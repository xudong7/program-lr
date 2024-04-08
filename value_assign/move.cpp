# include<iostream>
# include<bits/stdc++.h>
using namespace std;

class IntArray {
    int *a; // 指针 深拷贝
    int n;
public:
    IntArray(int n=1):n(n) {
        cout << "constructing.. p=";
        a=new int[n];
        for (int i=0;i<n;++i) a[i]=i; 
        cout << a <<endl;
    }
    IntArray(IntArray&& other) { //移动构造
        cout << "copy move... p=" << other.a <<endl;
        // no need to use 'new'
        // point change just ok
        a = other.a;n = other.n;
        // old obj nothing 
        other.a = nullptr; other.n=0;
    }
    ~IntArray() {
        cout << "release p=" << a <<endl;
        // if not empty -> delete
        if (a) delete[] a;
    }
    IntArray& operator = (IntArray&& other) {//移动赋值
        cout << "operator = move p=" << other.a <<endl;
        if (this != &other) {
            // if not empty -> delete to init
            if (other.a) delete[] a;
            // same as move constructor
            a = other.a;n = other.n;
            other.a = nullptr; other.n=0; 
        } 
        return *this;
    }
    IntArray& inc() {
        for (int i=0;i<n;++i) a[i]++;
        return *this;
    }
    void print() {
        for (int i=0;i<n;++i) cout<<a[i]<<" ";
        cout<<endl;
    }
};


IntArray foo(IntArray a) {
    a.inc();
    a.inc();
    return a;
}
IntArray bar() {
    IntArray a(8);
    a.inc();
    return a;
}

int main() {
    IntArray a(4), b, c;
    a.print();
    b=std::move(a); //a看作右值，调用移动赋值
    a.print(); //a nothing
    b.print();
    cout<< "1-----"<<endl;
    c = foo(std::move(b));
    a.print();// a nothing
    b.print();// b nothing
    c.print();
    cout<< "2-----"<<endl; 
    IntArray d; //d=bar(); //会更高效！
    d=std::move(bar());
    d.print();
    cout<< "3-----"<<endl;
    return 0;
}