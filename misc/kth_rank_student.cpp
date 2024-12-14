#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll ,ll>

const int MAXN = 100005;
const ll MOD = 1000000007;
//const ll BFN = (ll)1e17;
const ll BFN = (int)2e9;
int n, m, a, b, q, k; char t;
int r[MAXN];

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
Tree<pii> tr[MAXN];

struct DSU{
    int p[MAXN];
    int sz[MAXN];

    void init(int n) {
        for(int i = 1; i <= n; i++) {
            p[i] = i;
            sz[i] = 1;
            tr[i].insert({r[i], i});
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
        p[b] = a; //merge b onto a
        
        auto ptr = tr[b].begin();
        while(ptr != tr[b].end()) {
            tr[a].insert(*ptr);
            ptr++;
        }

        sz[a] += sz[b];
        return true;
    }
} dsu;

void sol() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    dsu.init(n);
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        dsu.merge(a, b);
    }

    cin >> q;
    pii ans = {-1, -1};
    for(int i = 1; i <= q; i++) {
        cin >> t;
        if(t == 'Q') {
            cin >> a >> k;
            a = dsu.find(a);
            
            if(tr[a].size() < k) ans = {-1, -1};
            else ans = *tr[a].find_by_order(k-1);

            cout << ans.second << "\n";
        }
        else {
            cin >> a >> b;
            dsu.merge(a, b);
        }
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