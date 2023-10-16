#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 250005;
int a[MAXN];
int seg[4*MAXN][10];
int lazy[4*MAXN];

void pushup(int cur) {
    for(int i = 0; i <= 9; i++) {
        seg[cur][i] = (seg[2*cur+1][i] + seg[2*cur+2][i]);
    }
}

void rotate(int cur) {
    ll temp = seg[cur][9];
    for(int i = 9; i > 0; i--) {
        seg[cur][i] = seg[cur][i-1];
    }
    seg[cur][0] = temp;
}

void pushdown(int cur, int l, int r){
    lazy[cur] %= 10;
    if(lazy[cur] == 0) return;

    for(int i = 1; i <= lazy[cur]; i++) {
        rotate(cur);
    }
    if(l != r){
        lazy[2*cur+1] = (lazy[2*cur+1] + lazy[cur]) % 10;
        lazy[2*cur+2] = (lazy[2*cur+2] + lazy[cur]) % 10;
    }
    lazy[cur] = 0;
}

void construct(int cur, int l, int r) {
    if(l == r) {
        seg[cur][a[l]] = 1;
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
        rotate(cur);
        if(l != r){
            lazy[2*cur+1] = (lazy[2*cur+1] + 1) % 10;
            lazy[2*cur+2] = (lazy[2*cur+2] + 1) % 10;
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
        ll sum = 0;
        for(int i = 0; i <= 9; i++) {
            sum += i*seg[cur][i];
        }
        return sum;
    }

    int m = (l+r)/2;
    return (query(2*cur+1, l, m, ql, qr) + query(2*cur+2, m+1, r, ql, qr));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    string s; cin >> s;
    for(int i = 1; i <= n; i++) {
        a[i] = s[i-1] - '0';
    }
    construct(1, 1, n);

    for(int i = 1; i <= m; i++) {
        int ql, qr; cin >> ql >> qr;
        cout << query(1, 1, n, ql, qr) << "\n";
        update(1, 1, n, ql, qr);
    }
    return 0;
}