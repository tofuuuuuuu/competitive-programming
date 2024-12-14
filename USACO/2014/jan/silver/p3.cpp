#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 155;
int n;
pii a[MAXN];

int main(){
    //freopen("recording.in", "r", stdin);
	//freopen("recording.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        a[i] = {r, l};
    }
    sort(a, a + n);

    int ans =  0;
    int end1 = 0;
    int end2 = 0;
    for(int i = 0; i < n; i++) {
        if(end2 < end1) swap(end1, end2);
        if(a[i].second >= end2) {
            ans++;
            end2 = a[i].first;
        }
        else if(a[i].second >= end1){
            ans++;
            end1 = a[i].first;
        }
    }

    cout << ans << "\n";
    
    return 0;
}