#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 105;
ll dp[MAXN][MAXN];
vector<int> res;

ll dpF(int val, int prev) {
    if(val == 0) {
        dp[val][prev] = 1;
        return 1;
    }
    if(dp[val][prev] != 0) return dp[val][prev];

    ll ans = 0;
    for(int i = 1; i <= prev && i <= val; i++) {
        ans += dpF(val - i, i);
    }
    dp[val][prev] = ans;
    return ans;
}

void fun(int val, ll k) {
    if(val == 0) return;
    ll ans = 0; int pos = -1;
    for(int i = 1; i <= val; i++) {
        ans += dp[val-i][i];
        if(ans >= k) {
            ans -= dp[val-i][i];
            pos = i;
            break;
        }
    }

    res.push_back(pos);
    fun(val - pos, k - ans);
}

void testCase() {
    res.clear();
    int a; ll k; cin >> a >> k;
    
    if(dp[a][a] < k) {
        cout << "Too big" << "\n";
        return;
    }

    fun(a, k);

    cout << "(" << res[0];
    for(int i = 1; i < res.size(); i++) {
        cout << "," << res[i];
    }
    cout << ")\n"; 
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < MAXN; i++) {
        for(int j = 1; j < MAXN; j++) {
            dpF(i, j);
        }
    }
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        testCase();
    }
    
    return 0;
}