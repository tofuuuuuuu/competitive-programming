#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
//const ll BFN = (ll)1e17;
const ll MOD = 1000000007;
const int BFN = (int)1e9;
int n, a, b;
vector<int> adj[MAXN];
ll dp[MAXN][2];

void fun(int v, int prev) {
    dp[v][0] = 1; dp[v][1] = 1;

    for(int i : adj[v]) {
        if(i == prev) continue;

        fun(i, v);
        dp[v][0] = ( dp[v][0] * (dp[i][0] + dp[i][1]) ) % MOD;
        dp[v][1] = ( dp[v][1] * (dp[i][0]) ) % MOD;
    }
}

void sol() { 
    cin >> n;
    for(int i = 1; i <= n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    fun(1, 1);
    cout << (dp[1][0] + dp[1][1]) % MOD << "\n";
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}