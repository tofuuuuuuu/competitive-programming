#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ll a[n+1];

    a[0] = 0;
    a[1] = 1;
    for(int i = 2; i <= n; i++) {
        a[i] = a[i-1] + a[i-2];
    }
    cout << a[n];

    return 0;
}