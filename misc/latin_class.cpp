#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int h[n+1];
    int highest = 0, highestIdx = 0;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        if(h[i] >= highest) {
            highest = h[i];
            highestIdx = i;
        }
    }
    
    ll ans = 1;
    int prevHigh = h[1];
    ll cnt = 0;
    for(int i = 2; i <= n; i++) {
        if(h[i] < prevHigh) {
            cnt++;
        }
        else {
            ans = (ans*(cnt+2)) % MOD;
            prevHigh = h[i];
            cnt = 0;
        }
    }

    cout << ans << "\n";
    
    return 0;
}