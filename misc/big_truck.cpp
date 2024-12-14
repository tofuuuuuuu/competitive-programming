#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
const ll MAX = INT_MAX;

struct Edge {
    int v;
    ll w;
    ll col;

    Edge(int vertex, ll weight, ll col) {
        this->v = vertex;
        this->w = weight;
        this-> col = col;
    }
};

class cmp {
public:
    bool operator() (Edge a, Edge b) {
        if(a.w == b.w) return a.col < b.col;
        return a.w > b.w;
    }
};

vector<Edge> adj[MAXN];
int cnt[MAXN];

void dijkstra(int v, ll dist[], ll col[], int n) {
    bool vis[n+1];
    for(int i = 1; i <= n; i++) {
        dist[i] = MAX;
        col[i] = 0;
        vis[i] = false;
    }
    dist[v] = 0; col[v] = cnt[v];
    priority_queue<Edge, vector<Edge>, cmp> q;
    q.emplace(Edge(v, 0, col[v]));
    while(!q.empty()) {
        Edge e = q.top(); q.pop();
        if(vis[e.v]) continue;
        vis[e.v] = true;
        
        for(Edge i : adj[e.v]) {
            if(dist[i.v] > e.w + i.w) {
                dist[i.v] = e.w + i.w;
                col[i.v] = e.col + cnt[i.v];
                q.emplace(Edge(i.v, dist[i.v], col[i.v]));
            }
            else if(dist[i.v] == e.w + i.w && col[i.v] < e.col + cnt[i.v]) {
                col[i.v] = e.col + cnt[i.v];
                q.emplace(Edge(i.v, dist[i.v], col[i.v]));
            }
        }
    }

    if(dist[n] == MAX) cout << "impossible\n";
    else cout << dist[n] << " " << col[n] << "\n";
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> cnt[i];
    
    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a].push_back(Edge(b, t, 0));
        adj[b].push_back(Edge(a, t, 0));
    }

    ll dist[n+1];
    ll cnt[n+1];
    dijkstra(1, dist, cnt, n);

    return 0;
}