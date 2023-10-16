#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 205;
const ll MOD = 1000000007;
//const ll BFN = (ll)1e17;
const int BFN = (int)1e9;
int n, k;
int a[MAXN];
ll dp[MAXN][MAXN];

ll fun(int l, int r) {
    if(r - l <= 1) return 0;
    if(dp[l][r] != 0) return dp[l][r];

    for(int i = l+1; i <= r-1; i++) {
        dp[l][r] = max(dp[l][r], fun(l, i) + fun(i, r) + a[l] + a[i] + a[r]);
    }
    return dp[l][r];
}

bool sol() { 
    cin >> n; 
    if(n == 0) return false;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    cout << fun(1, n) << "\n";
    return true;
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    while(sol()) {

    }

    return 0;
}