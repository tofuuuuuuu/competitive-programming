#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 1000005;
ll seg[4*MAXN];
ll lazy[4*MAXN];

void pushup(int cur) {
    seg[cur] = (seg[2*cur+1] + seg[2*cur+2]);
}

void pushdown(int cur, int l, int r){
    lazy[cur] %= 2;
    if(lazy[cur] == 0) return;

    seg[cur] = (r - l + 1) - seg[cur];
    if(l != r){
        lazy[2*cur+1] = (lazy[2*cur+1] + 1) % 2;
        lazy[2*cur+2] = (lazy[2*cur+2] + 1) % 2;
    }
    lazy[cur] = 0;
}

void construct(int cur, int l, int r) {
    if(l == r) {
        seg[cur] = 1;
        return;
    }

    int m = (l+r)/2;
    construct(cur*2 + 1, l, m);
    construct(cur*2 + 2, m+1, r);
    pushup(cur);
} 

void update(int cur, int l, int r, int ql, int qr) {
    pushdown(cur, l, r);
    if(r < ql || qr < l) return;
    if(ql <= l && r <= qr) {
        seg[cur] = (r - l + 1) - seg[cur];
        if(l != r){
            lazy[2*cur+1] = (lazy[2*cur+1] + 1) % 2;
            lazy[2*cur+2] = (lazy[2*cur+2] + 1) % 2;
        }
        return;
    }

    int m = (l+r)/2;
    update(2*cur + 1, l, m, ql, qr);
    update(2*cur + 2, m+1, r, ql, qr);
    pushup(cur);
}

ll query(int cur, int l, int r, int ql, int qr) {
    pushdown(cur, l, r);
    if(r < ql || qr < l) return 0;
    if(ql <= l && r <= qr) {
        return seg[cur];
    }

    int m = (l+r)/2;
    return (query(2*cur+1, l, m, ql, qr) + query(2*cur+2, m+1, r, ql, qr));
}

int bs(int n, int lim) {
    int l = 1, r = n, ans = -1;
    while(l <= r) {
        int m = (l+r)/2;
        int res = query(1, 1, n, 1, m);

        if(res == lim) {
            ans = m;
            r = m-1;
        }
        else if(res > lim) {
            r = m-1;
        }
        else {
            l = m+1;
        }
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, lim;
    cin >> n >> m >> lim;
    construct(1, 1, n);

    for(int i = 1; i <= m; i++) {
        int l, r; cin >> l >> r;
        update(1, 1, n, l, r);
        
        if(query(1, 1, n, 1, n) < lim) cout << "AC?" << "\n";
        else {
            cout << bs(n, lim) << "\n";
        }
    }

    return 0;
}