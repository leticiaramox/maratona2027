#include <iostream>
#include <deque>

using namespace std;



int main() {
    long long n;
    cin >> n;

    deque<char> list;
    int op;
    char val;

    long long contB = 0;
    long long contA = 0;
    long long cont = 0;
    for (long long i = 0; i < n; i++) {
        cin >> op;

        if (op == 2) {
            cin >> val;
            list.push_front(val);
            if (val == 'B') {
                contB++;
            } else {
                cont += contB;
                contA++;
            }
        } else if (op == 1) {
            cin >> val;
            list.push_back(val);
            if (val == 'B') {
                contB++;
                cont += contA;
            } else contA++;
        } else if (op == 3) {
            char popado = list.back();
            list.pop_back();
            if (popado == 'A') contA--;
            else {
                contB--;
                cont -= contA;
            }
        } else if (op == 4) {
            char popadinho = list.front();
            list.pop_front();
            if (popadinho == 'A') {
                contA--;
                cont -= contB;
            } else contB--;
        }
        cout << cont << "\n";
    }

    return 0;
}
