#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll ,ll>

const int MAXN = 55;
const ll MOD = 1000000007;
//const ll BFN = (ll)1e17;
const ll BFN = (int)2e9;
int n, cnt = 0, sum = 0;
int psa[MAXN][MAXN];

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T>
// using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// Tree<pll> tr;

unordered_map<int, int> mp;

void doPSA() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            psa[i][j] = psa[i][j] + psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }
}

ll getSum(int x1, int x2, int y1, int y2) {
    return psa[x2][y2] - psa[x1-1][y2] - psa[x2][y1-1] + psa[x1-1][y1-1];
}

void minmin(int x, int y) {
    if(x == 0 || y == 0 || x == n+1 || y == n+1) return;
    int x2 = x, y2 = y;

    for(int x1 = x2; x1 >= 1; x1--) {
        for(int y1 = y2; y1 >= 1; y1--) {
            mp[getSum(x1, x2, y1, y2)]++;
        }
    }
}

void plusplus(int x, int y) {
    if(x == 0 || y == 0 || x == n+1 || y == n+1) return;
    int x1 = x, y1 = y;

    for(int x2 = x1; x2 <= n; x2++) {
        for(int y2 = y1; y2 <= n; y2++) {
            if(mp.find(getSum(x1, x2, y1, y2)) != mp.end()) cnt += mp[getSum(x1, x2, y1, y2)];
        }
    }
}

void minplus(int x, int y) {
    if(x == 0 || y == 0 || x == n+1 || y == n+1) return;
    int x2 = x, y1 = y;

    for(int x1 = x2; x1 >= 1; x1--) {
        for(int y2 = y1; y2 <= n; y2++) {
            mp[getSum(x1, x2, y1, y2)]++;
        }
    }
}

void plusmin(int x, int y) {
    if(x == 0 || y == 0 || x == n+1 || y == n+1) return;
    int x1 = x, y2 = y;

    for(int x2 = x1; x2 <= n; x2++) {
        for(int y1 = y2; y1 >= 1; y1--) {
            if(mp.find(getSum(x1, x2, y1, y2)) != mp.end()) cnt += mp[getSum(x1, x2, y1, y2)];
        }
    }
}

void sol() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> psa[i][j];
        }
    }
    doPSA();

    for(int x = 1; x <= n; x++) {
        for(int y = 1; y <= n; y++) {
            mp.clear();
            minmin(x, y);
            plusplus(x+1, y+1);

            mp.clear();
            minplus(x, y);
            plusmin(x+1, y-1);
        }
    }

    cout << cnt << "\n";
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}