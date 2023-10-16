#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
int a[MAXN];
int segMin[4*MAXN];
int segMax[4*MAXN];
int segGCD[4*MAXN];

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

void pushup(int cur) {
    segMin[cur] = min(segMin[2*cur+1], segMin[2*cur+2]);
    segMax[cur] = max(segMax[2*cur+1], segMax[2*cur+2]);
    segGCD[cur] = gcd(segGCD[2*cur+1], segGCD[2*cur+2]);
}

void construct(int cur, int l, int r) {
    if(l == r) {
        segMin[cur] = a[l];
        segMax[cur] = a[l];
        segGCD[cur] = a[l];
        return;
    }

    int m = (l+r)/2;
    construct(cur*2 + 1, l, m);
    construct(cur*2 + 2, m+1, r);
    pushup(cur);
} 

void update(int cur, int l, int r, int idx, int val) {
    if(l == r) {
        segMin[cur] = val;
        segMax[cur] = val;
        segGCD[cur] = val;
        return;
    }
    
    int m = (l+r)/2;
    if(idx <= m) update(2*cur+1, l, m, idx, val);
    else update(2*cur+2, m+1, r, idx, val);
    pushup(cur);
}

int queryMin(int cur, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return segMin[cur];
    if(r < ql || qr < l) return INT_MAX;

    int m = (l+r)/2;
    return min(queryMin(2*cur+1, l, m, ql, qr), queryMin(2*cur+2, m+1, r, ql, qr));
}

int queryGCD(int cur, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return segGCD[cur];
    if(r < ql || qr < l) return 0;

    int m = (l+r)/2;
    return gcd(queryGCD(2*cur+1, l, m, ql, qr), queryGCD(2*cur+2, m+1, r, ql, qr));
}

int queryQ(int cur, int l, int r, int ql, int qr, int g) {
    if(ql <= l && r <= qr) {
        if(segMin[cur] > g) return 0;
        if(segMax[cur] == g) return r - l + 1;
        
        int m = (l+r)/2;
        return queryQ(2*cur+1, l, m, ql, qr, g) + queryQ(2*cur+2, m+1, r, ql, qr, g);
    }
    if(r < ql || qr < l) return 0;

    int m = (l+r)/2;
    return queryQ(2*cur+1, l, m, ql, qr, g) + queryQ(2*cur+2, m+1, r, ql, qr, g);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, idx, val, ql, qr; cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    construct(1, 1, n);

    for(int i = 1; i <= m; i++) {
        char qType; cin >> qType;
        if(qType == 'C') {
            cin >> idx >> val;
            update(1, 1, n, idx, val);
        }
        else if(qType == 'M') {
            cin >> ql >> qr;
            cout << queryMin(1, 1, n, ql, qr) << "\n";
        }
        else if(qType == 'G') {
            cin >> ql >> qr;
            cout << queryGCD(1, 1, n, ql, qr) << "\n";
        }
        else {
            cin >> ql >> qr;
            int g = queryGCD(1, 1, n, ql, qr);
            cout << queryQ(1, 1, n, ql, qr, g) << "\n";
        }
    }
    return 0;
}