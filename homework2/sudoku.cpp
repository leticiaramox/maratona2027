#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

struct Estado {
    int idx;
    vector<vector<char>> tab;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    while (n--) {
        vector<vector<char>> board(9, vector<char>(9));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> board[i][j];
            }
        }

        vector<pair<int, int>> vazios;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '0') {
                    vazios.push_back({i, j});
                }
            }
        }

        stack<Estado> pilha;
        pilha.push({0, board});
        int finalizado = 0;

        while (!pilha.empty() && !finalizado) {
            Estado elemento = pilha.top();
            pilha.pop();

            int idx = elemento.idx;
            vector<vector<char>> tab = elemento.tab;

            if (idx == (int)vazios.size()) {
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        cout << tab[i][j] << (j == 8 ? "" : " ");
                    }
                    cout << "\n";
                }
                finalizado = 1;
            } else {
                int x = vazios[idx].first;
                int y = vazios[idx].second;

                for (int num = 9; num >= 1; num--) {
                    char c = num + '0';
                    int valido = 1;

                    for (int k = 0; k < 9; k++) {
                        if (tab[x][k] == c || tab[k][y] == c) {
                            valido = 0;
                            break;
                        }
                    }

                    if (valido) {
                        int bx = (x / 3) * 3;
                        int by = (y / 3) * 3;
                        for (int i = bx; i < bx + 3; i++) {
                            for (int j = by; j < by + 3; j++) {
                                if (tab[i][j] == c) {
                                    valido = 0;
                                    break;
                                }
                            }
                            if (!valido) break;
                        }
                    }

                    if (valido) {
                        vector<vector<char>> novo = tab;
                        novo[x][y] = c;
                        pilha.push({idx + 1, novo});
                    }
                }
            }
        }

        if (!finalizado) {
            cout << "No solution\n";
        }
    }

    return 0;
}
