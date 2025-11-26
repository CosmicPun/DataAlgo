#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); 
    int n,m,k;
    cin >> n >> m >> k;
    vector<long long> sum(n+1);
    for(int i=1;i<=n;i++){
        cin >> sum[i];
        sum[i]+=sum[i-1];
    }
    for(int i=0;i<m;i++){
        int l;
        long long money;
        cin >> l >> money;
        l++;
        int st = l;
        int ed = n;
        long long ans = 0;
        while(st<=ed){
            int mid = (st+ed)/2;
            if(sum[mid]-sum[l-1]+(mid-l+1)*k <= money){
                st = mid+1;
                ans = sum[mid]-sum[l-1];
            }
            else ed = mid-1;
        }
        cout << ans << "\n";
    }
}