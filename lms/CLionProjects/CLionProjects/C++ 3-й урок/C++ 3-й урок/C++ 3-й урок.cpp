#include <iostream>
#include <clocale> // Для русского языка в консоли

using namespace std;

#include <iostream>
using namespace std;
/*3-х значное число, есть 3 попытки
 пользователь вводит тоже 3-х значное число
 если он угадал какую-то цифру, то если её место в его числе совпало с местом в нашем числе, то мы выводим горячо, если просто есть такая цифра, то тепло
 иначе холодно
 */
void again();
void game() {
    srand(time(0));
    int a = rand() % 900 + 100;
    int k = 0;
    while (k != 3) {
        cout << "Введите число:\n";
        int b = 0;
        cin >> b;
        if (a == b) {
            cout << "Ты выйграл(а)\n";
            again();
            return;
        }
        else {
            int z = b;
            int x = a;
            bool f = false;
            while (b != 0) {
                if (b % 10 == a % 10) {
                    cout << "Горячо\n";
                    f = true;
                    break;
                }
                b /= 10;
                a /= 10;
            }
            if (!f) {
                b = z;
                a = x;
                while (b != 0 && !f) {
                    int ost = b % 10;
                    a = x;
                    while (a != 0) {
                        if (a % 10 == ost) {
                            cout << "Тепло\n";
                            f = true;
                            break;
                        }
                        a /= 10;
                    }
                    b /= 10;
                }
            }
        }
        k += 1;
    }
    cout << "Ты проиграл(а)\n";
    again();
}
void again() {
    cout << "Если хочешь сыграть ещё раз, то напиши какой-нибудь символ, а если нет, то просто -\n";
    char c;
    cin >> c;
    if (c != '-') game();
    else {
        cout << "Пока\n";
    }
}

int main()
{
	setlocale(LC_ALL, "Russian"); // Для русского языка в консоли
	/*
	Указатели:
		int* b;
		int a = 0;
		b = &a;
		++*b;
		cout << *b;
	*/
    game();
}