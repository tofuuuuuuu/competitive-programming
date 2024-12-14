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
int check, x, maxMsk;
ll r, l; 
string s, s1, s2;
int a[10];
ll dp[1005][(1 << 10)][2][2];

void initDp() {
    for(int i = 0; i < 1005; i++) {
        for(int j = 0; j < (1<<10); j++) {
            for(int k = 0; k < 2; k++) {
                for(int l = 0; l < 2; l++) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
}

ll fun(int n, int msk, int started, int lmt) {
    if(dp[n][msk][started][lmt] != -1) return dp[n][msk][started][lmt];
    if(n == s.length()+1) {
        if(msk == maxMsk) return 1;
        return 0;
    }

    int mx = 9;
    if(lmt) mx = s[n-1] - '0';
    
    dp[n][msk][started][lmt] = 0;
    for(int i = 0; i <= mx; i++) {
        int newLmt = lmt;
        int newStarted = started;
        int newMsk = msk;
        if(i < mx) newLmt = 0;
        if(!started) {
            if(i != 0) newStarted = 1;
        }
        
        if(newStarted) {
            for(int j = 0; j < check; j++) {
                if(i == a[j]) {
                    newMsk = (newMsk | (1<<j));
                    break;
                }
            }
        }

        dp[n][msk][started][lmt] = (dp[n][msk][started][lmt] + fun(n+1, newMsk, newStarted, newLmt)) % MOD;
    }

    return dp[n][msk][started][lmt];
}

void sol() {
    cin >> check;
    for(int i = 0; i < check; i++) {
        cin >> a[i];
    }
    maxMsk = (1 << check)-1;

    cin >> s;
    initDp();
    ll ans = fun(1, 0, 0, 1);
    if(a[0] == 0 && check == 1) ans++;

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