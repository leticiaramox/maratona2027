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

    // Lista de adjacência (usando base 1 para os índices das pedras)
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 0 = não visitado, 1 = bolsa 1, 2 = bolsa 2
    vector<int> color(n + 1, 0);
    bool possivel = true;

    vector<int> bolsa1, bolsa2;

    // Percorrer todos os vértices para lidar com grafos desconexos (ilhas)
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            // Inicia BFS no componente conexo atual
            queue<int> q;
            q.push(i);
            color[i] = 1;
            bolsa1.push_back(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == 0) {
                        // Atribui a cor oposta à do vértice atual
                        color[v] = (color[u] == 1) ? 2 : 1;
                        if (color[v] == 1) bolsa1.push_back(v);
                        else bolsa2.push_back(v);
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        // Conflito: dois vizinhos têm a mesma cor (tóxicos na mesma bolsa)
                        possivel = false;
                    }
                }
            }
        }
    }

    if (!possivel) {
        cout << "IMPOSSIVEL\n";
    } else {
        cout << "POSSIVEL\n";
        cout << bolsa1.size() << " " << bolsa2.size() << "\n";
        
        for (int x : bolsa1) cout << x << " ";
        cout << "\n";
        
        for (int x : bolsa2) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
