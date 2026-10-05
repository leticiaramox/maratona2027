#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    int m, q;

    cin >> n >> m >> q;

    vector<long long> quart(m);
    for (int i = 0; i < m; i++) {
        cin >> quart[i];
    }

    sort(quart.begin(), quart.end());

    vector<int> diff(m + 1, 0);

    for (int i = 0; i < q; i++) {
        long long f, l;
        cin >> f >> l;

        auto it1 = lower_bound(quart.begin(), quart.end(), f);
        auto it2 = upper_bound(quart.begin(), quart.end(), l);

        int idx1 = distance(quart.begin(), it1);
        int idx2 = distance(quart.begin(), it2);

        if (idx1 < idx2) {
            diff[idx1] ^= 1;
            diff[idx2] ^= 1;
        }
    }

    int estado_atual = 0;
    int cont = 0;

    for (int i = 0; i < m; i++) {
        estado_atual ^= diff[i];
        if (estado_atual == 1) {
            cont++;
        }
    }

    cout << cont << "\n";

    return 0;
}
