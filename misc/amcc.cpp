#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int> 

const int MAXN = 66400000;
const int PRECOMPN = 180000;
const ll MOD = 1000000007;
int phi[PRECOMPN];
unordered_map<ll, int> f;

void precomp(int n) {
    int origN = n;
    int ans = n;
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) n/=i;

            ans = (ans - ans/i);
        }
    }

    if(n > 1) ans = (ans - ans/n);

    phi[origN] = ans;
}

int fun(ll n) {
    if(n < PRECOMPN) return phi[n];
    if(f.find(n - PRECOMPN) != f.end()) return f[n - PRECOMPN];

    ll ans = 0;
    if(n % 2 == 0) {
        ans = (n/2) % MOD; ans = ans*(n+1) % MOD;
    }
    else {
        ans = ((n+1)/2) % MOD; ans = ans*(n) % MOD;
    }

    for(ll m = 2; m*m <= n; m++) {
        ans = (ans - fun(n/m)) % MOD;
    }

    for(ll d = 1; d*d <= n; d++) {
        if(d == n/d) continue;
        ans = ans - ( ( ((n/d) - (n/(d+1)))) * fun(d) ) % MOD;
    }
    ans = ans % MOD;

    f[n - PRECOMPN] = ans;
    return ans;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i < PRECOMPN; i++) precomp(i);
    for(int i = 2; i < PRECOMPN; i++) {
        phi[i] = (phi[i] + phi[i-1]) % MOD;
    }

    ll n; cin >> n;

    ll ans = fun(n) % MOD;
    if(ans < 0) ans += MOD; 
    cout << ans << "\n";
    
    return 0;
}