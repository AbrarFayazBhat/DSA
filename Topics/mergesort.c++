#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int temp[], int low, int mid, int high) {
    int left = low;   // Starting index of the left half of arr
    int right = mid + 1; // Starting index of the right half of arr
    int index = low;   // Starting index for temp array

    // Storing elements in the temporary array in a sorted manner
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[index] = arr[left];
            left++;
        } else {
            temp[index] = arr[right];
            right++;
        }
        index++;
    }

    // If elements on the left half are still left
    while (left <= mid) {
        temp[index] = arr[left];
        left++;
        index++;
    }

    // If elements on the right half are still left
    while (right <= high) {
        temp[index] = arr[right];
        right++;
        index++;
    }

    // Transfering all elements from temporary array to the original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int temp[], int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;

    mergeSort(arr, temp, low, mid);    // Sort left half
    mergeSort(arr, temp, mid + 1, high); // Sort right half
    merge(arr, temp, low, mid, high); // Merge sorted halves
}

int main() {
    int arr[] = {9, 4, 7, 6, 3, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n]; // Temporary array for merging

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, temp, 0, n - 1);

    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
