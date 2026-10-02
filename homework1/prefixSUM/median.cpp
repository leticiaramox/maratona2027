#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> num(n);
    for (int i = 0; i < n; i++) cin >> num[i];
    
    for (int i = 0; i <= n - k; i++) {
        vector<long long> subarr(num.begin() + i, num.begin() + i + k);

        sort(subarr.begin(), subarr.end());
        long long median = subarr[(k - 1) / 2];

        cout << median << " ";
    }
    cout << "\n";

    return 0;
}
