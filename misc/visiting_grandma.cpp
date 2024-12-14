#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define int long long int

const int MAXN = 2000;
const ll MOD = 1000000;
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
        if(a.w == b.w) return a.v > b.v;
        return a.w > b.w;
    }
};

vector<Edge> adj[MAXN];

void dijkstra(int v, ll dist[], ll cnt[], int n) {
    for(int i = 0; i < n; i++) {
        dist[i] = MAX;
        cnt[i] = 0;
    }

    dist[v] = 0;
    cnt[v] = 1;
    priority_queue<Edge, vector<Edge>, cmp> q;
    q.emplace(Edge(v, 0));

    while(!q.empty()) {
        Edge e = q.top(); q.pop();
        if(e.w > dist[e.v]) continue;
        
        for(Edge i : adj[e.v]) {
            if(dist[i.v] == e.w + i.w) {
                cnt[i.v] = (cnt[i.v] + cnt[e.v])%MOD;
            }
            if(dist[i.v] > e.w + i.w) {
                dist[i.v] = e.w + i.w;
                cnt[i.v] = cnt[e.v] % MOD;
                q.emplace(Edge(i.v, dist[i.v]));
            }
        }
    }
}

signed main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int t;
            cin >> t;
            if(t != 0) {
                adj[i].push_back(Edge(j, t));
                adj[n+i].push_back(Edge(n+j, t));
            }
        }
    }

    int m;
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int c;
        cin >> c;
        adj[c].clear();
        adj[c].push_back(Edge(n+c, 0));
    }

    ll dist[2*n+1]; 
    ll cnt[2*n+1];
    dijkstra(1, dist, cnt, 2*n+1);

    cout << dist[2*n] << " " << cnt[2*n]%MOD << "\n";
    return 0;
}