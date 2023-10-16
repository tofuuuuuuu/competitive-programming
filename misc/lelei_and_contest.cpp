#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 200005;
ll MOD;
ll a[MAXN];
ll seg[4*MAXN+6];
ll lazy[4*MAXN+6];

void pushup(int cur) {
    seg[cur] = (seg[2*cur+1] + seg[2*cur+2]) % MOD;
}

void pushdown(int cur, int l, int r){
    if(lazy[cur] == 0) return;

    seg[cur] = (seg[cur] + ((r-l+1)%MOD * lazy[cur])) % MOD;
    if(l != r){
        lazy[2*cur+1] = (lazy[2*cur+1] + lazy[cur]) % MOD;
        lazy[2*cur+2] = (lazy[2*cur+2] + lazy[cur]) % MOD;
    }
    lazy[cur] = 0;
}

void construct(int cur, int l, int r) {
    if(l == r) {
        seg[cur] = a[l];
        return;
    }

    int m = (l+r)/2;
    construct(cur*2 + 1, l, m);
    construct(cur*2 + 2, m+1, r);
    pushup(cur);
} 

void update(int cur, int l, int r, int ql, int qr, int val) {
    pushdown(cur, l, r);
    if(r < ql || qr < l) return;
    if(ql <= l && r <= qr) {
        seg[cur] = (seg[cur] + ((r-l+1)%MOD * val)) % MOD;
        if(l != r){
            lazy[2*cur+1] = (lazy[2*cur+1] + val) % MOD;
            lazy[2*cur+2] = (lazy[2*cur+2] + val) % MOD;
        }
        return;
    }

    int m = (l+r)/2;
    update(2*cur + 1, l, m, ql, qr, val);
    update(2*cur + 2, m+1, r, ql, qr, val);
    pushup(cur);
}

ll query(int cur, int l, int r, int ql, int qr) {
    pushdown(cur, l, r);
    if(r < ql || qr < l) return 0;
    if(ql <= l && r <= qr) {
        return seg[cur];
    }

    int m = (l+r)/2;
    return (query(2*cur + 1, l, m, ql, qr) + query(2*cur + 2, m+1, r, ql, qr)) % MOD;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> MOD >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= MOD;
    }
    construct(1, 1, MAXN);

    for(int i = 1; i <= q; i++) {
        int type; cin >> type;
        if(type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            x %= MOD;
            update(1, 1, MAXN, l, r, x);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, MAXN, l ,r) % MOD << "\n";
        }
    }

    return 0;
}