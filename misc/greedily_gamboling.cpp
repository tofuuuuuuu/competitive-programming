#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const ll MAXN = 20005;
const ll MAX = (ll)9e10;

struct Edge {
    int v; ll w;

    Edge(int vertex, ll weight) {
        this->v = vertex;
        this->w = weight;
    }
};

struct DijkstraE {
    int v, msk; ll w;

    DijkstraE(int vertex, ll weight, int msk) {
        this->v = vertex;
        this->w = weight;
        this->msk = msk;
    }
};

class cmp {
public:
    bool operator() (DijkstraE a, DijkstraE b) {
        return a.w > b.w;
    }
};

vector<Edge> adj[MAXN];
int toggles[10];

ll dijkstra(int st, int n, int k) {
    int MAXMSK = (1 << k);
    ll dist[n][MAXMSK];
    bool vis[n][MAXMSK];
    for(int i = 0; i < n; i++) {
        for(int msk = 0; msk < MAXMSK; msk++) {
            vis[i][msk] = false;
            dist[i][msk] = MAX;
        }
    }
    dist[st][0] = 0;

    priority_queue<DijkstraE, vector<DijkstraE>, cmp> q;
    q.emplace(DijkstraE(st, 0, 0));
    while(!q.empty()) {
        DijkstraE e = q.top(); q.pop();
        if(vis[e.v][e.msk]) continue;
        vis[e.v][e.msk] = true;
        
        for(Edge i : adj[e.v]) {
            int newMsk = e.msk;
            ll curW = i.w;
            for(int mskIdx = 0; mskIdx < k; mskIdx++) {
                if(((1 << mskIdx) & e.msk) > 0) continue;
                if(((1 << (toggles[mskIdx])) & curW) == 0) continue;
                curW = curW - (1 << (toggles[mskIdx]));
                newMsk = newMsk + (1 << mskIdx);
            }

            ll newDist = e.w + curW;
            if(dist[i.v][newMsk] > newDist) {
                dist[i.v][newMsk] = newDist;
                q.emplace(DijkstraE(i.v, newDist, newMsk));
            }
        }
    }

    ll ans = MAX;
    for(int msk = 0; msk < MAXMSK; msk++) {
        ans = min(ans, dist[n-1][msk]);
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        int t; cin >> t;
        toggles[i] = t;
    }
    for(int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(Edge(b, w));
        adj[b].push_back(Edge(a, w));
    }

    cout << dijkstra(1, n+1, k) << "\n";
    return 0;
}