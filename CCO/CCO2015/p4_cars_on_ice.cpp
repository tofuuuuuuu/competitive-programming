#include <bits/stdc++.h>
using namespace std;
#define ll long long

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T>
// using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// Tree<ll> tr;

// #define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

// #define scanu(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
// char _;

const int MAXN = 2005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, m;
char a[MAXN][MAXN];
vector<pii> nxt[MAXN][MAXN];
int deg[MAXN][MAXN];

void findNxt(int x, int y) {
    if(a[x][y] == 'N') {
        for(int i = x-1; i >= 1; i--) {
            if(a[i][y] != '.') {
                nxt[i][y].push_back({x, y});
                deg[x][y]++;
                if(a[i][y] == 'N') return;
            }
        }
    }
    else if(a[x][y] == 'S') {
        for(int i = x+1; i <= n; i++) {
            if(a[i][y] != '.') {
                nxt[i][y].push_back({x, y});
                deg[x][y]++;
                if(a[i][y] == 'S') return;
            }
        }
    }
    else if(a[x][y] == 'W') {
        for(int i = y-1; i >= 1; i--) {
            if(a[x][i] != '.') {
                nxt[x][i].push_back({x, y});
                deg[x][y]++;
                if(a[x][i] == 'W') return;
            }
        }
    }
    else {
        for(int i = y+1; i <= m; i++) {
            if(a[x][i] != '.') {
                nxt[x][i].push_back({x, y});
                deg[x][y]++;
                if(a[x][i] == 'E') return;
            }
        }
    }
}

void sol() {   
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] == '.') continue;
            findNxt(i, j);
        }
    }

    queue<pii> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] == '.') continue;
            if(deg[i][j] == 0) q.push({i, j});
        }
    }

    pii cur;
    while(!q.empty()) {
        cur = q.front(); q.pop();
        cout << "(" << cur.first-1 << "," << cur.second-1 << ")\n";
        
        for(auto i : nxt[cur.first][cur.second]) {
            deg[i.first][i.second]--;

            if(deg[i.first][i.second] == 0) {
                q.push({i.first, i.second});
            }
        }
    }
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    sol();

    return 0;
}