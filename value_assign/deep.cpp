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
    IntArray& operator = (const IntArray& other) {
        if (this != &other) {
            delete[] a; //����aһ��Ҫ��Ϊ��
            n=other.n;
            a=new int[n];
            for(int i=0;i<other.n;i++) a[i] = other.a[i];
            // memcpy(a,other.a,sizeof(int)*n); 
        } 
        return *this;
    }
    void print() {
        for (int i=0;i<n;++i) cout<<a[i]<<" ";
        cout<<endl;
    }
};

void test1()
{
    IntArray a(4), b;
    a.print();
    b=a; // ����������Ը�ֵ
    b.print();
    a.print(); //a,b point to ...
    // 1.b����Դ���ͷ�
    // ��ָ��a��Դ�ĸ���
    // 2.b��a�����ͷ���Դ
}

int main() {
    test1();

    return 0;
}

