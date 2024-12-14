#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 20005;
int n;
vector<int> adj[MAXN];
int sz[MAXN];
int ans[MAXN];

void dfs(int v, int prev) {
    sz[v] = 1;
    int maxSt = 0;
    for(int i : adj[v]) {
        if(i == prev) continue;

        dfs(i, v);
        sz[v] += sz[i];
        maxSt = max(maxSt, sz[i]);
    }
    ans[v] = max(maxSt, n - sz[v]);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int a, b; cin >> n;
    for(int i = 1; i <= n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 1);

    int retN = 0;
    int ret = INT_MAX;
    for(int i = 1; i <= n; i++) {
        if(ans[i] < ret) {
            ret = ans[i];
            retN = i;
        }
    }

    cout << retN << " " << ret << "\n";
    
    return 0;
}