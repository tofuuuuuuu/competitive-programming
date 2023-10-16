#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

const int MAXN = 200005;
const ll BFN = (ll)1e20;
pii a[MAXN];
int n;
ll t, s;
vector<long long> v; 

int main(){
    freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first >> s;
        a[i].second = -(a[i].first + s*t);
    }
    sort(a+1, a+n+1);
    
    v.push_back(a[1].second);
    for(int i = 2; i <= n; i++) {
        if(*v.rbegin() <= a[i].second) {
            v.push_back(a[i].second);
            continue;
        }

        int idx = upper_bound(v.begin(), v.end(), a[i].second) - v.begin();
        v[idx] = a[i].second;
    }

    cout << v.size() << "\n";

    return 0;
}