#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;
int n;
long long q;

int a[200010];

int f(long long m) {
    long long sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += m / a[i];
        if (sum >= q) return 1;
    }
    
    return 0;
}

long long bs(long long l = 1, long long r = 1000000000000000000) {
    long long ans = -1;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (f(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
       
    cin >> n >> q;
    
    for (int i = 0; i < n; i++) cin >> a[i];
    
    cout << bs() << "\n";
    
    return 0;
}
