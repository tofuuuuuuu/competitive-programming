#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 1000005;
const ll BFN = (ll)1e11;
const ll MOD = 1000000007;
int n, q, t, l, r, k;

struct Segtree {
    ll a[MAXN];
    ll b[MAXN];
    ll segA[4*MAXN];
    ll segB[4*MAXN];
    ll segMax[4*MAXN];
    ll lazyA[4*MAXN];
    ll lazyB[4*MAXN];

    void pushup(int cur) {
        segA[cur] = max(segA[2*cur], segA[2*cur+1]);
        segB[cur] = max(segB[2*cur], segB[2*cur+1]);
        segMax[cur] = max(segMax[2*cur], segMax[2*cur+1]);
    }

    void pushdownA(int cur, int l, int r){
        if(lazyA[cur] == -BFN) return;

        segA[cur] = lazyA[cur];
        segMax[cur] = lazyA[cur] + segB[cur];
        if(l != r){
            lazyA[2*cur] = lazyA[cur];
            lazyA[2*cur+1] = lazyA[cur];
        }
        lazyA[cur] = -BFN;
    }

    void pushdownB(int cur, int l, int r) {
        if(lazyB[cur] == -BFN) return;
    
        segB[cur] = max(segB[cur], lazyB[cur]);
        segMax[cur] = max(segMax[cur], segA[cur] + lazyB[cur]);
        if(l != r) {
            lazyB[2*cur] = max(lazyB[2*cur], lazyB[cur]);
            lazyB[2*cur+1] = max(lazyB[2*cur+1], lazyB[cur]);
        }
        lazyB[cur] = -BFN;
    }

    void construct(int cur, int l, int r) {
        lazyA[cur] = -BFN; lazyB[cur] = -BFN;
        if(l == r) {
            segA[cur] = a[l];
            segB[cur] = b[l];
            segMax[cur] = a[l] + b[l];
            return;
        }

        int m = (l+r)/2;
        construct(cur*2, l, m);
        construct(cur*2+1, m+1, r);
        pushup(cur);
    } 

    void updateA(int cur, int l, int r, int ql, int qr, int val) {
        pushdownA(cur, l, r);
        pushdownB(cur, l, r);

        if(r < ql || qr < l) return;
        if(ql <= l && r <= qr) {
            lazyA[cur] = val;
            pushdownA(cur, l, r);
            return;
        }

        int m = (l+r)/2;
        updateA(2*cur, l, m, ql, qr, val);
        updateA(2*cur+1, m+1, r, ql, qr, val);
        pushup(cur);
    }

    void updateB(int cur, int l, int r, int ql, int qr, ll val) {
        pushdownA(cur, l, r);
        pushdownB(cur, l, r);

        if(r < ql || qr < l) return;
        if(ql <= l && r <= qr) {
            lazyB[cur] = val;
            pushdownB(cur, l, r);
            return;
        }

        int m = (l+r)/2;
        updateB(2*cur, l, m, ql, qr, val);
        updateB(2*cur+1, m+1, r, ql, qr, val);
        pushup(cur);
    }

    ll query(int cur, int l, int r, int ql, int qr) {
        pushdownA(cur, l, r);
        pushdownB(cur, l, r);
        if(r < ql || qr < l) return -BFN;
        if(ql <= l && r <= qr) {
            return segMax[cur];
        }

        int m = (l+r)/2;
        return max(query(2*cur, l, m, ql, qr), query(2*cur+1, m+1, r, ql, qr));
    }
};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    Segtree sex; 
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> sex.a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> sex.b[i];
    }
    sex.construct(1, 1, n);

    for(int i = 1; i <= q; i++) {
        cin >> t >> l >> r;
        if(t == 1) {
            cin >> k;
            sex.updateA(1, 1, n, l, r, k);
        }
        else if(t == 2) {
            cin >> k;
            sex.updateB(1, 1, n, l, r, k);
        }
        else {
            cout << sex.query(1, 1, n, l, r) << "\n";
        }
    }

    return 0;
}