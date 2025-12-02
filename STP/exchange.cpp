#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        vector<vector<double>> v(m,vector<double>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                cin >> v[i][j];
            }
        }
        for(int k=0;k<m;k++){
            for(int i=0;i<m;i++){
                for(int j=0;j<m;j++){
                    v[i][j] = max(v[i][j],v[i][k]*v[k][j]);
                }
            }
        }
        bool flag = false;
        for(int i=0;i<m;i++){
            if(v[i][i]>1){
                flag = true;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}