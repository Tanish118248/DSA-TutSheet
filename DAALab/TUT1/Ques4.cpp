#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int maxCross(vector<int>& a, int l, int m, int r) {
    int s = 0, left = INT_MIN, right = INT_MIN;
    for (int i = m; i >= l; i--) {
        s += a[i];
        left = max(left, s);
    }
    s = 0;
    for (int i = m + 1; i <= r; i++) {
        s += a[i];
        right = max(right, s);
    }
    return left + right;
}

int maxSub(vector<int>& a, int l, int r) {
    if (l == r) return a[l];
    int m = (l + r) / 2;
    return max({maxSub(a, l, m), maxSub(a, m + 1, r), maxCross(a, l, m, r)});
}

int main() {
    vector<int> arr = {-2, -5, 6, -2, -3, 1, 5, -6};
    cout << maxSub(arr, 0, arr.size() - 1);
}
