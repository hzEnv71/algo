#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx") // AVX优化指令，总之很nb
#pragma GCC optimize (1) // O(1)
#pragma GCC optimize (2) // O(2)
#pragma GCC optimize (3) // O(3)
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("inline")

void solve() {
    int n, m;
    string s;
    cin>>n>>m>>s;
    set<pair<int, int> > S;
    
    vector<int> nxt(n + 1, n), lst(n + 1, -1);
    for (int i = 0; i < n; i++) {
        lst[i + 1] = s[i] == '0' ? i : lst[i];
        nxt[n-i-1] = s[n-i-1] == '1' ? n-i-1 : nxt[n-i];
    }
    
    while (m--) {
        int l, r;
        cin>>l>>r;
        l--;
        l = nxt[l];
        r = lst[r];
        if (l > r) {
            l = r = -1;
        }
        S.insert(std::pair<int,int>(l,r));
    }
    cout<<S.size()<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while (t--) {
        solve();
    } 
    return 0;
}