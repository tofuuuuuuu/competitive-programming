#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
const ll MOD = 1000000007;
const ll BFN = (ll)1e17;
//const int BFN = (int)1e9;
int n, m, a, b, c;
int t[MAXN];
ll dist[4*MAXN];

struct Edge {
    int v; ll w;

    Edge(int v, ll w) {
        this->v = v;
        this->w = w;
    }
};
vector<Edge> adj[4*MAXN];

class cmp {
public:
    bool operator() (Edge a, Edge b) {
        if(a.w == b.w) return a.v > b.v;
        return a.w >= b.w;
    }
};

void dijkstra(int st) {
    priority_queue<Edge, vector<Edge>, cmp> pq;
    dist[st] = 0;
    pq.push(Edge(st, 0));

    while(!pq.empty()) {
        Edge e = pq.top(); pq.pop();
        
        for(Edge i : adj[e.v]) {
            if(dist[i.v] > e.w + i.w) {
                dist[i.v] = e.w + i.w;
                pq.push(Edge(i.v, dist[i.v]));
            }
        }
    }
}

void sol() { 
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for(int i = 0; i < 4*MAXN; i++) {
        dist[i] = BFN;
    }
    for(int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back(Edge(b, c));
        adj[a+n].push_back(Edge(b+n, c));
        adj[a+2*n].push_back(Edge(b+2*n, c));
        adj[a+3*n].push_back(Edge(b+3*n, c));
        adj[b].push_back(Edge(a, c));
        adj[b+n].push_back(Edge(a+n, c));
        adj[b+2*n].push_back(Edge(a+2*n, c));
        adj[b+3*n].push_back(Edge(a+3*n, c));
    }
    for(int i = 1; i <= n; i++) {
        if(t[i] == 1) {
            adj[i].clear();
            adj[i].push_back(Edge(i+n, 0));
        }
        else if(t[i] == 2) {
            adj[i+n].clear();
            adj[i+n].push_back(Edge(i+2*n, 0));
        }
        else if(t[i] == 3) {
            adj[i+2*n].clear();
            adj[i+2*n].push_back(Edge(i+3*n, 0));
        }
    }

    dijkstra(1);
    ll ans = BFN;
    for(int i = 1; i <= n; i++) {
        if(t[i] == 4) {
            ans = min(ans, dist[i+3*n]);
        }
    }
        
    if(ans == BFN) cout << "-1\n";
    else cout << ans << "\n";
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}