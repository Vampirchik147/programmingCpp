#include <iostream>
#include <cmath>

using namespace std;

//Работаем через структуру//

// 5 5 6 5 5 5 5 6 5 5 5 5 5 6 11 5 5

//complex Add( const& c1, const& c2);

class Complex{

    double Im, Re;
    string sign_Im, sign_Re;

public:
    Complex(){};

    Complex(double Im, double Re){
        this->Im = Im;
        this->Re = Re;

        if (Im >= 0){
            this->sign_Im = "";
        }
        else{
            this->sign_Im = "-";
        }

        if (Re >= 0){
            this->sign_Re = "+";
        }
        else{
            this->sign_Re = "-";
        }
    }

    ostream& print(ostream& os){
        os << sign_Im << abs(this->Im) << sign_Re << abs(this->Re) << "i" << endl;
    }


    void Add(Complex obj){
        this->Im += obj.Im;
        this->Re += obj.Re;

        if(Im >= 0){
            this->sign_Im = "";
        }
        else{
            this->sign_Im = "-";
        }

        if(Re >= 0){
            this->sign_Re = "";
        }
        else{
            this->sign_Re = "-";
        }

        Complex complex(Im, Re);
        complex.print(cout);
    }

    void Sub(Complex obj){
        this->Im -= obj.Im;
        this->Re -= obj.Re;

        if(Im >= 0){
            this->sign_Im = "";
        }
        else{
            this->sign_Im = "-";
        }

        if(Re >= 0){
            this->sign_Re = "";
        }
        else{
            this->sign_Re = "-";
        }

        Complex complex(Im, Re);
        complex.print(cout);
    }

    void Muv(int chislo){
        this->Im *= chislo;
        this->Re *= chislo;

        if(Im >= 0){
            this->sign_Im = "";
        }
        else{
            this->sign_Im = "-";
        }

        if(Re >= 0){
            this->sign_Re = "";
        }
        else{
            this->sign_Re = "-";
        }

        Complex complex(Im, Re);
        complex.print(cout);
    }

    void Div(int chislo){

        try {
                if(chislo == 0){
                    throw 1;
                }

            this->Im /= chislo;
            this->Re /= chislo;
        }catch (int chislo){
            cout << "Division by zero" << endl;

            return;
        }



        if(Im >= 0){
            this->sign_Im = "";
        }
        else{
            this->sign_Im = "-";
        }

        if(Re >= 0){
            this->sign_Re = "";
        }
        else{
            this->sign_Re = "-";
        }

        Complex complex(Im, Re);
        complex.print(cout);
    }

};

int main() {

    double Im_1, Im_2, Re_1, Re_2;
    int chislo;

    cout << "Enter two complex numbers: " << endl;
    cout << "\n";

    cout << "First number Im: ";
    cin >> Im_1;
    cout << "First number Re: ";
    cin >> Re_1;
    cout << "Second number Im: ";
    cin >> Im_2;
    cout << "Second number Re: ";
    cin >> Re_2;

    Complex complex_1(Im_1, Re_1);
    Complex complex_2(Im_2, Re_2);

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
                complex_1.Add(complex_2);
                break;
            case 2:
                cout << "Diff complex numbers: ";
                complex_1.Sub(complex_2);
                break;
            case 3:

                cout << "Enter chislo: ";
                cin >> chislo;
                cout << "\n";
                cout << "Mul first complex number: ";
                complex_1.Muv(chislo);

                cout << "Mul second complex number: ";
                complex_2.Muv(chislo);
                break;
            case 4:
                cout << "Enter chislo: ";
                    cin >> chislo;

                cout << "\n";

                cout << "Div first complex number: ";
                complex_1.Div(chislo);

                cout << "Div second complex number: ";
                complex_2.Div(chislo);
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