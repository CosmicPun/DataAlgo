#include <bits/stdc++.h>
using namespace std;

int find_head(int x, vector<int>& node){
    if(node[x] == x)return x;
    return node[x] = find_head(node[x],node);
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int v,e;
        cin >> v >> e;
        bool cycle = false;
        vector<int> node(v+1);
        for(int i=0;i<=v;i++)node[i] = i;
        while(e--){
            int st,en;
            cin >> st >> en;
            if(find_head(st,node) == find_head(en,node)){
                cycle = true;
            }
            else {
                node[find_head(en,node)] = find_head(st,node);
            }
        }
        cout << (cycle ? "YES\n" : "NO\n");
    }
}