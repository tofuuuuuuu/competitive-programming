#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

const int MAXN = 500005;
ll maxW;
ll psaW[MAXN];
ll psaV[MAXN];

int bs(int curEnd) {
    int l = 0, r = curEnd, ans = -1;
    while(l <= r) {
        int m = (l+r)/2;
        if(psaW[curEnd] - psaW[m] <= maxW) {
            ans = m;
            r = m-1;
        }
        else {
            l = m+1;
        }
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n >> maxW;
    int curEnd = 1;
    stack<ll> ans;
    ans.push(0);
    
    for(int i = 1; i <= n; i++) {
        char t; cin >> t; 
        if(t == 'A') {
            ll w, v; cin >> w >> v;
            psaW[curEnd] = psaW[curEnd-1] + w;
            psaV[curEnd] = psaV[curEnd-1] + v;

            int pos = bs(curEnd);
            if(psaV[curEnd] - psaV[pos] > ans.top()) {
                ans.push(psaV[curEnd] - psaV[pos]);
            }
            else {
                ans.push(ans.top());
            }

            cout << ans.top() << "\n";
            curEnd++;
        }
        else {
            curEnd--;
            ans.pop();
        }
    }
    return 0;
}