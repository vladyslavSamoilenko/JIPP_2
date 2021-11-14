#include <iostream>
#include <string>
#include "../matrixLib/include/lib/matrixlib.h"

#define INT 1
#define DOUBLE 2
#define TYP_LICZB DOUBLE

using namespace std;

int main(int argc, char *argv[])
{
    int rows_a{}, columns_a{};

#if (TYP_LICZB == INT)
    int **matrixA{nullptr};
    int **resultMatrix{nullptr};
#else
    double **matrixA{nullptr};
    double **resultMatrix{nullptr};
#endif
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if (!strcmp(argv[1], "addMatrix"))
    {
        matrixA = createMatrix(matrixA, &rows_a, &columns_a);
#if (TYP_LICZB == INT)
        int **matrixB{nullptr};
        matrixB = createMatrix(matrixB, &rows_a, &columns_a, 2);
#else
        double **matrixB{nullptr};
        matrixB = createMatrix(matrixB, &rows_a, &columns_a, 2);
#endif
        resultMatrix = addMatrix(matrixA, matrixB, rows_a, columns_a);
        showMatrix(resultMatrix, rows_a, columns_a);
        removeMatrix(matrixB, rows_a);
        removeMatrix(resultMatrix, rows_a);
        removeMatrix(matrixA, rows_a);
    }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (!strcmp(argv[1], "subtractMatrix"))
    {
        matrixA = createMatrix(matrixA, &rows_a, &columns_a);
#if (TYP_LICZB == INT)
        int **matrixB{nullptr};
        matrixB = createMatrix(matrixB, &rows_a, &columns_a, 2);
#else
        double **matrixB{nullptr};
        matrixB = createMatrix(matrixB, &rows_a, &columns_a, 2);
#endif
        resultMatrix = subtractMatrix(matrixA, matrixB, rows_a, columns_a);
        showMatrix(resultMatrix, rows_a, columns_a);
        removeMatrix(matrixB, rows_a);
        removeMatrix(resultMatrix, rows_a);
        removeMatrix(matrixA, rows_a);
    }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (!strcmp(argv[1], "multiplyMatrix"))
    {
        matrixA = createMatrix(matrixA, &rows_a, &columns_a);
        int rows_b{columns_a}, columns_b;
#if (TYP_LICZB == INT)
        int **matrixB{nullptr};
        matrixB = createMatrix(matrixB, &rows_b, &columns_b, 0);
#else
        double **matrixB{nullptr};
        matrixB = createMatrix(matrixB, &rows_b, &columns_b, 0);
#endif
        resultMatrix = multiplyMatrix(matrixA, matrixB, rows_a, columns_a, columns_b);
        showMatrix(resultMatrix, rows_a, columns_b);
        removeMatrix(matrixB, rows_a);
        removeMatrix(resultMatrix, rows_a);
        removeMatrix(matrixA, rows_a);
    }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (!strcmp(argv[1], "multiplyByScalar"))
    {
        matrixA = createMatrix(matrixA, &rows_a, &columns_a);
#if (TYP_LICZB == INT)
        int scalar;
        cout << "Podaj sklar:";
        while(!(cin >> scalar))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Blad. Sprobuj ponownie\n";
            cout << "Podaj sklar:";
        }
        int **matrixScalar{nullptr};
#else
        double scalar;
        cout << "Podaj sklar:";
        while(!(cin >> scalar))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Blad. Sprobuj ponownie\n";
            cout << "Podaj sklar:";
        }
        double **matrixScalar{nullptr};
#endif
        matrixScalar = createMatrix(matrixScalar, &rows_a, &columns_a, 4, scalar);
        resultMatrix = multiplyByScalar(matrixA, rows_a, columns_a, matrixScalar);
        showMatrix(resultMatrix, rows_a, columns_a);
        removeMatrix(matrixScalar, rows_a);
        removeMatrix(resultMatrix, rows_a);
        removeMatrix(matrixA, rows_a);
    }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (!strcmp(argv[1], "transpozeMatrix"))
    {
        matrixA = createMatrix(matrixA, &rows_a, &columns_a);
        resultMatrix = transpozeMatrix(matrixA, rows_a, columns_a);
        showMatrix(resultMatrix, columns_a, rows_a);
        removeMatrix(resultMatrix, columns_a);
        removeMatrix(matrixA, rows_a);
    }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (!strcmp(argv[1], "powerMatrix"))
    {
        matrixA = createMatrix(matrixA, &rows_a, &columns_a,5);
        unsigned long power{stoul(argv[2])};
        resultMatrix = powerMatrix(matrixA, rows_a, columns_a, power);
        showMatrix(resultMatrix, columns_a, rows_a);
        removeMatrix(resultMatrix, columns_a);
        removeMatrix(matrixA, rows_a);
    }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (!strcmp(argv[1], "determinantMatrix"))
    {
        matrixA = createMatrix(matrixA, &rows_a, &columns_a,5);
        cout << "Wyznacznik macierzy=" << determinantMatrix(matrixA, rows_a,columns_a)<<endl;
        delete[]resultMatrix;
        removeMatrix(matrixA, rows_a);
    }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (!strcmp(argv[1], "matrixIsDiagonal"))
    {
        matrixA = createMatrix(matrixA, &rows_a, &columns_a,5);
        bool score{matrixIsDiagonal(matrixA, rows_a, columns_a)};
        if (score)
        {
            cout << "Ta macierz jest diagonalizowalna\n";
        }
        else
        {
            cout << "Ta macierz nie jest diagonalizowalna\n";
        }
        delete[]resultMatrix;
        removeMatrix(matrixA, rows_a);
    }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (!strcmp(argv[1], "swap"))
    {
        matrixA = createMatrix(matrixA, &rows_a, &columns_a);

        int rowToSwap1, columnToSwap1;
        cout << "Podaj indeks pierwszej liczby do zamiany:\n";
        cout << "Wiersz:";
        while(!(cin >> rowToSwap1))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Blad. Sprobuj ponownie\n";
            cout << "Wiersz:";
        }

        cout << "Kolumna:";
        while(!(cin >> columnToSwap1))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Blad. Sprobuj ponownie\n";
            cout << "Wiersz:";
        }

        int rowToSwap2, columnToSwap2;
        cout << "Podaj indeks drugiej liczby do zamiany:\n";
        cout << "Wiersz:";
        while(!(cin >> rowToSwap2))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Blad. Sprobuj ponownie\n";
            cout << "Wiersz:";
        }

        cout << "Kolumna:";
        while(!(cin >> columnToSwap2))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Blad. Sprobuj ponownie\n";
            cout << "Wiersz:";
        }

        swap(matrixA[rowToSwap1][columnToSwap1],matrixA[rowToSwap2][columnToSwap2]);
        showMatrix(matrixA,rows_a,columns_a);
        delete[]resultMatrix;
        removeMatrix(matrixA, rows_a);
    }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (!strcmp(argv[1], "sortRow"))
    {
        matrixA = createMatrix(matrixA, &rows_a, &columns_a);
        int rowToSort;
        cout<<"Ktory wiersz posortowac:\n";
        while(!(cin >> rowToSort))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Blad. Sprobuj ponownie\n";
            cout << "Wiersz:";
        }
        sortRow(matrixA[rowToSort],columns_a);
        showMatrix(matrixA,rows_a,columns_a);
        delete[]resultMatrix;
        removeMatrix(matrixA, rows_a);
    }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (!strcmp(argv[1], "sortRowsInMatrix"))
    {
        matrixA = createMatrix(matrixA, &rows_a, &columns_a);
        sortRowsInMatrix(matrixA,rows_a,columns_a);
        showMatrix(matrixA,rows_a,columns_a);
        delete[]resultMatrix;
        removeMatrix(matrixA, rows_a);
    }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (!strcmp(argv[1], "help"))
    {
        help();
        delete[]resultMatrix;
    }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else
    {
        error_par();
        delete[]resultMatrix;
    }
    cout<<"KONIEC\n";
}