#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 1005;
const ll MOD = 1000000007;
//const ll BFN = (ll)1e17;
const int BFN = (int)1e9;
int n;
int dp[MAXN][MAXN];
int a[MAXN];

int fun(int l, int r) {
    if(dp[l][r] != 0) return dp[l][r];
    if(l > r) return BFN;
    if(l == r) return 1;

    dp[l][r] = BFN;
    for(int i = l; i < r; i++) {
        dp[l][r] = min(dp[l][r], fun(l, i) + fun(i+1, r));
    }
    if(a[l] == a[r]) {
        dp[l][r] = min(dp[l][r], fun(l,r-1));
    }
    
    return dp[l][r];
}

void sol() { 
    cin >> n;
    int newN = n;
    for(int i = 1; i <= newN; i++) {
        cin >> a[i];
        if(a[i] == a[i-1]) {
            i--;
            newN--;
        }
    }

    cout << fun(1, newN) << "\n";
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}