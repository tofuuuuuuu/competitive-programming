#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int BFN = 1000000000;
const int SFN = -1000000000;
const int MAXN = 2000005;
const ll MOD = 1000000007;
int a[MAXN];
pii seg[4*MAXN];
pii lazy[4*MAXN];
//{decr, incr}

pii decr(pii p, int c) {
    pii ret = p;
    if(c >= p.first) {
        
    }
    else if(c <= p.second) {
        ret.first = c; ret.second = c;
    }
    else {
        ret.first = c;
    }
    return ret;
}

pii incr(pii p, int c) {
    pii ret = p;
    if(c >= p.first) {
        ret.first = c; ret.second = c;
    }
    else if(c <= p.second) {
        
    }
    else {
        ret.second = c;
    }
    return ret;
}

void pushdown(int cur, int l, int r){
    seg[cur] = decr(seg[cur], lazy[cur].first);
    seg[cur] = incr(seg[cur], lazy[cur].second);

    if(l != r){
        lazy[2*cur] = decr(lazy[2*cur], lazy[cur].first);
        lazy[2*cur] = incr(lazy[2*cur], lazy[cur].second);
        lazy[2*cur+1] = decr(lazy[2*cur+1], lazy[cur].first);
        lazy[2*cur+1] = incr(lazy[2*cur+1], lazy[cur].second);
    }
    lazy[cur].first = BFN; lazy[cur].second = SFN;
}

void update(int cur, int l, int r, int ql, int qr, pii p) {
    pushdown(cur, l, r);
    if(r < ql || qr < l) return;
    if(ql <= l && r <= qr) {
        seg[cur] = decr(seg[cur], p.first);
        seg[cur] = incr(seg[cur], p.second);

        if(l != r){
            lazy[2*cur] = decr(lazy[2*cur], p.first);
            lazy[2*cur] = incr(lazy[2*cur], p.second);
            lazy[2*cur+1] = decr(lazy[2*cur+1], p.first);
            lazy[2*cur+1] = incr(lazy[2*cur+1], p.second);
        }
        return;
    }

    int m = (l+r)/2;
    update(2*cur, l, m, ql, qr, p);
    update(2*cur + 1, m+1, r, ql, qr, p);
}

ll query(int cur, int l, int r, int idx) {
    pushdown(cur, l, r);
    if(l == r) {
        return seg[cur].first;
    }

    int m = (l+r)/2;
    if(idx <= m) {
        return query(2*cur, l, m, idx);
    }
    else {
        return query(2*cur+1, m+1, r, idx);
    }
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]) {
    for(int i = 0; i < 4*MAXN; i++) {
        lazy[i].first = BFN; lazy[i].second = SFN; 
        seg[i].first = 0; seg[i].second = 0;
    }

    pii p;
    for(int i = 0; i < k; i++) {
        p.first = height[i]; p.second = height[i];
        if(op[i] == 1) {
            p.first = BFN;
        }
        else {
            p.second = SFN;
        }

        update(1, 1, n, left[i]+1, right[i]+1, p);
    }

    for(int i = 0; i < n; i++) {
        finalHeight[i] = query(1, 1, n, i+1);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    return 0;
}