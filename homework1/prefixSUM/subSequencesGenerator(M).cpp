#include <bits/stdc++.h>
#include <vector>
using namespace std;

'''
    void findSubsequences(int curr, vector<int> &arr, 
                      vector<int> &subarr, vector<vector<int>> &res) {
   
   // Base case: When we reach the end of the array,
    // add the current subsequence to the result
    if (curr == arr.size()) {
        res.push_back(subarr);
        return;
    }

    //  Include the current element in the subsequence
    subarr.push_back(arr[curr]);

    // Recurse to the next element
    findSubsequences(curr + 1, arr, subarr, res);  

    // Backtrack: Remove the current element and explore
   // the next possibility
    subarr.pop_back();

    //  Do not include the current element
  	// in the subsequence
    findSubsequences(curr + 1, arr, subarr, res);
}

int main() {
    vector<int> arr = {1, 2, 3};
    int n = arr.size();

    vector<int> subarr;
    vector<vector<int>> res;

    findSubsequences(0, arr, subarr, res);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

'''



long long countSubsequences(int curr, const vector<long long> &arr, long long target, long long soma) {

    if (curr == arr.size()) {
        if (soma == target) return 1;
        else return 0;
    }

    long long inclui = countSubsequences(curr + 1, arr, target, soma + arr[curr]);
    
    long long exclui = countSubsequences(curr + 1, arr, target, soma);

    return inclui + exclui;
}



int main() {
    
    int n;
    long long s;
    cin >> n >> s;
    
    int ajuste = 0;
    long long sum = 0;
    
    vector<long long> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        sum += num[i];
    }
    
    if (sum == s) {
        ajuste = -1;
    }
    
    long long c = countSubsequences(0, num, s, 0);
    
    long long tam = c + ajuste;
    
    cout << tam;
}
