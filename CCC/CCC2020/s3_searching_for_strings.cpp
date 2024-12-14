#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

const ll MOD = 1000000007;

bool check(int *freq, int *targetFreq) {
    for(int i = 0; i < 26; i++) {
        if(freq[i] != targetFreq[i]) return false;
    }
    return true;
}

ll getHash(ll *hash, ll *pow, int l , int r) {
    if(l == 0) return hash[r];
    ll a = (hash[r] - (hash[l-1] * pow[r - l + 1]) % MOD) % MOD;
    if(a < 0) a += MOD;
    return a;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string n, h; cin >> n >> h;
    int nL = n.length(); int hL = h.length();
    if (nL > hL) {
        cout << "0\n"; 
        return 0;
    }

    ll hash1[hL];
    ll pow1[hL];
    ll base1 = 137;
    pow1[0] = 1; hash1[0] = (ll)(h[0] - 'a');
    for(int i = 1; i < hL; i++) {
        hash1[i] = ((hash1[i-1] * base1) % MOD + (ll)(h[i] - 'a')) % MOD;
        pow1[i] = (pow1[i-1] * base1) % MOD;
    }
    ll hash2[hL];
    ll pow2[hL];
    ll base2 = 131;
    pow2[0] = 1; hash2[0] = (ll)(h[0] - 'a');
    for(int i = 1; i < hL; i++) {
        hash2[i] = ((hash2[i-1]*base2) % MOD + (ll)(h[i] - 'a')) % MOD;
        pow2[i] = (pow2[i-1] * base2) % MOD;
    }

    set<pll> s;

    int targetFreq[26];
    int freq[26]; 
    memset(freq, 0, sizeof(freq));
    memset(targetFreq, 0, sizeof(targetFreq));
    for(int i = 0; i < nL; i++) {
        freq[h[i] - 'a']++;
        targetFreq[n[i] - 'a']++;
    }

    if(check(freq, targetFreq)) {
        ll hashVal1 = getHash(hash1, pow1, 0, nL - 1);
        ll hashVal2 = getHash(hash2, pow2, 0, nL - 1);

        pll p; p.first = hashVal1; p.second = hashVal2;
        s.emplace(p);
    }
    for(int i = 1; i + nL - 1 < hL; i++) {
        freq[h[i-1] - 'a']--;
        freq[h[i + nL - 1] - 'a']++;

        if(check(freq, targetFreq)) {
            ll hashVal1 = getHash(hash1, pow1, i, i + nL - 1);
            ll hashVal2 = getHash(hash2, pow2, i, i + nL - 1);

            pll p; p.first = hashVal1; p.second = hashVal2;
            s.emplace(p);
        }
    }

    cout << s.size() << "\n"; 

    return 0;
}