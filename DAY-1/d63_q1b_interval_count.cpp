#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    vector<int> v;
    int m,n,k;
    cin >> n >> m >> k;
    while(n--){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    while(m--){
        int y;
        cin >> y;
        int st = y-k;
        int ed = y+k;
        auto first = lower_bound(v.begin(),v.end(),st);
        auto end = upper_bound(v.begin(),v.end(),ed);
        cout<<end-first<<" ";
    }
}