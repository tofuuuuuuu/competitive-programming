#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a;
    vector<int> b;
    for(int i = 0; i < n; i++) {
        int v; cin >> v;
        a.push_back(v); b.push_back(v);
    }
    sort(b.begin(), b.end());
    map<int, int> m;
    for(int i = 0; i < n; i++) {
        m[b[i]] = i/k;
    }
    for(int i = 0; i < n; i++) {
        a[i] = m[a[i]];
    }

    int lis[n];
    memset(lis, 0, sizeof(lis));
    for(int i = 0; i < n; i++) {
        lis[i] = 1;
        for(int j = i-1; j >= 0; j--) {
            if(a[i] >= a[j]) lis[i] = max(lis[i], lis[j] + 1);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, lis[i]);
    }

    cout << n - ans << "\n";

    return 0;
}