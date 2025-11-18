#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    map<string,int> votes;
    while(n--) {
        string name;
        cin >> name;
        votes[name]++;
    }
    priority_queue<int> pq;
    for(auto &v : votes){
        pq.push(v.second);
    }
    k--;
    while(k--)pq.pop();
    cout << pq.top();
}