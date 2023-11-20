#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
using namespace std;
vector<int> v1;
static bool cmp(const int i, const int j){
        return i > j;
    }
struct cmp {
    bool operator()(const int i, const int j) {
        return i > j;
    }
};
int main() {
    for (int i = 0;i < 7;i++) {
        v1.push_back(i);
        cout << v1[i] << " ";
    }
    cout << "\n";
    // sort(v1.begin(), v1.end(), [](int i, int j) {return i > j;});
    sort(v1.begin(), v1.end(), [](int x, int y) -> function<int(int)> {
        return [ = ](bool) { return x > y; };
        });
    // sort(v1.begin(), v1.end(), cmp);
    // sort(v1.begin(), v1.end(), greater<int>());
    for (auto num : v1) {
        cout << num << " ";
    }
    // for (int i=0;i<7;i++) cout<<v1[i]<<" ";
    // cout << v1[0] << " ";
    return 0;
}