/*
3. Given an unsorted array of integers, design an algorithm and
implement it using a program to find Kth smallest or largest element in
the array. (Worst case Time Complexity = O(n))
Input Format:
The first line contains number of test cases, T. For each test case,
there will be three input lines. First line contains n (the size of array).
Second line contains space-separated integers describing array. Third
line contains K.
Output Format:
The output will have T number of lines.
For each test case, output will be the Kth smallest or largest array
element. If no Kth element is present, output should be “not present”.
Sample for Kth smallest:
Input: Output:
3 123
10 78
123 656 54 765 344 514 765 34 765 234
3
15
4364 13 78 864 346 786 456 21 19 8 434 76 270 601
8 

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int>& arr, int l, int r, int x) {
    int i;
    for (i = l; i < r; i++)
        if (arr[i] == x)
            break;

    swap(arr[i], arr[r]);

    i = l;
    for (int j = l; j < r; j++) {
        if (arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int kSmallestEle(vector<int>& arr, int l, int r, int k) {

    if (k > 0 && k <= r - l + 1) {

        int n = r - l + 1;

        vector<int> median((n + 4) / 5);
        int i;

        for (i = 0; i < n / 5; i++) {
            sort(arr.begin() + l + i * 5, arr.begin() + l + i * 5 + 5);
            median[i] = arr[l + i * 5 + 2];
        }

        if (i * 5 < n) {
            sort(arr.begin() + l + i * 5, arr.begin() + l + i * 5 + (n % 5));
            median[i] = arr[l + i * 5 + (n % 5) / 2];
            i++;
        }

        int medOfMed = (i == 1) ? median[i - 1]
                                : kthSmallest(median, 0, i - 1, i / 2);

        int pos = partition(arr, l, r, medOfMed);

        if (pos - l == k - 1)
            return arr[pos];

        if (pos - l > k - 1)
            return kthSmallest(arr, l, pos - 1, k);

        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }

    return INT_MAX;
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

        int k;
        cin >> k;

        if (k > n || k <= 0) {
            cout << "not present" << endl;
        } else {
            int result = kthSmallest(arr, 0, n - 1, k);
            cout << result << endl;
        }
    }

    return 0;
}