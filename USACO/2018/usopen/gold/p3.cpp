#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

const int MAXN = 250001;
const ll BFN = (ll)1e14;
//const int BFN = (int)1e9;
int a[MAXN];
int n, minW;
int w[255];
int t[255];
ll dp[MAXN];

int main(){
    freopen("talent.in", "r", stdin);
	freopen("talent.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> minW;
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> t[i];
    }
    for(int i = 1; i < MAXN; i++) {
        dp[i] = BFN;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = MAXN-1; j >= t[i]; j--) {
            dp[j] = min(dp[j], dp[j-t[i]] + w[i]);
        }
    }

    long double ans = 0;
    for(int i = 1; i < MAXN; i++) {
        if(dp[i] < minW) continue;
        if(dp[i] == BFN) continue;
        long double cur = (long double)i/(long double)dp[i];
        ans = max(ans, cur);
    }
    ans *= 1000;

    cout << (ll)ans << "\n";

    return 0;
}