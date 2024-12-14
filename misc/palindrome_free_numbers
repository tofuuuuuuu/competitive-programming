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

const int MAXN = 1000005;
const int MAXK = 1000005;
const ll MOD = 1000000007;
const ll BFN = (ll)1e17;
//const int BFN = (int)2e9;
int n, x, target;
ll r, l; 
string s, s1, s2;
ll dp[20][100][3][2];

void initDp() {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 100; j++) {
            for(int k = 0; k < 3; k++) {
                for(int l = 0; l < 2; l++) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
}

ll fun(int n, int prev, int prefLen, int lmt) {
    if(dp[n][prev][prefLen][lmt] != -1) return dp[n][prev][prefLen][lmt];
    if(n == s.length()+1) return 1;

    int mx = 9;
    if(lmt) mx = s[n-1] - '0';
    
    dp[n][prev][prefLen][lmt] = 0;
    for(int i = 0; i <= mx; i++) {
        int newLmt = lmt;
        int newPrefLen = prefLen;
        if(i < mx) newLmt = 0;
        if(prefLen == 0) {
            if(i != 0) newPrefLen++;
        }
        else if(prefLen == 1) newPrefLen++;
        
        if(prefLen == 1) {
            if(prev == i) continue;
        }
        if(prefLen == 2) {
            if(prev % 10 == i) continue;
            if(prev/10 == i) continue;
        }

        dp[n][prev][prefLen][lmt] += fun(n+1, (prev % 10)*10 + i, newPrefLen, newLmt);
    }

    return dp[n][prev][prefLen][lmt];
}

void sol() {
    cin >> l >> r; l--;

    s = to_string(r);
    initDp();
    ll ans = fun(1, 0, 0, 1);

    s = to_string(l);
    initDp();
    ans -= fun(1, 0, 0, 1);
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