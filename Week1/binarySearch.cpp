/*
2. Given an already sorted array of positive integers, design an
algorithm and implement it using a program to find whether given key
element is present in the array or not. Also, find total number of
comparisons for each input case. (Time Complexity = O(nlogn), where
n is the size of input). 

*/

#include <iostream>
using namespace std;

// Binary Search
bool binarySearch(int arr[], int n, int key, int &comparisons) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        comparisons++;

        if (arr[mid] == key)
            return true;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main() {
    int n, key;
    int comparisons = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter sorted array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter key element to search: ";
    cin >> key;

    if (binarySearch(arr, n, key, comparisons))
        cout << "Key element is present in the array.\n";
    else
        cout << "Key element is NOT present in the array.\n";

    cout << "Total number of comparisons: " << comparisons << endl;

    return 0;
}
