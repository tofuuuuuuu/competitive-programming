#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

const int MAXL = 200006;
const ll b1 = 131;
const ll mod1 = 1e9 + 7;
ll h1[MAXL];
ll p1[MAXL];
const ll b2 = 137;
const ll mod2 = 1e9 + 9;
ll h2[MAXL];
ll p2[MAXL];
int sLength;
unordered_set<ll> s1;
unordered_set<ll> s2;

int getHash1(int l, int r) {
    if(l == 0) return h1[r];
    ll a = (h1[r] - (h1[l-1] * p1[r - l + 1]) % mod1) % mod1;
    if(a < 0) a += mod1;
    return (int)a;
}

int getHash2(int l, int r) {
    if(l == 0) return h2[r];
    ll a = (h2[r] - (h2[l-1] * p2[r - l + 1]) % mod2) % mod2;
    if(a < 0) a += mod2;
    return (int)a;
}

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
gp_hash_table<ll, null_type, chash> table1;

bool check(int leng) {
    table1.clear(); 
    for(int i = 0; i + leng - 1 < sLength; i++) {
        int hashVal1 = getHash1(i, i + leng - 1);
        int hashVal2 = getHash2(i, i + leng - 1);
        ll h = ((ll)hashVal1 << 32) + hashVal2;
        if(table1.find(h) != table1.end()) return true;

        table1.insert(h); 
    }
    return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> sLength >> s;

    h1[0] = s[0]; p1[0] = 1;
    h2[0] = s[0]; p2[0] = 1;
    for(int i = 1; i < sLength; i++) {
        h1[i] = (((h1[i-1]) * b1) % mod1 + (s[i])) % mod1;
        p1[i] = (p1[i-1] * b1) % mod1;
        h2[i] = (((h2[i-1]) * b2) % mod2 + (s[i])) % mod2;
        p2[i] = (p2[i-1] * b2) % mod2;
    }

    int ans = 0;
    int l = 1; int r = sLength-1;
    while(l <= r) {
        int m = (l+r)/2;
        if(check(m)) {
            ans = m;
            l = m+1;
        }
        else {
            r = m-1;
        }
    }

    cout << ans << "\n";

    return 0;
}