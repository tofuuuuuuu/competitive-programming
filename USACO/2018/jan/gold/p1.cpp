#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
const ll BFN = (ll)1e20;
int pa[MAXN];
int sz[MAXN];
int N, Q, p, q, r, k, v;
vector<pair<int, pii>> edges;
vector<pair<int, pii>> queries;
int ans[MAXN];

int find(int v) {
    if(pa[v] == v) return v;
    pa[v] = find(pa[v]);
    return pa[v];
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;

    if(sz[a] < sz[b]) swap(a, b);
    pa[b] = a;
    sz[a] += sz[b];
}

int main(){
    freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for(int i = 1; i <= N; i++) {
        pa[i] = i;
        sz[i] = 1;
    }
    for(int i = 1; i <= N-1; i++) {
        cin >> p >> q >> r;
        edges.push_back({r, {p, q}});
    }
    for(int i = 1; i <= Q; i++) {
        cin >> k >> v;
        queries.push_back({k, {v, i}});
    }
    sort(edges.begin(), edges.end(), greater<pair<int, pii>>());
    sort(queries.begin(), queries.end(), greater<pair<int, pii>>());

    int cnt = 0;
    for(auto qr : queries) {
        int curK = qr.first, curV = qr.second.first, curIdx = qr.second.second; 
        while(cnt < N-1 && edges[cnt].first >= curK) {
            int a = edges[cnt].second.first, b = edges[cnt].second.second;;
            merge(a, b);
            cnt++;
        }
        ans[curIdx] = sz[find(curV)];
    }

    for(int i = 1; i <= Q; i++) {
        cout << ans[i] - 1 << "\n";
    }

    return 0;
} 