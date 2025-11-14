#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(0);
    map<long long,long long> mm;
    int n,m;
    cin >> n >> m;
    long long x,y;
    while(n--){
        cin >> x >> y;
        mm[y] = x;
    }
    while(m--){
        cin >> x >> y;
        if(x==y){
            cout<<"NO\n";
            continue;
        }
        long long gft1 = mm[mm[x]];
        long long gft2 = mm[mm[y]];
        if(gft1 == gft2 && gft1 != 0 && gft2 != 0)cout<<"YES\n";
        else cout<<"NO\n";
    }
}