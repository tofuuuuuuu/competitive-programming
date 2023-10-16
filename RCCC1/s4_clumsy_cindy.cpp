#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const ll MAXV = 1000000000;

int ceil(int a, int b) {
    if(a % b == 0) return a/b;
    else return a/b + 1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n+2];
    int b[n+2];
    int c[n+2];
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    a[0] = 0; b[0] = 0; c[0] = 0;
    a[n+1] = 0; b[n+1] = 0; c[n+1] = 0;

    ll dp[n+2][5001];
    for(int i = 1; i <= n+1; i++) {
        for(int j = 0; j <= 5000; j++) dp[i][j] = MAXV;
    }
    for(int i = 0; i <= 5000; i++) dp[0][i] = 0;
    dp[1][0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int k = 0; k <= c[i]; k++) {
            int f1 = min(c[i], k + b[i-1]);
            dp[i][f1] = min(dp[i][f1], dp[i][k] + 1);

            ll t = ceil(c[i] - k, a[i]);
            int f2 = min((ll)c[i+1], t*b[i]);
            dp[i][c[i]] = min(dp[i][c[i]], dp[i][k] + t);
            dp[i+1][f2] = min(dp[i+1][f2], dp[i][k] + t);
        }
    }

    cout << dp[n][c[n]] << "\n";

    return 0;
}