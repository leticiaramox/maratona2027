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














#include <bits/stdc++.h>   // GCC header that pulls in the whole standard library (iostream, vector, etc.)
using namespace std;       // lets us write cin/cout/vector instead of std::cin/std::cout/std::vector

/*
 * main()
 * Entry point of the program. Goal: compute the sum of the minimum of
 * every contiguous subarray, without ever building the subarrays.
 *
 * Idea: for each index i, count how many subarrays have arr[i] as their
 * minimum, then add arr[i] * (that count) to the answer.
 * A subarray has arr[i] as minimum if it starts after the previous smaller
 * element (left side) and ends before the next smaller-or-equal element
 * (right side).
 * Returns 0 to tell the operating system the program ended successfully.
 */
int main() {
    // ios::sync_with_stdio(false)
    // Disconnects C++ streams (cin/cout) from C streams (scanf/printf).
    // Removes the synchronization overhead, making input/output much faster.
    // After this call, do NOT mix cin/cout with scanf/printf.
    ios::sync_with_stdio(false);

    // cin.tie(nullptr)
    // By default, cin is "tied" to cout, so cout is flushed before every cin read.
    // Passing nullptr unties them, avoiding those extra flushes (faster input).
    cin.tie(nullptr);

    // cin >> n
    // Stream extraction operator: reads one whitespace-separated value from
    // standard input and stores it in the variable on the right.
    int n;
    cin >> n;

    // vector<long long> arr(n)
    // Constructor of std::vector: creates a dynamic array with n elements,
    // all initialized to 0. Memory is allocated once, on the heap.
    // long long is used because values and sums can exceed the int range.
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];   // operator[] gives direct access to element i (O(1), no bounds check)

    // left[i]  = index of the previous element strictly smaller than arr[i], or -1 if none
    // right[i] = index of the next element smaller than or equal to arr[i], or n if none
    // st       = monotonic stack that stores INDICES (not values)
    vector<int> left(n), right(n), st;

    // st.reserve(n)
    // Member of std::vector: pre-allocates capacity for n elements WITHOUT
    // changing the size. Avoids repeated reallocations while pushing.
    st.reserve(n);

    // ---------- Pass 1: fill left[] scanning from left to right ----------
    for (int i = 0; i < n; i++) {
        // st.empty()
        //   Returns true if the stack (vector) has no elements.
        // st.back()
        //   Returns a reference to the LAST element (the "top" of our stack).
        // st.pop_back()
        //   Removes the last element (a "pop"). Does not return it.
        // Here we pop every index whose value is >= arr[i], because those
        // can no longer be the "previous strictly smaller" of anything to the right.
        while (!st.empty() && arr[st.back()] >= arr[i]) st.pop_back();

        // After popping, the top (if any) is the nearest strictly smaller element.
        left[i] = st.empty() ? -1 : st.back();

        // st.push_back(i)
        // Appends i to the end of the vector (a "push"). Amortized O(1).
        st.push_back(i);
    }

    // st.clear()
    // Removes all elements (size becomes 0). The allocated capacity is kept,
    // so the memory can be reused by the second pass without reallocating.
    st.clear();

    // ---------- Pass 2: fill right[] scanning from right to left ----------
    for (int i = n - 1; i >= 0; i--) {
        // Same logic, mirrored. We pop only while value is STRICTLY greater (>),
        // so equal values stay on the stack and become the boundary.
        // Together with ">=" in pass 1, this makes exactly one of several
        // equal minimums "own" each subarray, so nothing is counted twice.
        while (!st.empty() && arr[st.back()] > arr[i]) st.pop_back();

        right[i] = st.empty() ? n : st.back();
        st.push_back(i);
    }

    // ---------- Combine: contribution of each element ----------
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long cntLeft  = i - left[i];    // choices for where the subarray starts
        long long cntRight = right[i] - i;   // choices for where the subarray ends
        // arr[i] is the minimum of exactly cntLeft * cntRight subarrays.
        sum += arr[i] * cntLeft * cntRight;
    }

    // cout << ...
    // Stream insertion operator: writes the value to standard output.
    // "\n" is used instead of endl because endl also flushes the buffer (slower).
    cout << sum << "\n";

    return 0;
}
