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

const int MAXN = 100005;
const ll MOD = 1000000007;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, m, a, b, c;
int p[MAXN];
int sz[MAXN];

struct Edge{
    int a, b, w, idx;
     Edge(int x, int y, int z, int p) {
        a = x; b = y; w = z; idx = p;
     }
};

bool cmp(Edge &a, Edge &b) {
    return a.w < b.w;
}

vector<Edge> ls;
vector<Edge> queries;

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

const int LOG = 16;
vector<pii> adj[MAXN];
int depth[MAXN];
int lft[MAXN][LOG];
int lftMax[MAXN][LOG];
int scdMax[MAXN][LOG];

vector<int> vect;
pii findMaxes() {
    sort(vect.begin(), vect.end(), greater<int>());
    int mx = vect[0], scd = -1;
    for(int i : vect) {
        if(i == mx) continue;
        scd = i;
        break;
    }
    return {mx, scd};
}

void initLft(int v, int prev, int w) {
    depth[v] = depth[prev] + 1;
    lft[v][0] = prev; 
    lftMax[v][0] = w; scdMax[v][0] = -1;
    for(int i = 1; i < LOG; i++) {
        lft[v][i] = lft[lft[v][i-1]][i-1];

        vect.clear();
        vect.push_back(lftMax[v][i-1]); vect.push_back(scdMax[v][i-1]);
        vect.push_back(lftMax[lft[v][i-1]][i-1]); vect.push_back(scdMax[lft[v][i-1]][i-1]);
        pii res = findMaxes();
        lftMax[v][i] = res.first; scdMax[v][i] = res.second;
    }

    for(pii i : adj[v]) {
        if(i.first == prev) continue;
        initLft(i.first, v, i.second);
    }
}

pii query(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);

    pii mxA = {-1, -1}, mxB = {-1, -1};
    for(int i = LOG-1; i >= 0; i--) {
        if(depth[lft[a][i]] >= depth[b]) {
            vect.clear();
            vect.push_back(mxA.first); vect.push_back(mxA.second); vect.push_back(lftMax[a][i]); vect.push_back(scdMax[a][i]);
            mxA = findMaxes();

            a = lft[a][i];
        }
    }

    if(a == b) return mxA;

    for(int i = LOG-1; i >= 0; i--) {
        if(lft[a][i] != lft[b][i]) {
            vect.clear();
            vect.push_back(mxA.first); vect.push_back(mxA.second); vect.push_back(lftMax[a][i]); vect.push_back(scdMax[a][i]);
            mxA = findMaxes();
            
            vect.clear();
            vect.push_back(mxB.first); vect.push_back(mxB.second); vect.push_back(lftMax[b][i]); vect.push_back(scdMax[b][i]);
            mxB = findMaxes();

            a = lft[a][i];
            b = lft[b][i];
        }    
    }
    
    vect.clear();
    vect.push_back(mxA.first); vect.push_back(mxA.second); vect.push_back(lftMax[a][0]); vect.push_back(scdMax[a][0]);
    vect.push_back(mxB.first); vect.push_back(mxB.second); vect.push_back(lftMax[b][0]); vect.push_back(scdMax[b][0]);
    return findMaxes();
}

void sol() {
    cin >> n >> m;
    if(m < n-1) {
        cout << "-1\n";
        return;
    }

    for(int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        ls.push_back(Edge(a, b, c, i));
    }
    sort(ls.begin(), ls.end(), cmp);
    init();

    int tot = 0;
    int cnt = 0;
    for(auto e : ls) {
        if(merge(e.a, e.b)) {
            adj[e.a].push_back({e.b, e.w});
            adj[e.b].push_back({e.a, e.w});
            tot += e.w;
            cnt++;
        }
        else {
            queries.push_back(e);
        }
    }

    if(cnt != n-1) {
        cout << "-1\n";
        return;
    }

    initLft(1, 1, -1);

    int maxAns = BFN;
    for(auto e : queries) {
        pii curAns = query(e.a, e.b);
        int bruh = curAns.first;
        if(bruh >= e.w) {
            if(curAns.second == -1) continue;
            bruh = curAns.second;
        }
        
        maxAns = min(maxAns, e.w - bruh);
    }   

    if(maxAns == BFN) {
        cout << "-1\n";
        return;
    }

    cout << tot + maxAns << "\n";
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();
    cout << "\n";

    return 0;
}