#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define int long long
#define pii pair<int, int>
#define pll pair<ll ,ll>

// #define scanu(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
// char _;

const int MAXN = 100005;
const ll MOD = 1000000007;
//const ll BFN = (ll)1e17;
const int BFN = (int)2e9;
int n, m, q, a, b, v, w, l, r;
priority_queue<ll, vector<ll>, greater<ll>> pq;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T>
// using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// Tree<int> tr;

void sol() {
    cin >> n;
    ll cnt1 = 0, low = 0, high = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        if(a == 1) cnt1++;
        else {
            pq.push(a);
            low = (low + a) % MOD;
        }
    }

    if(pq.size() == 0) {
        low = 1;
    }
    
    while(cnt1 > 0 && !pq.empty()) {
        if(pq.top() != 2) break;
        pq.pop();
        pq.push(3);
        cnt1--;
    }

    while(cnt1 >= 3) {
        pq.push(3);
        cnt1 -= 3;
    }

    if(cnt1 == 2) {
        pq.push(2);
    }
    else if(cnt1 == 1 && !pq.empty()) {
        pq.push(pq.top() + 1);
        pq.pop();
    }

    while(!pq.empty()) {
        high = (high * pq.top()) % MOD;
        pq.pop();
    }

    cout << low << "\n";
    cout << high << "\n";
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}