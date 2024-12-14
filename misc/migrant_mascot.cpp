#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 200005;
vector<pii> adj[MAXN];
int ans[MAXN];

pii new_pair(int a, int b) {
    pii p; p.first = a; p.second = b; return p;
}

void mst_prim(int n, int st) {
    int vis[n+1];
    memset(ans, 0, sizeof(ans));
    memset(vis, 0, sizeof(vis));

    priority_queue<pii> pq;
    pq.push(new_pair(INT_MAX, st));
    for(int i = 1; i <= n; i++) {
        pii v = pq.top();
        pq.pop();

        if(vis[v.second]) {i--; continue;}
        ans[v.second] = v.first;
        vis[v.second] = 1;

        for(auto e : adj[v.second]) {
            if(vis[e.second]) continue;
            pq.push(make_pair(min(v.first, e.first), e.second));
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back(new_pair(c, b));
        adj[b].push_back(new_pair(c, a));
    }

    mst_prim(n, 1);
    cout << 0 << "\n";
    for(int i = 2; i <= n; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}