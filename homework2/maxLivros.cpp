#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long t;
    cin >> n >> t;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 0;
    long long soma_tempo = 0;
    int max_livros = 0;

    for (int right = 0; right < n; right++) {
        soma_tempo += a[right];

        while (soma_tempo > t) {
            soma_tempo -= a[left];
            left++;
        }

        max_livros = max(max_livros, right - left + 1);
    }

    cout << max_livros << "\n";

    return 0;
}
