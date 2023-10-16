#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 1000005;
const ll MOD = 1000000007;
//const ll BFN = (ll)1e17;
const int BFN = (int)1e9;
int n;
int a[MAXN];
int sorted[MAXN];
map<int, int> mp; 

void sol() { 
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sorted[i] = a[i];
    }
    sort(sorted+1, sorted+n+1);
    for(int i = 1; i <= n; i++) {
        if(mp.find(sorted[i]) == mp.end()) {
            mp[sorted[i]] = i;
        }
    }

    int tmp;
    for(int i = 1; i <= n; i++) {
        tmp = a[i];
        a[i] = mp[tmp];
        mp[tmp]++;
    }

    int mx = 0;
    for(int i = 1; i <= n; i++) {
        mx = max(mx, i - a[i]);
    }

    cout << mx + 1 << "\n";
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}