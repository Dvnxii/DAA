/*
2. Given an unsorted array of integers, design an algorithm and
implement it using a program to sort an array of elements by
partitioning the array into two subarrays based on a pivot element such
that one of the sub array holds values smaller than the pivot element
while another sub array holds values greater than the pivot element.
Pivot element should be selected randomly from the array. Your
program should also find number of comparisons and swaps required
for sorting the array.
Input Format:
The first line contains number of test cases, T. For each test case,
there will be two input lines. First line contains n (the size of array).
Second line contains space-separated integers describing array.
Output Format:
The output will have T number of lines.
For each test case T, there will be three output lines. First line will give
the sorted array.
Second line will give total number of comparisons. Third line will give
total number of swaps required.
Sample 1/0O Problem II:
Input: Output:
3 2123324546 65 76 89
8 comparisons = 14
2365217646 894532 swaps =10
10 21323446515465767897
54 6534 76 78 97 46 32 5121 comparisons = 29 

*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

long long comparisons = 0;
long long swaps = 0;

int partition(vector<int> &arr, int low, int high) {

    int pivotIndex = low + rand() % (high - low + 1);
    swap(arr[pivotIndex], arr[high]);
    swaps++;

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;

        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }

    swap(arr[i + 1], arr[high]);
    swaps++;

    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {

    srand(time(0));

    int T;
    cin >> T;

    while (T--) {

        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        comparisons = 0;
        swaps = 0;

        quickSort(arr, 0, n - 1);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        cout << "comparisons = " << comparisons << endl;
        cout << "swaps = " << swaps << endl;
    }

    return 0;
}