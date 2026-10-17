#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // Otimização de entrada/saída
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> p(n + 1);
    bool unique = true;
    int current_val = 1;

    while (!q.empty()) {
        // Se houver mais de um nó com grau de entrada 0 ao mesmo tempo,
        // significa que a ordem não é única.
        if (q.size() > 1) {
            unique = false;
        }

        int u = q.front();
        q.pop();

        p[u] = current_val++;

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Se não conseguimos processar todos os nós (ciclo ou grafo desconexo sem ordem total)
    if (current_val <= n) {
        cout << "No\n";
        return 0;
    }

    if (!unique) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        for (int i = 1; i <= n; i++) {
            cout << p[i] << (i == n ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
