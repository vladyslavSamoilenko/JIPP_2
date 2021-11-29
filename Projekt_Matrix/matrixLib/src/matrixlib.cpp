#include "iostream"
#include "lib/matrixlib.h"

using namespace std;

int **createMatrix(int **matrix, int *rows, int *columns, int option, double scalar)
{
  enterDimensions(rows, columns, option);
  matrix = allocateMatrix(matrix, *rows, *columns);
  fillMatrix(matrix, *rows, *columns, option, scalar);
  return matrix;
}

double **createMatrix(double **matrix, int *rows, int *columns, int option, double scalar)
{
    enterDimensions(rows, columns, option);
    matrix = allocateMatrix(matrix, *rows, *columns);
    fillMatrix(matrix, *rows, *columns, option, scalar);
    return matrix;
}

void enterDimensions(int *rows, int *columns, int option)
{
    if (option == 1)
    {
      cout << "Uzupelnij informacje dotyczace macierzy A\n";
      cout << "Wprowadz ilosc wierszy:";
      while(!(cin>>*rows))
     {
     cin.clear();
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     cout<<"Blad. Sprobuj ponownie\n";
     cout << "Wprowadz ilosc wierszy:";
     }
     cout << "Wprowadz ilosc kolumn:";
     while(!(cin >> *columns))
     {
     cin.clear();
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     cout<<"Blad. Sprobuj ponownie\n";
     cout << "Wprowadz ilosc kolumn:";
     }
    }
    else if (option == 0)
    {
        cout << "Uzupelnij informacje dotyczace macierzy B\n";
        cout << "Wprowadz ilosc kolumn:";
        while(!(cin >> *columns))
     {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout<<"Blad. Sprobuj ponownie\n";
      cout << "Wprowadz ilosc kolumn:";
      }
    }
    else if (option == 5)
   {
    cout << "Uzupelnij informacje dotyczace macierzy A\n";
    cout << "Wprowadz ilosc wierszy i kolumn:";
    while(!(cin>>*rows))
   {
   cin.clear();
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   cout<<"Blad. Sprobuj ponownie\n";
   cout << "Wprowadz ilosc wierszy i kolumn:";
   }
   *columns=*rows;
   }
}

int **allocateMatrix(int **matrix, int rows, int columns)
{
    matrix = new int *[rows];
    for (int row_number = 0; row_number < rows; ++row_number)
    {
        matrix[row_number] = new int[columns];
    }
    return matrix;
}

double **allocateMatrix(double **matrix, int rows, int columns)
{
  matrix = new double *[rows];
  for (int row_number = 0; row_number < rows; ++row_number)
  {
  matrix[row_number] = new double[columns];
  }
  return matrix;
}

void fillMatrix(int **matrix, int rows, int columns, int option, double scalar)
{
  if (option == 4)
  {
   for (int row_number = 0; row_number < rows; ++row_number)
  {
   for (int column_number = 0; column_number < columns; ++column_number)
  {
   matrix[row_number][column_number] = scalar;
  }
  }
   return;
  }
   if (option != 3)
  {
   if (option == 2)
  {
   static char matrixName{'B'};
   cout << "Uzupelnij macierz " << matrixName << "\n";
   matrixName++;
   }
   for (int row_number = 0; row_number < rows; ++row_number)
   {
   for (int column_number = 0; column_number < columns; ++column_number)
   {
    cout << "[" << row_number << "][" << column_number << "]=";
    while(!(cin >> matrix[row_number][column_number]))
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout<<"Blad. Sprobuj ponownie\n";
      cout << "[" << row_number << "][" << column_number << "]=";
    }
    }
    }
    }
  else
{
 for (int row_number = 0; row_number < rows; ++row_number)
{
for (int column_number = 0; column_number < columns; ++column_number)
{
matrix[row_number][column_number]=0;
}
}
}
}

void fillMatrix(double **matrix, int rows, int columns, int option, double scalar)
{
 if (option == 4)
 {
 for (int row_number = 0; row_number < rows; ++row_number)
 {
 for (int column_number = 0; column_number < columns; ++column_number)
 {
 matrix[row_number][column_number] = scalar;
 }
 }
 return;
 }
  if (option != 3)
 {
  if (option == 2)
 {
 static char matrixName{'B'};
 cout << "Uzupelnij macierz " << matrixName << "\n";
 matrixName++;
 }
 for (int row_number = 0; row_number < rows; ++row_number)
 {
 for (int column_number = 0; column_number < columns; ++column_number)
 {
 cout << "[" << row_number << "][" << column_number << "]=";
 while(!(cin >> matrix[row_number][column_number]))
 {
 cin.clear();
 cin.ignore(numeric_limits<streamsize>::max(), '\n');
 cout<<"Blad. Sprobuj ponownie\n";
 cout << "[" << row_number << "][" << column_number << "]=";
}
}
}
}
else
{
for (int row_number = 0; row_number < rows; ++row_number)
{
for (int column_number = 0; column_number < columns; ++column_number)
{
matrix[row_number][column_number]=0;
}
}
}
}

void removeMatrix(int **matrix, int rows)
{
 for (int row_number = 0; row_number < rows; ++row_number)
 {
  delete[]matrix[row_number];
 }
  delete[]matrix;
 }

void removeMatrix(double **matrix, int rows)
{
 for (int row_number = 0; row_number < rows; ++row_number)
{
 delete[]matrix[row_number];
 }
 delete[]matrix;
}

void showMatrix(int **matrix, int rows, int columns)
{
   cout << "\nMacierz wynikowa:\n";
   for (int row_number = 0; row_number < rows; ++row_number)
   {
   for (int column_number = 0; column_number < columns; ++column_number)
   {
   cout << "[" << row_number << "][" << column_number << "]=" << matrix[row_number][column_number] << "\n";
   }
   }
}

void showMatrix(double **matrix, int rows, int columns)
{
  cout << "\nMacierz wynikowa:\n";
  for (int row_number = 0; row_number < rows; ++row_number)
  {
  for (int column_number = 0; column_number < columns; ++column_number)
  {
  cout << "[" << row_number << "][" << column_number << "]=" <<matrix[row_number][column_number] << "\n";
  }
  }
}

int **addMatrix(int **matrixA, int **matrixB, int rows, int columns)
{
    int **resultMatrix{nullptr};
    resultMatrix = createMatrix(resultMatrix, &rows, &columns, 3);
    for (int row_number = 0; row_number < rows; ++row_number)
    {
    for (int col_number = 0; col_number < columns; ++col_number)
    {
    resultMatrix[row_number][col_number] = matrixA[row_number][col_number] + matrixB[row_number][col_number];
    }
    }
    return resultMatrix;
}

double **addMatrix(double **matrixA, double **matrixB, int rows, int columns)
{
    double **resultMatrix{nullptr};
    resultMatrix = createMatrix(resultMatrix, &rows, &columns, 3);
    for (int row_number = 0; row_number < rows; ++row_number)
    {
    for (int col_number = 0; col_number < columns; ++col_number)
    {
    resultMatrix[row_number][col_number] = matrixA[row_number][col_number] + matrixB[row_number][col_number];
    }
    }
    return resultMatrix;
}

int **subtractMatrix(int **matrixA, int **matrixB, int rows, int columns)
{
    int **resultMatrix{nullptr};
    resultMatrix = createMatrix(resultMatrix, &rows, &columns, 3);
    for (int row_number = 0; row_number < rows; ++row_number)
    {
    for (int col_number = 0; col_number < columns; ++col_number)
    {
    resultMatrix[row_number][col_number] = matrixA[row_number][col_number] - matrixB[row_number][col_number];
    }
    }
    return resultMatrix;
}

double **subtractMatrix(double **matrixA, double **matrixB, int rows, int columns)
{
    double **resultMatrix{nullptr};
    resultMatrix = createMatrix(resultMatrix, &rows, &columns, 3);
    for (int row_number = 0; row_number < rows; ++row_number)
    {
     for (int col_number = 0; col_number < columns; ++col_number)
    {
    resultMatrix[row_number][col_number] = matrixA[row_number][col_number] - matrixB[row_number][col_number];
    }
    }
    return resultMatrix;
}

int **multiplyMatrix(int **matrixA, int **matrixB, int rowsA, int columnsA, int columnsB)
{
    int **resultMatrix{nullptr};
    int sum;
    resultMatrix = createMatrix(resultMatrix, &rowsA, &columnsB, 3);
    for (int row_number = 0; row_number < rowsA; ++row_number)
    {
    for (int col_number_1 = 0; col_number_1 < columnsB; ++col_number_1)
    {
    sum = 0;
    for (int col_number_2 = 0; col_number_2 < columnsA; ++col_number_2)
    {
    sum += matrixA[row_number][col_number_2] * matrixB[col_number_2][col_number_1];
    }
    resultMatrix[row_number][col_number_1] = sum;
    }
    }
    return resultMatrix;
}

double **multiplyMatrix(double **matrixA, double **matrixB, int rowsA, int columnsA, int columnsB)
{
    double **resultMatrix{nullptr};
    double sum;
    resultMatrix = createMatrix(resultMatrix, &rowsA, &columnsB, 3);
    for (int row_number = 0; row_number < rowsA; ++row_number)
    {
     for (int col_number_1 = 0; col_number_1 < columnsB; ++col_number_1)
    {
    sum = 0;
    for (int col_number_2 = 0; col_number_2 < columnsA; ++col_number_2)
    {
    sum += matrixA[row_number][col_number_2] * matrixB[col_number_2][col_number_1];
    }
    resultMatrix[row_number][col_number_1] = sum;
    }
    }
    return resultMatrix;
}

int **multiplyByScalar(int **matrix, int rows, int columns, int **scalar)
{
    int **resultMatrix{nullptr};
    resultMatrix = createMatrix(resultMatrix, &rows, &columns, 3);
    for (int row_number = 0; row_number < rows; ++row_number)
    {
    for (int col_number = 0; col_number < columns; ++col_number)
     {
     resultMatrix[row_number][col_number] = matrix[row_number][col_number] * scalar[row_number][col_number];
     }
    }
    return resultMatrix;
}

double **multiplyByScalar(double **matrix, int rows, int columns, double **scalar)
{
    double **resultMatrix{nullptr};
    resultMatrix = createMatrix(resultMatrix, &rows, &columns, 3);
    for (int row_number = 0; row_number < rows; ++row_number)
    {
    for (int col_number = 0; col_number < columns; ++col_number)
    {
    resultMatrix[row_number][col_number] = matrix[row_number][col_number] * scalar[row_number][col_number];
    }
    }
    return resultMatrix;
}

int **transpozeMatrix(int **matrix, int rows, int columns)
{
    int **resultMatrix{nullptr};
    resultMatrix = createMatrix(resultMatrix, &columns, &rows, 3);
    for (int row_number = 0; row_number < columns; ++row_number)
    {
     for (int col_number = 0; col_number < rows; ++col_number)
     {
      resultMatrix[row_number][col_number] = matrix[col_number][row_number];
     }
    }
    return resultMatrix;
}

double **transpozeMatrix(double **matrix, int rows, int columns)
{
    double **resultMatrix{nullptr};
    resultMatrix = createMatrix(resultMatrix, &columns, &rows, 3);
    for (int row_number = 0; row_number < columns; ++row_number)
    {
      for (int col_number = 0; col_number < rows; ++col_number)
      {
        resultMatrix[row_number][col_number] = matrix[col_number][row_number];
      }
    }
    return resultMatrix;
}

int **powerMatrix(int **matrix, int rows, int columns, unsigned long power)
{
    int **resultMatrix{nullptr};
    resultMatrix = createMatrix(resultMatrix, &rows, &columns, 3);

    resultMatrix = multiplyMatrix(matrix, matrix, rows, columns, columns);

    for (unsigned long i = 2; i < power; ++i)
    {
        resultMatrix = multiplyMatrix(resultMatrix, matrix, rows, columns, columns);
    }
    return resultMatrix;
}

double **powerMatrix(double **matrix, int rows, int columns, unsigned long power)
{
    double **resultMatrix{nullptr};
    resultMatrix = createMatrix(resultMatrix, &rows, &columns, 3);

    resultMatrix = multiplyMatrix(matrix, matrix, rows, columns, columns);

    for (unsigned long i = 2; i < power; ++i)
    {
        resultMatrix = multiplyMatrix(resultMatrix, matrix, rows, columns, columns);
    }
    return resultMatrix;
}

double determinantMatrix(int **matrix, int rows, int columns)
{
    double det{};
    int **matrixHelp{nullptr};
    matrixHelp = createMatrix(matrixHelp, &rows, &columns, 3);
    if (rows == 2)
    {
      return ((matrix[0][0]*matrix[1][1])-(matrix[1][0]*matrix[0][1]));
    }
    else
    {
     for (int c = 0; c < rows; ++c)
    {
     int subi{};
     for (int i = 1; i < rows; ++i)
     {
      int subj{};
      for (int j = 0; j < rows; ++j)
     {
       if (j==c)
     {
      continue;
     }
      matrixHelp[subi][subj]=matrix[i][j];
      subj++;
     }
      subi++;
     }
      det = det + (pow(-1, c) * matrix[0][c] * determinantMatrix(matrixHelp,rows-1,columns-1));
     }
    }
    removeMatrix(matrixHelp, rows);
    return det;
}

double determinantMatrix(double **matrix, int rows, int columns)
{
  double det{};
  double **matrixHelp{nullptr};
  matrixHelp = createMatrix(matrixHelp, &rows, &columns, 3);
  if (rows == 2)
  {
  return ((matrix[0][0]*matrix[1][1])-(matrix[1][0]*matrix[0][1]));
  }
  else
  {
  for (int c = 0; c < rows; ++c)
  {
   int subi{};
   for (int i = 1; i < rows; ++i)
   {
   int subj{};
   for (int j = 0; j < rows; ++j)
   {
   if (j==c)
   {
   continue;
   }
   matrixHelp[subi][subj]=matrix[i][j];
   subj++;
   }
   subi++;
   }
   det = det + (pow(-1, c) * matrix[0][c] * determinantMatrix(matrixHelp,rows-1,columns-1));
   }
    }
    removeMatrix(matrixHelp, rows);
    return det;
}

bool matrixIsDiagonal(int **matrix, int rows, int columns)
{
 int i{0}, j{0};
 for (int row_number = 0; row_number < rows; ++row_number)
 {
 for (int col_number = 0; col_number < columns; ++col_number)
 {
 if (((row_number != i) || (col_number != i)) && (matrix[row_number][col_number] != 0))
 {
 return false;
 }
 }
 i++;
 }
  return true;
}

bool matrixIsDiagonal(double **matrix, int rows, int columns)
{
   int i{0};
  for (int row_number = 0; row_number < rows; ++row_number)
 {
  for (int col_number = 0; col_number < columns; ++col_number)
 {
  f (((row_number != i) || (col_number != i)) && (matrix[row_number][col_number] != 0))
 {
 return false;
 }
 }
 i++;
 }
 return true;
}

void swap(int &a, int &b)
{
  int tmp=a;
  a=b;
  b=tmp;
}

void swap(double &a, double &b)
{
  double tmp=a;
  a=b;
  b=tmp;
}

void sortRow(int *matrix, int columns)
{
 for (int j = 0; j < columns-1; ++j)
{
for (int i = 0; i < columns-1; ++i)
{
if (matrix[i]>matrix[i+1])
{
swap(matrix[i],matrix[i+1]);
}
}
}
}

void sortRow(double *matrix, int columns)
{
 for (int j = 0; j < columns-1; ++j)
{
 for (int i = 0; i < columns-1; ++i)
{
if (matrix[i]>matrix[i+1])
{
swap(matrix[i],matrix[i+1]);
}
}
}
}

void sortRowsInMatrix(int **matrix, int rows, int columns)
{
 for (int i = 0; i < rows; ++i,*matrix++)
{
sortRow(*matrix,columns);
}
}

void sortRowsInMatrix(double **matrix, int rows, int columns)
{
 for (int i = 0; i < rows; ++i,*matrix++)
 {
 sortRow(*matrix,columns);
 }
}

void help()
{
    cout << endl << R"(Instrukcja obslugi programu.
0. Najpierw podaj ilosc wierszy i kolumn macierzy A.
   Nastepnie wczytaj dane do macierzy A.
   Podaj ilosc kolumn macierzy B.
   Podaj dane do macirzy B.
   Po uruchomieniu programu z odpowiednim parametrem. Program bedzie Cie informowal co nalezy wprowadzic z klawiatury.
1. Aby dodac dwie macierze wprowadz nastepujacy parametr: |addMatrix|
2. Aby odjac dwie macierze wprowadz nastepujacy parametr: |subtractMatrix|
3. Aby pomnozyc dwie macierze przez siebie wprowadz nastepujacy parametr: |multiplyMatrix|
4. Aby pomnozyc dwie macierze przez skalar wprowadz nastepujacy parametr: |multiplyByScalar|
5. Aby transponowac macierz wprowadz nastepujacy parametr: |transpozeMatrix|
6. Aby podniesc macierz do wybranej potegi wprowadz nastepujace paramety: |powerMatrix| |wartosc potegi|
7. Aby obliczyc wyznacznik macierzy wprowadz nastepujacy parametr: |determinantMatrix|
8. Aby sprawdzic czy macierze jest diagonalna wprowadz nastepujacy parametr: |matrixIsDiagonal|
9. Aby zamienic dwie wartoscie miejscami wprowadz nastepujacy parametr: |swap|
10. Aby posortowac wybrany wiersz macierzy wprowadz nastepujacy parametr: |sortRow|
11. Aby posortowac wszystkie wierszy macierzy wprowadz nastepujacy parametr: |sortRowsInMatrix|
12. Aby wywolac instrukcje obslugi programu wprowadz nastepujacy parametr: |help|)";
}

void error_par()
{
    cout << endl << R"(Program zostal uruchomiony z blednymi parametrami.
Jesli potrzebujesz pomocy uruchom program z nastepujacym parametrem: |help|)";
}
