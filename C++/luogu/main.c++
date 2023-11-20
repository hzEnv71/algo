#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
using namespace std;
using i64 = long long;
using p = pair<int, int>;
const int N = 1e5 + 10;
int  n, m, a[N], id[N], ans[N];
vector<p> v[N];
int main() {
    IOS;
    cin >> m >> n;
    for (int i = 1;i <= m;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) {
        int l, r;
        cin >> l >> r;
        v[r].push_back({ l,i });
    }
    int l = 1, r = 0;
    for (int i = 1;i <= m;i++) {
        while (l <= r && a[id[r]] >= a[i]) r--;
        id[++r] = i;
        for (auto p : v[i]) {
            ans[p.second] = a[*lower_bound(id + l, id + r + 1, p.first)];
        }
    }
    for (int i = 1;i <= n;i++) cout << ans[i] << " ";
    return 0;
}

