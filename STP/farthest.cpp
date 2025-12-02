#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> dist(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> dist[i][j];
        }
    }
    
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k] != -1 && dist[k][j] != -1){
                    if(dist[i][j] == -1){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                    else dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }  
    }

    int Mx = -1;
    for(int i=0;i<n;i++){
        if(dist[0][i]==-1){
            cout << -1;
            return 0;
        }
        else Mx = max(Mx,dist[0][i]);
    }
    cout << Mx;
}