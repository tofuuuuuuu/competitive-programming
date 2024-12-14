#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll ,ll>

const int MAXN = 55;
const ll MOD = 1000000007;
//const ll BFN = (ll)1e17;
const int BFN = (int)2e9;
int n, x;
int a[MAXN];

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
Tree<int> tr;
unordered_map<int, int> mp;

void sol() {
    cin >> n;
    ll ans = 0, l, r;
    cin >> x; tr.insert(x); mp[x] = 0; mp[0] = -BFN;
    cout << "0\n";
    for(int i = 2; i <= n; i++) {
        cin >> x;
        int a = tr.order_of_key(x);
        l = *tr.find_by_order(a-1);
        r = *tr.find_by_order(a);
        if(a-1 < 0) l = 0; 
        if(a >= i-1) r = 0;

        mp[x] = max(mp[l], mp[r]) + 1;
        ans += mp[x];
        tr.insert(x);
        cout << ans << "\n";
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