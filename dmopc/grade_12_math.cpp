#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 500005;
int a[MAXN];

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};

gp_hash_table<int, int, chash> seg[4*MAXN];

void pushup(int cur, int oldV, int newV) {
    seg[cur][oldV]--; 
    if(seg[cur][oldV] == 0) seg[cur].erase(oldV);
    seg[cur][newV]++;
}

void construct(int cur, int l, int r) {
    if(l == r) {
        seg[cur][0] = 1;
        return;
    }

    int m = (l+r)/2;
    construct(cur*2 + 1, l, m);
    construct(cur*2 + 2, m+1, r);
    seg[cur][0] = seg[cur*2 + 1][0] + seg[cur*2 + 2][0];
} 

void update(int cur, int l, int r, int idx, int val) {
    if(l == r) {
        seg[cur].erase(a[idx]);
        seg[cur][a[idx] + val] = 1;
        return;
    }
    
    int m = (l+r)/2;
    if(idx <= m) update(2*cur+1, l, m, idx, val);
    else update(2*cur+2, m+1, r, idx, val);
    pushup(cur, a[idx], a[idx] + val);
}

int query(int cur, int l, int r, int ql, int qr, int qc) {
    if(ql <= l && r <= qr) {
        if(seg[cur].find(qc) == seg[cur].end()) return 0;
        return seg[cur][qc];
    }
    if(r < ql || qr < l) return 0;

    int m = (l+r)/2;
    return query(2*cur+1, l, m, ql, qr, qc) + query(2*cur+2, m+1, r, ql, qr, qc);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    construct(1, 1, n);

    for(int i = 1; i <= q; i++) {
        int t; cin >> t;
        if(t == 1) {
            int x; cin >> x;
            update(1, 1, n, x, 1);
            a[x]++;
        }
        else if(t == 2) {
            int x; cin >> x;
            update(1, 1, n, x, -1);
            a[x]--;
        }
        else {
            int ql, qr, qc; cin >> ql >> qr >> qc;
            cout << query(1, 1, n, ql, qr, qc) << "\n";
        }
    }
    return 0;
}