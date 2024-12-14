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

const int MAXN = 10005;
const ll MOD = 1000000007;
// const ll BFN = (ll)1e16;
const int BFN = (int)1e8;
int n, k; char c;
vector<int> v;
int a[MAXN][11][11];
int m1[11][11];
map<int, int> mp;

void flip(int k, int i, int j) {
    a[k][i][j] ^= 1;
    a[k][i+1][j] ^= 1;
    a[k][i][j+1] ^= 1;
    a[k][i+1][j+1] ^= 1;
}

int convert(int k) {
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            if(a[k][i][j]) flip(k, i, j);
        }
    }

    int val = 0;
    int mt = 1;
    for(int i = 1; i <= n; i++) {
        val += a[k][i][n] * mt;
        mt *= 2;
    }
    for(int i = 1; i <= n; i++) {
        val += a[k][n][i] * mt;
        mt *= 2;
    }
    return val;
}

void sol() {
    cin >> n >> k;
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            for(int l = 1; l <= n; l++) {
                cin >> c;
                if(c == 'R') a[i][j][l] = 1;
            }
        }
    }

    for(int i = 1; i <= k; i++) {
        mp[convert(i)]++;
    }

    int ans = 0;
    for(auto i : mp) {
        ans += i.second * (i.second - 1) / 2;
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