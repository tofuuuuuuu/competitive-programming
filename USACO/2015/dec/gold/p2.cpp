#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

const int MAXN = 5000005;
//const ll BFN = (ll)1e20;
const int BFN = (int)1e9;
bool ans[MAXN][2];
int n, t, a, b, res = 0;

void dfs(int v, int dr) {
    if(v > t) return;
    if(ans[v][dr]) return;
    if(v > res) res = v;
    ans[v][dr] = true;

    dfs(v+a, dr);
    dfs(v+b, dr);
    if(dr == 0) {
        dfs(v/2, 1);
    } 
}

int main(){
    freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> a >> b;
    dfs(0, 0);
    cout << res << "\n";

    return 0;
}