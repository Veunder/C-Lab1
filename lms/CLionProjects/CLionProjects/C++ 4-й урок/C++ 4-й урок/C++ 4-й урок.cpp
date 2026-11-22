#include <iostream>
#include <vector>
#define ll long long
using namespace std;
/*На вход поступает шахматная доска и нужно посчитать количество возможных ходов для белых фигур и для чёрных фигур
 * белые фигуры:
 * 0 - конь
 * 1 - ладья
 * 2 - слон
 * 3- король
 * 4 - ферзь
 * чёрные фигуры:
 * 5 - конь
 * 6 - ладья
 * 7 - слон
 * 8 - король
 * 9 - ферзь
 без учёта того становится ли король под ударом*/
bool checktask(char c[8][8], char b) {
    int x, y;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (c[i][j] == '3' && b == 'w') {
                x = i;
                y = j;
            }
            if (c[i][j] == '8' && b == 'b') {
                x = i;
                y = j;
            }
        }
    }
    vector <pair<int, int>>v = { {2,1},{-2,1},{2,-1},{-2,-1},{1,2},{1,-2},{-1,-2},{-1,2} };
    bool f = true;
    int x1, y1;
    for (auto z : v) {
        x1 = z.first + x;
        y1 = z.first + y;
        if (x1 < 8 && x1 >= 0 && y1 >= 0 && y1 < 8) {
            if (c[x1][y1] == '5' && b == 'w') {
                f = false;
                break;
            }
            if (c[x1][y1] == '0' && b == 'b') {
                f = false;
                break;
            }
        }
    }
    for (int i = x; i < 8; i++) {
        if ((c[i][y] == '6' || c[i][y] == '9') && b == 'w') {
            f = false;
            break;
        }
        if ((c[i][y] == '1' || c[i][y] == '4') && b == 'b') {
            f = false;
            break;
        }
        else if (c[i][y] <= '9' && c[i][y] >= '0') break;
    }
    for (int i = x; i >= 0; i--) {
        if ((c[i][y] == '6' || c[i][y] == '9') && b == 'w') {
            f = false;
            break;
        }
        if ((c[i][y] == '1' || c[i][y] == '4') && b == 'b') {
            f = false;
            break;
        }
        else if (c[i][y] <= '9' && c[i][y] >= '0') break;
    }
    for (int i = y; i < 8; i++) {
        if ((c[x][i] == '6' || c[x][i] == '9') && b == 'w') {
            f = false;
            break;
        }
        if ((c[x][i] == '1' || c[x][i] == '4') && b == 'b') {
            f = false;
            break;
        }
        else if (c[x][i] <= '9' && c[x][i] >= '0') break;
    }
    for (int i = y; i >= 0; i--) {
        if ((c[x][i] == '6' || c[x][i] == '9') && b == 'w') {
            f = false;
            break;
        }
        if ((c[x][i] == '1' || c[x][i] == '4') && b == 'b') {
            f = false;
            break;
        }
        else if (c[x][i] <= '9' && c[x][i] >= '0') break;
    }
    for (int i = 1; x + i < 8 && y + i < 8; i++) {
        if ((c[x + i][y + i] == '2' || c[x + i][y + i] == '4') && b == 'b') {
            f = false;
            break;
        }
        if ((c[x + i][y + i] == '7' || c[x + i][y + i] == '9') && b == 'w') {
            f = false;
            break;
        }
        else if ((c[x + i][y + i] <= '9' && c[x + i][y + i] >= '0')) break;
    }
    for (int i = 1; x + i < 8 && y - i >= 0; i++) {
        if ((c[x + i][y - i] == '2' || c[x + i][y - i] == '4') && b == 'b') {
            f = false;
            break;
        }
        if ((c[x + i][y - i] == '7' || c[x + i][y - i] == '9') && b == 'w') {
            f = false;
            break;
        }
        else if ((c[x + i][y - i] <= '9' && c[x + i][y - i] >= '0')) break;
    }
    for (int i = 1; x - i >= 8 && y - i >= 0; i++) {
        if ((c[x - i][y - i] == '2' || c[x - i][y - i] == '4') && b == 'b') {
            f = false;
            break;
        }
        if ((c[x - i][y - i] == '7' || c[x - i][y - i] == '9') && b == 'w') {
            f = false;
            break;
        }
        else if ((c[x - i][y - i] <= '9' && c[x - i][y - i] >= '0')) break;
    }
    for (int i = 1; x - i >= 0 && y + i < 8; i++) {
        if ((c[x - i][y + i] == '2' || c[x - i][y + i] == '4') && b == 'b') {
            f = false;
            break;
        }
        if ((c[x - i][y + i] == '7' || c[x - i][y + i] == '9') && b == 'w') {
            f = false;
            break;
        }
        else if ((c[x - i][y + i] <= '9' && c[x - i][y + i] >= '0')) break;
    }
    if (x + 1 < 8 && y + 1 < 8 && c[x + 1][y + 1] == 'p' && b == 'w') f = false;
    if (x - 1 >= 0 && y + 1 < 8 && c[x - 1][y + 1] == 'p' && b == 'w') f = false;
    if (x - 1 >= 0 && y - 1 >= 0 && c[x - 1][y - 1] == 'p' && b == 'b') f = false;
    if (x + 1 < 8 && y - 1 >= 0 && c[x + 1][y - 1] == 'p' && b == 'b') f = false;
    return f;
}
int main() {
    char c[8][8];
    for (int i = 0; i < 8; i++) {
        cin >> c[i];
    }
    int k1 = 0, k2 = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (c[i][j] == '0') {
                if (i + 1 < 8) {
                    if (j - 2 >= 0) k1++;
                    if (j + 2 < 8) k1++;
                }
                if (i + 2 < 8) {
                    if (j - 1 >= 0) k1++;
                    if (j + 1 < 8) k1++;
                }
                if (i - 1 > 0) {
                    if (j - 2 >= 0) k1++;
                    if (j + 2 < 8) k1++;
                }
                if (i - 2 > 0) {
                    if (j - 1 >= 0) k1++;
                    if (j + 1 < 8) k1++;
                }
            }
            if (c[i][j] == '2') {
                for (int z = 1; i + z < 8 && j + z < 8; z++) {
                    if (c[i + z][j + z] == '.') k1++;
                    else break;
                }
                for (int z = 1; i - z >= 0 && j + z < 8; z++) {
                    if (c[i - z][j + z] == '.') k1++;
                    else break;
                }
                for (int z = 1; i + z < 8 && j - z >= 0; z++) {
                    if (c[i + z][j - z] == '.') k1++;
                    else break;
                }
                for (int z = 1; i - z >= 0 && j - z >= 0; z++) {
                    if (c[i - z][j - z] == '.') k1++;
                    else break;
                }
            }
            if (c[i][j] == '1') {
                for (int z = 1; i + z < 8; z++) {
                    if (c[i + z][j] == '.') k1++;
                    else break;
                }
                for (int z = 1; i - z >= 0; z++) {
                    if (c[i - z][j] == '.') k1++;
                    else break;
                }
                for (int z = 1; j + z < 8; z++) {
                    if (c[i][j + z] == '.') k1++;
                    else break;
                }
                for (int z = 1; j - z >= 0; z++) {
                    if (c[i][j + z] == '.') k1++;
                    else break;
                }
            }
            if (c[i][j] == '3') {
                if (i - 1 >= 0 && j - 1 >= 0) k1++;
                if (j - 1 >= 0)  k1++;
                if (i + 1 < 8 && j - 1 >= 0) k1++;
                if (i + 1 < 8) k1++;
                if (i + 1 < 8 && j + 1 < 8) k1++;
                if (j + 1 < 8) k1++;
                if (i - 1 >= 0 && j + 1 < 8) k1++;
                if (i - 1 >= 0) k1++;
            }
            if (c[i][j] == '4') {
                for (int z = 1; i + z < 8; z++) {
                    if (c[i + z][j] == '.') k1++;
                    else break;
                }
                for (int z = 1; i - z >= 0; z++) {
                    if (c[i - z][j] == '.') k1++;
                    else break;
                }
                for (int z = 1; j + z < 8; z++) {
                    if (c[i][j + z] == '.') k1++;
                    else break;
                }
                for (int z = 1; j - z >= 0; z++) {
                    if (c[i][j + z] == '.') k1++;
                    else break;
                }
                for (int z = 1; i + z < 8 && j + z < 8; z++) {
                    if (c[i + z][j + z] == '.') k1++;
                    else break;
                }
                for (int z = 1; i - z >= 0 && j + z < 8; z++) {
                    if (c[i - z][j + z] == '.') k1++;
                    else break;
                }
                for (int z = 1; i + z < 8 && j - z >= 0; z++) {
                    if (c[i + z][j - z] == '.') k1++;
                    else break;
                }
                for (int z = 1; i - z >= 0 && j - z >= 0; z++) {
                    if (c[i - z][j - z] == '.') k1++;
                    else break;
                }
            }
            if (c[i][j] == '5') {
                if (i + 1 < 8) {
                    if (j - 2 >= 0) k2++;
                    if (j + 2 < 8) k2++;
                }
                if (i + 2 < 8) {
                    if (j - 1 >= 0) k2++;
                    if (j + 1 < 8) k2++;
                }
                if (i - 1 > 0) {
                    if (j - 2 >= 0) k2++;
                    if (j + 2 < 8) k2++;
                }
                if (i - 2 > 0) {
                    if (j - 1 >= 0) k2++;
                    if (j + 1 < 8) k2++;
                }
            }
            if (c[i][j] == '7') {
                for (int z = 1; i + z < 8 && j + z < 8; z++) {
                    if (c[i + z][j + z] == '.') k2++;
                    else break;
                }
                for (int z = 1; i - z >= 0 && j + z < 8; z++) {
                    if (c[i - z][j + z] == '.') k2++;
                    else break;
                }
                for (int z = 1; i + z < 8 && j - z >= 0; z++) {
                    if (c[i + z][j - z] == '.') k2++;
                    else break;
                }
                for (int z = 1; i - z >= 0 && j - z >= 0; z++) {
                    if (c[i - z][j - z] == '.') k2++;
                    else break;
                }
            }
            if (c[i][j] == '6') {
                for (int z = 1; i + z < 8; z++) {
                    if (c[i + z][j] == '.') k2++;
                    else break;
                }
                for (int z = 1; i - z >= 0; z++) {
                    if (c[i - z][j] == '.') k2++;
                    else break;
                }
                for (int z = 1; j + z < 8; z++) {
                    if (c[i][j + z] == '.') k2++;
                    else break;
                }
                for (int z = 1; j - z >= 0; z++) {
                    if (c[i][j + z] == '.') k2++;
                    else break;
                }
            }
            if (c[i][j] == '8') {
                if (i - 1 >= 0 && j - 1 >= 0) k2++;
                if (j - 1 >= 0)  k2++;
                if (i + 1 < 8 && j - 1 >= 0) k2++;
                if (i + 1 < 8) k2++;
                if (i + 1 < 8 && j + 1 < 8) k2++;
                if (j + 1 < 8) k2++;
                if (i - 1 >= 0 && j + 1 < 8) k2++;
                if (i - 1 >= 0) k2++;
            }
            if (c[i][j] == '9') {
                for (int z = 1; i + z < 8; z++) {
                    if (c[i + z][j] == '.') k2++;
                    else break;
                }
                for (int z = 1; i - z >= 0; z++) {
                    if (c[i - z][j] == '.') k2++;
                    else break;
                }
                for (int z = 1; j + z < 8; z++) {
                    if (c[i][j + z] == '.') k2++;
                    else break;
                }
                for (int z = 1; j - z >= 0; z++) {
                    if (c[i][j + z] == '.') k2++;
                    else break;
                }
                for (int z = 1; i + z < 8 && j + z < 8; z++) {
                    if (c[i + z][j + z] == '.') k2++;
                    else break;
                }
                for (int z = 1; i - z >= 0 && j + z < 8; z++) {
                    if (c[i - z][j + z] == '.') k2++;
                    else break;
                }
                for (int z = 1; i + z < 8 && j - z >= 0; z++) {
                    if (c[i + z][j - z] == '.') k2++;
                    else break;
                }
                for (int z = 1; i - z >= 0 && j - z >= 0; z++) {
                    if (c[i - z][j - z] == '.') k2++;
                    else break;
                }
            }
        }
        cout << k1 << " " << k2;
    }
    return 0;
}
