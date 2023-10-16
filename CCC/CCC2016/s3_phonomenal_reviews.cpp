#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
vector<int> adj[MAXN];
int isPho[MAXN];
int removed[MAXN];
int dist[MAXN];
int maxNode; 

int dfs_remove(int v, int prev) {
    int cnt = 0;
    if(isPho[v]) cnt++;
    for(int i : adj[v]) {
        if(i == prev) continue;
        cnt += dfs_remove(i, v);
    }

    if(cnt == 0) removed[v] = 1;
    return cnt;
}

void dfs(int v, int prev) {
    for(int i : adj[v]) {
        if(removed[i]) continue;
        if(i == prev) continue;
        dist[i] = dist[v] + 1;
        if(dist[i] > dist[maxNode]) {
            maxNode = i;
        } 
        dfs(i, v);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, firstPho;
    cin >> n >> m;
    for(int i = 0; i < m; i++)  {
        int a;
        cin >> a;
        isPho[a] = 1;
        firstPho = a;
    }
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(removed, 0, sizeof(removed));
    dfs_remove(firstPho, firstPho);
    

    memset(dist, 0, sizeof(dist));
    dfs(firstPho, firstPho);
    memset(dist, 0, sizeof(dist));
    dfs(maxNode, maxNode);

    int removedCnt = 0;
    for(int i = 0; i < n; i++) {
        if(removed[i]) removedCnt++;
    }
    int total = n-1 - removedCnt;

    cout << 2*total - dist[maxNode] << "\n";

    return 0;
}