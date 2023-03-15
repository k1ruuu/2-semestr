#include <iostream>
using namespace std;

class Complex {
private:
    double real = 0;
    double imag = 0;
    friend ostream& operator<<(ostream& os, const Complex& c);
    friend istream& operator>>(istream& is, Complex& c);

public:
    Complex() = default; // базовый конструктор

    Complex(double r, double i) : real(r), imag(i) {} // конструктор

    Complex(const Complex& other) : real(other.real), imag(other.imag) {} // конструктор копирования

    // Оператор присваивания копированием
    Complex& operator=(const Complex& other) {
        real = other.real;
        imag = other.imag;
        return *this;
    }

    //Оператор +=
    Complex& operator+=(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    //Операторы +
    Complex operator+(const Complex& other)  {
        return Complex(real + other.real, imag + other.imag);
    }

    //Операторы *= 
    Complex& operator*=(const Complex& other) {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        real = r;
        imag = i;
        return *this;
    }

    //Оператор *
    Complex operator*(const Complex& other)  {
        return Complex(real * other.real - imag * other.imag,
            real * other.imag + imag * other.real);
    }

    //Оператор ++ префиксный
    Complex& operator++() {
        ++real;
        return *this;
    }

    //Оператор ++ постфиксный
    Complex operator++(int) {
        Complex temp(*this);
        ++real;
        return temp;
    }

    ~Complex() {} // деструктор
};

//Оператор вывода
ostream& operator<<(ostream& os, const Complex& c) {
    if (c.imag >= 0)
        os << c.real << " + " << c.imag << "i";
    if (c.imag < 0)
        os << c.real << c.imag << "i";
    return os;
}

//Оператор ввода
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
