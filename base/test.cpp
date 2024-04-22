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

//公有派生：在Y1类中，i、j是受保护成员
class Y1:public BASE
{
public: 
    void increment(); //get_ij()是公有成员，x_temp不可访问
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

int main() //程序Access
{
    BASE obj1;
    Y1 obj2;
    obj2.increment();
    obj2.get_ij();
    obj1.get_ij();
}
