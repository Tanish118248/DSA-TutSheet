#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void merge(vector<int>& a, int l, int m, int r) {
    vector<int> x(a.begin() + l, a.begin() + m + 1);
    vector<int> y(a.begin() + m + 1, a.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < x.size() && j < y.size())
        a[k++] = (x[i] <= y[j]) ? x[i++] : y[j++];
    while (i < x.size()) a[k++] = x[i++];
    while (j < y.size()) a[k++] = y[j++];
}

void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

int main() {
    vector<int> arr1 = {12, 11, 13, 5, 6, 7};
    vector<int> arr2 = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(arr1, 0, arr1.size() - 1);
    mergeSort(arr2, 0, arr2.size() - 1);
    for (int x : arr1) cout << x << " ";
    cout << endl;
    for (int x : arr2) cout << x << " ";
}
