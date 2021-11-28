#include "../include/calc.h"
#include <iostream>
#include <string>
#include <experimental/string_view>

using namespace std;

int main(int argc, char *argv[])
{
    if(experimental::string_view(argv[1]) == "add") {
        if(argc!=4) {
            blad();
            return 1;
        }

        else {
            try {
                stoi(argv[2]);
                stoi(argv[3]);
            }

            catch(const invalid_argument) {
                blad();
                return 1;
            }

            cout<<"Wynik: "<<add(stoi(argv[2]), stoi(argv[3]));
            zakonczProgram();
        }
    }

    else if(experimental::string_view(argv[1]) == "subtract") {
        if(argc!=4) {
            blad();
            return 1;
        }

        else {
            try {
                stoi(argv[2]);
                stoi(argv[3]);
            }

            catch(const invalid_argument) {
                blad();
                return 1;
            }

            cout<<"Wynik: "<<subtract(stoi(argv[2]), stoi(argv[3]));
            zakonczProgram();
        }
    }

    else if(experimental::string_view(argv[1]) == "volume") {
        if(argc!=6) {
            blad();
            return 1;
        }

        else {
            try {
                stoi(argv[2]);
                stoi(argv[3]);
                stoi(argv[4]);
                stoi(argv[5]);

            }

            catch(const invalid_argument) {
                blad();
                return 1;
            }

            cout<<"Wynik: "<<volume(stoi(argv[2]), stoi(argv[3]), stoi(argv[4]), stoi(argv[5]));
            zakonczProgram();
        }
    }

    else if(experimental::string_view(argv[1]) == "help") {
        help();
        zakonczProgram();
    }

    else {
        blad();
        return 1;
    }

    return 0;
}