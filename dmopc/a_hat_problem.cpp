#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

const int MAXN = 1000005;
const ll BFN = (ll)1e17;
//const int BFN = (int)1e9;
int n, q, k;
ll v[MAXN];
ll w[MAXN];
ll psa[MAXN];
ll dp[MAXN];

struct segtree{
    ll seg[4*MAXN];

    void pushup(int cur) {
        seg[cur] = min(seg[2*cur], seg[2*cur+1]);
    }

    void construct() {
        for(int i = 0; i < 4*MAXN; i++) {
            seg[i] = BFN;
        }
    } 

    void update(int cur, int l, int r, int idx, ll val) {
        if(l == r) {
            seg[cur] = min(seg[cur], val);
            return;
        }
        
        int m = (l+r)/2;
        if(idx <= m) update(2*cur, l, m, idx, val);
        else update(2*cur+1, m+1, r, idx, val);
        pushup(cur);
    }

    ll query(int cur, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) return seg[cur];
        if(r < ql || qr < l) return BFN;
        int m = (l+r)/2;
        return min(query(2*cur, l, m, ql, qr), query(2*cur+1, m+1, r, ql, qr));
    }
};

segtree sex1, sex2;

void sol() {
    sex1.construct();
    sex2.construct();

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }

    for(int i = 2; i <= n; i++) {
        psa[i] = psa[i-1] + abs(v[i] - w[i-1]);
    }

    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        dp[i] = min(dp[i-1] + abs(v[i] - w[i]), 
                    min(sex1.query(1, 1, MAXN-1, w[i], MAXN-1) + psa[i] - w[i], 
                        sex2.query(1, 1, MAXN-1, 1, w[i]-1) + psa[i] + w[i]));
        sex1.update(1, 1, MAXN-1, v[i], ( dp[i-1] - psa[i] + v[i] ));
        sex2.update(1, 1, MAXN-1, v[i], ( dp[i-1] - psa[i] - v[i] ));
    }

    cout << dp[n] << "\n";
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}