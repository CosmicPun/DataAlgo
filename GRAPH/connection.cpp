#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, E, K;
    cin >> N >> E >> K;
    vector<vector<int>> v(N);

    while (E--)
    {
        int st, en;
        cin >> st >> en;
        v[st].push_back(en);
        v[en].push_back(st);
    }
    int Mx = 0;
    for (int i = 0; i < N; i++)
    {
        vector<bool> mark(N);
        queue<pair<int, int>> s;
        int cnt = 0;
        s.push({i, 0});
        while (!s.empty())
        {
            auto [now, friends] = s.front();
            s.pop();
            if (mark[now] || friends > K)
                continue;
            mark[now] = true;
            cnt++;
            for (auto &next : v[now])
                s.push({next, friends + 1});
        }
        Mx = max(Mx, cnt);
    }
    cout << Mx;
}