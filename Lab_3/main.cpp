#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

template <class TYPE>
class Matrix{
private:
    TYPE **arr;
    int rows;
    int columns;
public:
    Matrix(){}
    Matrix(int row, int cols): rows(row), columns(cols){
        arr = new TYPE*[row];
        for(int i = 0; i < row; i++){
            arr[i] = new TYPE[cols]{};
        }
    }

    ~Matrix(){}

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


int main() {

    string A = "/Users/levin/Sveta/ИУ10-41/C++/Lab_3/A.txt";
    string B = "/Users/levin/Sveta/ИУ10-41/C++/Lab_3/B.txt";
    string C = "/Users/levin/Sveta/ИУ10-41/C++/Lab_3/C.txt";
    string D = "/Users/levin/Sveta/ИУ10-41/C++/Lab_3/D.txt";

    Matrix<int> matrix1;
    Matrix<int> matrix2;
    Matrix<int> matrix3;
    Matrix<int> matrix4;
    Matrix<int> matrix5;
    Matrix<int> matrix6;
    Matrix<int> matrix7;
    Matrix<int> matrix8;
    Matrix<int> matrix9;

    cout << "Matrix A:" << endl;
    matrix1.Read(A);
    matrix1.Print();

    cout << "\nMatrix B:" << endl;
    matrix2.Read(B);
    matrix2.Print();

    cout << "\nMatrix A + Matrix B:" << endl;
    matrix3 = matrix1 + matrix2;
    matrix3.Print();


    cout << "\nMatrix A - Matrix B:" << endl;
    matrix4 = matrix1 - matrix2;
    matrix4.Print();

    cout << "\nMatrix A * Matrix B:" << endl;
    matrix5 = matrix1 * matrix2;
    matrix5.Print();

    cout << "\nMatrix C:" << endl;
    matrix6.Read(C);
    matrix6.Print();

    cout << "\nMatrix C -> Transpont:" << endl;
    matrix7 = matrix6.Transp();
    matrix7.Print();


    return 0;
}
