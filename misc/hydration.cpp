#include <bits/stdc++.h>
using namespace std;
#define ll long long

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T>
// using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// Tree<ll> tr;

// #define int long long
#define pii pair<int, int>
#define pll pair<ll ,ll>

// #define scanu(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
// char _;

const int MAXN = 1000006;
const ll MOD = 1000000007;
//const ll BFN = (ll)1e17;
const int BFN = (int)2e9;
int n, st, q, x, b;
int m, k;
ll c[MAXN];
ll t[MAXN];

bool check(int x) {
    int cnt = 1, amt = 0;
    for(int i = 1; i <= n; i++) {
        while(t[cnt] < c[i] - k) {
            cnt++;
            amt = 0;
        }

        if(t[cnt] > c[i]) return false;

        amt++;
        if(amt == x) {
            cnt++;
            amt = 0;
        }
    }
    return true;
}

void sol() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> t[i];
    }
    sort(c+1, c+n+1);
    sort(t+1, t+m+1);

    int l = 1, r = n, m, ans = -1;
    while(l <= r) {
        m = (l+r)/2;
        if(check(m)) {
            ans = m;
            r = m-1;
        }
        else {
            l = m+1;
        }
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