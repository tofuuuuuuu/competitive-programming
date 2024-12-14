#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 200005;
const ll BFN = (ll)1e17;
const ll MOD = 1000000007;
//const int BFN = (int)1e9;
int n, m;
pii dp[MAXN];
int x, y, indx;
pii res;

struct Range {
    int l, r;

    Range(int l, int r) {
        this->l = l;
        this->r = r;
    }
};

vector<Range> a;
vector<Range> orig;

struct Segtree{
    pii seg[4*MAXN];

    void pushup(int cur) {
        if(seg[2*cur].first < seg[2*cur+1].first) {
            seg[cur] = seg[2*cur+1];
        }
        else {
            seg[cur] = seg[2*cur];
        }
    }

    void construct() {
        for(int i = 0; i < 4*MAXN; i++) {
            seg[i] = {0, -1};
        }
    } 

    void update(int cur, int l, int r, int idx, pii val) {
        if(l == r) {
            seg[cur] = val;
            return;
        }
        
        int m = (l+r)/2;
        if(idx <= m) update(2*cur, l, m, idx, val);
        else update(2*cur+1, m+1, r, idx, val);
        pushup(cur);
    }

    pii query(int cur, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) return seg[cur];
        if(r < ql || qr < l) return {0, -1};
        int m = (l+r)/2;

        pii x = query(2*cur, l, m, ql, qr);
        pii y = query(2*cur+1, m+1, r, ql, qr);
        if(x.first > y.first) return x;
        else return y;
    }
};

bool cmp(Range &a, Range &b) {
    if(a.r == b.r) {
        return a.l > b.l;
    }
    return a.r < b.r;
}

vector<int> coord;

void sol() {
    Segtree sex; sex.construct();

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        coord.push_back(x); coord.push_back(y);
        orig.push_back(Range(x, y));
        a.push_back(Range(x, y));
    }    
    sort(a.begin(), a.end(), cmp);
    sort(coord.begin(), coord.end());

    for(int i = 0; i < n; i++) {
        indx = upper_bound(coord.begin(), coord.end(), a[i].l) - coord.begin();
        res = sex.query(1, 1, MAXN-1, indx, MAXN-1);
        dp[i] = {res.first + 1, res.second};
        sex.update(1, 1, MAXN-1, indx, {dp[i].first, i});
    }

    int ans = 0, st = 0;
    for(int i = 0; i < n; i++) {
        if(dp[i].first > ans) {
            ans = dp[i].first;
            st = i;
        }
    }

    cout << ans << "\n";
    while(st != -1) {
        cout << a[st].l << " " << a[st].r << "\n";
        st = dp[st].second;
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