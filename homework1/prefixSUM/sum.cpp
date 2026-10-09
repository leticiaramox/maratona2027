#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Função gulosa que checa se é possível dividir o array 
// de forma que nenhum grupo passe do limite 'mid'
bool ehPossivel(const vector<long long>& nums, int k, long long mid) {
    int grupos = 1;
    long long soma_atual = 0;

    for (int num : nums) {
        // Se um único número sozinho for maior que o limite, é impossível
        if (num > mid) return false;

        // Se estourar o limite atual, criamos um novo grupo
        if (soma_atual + num > mid) {
            grupos++;
            soma_atual = num;
        } else {
            soma_atual += num;
        }
    }

    return grupos <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<long long> nums(n);
    long long low = 0;
    long long high = 0;

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (nums[i] > low) low = nums[i]; // O 'low' começa como o maior elemento
        high += nums[i];                  // O 'high' começa como a soma de tudo
    }

    long long resultado = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (ehPossivel(nums, k, mid)) {
            resultado = mid;   // 'mid' é viável, guardamos ele
            high = mid - 1;    // Tentamos achar uma soma máxima ainda menor
        } else {
            low = mid + 1;     // 'mid' é muito pequeno, precisamos aumentar o limite
        }
    }
    
    cout << resultado << "\n";

    return 0;
}
