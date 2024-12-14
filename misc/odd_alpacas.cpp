#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

struct Edge{
    int v, w;
    Edge(int v, int w) {
        this->v = v;
        this->w = w;
    }
};

const int MAXN = 200005;
vector<Edge> adj[MAXN];
ll evenCnt[MAXN];
ll oddCnt[MAXN];
ll ans = 0;

void dfs1(int v, int prev, int dist) {
    if(dist == 0) evenCnt[v]++;
    else oddCnt[v]++;

    for(Edge e : adj[v]) {
        if(e.v == prev) continue;

        dfs1(e.v, v, (dist + e.w) % 2);
        evenCnt[v] += evenCnt[e.v];
        oddCnt[v] += oddCnt[e.v];   
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n-1; i++) {
        int a, b, w; cin >> a >> b >> w; w %= 2;
        adj[a].push_back(Edge(b, w)); adj[b].push_back(Edge(a, w));
    }

    dfs1(1, 1, 0);
    
    ll evenAns = evenCnt[1]*(evenCnt[1]-1)/2 + oddCnt[1]*(oddCnt[1]-1)/2;
    ll oddAns = evenCnt[1]*oddCnt[1];
    ans = abs(evenAns - oddAns);

    for(int i = 1; i <= n; i++) {
        ll newEvenCnt = evenCnt[1] - evenCnt[i] + oddCnt[i];
        ll newOddCnt = oddCnt[1] - oddCnt[i] + evenCnt[i];
        ll newEvenAns = newEvenCnt*(newEvenCnt-1)/2 + newOddCnt*(newOddCnt-1)/2;
        ll newOddAns = newEvenCnt*newOddCnt;
        ans = min(ans, abs(newEvenAns - newOddAns));
    }

    cout << ans << "\n";

    return 0;
}