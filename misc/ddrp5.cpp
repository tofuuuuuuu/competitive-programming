#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int> 

const int BFN = 2000000000;

pii lowFun(int low1, int low2, int val) {
    if(val < low1) {
        low2 = low1;
        low1 = val;
    }
    else if(val < low2) {
        low2 = val;
    }
    return {low1, low2};
}

pii highFun(int high1, int high2, int val) {
    if(val > high1) {
        high2 = high1;
        high1 = val;
    }
    else if(val > high2) {
        high2 = val;
    }
    return {high1, high2};
}

pii lowPairs(pii p1, pii p2) {
    pii res = p1; 
    res = lowFun(res.first, res.second, p2.first); 
    res = lowFun(res.first, res.second, p2.second);
    return res; 
}

pii highPairs(pii p1, pii p2) {
    pii res = p1; 
    res = highFun(res.first, res.second, p2.first); 
    res = highFun(res.first, res.second, p2.second);
    return res; 
}

const int MAXN = 1000005;
pii segLow[4*MAXN];
pii segHigh[4*MAXN];
pii arrLow[MAXN];
pii arrHigh[MAXN];

void pushup(int cur) {
    segLow[cur] = lowPairs(segLow[2*cur], segLow[2*cur+1]);
    segHigh[cur] = highPairs(segHigh[2*cur], segHigh[2*cur+1]);
}

void construct(int cur, int l, int r) {
    if(l == r) {
        segLow[cur] = arrLow[l];
        segHigh[cur] = arrHigh[l];
        return;
    }

    int m = (l+r)/2;
    construct(cur*2, l, m);
    construct(cur*2 + 1, m+1, r);
    pushup(cur);
} 

void update(int cur, int l, int r, int idx, pii lowVal, pii highVal) {
    if(l == r) {
        segLow[cur] = lowVal;
        segHigh[cur] = highVal;
        return;
    }
    
    int m = (l+r)/2;
    if(idx <= m) update(2*cur, l, m, idx, lowVal, highVal);
    else update(2*cur+1, m+1, r, idx, lowVal, highVal);
    pushup(cur);
}

pii queryLow(int cur, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return segLow[cur];
    if(r < ql || qr < l) return {BFN, BFN};

    int m = (l+r)/2;
    return lowPairs(queryLow(2*cur, l, m, ql, qr), queryLow(2*cur+1, m+1, r, ql, qr));
}

pii queryHigh(int cur, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return segHigh[cur];
    if(r < ql || qr < l) return {-1, -1};

    int m = (l+r)/2;
    return highPairs(queryHigh(2*cur, l, m, ql, qr), queryHigh(2*cur+1, m+1, r, ql, qr));
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    int sqrt = 2; while(sqrt * sqrt < n) sqrt++;
    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        arrLow[i] = {a[i], BFN}; arrHigh[i] = {a[i], -1};
    }
    construct(1, 1, n);

    int t, idx, v, l, r; 
    int lastAns = 0;
    for(int qi = 1; qi <= q; qi++) {
        cin >> t;
        if(t == 1) {
            cin >> idx >> v; idx ^= lastAns; v ^= lastAns;
            int prevVal = a[idx]; a[idx] = v;

            update(1, 1, n, idx, {v, BFN}, {v, -1});
        }
        else if(t == 2) {
            cin >> l >> r; l ^= lastAns; r ^= lastAns;
            l = sqrt*(l-1) + 1; r = sqrt*r;

            pii res = queryLow(1, 1, n, l, r);
            lastAns = res.first + res.second;
            cout << lastAns << "\n";
        }
        else {
            cin >> l >> r; l ^= lastAns; r ^= lastAns;
            l = sqrt*(l-1) + 1; r = sqrt*r;

            pii res = queryHigh(1, 1, n, l, r);
            lastAns = res.first + res.second;
            cout << lastAns << "\n";
        }
    }
    
    return 0;
}