#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
const ll BFN = (ll)1e20;
int a[MAXN];
int n, q, k;
ll x, y;
char t;

struct Node{
    ll opt = 0;
    ll lSum = 0;
    ll rSum = 0;
    ll totSum = 0;
};

struct segtree{
    ll a[MAXN];
    Node seg[4*MAXN];

    void pushup(int cur) {
        seg[cur].opt = max(seg[2*cur].rSum + seg[2*cur+1].lSum, max(seg[2*cur].opt, seg[2*cur+1].opt));
        seg[cur].lSum = max(seg[2*cur].lSum, seg[2*cur].totSum + seg[2*cur+1].lSum);
        seg[cur].rSum = max(seg[2*cur+1].rSum, seg[2*cur+1].totSum + seg[2*cur].rSum);
        seg[cur].totSum = seg[2*cur].totSum + seg[2*cur+1].totSum;
    }

    void construct(int cur, int l, int r) {
        if(l == r) {
            seg[cur].opt = a[l];
            seg[cur].lSum = a[l];
            seg[cur].rSum = a[l];
            seg[cur].totSum = a[l];
            return;
        }

        int m = (l+r)/2;
        construct(cur*2, l, m);
        construct(cur*2 + 1, m+1, r);
        pushup(cur);
    } 

    void update(int cur, int l, int r, int idx, ll val) {
        if(l == r) {
            seg[cur].opt = val;
            seg[cur].lSum = val;
            seg[cur].rSum = val;
            seg[cur].totSum = val;
            return;
        }
        
        int m = (l+r)/2;
        if(idx <= m) update(2*cur, l, m, idx, val);
        else update(2*cur+1, m+1, r, idx, val);
        pushup(cur);
    }

    Node query(int cur, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) return seg[cur];
        if(r < ql || qr < l) {
            Node ret;
            ret.opt = BFN;
            ret.lSum = BFN;
            ret.rSum = BFN;
            ret.totSum = BFN;
            return ret;
        }

        int m = (l+r)/2;
        Node ret;
        Node lNode = query(2*cur, l, m, ql, qr);
        Node rNode = query(2*cur+1, m+1, r, ql, qr);
        
        if(lNode.opt == BFN) return rNode;
        if(rNode.opt == BFN) return lNode;
        ret.opt = max(lNode.rSum + rNode.lSum, max(lNode.opt, rNode.opt));
        ret.lSum = max(lNode.lSum, lNode.totSum + rNode.lSum);
        ret.rSum = max(rNode.rSum, rNode.totSum + lNode.rSum);
        ret.totSum = rNode.totSum + lNode.totSum;
        return ret;
    }
};

segtree s;

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> s.a[i];
    }
    s.construct(1, 1, n);
    
    for(int i = 1; i <= q; i++) {
        cin >> t >> x >> y;
        if(t == 'S') {
            s.update(1, 1, n, x, y);
        }
        else {
            Node ret = s.query(1, 1, n, x, y);
            cout << ret.opt << "\n";
        }
    }

    return 0;
}