#include <iostream>
#include <cmath>

int main() {
    int A, B;
    std::cin >> A >> B;

    int X, Y;
    if (A == 0) {
        X = 1;
        Y = -B;
    } else if (B == 0) {
        X = -A;
        Y = 1;
    } else {
        double k = std::sqrt(B * B - A * A);
        X = std::round(k - B);
        Y = std::round(A / (k - B));
    }

    if (std::abs(X) <= 10000 && std::abs(Y) <= 10000) {
        std::cout << X << " " << Y;
    } else {
        std::cout << "0 0";
    }

    return 0;
}
