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

const int MAXN = 310;
const ll MOD = 1000000007;
// const ll BFN = (ll)1e17;
const int BFN = (int)1e8;
int n, idx, d, child, x, v;
ll dp[MAXN][2*MAXN];
int c[MAXN];
vector<int> adj[MAXN];

int shiftVal(int x) {
    return 303 + x;
}

void init() {
    for(int i = 0; i < MAXN; i++) {
        for(int j = 0; j < 2*MAXN; j++) {
            dp[i][j] = BFN;
        }
    }
}

void dfs(int v) {
    dp[v][shiftVal(0)] = 1;
    if(adj[v].size() == 0 ) {
        dp[v][shiftVal(c[v])] = 0;
    }
    else if(adj[v].size() == 1){
        dfs(adj[v][0]);
        for(int i = -302; i <= 302; i++) {
            int sum = i + c[v];
            if(shiftVal(sum) < 0 || shiftVal(sum) >= 2*MAXN) continue;
            dp[v][shiftVal(sum)] = min(dp[v][shiftVal(sum)], dp[adj[v][0]][shiftVal(i)]);
        }
    }
    else {
        int c1 = adj[v][0], c2 = adj[v][1];
        dfs(c1);
        dfs(c2);

        for(int i = -302; i <= 302; i++) {
            for(int j = -302; j <= 302; j++) {
                int sum = i + j + c[v];
                if(shiftVal(sum) < 0 || shiftVal(sum) >= 2*MAXN) continue;

                dp[v][shiftVal(sum)] = min(dp[v][shiftVal(sum)], dp[c1][shiftVal(i)] + dp[c2][shiftVal(j)]);
            }
        }
    }
}

void sol() {
    cin >> n >> d;

    init();
    for(int i = 1; i <= n; i++) {
        cin >> idx; idx++;
        cin >> c[idx] >> child;
        if(c[idx] == 0) c[idx] = -1;

        for(int j = 1; j <= child; j++) {
            cin >> x; x++;
            adj[idx].push_back(x);
        }
    }

    dfs(1);

    if(dp[1][shiftVal(d)] == BFN) {
        cout << "-1\n";
    }
    else {
        cout << dp[1][shiftVal(d)] << "\n";
    }
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}