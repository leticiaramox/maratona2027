#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> getSubArrays(vector<long long>& arr) {
    vector<vector<long long>> ans;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vector<long long> subarray;

            for (int k = i; k <= j; k++)
                subarray.push_back(arr[k]);

            ans.push_back(subarray);
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    
    
    vector<long long> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }
    
    vector<vector<long long>> ans = getSubArrays(arr);

    vector<int> mins;

    long long sum = 0;
    for (const auto& subarray : ans) {
        long long menor = *min_element(subarray.begin(), subarray.end());
        sum += menor;
    }

    cout << sum;

    return 0;
}
