#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
const ll BFN = (int)2e9;
int a[MAXN];
int n, q, k;
vector<int> ans;

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

    ll query(int cur, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) return seg[cur];
        if(r < ql || qr < l) return 0;
        int m = (l+r)/2;
        return (query(2*cur, l, m, ql, qr) + query(2*cur+1, m+1, r, ql, qr));
    }
};

int main(){
    freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    segtree s;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int cnt1 = 1;
    s.update(1, 1, n, a[n], 1);
    for(int i = n-1; i >= 1; i--) {
        if(a[i] < a[i+1]) {
            s.update(1, 1, n, a[i], 1);
            cnt1++;
        }
        else {
            break;
        }
    }

    int cnt = cnt1;
    for(int i = 1; i <= n - cnt1; i++) {
        ans.push_back(s.query(1, 1, n, 1, a[i]) + n - cnt - 1);
        s.update(1, 1, n, a[i], 1);
        cnt++;
    }

    cout << ans.size() << "\n";
    if(ans.size() > 0) cout << ans[0];
    for(int i = 1; i < ans.size(); i++) {
        cout << " " << ans[i];
    }
    cout << "\n";

    return 0;
}