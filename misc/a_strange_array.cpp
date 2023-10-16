#include <bits/stdc++.h>
using namespace std;

int main ()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    int a[n+1];
    int prev1[n+2];
    int next1[n+2];
    int psa[n+1];
    prev1[0] = -1;
    next1[n+1] = -1;
    psa[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        psa[i] = a[i] + psa[i-1];
        if(a[i] == 1) prev1[i] = i;
        else prev1[i] = prev1[i-1];
    }
    for(int i = n; i > 0; i--) {
        if(a[i] == 1) next1[i] = i;
        else next1[i] = next1[i+1];
    }

    for(int t = 0; t < q; t++) {
        int l, r, x;
        cin >> l >> r >> x;

        if((psa[r] - psa[l-1]) % 2 == x % 2) {
            if(psa[r] - psa[l-1] >= x) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
        else {
            if(next1[l] == -1 || next1[l] > r) cout << "NO" << "\n";
            else {
                int newSum = psa[r] - psa[l-1] - 2*min(next1[l] - l, r - prev1[r]);
                if(newSum >= x) cout << "YES" << "\n";
                else cout << "NO" << "\n";
            } 
        }
    }

    return 0;
}