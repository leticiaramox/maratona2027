#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    map<long long, long long> freq;   
    freq[0] = 1;

    long long pre = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        pre += a;
        auto it = freq.find(pre - x);
        if (it != freq.end()) ans += it->second;
        freq[pre]++;
    }
     cout << ans << "\n";
    return 0;
}
