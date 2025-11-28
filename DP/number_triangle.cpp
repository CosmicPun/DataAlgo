#include <bits/stdc++.h>
using namespace std;

int arr[101][101];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin >> arr[i][j];
        }
    }
    if(n==1){
        cout << arr[0][0];
        return 0;
    }    
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            arr[i][j] = max(arr[i][j]+arr[i+1][j],arr[i][j]+arr[i+1][j+1]);
            //cout << arr[i][j] << " ";
        }
        //cout << "\n";
    }
    cout << arr[0][0];
}