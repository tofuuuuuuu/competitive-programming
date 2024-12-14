#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 200005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, m, x, y, z;

struct Segtree{
    ll seg[4*MAXN];

    void pushup(int cur) {
        seg[cur] = (seg[2*cur] + seg[2*cur+1]);
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

        int s1 = query(2*cur, l, m, ql, qr);
        int s2 = query(2*cur+1, m+1, r, ql, qr);

        return s1 + s2;
    }
};

struct Building {
    int h, c, idx;

    Building() {

    }

    Building(int h, int c, int idx) {
        this->h = h;
        this->c = c;
        this->idx = idx;
    }
};

struct Query {
    int idx, x, l, r;
    
    Query() {

    }

    Query(int idx, int x, int l, int r) {
        this->idx = idx;
        this->x = x;
        this->l = l;
        this->r = r;
    }
};

bool cmpB(Building &a, Building &b) {
    if(a.h == b.h) {
        return a.idx < b.idx; 
    }
    return a.h > b.h;
}

bool cmpQ(Query &a, Query &b) {
    if(a.x == b.x) {
        return a.idx < b.idx;
    }
    return a.x < b.x;
}

map<int, int> cnt; 
map<int, int > sm;
ld ans[MAXN];

int gr; 
Segtree ls; 
Segtree ch;

void sol() {
    Building a[MAXN];
    Query q[MAXN];

    cin >> n; 
    for(int i = 1; i <= n; i++) {
        cin >> x >> y;
        a[i] = Building(x, y, i);
        cnt[a[i].h]++;
        sm[a[i].h] += y;
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        q[i] = Query(i, x, y, z);
    }

    sort(a+1, a+n+1, cmpB);
    sort(q+1, q+m+1, cmpQ);

    for(int i = 1; i <= n; i++) {
        ls.update(1, 1, n, a[i].idx, a[i].c);
    }

    gr = 0;
    int curH = -1; int cntH = 0; int totH = 1; 
    int curX = 1; int curB = 1;
    vector<pii> inCh; 
    for(int i = 1; i <= m; i++) {
        while(curX <= q[i].x) {
            if(cntH == 0) {
                curH = a[curB].h;
                totH = cnt[curH];
                cntH = totH;
                for(auto p : inCh) {
                    ls.update(1, 1, n, p.first, 0);
                    ch.update(1, 1, n, p.first, 0);
                    gr += p.second; 
                }
                inCh.clear();

                while(curB <= n && a[curB].h == curH) {
                    ch.update(1, 1, n, a[curB].idx, a[curB].c);
                    inCh.push_back({a[curB].idx, a[curB].c});
                    curB++;
                }   
            }
            cntH--;
            curX++;
        }

        ld prob = (sm[curH] - ch.query(1, 1, n, q[i].l, q[i].r)) * ((ld)(totH - cntH) / totH);
        ans[q[i].idx] = gr + ls.query(1, 1, n, q[i].l, q[i].r) + prob;
    }

    for(int i = 1; i <= m; i++) {
        cout << fixed<< setprecision(numeric_limits<double>::max_digits10);
        cout << ans[i] << "\n";
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