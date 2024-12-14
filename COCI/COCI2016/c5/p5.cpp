#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 500005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, q, x, y; char qType;

int seg[4*MAXN];
int a[MAXN];
unordered_map<int, int> last;
unordered_map<int, int> secondLast;
unordered_map<int, int> thirdLast;
int ans[MAXN];

struct Query{
    int l, r, idx;
    Query(int a, int b, int c) {
        l = a; r = b; idx = c;
    }
};
vector<Query> vec;

bool cmp(Query a, Query b) {
    return a.r < b.r;
}

void pushup(int cur) {
    seg[cur] = seg[2*cur] + seg[2*cur+1];
}   

void update(int cur, int l, int r, int idx, int v) {
    if(l == r) {
        seg[cur] = v;
        return;
    }

    int m = (l+r)/2;
    if(idx <= m) {
        update(2*cur, l, m, idx, v);
    }
    else {
        update(2*cur+1, m+1, r, idx, v);
    }
    pushup(cur);
}

int query(int cur, int l, int r, int ql, int qr) {
    if(r < ql || qr < l) return 0;
    if(ql <= l && r <= qr) {
        return seg[cur];
    }

    int m = (l+r) / 2;
    return query(2*cur, l, m, ql, qr) + query(2*cur+1, m+1, r, ql, qr);
}

void insert(int idx, int v) {
    if(thirdLast[v] != 0) {
        update(1, 1, n, thirdLast[v], 0);
    }
    if(secondLast[v] != 0) {
        update(1, 1, n, secondLast[v], 0);
    }

    thirdLast[v] = secondLast[v];
    secondLast[v] = last[v];
    last[v] = idx;

    if(secondLast[v] != 0) {
        update(1, 1, n, secondLast[v], 1);
    }
    if(thirdLast[v] != 0) {
        update(1, 1, n, thirdLast[v], -1);
    }
}

void sol() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= q; i++) {
        cin >> x >> y;
        vec.push_back(Query(x, y, i));
    } 
    sort(vec.begin(), vec.end(), cmp);

    int idx = 1;
    for(Query qu : vec) {
        while(idx <= qu.r) {
            insert(idx, a[idx]);
            idx++;
        }

        ans[qu.idx] = query(1, 1, n, qu.l, qu.r);
    }

    for(int i = 1; i <= q; i++) {
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