#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
ll a[MAXN];
int M, m;
ll n;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> n;
    m = M;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a, a + n+1, greater<int>());

    ll curS;
    for(int i = 0; i < n; i++) {
        ll amt = i+1;
        ll curS = (a[i] - a[i+1]) * amt;

        if(curS > m) {
            ll subtractAmt = m / amt;
            ll cnt = 0;
            for(int j = 0; j <= i; j ++) {
                cnt += a[j] - a[i];
                a[j] = a[i];
            }
            M -= cnt;
            for(int j = 0; j <= i; j++) {
                a[j] -= subtractAmt;
                M -= subtractAmt;
            }
            for(int j = 0; j < M; j++) {
                a[j]--;
            }

            break;
        }
        else {
            m -= curS;
        }
    }

    ll res = 0;
    for(int i = 0; i < n; i++) {
        res += a[i] * a[i];
    }

    cout << res << "\n";

    return 0;
}