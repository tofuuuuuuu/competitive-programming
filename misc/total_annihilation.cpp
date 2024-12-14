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

const int MAXN = 200005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, m;
ll ans;
int a[40];
unordered_map<int, int> mp;

void sol() {   
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> a[i+n];
        a[i+n] = -a[i+n];
    }

    int t = (n+m) / 2;
    int maxMsk = (1 << t) - 1;
        
    for(int msk = 0; msk <= maxMsk; msk++) {
        int tmp = msk, sm = 0;
        for(int cur = 1; cur <= t; cur++) {
            if((msk & (1 << (cur-1))) > 0) sm += a[cur];
        }
        mp[sm]++;
    }

    t = n + m - t;
    maxMsk = (1 << t) - 1;
        
    ans = 0;
    for(int msk = 0; msk <= maxMsk; msk++) {
        int tmp = msk, sm = 0;
        for(int cur = 1; cur <= t; cur++) {
            if((msk & (1 << (cur-1))) > 0) sm += a[n+m-t+cur];
        }
        
        ans += mp[-sm];
    }

    cout << ans - 1 << "\n";
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    sol();

    return 0;
}