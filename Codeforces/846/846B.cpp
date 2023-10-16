#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>
 
ll gcd(ll a, ll b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}
 
ll fun() {
    int n; cin >> n;
    ll a[n+1];
    ll psa[n+1];
    a[0] = 0; psa[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i]; psa[i] = psa[i-1] + a[i];
    }
 
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        ll s1 = psa[i];
        ll s2 = psa[n] - psa[i];
        ans = max(ans, gcd(s1, s2));
    }
    return ans;
}
 
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        cout << fun() << "\n";
    }
 
    return 0;
}