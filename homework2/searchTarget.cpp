#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long long, int>> a;

// Busca binaria para encontrar o elemento complemento 'target'
int bs(int l, int r, int original_idx, long long target) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (a[mid].first == target) {
            // Se encontrou o valor, verifica se nao e o proprio elemento (mesmo indice original)
            if (a[mid].second != original_idx) {
                return a[mid].second;
            }
            // Se for o mesmo elemento, verifica os vizinhos imediatos caso haja duplicatas
            if (mid + 1 <= r && a[mid + 1].first == target) return a[mid + 1].second;
            if (mid - 1 >= l && a[mid - 1].first == target) return a[mid - 1].second;
            
            return -1;
        }

        if (a[mid].first < target) {
            l = mid + 1; // Busca na metade direita
        } else {
            r = mid - 1; // Busca na metade esquerda
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long s;
    cin >> n >> s;

    a.resize(n);
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        a[i] = {num, i};
    }

    sort(a.begin(), a.end());
    int ans;

    for (int i = 0; i < n; i++) {
        long long target = s - a[i].first;
        
        int idx = bs(0, n - 1, a[i].second, target);
        ans = idx;

        if (idx != -1) {
            if (a[i].second > idx) {
                int hold = a[i].second;
                a[i].second = idx;
                idx = hold;
            }
            cout << a[i].second + 1 << " " << idx + 1 << "\n";
            break;
        }
    }
    
    if (ans == -1) {
        cout << "IMPOSSIBLE" << "\n";
    }

    return 0;
}
