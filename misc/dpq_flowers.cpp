#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

const int MAXN = 200005;
const ll BFN = (ll)1e17;
//const int BFN = (int)1e9;
int n;
int h[MAXN];
ll a[MAXN];
ll dp[MAXN];

struct segtree{
    ll seg[4*MAXN];

    void pushup(int cur) {
        seg[cur] = max(seg[2*cur], seg[2*cur+1]);
    }

    void construct() {
        for(int i = 0; i < 4*MAXN; i++) {
            seg[i] = 0;
        }
    } 

    void update(int cur, int l, int r, int idx, ll val) {
        if(l == r) {
            seg[cur] = val;
            return;
        }
        
        int m = (l+r)/2;
        if(idx <= m) update(2*cur, l, m, idx, val);
        else update(2*cur+1, m+1, r, idx, val);
        pushup(cur);
    }

    ll query(int cur, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) return seg[cur];
        if(r < ql || qr < l) return 0;
        int m = (l+r)/2;
        return max(query(2*cur, l, m, ql, qr), query(2*cur+1, m+1, r, ql, qr));
    }
};

void sol() {
    segtree st; st.construct();

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = st.query(1, 1, n, 1, h[i]) + a[i];
        ans = max(ans, dp[i]);
        st.update(1, 1, n, h[i], dp[i]);
    }

    cout << ans << "\n";
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}