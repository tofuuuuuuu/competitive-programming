#include <bits/stdc++.h>
using namespace std;

int main ()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    long k;
    cin >> n >> k;
    long t[n];
    long x[n];
    long y[n];
    for(int i = 0; i < n; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }

    long minR, maxL, ans;
    ans = 0;
    minR = maxL = x[0];

    for(int i = 1; i < n; i++) {
        minR = max(minR - k*(t[i]-t[i-1]), x[i]);
        maxL = min(maxL + k*(t[i]-t[i-1]), x[i]);
        ans = max(ans, minR - maxL);
    }
    minR = maxL = y[0];
    for(int i = 1; i < n; i++) {
        minR = max(minR - k*(t[i]-t[i-1]), y[i]);
        maxL = min(maxL + k*(t[i]-t[i-1]), y[i]);
        ans = max(ans, minR - maxL);
    }

    cout << ans << "\n";

    return 0;
}