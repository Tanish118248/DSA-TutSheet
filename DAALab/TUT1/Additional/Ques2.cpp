#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
    int ans = 1, l = 0;
    for (int r = 0; r < n; r++) {
        while (a[r] - a[l] > 10) l++;
        ans = max(ans, r - l + 1);
    }
    cout << ans;
}
