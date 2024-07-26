#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int n) {//void reverseArray(int arr*, int n)
    for(i=0;i<n/2;i++) swap(arr[i],arr[n-i]);  
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    reverseArray(arr, n);
    
    cout << "Reversed array: ";
    printArray(arr, n);
    
    return 0;
}
