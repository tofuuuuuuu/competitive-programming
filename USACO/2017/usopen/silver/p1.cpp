#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
int n;
pii a[MAXN];

int main(){
    //freopen("filename.in", "r", stdin);
	//freopen("filename.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[i] = {y, x};
    }
    sort(a, a+n);

    int ans = 0;
    int l = 0; int r = n-1;
    while(l <= r) {
        ans = max(ans, a[l].first + a[r].first);

        if(a[l].second == a[r].second) {
            a[l].second = 0; l++; 
            a[r].second = 0; r--;
        }
        else if(a[l].second < a[r].second) {
            a[r].second -= a[l].second;
            l++;
        }
        else {
            a[l].second -= a[r].second;
            r--;
        }
    }

    if(a[l].second != 0) {
        ans = max(ans, 2*a[l].first);
    }
    if(a[r].second != 0) {
        ans = max(ans, 2*a[l].first);
    }

    cout << ans << "\n";
    
    return 0;
}