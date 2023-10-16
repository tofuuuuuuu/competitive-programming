#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 505;
const ll MOD = 1000000007;
int a[MAXN];
ll ans = 1;
ll sum = 0;
int k;

ll modInv(ll a) {
    ll p = MOD - 2;
    ll ans = 1;
    ll cur = a;
    while(p) {
        if(p & 1) {
            ans *= cur;
            ans %= MOD;
        }  
        p >>= 1;
        cur *= cur;
        cur %= MOD;
    }
    return ans;
}

ll fun(ll n, ll k) {
    ll numer = 1;
    ll denom = 1;
    for(ll i = k+1; i <= n; i++) {
        numer = (numer*i) % MOD;
    }
    for(ll i = 1; i <= n-k; i++) {
        denom = (denom * i) % MOD;
    }
    ll ret = (numer * modInv(denom)) % MOD;
    if(ret < 0) ret += MOD;
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    for(int i = 1; i <= k; i++) {
        cin >> a[i];
    }

    sum = a[1];
    for(int i = 2; i <= k; i++) {
        sum = sum + a[i];
        ans = (ans * fun(sum - 1, a[i] - 1)) % MOD;
    }

    cout << ans << "\n";

    return 0;
} 