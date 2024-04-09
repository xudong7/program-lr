#include<bits/stdc++.h>
using namespace std;

class IntArray  {
    int *a; 
    int n;
public:
    IntArray(int n=1):n(n)  {
        a=new int[n];
        for (int i=0;i<n;++i) a[i]=i; 
    }
    ~IntArray() {
        cout << "release p=" << a <<endl;
        delete[] a;
    }
    IntArray& operator = (const IntArray& other)    {
        if (this != &other) {
            if(n != other.n)
            {
                delete[] a;  //这里a一定不为空 
                n = 0;
                a = nullptr;
                a = new int[other.n];
                n = other.n; 
            }
            for(int i=0;i<n;i++)
                a[i] = other.a[i];
            // memcpy(a, other.a, sizeof(int)*n);            
        } 
        return *this;
    }
    void print()    {
        for (int i=0;i<n;++i) cout<<a[i]<<" ";
        cout<<endl;
    }
};

int main()  {
    IntArray a(4), b;
    a.print();
    b=a; // 调用深拷贝策略赋值 
    b.print();
    a.print(); //a,b point to ...
    return 0;
}



