#include <bits/stdc++.h>
using namespace std;

#define edge pair<int,int>
int main(){
    int n,m,k;
    cin >> n >> m >> k;

    vector<int> start;
    vector<int> dist(n);
    vector<vector<edge>> adj(n);
    while(k--){
        int st;
        cin >> st;
        start.push_back(st);
    }   
    
    for(int i=0;i<n;i++){
        cin >> dist[i];
    }

    while(m--){
        int st,en;
        cin >> st >> en;
        adj[st].push_back({dist[en],en});
        adj[en].push_back({dist[st],st});
    }

    priority_queue<edge,vector<edge>,greater<edge>> pq;
    vector<bool> visited(n,false);

    for(auto& x:start){
        pq.push({dist[x],x});
    }
    int time = 0;
    while(pq.size()){
        auto [w,now] = pq.top();pq.pop();
        if(visited[now])continue;
        visited[now]=true;
        time = w;
        for(auto& [ww,next]:adj[now]){
            pq.push({ww+w,next});
        }
    }
    cout << time;
}