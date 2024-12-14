#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

const ll MOD = 1000000007;
int n;

vector<vector<ll>> mult(vector<vector<ll>> a, vector<vector<ll>> b) {
    vector<ll> row(n+1, 0);
    vector<vector<ll>> res(n+1, row);
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % MOD ) % MOD;
            }
        }
    }

    return res;
}

vector<vector<ll>> quickPow(vector<vector<ll>> m, ll p) {
    vector<ll> row(n+1, 0);
    vector<vector<ll>> ans(n+1, row);
    vector<vector<ll>> cur(n+1, row);

    for(int i = 1; i <= n; i++) ans[i][i] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) cur[i][j] = m[i][j];
    }

    while(p) {
        if(p & 1) ans = mult(ans, cur);

        p >>= 1;
        cur = mult(cur, cur);
    }

    return ans;
}

vector<vector<ll>> testF(vector<vector<ll>> a) {
    a[1][1] = 1;
    return a;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll k; cin >> n >> k;
    vector<ll> row(n+1, 0);
    vector<vector<ll>> a(n+1, row);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    a = quickPow(a, k);

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) ans = (ans + a[i][j]) % MOD;
    }
    if(ans < 0) ans += MOD;

    cout << ans << "\n";
    
    return 0;
}