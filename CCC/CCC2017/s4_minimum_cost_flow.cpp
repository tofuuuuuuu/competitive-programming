#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
int p[MAXN];
int r[MAXN];

struct Edge {
    int a, b, w, idx;

    Edge(int a, int b, int weight, int index) {
        this->a = a;
        this->b = b;
        this->w = weight;
        this->idx = index;
    }
};

bool cmp(Edge &a, Edge &b) {
    if(a.w == b.w) return a.idx < b.idx;
    return a.w < b.w;
}

int find(int v) {
    if(p[v] != v) p[v] = find(p[v]);
    return p[v];
}

bool merge(int a, int b) {
    int p1 = find(a);
    int p2 = find(b);
    if(p1 == p2) return false;

    if(r[p1] == r[p2]) {
        p[p2] = p1;
        r[p1]++;
    }
    else if(r[p1] > r[p2]) {
        p[p2] = p1;
    }
    else {
        p[p1] = p2;
    }
    return true;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, d;
    cin >> n >> m >> d;
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        r[i] = 0;
    }

    vector<Edge> edges;
    for(int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(Edge(a, b, c, i));
    }
    sort(edges.begin(), edges.end(), cmp);

    int ans = 0;
    int max = 0;
    int lastEdge = 0;
    for(auto e : edges) {
        if(merge(e.a, e.b)) {
            if(e.idx > n-1) {
                ans++;
            }
            max = e.w;
            lastEdge = e.idx;
        }
    }

    for(int i = 1; i <= n; i++) {
        p[i] = i;
        r[i] = 0;
    }

    if(lastEdge > n-1) {
        int cnt = 0;
        while(cnt < m && edges[cnt].w < max) {
            merge(edges[cnt].a, edges[cnt].b);
            cnt++;
        }
        while(cnt < m && edges[cnt].w == max && edges[cnt].idx <= n-1) {
            merge(edges[cnt].a, edges[cnt].b);
            cnt++;
        }
        while(cnt < m && edges[cnt].w <= d) {
            if(find(edges[cnt].a) == find(edges[cnt].b)) {
                cnt++;
                continue;
            }
            if(edges[cnt].idx <= n-1) {
                ans--;
                break;
            }
            cnt++;
        }
    }

    cout << ans << "\n";
    return 0;
}