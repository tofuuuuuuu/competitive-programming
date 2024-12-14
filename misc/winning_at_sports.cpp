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
#define pll pair<ll, ll>

// #define scanu(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
// char _;

const int MAXN = 20005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
ll n, a, b;
char c;
ll stressful[2005][2005];
ll stressfree[2005][2005];

ll funStressfree(int x, int y) {
    if(y >= x) return 0;
    if(x == 0 || y == 0) return 1;
    if(stressfree[x][y] != 0) return stressfree[x][y];

    stressfree[x][y] = (funStressfree(x-1, y) + funStressfree(x, y-1)) % MOD; 
    return stressfree[x][y];
}

ll funStressful(int x, int y) {
    if(x > y) return 0;
    if(x == 0 || y == 0) return 1; 
    if(stressful[x][y] != 0) return stressful[x][y];

    stressful[x][y] = (funStressful(x-1, y) + funStressful(x, y-1)) % MOD;
    return stressful[x][y];
}

void sol(int t) {
    cin >> a >> c >> b;
    
    funStressfree(a, b);
    funStressful(b, b);

    cout << "Case #" << t << ": " << funStressfree(a, b) <<  " " << funStressful(b, b) << "\n"; 
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; 
    for(int i = 1; i <= t; i++) sol(i);

    return 0;
}