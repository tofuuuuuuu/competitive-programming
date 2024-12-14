#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 1000005;
const ll MOD = 1000000007;
const ll BFN = (ll)1e16;
int n;
int a[MAXN];

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        int opp = (i+n/2) % n;
        if(opp == 0) opp = n;

        if(a[i] == a[opp]) ans++;
    }

    cout << ans << "\n";

    return 0;
}