#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long m = 1e9;

long long fatorialMod(long long n, long long mod) {
    if (n >= mod) return 0;

    long long ans = 1;
    for (long long i = 1; i <= n; i++) {
        ans = (ans * i) % mod;
    }
    return ans;
}

void backtrack(const string& arr, vector<bool>& visited,
               string& curr, vector<string>& result) {

    // Se a permutação atual estiver completa, adiciona ao resultado
    if (curr.size() == arr.size()) {
        result.push_back(curr);
        return;
    }

    // Constrói as permutações
    for (size_t i = 0; i < arr.size(); i++) {

        // Pula elementos já visitados
        if (visited[i]) continue;

        // Pula duplicatas: se arr[i] == arr[i-1] e arr[i-1] não foi usado
        if (i > 0 && arr[i] == arr[i - 1] && !visited[i - 1]) continue;

        // Escolhe arr[i]
        visited[i] = true;
        curr.push_back(arr[i]);

        // Recursão para construir a próxima parte
        backtrack(arr, visited, curr, result);

        // Desfaz a escolha (backtrack)
        curr.pop_back();
        visited[i] = false;
    }
}

// Função para retornar todas as permutações únicas de uma string
vector<string> uniquePerms(string arr) {

    // Ordena a string para agrupar caracteres iguais
    sort(arr.begin(), arr.end());

    vector<string> result;
    string curr = "";
    vector<bool> visited(arr.size(), false);

    // Inicia o backtracking
    backtrack(arr, visited, curr, result);
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string word;
    if (!(cin >> word)) return 0;
    
    int tamS = word.size();
    
    vector<int> freq(26, 0);
    for (char c : word) {
        freq[c - 'a']++;
    }
    
    // Calcula o produto dos fatoriais de cada caractere único
    long long prod = 1;
    for (int f : freq) {
        if (f > 0) {
            prod *= fatorialMod(f, m);
        }
    }
    
    long long num = fatorialMod(tamS, m) / prod;
    
    cout << num << "\n";
    
    vector<string> permutations = uniquePerms(word);

    for (const string& perm : permutations) {
        cout << perm << "\n";
    }

    return 0;
}
