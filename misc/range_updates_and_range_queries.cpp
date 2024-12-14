#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 1000005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, m, q, x, y, qType;
int a[MAXN];
vector<int> adj[MAXN];
int ans[MAXN];
bool vis[MAXN];

struct Segtree1 {
    ll seg[4*MAXN];
    ll lazy[4*MAXN];

    void pushup(int cur) {
        seg[cur] = seg[2*cur] + seg[2*cur+1];
    }

    void pushdown(int cur, int l, int r){
        if(lazy[cur] == 0) return;

        seg[cur] = seg[cur] + (r-l+1)*lazy[cur];
        if(l != r){
            lazy[2*cur] = lazy[2*cur] + lazy[cur];
            lazy[2*cur+1] = lazy[2*cur+1] + lazy[cur];
        }
        lazy[cur] = 0;
    }

    void update(int cur, int l, int r, int ql, int qr, int val) {
        pushdown(cur, l, r);
        if(r < ql || qr < l) return;
        if(ql <= l && r <= qr) {
            lazy[cur] = val;
            pushdown(cur, l, r);
            return;
        }

        int m = (l+r)/2;
        update(2*cur, l, m, ql, qr, val);
        update(2*cur+1, m+1, r, ql, qr, val);
        pushup(cur);
    }

    ll query(int cur, int l, int r, int ql, int qr) {
        pushdown(cur, l, r);
        if(r < ql || qr < l) return 0;
        if(ql <= l && r <= qr) {
            return seg[cur];
        }

        int m = (l+r)/2;
        return query(2*cur, l, m, ql, qr) + query(2*cur+1, m+1, r, ql, qr);
    }
} seg1;

struct Segtree2 {
    ll seg[4*MAXN];
    ll lazy[4*MAXN];

    void pushup(int cur) {
        seg[cur] = seg[2*cur] + seg[2*cur+1];
    }

    void pushdown(int cur, int l, int r){
        if(lazy[cur] == 0) return;

        seg[cur] = seg[cur] + lazy[cur] * (r*(r+1) - (l-1)*(l)) / 2;
        if(l != r){
            lazy[2*cur] = lazy[2*cur] + lazy[cur];
            lazy[2*cur+1] = lazy[2*cur+1] + lazy[cur];
        }
        lazy[cur] = 0;
    }

    void update(int cur, int l, int r, int ql, int qr, int val) {
        pushdown(cur, l, r);
        if(r < ql || qr < l) return;
        if(ql <= l && r <= qr) {
            lazy[cur] = val;
            pushdown(cur, l, r);
            return;
        }

        int m = (l+r)/2;
        update(2*cur, l, m, ql, qr, val);
        update(2*cur+1, m+1, r, ql, qr, val);
        pushup(cur);
    }

    ll query(int cur, int l, int r, int ql, int qr) {
        pushdown(cur, l, r);
        if(r < ql || qr < l) return 0;
        if(ql <= l && r <= qr) {
            return seg[cur];
        }

        int m = (l+r)/2;
        return query(2*cur, l, m, ql, qr) + query(2*cur+1, m+1, r, ql, qr);
    }
} seg2;

void sol() {
    cin >> n >> q;

    int l, r;
    for(int i = 1; i <= q; i++) {
        cin >> qType;
        if(qType == 1) {
            cin >> l >> r >> x;

            seg1.update(1, 1, n, l, r, -x * (l-1));
            seg2.update(1, 1, n, l, r, x);
        }
        else {
            cin >> l >> r;
            cout << seg1.query(1, 1, n, l, r) + seg2.query(1, 1, n, l, r) << "\n";
        }
    }
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    sol();

    return 0;
}