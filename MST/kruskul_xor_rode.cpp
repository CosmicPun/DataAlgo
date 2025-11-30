#include <bits/stdc++.h>
using namespace std;

#define edge tuple<size_t,int,int>

int findhead(int x,vector<int> &heads){
    if(heads[x]==x)return x;
    return heads[x] = findhead(heads[x],heads);
}

void connect(int st,int en,vector<int> &heads){
    heads[findhead(en,heads)] = findhead(st,heads);
}

int main(){
    int n;
    cin >> n;
    
    priority_queue<edge> pq;
    vector<int> node(n);
    vector<int> head(n);    

    for(int i=0;i<n;i++){
        cin >> node[i];
        head[i] = i;
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            pq.push({node[i] ^ node[j],i,j});
        }
    }

    size_t sum=0;
    while(!pq.empty()){
        auto [w,st,en] = pq.top();pq.pop();
        if(findhead(st,head)!=findhead(en,head)){
            connect(st,en,head);
            sum+=w;
        }   
    }
    cout << sum;
}