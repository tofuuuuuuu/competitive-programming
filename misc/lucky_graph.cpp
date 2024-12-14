#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

struct Edge{
    int v, idx;

    Edge(int v, int idx) {
        this->v = v;
        this->idx = idx;
    }
};

const int MAXN = 200005;
vector<Edge> adj[MAXN];
bool vis[MAXN];
unordered_set<int> removed;
unordered_set<int> dfsNodes;

int dfs(int v, int prev, int prevEdgeIdx) { 
    dfsNodes.emplace(v);
    int childCnt = 0;
    for(Edge e : adj[v]) {
        if(vis[e.v]) continue;
        vis[e.v] = true; 
        removed.erase(e.idx);

        childCnt += dfs(e.v, v, e.idx);
    }

    if((childCnt + 1) % 2 == 0) {
        removed.emplace(prevEdgeIdx);
        return 0;
    }
    return 1;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(Edge(b, i)); adj[b].push_back(Edge(a, i));
        removed.emplace(i);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        vis[i] = true;
        dfs(i, -1, 0);
        if(dfsNodes.size() % 2 == 1) {
            ans += dfsNodes.size() - 1;
        }
        else {
            ans += dfsNodes.size();
        }
        dfsNodes.clear();
    }
    removed.erase(0);

    cout << ans << "\n";
    cout << removed.size() << "\n";
    for(int i : removed) {
        cout << i << " ";
    }
    cout << "\n";
    
    return 0;
}