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

const int MAXN = 5005;
const ll MOD = 1000000007;
const ll BFN = (ll)1e17;
//const int BFN = (int)2e9;
int n, k, res;
int ret[MAXN];
int dp[MAXN][MAXN];
vector<pii> idxMp; //{index, value}

void query(int l, int r) {
    if(l == r) {
        res = 1;
        return;
    }
    if(dp[l][r] != 0) {
        res = dp[l][r];
        return;
    }
    cout << "? " << l << " " << r << endl; 
    cin >> res;
    dp[l][r] = res;
}

void find(int idx) {
    if(idx == 1) {
        ret[idx] = 1;
        idxMp.push_back({idx, ret[idx]});
        return;
    }

    query(1, idx); 
    if(res != idxMp.size()) { //not in 
        ret[idx] = idxMp.size() + 1;
        idxMp.push_back({idx, ret[idx]});
        return;
    }

    int l = 0, r = idxMp.size()-1, m, ans = -1;
    while(l <= r) {
        m = (l+r)/2;
        query(idxMp[m].first, idx);
        if(res == idxMp.size() - m) { //idx is in here
            l = m+1;
            ans = m;
        }
        else {
            r = m-1;
        }
    }
    
    ret[idx] = idxMp[ans].second;
    int removeIdx = 0;
    for(int i = 0; i < idxMp.size(); i++) {
        if(idxMp[i].second == ret[idx]) {
            removeIdx = i;
            break;
        }
    }
    idxMp.erase(idxMp.begin() + removeIdx);
    idxMp.push_back({idx, ret[idx]});
}

void sol() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        find(i);
    }

    cout << "!";
    for(int i = 1; i <= n; i++) {
        cout << " " << ret[i];
    }
    cout << endl;
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}