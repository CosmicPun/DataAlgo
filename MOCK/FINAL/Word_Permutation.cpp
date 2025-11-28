#include <bits/stdc++.h>
using namespace std;

multiset<char> ms;
int n,cnt=0;
map<string,bool> ans;
vector<bool> visited(14,false);
string s;

void permu(int pos,string &x){
    if(pos==s.size()){
        ans[x]=true;
        return;
    }
    for(int i=0;i<s.size();i++){
        if(!visited[i]){
            visited[i]=true;
            x[pos] = s[i];
            permu(pos+1,x);
            visited[i]=false;
        }
    }
}

int main(){
    cin >> s;
    string res(s.size(),' ');
    for(auto&x : s)ms.insert(x);
    permu(0,res);
    cout << ans.size();
    for(auto &x : ans){
        cout << "\n" << x.first;
    }
}