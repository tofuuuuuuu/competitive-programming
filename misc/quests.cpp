#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const ll BIGVAL = (ll)1e16;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, H;
    cin >> n >> H;
    ll g[n+1];
    int h[n+1];
    ll q[n+1];
    int t[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> g[i] >> h[i] >> q[i] >> t[i];
    }

    ll dp[H+1][2];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < h[i]; j++) {
            dp[j][1] = -BIGVAL;
        }
        for(int j = h[i]; j <= H; j++) {
            dp[j][1] = dp[j-h[i]][0] + g[i];
            if(j-t[i] >= 0) dp[j][1] = max(dp[j][1], dp[j-t[i]][1] + q[i]);
        }
        for(int j = 0; j <= H; j++) {
            dp[j][0] = max(dp[j][0], dp[j][1]);
            dp[j][1] = 0;
        }
    }

    ll ans = 0;
    for(int i = 0; i <= H; i++) {
        ans = max(ans, dp[i][0]);
    }
    cout << ans << "\n";

    return 0;
}