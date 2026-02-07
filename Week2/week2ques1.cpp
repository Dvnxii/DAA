/*
l. Given a sorted array of positive integers containing few duplicate 
elements, design an algorithm and implement it using a program to find 
whether the given key element is present in the array or not. If present, 
then also find the number of copies of given key. (Time Complexity = 
O(log n))
 
Input format: 
The first line contains number of test cases, T. For each test case, 
there will be three input lines. First line contains n (the size of array). 
Second line contains space-separated integers describing array. 
Third line contains the key element that need to be searched in the 
array. 

Output format: 
The output will have T number of lines. 
For each test case T, output will be the key element and its number of 
copies in the array if the key element is present in the array otherwise 
print “ Key not present”.

Sample 1/O Problem I: 
Input: Output: 
2 
10 
235 235 278 278 763 764 790 853 981 981 
981 
15 
122335552575757597 
97 97 
75 
*/

#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(const vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            result = mid;
            high = mid - 1;   
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return result;
}

int lastOccurrence(const vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            result = mid;
            low = mid + 1; 
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int key;
        cin >> key;

        int first = firstOccurrence(arr, key);

        if (first == -1) {
            cout << "Key not present" << endl;
        } else {
            int last = lastOccurrence(arr, key);
            int count = last - first + 1;
            cout << key << " " << count << endl;
        }
    }

    return 0;
}
