#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
using namespace std;
using i64 = long long;
// using p = pair<int, string>;
const int N = 1e5 + 10;
i64  n, q, ans, d[N], c[N], nxt[N][20], sum[N][20];
void stk() {
    stack<int> stk;
    for (int i = 1;i <= n;i++) {
        while (stk.size() && d[i] > d[stk.top()]) {
            nxt[stk.top()][0] = i;
            sum[stk.top()][0] = c[i];
            stk.pop();
        }
        stk.push(i);
    }
    while (stk.size()) nxt[stk.top()][0] = 0, stk.pop();
}
void st() {
    for (int j = 1;(1 << j) <= n;j++) {
        for (int i = 1;i + (1 << j) <= n;i++) {
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];//表示从 i这个位置向下的第 2^j个圆盘是哪个
            sum[i][j] = sum[i][j - 1] + sum[nxt[i][j - 1]][j - 1];//表示从 i这个位置向下的第 2^j个圆盘（不包括i）需要多少体积的水。
        }
    }
}
int query(int r, int v) {
    if (c[r] >= v) return r;
    v -= c[r];
    for (int i = 18;i >= 0;i--) {
        if (nxt[r][i] != 0 && v > sum[r][i]) {
            v -= sum[r][i];
            r = nxt[r][i];
        }
    }
    return nxt[r][0];
}
int main() {
    IOS;
    cin >> n >> q;
    for (int i = 1;i <= n;i++) cin >> d[i] >> c[i];
    memset(sum, 0x3f, sizeof(sum));
    stk();//求出对每个圆盘求出第一个比该圆盘大的圆盘信息（编号和容量）
    st();//倍增出完整的nxt数组和sum数组
    for (int i = 1;i <= q;i++) {
        int r, v;
        cin >> r >> v;
        cout << query(r, v) << "\n";
    }
    return 0;
}
