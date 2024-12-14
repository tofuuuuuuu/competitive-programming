#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll ,ll>

const int MAXN = 200005;
const ll MOD = 1000000007;
const ll BFN = (ll)1e17;
//const int BFN = (int)1e9;
int n, q, l, r; ll v;

struct Segtree{
    ll a[MAXN];
    ll seg[4*MAXN];

    void pushup(int cur) {
        seg[cur] = min(seg[2*cur], seg[2*cur+1]);
    }

    void construct(int cur, int l, int r) {
        if(l == r) {
            seg[cur] = a[l];
            return;
        }

        int m = (l+r)/2;
        construct(cur*2, l, m);
        construct(cur*2 + 1, m+1, r);
        pushup(cur);
    } 

    pll query(int cur, int l, int r, int ql, int qr, ll v) {
        if(r < ql || qr < l) return {BFN, -1};
        if(l == r) return {seg[cur], l};

        int m = (l+r)/2;
        if(seg[2*cur] > v) return query(2*cur+1, m+1, r, ql, qr, v);
        pll r1 = query(2*cur, l, m, ql, qr, v);
        if(r1.first == BFN) return query(2*cur+1, m+1, r, ql, qr, v);
        return r1;
    }
};

void sol() {
    Segtree sex;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> sex.a[i];
    }
    sex.construct(1, 1, n);

    pll curMod = {0, 0};
    int curL = 0;
    for(int i = 1; i <= q; i++) {
        cin >> v >> l >> r;
        curL = l;
        while(v != 0) {
            if(curL > r) break;
            curMod = sex.query(1, 1, n, curL, r, v);
            if(curMod.first == BFN) break;

            v = v % curMod.first;
            curL = curMod.second + 1;
        }

        cout << v << "\n";
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