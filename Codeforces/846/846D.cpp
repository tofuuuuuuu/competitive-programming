#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

int fun() {
    int cnt, newCnt; cin >> cnt;
    int totalCnt = cnt;
    
    int ans = 0;
    int cur = 0;
    for(int i = 0; i < totalCnt; i++) {
        cout << "- " << (1 << cur) << "\n";
        cout.flush();
        cin >> newCnt;

        int dif = newCnt - cnt;
        int next1 = dif + 1;
        cur += next1;
        ans += (1 << cur);

        cnt = newCnt;
        cur++;
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        int ans = fun();
        cout << "! " << ans << "\n";
        cout.flush();
    }

    return 0;
}