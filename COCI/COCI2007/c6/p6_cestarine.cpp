#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 100005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n;
int a[MAXN];
int b[MAXN];
int dp[MAXN];

int getMin1(int x) {
    if(a[x] == b[x]) return BFN;
    return abs(a[x] - b[x]);
}

int getMin2(int x) {
    if(a[x-1] == b[x-1] || a[x] == b[x]) return abs(a[x-1] - b[x]) + abs(a[x] - b[x-1]);
    return min(abs(a[x-1] - b[x-1]) + abs(a[x]-b[x]), abs(a[x-1] - b[x]) + abs(a[x] - b[x-1]));   
}

int getMin3(int x) {
    int ret = BFN;
    for(int i = 0; i <= 2; i++) {
        for(int j = 0; j <= 2; j++) {
            if(j == i) continue;

            for(int k = 0; k <= 2; k++) {
                if(k == i || k == j) continue;
                if(a[x-2] == b[x-i] || a[x-1] == b[x-j] || a[x] == b[x-k]) continue;

                ret = min(ret, abs(a[x-2] - b[x-i]) + abs(a[x-1] - b[x-j]) + abs(a[x] - b[x-k]));
            }
        }
    }
    return ret;
}

void sol() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);

    dp[0] = 0;
    dp[1] = getMin1(1);
    dp[2] = getMin2(2);

    for(int i = 3; i <= n; i++) {
        dp[i] = BFN;
        dp[i] = min(dp[i], dp[i-1] + getMin1(i));
        dp[i] = min(dp[i], dp[i-2] + getMin2(i));
        dp[i] = min(dp[i], dp[i-3] + getMin3(i));
    }

    cout << dp[n] << "\n";
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    sol();

    return 0;
}