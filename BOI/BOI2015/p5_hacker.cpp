#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    ll v[2*n];
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = n; i < 2*n; i++) {
        v[i] = v[i - n];
    }

    int len = (n+1)/2;
    ll ans;
    
    map<ll, ll> mp;
    queue<ll> q;

    ll s = 0;
    for(int i = 0; i < len; i++) {
        s += v[i];
    }
    mp.insert(pair<ll, int>(s, 1));
    q.push(s);
    for(int f = 0, cnt = 0; f < len - 1; f++, cnt++) {
        s = s - v[f] + v[len + cnt];
        if(mp.find(s) == mp.end()) {
            mp[s] = 1;
        }
        else {
            mp[s] = mp[s] + 1;
        }
        q.push(s);
    }
    ans = mp.begin()->first;

    for(int i = len; i + len - 1 < 2*n; i++) {
        ll rem = q.front(); q.pop();
        mp[rem] = mp[rem] - 1;
        if(mp[rem] == 0) {
            mp.erase(rem);
        }

        s = s - v[i-1] + v[i + len - 1];
        if(mp.find(s) == mp.end()) {
            mp[s] = 1;
        }
        else {
            mp[s] = mp[s] + 1;
        }
        q.push(s);

        ans = max(ans, mp.begin()->first);
    }

    cout << ans << "\n";
    
    return 0;
}