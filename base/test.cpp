# include<iostream>

using namespace std;

class BASE
{
public: 
    BASE();
    void get_ij();
protected:
    int i, j;
private:
    int x_temp;
};

//������������Y1���У�i��j���ܱ�����Ա
class Y1:public BASE
{
public: 
    void increment(); //get_ij()�ǹ��г�Ա��x_temp���ɷ���
private:
    float nmember;
};

BASE::BASE()
{ 
    i=0; j=0; x_temp=0; 
    
}

void BASE:: get_ij()
{
    cout << i << " " << 
    j << endl;
}

void Y1::increment()
{
    i++; j++;
}

int main() //����Access
{
    BASE obj1;
    Y1 obj2;
    obj2.increment();
    obj2.get_ij();
    obj1.get_ij();
}
