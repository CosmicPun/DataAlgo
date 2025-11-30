#include <bits/stdc++.h>
using namespace std;

int find_head(int x, vector<int>& node){
    if(node[x] == x)return x;
    return node[x] = find_head(node[x],node);
}

void connect(int st,int en,vector<int> &heads){
    heads[find_head(en,heads)] = find_head(st,heads);
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
            else connect(st,en,node);
        }
        cout << (cycle ? "YES\n" : "NO\n");
    }
}