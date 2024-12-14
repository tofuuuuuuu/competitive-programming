#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
const ll MAX = INT_MAX;

struct Edge {
    int v;
    ll w;

    Edge(int vertex, ll weight) {
        this->v = vertex;
        this->w = weight;
    }
};

class cmp {
public:
    bool operator() (Edge a, Edge b) {
        return a.w > b.w;
    }
};

vector<Edge> adj[MAXN];

void dijkstra(int v, ll dist[], int n) {
    for(int i = 0; i < n; i++) dist[i] = MAX;
    dist[v] = 0;
    priority_queue<Edge, vector<Edge>, cmp> q;
    q.emplace(Edge(v, 0));
    while(!q.empty()) {
        Edge e = q.top(); q.pop();
        if(e.w > dist[e.v]) continue;
        
        for(Edge i : adj[e.v]) {
            if(dist[i.v] > e.w + i.w) {
                dist[i.v] = e.w + i.w;
                q.emplace(Edge(i.v, dist[i.v]));
            }
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a].push_back(Edge(b, t));
        adj[b].push_back(Edge(a, t));
    }

    ll dist1[n];
    ll dist2[n]; 
    dijkstra(0, dist1, n);
    dijkstra(n-1, dist2, n);

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dist1[i] + dist2[i]);
    }

    cout << ans;

    return 0;
}