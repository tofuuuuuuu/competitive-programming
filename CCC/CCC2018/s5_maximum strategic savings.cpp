#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

struct Edge {
    int a, b; ll weight; int type;

    Edge(int a, int b, ll weight, int type) {
        this->a = a;
        this->b = b;
        this->weight = weight;
        this->type = type;
    }
};

static int kruskalCmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

struct DisjointSet {
    vector<Edge> edges;
    vector<int> parent, rank;

    DisjointSet(int v) : rank(v+1) {
        for (int i = 0; i <= v; i++) {
            parent.push_back(i);
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool merge(int x, int y) {
        int xRt = find(x), yRt = find(y);
        if (xRt == yRt) {
            return false;
        }
        if (rank[xRt] < rank[yRt]) {
            parent[xRt] = yRt;
        } else if (rank[xRt] > rank[yRt]) {
            parent[yRt] = xRt;
        } else {
            parent[xRt] = yRt;
            rank[yRt]++;
        }
        return true;
    }
};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, p, q;
    cin >> n >> m >> p >> q;
    DisjointSet ds1(m);
    DisjointSet ds2(n);

    vector<Edge> edgeList;
    ll total = 0;
    for(int i = 1; i <= p; i++) {
        int a, b; ll w;
        cin >> a >> b >> w;
        edgeList.push_back(Edge(a, b, w, 1));
        total += w*n;
    }
    for(int i = 1; i <= q; i++) {
        int x, y; ll z;
        cin >> x >> y >> z;
        edgeList.push_back(Edge(x, y, z, 2));
        total += z*m;
    }
    sort(edgeList.begin(), edgeList.end(), kruskalCmp);

    ll ans = 0;
    int mCnt = m;
    int nCnt= n;
    for(Edge e : edgeList) {
        if(e.type == 1) {
            if(ds1.merge(e.a, e.b)) {
                ans += nCnt*e.weight;
                mCnt--;
            }
        }
        else {
            if(ds2.merge(e.a, e.b)) {
                ans += mCnt*e.weight;
                nCnt--;
            }
        }
    }
    
    cout << total - ans << "\n";
    return 0;
}