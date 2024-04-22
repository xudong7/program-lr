# include<iostream>
using namespace std;

class C {
public:
    C( ); //���캯��
    ~C( ); //��������
};

class BASE {
public:
    BASE( ); // ���캯��
    ~BASE( ); // ��������
};


C::C( ) //���캯��
{ cout << "Constructing C object.\n"; }
C:: ~C( ) //��������
{ cout << "Destructing C object.\n"; }
BASE::BASE( ) // ���캯��
{ cout << "Constructing BASE object.\n"; }
BASE:: ~BASE( ) // ��������
{ cout << "Destructing BASE object.\n";}


class DERIVED: public BASE { // Derived.h
public:
    DERIVED(); // ���캯��
    ~DERIVED(); // ��������
private:
    C mOBJ;
};


DERIVED::DERIVED() // ���캯��
{ cout << "Constructing derived object.\n"; }
DERIVED:: ~DERIVED() // ��������
{ cout << "Destructing derived object.\n"; }


/*
����˳��
1.���ȵ��������Ĺ��캯�������ؼ̳У�����˳���ջ��౻�̳�ʱ��
����˳�򣨴������ң���
2.Ȼ����ñ�������Ա�Ĺ��캯��������˳���ն����Ա�����е���
��˳��
3.�����ñ���Ĺ��캯��
����˳��
�빹��˳���෴
*/


int main()
{
    DERIVED obj; // ����һ��������Ķ���
    // ʲôҲ����������ɶ���obj�Ĺ���������
    return 0;
}