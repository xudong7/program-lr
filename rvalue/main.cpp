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
    String(String&& other) noexcept // 右值引用
    {
        cout << "move!" << endl;        
        m_size = other.m_size;
        m_name = other.m_name;
        // 销毁旧指针 以防m_name被销毁
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
        // 显式右值引用
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

    // 这里=不是赋值操作 而是构造操作
    String des = apple;

    cout << "apple: ";
    apple.Print();
    cout << "des: ";
    des.Print();

    // 这里=是赋值操作 与下方操作相同
    // des.operator=(move(apple));
    des = move(apple);

    cout << "apple: ";
    apple.Print();
    cout << "des: ";
    des.Print();


}