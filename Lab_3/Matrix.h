//
// Created by levin on 19.04.18.
//

#ifndef INC_46546554_MATRIX_H
#define INC_46546554_MATRIX_H
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;
//списко инициализаторов


template <class TYPE>
class Matrix{
private:
    TYPE **arr;
    unsigned int rows;
    unsigned int columns;
public:
    Matrix(){}
    Matrix(int row, int cols): rows(row), columns(cols){
        arr = new TYPE*[row];
        for(int i = 0; i < row; i++){
            arr[i] = new TYPE[cols]{};
        }
    }

    ~Matrix(){
//        for(int i = 0; i < rows; i++){
//            delete[] arr[i];
//        }
//        delete[] arr;
    }

    int Rows(string filename){
        ifstream file(filename);

        if (!file.is_open()){
            cout << "ERROR";
        }else{
            file >> rows;
        }
        file.close();
        return rows;
    }

     int Columns(string filename){
        ifstream file(filename);

        if (!file.is_open()){
            cout << "ERROR";
        }else{
            file >> rows >> columns;
        }
        file.close();
        return columns;
    }



    void Read(string filename){
        ifstream file(filename);

        if (!file.is_open()){
            cout << "ERROR";
        }else{
            file >> rows >> columns;

            arr = new TYPE*[rows];
            for(int i = 0; i < rows; i++){
                arr[i] = new TYPE[columns];
            }

            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++){
                    file >> arr[i][j];
                }
            }
        }
        file.close();
    }

    void Print(){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                cout << arr[i][j] << " ";
            }
            cout<<endl;
        }
    }

    Matrix operator+(Matrix &other)const {
        assert(rows == other.rows && columns == other.columns);
        Matrix result(other.rows, other.columns);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                result.arr[i][j] = arr[i][j] + other.arr[i][j];
            }
        }
        return result;
    }

    Matrix operator-(Matrix &other)const {
        assert(rows == other.rows && columns == other.columns);
        Matrix result(other.rows, other.columns);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                result.arr[i][j] = arr[i][j] - other.arr[i][j];
            }
        }
        return result;
    }

    Matrix operator*(Matrix &other)const {
        assert(columns == other.rows);
            Matrix result(rows, other.columns);
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < other.columns; j++){
                    int tmp = 0;
                    for(int t = 0; t < columns; t++){
                        tmp += arr[i][t]*other.arr[t][j];
                    }
                    result.arr[i][j] = tmp;
                }
            }
            return result;
        }

    bool operator==(Matrix &other)const {
        int k = 0;
        assert(rows == other.rows && columns == other.columns);
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                if(arr[i][j] == other.arr[i][j]){
                    k++;
                }
            }
        }
        int p = rows*columns;
        if(k == p){
            return true;
        }else{
            return false;
        }
    }

    Matrix Transp()const {
        Matrix result(columns, rows);
        for (int i = 0; i < rows; i++){
            for( int j = 0; j < columns; j++){
                result.arr[j][i] = arr[i][j];
            }
        }
        return result;
    }
};

string TestRows(int row1, int row2, int col1, int col2){
    assert(row1 == row2);
    assert(col1 == col2);
    return "Равны\n";
}

#endif //INC_46546554_MATRIX_H
