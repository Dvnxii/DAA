/*
l. Given an array of nonnegative integers, design a linear algorithm
and implement it using a program to find whether given key element is
present in the array or not. Also, find total number of comparisons for
each input case. (Time Complexity = O(n), where n is the size of input) 

Sample 1/0O Problem - 1: 
Input: Output: 
3 
Present 6 
8 
Present 3 
34 35653125896430 NotPresent6 
89 
5 
977 354 244 546 355 
244 
6 
2364 13 67 43 56 
63 
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cin >> key;

    int comparisons = 0;
    bool found = false;

    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == key) {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Present " << comparisons << endl;
    else
        cout << "NotPresent " << comparisons << endl;

    return 0;
}


