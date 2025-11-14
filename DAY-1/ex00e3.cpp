#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); std::cin.tie(0); 
    int N;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; ++i) cin >> S[i];
    unordered_set<int> seen;

    for (int x : S) {
        if (x < 1 || x > N) {
            cout << "NO\n";
            return 0;
        }
        if (!seen.insert(x).second) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
