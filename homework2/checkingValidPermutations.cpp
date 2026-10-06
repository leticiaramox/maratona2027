#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> sets(m, 0);

    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int val;
            cin >> val;
            sets[i] |= (1 << (val - 1));
        }
    }

    int target_mask = (1 << n) - 1;
    int valid_combinations = 0;

    for (int mask = 1; mask < (1 << m); mask++) {
        int combined_or = 0;

        for (int i = 0; i < m; i++) {
            if (mask & (1 << i)) {
                combined_or |= sets[i];
            }
        }

        if (combined_or == target_mask) {
            valid_combinations++;
        }
    }

    cout << valid_combinations << "\n";

    return 0;
}f
