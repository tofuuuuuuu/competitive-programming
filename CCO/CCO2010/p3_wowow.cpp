#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll ,ll>

const int MAXN = 1000005;
const ll MOD = 1000000007;
//const ll BFN = (ll)1e17;
const ll BFN = (int)2e9;
int n, x, r, k; char t;
int val[MAXN];

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using Tree = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>; 
Tree<pii> tr;

void sol() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> t;
        if(t == 'N') {
            cin >> x >> r;
            val[x] = r;
            tr.insert({r, x});
        }
        else if(t == 'M'){
            cin >> x >> r;
            tr.erase({val[x], x});
            val[x] = r;
            tr.insert({r, x});
        }
        else {
            cin >> k;
            pii res = *tr.find_by_order(k-1);
            cout << res.second << "\n";
        }
    }
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}