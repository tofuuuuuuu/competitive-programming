#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;

struct Edge {
    int a, b, t;

    Edge(int a, int b, int type) {
        this->a = a;
        this->b = b;
        this->t= type;
    }
};

struct DSU {
    int p[MAXN];
    int r[MAXN];

    DSU(int n) {
        for(int i = 1; i <= n; i++) {
            p[i] = i;
            r[i] = 0;
        }
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
};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<Edge> edges0;
    vector<Edge> edges1;
    vector<Edge> ans;
    for(int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if(c == 0) edges0.push_back(Edge(a, b, 0));
        else edges1.push_back(Edge(a, b, 1));
    }

    if(k > n-1) {
        cout << "no solution\n";
        return 0;
    }

    int cntTot = 0, cnt0 = 0; 
    DSU dsu = DSU(n);
    for(Edge e : edges1) {
        if(dsu.merge(e.a, e.b)) {
            cntTot++;
        }
    }
    for(Edge e : edges0) {
        if(dsu.merge(e.a, e.b)) {
            ans.push_back(e);
            cntTot++;
            cnt0++;
        }
    }

    if(cntTot != n-1) {
        cout << "no solution\n";
        return 0;
    }

    if(cnt0 > k) {
        cout << "no solution\n";
        return 0;
    }

    cntTot = 0; cnt0 = 0;
    dsu = DSU(n);
    for(Edge e : ans) {
        if(dsu.merge(e.a, e.b)) {
            cntTot++;
            cnt0++;
        }
    }
    for(Edge e : edges0) {
        if(dsu.merge(e.a, e.b)) {
            ans.push_back(e);
            cntTot++;
            cnt0++;
        }
        if(cnt0 == k) break;
    }
    for(Edge e : edges1) {
        if(dsu.merge(e.a, e.b)) {
            cntTot++;
            ans.push_back(e);
        }
    }

    if(cntTot != n-1) {
        cout << "no solution\n";
        return 0;
    }

    if(cnt0 != k) {
        cout << "no solution\n";
        return 0;
    }

    for(Edge e : ans) {
        cout << e.a << " " << e.b << " " << e.t << "\n";
    }

    return 0;
}