#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 505;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, inter;
int f[2][MAXN][MAXN];
int psa[2][MAXN][MAXN];

void resetf1() {
    for(int i = 0; i < MAXN; i++) {
        for(int j = 0; j < MAXN; j++) {
            f[1][i][j] = 0;
        }
    }
}

void makePsa() {
    for(int a = 0; a <= n; a++) {
        psa[0][a][0] = f[0][a][0];
        for(int k = 1; k <= inter; k++) {
            psa[0][a][k] = (f[0][a][k] + psa[0][a][k-1]) % MOD;
        }
    }
}

void sol() {
    cin >> n >> inter;

    f[0][0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int a = 0; a <= n; a++) {
            for(int k = 0; k <= inter; k++) {
                f[1][a][k] = (f[1][a][k] + f[0][a][k]) % MOD;
                if(a-1 >= 0) f[1][a][k] = (f[1][a][k] + f[0][a-1][k]) % MOD;

                ll s = psa[0][a+1][k];
                ll s2 = 0;
                if(k-a-1 >= 0) s2 = psa[0][a+1][max((ll)0, k-a-1)];
                s = (s - s2) % MOD;

                if(s < 0) s += MOD;
                f[1][a][k] = (f[1][a][k] + s) % MOD;
            }
        }

        swap(f[0], f[1]);
        resetf1();
        makePsa();
    }

    cout << f[0][0][inter] << "\n";
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    sol();

    return 0;
}