#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n, k;
    scanf("%d\n",&t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d\n",&n,&k);
        vector<int> nums(n);
        for (int j = 0; j < n; j++) {
            scanf("%d",&nums[j]);
        }
        auto c1 = 0, c2 = 0;
        bool flag = false;
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == nums[0] && c1 < k) {
                c1++;
                l = i;
            }
            if (nums[n - 1 - i] == nums[n - 1] && c2 < k) {
                c2++;
                r = n - 1 - i;
            }
            if (nums[0] == nums[n - 1]) {
                if (l == r && c1 + c2 - 1 >= k) {
                    flag = true;
                    break;
                }
                if (l < r && c1 + c2 >= k) {
                    flag = true;
                    break;
                }
            }
            if (c1 >= k && c2 >= k && l <= r) {
                flag = true;
                break;
            }
        }
        if (flag) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}
