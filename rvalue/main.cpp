// https://www.youtube.com/watch?v=OWNeCTd7yQE

# include<iostream>
# include<cstring>

using namespace std;

class String
{
private:
    char* m_name;
    int m_size;
public:
    String() = default;
    String(const char* string)
    {
        cout << "constructed!" << endl;
        m_size = strlen(string);
        m_name = new char[m_size + 1];
        memcpy(m_name, string, m_size);
    }
    String(const String& other)
    {
        cout << "copy!" << endl;        
        m_size = other.m_size;
        m_name = new char[m_size + 1];
        memcpy(m_name, other.m_name, m_size);
    }
    String(String&& other) noexcept // ��ֵ����
    {
        cout << "move!" << endl;        
        m_size = other.m_size;
        m_name = other.m_name;
        // ���پ�ָ�� �Է�m_name������
        other.m_size = 0;
        other.m_name = nullptr;
    }
    String& operator=(String&& other) noexcept
    {
        cout << "move!" << endl;      
        if(this != &other) 
        {
            delete[] m_name;
            m_size = other.m_size;
            m_name = other.m_name;
            other.m_size = 0;
            other.m_name = nullptr;
        }
        return *this;
    }
    ~String()
    {
        cout << "destoryed!" << endl;
        delete []m_name;
    }
    void Print()
    {
        for(int i=0;i<m_size;i++)
            cout << m_name[i];
        cout << endl;
    }
};


class Entry
{
private:
    String m_Name;
public:
    Entry(const String& name)
        : m_Name(name)
    {}
    Entry(String&& name)
        // ��ʽ��ֵ����
        : m_Name(move(name))
    {}
    void m_Print()
    {
        m_Name.Print();
    }
};

int main()
{
    String apple("apple");

    // ����=���Ǹ�ֵ���� ���ǹ������
    String des = apple;

    cout << "apple: ";
    apple.Print();
    cout << "des: ";
    des.Print();

    // ����=�Ǹ�ֵ���� ���·�������ͬ
    // des.operator=(move(apple));
    des = move(apple);

    cout << "apple: ";
    apple.Print();
    cout << "des: ";
    des.Print();


}