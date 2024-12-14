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
ll dp[100005][2][2][2];

void initDp() {
    for(int i = 0; i < 100005; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                for(int l = 0; l < 2; l++) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
}

ll fun(int n, int has1, int amt0, int lmt) {
    if(dp[n][has1][amt0][lmt] != -1) return dp[n][has1][amt0][lmt];
    if(n == s.length()+1) {
        if(has1 && amt0) return 1;
        return 0;
    }

    int mx = 9;
    if(lmt) mx = s[n-1] - '0';
    
    dp[n][has1][amt0][lmt] = 0;
    for(int i = 0; i <= mx; i++) {
        int newLmt = lmt;
        if(i < mx) newLmt = 0;
        if(has1 && i == 0) {
            if(amt0 == 1) continue;
            dp[n][has1][amt0][lmt] += fun(n+1, 1, amt0+1, newLmt);
        }
        else if(!has1 && i == 1) {
            dp[n][has1][amt0][lmt] += fun(n+1, 1, amt0, newLmt);
        }
        else {
            dp[n][has1][amt0][lmt] += fun(n+1, has1, amt0, newLmt);
        }
    }
    dp[n][has1][amt0][lmt] %= MOD;

    return dp[n][has1][amt0][lmt];
}

void sol() {
    cin >> s;
    initDp();
    cout << fun(1, 0, 0, 1) << "\n";
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}