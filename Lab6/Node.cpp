#include <math.h>
#include <iostream>
#include "Lab6.h"
using namespace std;

Node::Node() {
    x = 0;
    y = 0;
}

Node::Node(double x, double y): x(x), y(y) {}

void Node::display() {
    cout << "x: " << x << "\ty: " << y << endl;
}

void Node::updateValue(double x, double y) {
    this->x = x;
    this->y = y;
}

double pointsDistance(Node& a, Node& b) {
    sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}