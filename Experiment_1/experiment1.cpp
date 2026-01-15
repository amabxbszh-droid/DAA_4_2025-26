#include <bits/stdc++.h>
using namespace std;

// Global counters
long long operationCount = 0;   // counts operations
int maxDepth = 0;               // maximum recursion depth

void complexRec(int n, int depth) {
    if (n <= 2) return;

    // Track recursion depth
    maxDepth = max(maxDepth, depth);

    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            operationCount++;   // count each assignment as an operation
        }
        p >>= 1;
        operationCount++;       // count shift as operation
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        operationCount++;
    }

    reverse(small.begin(), small.end());
    operationCount += n;        // count reverse as n operations

    // Recursive calls
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
}

int main() {
    vector<int> testSizes = {10, 50, 100, 200, 500, 1000};

    for (int n : testSizes) {
        operationCount = 0;
        maxDepth = 0;

        auto start = chrono::high_resolution_clock::now();
        complexRec(n, 1);
        auto end = chrono::high_resolution_clock::now();

        long long duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        cout << "Input size n = " << n << "\n";
        cout << "Operations performed = " << operationCount << "\n";
        cout << "Max recursion depth = " << maxDepth << "\n";
        cout << "Execution time = " << duration << " ms\n";
        cout << "-----------------------------------\n";
    }

    return 0;
}