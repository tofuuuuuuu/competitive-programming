#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

pii makePair(int a, int b) {
    pii p;
    p.first = a; p.second = b;
    return p;
}

int computeX(int y, int xi, int hi, int vi, int pos) {
    if(pos) {
        if(hi*y % vi == 0) return hi*y/vi + xi;
        else return ceil((double)hi*y/vi + xi);
    }
    else {
        if(hi*y % vi == 0) return -hi*y/vi + xi + 1;
        else return ceil((double) -hi*y/vi + xi);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, l, r, y;
    cin >> n >> l >> r >> y;

    pii events[2*n];
    for(int i = 0; i < n; i++) {
        int xi, vi, hi;
        cin >> xi >> vi >> hi; 

        events[2*i] = makePair(computeX(y, xi, hi, vi, 0), 1);
        events[2*i+1] = makePair(computeX(y, xi, hi, vi, 1), -1);
    }
    sort(events, events + 2*n);
    
    int ans[n+1];
    memset(ans, 0, sizeof(ans));
    int i = 0;
    int cnt = 0;
    while(events[i].first < l) {
        cnt += events[i].second;
        i++;
    }
    ans[cnt] += events[i].first - l;
    cnt += events[i].second; 
    i++;

    while(i < 2*n) {
        if(events[i].first > r) {
            break;
        }

        ans[cnt] += events[i].first - events[i-1].first;
        cnt += events[i].second;
        i++;
    }
    if(r >= events[i-1].first) {
        ans[cnt] += r - events[i-1].first + 1;
    }

    cout << ans[0] << "\n";
    for(int i = 1; i <= n; i++) {
        ans[i] += ans[i-1];
        cout << ans[i] << "\n";
    }

    return 0;
}