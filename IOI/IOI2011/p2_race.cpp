#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

const int MAXN = 200005;
ll ans = MAXN;
int k;
struct Edge {
    int v;
    ll w;

    Edge(int vertex, ll weight) {
        this->v = vertex;
        this->w = weight;
    }
};
vector<Edge> adj[MAXN];
bool removed[MAXN];
int sz[MAXN];
vector<pii> subtreeD;
map<ll, ll> distM;

void findSz(int v, int prev) {
    sz[v] = 1;
    for(Edge e : adj[v]) {
        if(e.v == prev || removed[e.v]) continue;
        findSz(e.v, v);
        sz[v] += sz[e.v];
    }
}

int findCentroid(int v, int prev, int total) {
    for(Edge e : adj[v]) {
        if(e.v == prev || removed[e.v]) continue;

        if(2*sz[e.v] >= total) return findCentroid(e.v, v, total);
    }
    return v;
}

void dfs(int v, int prev, ll curDist, int edgeCnt) {
    if(curDist > k) return;
    subtreeD.push_back({curDist, edgeCnt});
    if(distM.find(k - curDist) != distM.end()) ans = min(ans, distM[k - curDist] + edgeCnt);
    for(Edge e: adj[v]) {
        if(e.v == prev || removed[e.v]) continue;

        dfs(e.v, v, curDist + e.w, edgeCnt + 1);
    }
}

void fun(int v) {
    findSz(v, v);
    int centroid = findCentroid(v, v, sz[v]); removed[centroid] = true;
    subtreeD.clear();
    distM.clear();

    distM[0] = 0;
    for(Edge e : adj[centroid]) {
        if(removed[e.v]) continue;

        dfs(e.v, centroid, e.w, 1);
        for(pii p : subtreeD) {
            if(distM.find(p.first) == distM.end()) distM[p.first] = p.second;
            else distM[p.first] = min(distM[p.first], p.second);
        }
        subtreeD.clear();
    }

    for(Edge e : adj[centroid]) {
        if(removed[e.v]) continue;

        fun(e.v);
    }
}

int best_path(int N, int K, int H[][2], int L[]) {
    k = K;
    for(int i = 0; i < N-1; i++) {
        adj[H[i][0]].push_back(Edge(H[i][1], L[i]));
        adj[H[i][1]].push_back(Edge(H[i][0], L[i]));
    }

    fun(0);
    if(ans == MAXN) return -1;
    return (int)ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    return 0;
}