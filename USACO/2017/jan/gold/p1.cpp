#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
const ll BFN = (int)2e9;
int a[MAXN];
int n, q, k;
vector<pii> v;
int ans[MAXN];

struct segtree{
    int a[MAXN];
    int seg[4*MAXN];

    void pushup(int cur) {
        seg[cur] = (seg[2*cur] + seg[2*cur+1]);
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

    int query(int cur, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) return seg[cur];
        if(r < ql || qr < l) return 0;
        int m = (l+r)/2;
        return (query(2*cur, l, m, ql, qr) + query(2*cur+1, m+1, r, ql, qr));
    }
};

int main(){
    freopen("bphoto.in", "r", stdin);
	freopen("bphoto.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    segtree s;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> k;
        v.push_back({k, i});
    }
    sort(v.begin(), v.end(), greater<pii>());
    
    int tot = 0;
    for(pii p : v) {
        int a1 = s.query(1, 1, n, p.second, n); int a2 = s.query(1, 1, n, 1, p.second);
        if(a2 > a1) swap(a1, a2);
        if(a1 > 2*a2) tot++;

        s.update(1, 1, n, p.second, 1);
    }

    cout << tot << "\n";

    return 0;
}