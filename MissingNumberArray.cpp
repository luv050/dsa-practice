#include <bits/stdc++.h>
using namespace std;

// Function to find the missing number using the sum formula
int missingNumberSumFormula(vector<int>& a, int N) {
    // Summation of first N numbers:
    int sum = (N * (N + 1)) / 2;

    // Summation of all array elements:
    int s2 = 0;
    for (int i = 0; i < N - 1; i++) {
        s2 += a[i];
    }

    return sum - s2;
}

// Function to find the missing number using the XOR method
int missingNumberXOR(vector<int>& a, int N) {
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < N - 1; i++) {
        xor2 = xor2 ^ a[i]; // XOR of array elements
        xor1 = xor1 ^ (i + 1); // XOR up to [1...N-1]
    }
    xor1 = xor1 ^ N; // XOR up to [1...N]

    return (xor1 ^ xor2); // the missing number
}

int main() {
    int N = 5;
    vector<int> a = {1, 2, 4, 5};

    // Finding missing number using sum formula
    int missingNumSumFormula = missingNumberSumFormula(a, N);
    cout << "The missing number using sum formula is: " << missingNumSumFormula << endl;

    // Finding missing number using XOR method
    int missingNumXOR = missingNumberXOR(a, N);
    cout << "The missing number using XOR method is: " << missingNumXOR << endl;

    return 0;
}
