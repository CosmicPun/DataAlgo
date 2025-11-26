#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(40,vector<int>(40,-1));

int cnk(int n,int r){
    if(r==n)return 1;
    if(r==0)return 1;

    if(v[n][r] != -1)return v[n][r];
    int result = cnk(n-1,r) + cnk(n-1,r-1);
    v[n][r] = result;
    return result;
}

int main(){
    int n,r;
    cin >> n >> r;
    cout << cnk(n,r);
}