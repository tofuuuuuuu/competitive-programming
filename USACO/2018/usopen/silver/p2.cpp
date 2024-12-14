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

void sol() { 
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1, greater<int>());

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] >= cnt) {
            cnt++;
        }
    }

    cout << cnt << "\n";
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}