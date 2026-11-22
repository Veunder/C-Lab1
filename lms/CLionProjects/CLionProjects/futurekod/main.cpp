#include <iostream>
#include <vector>

int main() {
    int q, n, a;
    std::cin >> q;
    for (int i = 0; i <= q; i++) {
        std::cin >> n;
        int min = 99999;
        int max = 0;
        for (int j = 0; j <= n; j++) {
            std::cin >> a;
            if (a > max){
                max = a;
            }
            if (a < min){
                min = a;
            }
        }
        std::cout << max - min;
    }
};