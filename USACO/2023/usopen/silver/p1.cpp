#include <bits/stdc++.h>
using namespace std;
#define ll long long

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T>
// using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// Tree<ll> tr;

#define int long long
#define pii pair<int, int>
#define pll pair<ll ,ll>

// #define scanu(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
// char _;

const int MAXN = 150005;
const ll MOD = 1000000007;
const ll BFN = (ll)1e17;
//const int BFN = (int)2e9;
int t, n, q, idx, newVal;
ll a[MAXN];
ll sorted[MAXN];
ll psa[MAXN];
ll psaSimple[MAXN];
unordered_map<ll, ll> valMp;

void sol() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i]; valMp[i] = a[i];
    }
    sort(a+1, a+n+1);

    for(ll i = 1; i <= n; i++) {
        psa[i] = psa[i-1] + a[i] * i;
        psaSimple[i] = psaSimple[i-1] + a[i];
    }
    
    cin >> q;
    ll ans;
    while(q--) {
        cin >> idx >> newVal;
        ll curVal = valMp[idx];
        idx = lower_bound(a+1, a+n+1, curVal) - (a);
        int idx2 = lower_bound(a+1, a+n+1, newVal) - (a);

        if(curVal <= newVal) {
            ans = psa[idx-1] + (psa[n] -psa[idx2-1]) + (psa[idx2-1] - psa[idx]) - (psaSimple[idx2-1] - psaSimple[idx]) + newVal * (idx2-1);
        }
        else {
            ans = psa[idx2-1] + (psa[n] - psa[idx]) + (psa[idx-1] - psa[idx2-1]) + (psaSimple[idx-1] - psaSimple[idx2-1]) + newVal * (idx2);
        }
        cout << ans << "\n";
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