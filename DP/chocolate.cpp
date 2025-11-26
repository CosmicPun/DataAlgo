#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> dp(n+1),v(m);
    for(int i=0;i<m;i++){
        cin >> v[i];
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(auto &x:v){
            if(i>=x){
                dp[i]+=dp[i-x];
                dp[i]=dp[i]%1000003;
            }
        }
    }
    cout << dp[n];
}