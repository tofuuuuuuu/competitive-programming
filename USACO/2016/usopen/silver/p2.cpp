#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 50005;
int n, k;
int a[MAXN];
int forwards[MAXN];
int backwards[MAXN];

int main(){
    freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);

    forwards[n+1] = 0;
    backwards[0] = 0;

    for(int l = 1, r = 1; l <= n; l++) {
        while(r + 1 <= n && a[r + 1] - a[l] <= k) 
            r++;
        forwards[l] = r - l + 1; 
    }
    
    for(int l = 1, r = 1; r <= n; r++) {
        while(l <= r && a[r] - a[l] > k) 
            l++;
        backwards[r] = r - l + 1; 
    }

    for(int i = n-2; i >= 0; i--) {
        forwards[i] = max(forwards[i], forwards[i+1]);
    }
    for(int i = 1; i < n; i++) {
        backwards[i] = max(backwards[i], backwards[i-1]);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, max(backwards[i] + forwards[i+1], backwards[i-1] + forwards[i]));
    }

    cout << ans << "\n";
    
    return 0;
}