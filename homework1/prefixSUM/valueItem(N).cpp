#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compara(const string& l, const string& p) {
    return (l + p) > (p + l);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<string> lista(n);
    
    for (int i = 0; i < n; i++) {
        cin >> lista[i]; 
    }

    sort(lista.begin(), lista.end(), compara);

    for (int i = n - 1; i >= 0; i--) {
        cout << lista[i]; 
    }
    cout << "\n";

    return 0;
}
