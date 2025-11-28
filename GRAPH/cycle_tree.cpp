#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for(int i=0;i<n;i++){
        int st,en;
        cin >> st >> en;
        v[st].push_back(en);
        v[en].push_back(st);
    }
    vector<bool> visited(n,false);
    stack<pair<int,int>> s;
    vector<int> val(n,0);
    s.push({0,0});
    while(!s.empty()){
        auto [now,size] = s.top();s.pop();
        if(visited[now]){
            if(size - val[now] >=3){
                cout<<size - val[now];
                return 0;
            }
            continue;
        }
        visited[now]=true;

        val[now]=size;

        for(auto& next:v[now]){
            s.push({next,size+1});
        }
    }
}