
#include <iostream>

using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    // Output: 1 1 2 3 3 4 5 5 5 6 9
    return 0;
}
