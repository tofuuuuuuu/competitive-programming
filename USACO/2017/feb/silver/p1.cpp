#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 20005;
int c, n;
int t[MAXN];
pii a[MAXN];

int main(){
    //freopen("helpcross.in", "r", stdin);
	//freopen("helpcross.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> c >> n;
    for(int i = 0; i < c; i++) {
        cin >> t[i];
    }
    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        a[i] = {l, r};
    }
    sort(t, t+c);
    sort(a, a+n);

    int ans = 0;
    int cIdx = 0;
    priority_queue<int> q;
    for(int i = 0; i < c; i++) {
        while(cIdx < n && a[cIdx].first <= t[i]) {
            q.push(-a[cIdx].second);
            cIdx++;
        }

        while(!q.empty()) {
            int r = -q.top();
            if(r < t[i]) q.pop();
            else break;
        }

        if(!q.empty()) {
            ans++;
            q.pop();
        }
    }

    cout << ans << "\n";
    
    return 0;
}