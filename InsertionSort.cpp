#include <iostream>

using namespace std;

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    // Output: 1 1 2 3 3 4 5 5 5 6 9
    return 0;
}
