#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
using namespace std;
using i64 = long long;
using p = pair<int, int>;

const int N = 1e6 + 10;
int kmp[N];
char s1[N], s2[N];

int main() {
    IOS;
    cin >> (s1 + 1) >> (s2 + 1);
    int la = strlen(s1 + 1), lb = strlen(s2 + 1);
    for (int i = 2, j = 0;i <= lb;i++) {
        while (j && s2[i] != s2[j + 1]) j = kmp[j];
        if (s2[j + 1] == s2[i]) j++;
        kmp[i] = j;
    }
    for (int i = 1, j = 0;i <= la;i++) {
        while (j && s2[j + 1] != s1[i]) j = kmp[j];
        if (s2[j + 1] == s1[i]) j++;
        if (j == lb) cout << i - lb + 1 << "\n", j = kmp[j];
    }
    for (int i = 1;i <= lb;i++) cout << kmp[i]<<' ';
    return 0;
}


