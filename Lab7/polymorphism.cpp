#include <iostream>
#include <math.h>
using namespace std;

class Figure {
protected:
    string name, color;

public:
    void getData() {
        cout<<"Nazwa: "<<name<<endl;
        cout<<"Kolor: "<<color<<endl;
    }

    void setData(string name, string color) {
        this->name = name;
        this->color = color;
    }

    virtual double getArea() = 0;
};

class Circle : public Figure {
private:
    double radius;

public:
    Circle(double radius);

    double getArea() {
        return M_PI * pow(radius, 2);
    }

    double getCircumference() {
        return 2 * M_PI * radius;
    }

    void setRadius(double radius) {
        this->radius = radius;
    }
};

Circle::Circle(double radius) {
    this->radius = radius;
}

class Rectangle : public Figure {
private:
    double a, b;

public:
    Rectangle(double a, double b);

    double getArea() {
        return a*b;
    }

    double getCircumference() {
        return 2*(a+b);
    }

    void setDimensions(double a, double b) {
        this->a = a;
        this->b = b;
    }
};

Rectangle::Rectangle(double a, double b) {
    this->a = a;
    this->b = b;
}

int main() {
    Figure *circle = new Circle(5);
    Figure *rectangle = new Rectangle(5, 18);

    cout << "Circle area: " << circle->getArea() << endl;
    cout << "Rectangle area: " << rectangle->getArea() << endl;
    return 0;
}

