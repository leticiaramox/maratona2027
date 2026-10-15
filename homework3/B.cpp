#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int passos = 0;
    while (m > n) {
        if (m % 2 == 0) m /= 2;
        else m += 1;
        passos++;
    }

    cout << passos + (n - m) << "\n";
    return 0;
}
