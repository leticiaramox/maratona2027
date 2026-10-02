#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maximizePotions(vector<long long>& potions, int n) {
    priority_queue<long long, vector<long long>, greater<long long>> pq; 
    long long saude_atual = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        long long potion = potions[i];
        saude_atual += potion;
        pq.push(potion);
        count++;

        if (saude_atual < 0) {
            if (!pq.empty()) {
                saude_atual -= pq.top();
                pq.pop();
                count--;
            }
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    
    vector<long long> poc(n);
    for (int i = 0; i < n; i++) cin >> poc[i];
    
    cout << maximizePotions(poc, n) << endl; 
    return 0;
}
