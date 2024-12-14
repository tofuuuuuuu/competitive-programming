#include <bits/stdc++.h>
using namespace std;
#define ll long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
Tree<pair<ll, ll>> tr;

// #define int long long
#define pii pair<int, int>
#define pll pair<ll ,ll>

// #define scanu(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
// char _;

const int MAXN = 3003;
const ll MOD = 1000000007;
const ll BFN = (ll)1e17;
//const int BFN = (int)2e9;
int n, minWage, adjust = 0, k, cnt = 0, v; 
char qType;
pll cur;
unordered_map<int, int> mp;

void sol() {
    cin >> n >> minWage;
    for(int i = 1; i <= n; i++) {
        cin >> qType >> k;
        if(qType == 'I') {
            if(k >= minWage) {
                v = k - adjust;
                tr.insert({v, mp[v]++});
            }
        }
        else if(qType == 'A') {
            adjust += k;
        }
        else if(qType == 'S') {
            adjust -=k;
            while(!tr.empty()) {
                cur = *tr.begin();
                if(cur.first + adjust >= minWage) break;
                
                tr.erase(cur);
                cnt++;
            }
        }
        else {
            if(tr.size() < k) {
                cout << "-1\n";
            }
            else cout << tr.find_by_order(tr.size() - k)->first + adjust << "\n";
        }
    }
    cout << cnt << "\n";
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}