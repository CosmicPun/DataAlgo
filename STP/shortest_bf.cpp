#include <bits/stdc++.h>
using namespace std;

#define edge tuple<int,int,int>

int main(){
    int n,e,s;
    cin >> n >> e >> s;
    vector<edge> adj;
    for(int i=0;i<e;i++){
        int st,en,w;
        cin >> st >> en >> w;
        adj.push_back({st,en,w});
    }
    vector<long long> dist(n,LLONG_MAX);
    dist[s]=0;

    for(int i=0;i<n-1;i++){
        bool updated = false;
        for(auto& [u,v,w] : adj){
            if(dist[u] < LLONG_MAX && dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
                updated = true;
            }
        }
        if(!updated) break;
    }
    for(auto& [u,v,w] : adj){
        if(dist[u]+w < dist[v]){
            cout << -1;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        cout << dist[i] << " ";
    }
}