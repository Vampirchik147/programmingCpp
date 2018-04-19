//
// Created by levin on 19.04.18.
//

#include <iostream>
#include <fstream>
#include "Matrix.h"
#include <cassert>
using namespace std;

int main() {

    string A = "/Users/levin/Sveta/ИУ10-41/C++/Lab_3/A.txt";
    string B = "/Users/levin/Sveta/ИУ10-41/C++/Lab_3/B.txt";
    string C = "/Users/levin/Sveta/ИУ10-41/C++/Lab_3/C.txt";
    string D = "/Users/levin/Sveta/ИУ10-41/C++/Lab_3/D.txt";

    Matrix <int>matrix1;
    Matrix <int>matrix2;
    Matrix <int>matrix3;
    Matrix <int>matrix4;
    Matrix <int>matrix5;
    Matrix <int>matrix6;
    Matrix <int>matrix7;
    Matrix <int>matrix8;
    Matrix <int>matrix9;

    cout<<"Matrix A:"<<endl;
    matrix1.Read(A);
    matrix1.Print();

    cout<<"\nMatrix B:"<<endl;
    matrix2.Read(B);
    matrix2.Print();

    cout<<"\nMatrix A + Matrix B:"<<endl;
    matrix3 = matrix1 + matrix2;
    matrix3.Print();

    matrix8.Read(D);

    cout << "\nСравнимаем матрицы из файла D и матрицу - результат сложения матриц из файла A и B: " << (matrix3 == matrix8);

    cout<<"\nMatrix A - Matrix B:"<<endl;
    matrix4 = matrix1 - matrix2;
    matrix4.Print();

    cout<<"\nMatrix A * Matrix B:"<<endl;
    matrix5 = matrix1 * matrix2;
    matrix5.Print();

    cout<<"\nMatrix C:"<<endl;
    matrix6.Read(C);
    matrix6.Print();

    cout<<"\nMatrix C -> Transpont:"<<endl;
    matrix7 = matrix6.Transp();
    matrix7.Print();

    cout<<"\nСравнение размеров считанной матрицы A, с заданными вручную: ";
    cout << TestRows(matrix1.Rows(A), 3, matrix1.Columns(A), 3);



    return 0;
}