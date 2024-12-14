#include <bits/stdc++.h>
using namespace std;
#define ll long long

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T>
// using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// Tree<ll> tr;

#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

// #define scanu(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
// char _;

const int MAXN = 100005;
const ll MOD = 1000000007;
// const ll BFN = (ll)1e17;
const int BFN = (int)1e9;
int n, k;
int a[MAXN];
int dist[MAXN];
int prv[MAXN];
int nxt[MAXN];
bool removed[MAXN];

struct Link {
    int w, idx;

    Link(int x, int y) {
        w = x; idx = y;
    }
};

class cmp {
public:
    bool operator() (Link a, Link b) {
        if(a.w == b.w) return a.idx > b.idx;
        return a.w > b.w;
    }
};

void sol() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++) {
        dist[i] = a[i+1] - a[i]; 
        prv[i] = i-1;
        nxt[i] = i+1;
    }
    dist[0] = BFN; dist[n] = BFN;
    prv[0] = 0; nxt[n] = n;

    priority_queue<Link, vector<Link>, cmp> pq;
    for(int i = 1; i < n; i++) {
        pq.push(Link(dist[i], i));
    }

    int ans = 0;
    for(int cnt = 1; cnt <= k; cnt++) {
        while(removed[pq.top().idx]) pq.pop();
        Link cur = pq.top(); pq.pop();

        ans += cur.w;
        int oldPrv = prv[cur.idx]; int oldNxt = nxt[cur.idx];
        dist[cur.idx] = dist[oldPrv] + dist[oldNxt] - cur.w;
        pq.push(Link(dist[cur.idx], cur.idx));
        removed[oldPrv] = true; removed[oldNxt] = true;
        prv[cur.idx] = prv[oldPrv]; nxt[cur.idx] = nxt[oldNxt];
        nxt[prv[cur.idx]] = cur.idx; prv[nxt[cur.idx]] = cur.idx;
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