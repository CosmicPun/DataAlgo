#include <bits/stdc++.h>
using namespace std;

const int MOD = 100000007;

int main(){
    int cnt=0;
    int n;
    cin >> n;

    vector<vector<int>> dp(n+1,vector<int>(5,0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    for(int i=2;i<=n;i++){
        dp[i][0] = (dp[i-1][2] + dp[i-1][3]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][3]) % MOD;
        dp[i][2] = dp[i-1][1] % MOD;
        dp[i][3] = dp[i-1][0] % MOD;
    }
    for(int i=0;i<4;i++){
        cnt = (cnt+dp[n][i])%MOD;
    }
    cout<<cnt;
}