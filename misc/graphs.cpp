#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll ,ll>

#define scanu(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MAXN = 100005;
const ll MOD = 1000000007;
//const ll BFN = (ll)1e17;
const int BFN = (int)2e9;
int n, m, q, a, b, v;
vector<int> adj[MAXN];
int dist[MAXN];

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T>
// using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// Tree<int> tr;

int bfs(int a, int b) {
    memset(dist, 0, sizeof(dist));
    queue<int> qu1;
    queue<int> qu2;

    dist[a] = 1; dist[b] = -1; 
    qu1.push(a); qu2.push(b);
    while(!qu1.empty() || !qu2.empty()) {
        int sz = qu1.size();
        for(int cnt = 1; cnt <= sz; cnt++) {
            v = qu1.front(); qu1.pop();

            for(int i : adj[v]) {
                if(dist[i] > 0) continue;
                if(dist[i] < 0) return dist[v] - dist[i] - 1;
                dist[i] = dist[v] + 1;
                qu1.push(i);
            }
        }

        sz = qu2.size();
        for(int cnt = 1; cnt <= sz; cnt++) {
            v = qu2.front(); qu2.pop();

            for(int i : adj[v]) {
                if(dist[i] < 0) continue;
                if(dist[i] > 0) return -dist[v] + dist[i] - 1;
                dist[i] = dist[v] - 1;
                qu2.push(i);
            }
        }
    }
    return -1;
}

struct DSU{
    int p[MAXN];
    int sz[MAXN];

    void init(int n) {
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
} dsu;

void sol() {
    scanu(n); scanu(m); scanu(q);
    dsu.init(n);
    for(int i = 1; i <= m; i++) {
        scanu(a); scanu(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        dsu.merge(a, b);
    }

    for(int i = 1; i <= q; i++) {
        scanu(a); scanu(b);
        if(dsu.find(a) != dsu.find(b)) cout << "-1\n";
        else if(a == b) cout << "0\n";
        else cout << bfs(a, b) << "\n";
    }
}


int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}