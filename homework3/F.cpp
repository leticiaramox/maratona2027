#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Função DFS para calcular as distâncias a partir de um nó raiz
void dfs(int u, int p, int d, const vector<vector<int>>& adj, vector<int>& dist) {
    dist[u] = d;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1, adj, dist);
        }
    }
}

int main() {
    // Otimização de E/S para garantir rapidez com 2 * 10^5 nós
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }

    // 1. Encontra a primeira ponta do diâmetro (A) a partir do nó 1
    vector<int> dist1(n + 1, 0);
    dfs(1, 0, 0, adj, dist1);

    int A = 1;
    for (int i = 1; i <= n; i++) {
        if (dist1[i] > dist1[A]) {
            A = i;
        }
    }

    // 2. Encontra a outra ponta do diâmetro (B) e calcula distâncias a partir de A
    vector<int> distA(n + 1, 0);
    dfs(A, 0, 0, adj, distA);

    int B = A;
    for (int i = 1; i <= n; i++) {
        if (distA[i] > distA[B]) {
            B = i;
        }
    }

    // 3. Calcula as distâncias a partir de B
    vector<int> distB(n + 1, 0);
    dfs(B, 0, 0, adj, distB);

    // 4. A resposta para cada nó é o maior valor entre distA[i] e distB[i]
    for (int i = 1; i <= n; i++) {
        cout << max(distA[i], distB[i]) << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}
