#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

int n;
vector<int> a1;
vector<int> a2;

int main(){
    freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        a2.push_back(x);
    }
    sort(a2.begin(), a2.end());

    for(int j = 1; j < a2[0]; j++)
        a1.push_back(j);

    for(int i = 1; i < n; i++) 
        for(int j = a2[i-1] + 1; j < a2[i]; j++) 
            a1.push_back(j);

    for(int j = a2[n-1] + 1; j <= 2*n; j++) 
        a1.push_back(j);

    int ans = 0;
    for(int p1 = 0, p2 = 0; p1 < n && p2 < n; p2++) {
        while(p1 < n && a1[p1] < a2[p2]) 
            p1++;
        if(p1 < n) {
            ans++;
            p1++;
        }
    }

    cout << ans << "\n";
    
    return 0;
}