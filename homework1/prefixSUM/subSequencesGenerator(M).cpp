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
}#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int counter(vector<long long>& sub, int n, int target) {
    priority_queue<long long, vector<long long>, greater<long long>> pq; 
    long long soma_atual = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        long long potion = sub[i];
        soma_atual += potion;
        pq.push(potion);
        count++;

        if (soma_atual > target) {
            if (!pq.empty()) {
                soma_atual -= pq.top();
                pq.pop();
                count--;
            }
        }
    }

    return count;
}

int main() {
    int n, s;
    cin >> n >> s;
    
    vector<long long> num(n);
    long long soma = 0;
    for (int i = 0; i < n; i++) {
        cin >>num[i];
        soma += num[i];
    }
    
    int ajuste = 0;
    if (soma == s) ajuste = -1;
    
    cout << counter(num, n, s) + ajuste << endl; 
    
}
