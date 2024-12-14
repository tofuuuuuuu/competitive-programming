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
#define pll pair<ll ,ll>

// #define scanu(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
// char _;

const int MAXN = 100005;
const ll MOD = 1000000007;
//const ll BFN = (ll)1e17;
const int BFN = (int)2e9;
int n, m, q, a, b, v, w, l, r, st, cnt;
ll adj[27][27];
string s;

void sol() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        adj[s[0] - 'A' + 1][s[s.size()-1] - 'A' +1]++;
    }

    ll ans = 0;
    for(int i = 1; i <= 26; i++) {
        for(int j = 1; j <= 26; j++) {
            for(int k = 1; k <= 26; k++) {
                for(int l = 1; l <= 26; l++) {
                    ll a = adj[i][j]; adj[i][j]--;
                    ll b = adj[i][k]; adj[i][k]--;
                    ll c = adj[j][l]; adj[j][l]--;
                    ll d = adj[k][l]; adj[k][l]--;

                    ans += a * b * c * d;
                    adj[i][j]++; adj[i][k]++; adj[j][l]++; adj[k][l]++;
                }
            }
        }
    }
    cout << ans << "\n";
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}