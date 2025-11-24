#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); 
    map<int,priority_queue<int,vector<int>,greater<int>>> items;
    queue<vector<int>> demon;
    int n,d,t,z,cnt=0;
    cin >> n >> d >> t >> z;
    // item -> dungeon
    for(int i=0;i<d;i++){
        int time,key;
        cin>>time>>key;
        items[key].push(time);
    }
    // demon queue
    for(int i=0;i<n;i++){
        vector<int> v;
        int m,input;
        cin>>m;
        while(m--){
            cin>>input;
            v.push_back(input);
        }
        if(m!=0)demon.push(v);
    }
    // check demon can slay?
    while(!demon.empty()){
        //call demon
        auto cur_demon = demon.front();
        demon.pop();
        
        int total_stamina = 0;
        for(auto x:cur_demon){
            if(!items[x].empty()){
                total_stamina += items[x].top();
                items[x].pop();
            }
            else {
                cout << cnt;
                return 0;
            }
        }
        t -= total_stamina;
        if(t>=0)cnt++;
        else break;
        //cout<<total_stamina << "<---------------\n";
    }
    cout << cnt;
}