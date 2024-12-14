#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pii pair<int, int>
#define pll pair<ll ,ll>

// #define scanu(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
// char _;

const int MAXN = 400005;
const ll MOD = 1000000007;
//const ll BFN = (ll)1e17;
const int BFN = (int)2e9;
ll n, m, q, a, b, v, w, l, r;
ll dp[MAXN];
vector<pair<ll, pll>> ranges;
vector<ll> mp;
unordered_set<ll> s;

struct Segtree{
    ll seg[4*MAXN];

    void init() {
        for(int i = 0; i < 4*MAXN; i++) seg[i] = 0;
    }

    void pushup(int cur) {
        seg[cur] = max(seg[2*cur], seg[2*cur+1]);
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
} st;

ll cmpr(ll x) {
    ll lt = 0, rt = mp.size()-1, mt;
    while(lt <= rt) {
        mt = (lt+rt)/2;
        if(mp[mt] == x) return mt+1;
        else if(mp[mt] > x) rt = mt-1;
        else lt = mt+1;
    }
    return -1;
}

void sol() {
    cin >> n;
    st.init();
    for(int i = 1; i <= n; i++) {
        cin >> l >> r >> v;
        r = l + r;
        ranges.push_back({r, {l, v}});

        if(s.find(l) == s.end()) {
            mp.push_back(l);
            s.insert(l);
        }
        if(s.find(r) == s.end()) {
            mp.push_back(r);
            s.insert(r);
        }
    }
    sort(ranges.begin(), ranges.end());
    sort(mp.begin(), mp.end());

    for(int i = 0; i < n; i++) {
        pair<ll, pll> cur = ranges[i];
        r = cmpr(cur.first), l = cmpr(cur.second.first), v = cur.second.second; 
        dp[r] = max(dp[r], st.query(1, 1, MAXN-1, 1, l) + v);
        st.update(1, 1, MAXN-1, r, dp[r]);
    }

    ll ans = dp[0];
    for(int i = 1; i < MAXN; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}