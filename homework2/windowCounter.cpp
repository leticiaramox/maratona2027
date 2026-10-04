#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long l, r, x;
    if (!(cin >> n >> l >> r >> x)) return 0;

    vector<long long> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int total_validos = 0;

    // Itera por todos os 2^N subconjuntos possiveis
    for (int mask = 0; mask < (1 << n); mask++) {
        // Conta quantos elementos estao no subconjunto atual
        if (__builtin_popcount(mask) < 2) continue;

        long long soma = 0;
        long long min_val = 1e18, max_val = -1e18;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                soma += p[i];
                min_val = min(min_val, p[i]);
                max_val = max(max_val, p[i]);
            }
        }

        // Verifica as condicoes do problema
        if (soma >= l && soma <= r && (max_val - min_val) >= x) {
            total_validos++;
        }
    }

    cout << total_validos << "\n";

    return 0;
}
