#include <iostream>
#include <cstring>

using namespace std;

void countSort(string arr[], int n, int exp) {
    int count[10] = {0};
    string output[n];
    for(int i = 0; i < n; i++) {
        count[(arr[i][exp] - '0')]++;
    }
    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for(int i = n - 1; i >= 0; i--) {
        output[count[(arr[i][exp] - '0')] - 1] = arr[i];
        count[(arr[i][exp] - '0')]--;
    }
    for(int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(string arr[], int n) {
    int m = arr[0].length();
    for(int exp = m - 1; exp >= 0; exp--) {
        countSort(arr, n, exp);
    }
}

int main() {
    string arr[] = {"000", "001", "101", "100", "010", "110", "011", "111"};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    // Output: 000 001 010 011 100 101 110 111
    return 0;
}
