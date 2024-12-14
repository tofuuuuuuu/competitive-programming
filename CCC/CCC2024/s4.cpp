#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 200005;
const ll MOD = 1000000007;
const ll BFN = (ll)1e16;
int n, m, a, b;
vector<pii> adj[MAXN];
bool vis[MAXN];
int ans[MAXN];

void dfs(int v, int prevC) {
    vis[v] = true;
    for(auto i : adj[v]) {
        if(vis[i.first]) continue;

        if(prevC == 1) ans[i.second] = 2;
        else ans[i.second] = 1;

        dfs(i.first, ans[i.second]); 
    }
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;

        dfs(i, 1);
    }

    for(int i = 1; i <= m; i++) {
        if(ans[i] == 1) cout << 'R';
        else if(ans[i] == 2) cout << 'B';
        else cout << 'G';
    }
    cout << "\n";

    return 0;
}