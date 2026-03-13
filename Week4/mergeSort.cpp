/*
1. Given an unsorted array of integers, design an algorithm and
implement it using a program to sort an array of elements by dividing
the array into two subarrays and combining these subarrays after
sorting each one of them. Your program should also find number of
comparisons and inversions during sorting the array.
Input Format:
The first line contains number of test cases, T. For each test case,
there will be two input lines. First line contains n (the size of array).
Second line contains space-separated integers describing array.
Output Format:
The output will have T number of lines.
For each test case T, there will be three output lines. First line will give
the sorted array.
Second line will give total number of comparisons. Third line will give total number of inversions required.
Sample 1/O Problem I:
Input: Output:
3 2123324546 6576 89
8 comparisons = 16
2365217646 894532 inversions =
10 213234465154 65767897
54 6534 76 78 97 46 32 51 21 comparisons = 22
15 inversions =
63 42 223 645 652 31 324 22 553 12 54 65 86 46 32512 22 31 42 46
54 63 65 86 223 324 325 553 645 652
comparisons = 43
inversions = 
*/

#include <iostream>
#include <vector>
using namespace std;

long long comparisons = 0;
long long inversions = 0;

void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        comparisons++;

        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inversions += (n1 - i); 
        }
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        comparisons = 0;
        inversions = 0;

        mergeSort(arr, 0, n - 1);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        cout << "comparisons = " << comparisons << endl;
        cout << "inversions = " << inversions << endl;
    }

    return 0;
}