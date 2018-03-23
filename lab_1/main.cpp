#include <iostream>

using namespace std;

template <typename T>

class Print_Size{
    private:
        T element;
    public:
        Print_Size(T element): element(element){}

        T print_size(){
            cout << "The size of the variable type " << element << ": " << sizeof(T) << endl;
        }



};


int main() {

    int a1;
    char a2;
    short a3;
    long a4;
    float a5;
    double a6;
    unsigned char a7;
    unsigned short a8;
    unsigned int a9;
    unsigned long a10;
    long double a11;

    cout << "Enter a value for the type variable int: " << endl;
    cin >> a1;
    Print_Size<int> type_print_1(a1);
    type_print_1.print_size();

    cout << "Enter a value for the type variable char: " << endl;
    cin >> a2;
    Print_Size<char> type_print_2(a2);
    type_print_2.print_size();

    cout << "Enter a value for the type variable short: " << endl;
    cin >> a3;
    Print_Size<short> type_print_3(a3);
    type_print_3.print_size();

    cout << "Enter a value for the type variable long: " << endl;
    cin >> a4;
    Print_Size<long> type_print_4(a4);
    type_print_4.print_size();

    cout << "Enter a value for the type variable float: " << endl;
    cin >> a5;
    Print_Size<float> type_print_5(a5);
    type_print_5.print_size();

    cout << "Enter a value for the type variable double: " << endl;
    cin >> a6;
    Print_Size<double> type_print_6(a6);
    type_print_6.print_size();

    cout << "Enter a value for the type variable unsigned char: " << endl;
    cin >> a7;
    Print_Size<unsigned char> type_print_7(a7);
    type_print_7.print_size();

    cout << "Enter a value for the type variable unsigned short: " << endl;
    cin >> a8;
    Print_Size<unsigned short> type_print_8(a8);
    type_print_8.print_size();

    cout << "Enter a value for the type variable unsigned int: " << endl;

    cin >> a9;
    Print_Size<unsigned int> type_print_9(a9);
    type_print_9.print_size();

    cout << "Enter a value for the type variable unsigned long: " << endl;
    cin >> a10;
    Print_Size<unsigned long> type_print_10(a10);
    type_print_10.print_size();

    cout << "Enter a value for the type variable long double: " << endl;
    cin >> a11;
    Print_Size<long double> type_print_11(a11);
    type_print_11.print_size();

    return 0;
}
