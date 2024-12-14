#include <bits/stdc++.h>
using namespace std;

int main ()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long m, k;
    cin >> n >> m >> k;
    k -= n;
    int ans[n];

    int cnt = 0;
    if(k  >= (m)*(m-1)/2) {
        if(m > n) {
            cout << -1 << "\n";
            return 0;
        }

        for(int i = 1; i <= m; i++) {
            ans[cnt] = i;
            cnt++;
        }
        k -= (m)*(m-1)/2;
    }
    else {
        int cur = 1;
        while(k - cur + 1 >= 0 && cnt < n) {
            ans[cnt] = cur;
            k -= cur-1;
            cnt++;
            cur++;
        }
        while(k > 0 && cnt < n) {
            if(cur > k) cur = k;
            ans[cnt] = ans[cnt - cur - 1];
            k -= cur;
            cnt++;
        }
    }
    
    int cur = m-1;
    while(k > 0 && cnt < n) {
        if(cur > k) cur=k;
        ans[cnt] = ans[cnt - cur - 1];
        k -= cur;
        cnt++;
    }
    while(cnt < n) {
        ans[cnt] = ans[cnt-1];
        cnt++;
    }

    if(cnt == n && k != 0) cout << -1 << "\n";
    else {
        for(auto& i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}