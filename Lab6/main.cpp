#include <iostream>
#include "Lab6.h"

using namespace std;

int main() {
    Vector v1, v2, v3, v4, v5;
    ImaginaryNumber num1;
    Node test1, test2;

    test1.updateValue(2,5);
    test2.updateValue(5,9);

    num1={5,2};
    v1={3, 4};
    v2={4, 3};

    v3=v1+v2;
    v4=!v3;
    v5=v1-v2;

    v3.print();
    v4.print();
    v5.print();

    num1.print();

    cout<<pointsDistance(test1, test2);

    return 0;
}