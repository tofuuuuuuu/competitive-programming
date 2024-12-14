#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 100005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, q, x, y, qType;

int lftMax[4*MAXN];
int rhtMax[4*MAXN];
int arrMaxLft[4*MAXN];
int arrMaxRht[4*MAXN];
int lazy[4*MAXN];

void pushup(int cur, int lft, int rht) {
    int m = (lft+rht)/2;

    lftMax[cur] = lftMax[2*cur]; 
    if(lftMax[2*cur] == m && lftMax[2*cur+1] != 0) lftMax[cur] = lftMax[2*cur+1];

    rhtMax[cur] = rhtMax[2*cur+1];
    if(rhtMax[2*cur+1] == m+1 && rhtMax[2*cur] != 0) rhtMax[cur] = rhtMax[2*cur];

    int lft1 = arrMaxLft[2*cur], rht1 = arrMaxRht[2*cur], len1 = rht1 - lft1 + 1;
    int lft2 = rhtMax[2*cur], rht2 = lftMax[2*cur+1], len2 = rht2 - lft2 + 1;
    int lft3 = arrMaxLft[2*cur+1], rht3 = arrMaxRht[2*cur+1], len3 = rht3 - lft3 + 1;

    int l = 0, r = 0, len = 0;
    if(lft1 != 0 && rht1 != 0) {
        l = lft1; r = rht1; len = len1;
    }
    if(lft2 != 0 && rht2 != 0 && len2 > len) {
        l = lft2; r = rht2; len = len2;
    }
    if(lft3 != 0 && rht3 != 0 && len3 > len) {
        l = lft3; r = rht3; len = len3;
    }
    arrMaxLft[cur] = l; arrMaxRht[cur] = r;
}

void pushdown(int cur, int l, int r){
    if(lazy[cur] == -1) return;

    if(lazy[cur] == 0) {
        lftMax[cur] = rhtMax[cur] = arrMaxLft[cur] = arrMaxRht[cur] = 0;
    }
    else if(lazy[cur] == 1) {
        lftMax[cur] = r; rhtMax[cur] = l; arrMaxLft[cur] = l; arrMaxRht[cur] = r;
    }
    
    if(l != r){
        lazy[2*cur] = lazy[cur];
        lazy[2*cur+1] = lazy[cur];
    }
    lazy[cur] = -1;
}

void init(int cur, int l, int r) {
    if(l == r) {
        lazy[cur] = -1; lftMax[cur] = rhtMax[cur] = arrMaxLft[cur] = arrMaxRht[cur] = 0;
        return;
    }

    int m = (l+r)/2;
    init(cur*2, l, m);
    init(cur*2+1, m+1, r);
    pushup(cur, l, r);
} 

void update(int cur, int l, int r, int ql, int qr, int val) {
    pushdown(cur, l, r);
    if(r < ql || qr < l) return;
    if(ql <= l && r <= qr) {
        lazy[cur] = val;
        pushdown(cur, l, r);
        return;
    }

    int m = (l+r)/2;
    update(2*cur, l, m, ql, qr, val);
    update(2*cur+1, m+1, r, ql, qr, val);
    pushup(cur, l, r);
}

pii query() {
    return {arrMaxLft[1], arrMaxRht[1]};
}

void sol() {
    cin >> n >> q;
    init(1, 1, n);

    for(int i = 1; i <= q; i++) {
        cin >> qType;
        if(qType == 0) {
            cin >> x >> y;
            update(1, 1, n, x, y, 0);
            
            pii a = query();
            if(a.first == 0) cout << "0\n";
            else cout << a.second - a.first + 1<< "\n";
        }
        else if(qType == 1) {
            cin >> x >> y;
            update(1, 1, n, x, y, 1);

            pii a = query();
            if(a.first == 0) cout << "0\n";
            else cout << a.second - a.first + 1<< "\n";
        }
        else {
            pii a = query();
            x = a.first; y = a.second;
            update(1, 1, n, x, y, 0);
        }
    }
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    sol();

    return 0;
}