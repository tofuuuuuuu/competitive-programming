#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    ll ans[n+1];
    for(int i = 1; i <= n; i++) ans[i] = (ll)1e10;
    ans[1] = 0;

    for(int i = 1; i <= n; i++) {
        ll curSum = 0;
        for(int d = 1; (i - d) > 0 && (i + d) <= n; d++) {
            ll val = abs(a[i + d] - a[i - d]);
            curSum += val;
            ans[2*d + 1] = min(ans[2*d + 1], curSum);
        }
    }

    for(int i = 2; i <= n; i++) {
        ll curSum = abs(a[i] - a[i-1]);
        ans[2] = min(ans[2], curSum);

        for(int d = 1; (i-1-d) > 0 && (i+d) <= n; d++) {
            ll val = abs(a[i-1-d] - a[i+d]);
            curSum += val;
            ans[2*d + 2] = min(ans[2*d + 2], curSum);
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}