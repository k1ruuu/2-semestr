#include <iostream>
using namespace std;

class String {
private:
	size_t m_size = 0;
	char* m_str = nullptr;
	friend istream& operator>>(istream& is, String& str);
	friend ostream& operator << (ostream& os, const String& str);
public:
	String() = default;

	String(int c, size_t size) = delete;

	String(char c, size_t size) : m_size(size), m_str(new char[size + 1]) {
		fill(m_str, m_str + m_size, c);
		m_str[m_size] = '\0';
	}

	String(char* str) : m_size(strlen(str)), m_str(new char[m_size + 1]) {
		copy(str, str + m_size + 1, m_str);
		m_str[m_size] = '\0';
	}

	String(const String& other) : String(other.m_str) {

	}

	String& operator=(const String& other) {
		delete[] m_str;
		m_size = other.m_size;
		m_str = new char[m_size];
		copy(other.m_str, other.m_str + other.m_size, m_str);
		return *this;
	}

	String& operator+=(const String& other) {
		char* newStr = new char[m_size + other.m_size + 1];
		copy(m_str, m_str + m_size, newStr);
		copy(other.m_str, other.m_str + other.m_size + 1, newStr + m_size);
		delete[] m_str;
		m_str = newStr;
		m_size = strlen(m_str);
		return *this;
	}

	String operator+(const String& str2) {
		String result(this -> m_str);
		result += str2;
		return result;
	}

	char& operator[](int c) {
		if (c < 0 || c >= m_size) {
			throw out_of_range("index out of range");
		}
		return m_str[c];
	}

	bool operator==(const String& other) {
		return strcmp(m_str, other.m_str) == 0;
	}

	bool operator<(const String& other) {
		return strcmp(m_str, other.m_str) < 0;
	}

	bool operator>(const String& other) {
		return strcmp(m_str, other.m_str) > 0;
	}
	
	int find(char c) {
		for (int i = 0; i < m_size; i++) {
			if (m_str[i] == c) {
				return i;
			}
		}
		return -1;
	}

	int length() {
		return m_size;
	}
	
	const char* c_str() const {
		return m_str;
	}

	char& at(int c) {
		if (c < 0 || c >= m_size) {
			throw out_of_range("index out of range");
		}
		return m_str[c];
	}

	~String() {
		if (m_str != nullptr) {
			delete[] m_str;
		}
	}
};
istream& operator >> (istream& is, String& str) {
	char* masc = new char[1000];
	is >> masc;
	int c = 0;
	for (int i = 0; i < 1000; i++) {
		if (masc[i] == '\0' && masc[i] != '\n') {
			c = i;
			break;
		}
	}
	str.m_size = c + 1;
	str.m_str = new char[str.m_size + 1];
	copy(masc, masc + c + 1, str.m_str);
	return is;
}
ostream& operator << (ostream& os, const String& str)
{
	os << str.m_str;
	return os;
}


int  main()
{
	String s1("Hello, world!");
	cout << s1 << endl;
	String s2 = "strstsr";
	cout << s2 << endl;
	String s3("123");
	cout << s3 << endl;
	s3 += s1;
	cout << s3 << endl;
	String s4 = s1 + s2;
	cout << s4 << endl;
	s1[2] = 'h';
	cout << s1 << endl;
	cout << s1[2] << endl;
	String str1 = "Hello";
	String str2 = "Hello";
	if (str1 == str2) {
		cout << "str1 = str2";
	}
	else {
		cout << "str1 != str2";
	}
	cout << endl;
	cout << s1.find('z') << endl;
	cout << s1.length() << endl;
	cout << s1.c_str() << endl;
	s1.at(2) = 'l';
	cout << s1 << endl;
	cout << s1[2] << endl;
	String strin;
	cin >> strin;
	cout << strin << endl;
}