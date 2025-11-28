#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n,cnt=0;
    cin >> m >> n;
    vector<vector<int>> v(m+1);

    while(n--){
        int st,en;
        cin >> st >> en;
        v[st].push_back(en);
        v[en].push_back(st);
    }

    vector<bool> visited(m+1,false);
    
    for(int i=1;i<=m;i++){
        if(visited[i])continue;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int now = q.front();q.pop();
            if(visited[now])continue;
            visited[now]=true;
            for(auto& x:v[now])q.push(x);
        }
        cnt++;
    }
    cout << cnt;
}