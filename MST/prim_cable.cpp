#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> v(n,vector<pair<int,int>>());
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int w;
            cin >> w;
            v[i].push_back({w,j});
            v[j].push_back({w,i});
        }
    }

    int sum=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool> visited(n);
    pq.push({0,0});
    while(!pq.empty()){
        auto [w,now] = pq.top();pq.pop();
        if(visited[now])continue;
        visited[now]=true;
        sum+=w;
        for(auto& [ww,next]:v[now]){
            if(!visited[next])pq.push({ww,next});
        }
    }
    cout << sum;
}