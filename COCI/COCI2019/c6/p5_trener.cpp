#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const ll MOD = 1000000007;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    string s[n+1][k+1];
    unordered_map<string, int> idx;
    unordered_map<int, string> str;
    unordered_map<int, int> cnt;

    int idxCnt = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            cin >> s[i][j];
            if(idx.find(s[i][j]) == idx.end()) {
                idx[s[i][j]] = idxCnt;
                str[idxCnt] = s[i][j];
                cnt[idxCnt] = 1;
                idxCnt++;
            } 
            else {
                cnt[idx[s[i][j]]]++; 
            }
        }
    }

    vector<int> adj[idxCnt];
    ll dp[idxCnt];
    bool vis[idxCnt];
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));

    for(int i = 1; i < idxCnt; i++) {
        string cur = str[i]; int l = cur.length();
        string sub1 = cur.substr(0, l-1);
        string sub2 = cur.substr(1, l-1);
        if(idx.find(sub1) != idx.end()) adj[i].push_back(idx[sub1]);
        if(sub1 != sub2 && idx.find(sub2) != idx.end()) adj[i].push_back(idx[sub2]);
    }

    queue<int> q;
    for(int i = idxCnt-1; i >= 1; i--) {
        if(str[i].length() != n) break;
        dp[i] = 1;
        vis[i] = true;
        q.push(i);
    }

    ll ans = 0;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        dp[v] = (dp[v] * cnt[v]) % MOD;
        if(str[v].length() == 1) ans = (ans + dp[v]) % MOD;

        for(int u : adj[v]) {
            dp[u] = (dp[u] + dp[v]) % MOD;

            if(!vis[u]) {
                q.push(u);
                vis[u] = true;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}