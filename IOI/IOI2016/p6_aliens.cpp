#include <bits/stdc++.h>
using namespace std;
#define ll long long

//#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 100005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, k;
ll x[MAXN];
ll y[MAXN];
pll tmp[MAXN];

ll q[MAXN];
ll dp[MAXN];
ll sq[MAXN];

long double m(int a, int b) {
    return (dp[a] + (y[a+1] - 1) * (y[a+1] - 1) - dp[b] - (y[b+1] - 1) * (y[b+1] - 1)) / ((long double)y[a+1] - y[b+1]);
} 

ll fun(ll t) {
    int l = 1, r = 1; q[1] = 0;
    for(int i = 1; i <= n; i++)
    {
        while(r - l + 1 >= 2) {
            if((long double)2 * x[i] > m(q[l], q[l + 1])) l++;
            else break;
        }

        dp[i] = dp[q[l]] + (x[i] - y[q[l] + 1] + 1) * (x[i] - y[q[l] + 1] + 1) + t;
        sq[i] = sq[q[l]] + 1;
        if(i == n) break;
        dp[i] -= max(0LL, (x[i] - y[i + 1] + 1)) * max(0LL, (x[i] - y[i + 1] + 1));
        
        while(r - l + 1 >= 2) {
            if(m(q[r], q[r - 1]) > m(q[r], i)) r--;
            else break;
        }

        r++;
        q[r] = i; 
    }
    return sq[n];
}

ll take_photos(int nC, int m, int kC, int rC[], int cC[]) {
    n = nC, k = kC;
    for(int i = 0; i < n; i++) {
        if(rC[i] > cC[i]) swap(rC[i], cC[i]);
        tmp[i] = {rC[i], cC[i]};
    }
    sort(tmp, tmp+n);

    stack<pii> st;
    st.push({tmp[0].first, tmp[0].second});
    for(int i = 1; i < n; i++) {
        while(!st.empty()) {
            if(tmp[i].first <= st.top().first && tmp[i].second >= st.top().second) st.pop();
            else break;
        }

        if(!st.empty() && tmp[i].first >= st.top().first && tmp[i].second <= st.top().second) continue;
        st.push({tmp[i].first, tmp[i].second});
    }

    n = st.size();

    for(int i = n; i >= 1; i--) {
        y[i] = st.top().first;
        x[i] = st.top().second;
        st.pop();
    }

    ll l = 0, r = 1e13, ans = 0;
    while(l <= r)
    {
        ll m = (l+r)/2;

        if(fun(m) <= k) {
            r = m - 1;
            ans = dp[n];
        }
        else {
            l = m + 1;
        }
    }

    return ans - (r + 1) * k;
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    // int a[] = {0, 1};
    // int b[] = {0, 1};
    // cout << take_photos(2, 2, 1, a, b) << "\n";

    return 0;
}