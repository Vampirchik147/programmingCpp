#include <iostream>
#include <cmath>

using namespace std;

class Complex{
private:
    double Im, Re;
public:
    Complex():Re(0.0),Im(0.0){};
    Complex(double re, double im): Re(re), Im(im){}

    void print(ostream& os){
        if(Im < 0){
            os << Re << Im << "i" << endl;
        }else{
            os << Re <<"+"<< Im << "i" << endl;
        }
    }


    Complex add(const Complex& other){
        return Complex(Re+other.Re, Im+other.Im);
    }
    Complex sub(const Complex& other){
        return Complex(Re-other.Re, Im-other.Im);
    }
    Complex mul(int number){
        return Complex(Re*number, Im*number);
    }
    Complex div(int number){
        try{
            if(number == 0){
                throw 1;
            }
            Re = Re/number;
            Im = Im/number;
        }catch (int number){
            cout << "Division by zero" << endl;

        }
        return Complex(Re, Im);
    }

};

int main() {

    double Im_1, Im_2, Re_1, Re_2;
    int chislo;

    cout << "Enter two complex numbers: " << endl;
    cout << "\n";

    cout << "First number Re, Im: ";
    cin >> Re_1 >> Im_1;

    cout << "Second number Re, Im: ";
    cin >> Re_2 >> Im_2;

    Complex complex_1(Re_1, Im_1);
    Complex complex_2(Re_2, Im_2);

    Complex complex;

    cout << "\n";
    cout << "First complex number: ";
    complex_1.print(cout);

    cout << "Second complex number: ";
    complex_2.print(cout);
    cout << "\n";


    char answer = 'y';

    while(answer == 'y'){

        cout << "Перечень методов: \n\t 1) сложить два числа \n\t 2) вычестить из первого второе"
                "\n\t 3) умножить комплексное число на число типа int \n\t 4) разделить комплексное число на число "
                "типа int \n Ваш выбор: ";
        int choose;
        cin >> choose;
        cout << "\n";

        switch(choose){
            case 1:
                cout << "Add complex numbers: ";
                complex_1.add(complex_2).print(cout);
                break;
            case 2:
                cout << "Diff complex numbers: ";
                complex_1.sub(complex_2).print(cout);
                break;
            case 3:

                cout << "Enter chislo: ";
                cin >> chislo;
                cout << "\n";
                cout << "Mul first complex number: ";
                complex_1.mul(chislo).print(cout);

                cout << "Mul second complex number: ";
                complex_2.mul(chislo).print(cout);
                break;
            case 4:
                cout << "Enter chislo: ";
                    cin >> chislo;

                cout << "\n";

                cout << "Div first complex number: ";
                complex_1.div(chislo).print(cout);

                cout << "Div second complex number: ";
                complex_2.div(chislo).print(cout);
                break;
            default:
                cout<<"Такого метода нет";
        }
        cout << "\n";

        cout << "Хотите вернуть к списку методов? [y/n] ";
        cin >> answer;
        cout << "\n";
    }
    return 0;
}