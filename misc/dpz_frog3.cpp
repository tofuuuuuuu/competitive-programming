#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 500005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, c;
int h[MAXN];
int dp[MAXN];

struct LineContainer {
    int m[MAXN];
    int b[MAXN];
    int l = 0, r = 0;

    void addLine(int m1, int b1) {
        while(r - l + 1 >= 2 && intersect(m1, b1, m[r], b[r]) < intersect(m1, b1, m[r-1], b[r-1])) {
            r--;
        }
        r++;
        m[r] = m1;
        b[r] = b1;
    }

    int getMin(int x) {
        while(l+1 <= r && getVal(m[l], b[l], x) > getVal(m[l+1], b[l+1], x)) {
            l++;
        }
        return getVal(m[l], b[l], x);
    }

    long double intersect(long double m1, long double b1, long double m2, long double b2) {
        return (b1 - b2) / (m2 - m1);
    }

    int getVal(int m, int b, int x) {
        return m*x + b;
    }
};

void sol() {
    cin >> n >> c;
    LineContainer lc;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    dp[1] = 0;
    lc.addLine(-2*h[1], h[1]*h[1] + dp[1]);
    for(int i = 2; i <= n; i++) {
        dp[i] = lc.getMin(h[i]) + c + h[i]*h[i];
        lc.addLine(-2*h[i], h[i] * h[i] + dp[i]);
    }
    cout << dp[n] << "\n";
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    sol();

    return 0;
}