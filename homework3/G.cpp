#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    // Otimização de entrada/saída
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    // Como M é pequeno (<= 10), podemos calcular os caminhos mínimos.
    // Para responder para cada k de 2 até n-1 de forma eficiente, 
    // podemos usar Dijkstra ou BFS ponderada, já que todas as arestas têm peso 1.

    // Vamos criar uma função ou estrutura para encontrar a menor distância de 1 a N evitando o vértice k.
    // Como refazer o Dijkstra para cada k seria O(N * M log N), o que passaria perto do limite, 
    // podemos otimizar guardando os caminhos ou usando uma abordagem com DAG (já que i < j sempre para os teleportes).

    // Como i -> j só ocorre se j > i, o grafo é um DAG (Directed Acyclic Graph).
    // Isso significa que podemos calcular DP de caminhos mínimos em O(N * M):
    // dp[i] = menor distância de 1 até i.
    
    // Vamos calcular dist_from_1[i]: menor distância de 1 até i
    vector<int> dist1(n + 1, 1e9);
    dist1[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (dist1[i] == 1e9) continue;
        for (int j = 1; j <= m; j++) {
            if (i + j <= n && s[i][j - 1] == '1') {
                dist1[i + j] = min(dist1[i + j], dist1[i] + 1);
            }
        }
    }

    // E dist_to_n[i]: menor distância de i até n
    vector<int> distN(n + 1, 1e9);
    distN[n] = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            if (i + j <= n && s[i][j - 1] == '1') {
                distN[i] = min(distN[i], distN[i + j] + 1);
            }
        }
    }

    // Para encontrar o caminho mínimo de 1 até N sem passar por k,
    // precisamos passar por algum u e v onde existe um teleporte de u para v,
    // com u < k e v > k (ou u e v contendo k no meio, o que é impossível já que pulamos k).
    // Mais precisamente, um caminho evita k se ele usa uma aresta (u, w) tal que u < k e w > k (ou seja, o teleporte pula por cima de k),
    // OU se o caminho simplesmente passa por nós antes e depois de k sem usar k.
    // Na verdade, qualquer caminho que não passa por k deve usar alguma aresta que "salta" por cima de k, 
    // ou o próprio destino N pode ser alcançado diretamente.
    // Espere, se k está no meio, o caminho vem de um conjunto de nós à esquerda de k e vai para um conjunto à direita de k.
    // Como M <= 10, podemos manter a menor distância usando umaEstrutura de dados para gerenciar o mínimo de `dist1[u] + 1 + distN[w]` 
    // para todas as arestas válidas (u -> w) que cobrem o obstáculo k.

    // Vamos usar um multiset ou árvore para rastrear os valores de `dist1[u] + 1 + distN[w]` 
    // para as arestas que cobrem a posição k (ou seja, u <= k e w > k).
    
    struct Edge {
        int u, w, cost;
    };

    // Para cada k, quais arestas cobrem k? Uma aresta (u, w) cobre k se u < k e w >= k (ou w > k).
    // Como M <= 10, w - u <= M. Portanto, w - u pode ser no máximo 10.
    // Uma aresta (u, w) cobre k se u < k e w > k.
    
    // Vamos armazenar para cada k quais arestas iniciam antes de k e terminam depois de k.
    // Em vez de recalcular tudo, podemos usar um 'multiset' que mantém os custos das arestas ativas.
    // Uma aresta (u, w) cobre o ponto k se u < k e w > k. 
    // Isso significa que u varia de `max(1, w - M)` até `w - 1`, e k pode estar em qualquer posição entre `u + 1` e `w - 1`.

    vector<int> ans(n - 1, 1e9);
    
    // Vamos coletar todas as arestas válidas no grafo
    vector<vector<int>> covering_edges(n + 1); // guarda os custos para cada ponto que a aresta cobre
    // Uma aresta de u para w cobre todos os k tal que u < k < w.
    for (int u = 1; u <= n; u++) {
        if (dist1[u] == 1e9) continue;
        for (int j = 1; j <= m; j++) {
            int w = u + j;
            if (w <= n && s[u][j - 1] == '1' && distN[w] != 1e9) {
                int cost = dist1[u] + 1 + distN[w];
                // Esta aresta cobre todos os k no intervalo [u + 1, w - 1]
                // Para simplificar, podemos adicionar o custo nas pontas ou usar uma estrutura de janela deslizante.
            }
        }
    }

    // Como M <= 10 é muito pequeno, podemos usar uma abordagem com Segment Tree ou Multiset com varredura (Sweep-line).
    // Vamos construir eventos para o sweep-line em cada k:
    vector<vector<pair<int, int>>> adds(n + 1); // k onde a aresta começa a cobrir (u+1)
    vector<vector<pair<int, int>>> removes(n + 1); // k onde a aresta para de cobrir (w)

    for (int u = 1; u <= n; u++) {
        if (dist1[u] == 1e9) continue;
        for (int j = 1; j <= m; j++) {
            int w = u + j;
            if (w <= n && s[u][j - 1] == '1' && distN[w] != 1e9) {
                int cost = dist1[u] + 1 + distN[w];
                if (u + 1 <= w - 1) {
                    adds[u + 1].push_back({cost, u});
                    removes[w].push_back({cost, u});
                }
            }
        }
    }

    multiset<int> active_costs;
    // Para cada k de 2 até n-1:
    for (int k = 2; k <= n - 1; k++) {
        // Adiciona as arestas que começam a cobrir k
        for (auto& p : adds[k]) {
            active_costs.insert(p.first);
        }
        // Remove as arestas que param de cobrir k
        for (auto& p : removes[k]) {
            auto it = active_costs.find(p.first);
            if (it != active_costs.end()) {
                active_costs.erase(it);
            }
        }

        if (!active_costs.empty()) {
            ans[k - 1] = *active_costs.begin();
        }
    }

    // Imprime os resultados para k = 2 até n-1
    for (int i = 1; i <= n - 2; i++) {
        if (ans[i] > 1e8) cout << -1 << " ";
        else cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
