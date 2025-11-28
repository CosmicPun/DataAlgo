#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,c,t;
    cin >> r >> c >> t;
    vector<vector<int>> v(r,vector<int>(c));
    vector<vector<bool>> visited(r,vector<bool>(c,false));
    queue<tuple<int,int,int>> q;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> v[i][j];
            if(v[i][j]==1)q.push({i,j,t});
        }
    }
    
    int cnt = 0;
    while(!q.empty()){
        auto [row,column,countt] = q.front();q.pop();
        if(row < 0 || column < 0 || row >= r || column >= c || visited[row][column] || v[row][column]==2 || countt<0 )continue;
        visited[row][column]=true;

        cnt++;
        q.push({row-1,column,countt-1});
        q.push({row,column+1,countt-1});
        q.push({row+1,column,countt-1});
        q.push({row,column-1,countt-1});
    }
    cout<<cnt;
}