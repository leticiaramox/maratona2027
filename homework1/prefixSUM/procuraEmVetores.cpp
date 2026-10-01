#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n_participantes, n_problemas, n_submissoes;
    cin >> n_participantes >> n_problemas >> n_submissoes;

    vector<string> nomes(n_participantes);
    unordered_map<string, long long> pontuacoes;

    for (int i = 0; i < n_participantes; i++) {
        cin >> nomes[i];
        pontuacoes[nomes[i]] = 0; 
    }

    unordered_map<string, long long> valor_problema;
    for (int i = 0; i < n_problemas; i++) {
        string prob;
        long long val;
        cin >> prob >> val;
        valor_problema[prob] = val;
    }

    for (int i = 0; i < n_submissoes; i++) {
        string nome, problema, vered;
        cin >> nome >> problema >> vered;

        if (vered == "AC") {
            pontuacoes[nome] += valor_problema[problema];
        }
    }

    for (int i = 0; i < n_participantes; i++) {
        cout << nomes[i] << " " << pontuacoes[nomes[i]] << "\n";
    }

    return 0;
}
