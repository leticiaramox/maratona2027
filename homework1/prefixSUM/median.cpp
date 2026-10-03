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






#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> num(n);
    for (int i = 0; i < n; i++) cin >> num[i];

    multiset<long long> ms;

    // 1. Insert initial window of size K
    for (int i = 0; i < k; i++) {
        ms.insert(num[i]);
    }

    // 2. Set 'mid' iterator to the lower median at index (k - 1) / 2
    auto mid = next(ms.begin(), (k - 1) / 2);

    cout << *mid;

    // 3. Slide the window across the array
    for (int i = k; i < n; i++) {
        long long to_add = num[i];
        long long to_remove = num[i - k];

        // --- INSERTION ---
        ms.insert(to_add);
        if (to_add < *mid) {
            mid--; // Shift left if new value is smaller than current median
        }

        // --- REMOVAL ---
        if (to_remove <= *mid) {
            mid++; // Advance 'mid' BEFORE erasing to avoid iterator invalidation
        }
        ms.erase(ms.find(to_remove)); // Remove one instance of the old element

        cout << " " << *mid;
    }
    cout << "\n";

    return 0;
}
