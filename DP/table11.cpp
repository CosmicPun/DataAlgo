#include <bits/stdc++.h>
using namespace std;

const int MOD = 100000007;
int dp[10000005][2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); 
    int n;
    cin >> n;
    dp[1][0] = 1;dp[1][1] = 1;
    for(int i=1;i<n;i++){
        dp[i+1][0] = (dp[i][0] + (dp[i][1]%MOD)*2)%MOD;
        dp[i+1][1] = (dp[i][0] + dp[i][1])%MOD;
    }
    cout << ((dp[n][1]*2)%MOD+dp[n][0])%MOD;
}