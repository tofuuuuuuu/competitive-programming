#include <bits/stdc++.h>
#include <stack>
#include <map>
using namespace std;
#define ll long long

const int MOD = 1000000007;

int modInv(int n) {
    int cnt = MOD - 2;
    ll cur = n;
    ll inv = 1;
    while(cnt > 0) {
        if(cnt % 2 == 1) {
            inv *= cur;
            inv %= MOD;
        }
        cur *= cur;
        cur %= MOD;
        cnt /= 2;
    }
    return inv;
}

int main ()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int k; 
    cin >> k;
    
    map<int, string> m1;
    map<string, int> m2;
    int orig[k];
    ll mult[k];
    vector<string> names;
    stack<int> s;
    memset(orig, 0, sizeof(orig));
    for(int i = 0; i < k; i++) {
        mult[i] = 1;
    }

    for(int i = 0; i < k; i++) {
        string str;
        cin >> str;
        if(str == "(") {
            s.push(i);
        }
        else if(str == ")") {
            ll m1;
            cin >> m1;

            int prev = s.top();
            s.pop();

            mult[prev] *= m1;
            mult[prev] %= MOD;
            mult[i] *= modInv(m1);
            mult[i] %= MOD;
        }
        else {
            ll n;
            cin >> n;
            orig[i] = n;
            m1[i] = str;
            names.push_back(str);
        }
    }
    sort(names.begin(), names.end());

    int cnt = 0;
    for(auto name : names) {
        m2[name] = cnt;
        cnt++;
    }
    ll ans[cnt+1];
    memset(ans, 0, sizeof(ans));
    
    if(m1.find(0) != m1.end()) {
        ans[m2[m1[0]]] += (ll)orig[0]*mult[0];
        ans[m2[m1[0]]] %= MOD;
    }
    for(int i = 1; i < k; i++) {
        mult[i] *= mult[i-1];
        mult[i] %= MOD;
        ans[m2[m1[i]]] += (ll)orig[i]*mult[i];
        ans[m2[m1[i]]] %= MOD;
    }

    string prevName = "";
    for(auto name : names) {
        if(name == prevName) continue;
        cout << name << " " << ans[m2[name]] << "\n";
        prevName = name;
    }
    return 0;
}