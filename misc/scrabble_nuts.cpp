#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int BIGVAL = (int)1e8;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; string a, b; cin >> n >> m >> a >> b;

    int dp[2][m+1];
    memset(dp, 0, sizeof(dp));

    for(int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }
    for(int i = 1; i <= n; i++) {
        dp[1][0] = i;
        for(int j = 1; j <= m; j++) {
            if(a[i-1] == b[j-1]) dp[1][j] = dp[0][j-1];
            else {
                //insertion, replace, deletion
                dp[1][j] = min(dp[1][j-1] + 1, min(dp[0][j-1] + 1, dp[0][j] + 1));
            }
        }
        for(int j = 0; j <= m; j++) {
            dp[0][j] = dp[1][j]; dp[1][j] = 0;
        }
    }

    int ans = 0;
    for(int i = 1; i < m; i++) {
        ans += dp[0][i];
    }

    cout << ans << "\n";
    
    return 0;
}