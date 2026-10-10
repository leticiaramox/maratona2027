#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <bit>

using namespace std;

const int MAX_N = 35;

long long calcularFatorial(long long n) {
    if (n < 0) return -1; 
    long long fat = 1;
    for (int i = 2; i <= n; i++) {
        fat *= i;
    }
    return fat;
}

long long possibilidades(vector<bitset<MAX_N>> &b, vector<int> &r, int m, int n) {
    long long acertos = r[0];
    for (int i = 1; i < m; i++) {
        if (r[i] - r[i - 1] > 0) {
            acertos += b[i].count();
        } else if (r[i] - r[i - 1] < 0) {
            acertos -= b[i].count();
        }
    }
    
    long long fat = calcularFatorial(acertos - 1);
    
    return fat;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<bitset<MAX_N>> binario_xor(m);
    vector<bitset<MAX_N>> binario(m);
    vector<int> result(m);
    
    string s;
    cin >> s >> result[0];
    binario_xor[0] = bitset<MAX_N>(s);
    binario[0] = bitset<MAX_N>(s);

    for (int i = 1; i < m; i++) {
        int resul;
        cin >> s >> result[i];
        bitset<MAX_N> atual(s);
    
        binario_xor[i] = atual ^ binario[i - 1];
        binario[i] = atual;
    }

    if (result[m - 1] == 0) {
        cout << "0\n";
    } else {
        long long p = possibilidades(binario_xor, result, m, n);
        cout << p << "\n";
    }

    return 0;
}
