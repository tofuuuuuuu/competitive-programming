#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 255;
const ll MOD = 1000000007;
//const ll BFN = (ll)1e17;
const int BFN = (int)1e9;
int n, x, y;
int a[MAXN][MAXN];
pii dir[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int vis1[MAXN][MAXN];
int vis2[MAXN][MAXN];
int vis3[MAXN][MAXN];
vector<pii> v;

void clearv3() {
    for(pii p: v) {
        vis3[p.first][p.second] = false;
    }
    v.clear();
}

int bfs1(int i, int j) {
    int c = a[i][j];
    int cnt = 1;
    queue<pii> q;
    vis1[i][j] = true;
    q.push({i, j});
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        for(pii d : dir) {
            x = cur.first + d.first;
            y = cur.second + d.second;

            if(x < 1 || x > n || y < 1 || y > n) continue;
            if(vis1[x][y]) continue;
            if(a[x][y] != c) continue;
            vis1[x][y] = true;
            q.push({x, y});  
            cnt++;
        }
    }
    return cnt;
}

int bfs22(int i, int j, int c1, int c2) {
    int cnt = 1;
    queue<pii> q;
    v.push_back({i, j});
    vis3[i][j] = true;
    q.push({i, j});
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        for(pii d : dir) {
            x = cur.first + d.first;
            y = cur.second + d.second;

            if(x < 1 || x > n || y < 1 || y > n) continue;
            if(vis3[x][y]) continue;
            if(a[x][y] != c1 && a[x][y] != c2) continue;
            vis3[x][y] = true;
            v.push_back({x, y});
            q.push({x, y});  
            cnt++;
        }
    }

    return cnt;
}

int bfs2(int i, int j) {
    unordered_set<int> adj;
    int c = a[i][j];
    queue<pii> q;
    vis2[i][j] = true;
    q.push({i, j});
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        for(pii d : dir) {
            x = cur.first + d.first;
            y = cur.second + d.second;

            if(x < 1 || x > n || y < 1 || y > n) continue;
            if(vis2[x][y]) continue;
            if(a[x][y] != c) {
                adj.insert(a[x][y]);
                continue;
            }
            vis2[x][y] = true;
            q.push({x, y});  
        }
    }

    int mx = 0;
    for(int c2 : adj) {
        clearv3();
        mx = max(mx, bfs22(i, j, c, c2));
    }
    return mx;
}

void sol() { 
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int mx1 = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!vis1[i][j]) {
                mx1 = max(mx1, bfs1(i, j));
            }
        }
    }

    int mx2 = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!vis2[i][j]) {
                mx2 = max(mx2, bfs2(i, j));

                if(mx2 >= n*n/2) {
                    cout << mx1 << "\n" << mx2 << "\n";
                    return;
                }
            }
        }
    }

    cout << mx1 << "\n" << mx2 << "\n";
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}