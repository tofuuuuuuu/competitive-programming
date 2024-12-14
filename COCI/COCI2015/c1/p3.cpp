#include <bits/stdc++.h>
using namespace std;
#define ll long long

// #define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 1000005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, x;
map<int, int> cnt;

void sol() {
    cin >> n;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        cnt[x]++;
        if(cnt[x+1] > 0) {
            cnt[x+1]--;
        }
        else {
            ans++;
        }
    }

    cout << ans << "\n";
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}