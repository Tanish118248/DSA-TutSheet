#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int j = 0; 
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n - 1]; 
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < j; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}



