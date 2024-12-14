#include <bits/stdc++.h>
using namespace std;
#define ll long long

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T>
// using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// Tree<ll> tr;

// #define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

// #define scanu(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
// char _;

const int MAXN = 205;
const ll MOD = 1000000007;
// const ll BFN = (ll)1e17;
const int BFN = (int)1e8;
int n, w, m, x, y; char type;
vector<int> adj[MAXN];
int t[MAXN]; //accuse = 1, defend = 0
ll dp[MAXN][2][MAXN]; //0 : not a werewolf, 1 : werewolf
ll tmp[MAXN][2][MAXN];
int inDeg[MAXN];

void dfs(int v) {
    if(adj[v].size() == 0) {
        dp[v][0][0] = 1;
        dp[v][1][1] = 1;
        return;
    }

    for(int i : adj[v]) {
        dfs(i);
    }

    //if v is not a werewolf:
    dp[v][0][0] = 1;
    for(int i : adj[v]) {
        for(int v1 = 0; v1 <= w; v1++) {
            for(int v2 = 0; v2 <= w; v2++) {
                if(v1 + v2 > w) continue;
                tmp[v][0][v1 + v2] = (tmp[v][0][v1 + v2] + (dp[v][0][v1] * (dp[i][0][v2] + dp[i][1][v2])) % MOD) % MOD;
            }
        }

        for(int k = 0; k < MAXN; k++) {
            dp[v][0][k] = tmp[v][0][k];
            tmp[v][0][k] = 0;
        }
    }

    //if v is a werewolf:
    dp[v][1][1] = 1;
    for(int i : adj[v]) {
        if(t[i] == 1) { //accused => i not werewolf 
            for(int v1 = 0; v1 <= w; v1++) {
                for(int v2 = 0; v2 <= w; v2++) {
                    if(v1 + v2 > w) continue;
                    tmp[v][1][v1 + v2] = (tmp[v][1][v1 + v2] + (dp[v][1][v1] * dp[i][0][v2]) % MOD) % MOD;
                }
            }
        }
        else { //defended => i is werewolf 
            for(int v1 = 0; v1 <= w; v1++) {
                for(int v2 = 0; v2 <= w; v2++) {
                    if(v1 + v2 > w) continue;
                    tmp[v][1][v1 + v2] = (tmp[v][1][v1 + v2] + (dp[v][1][v1] * dp[i][1][v2]) % MOD) % MOD;
                }
            }
        }

        for(int k = 0; k < MAXN; k++) {
            dp[v][1][k] = tmp[v][1][k];
            tmp[v][1][k] = 0;
        }
    }

    return;
}

void sol() {
    cin >> n >> w >> m;
    for(int i = 1; i <= m; i++) {
        cin >> type >> x >> y;
        inDeg[y]++;
        adj[x].push_back(y);
        if(type == 'A') t[y] = 1;
        else t[y] = 0;
    }

    for(int i = 1; i <= n; i++) {
        if(inDeg[i] == 0) adj[n+1].push_back(i);
    }

    dfs(n+1);
    cout << dp[n+1][0][w] << "\n";
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}