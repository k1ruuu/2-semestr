#include <iostream>
#include <string>
#include <vector>
using namespace std;

class shifr {
private:
	vector <int> fib = { 1, 2 };
	vector <string> text;
	vector <string> code;
public:
	shifr() {
		code.resize(30);
	}
	void fibanachi(int i) {
		for (int j = 2; j < i; j++) {
			fib.push_back(fib[j - 1] + fib[j - 2]);
		}
	}
	void encode(vector <int> key){
		if (check(key) == false) {
			cout << "Îøèáêà â êëþ÷å";
		}
		else {
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
			for (int i = 0; i < key.size(); i++) {
				for (int j = 0; j < fib.size(); j++) {
					if (key[i] == fib[j]) {
						code[j] = text[i];
					}
				}
			}
		}
	}
	void decode(vector <int> key) {
		if (text.size() > 30) {
			cout << "Ìíîãî ñëîâ" << endl;
		}
		if (check(key) == false) {
			cout << "Îøèáêà â êëþ÷å";
		}
		else {
			for (int i = 0; i < key.size(); i++) {
				for (int j = 0; j < fib.size(); j++) {
					if (key[i] == fib[j]) {
						cout << code[j];
					}
				}
			}
		}
	}
	bool check(vector <int> mas) {
		for (int i = 0; i < mas.size(); i++) {
			int count = 0;
			for (int j = 0; j < fib.size(); j++) {
				if (mas[i] != fib[j]) {
					count++;
				}
			}
			if (count == fib.size()) {
				return false;
			}
		}
		return true;
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	shifr i;
	i.fibanachi(30);
	i.encode({3,2,1,8,5});
	i.decode({ 1,3,2,8,4 });
}
