#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long solve(int idx, long long sum1, long long sum2, const vector<long long>& a, int n) {
    if (idx == n) {
        return abs(sum1 - sum2);
    }

    long long g1 = solve(idx + 1, sum1 + a[idx], sum2, a, n);
    
    long long g2 = solve(idx + 1, sum1, sum2 + a[idx], a, n);

    return min(g1, g2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << solve(0, 0, 0, a, n) << "\n";

    return 0;
}
