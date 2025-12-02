#include <bits/stdc++.h>
using namespace std;

#define edge tuple<int,int,int>

int main(){
    int r,c;
    cin >> r >> c;
    vector<vector<int>> v(r+2,vector<int>(c+2));
    vector<vector<bool>> visited(r+2,vector<bool>(c+2,false));
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> v[i][j];
        }
    }
    priority_queue<edge,vector<edge>,greater<edge>> pq;
    pq.push({0,1,1});
    while(pq.size()){
        auto [w,x,y] = pq.top();pq.pop();
        if(x<1 || y<1 || x>r || y>c || visited[x][y])continue;
        visited[x][y] = true;

        v[x][y] = w;

        pq.push({v[x-1][y]+w,x-1,y});
        pq.push({v[x+1][y]+w,x+1,y});
        pq.push({v[x][y-1]+w,x,y-1});
        pq.push({v[x][y+1]+w,x,y+1});
    }

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}