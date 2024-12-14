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

const int MAXN = 1000006;
const ll MOD = 1000000007;
// const ll BFN = (ll)1e17;
const int BFN = (int)1e8;
int n, q, x, y;
int h[MAXN];
ll ans[MAXN];
bool inArr[MAXN];
vector<pii> v;

int p[MAXN];
int sz[MAXN];

void init() {
    for(int i = 1; i <= n; i++) {
        p[i] = i; sz[i] = 1;
    }
}

int find(int v) {
    if(p[v] != v) p[v] = find(p[v]);
    return p[v];
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;

    if(sz[a] < sz[b]) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
}

void sol() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> h[i]; 
        v.push_back({h[i], i});
    }
    sort(v.begin(), v.end(), greater<pii>());

    init();
    int cnt = 0;
    for(int i = 1000000; i >= 1; i--) {
        ll curAns = 0;
        while(cnt < n && v[cnt].first >= i) {
            int idx = v[cnt].second; ll lft = 1, rht = 1;
            if(inArr[idx-1]) lft = sz[find(idx-1)] + 1;
            if(inArr[idx+1]) rht = sz[find(idx+1)] + 1;
            curAns += lft * rht;

            inArr[idx] = 1;
            if(inArr[idx-1]) merge(idx, idx-1);
            if(inArr[idx+1]) merge(idx, idx+1);
            cnt++;
        }

        ans[i] = ans[i+1] + curAns;
    }

    for(int i = 1; i <= q; i++) {
        cin >> x >> y;
        cout << ans[x] - ans[y+1] << "\n";
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