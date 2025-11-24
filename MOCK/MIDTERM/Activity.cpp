#include <bits/stdc++.h>
using namespace std;

vector<string> order;
unordered_set<string> event;
unordered_map<string,string> name;
unordered_map<string,set<string>> eventList;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int n;
    cin >> n;
    while(n--){  
        string s,input,x,y;
        getline(cin>>ws,s);
        stringstream ss(s);
        ss >> input;
        //store order
        if(input == "REGISTER" || input == "CANCEL")order.push_back(s);

        if(input == "ADDEVENT"){
            ss >> x;
            event.insert(x);
        }
        else if(input == "REGISTER"){
            ss >> x >> y;
            if(event.find(x) == event.end())event.insert(x);
            if(name[y] == ""){
                name[y] = x;
                eventList[x].insert(y);
            }
        }
        else if(input == "CANCEL"){
            ss >> x >> y;
            if(name[y] != ""){
                name[y] = "";
                eventList[x].erase(y);
            }
        }
        else if(input == "SHOW"){
            ss >> x;
            for(auto &ans:eventList[x]){
                cout << ans << " ";
            }
            cout << endl;
        }
        else if(input == "UNDO"){
            if(order.size() == 0)continue;
            string last = order.back();
            stringstream ls(last);
            ls >> input;
            if(input == "REGISTER"){
                ls >> x >> y;
                name[y] = "";
                eventList[x].erase(y);
            }
            else if(input == "CANCEL"){
                ls >> x >> y;
                name[y] = x;
                eventList[x].insert(y);
            }
        }
    }
    //for(auto &x:v)cout<<x<<endl;
    //for(auto &xx:v){
    //}
}