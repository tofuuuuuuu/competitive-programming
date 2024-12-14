#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; 
    string s;
    cin >> n >> s;
    string rev = "";
    for(int i = n-1; i >= 0; i--) {
        rev += s[i];
    }

    short dp[2][n+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == rev[j-1]) {
                dp[1][j] = dp[0][j-1] + 1;
            }
            else dp[1][j] = max(dp[0][j], dp[1][j-1]);
        }
        for(int j = 0; j <= n; j++) {
            dp[0][j] = dp[1][j];
        }
    }

    short lcs = dp[0][n]; 
    cout << n - lcs << "\n";

    return 0;
}