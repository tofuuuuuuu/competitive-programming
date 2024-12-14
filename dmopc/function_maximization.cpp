#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

using u64 = uint64_t;
using u128 = __uint128_t;

u64 quickPow(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = quickPow(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n) { 
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

const int bitSz = 5005;
const int MAXN = 100005;
ll a[MAXN];
ll k;
bitset<bitSz> seg[4*MAXN];
ll lazy[4*MAXN];
bool isPrime[5005];

void pushup(int cur) {
    seg[cur] = (seg[2*cur+1] | seg[2*cur+2]);
}

void pushdown(int cur, int l, int r){
    if(lazy[cur] == 0) return;

    if(lazy[cur] > 0) seg[cur] = (seg[cur] << lazy[cur]);
    else seg[cur] = (seg[cur] >> (-lazy[cur]));

    if(l != r){
        lazy[2*cur+1] = (lazy[2*cur+1] + lazy[cur]);
        lazy[2*cur+2] = (lazy[2*cur+2] + lazy[cur]);
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

void update(int cur, int l, int r, int ql, int qr, int val) {
    pushdown(cur, l, r);
    if(r < ql || qr < l) return;
    if(ql <= l && r <= qr) {
        if(val > 0) seg[cur] = (seg[cur] << val);
        else seg[cur] = (seg[cur] >> (-val));

        if(l != r){
            lazy[2*cur+1] = (lazy[2*cur+1] + val);
            lazy[2*cur+2] = (lazy[2*cur+2] + val);
        }
        return;
    }

    int m = (l+r)/2;
    update(2*cur + 1, l, m, ql, qr, val);
    update(2*cur + 2, m+1, r, ql, qr, val);
    pushup(cur);
}

bitset<bitSz> query(int cur, int l, int r, int ql, int qr) {
    pushdown(cur, l, r);
    if(r < ql || qr < l) return 0;
    if(ql <= l && r <= qr) {
        return seg[cur];
    }

    int m = (l+r)/2;
    return (query(2*cur+1, l, m, ql, qr) | query(2*cur+2, m+1, r, ql, qr));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q >> k;
    for(int i = 1; i <= n; i++) {
        ll ai; cin >> ai; ai -= k; a[i] = ai;
    }
    construct(1, 1, n);
    for(int i = 0; i <= 5001; i++) {
        isPrime[i] = MillerRabin(k + i);
    }

    for(int i = 1; i <= q; i++) {
        int t, ql, qr; cin >> t >> ql >> qr;
        if(t == 1) {
            ll ans = -1;
            bitset<bitSz> qSet = query(1, 1, n, ql, qr);
            for(int bt = 5001; bt >= 0; bt--) {
                if(qSet.test(bt) && isPrime[bt]) {
                    ans = bt + k;
                    break;
                } 
            }

            cout << ans << "\n";
        }
        else {
            int val; cin >> val;
            update(1, 1, n, ql, qr, val);
        }
    }
    return 0;
}