#include <bits/stdc++.h>
using namespace std;
#define ll long long

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T>
// using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// Tree<ll> tr;

#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

// #define scanu(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
// char _;

const int MAXN = 2005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, m, u, v, l, c;

struct Edge {
    int v, w, c;

    Edge(int x, int y, int z) {
        v = x; w = y; c = z;
    }
};

class cmp {
public:
    bool operator() (Edge a, Edge b) {
        if(a.w == b.w) return a.c < b.c;
        return a.w > b.w;
    }
};

struct Edge2 {
    int v, u, w, c;

    Edge2(int x, int vTo, int y, int z) {
        v = x; u = vTo; w = y; c = z;
    }
};

bool cmp2(Edge2 &a, Edge2 &b) {
    return a.c < b.c;
}

bool cmp3(Edge2 &a, Edge2 &b) {
    if(a.w == b.w) return a.c < b.c;
    return a.w < b.w;
}

vector<Edge2> allEdges;
vector<Edge2> zeroEdges;
vector<Edge> adj[MAXN];

int p[MAXN];
int sz[MAXN];

void init() {
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
}

int find(int v) {
    if(p[v] != v) p[v] = find(p[v]);
    return p[v];
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;
    
    if(sz[a] < sz[b]) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
    return true;
}

bool vis[MAXN][MAXN];
ll dist[MAXN][MAXN];

void dijkstra(int st) {
    for(int i = 1; i <= n; i++) {
        dist[st][i] = BFN;
        vis[st][i] = false;
    }
    dist[st][st] = 0;
    priority_queue<Edge, vector<Edge>, cmp> q;
    q.emplace(Edge(st, 0, 0));
    while(!q.empty()) {
        Edge e = q.top(); q.pop();
        if(vis[st][e.v]) continue;
        vis[st][e.v] = true;
        
        for(Edge i : adj[e.v]) {
            if(dist[st][i.v] > e.w + i.w) {
                dist[st][i.v] = e.w + i.w;
                q.emplace(Edge(i.v, dist[st][i.v], 0));
            }
        }
    }
}

void sol() {
    cin >> n >> m;
    init();
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> l >> c;
        if(u == v) continue;

        allEdges.push_back(Edge2(u, v, l, c));
        if(l == 0) zeroEdges.push_back(Edge2(u, v, l, c));
    }

    ll ans = 0;
    sort(zeroEdges.begin(), zeroEdges.end(), cmp2);
    sort(allEdges.begin(), allEdges.end(), cmp3);
    for(auto e : zeroEdges) {
        if(merge(e.u, e.v)) {
            ans += 2*e.c;
        }
    }

    for(auto e : allEdges) {
        int a = find(e.u), b = find(e.v);
        if(a == b) continue;
        if(e.w == 0) continue;
        if(dist[a][b] != 0) continue;

        adj[a].push_back(Edge(b, e.w, e.c));
        adj[b].push_back(Edge(a, e.w, e.c));
        dist[a][b] = dist[b][a] = e.w;
    }

    for(int i = 1; i <= n; i++) {
        if(find(i) != i) continue;
        dijkstra(i);
    }

    for(int i = 1; i <= n; i++) {
        if(find(i) != i) continue;

        for(Edge e : adj[i]) {
            bool good = true;
            for(int j = 1; j <= n; j++) {
                if(j == i) continue;
                if(j == e.v) continue;
                if(dist[i][j] + dist[j][e.v] <= e.w) {
                    good = false;
                    break;
                }
            }

            if(good) ans += e.c;
        }
    }

    cout << ans / 2 << "\n";
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}