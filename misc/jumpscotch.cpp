#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 1000005;
int seg[4*MAXN];

void pushup(int cur) {
    seg[cur] = min(seg[2*cur+1], seg[2*cur+2]);
}

void update(int cur, int l, int r, int idx, int val) {
    if(l == r) {
        seg[cur] = val;
        return;
    }
    
    int m = (l+r)/2;
    if(idx <= m) update(2*cur+1, l, m, idx, val);
    else update(2*cur+2, m+1, r, idx, val);
    pushup(cur);
}

int query(int cur, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return seg[cur];
    if(r < ql || qr < l) return INT_MAX;

    int m = (l+r)/2;
    return min(query(2*cur+1, l, m, ql, qr), query(2*cur+2, m+1, r, ql, qr));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i < 4*MAXN; i++) {
        seg[i] = INT_MAX/4;
    }
    int n, d;
    cin >> n >> d;
    int dp[n];
    cin >> dp[1];
    update(1, 1, n, 1, dp[1]);
    for(int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        dp[i] = query(1, 1, n, max(1, i-d), i-1) + a;
        update(1, 1, n, i, dp[i]);
    }
    cout << dp[n] << "\n";

    return 0;
}