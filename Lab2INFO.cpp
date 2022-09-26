
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    while (true) {
        int Prov = 0;
        setlocale(LC_ALL, "Russian");
        cout << "Введите код для декодирования(7 символов):" << endl;
        string Stroka;
        cin >> Stroka;
        if (Stroka.length() != 7) {
            cout << "Неверные данные" << endl;
            
        }
        else {

            char InputStr[1024];
            strncpy_s(InputStr, Stroka.c_str(), sizeof(InputStr));
            InputStr[sizeof(InputStr) - 1] = 0;

            for (int i = 0; i < 7; i++) {
                //  cin >> InputStr[i];
                if (InputStr[i] != '0' && InputStr[i] != '1') {
                    
                    Prov = 1;
                }

            }
            if (Prov == 1) {
                cout<< "Неверные данные" << endl;
            }
            else {
                int Number[7];
                for (int i = 0; i < 7; i++) {
                    Number[i] = int(InputStr[i]) - 48;

                }
                int ProvBit[3];
                int WrongBit = 0;
                ProvBit[0] = (Number[2] + Number[4] + Number[6]) % 2;
                ProvBit[1] = (Number[2] + Number[5] + Number[6]) % 2;
                ProvBit[2] = (Number[4] + Number[5] + Number[6]) % 2;
                if (ProvBit[0] != Number[0]) {
                    WrongBit += 1;
                }
                if (ProvBit[1] != Number[1]) {
                    WrongBit += 2;
                }
                if (ProvBit[2] != Number[3]) {
                    WrongBit += 4;
                }
                if (WrongBit != 0) {
                    Number[WrongBit - 1] = 1 - (Number[WrongBit - 1] % 2);
                }

                if (WrongBit == 0) {
                    cout << "все правильно, ни единой ошибки"<<endl;
                }
                else {
                    cout << "ошибка в бите под номером:" << WrongBit << endl;
                    cout << "информационные биты:" << Number[2] << Number[4] << Number[5] << Number[6] << endl;
                }
            }
        }
    }
}

