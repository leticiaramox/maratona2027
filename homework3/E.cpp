#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Otimização de entrada/saída para maior rapidez
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, start_col;
    while (cin >> n >> m >> start_col && (n != 0 || m != 0 || start_col != 0)) {
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        // Matriz para armazenar o número do passo em que cada célula foi visitada (1-indexed)
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int r = 0, c = start_col - 1; // Posição inicial (linha 0, coluna convertida para base 0)
        int step = 0;

        bool exited = false;
        int loop_start = 0;
        int loop_length = 0;

        while (true) {
            // Verificar se o robô saiu da grelha
            if (r < 0 || r >= n || c < 0 || c >= m) {
                exited = true;
                break;
            }

            // Verificar se a célula já foi visitada (deteta um ciclo/loop)
            if (visited[r][c] > 0) {
                loop_start = visited[r][c] - 1;
                loop_length = step - visited[r][c] + 1;
                break;
            }

            step++;
            visited[r][c] = step;

            // Mover de acordo com a instrução na célula atual
            char dir = grid[r][c];
            if (dir == 'N') r--;
            else if (dir == 'S') r++;
            else if (dir == 'E') c++;
            else if (dir == 'W') c--;
        }

        // Imprimir o resultado de acordo com o formato exigido
        if (exited) {
            cout << step << " step(s) to exit\n";
        } else {
            cout << loop_start << " step(s) before a loop of " << loop_length << " step(s)\n";
        }
    }

    return 0;
}
