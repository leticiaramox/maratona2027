#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visitados(n + 1, false);
    vector<int> reps;  

    for (int i = 1; i <= n; i++) { // DFS iterativa
        if (visitados[i]) continue;
        reps.push_back(i);

        stack<int> st;
        st.push(i);
        visitados[i] = true;
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            for (int v : adj[u]) {
                if (!visitados[v]) {
                    visitados[v] = true;
                    st.push(v);
                }
            }
        }
    }

    cout << reps.size() - 1 << "\n";
    for (size_t i = 0; i + 1 < reps.size(); i++) {
        cout << reps[i] << " " << reps[i + 1] << "\n";
    }

    return 0;
}
