#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Shape {
protected:
    string color;
    double x;
    double y;

public:
    Shape(const string& color, double x, double y) : color(color), x(x), y(y) {}

    virtual double Area() = 0;
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(const string& color, double x, double y, double base, double height) : Shape(color, x, y), base(base), height(height) {}
    
    double Area() override {
        return 0.5 * base * height;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(const string& color, double x, double y, double width, double height) : Shape(color, x, y), width(width), height(height) {}

    double Area() override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(const string& color, double x, double y, double radius) : Shape(color, x, y), radius(radius) {}

    double Area() override {
        return 3.14 * radius * radius;
    }
};

int main() {
    vector<Shape*> shapes;
    shapes.push_back(new Triangle("Red", 0.0, 0.0, 4.0, 3.0));
    shapes.push_back(new Rectangle("Green", 1.0, 1.0, 5.0, 2.0));
    shapes.push_back(new Circle("Blue", 2.0, 2.0, 3.0));

    for (int i = 0; i < shapes.size(); i++) {
        cout << "Shape " << i + 1 << " Area: " << shapes[i]->Area() << endl;
    }

    return 0;
}
