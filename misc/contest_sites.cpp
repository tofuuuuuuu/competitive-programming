#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
const ll MOD = 1000000007;
const ll BFN = (ll)1e17;
//const int BFN = (int)1e9;
int n, m, a, b, c; ll k;
ll cnt[MAXN];
ll dist1[MAXN];
ll dist2[MAXN];
vector<pii> dist;

struct Edge {
    int v; ll w;

    Edge(int v, ll w) {
        this->v = v;
        this->w = w;
    }
};
vector<Edge> adj[MAXN];

class cmp {
public:
    bool operator() (Edge a, Edge b) {
        if(a.w == b.w) return a.v > b.v;
        return a.w >= b.w;
    }
};

void dijkstra(int st, ll *dist) {
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
    cin >> n >> m >> k;
    for(int i = 0; i < MAXN; i++) {
        dist1[i] = BFN;
        dist2[i] = BFN;
    }
    for(int i = 1; i <= n; i++) {
        cin >> cnt[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        adj[b].push_back(Edge(a, c));
    }

    dijkstra(1, dist1);
    dijkstra(2, dist2);
    
    ll ans = 0, amt = 0;
    for(int i = 1; i <= n; i++) {
        if(dist1[i] >= BFN && dist2[i] >= BFN && cnt[i] != 0) {
            cout << "-1\n";
            return;
        } 
        else if(dist1[i] >= BFN) {
            amt += cnt[i];
            ans += dist2[i] * cnt[i];
        }
        else if(dist2[i] >= BFN) {
            ans += dist1[i] * cnt[i];
        }
        else if(dist1[i] <= dist2[i]) {
            ans += dist1[i] * cnt[i];
        }
        else {
            dist.push_back({dist2[i] - dist1[i], i});
        }
    }
    sort(dist.begin(), dist.end());

    if(amt > k) {
        cout << "-1\n";
        return;
    }

    for(pii p : dist) {
        if(amt + cnt[p.second] > k) {
            ans += dist2[p.second] * (k - amt) + dist1[p.second] * (cnt[p.second] - k + amt);
            amt = k;
        }
        else {
            ans += dist2[p.second] * cnt[p.second];
            amt += cnt[p.second];
        }
    }

    cout << ans << "\n";
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}