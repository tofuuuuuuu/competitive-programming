#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 300005;
int n, m, a, b;
vector<int> adj[MAXN];
bool vis[MAXN];
int ans [MAXN];

void dfs(int v, int st) {
    if(vis[v]) return;

    ans[v] = st;
    vis[v] = true;
    for(int i : adj[v]) {
        if(vis[i]) continue;

        dfs(i, st);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> m;
    bool possible = false;
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        adj[b].push_back(a);

        if(b > a) possible = true;
    }

    if(!possible) {
        cout << "-1\n";
        return 0;
    }

    for(int y = n; y >= 1; y--) {
        if(vis[y]) continue;
        dfs(y, y);
    }

    for(int i = n-1; i >= 1; i--) {
        if(ans[i] == i) continue;

        cout << i << " " << ans[i] << "\n";
        break;
    }

    return 0;
}