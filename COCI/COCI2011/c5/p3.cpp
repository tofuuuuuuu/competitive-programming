#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 1000005;
const ll MOD = 1000000007;
//const ll BFN = (ll)1e17;
const int BFN = (int)1e9;
int n;
string s;
int dp[MAXN][2];

void sol() { 
    cin >> n >> s;

    if(s[0] == 'A') {
        dp[1][0] = 0; dp[1][1] = 1;
    }
    else {
        dp[1][0] = 1; dp[1][1] = 0;
    }
    
    for(int i = 2; i <= n; i++) {
        if(s[i-1] == 'A') {
            dp[i][0] = min(dp[i-1][0], dp[i-1][1] + 1);
            dp[i][1] = min(dp[i-1][0] + 1, dp[i-1][1] + 1);
        }
        else {
            dp[i][0] = min(dp[i-1][0] + 1, dp[i-1][1] + 1);
            dp[i][1] = min(dp[i-1][0] + 1, dp[i-1][1]);
        }
    }

    cout << dp[n][0] << "\n";
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}