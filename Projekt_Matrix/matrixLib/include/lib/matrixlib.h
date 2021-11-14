#ifndef PROJEKT_1_MATRIXLIB_HPP
#define PROJEKT_1_MATRIXLIB_HPP

int **createMatrix(int **matrix, int *rows, int *columns, int option = 1,double scalar=0);

double **createMatrix(double **matrix, int *rows, int *columns, int option = 1,double scalar=0);

void enterDimensions(int *rows, int *columns, int option = 1);

int **allocateMatrix(int **matrix, int rows, int columns);

double **allocateMatrix(double **matrix, int rows, int columns);

void fillMatrix(int **matrix, int rows, int columns,int option,double scalar);

void fillMatrix(double **matrix, int rows, int columns,int option,double scalar);

void removeMatrix(int **matrix,int rows);

void removeMatrix(double **matrix,int rows);

void showMatrix(int **matrix, int rows, int columns);

void showMatrix(double **matrix, int rows, int columns);

int **addMatrix(int **matrixA, int **matrixB, int rows, int columns);

double **addMatrix(double **matrixA, double **matrixB, int rows, int columns);

int **subtractMatrix(int **matrixA, int **matrixB, int rows, int columns);

double **subtractMatrix(double **matrixA, double **matrixB, int rows, int columns);

int **multiplyMatrix(int **matrixA, int **matrixB, int rowsA, int columnsA, int columnsB);

double **multiplyMatrix(double **matrixA, double **matrixB, int rowsA, int columnsA, int columnsB);

int **multiplyByScalar(int **matrix, int rows, int columns, int **scalar);

double **multiplyByScalar(double **matrix, int rows, int columns, double **scalar);

int **transpozeMatrix(int **matrix, int rows, int columns);

double **transpozeMatrix(double **matrix, int rows, int columns);

int **powerMatrix(int **matrix, int rows, int columns, unsigned long power);

double **powerMatrix(double **matrix, int rows, int columns, unsigned long power);

double determinantMatrix(int **matrix, int rows, int columns);

double determinantMatrix(double **matrix, int rows, int columns);

bool matrixIsDiagonal(int **matrix, int rows, int columns);

bool matrixIsDiagonal(double **matrix, int rows, int columns);

void swap(int &a, int &b);

void swap(double &a, double &b);

void sortRow(int *matrix, int columns);

void sortRow(double *matrix, int columns);

void sortRowsInMatrix(int **matrix, int rows, int columns);

void sortRowsInMatrix(double **matrix, int rows, int columns);

void help();

void error_par();

#endif //PROJEKT_1_MATRIXLIB_HPP