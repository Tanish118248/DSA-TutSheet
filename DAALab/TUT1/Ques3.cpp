#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int partition(vector<int>& a, int l, int r) {
    int p = a[r], i = l - 1;
    for (int j = l; j < r; j++)
        if (a[j] <= p) swap(a[++i], a[j]);
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSort(vector<int>& a, int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

int main() {
    vector<int> arr = {4, 2, 6, 9, 2};
    quickSort(arr, 0, arr.size() - 1);
    for (int x : arr) cout << x << " ";
}
