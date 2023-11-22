#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
using namespace std;
using i64 = long long;
using p = pair<int, int>;
const int N = 8e5 + 10;
int n, m;
string name, s;
struct node {
    int cnt;
    int child[26];
    bool hasNext;
    node() {
        cnt = 0;
        memset(child, 0, sizeof(child));
        hasNext = false;
    }
}trie[N];
int _index;
void insert(string s) {
    int len = s.length();
    int cur = 0;
    for (int i = 0;i < len;i++) {
        int t = s[i] - 'a';
        if (!trie[cur].child[t]) trie[cur].child[t] = ++_index;
        cur = trie[cur].child[t];
    }
    trie[cur].hasNext = 1;
}
int find(string s) {
    int len = s.length();
    int cur = 0;
    for (int i = 0;i < len;i++) {
        int t = s[i] - 'a';
        if (!trie[cur].child[t]) return 3;
        cur = trie[cur].child[t];
    }
    if (!trie[cur].hasNext) return 3;
    if (!trie[cur].cnt) {
        trie[cur].cnt++;
        return 1;
    }
    return 2;
}
int main() {
    IOS;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> s, insert(s);
    cin >> m;
    for (int i = 1;i <= m;i++) {
        cin >> name;
        if (find(name) == 1) cout << "OK\n";
        else if (find(name) == 2) cout << "REPEAT\n";
        else cout << "WRONG\n";
    }
    return 0;
}


