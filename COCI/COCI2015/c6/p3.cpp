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

const int MAXN = 1000005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n;
ll a[MAXN];
ll dif[MAXN];
map<int, int> cnt;

void sol() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 2; i <= n; i++) {
        if(a[i] > a[i-1]) {
            dif[i] = 1;
        }
        else if(a[i] < a[i-1]) {
            dif[i] = -1;
        }
        dif[i] = dif[i] + dif[i-1];
    }

    int gcancer = 0;
    int fst = a[1];
    for(int i = 1; i <= n; i++) {
        if(a[i] - fst == 0) {
            if(dif[i] == 0) gcancer++;
            else cnt[0]++;
        }
        else {
            if(dif[i] == 0) {
                continue;
            }
            if((a[i] - fst) % dif[i] == 0) {
                cnt[(a[i] - fst) / dif[i]]++;
            }
        }
    }

    int maxK = 0, maxVal = 0;
    for(auto i : cnt) {
        if(i.second > maxVal) {
            maxK = i.first;
            maxVal = i.second;
        }
    }

    cout << (maxVal + gcancer) << "\n" << maxK << "\n";
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    sol();

    return 0;
}