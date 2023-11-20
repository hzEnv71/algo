#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#pragma GCC optimize (1)
#pragma GCC optimize (2)
#pragma GCC optimize (3)
using namespace std;
using ll = long long;
const int N = 10001;
array<int, N> a;
priority_queue<int, vector<int>, greater<int>> pq;
int n;
int main() {
    IOS;
    cin >> n;
    int ans = 0;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        pq.push(a[i]);
    }
    while (pq.size() > 1) {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        ans += x + y;
        pq.push(x + y);
    }
    cout << ans;
    return 0;
}



