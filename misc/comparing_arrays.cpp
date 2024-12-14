#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

const int MAXN = 500005;
ll a[MAXN];
ll segHash1[4*MAXN];
ll segHash2[4*MAXN];
const ll base1 = 137;
const ll base2 = 131; 
const ll mod1 = 1000000007;
const ll mod2 = 1000000009;

ll quickPow(ll b, ll p, ll mod) {
    ll ans = 1;
    ll cur = b;
    while(p) {
        if(p & 1) {
            ans *= cur;
            ans %= mod;
        }  
        p >>= 1;
        cur *= cur;
        cur %= mod;
    }
    return ans;
}

void pushup(int cur, int len) {
    segHash1[cur] = (segHash1[2*cur+1] + (segHash1[2*cur+2] * quickPow(base1, len, mod1)) % mod1) % mod1;
    segHash2[cur] = (segHash2[2*cur+1] + (segHash2[2*cur+2] * quickPow(base2, len, mod2)) % mod2) % mod2;
    if(segHash1[cur] < 0) segHash1[cur] += mod1;
    if(segHash2[cur] < 0) segHash2[cur] += mod2;
}

void construct(int cur, int l, int r) {
    if(l == r) {
        segHash1[cur] = a[l];
        segHash2[cur] = a[l];
        return;
    }

    int m = (l+r)/2;
    construct(cur*2 + 1, l, m);
    construct(cur*2 + 2, m+1, r);
    pushup(cur, m - l + 1);
} 

void update(int cur, int l, int r, int idx, int val) {
    if(l == r) {
        segHash1[cur] = val;
        segHash2[cur] = val;
        return;
    }
    
    int m = (l+r)/2;
    if(idx <= m) update(2*cur+1, l, m, idx, val);
    else update(2*cur+2, m+1, r, idx, val);
    pushup(cur, m - l + 1);
}

pll query(int cur, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        ll ret1 = (segHash1[cur] * quickPow(base1, l - ql, mod1)) % mod1;
        ll ret2 = (segHash2[cur] * quickPow(base2, l - ql, mod2)) % mod2;
        if(ret1 < 0) ret1 += mod1;
        if(ret2 < 0) ret2 += mod2;

        pll ret; ret.first = ret1; ret.second = ret2;
        return ret;
    }
    if(r < ql || qr < l) return {0, 0};

    int m = (l+r)/2;

    pll ret;
    pll q1 = query(2*cur+1, l, m, ql, qr); pll q2 = query(2*cur+2, m+1, r, ql, qr);

    ret.first = (q1.first + q2.first) % mod1;
    ret.second = (q1.second + q2.second) % mod2;
    if(ret.first < 0) ret.first += mod1;
    if(ret.second < 0) ret.second += mod2;
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q, idx, val, ql1, qr1, ql2, qr2; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    construct(1, 1, n);

    for(int i = 1; i <= q; i++) {
        int qType; cin >> qType;
        if(qType == 1) {
            cin >> ql1 >> qr1 >> ql2 >> qr2; 

            pll q1 = query(1, 1, n, ql1, qr1); pll q2 = query(1, 1, n, ql2, qr2);
            if(q1.first == q2.first && q1.second == q2.second) cout << "1\n";
            else cout << "0\n";
        }
        else {
            cin >> idx >> val;
            update(1, 1, n, idx, val);
        }
    }
    return 0;
}