#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int canPlace(const vector<long long> &cows, int c, long long dist) {
    int count = 1; 
    long long last_pos = cows[0];

    for (size_t i = 1; i < cows.size(); i++) {
        if (cows[i] - last_pos >= dist) {
            count++;
            last_pos = cows[i];
            if (count >= c) return 1; 
        }
    }

    return 0;
}

long long maxMinDistance(vector<long long> &cows, int c) {
    long long low = 1;
    long long high = cows.back() - cows.front();
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (canPlace(cows, c, mid)) {
            ans = mid;   
            low = mid + 1;
        } else {
            high = mid - 1; 
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, c;
        cin >> n >> c;

        vector<long long> cows(n);
        for (int j = 0; j < n; j++) cin >> cows[j];

        sort(cows.begin(), cows.end());

        cout << maxMinDistance(cows, c) << "\n";
    }

    return 0;
}
