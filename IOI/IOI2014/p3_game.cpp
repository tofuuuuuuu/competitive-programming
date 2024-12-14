#include <bits/stdc++.h>
using namespace std;
#define ll long long

// #define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 1505;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, x, y;
int qAmt[MAXN][MAXN];

int p[MAXN];
int sz[MAXN];

int find(int v) {
    if(p[v] != v) p[v] = find(p[v]);
    return p[v];
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;
    
    if(sz[a] < sz[b]) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
    return true;
}

void initialize(int N) {
    n = N;
    for(int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
}

int hasEdge(int u, int v) {
    int a = find(u);
    int b = find(v);

    if(a == b) return 0;

    qAmt[a][b]++;
    qAmt[b][a]++;
    if(sz[a] * sz[b] == qAmt[a][b]) {
        merge(a, b);
        int newRep = find(a);
        for(int i = 1; i <= n; i++) {
            if(find(i) == newRep) continue;
            qAmt[newRep][i] = qAmt[i][a] + qAmt[i][b];
            qAmt[i][newRep] = qAmt[newRep][i];
        }

        return 1;
    }

    return 0;
}

void sol() {
    
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    sol();

    return 0;
}