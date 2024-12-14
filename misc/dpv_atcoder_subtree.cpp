#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
ll MOD;
vector<int> adj[MAXN];
ll dp1[MAXN];
ll dp2[MAXN];

void dfs1(int v, int prev) {
    dp1[v] = 1;
    for(auto i : adj[v]) {
        if(i == prev) continue;
        dfs1(i, v);
        dp1[v] = dp1[v]*(dp1[i]) % MOD;
    }
    dp1[v] = (dp1[v] + 1) % MOD;
}

void dfs2(int v, int prev) {
    int sz = adj[v].size();
    ll pre[sz+2];
    ll suf[sz+2];
    for(int i = 0; i <= sz+1; i++) {
        pre[i] = 1; suf[i] = 1;
    }

    int cnt = 1;
    for(auto i : adj[v]) {
        if(i == prev) continue;
        pre[cnt] = dp1[i];
        suf[cnt] = dp1[i];
        cnt++;
    }
    for(int i = 1; i <= sz + 1; i++) {
        pre[i] = (pre[i]*pre[i-1]) % MOD;
    }
    for(int i = sz; i >= 0; i--) {
        suf[i] = (suf[i]*suf[i+1]) % MOD;
    }

    cnt = 1;
    for(auto i : adj[v]) {
        if(i == prev) continue;
        ll prod = (pre[cnt-1] * suf[cnt+1]) % MOD;
        dp2[i] = ((prod * dp2[v]) % MOD + 1) % MOD;
        cnt++;
        dfs2(i, v);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n >> MOD;
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }

    dfs1(1, 1);
    dp2[1] = 1;
    dfs2(1, 1);
    
    for(int i = 1; i <= n; i++) {
        ll ans = (dp2[i])*(dp1[i]-1)%MOD;
        if(ans < 0) ans += MOD;
        cout << ans << "\n";
    }
    return 0;
}