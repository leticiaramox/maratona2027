#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    --r1;
    --c1;
    --r2;
    --c2;

    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};

    const int start = r1 * m + c1;
    const int target = r2 * m + c2;

    // Conta as células vazias adjacentes ao destino.
    int cnt = 0;

    for (int i = 0; i < 4; ++i) {
        int nx = r2 + dx[i];
        int ny = c2 + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
            grid[nx][ny] == '.') {
            ++cnt;
        }
    }

    // Representa a grade como um vetor linear.
    vector<char> visited(n * m, 0);

    // Fila implementada com um vetor para evitar alocações
    // adicionais durante a BFS.
    vector<int> q(n * m);
    int head = 0;
    int tail = 0;

    q[tail++] = start;
    visited[start] = 1;

    // A busca termina assim que o destino é encontrado.
    while (head < tail && !visited[target]) {
        int u = q[head++];

        int x = u / m;
        int y = u % m;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            int v = nx * m + ny;

            if (!visited[v] &&
                (grid[nx][ny] == '.' || v == target)) {

                visited[v] = 1;
                q[tail++] = v;

                if (v == target) {
                    break;
                }
            }
        }
    }

    bool can = false;

    if (grid[r2][c2] == 'X') {
        if (start == target) {
            can = (cnt >= 1);
        } else {
            can = visited[target] &&
                  (cnt >= 1 ||
                   abs(r1 - r2) + abs(c1 - c2) == 1);
        }
    } else {
        can = (visited[target] && cnt >= 2) ||
              (start == target && cnt >= 1);
    }

    cout << (can ? "YES" : "NO") << '\n';

    return 0;
}
