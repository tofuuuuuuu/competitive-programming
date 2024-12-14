#include <bits/stdc++.h>
using namespace std;
#define ll long long

// #define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 500005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, k, x;
const int LOG = 21;
vector<pii> adj[MAXN];
int level[MAXN];
int par[MAXN];
ll dist[MAXN][LOG];

int sz[MAXN];
bool removed[MAXN];

void find_sz(int v, int prev) {
    sz[v] = 1;
    for(pii i : adj[v]) {
        if(i.first == prev || removed[i.first]) continue;
        find_sz(i.first, v);
        sz[v] += sz[i.first]; 
    }
}

int find_centroid(int v, int prev, int nodeAmt) {
    int centroid = v;
    for(pii i : adj[v]) {
        if(i.first == prev || removed[i.first]) continue;
        if(2*sz[i.first] >= nodeAmt) {
            return find_centroid(i.first, v, nodeAmt);
        }
    }
    return centroid;
}

void find_dist(int v, int prev, int lvl) {
    for(pii i : adj[v]) {
        if(i.first == prev || removed[i.first]) continue;
        dist[i.first][lvl] = dist[v][lvl] + i.second;
        find_dist(i.first, v, lvl);
    }
}

void make_centroid(int v, int prevCentroid, int lvl) {
    find_sz(v, v);
    int centroid = find_centroid(v, v, sz[v]);
    level[centroid] = lvl;

    par[centroid] = prevCentroid;
    find_dist(centroid, centroid, lvl);
    
    removed[centroid] = true;
    for(pii i : adj[centroid]) {
        if(removed[i.first]) continue;

        make_centroid(i.first, centroid, lvl+1);
    }
}

stack<int> changed_lst;
ll minDist[MAXN];

void initQuery() {
    while(!changed_lst.empty()) {
        minDist[changed_lst.top()] = BFN;
        changed_lst.pop();
    }
}

void update(int v) {
    int cur = v;
    int lvl = level[cur];
    while(lvl >= 1) {
        changed_lst.push(cur);
        minDist[cur] = min(minDist[cur], dist[v][lvl]);
        cur = par[cur];
        lvl--;
    }
}

ll query(int v) {
    ll ret = BFN;
    int cur = v;
    int lvl = level[cur];
    while(lvl >= 1) {
        ret = min(ret, minDist[cur] + dist[v][lvl]);
        cur = par[cur];
        lvl--;
    }
    return ret;
}

void Init(int N, int A[], int B[], int D[]) {
    n = N;
    for(int i = 0; i < N-1; i++) {
        adj[A[i] + 1].push_back({B[i] + 1, D[i]});
        adj[B[i] + 1].push_back({A[i] + 1, D[i]});
    }

    make_centroid(1, 0, 1);

    for(int i = 1; i <= n; i++) {
        minDist[i] = BFN;
    }
}

long long Query(int S, int X[], int T, int Y[]) {
    initQuery();

    for(int i = 0; i < S; i++) {
        update(X[i] + 1);
    }

    ll ans = BFN;
    for(int i = 0; i < T; i++) {
        ans = min(ans, query(Y[i] + 1));
    }

    return ans;
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    // int a[6] = {0, 1, 2, 2, 4, 1};
    // int b[6] = {1, 2, 3, 4, 5, 6};
    // int c[6] = {4, 4, 5, 6, 5, 3};
    // Init(7, a, b, c);
    // int x[2] = {0, 6}; 
    // int y[2] = {3, 4};
    // cout << Query(2, x, 2, y) << "\n"; //returns 12.
    // int x2[3] = {0, 1, 3};
    // int y2[2] = {4, 6};
    // cout << Query(3, x2, 2, y2) << "\n"; //returns 3.
    // int x3[1] = {2};
    // int y3[1] = {5};
    // cout << Query(1, x3, 1, y3) << "\n"; //returns 11.

    return 0;
}