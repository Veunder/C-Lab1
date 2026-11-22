#include <iostream>
#define forn(i,n) for (int i=0;i<int(n);i++)
using namespace std;
char a[3][3];
void print() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}
void pole() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = '.';
            cout << a[i][j];
        }
        cout << "\n";
    }
}
void your_turn() {
    cout << "Enter cell:  ";
    int n;
    cin >> n;
    cout << "\n";
    n--;
    if (a[n / 3][n % 3] == '.') {
        a[n / 3][n % 3] = '0';
        print();
    }
    else {
        cout << "Error\n";
        your_turn();
    }
}

void move_computer() {
    //проверяем главную диагональ
    int k1 = 0;
    int k2 = 0;
    for (int i = 0; i < 3; i++) {
        if (a[i][i] == '0') k1++;
        else if (a[i][i] == 'X') k2++;
    }
    if (k2 == 2 and k1 == 0) {
        for (int i = 0; i < 3; i++) a[i][i] == 'X';
        print();
        return;
    }
    if (k1 == 2 and k2 == 0) {
        for (int i = 0; i < 3; i++) {
            if (a[i][i] == '.') a[i][i] = 'X';
        }
        print();
        return;
    }


    //проверяем побочную диагональ
    k1 = 0;
    k2 = 0;
    for (int i = 0; i < 3; i++) {
        if (a[i][2 - i] == '0') k1++;
        else if (a[i][2 - i] == 'X') k2++;
    }
    if (k2 == 2 and k1 == 0) {
        for (int i = 0; i < 3; i++) a[i][2 - i] == 'X';
        print();
        return;
    }
    if (k1 == 2 and k2 == 0) {
        for (int i = 0; i < 3; i++) {
            if (a[i][2 - i] == '.') a[i][2 - i] = 'X';
        }
        print();
        return;
    }


    //проверяем строки
    for (int i = 0; i < 3; i++) {
        k1 = 0;
        k2 = 0;
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == '0') k1++;
            if (a[i][j] == 'X') k2++;
        }
        if (k1 == 2 and k2 == 0) {
            for (int j = 0; j < 3; j++) {
                if (a[i][j] == '.') a[i][j] = 'X';
            }
            print();
            return;
        }
        if (k2 == 2 and k1 == 0) {
            for (int j = 0; j < 3; j++) a[i][j] = 'X';
            print();
            return;
        }
    }


    //проверяем столбцы
    for (int i = 0; i < 3; i++) {
        k1 = 0;
        k2 = 0;
        for (int j = 0; j < 3; j++) {
            if (a[j][i] == '0') k1++;
            if (a[j][i] == 'X') k2++;
        }
        if (k1 == 2 and k2 == 0) {
            for (int j = 0; j < 3; j++) {
                if (a[j][i] == '.') a[j][i] = 'X';
            }
            print();
            return;
        }
        if (k2 == 2 and k1 == 0) {
            for (int j = 0; j < 3; j++) a[j][i] = 'X';
            print();
            return;
        }
    }


    //просто ход компьютера если он не может победить или проиграть на этом/следующем ходу
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == '.') {
                a[i][j] = 'X';
                print();
                return;
            }
        }
    }
}
bool win(char c) {
    bool f1 = false, f2 = false;
    //для 0

    //проверяем диагонали
    if (a[0][0] == '0' and a[1][1] == '0' and a[2][2] == '0') f1 = true;
    if (a[0][2] == '0' and a[1][1] == '0' and a[2][0] == '0') f1 = true;

    //проверяем столбцы
    if (a[0][0] == '0' and a[1][0] == '0' and a[2][0] == '0') f1 = true;
    if (a[0][1] == '0' and a[1][1] == '0' and a[2][1] == '0') f1 = true;
    if (a[0][2] == '0' and a[1][2] == '0' and a[2][2] == '0') f1 = true;

    //проверяем строки
    if (a[0][0] == '0' and a[0][1] == '0' and a[0][2] == '0') f1 = true;
    if (a[1][0] == '0' and a[1][1] == '0' and a[1][2] == '0') f1 = true;
    if (a[2][0] == '0' and a[2][1] == '0' and a[2][2] == '0') f1 = true;

    //для     X
    //проверяем диагонали
    if (a[0][0] == 'X' and a[1][1] == 'X' and a[2][2] == 'X') f2 = true;
    if (a[0][2] == 'X' and a[1][1] == 'X' and a[2][0] == 'X') f2 = true;

    //проверяем столбцы
    if (a[0][0] == 'X' and a[1][0] == 'X' and a[2][0] == 'X') f2 = true;
    if (a[0][1] == 'X' and a[1][1] == 'X' and a[2][1] == 'X') f2 = true;
    if (a[0][2] == 'X' and a[1][2] == 'X' and a[2][2] == 'X') f2 = true;

    //проверяем строки
    if (a[0][0] == 'X' and a[0][1] == 'X' and a[0][2] == 'X') f2 = true;
    if (a[1][0] == 'X' and a[1][1] == 'X' and a[1][2] == 'X') f2 = true;
    if (a[2][0] == 'X' and a[2][1] == 'X' and a[2][2] == 'X') f2 = true;
    if (f1) {
        cout << "You win\n";
        return false;
    }
    else if (f2) {
        cout << "You lose\n";
        return false;
    }
    else {
        bool flag = false;
        //проверяем может ли кто-то выиграть в будущем
        if (c == 'X') {
            int k = 0;
            for (int i = 0; i < 3; i++) {
                f1 = true; f2 = true;
                for (int j = 0; j < 3; j++) {
                    if (a[i][j] == '0') f1 = false;
                    if (a[j][i] == '0') f2 = false;
                }
                if (f1) k++;
                if (f2) k++;
            }
            f1 = true, f2 = true;
            for (int i = 0; i < 3; i++) {
                if (a[i][i] == '0') f1 = false;
                if (a[i][2 - i] == '0') f2 = false;
            }
            if (f1) k++;
            if (f2) k++;
            if (k > 0) {
                flag = true;
            }
            else {
                bool f1, f2;
                for (int i = 0; i < 3; i++) {
                    f1 = true; f2 = true;
                    for (int j = 0; j < 3; j++) {
                        if (a[i][j] == 'X') f1 = false;
                        if (a[j][i] == 'X') f2 = false;
                    }
                    if (f1 || f2) k++;
                }
                f1 = true; f2 = true;
                for (int i = 0; i < 3; i++) {
                    if (a[i][i] == 'X') f1 = false;
                    if (a[i][2 - i] == 'X') f2 = false;
                }
                if (f1 || f2) k++;
                int count = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (a[i][j] == '.') count++;
                    }
                }
                if (k > 0 && count >= 2) flag = true;
            }
        }
        else {
            int k = 0;
            bool f1, f2;
            for (int i = 0; i < 3; i++) {
                f1 = true;
                f2 = true;
                for (int j = 0; j < 3; j++) {
                    if (a[i][j] == 'X') f1 = false;
                    if (a[i][j] == 'X') f2 = false;
                }
                if (f1 || f2) {
                    k++;
                }
            }
            f1 = true; f2 = true;
            for (int i = 0; i < 3; i++) {
                if (a[i][i] == 'X') f1 = false;
                if (a[i][2 - i] == 'X') f1 = false;
            }
            if (f1 || f2) k++;
            if (k > 0) flag = true;
            else {
                bool f1, f2;
                for (int i = 0; i < 3; i++) {
                    f1 = true; f2 = true;
                    for (int j = 0; j < 3; j++) {
                        if (a[i][j] == '0') f1 = false;
                        if (a[j][i] == '0') f2 = false;
                    }
                    if (f1 || f2) k++;
                }
                f1 = true; f2 = true;
                for (int i = 0; i < 3; i++) {
                    if (a[i][i] == '0') f1 = false;
                    if (a[i][2 - i] == '0') f2 = false;
                }
                if (f1 || f2) k++;
                int count = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (a[i][j] == '.') count++;
                    }
                }
                if (k > 0 && count >= 2) flag = true;
            }
        }
        return flag;
    }
}
void game() {
    pole();
    while (win('0')) {
        your_turn();
        if (!win('X')) {
            break;
        }
        move_computer();
    }
}
int main() {
    game();
    return 0;
}