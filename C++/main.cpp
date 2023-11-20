#define INT_MAX __INT_MAX__
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
using namespace std;

int gcd(int a, int b) {
    if (b > 0) {
        return gcd(b, a % b);
    }
    return a;
}

int lcm(int a, int b) {return a / gcd(a, b) * b;}
int abs(int a,int b){if (a>b) return a-b;return b-a;}
int dfs(int n, vector<vector<int> > &v, int a, int b, int len, int cnt) {
    if (a == b) {
        return len;
    }
    if (cnt > n/3) {
        return INT_MAX;
    }
    int l = INT_MAX;
    for (int i = 0; i <v[a].size(); i++) {
        l = min(l, dfs(n, v, v[a][i], b, abs(a, v[a][i]) + len, cnt + 1));
    }
    return l;
}
void run() {
        int  n, q;
        cin >> n >> q;
        vector<vector<int> > v(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) { 
                if (gcd(i, j) == i && lcm(i, j) == j) {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }   
        }
        int x, y, cnt=0;
        for (int i = 0; i < q; i++) {
            cin >> x >> y;
            int minV = INT_MAX;
            for (int j=0;j<v[x].size();j++) {
                minV = min(minV, dfs(n, v, v[x][j], y, abs(x, v[x][j]), cnt));
            }
            cout << minV <<" \n";

        }
}
int main() {
    IOS;
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) { run(); }
    return 0;
}