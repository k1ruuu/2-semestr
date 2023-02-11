#include <iostream>
#include <string>
#include <vector>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class shifr {
private:
	vector <int> fib = { 1, 2 };
	vector <string> text;
public:
	void fibanachi(int i) {
		for (int j = 2; j < i; j++) {
			fib.push_back(fib[j - 1] + fib[j - 2]);
		}
	}
	void encode(){
		string str;
		getline(cin, str);
		string txt = "";
		for (int i = 0; i < str.length(); i++) {
			if (str[i] != ' ') {
				txt += str[i];
			}
			if (str[i] == ' ') {
				text.push_back(txt);
				txt = "";
			}
		}
		if (txt.length() != 0) {
			text.push_back(txt);
		}
	}
	void get() {
		for (int i = 0; i < text.size(); i++) {
			cout << text[i] << " ";
		}
	}
};

int main() {
	shifr i;
	i.fibanachi(30);
	i.encode();
	i.get();
}