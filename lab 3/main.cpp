#include <iostream>
using namespace std;

class Complex {
private:
    double real = 0;
    double imag = 0;
    friend ostream& operator<<(ostream& os, const Complex& c);
    friend istream& operator>>(istream& is, Complex& c);

public:
    Complex() = default; // áàçîâûé êîíñòðóêòîð

    Complex(double r, double i) : real(r), imag(i) {} // êîíñòðóêòîð

    Complex(const Complex& other) : real(other.real), imag(other.imag) {} // êîíñòðóêòîð êîïèðîâàíèÿ

    // Îïåðàòîð ïðèñâàèâàíèÿ êîïèðîâàíèåì
    Complex& operator=(const Complex& other) {
        real = other.real;
        imag = other.imag;
        return *this;
    }

    //Îïåðàòîð +=
    Complex& operator+=(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    //Îïåðàòîðû +
    Complex operator+(const Complex& other)  {
        return Complex(real + other.real, imag + other.imag);
    }

    //Îïåðàòîðû *= 
    Complex& operator*=(const Complex& other) {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        real = r;
        imag = i;
        return *this;
    }

    //Îïåðàòîð *
    Complex operator*(const Complex& other)  {
        return Complex(real * other.real - imag * other.imag,
            real * other.imag + imag * other.real);
    }

    //Îïåðàòîð ++ ïðåôèêñíûé
    Complex& operator++() {
        ++real;
        return *this;
    }

    //Îïåðàòîð ++ ïîñòôèêñíûé
    Complex operator++(int) {
        Complex temp(*this);
        ++real;
        return temp;
    }

    ~Complex() {} // äåñòðóêòîð
};

//Îïåðàòîð âûâîäà
ostream& operator<<(ostream& os, const Complex& c) {
    if (c.imag >= 0)
        os << c.real << "+" << c.imag << "i";
    if (c.imag < 0)
        os << c.real << c.imag << "i";
    return os;
}

//Îïåðàòîð ââîäà
istream& operator>>(istream& is, Complex& c) {
    cout << "Real part: ";
    is >> c.real;
    cout << "Imaginary part: ";
    is >> c.imag;
    return is;
}

int main() {
    Complex c0;
    cout << c0 << endl;
    Complex c1(2.0, 3.0);
    cout << c1 << endl;
    Complex c2(1.0, 2.0);
    cout << c2 << endl;
    Complex c3(c1);
    cout << c3 << endl;

    c1 += c2;
    cout << c1 << endl;

    Complex c4 = c1 + c2;
    cout << c4 << endl;

    c3 *= c2;
    cout << c3 << endl;

    Complex c5 = c1 * c2;
    cout << c5 << endl;

    ++c1;
    cout << c1 << endl;

    Complex c6 = c2++;
    cout << c6 << endl;
    cout << c2 << endl;

    Complex c7;
    cin >> c7;
    cout << c7 << endl;
}
