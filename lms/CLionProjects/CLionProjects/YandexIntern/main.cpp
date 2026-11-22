#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

const long double EPS = 1e-18L;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Первая вводимая матрица весов
    long double w1[105][106] = {};
    // Искомый вектор
    long double x[105] = {};
    // Массив, который связывает столбцы матрицы с ведущими строками
    int where[105];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w1[i][j];
        }

        // Решаем систему Ax = -1
        w1[i][n] = -1;
    }

    // Чтение второй матрицы весов (в данном решение она не нужна)
    long long value;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> value;
        }
    }

    fill_n(where, n, -1);

    // Индекс текущей строки, в которую мы помещаем следующий ведущий элемент
    int row = 0;

    // Метод Гаусса с выбором главного элемента
    for (int col = 0; col < n && row < n; col++) {

        // Номер строки, в которой находится предполагаемый ведущий элемент
        int sel = row;

        for (int i = row + 1; i < n; i++) {
            if (fabsl(w1[i][col]) > fabsl(w1[sel][col])) {
                sel = i;
            }
        }

        if (fabsl(w1[sel][col]) < EPS) {
            continue;
        }

        for (int j = 0; j <= n; j++) {
            swap(w1[sel][j], w1[row][j]);
        }

        where[col] = row;

        // Ведущий элемент текущей строки
        long double div = w1[row][col];

        for (int j = col; j <= n; j++) {
            w1[row][j] /= div;
        }

        for (int i = 0; i < n; i++) {
            if (i == row) continue;

            // Коэффициент исключения переменной
            long double factor = w1[i][col];

            for (int j = col; j <= n; j++) {
                w1[i][j] -= factor * w1[row][j];
            }
        }

        row++;
    }

    // Если матрица вырождена
    if (row < n) {

        int free_col = 0;

        while (where[free_col] != -1) {
            free_col++;
        }

        x[free_col] = 1;

        for (int j = 0; j < n; j++) {
            if (where[j] != -1) {
                x[j] = -w1[where[j]][free_col];
            }
        }

    } else {

        // Матрица невырождена
        for (int j = 0; j < n; j++) {
            x[j] = w1[where[j]][n];
        }
    }

    // Нормализуем вектор
    long double mx = 0;

    for (int i = 0; i < n; i++) {
        mx = max(mx, fabsl(x[i]));
    }

    for (int i = 0; i < n; i++) {
        x[i] /= mx;
    }

    cout << "YES\n";
    cout << fixed << setprecision(20);

    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }

    cout << '\n';

    return 0;
}