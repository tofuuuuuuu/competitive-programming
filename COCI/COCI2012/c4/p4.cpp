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
#define pll pair<ll, ll>

// #define scanu(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
// char _;

const int MAXN = 1000006;
const ll MOD = 1000000007;
// const ll BFN = (ll)1e16;
const int BFN = (int)1e8;
int n, k;
int a[MAXN];
int diff[MAXN];
deque<pii> dq;

void insert(int k) {
    int cnt = 1;
    while(!dq.empty() && k <= dq.back().first) {
        cnt += dq.back().second;
        dq.pop_back();
    }
    dq.push_back({k, cnt});
}

void sol() {
    cin >> n >> k; k = n - k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+1+n);

    for(int i = 1; i < n; i++) {
        diff[i] = a[i+1] - a[i];
    }

    int diffCnt = 1;
    while(diffCnt < k) {
        insert(diff[diffCnt]);
        diffCnt++;
    }
    int ans = a[k] - a[1] + dq.front().first;
    
    for(int i = 2; i < n; i++) {
        if(i + k -1 > n) break;

        insert(diff[diffCnt]);
        dq.front().second--;
        while(dq.front().second == 0) dq.pop_front();

        ans = min(ans, a[i+k-1] - a[i] + dq.front().first);
        diffCnt++;
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