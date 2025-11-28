#include <bits/stdc++.h>
using namespace std;

int main(){
    int V,E,cnt=0;
    cin >> V >> E;
    vector<vector<int>> v(V);
    for(int i=0;i<E;i++){
        int st,en;
        cin >> st >> en;
        v[st].push_back(en);
        v[en].push_back(st);
    }
    
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++){
        if(visited[i])continue;
        bool line=true;
        int node1 = 0;
        int node2 = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int now = q.front();q.pop();
            if(visited[now])continue;
            visited[now]=true;

            if(v[now].size()>2){
                line = false;
                break;
            }
            
            if(v[now].size()==1)node1++;
            else if(v[now].size()==2)node2++;

            for(auto& next:v[now])q.push(next);

        }
        if(line && (node1 == 2 || node1 == 0 && node2 ==0))cnt++;
    }
    cout<<cnt;
}