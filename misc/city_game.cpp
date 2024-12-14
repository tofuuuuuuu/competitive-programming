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
int n, m;
int a[MAXN];

int fun() {
    int ans = 0;
    stack<int> st;
    for(int i = 1; i <= m; i++) {
        while(!st.empty()) {
            if(a[st.top()] > a[i]) {
                ans = max(ans, a[st.top()] * (i - st.top()));
                st.pop();
            }
            else break;
        }
        st.push(i);
    } 
    while(!st.empty()) {
        ans = max(ans, a[st.top()] * (m - st.top() + 1));
        st.pop();
    }

    return ans;
}

void sol() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        a[i] = 0;
    }

    int ans = 0;
    char c;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> c;
            if(c == 'R') a[j] = 0;
            else a[j]++;
        }

        ans = max(ans, fun());
    }

    cout << 3 * ans << "\n";
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for(int i = 1; i <= t; i++) {
        sol();
    }
    
    return 0;
}