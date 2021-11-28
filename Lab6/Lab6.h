#ifndef UNTITLED1_VECTOR_H
#define UNTITLED1_VECTOR_H

class Vector {
private:
    double x,y;

public:
    Vector() {};
    Vector(double x, double y) : x(x), y(y) {};

    double length();
    void print();

    Vector operator+(const Vector &rhs) const;
    Vector operator!() const;
    Vector operator-(const Vector &rhs) const;
};

class ImaginaryNumber {
private:
    double re, im;

public:
    ImaginaryNumber() {};
    ImaginaryNumber(double re, double im) : re(re), im(im) {};

    void print();
};

class Node {
    friend double pointsDistance (Node& a, Node& b);
private:
    double x, y;

public:
    Node();
    Node(double x, double y);

    void display();

    void updateValue(double x, double y);
};

double pointsDistance(Node& a, Node& b);

#endif //UNTITLED1_VECTOR_H
