#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

int n, m, c;

bool check(int maxDif, int *t) {
    int curLen = 0; int curBeg = 0; int segCnt = 0;
    for(int i = 0; i < n; i++) {
        if(curLen == 0) {
            segCnt++;
            curLen = 1;
            curBeg = i;
        }
        else if(t[i] - t[curBeg] <= maxDif) {
            curLen++;
            if(curLen == c) {
                curLen = 0;
            }
        }
        else {
            segCnt++;
            curLen = 1;
            curBeg = i;
        }
    }

    if(segCnt > m) return false;
    return true;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> c;
    int t[n];
    for(int i = 0; i < n; i++) cin >> t[i];
    sort(t, t + n);

    int l = 0; int r = 1000000001;
    int ans = -1;
    while(l <= r) {
        int m = (l + r)/2;
        if(check(m, t)) {
            ans = m;
            r = m-1;
        }
        else {
            l = m+1;
        }
    }

    cout << ans << "\n";
    
    return 0;
}