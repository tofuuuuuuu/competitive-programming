#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 200005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, m, q, k, x, y, qType;
pii a[MAXN];

void sol() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second; 
    }
    sort(a+1, a+n+1);

    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;
    int cnt = 0;
    int cur = n;
    while(cur >= 1) {
        bool good = false;
        while(cur >= 1 && a[cur].first - cnt <= cur) {
            pq.push(a[cur].second);

            if(a[cur].first - cnt == cur) {
                good = true;
                cur--;
                break;
            }
            cur--;
        }
        
        if(good) ans += pq.top(); pq.pop();
        cnt++;
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