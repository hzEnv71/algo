#include<iostream>
using namespace std;
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
const int N = 1e6 + 10;
int a[N], maxh[N], minh[N], st[N];
int maxv = -1,minv = 1e9 + 10,n;
int main()
{
	IOS;
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] > maxv) maxv = a[i], maxh[i] = a[i];
		else maxh[i] = maxv;
	}
    for (int i = 0; i < n; i++){
        if (a[n-i-1] < minv) minv = a[n-i-1], minh[n-i-1] = a[n-i-1];
		else minh[n-i-1] = minv;

	}
	
	for (int i = 0; i <n-1; i++)
		if (maxh[i] <= minh[i + 1])
			st[i] = 1;

	int ans = 1;
	for (int k = 1; k <= n-1; k++){
		bool flag = 1;
		for(int i=k-1;i<n-1;i+=k)
			if (st[i] == 0){flag = 0;break;}
		if (flag) ans++;
    }
	cout << ans;
}






