#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 200005;
//const ll BFN = (ll)1e17;
const ll MOD = 1000000007;
const int BFN = (int)1e9;
int n, q, a, b;
char qType;

struct Segtree{
    int seg[4*MAXN];

    void pushup(int cur) {
        seg[cur] = min(seg[2*cur], seg[2*cur+1]);
    }

    void construct() {
        for(int i = 0; i < 4*MAXN; i++) {
            seg[i] = BFN;
        }
    } 

    void update(int cur, int l, int r, int idx, int val) {
        if(l == r) {
            seg[cur] = val;
            return;
        }
        
        int m = (l+r)/2;
        if(idx <= m) update(2*cur, l, m, idx, val);
        else update(2*cur+1, m+1, r, idx, val);
        pushup(cur);
    }

    int query(int cur, int l, int r, int ql, int mx) {
        if(l == r) {
            if(seg[cur] <= mx) return l;
            return BFN;
        }

        int m = (l+r)/2;
        if(m < ql) {
            return query(2*cur+1, m+1, r, ql, mx);
        }

        int res = BFN;
        if(seg[2*cur] <= mx) {
            res = query(2*cur, l, m, ql, mx);
        }
        if(res == BFN) {
            return query(2*cur+1, m+1, r, ql, mx);
        }
        return res;
    }
};

void sol() {
    Segtree sex; sex.construct();

    cin >> n >> q;
    for(int i = 1; i <= q; i++) {
        cin >> qType >> a >> b;
        if(qType == 'M') {
            sex.update(1, 1, n, b, a);
        }
        else {
            int res = sex.query(1, 1, n, b, a);
            if(res == BFN) cout << "-1\n";
            else cout << res << "\n";
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