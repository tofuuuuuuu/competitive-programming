#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

const int MAXN = 3005;
const ll BFN = (ll)1e17;
const ll MOD = 1000000007;
//const int BFN = (int)1e9;
int n, k;
string s;
ll dp[MAXN][MAXN];

void sol() {
    cin >> n >> s;
    dp[1][1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int newLst = 1; newLst <= i; newLst++) {
            if(s[i-2] == '<') {
                dp[i][newLst] = dp[i-1][newLst-1];
            }
            else {
                dp[i][newLst] = (dp[i-1][i-1] - dp[i-1][newLst-1]) % MOD;
                if(dp[i][newLst] < 0) dp[i][newLst] += MOD;
            }
        }

        for(int lst = 1; lst <= i; lst++) {
            dp[i][lst] = (dp[i][lst] + dp[i][lst-1]) % MOD;
        }
    }

    cout << dp[n][n] << "\n";
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}