#include <iostream>
using namespace std;

class String {
private:
	size_t m_size;
	char* m_str = nullptr;
public:
	String() = default;

	String(int c, size_t size) = delete;

	String(char c, size_t size) : m_size(size), m_str(new char[size+1]) {
		fill(m_str, m_str + m_size, c);
		m_str[m_size] = 0;
	}

	String(char* str) : m_size(strlen(str)), m_str(new char[m_size + 1]) {
		copy(str, str + m_size+1, m_str);
		m_str[m_size] = 0;
	}

	String(const String& other) : String(other.m_str){
	}

	String& operator=(const String& other) {
		delete[] m_str;
		m_size = other.m_size;
		m_str = new char[m_size];
		copy(other.m_str, other.m_str + other.m_size, m_str);
		return *this;
	}

	~String() {
		if (m_str != nullptr) {
			delete[] m_str;
		}
	}

	size_t Size() {
		return m_size;
	}

	void Print() {
		for(int i = 0; i < m_size; i++)
			cout << m_str[i];
	}
};

int  main()
{
	String s1("Hello, world!");
	String s2("strst");
	String s3("123");
	s3=s2 = s1;
	s1.Print();
	cout << endl;
	s2.Print();
	cout << endl;
	s3.Print();
}
