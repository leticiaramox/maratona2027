#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Evento {
    long long ponto;
    int tipo; // +1 para início, -1 para fim

    // Ordenação: primeiro por coordenada 'ponto'.
    // Se o ponto for igual, +1 vem ANTES de -1 para contar bordas compartilhadas (ex: [2,4] e [4,5]).
    bool operator<(const Evento& outro) const {
        if (ponto == outro.ponto) return tipo > outro.tipo;
        return ponto < outro.ponto;
    }
};

int main() {
    // Otimização de I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<Evento> eventos;
    eventos.reserve(2 * n); // aloca memória

    for (int i = 0; i < n; i++) {
        long long l, r;
        cin >> l >> r;

        eventos.push_back({l, +1});
        eventos.push_back({r, -1});
    }

    // 1. Ordena todos os eventos
    sort(eventos.begin(), eventos.end());

    int ativos = 0;
    int max_simultaneos = 0;

    // 2. Percorre a linha de varredura acumulando os eventos
    for (const auto& ev : eventos) {
        ativos += ev.tipo;
        max_simultaneos = max(max_simultaneos, ativos);
    }

    cout << max_simultaneos << "\n";

    return 0;
}
