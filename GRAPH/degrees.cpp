#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<bool>> adj(n,vector<bool>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            adj[i][j] = x;
        }
    }
    int Mx = 0;
    vector<int> ans(n+1,0);
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++)if(adj[i][j])cnt++;
        Mx = max(Mx,cnt);
        ans[cnt]++;
    }
    for(int i=0;i<=Mx;i++)cout << ans[i] << " ";
}