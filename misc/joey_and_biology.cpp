#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll ,ll>

// #define scanu(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
// char _;

const int MAXN = 1005;
const ll MOD = 1000000007;
//const ll BFN = (ll)1e17;
const int BFN = (int)2e9;
int n, m, q, a, b, v, w;
int h[MAXN];
int dp[MAXN][MAXN];
string s1, s2;

void sol() {
    cin >> n >> m >> s1 >> s2;

    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = (i+2)/3;
    }
    for(int j = 1; j <= m; j++) {
        dp[0][j] = (j+2)/3;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = BFN;
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            if(i-1 >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            if(i-2 >= 0) dp[i][j] = min(dp[i][j], dp[i-2][j] + 1);
            if(i-3 >= 0) dp[i][j] = min(dp[i][j], dp[i-3][j] + 1);
            if(j-1 >= 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            if(j-2 >= 0) dp[i][j] = min(dp[i][j], dp[i][j-2] + 1);
            if(j-3 >= 0) dp[i][j] = min(dp[i][j], dp[i][j-3] + 1);
            if(i-1 >= 0 && j-1 >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
        }
    }

    cout << dp[n][m] << "\n";
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}