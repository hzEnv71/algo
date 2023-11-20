#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),tie.cin(nullptr),tie.cout(nullptr);
using namespace std;
using ll=long long;
const int N=25;
#define p pair<ll,ll>
set<p> st;
ll n,m,x,y,dp[N][N];
int dir[8][2]={{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,1},{-2,-1},{-1,2}};
int main() {
    cin >> n >> m >> x >> y;
    st.insert({x,y});
    for (int i=0;i<8;i++){
        st.insert({x+dir[i][0],y+dir[i][1]});
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            if (st.find({i,j})==st.end()){
                if (i==0&&j==0){
                    dp[i][j]=1;
                }else if (i==0){
                    dp[i][j]=dp[i][j-1];
                }else if (j==0){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]+=dp[i-1][j]+dp[i][j-1];
                }
            }  
        }
    }
    cout<<dp[n][m];
    return 0;
}
