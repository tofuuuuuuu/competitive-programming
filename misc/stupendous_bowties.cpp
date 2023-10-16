#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100000;
vector<int> xPoints[MAXN]; 
vector<int> yPoints[MAXN];
unordered_map<int, int> xMap;
unordered_map<int, int> yMap;

int bs(vector<int> &a, int x) {
    int l = 0; int r = a.size()-1;
    while(l <= r) {
        int m = (l+r)/2;
        if(a[m] == x) return m;
        else if(a[m] < x) l = m+1;
        else r = m-1;
    }
    return -1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int xi[n], yi[n];
    vector<int> xVals;
    vector<int> yVals;
    
    int xCnt = 1; int yCnt = 1;
    for(int i = 0; i < n; i++) {
        cin >> xi[i] >> yi[i];
        xVals.push_back(xi[i]);
        yVals.push_back(yi[i]);
    }
    sort(xVals.begin(), xVals.end());
    sort(yVals.begin(), yVals.end());

    int cnt = 0;
    for(int k : xVals) {
        if(xMap.find(k) == xMap.end()) {
            xMap[k] = cnt;
            cnt++;
        }
    }
    cnt = 0;
    for(int k : yVals) {
        if(yMap.find(k) == yMap.end()) {
            yMap[k] = cnt;
            cnt++;
        }
    }
    
    for(int i = 0; i < n; i++) {
        xi[i] = xMap[xi[i]];  yi[i] = yMap[yi[i]]; 
        xPoints[xi[i]].push_back(yi[i]); yPoints[yi[i]].push_back(xi[i]); 
    }
    for(int i = 0; i < MAXN; i++) {
        sort(xPoints[i].begin(), xPoints[i].end());
        sort(yPoints[i].begin(), yPoints[i].end());
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int cX = xi[i]; int cY = yi[i];
        ll y1 = bs(xPoints[cX], cY);
        ll x1 = bs(yPoints[cY], cX);
        ll y2 = xPoints[cX].size() - y1 - 1;
        ll x2 = yPoints[cY].size() - x1 - 1;

        ans += (y1*x1)*(x2*y2);
        ans += (y1*x2)*(y2*x1);
    }

    cout << ans << "\n";

    return 0;
}