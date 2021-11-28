#include <math.h>
#include <iostream>
#include "Lab6.h"
using namespace std;

double Vector::length() {
    return sqrt(x * x + y * y);
}

void Vector::print() {
    cout<<x<<", "<<y<<endl;
}

Vector Vector::operator+(const Vector &rhs) const {
    return {x + rhs.x, y + rhs.y};
}

Vector Vector::operator!() const {
    return {x*(-1), y*(-1)};
}

Vector Vector::operator-(const Vector &rhs) const {
    return {x - rhs.x, y - rhs.y};
}