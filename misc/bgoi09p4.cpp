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

const int MAXN = 1000005;
const ll MOD = 1000000007;
//const ll BFN = (ll)1e17;
const int BFN = (int)2e9;
int n, m, q, a, b, v, w, l, r, st, cnt;
int h[MAXN];
int s[MAXN];
int ans[MAXN];

void sol() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    deque<int> dq;
    for(int i = n; i >= 1; i--) {
        while(!dq.empty()) {
            if(h[dq.front()] <= h[i]) dq.pop_front();
            else break;
        }

        if(dq.size() < s[i]) {
            ans[i] = -1;
            dq.push_front(i);
        }
        else {
            dq.push_front(i);
            ans[i] = h[dq.at(s[i])];
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << " ";
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}