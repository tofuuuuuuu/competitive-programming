#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

const int MAXN = 500005;
vector<int> adj[MAXN];
vector<int> leafs;

void dfs(int v, int prev) {
    if(adj[v].size() == 1) {
        leafs.push_back(v);
    }

    for(int i : adj[v]) {
        if(i == prev) continue;
        dfs(i, v);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n; 
    for(int i = 1; i <= n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }

    dfs(1, 1);
    int sz = leafs.size();

    cout << (sz+1)/2 << "\n"; 
    for(int i = 0; i < (sz + 1)/2; i++) {
        cout << leafs[i] << " " << leafs[i + sz/2] << "\n";
    }

    return 0;
}