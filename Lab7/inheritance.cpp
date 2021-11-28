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
};

class Circle : public Figure {
private:
    double radius;

public:
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

class Rectangle : public Figure {
private:
    double a, b;

public:
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

int main() {
    Circle kolo;

    kolo.setData("kolko", "czerwony");
    kolo.setRadius(6);

    kolo.getData();
    cout<<"Pole: "<<kolo.getArea()<<endl;
    cout<<"Obwod: "<<kolo.getCircumference()<<endl;

    cout<<endl;
    Rectangle prostokat;

    prostokat.setData("prostokat", "zielony");
    prostokat.setDimensions(5, 6);

    prostokat.getData();
    cout<<"Pole: "<<prostokat.getArea()<<endl;
    cout<<"Obwod: "<<prostokat.getCircumference()<<endl;

    return 0;
}

