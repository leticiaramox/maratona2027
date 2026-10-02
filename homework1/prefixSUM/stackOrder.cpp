#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<long long> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());

    vector<long long> B;      
    vector<string> moves;    
    int next = 0;              
    int movimentos = 0;

    for (int i = n - 1; i >= 0; i--) {
        long long x = arr[i];

        if (x == sorted_arr[next]) {
            moves.push_back("A C");
            next++;
            movimentos++;

            while (!B.empty() && next < n && B.back() == sorted_arr[next]) {
                moves.push_back("B C");
                B.pop_back();
                next++;
                movimentos++;
            }
        } else {
            moves.push_back("A B");
            B.push_back(x);
            movimentos++;
        }
    }

    if (!B.empty()) {
        cout << -1 << "\n";
        return 0;
    }

    cout << movimentos << "\n";
    for (const string& m : moves) cout << m << "\n";
    return 0;
}
