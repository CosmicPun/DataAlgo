#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    queue<int> q;
    vector<int> v;
    q.push(m);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        v.push_back(tmp);
        int l = tmp*2+1;
        int r = tmp*2+2;
        if(l<n)q.push(l);
        if(r<n)q.push(r);
    }
    cout << v.size() << endl;
    for(auto &x:v)cout << x << " ";
}