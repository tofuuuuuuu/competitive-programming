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

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        r[i] = 0;
    }

    vector<Edge> edges;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back(Edge(a, b, 1, i));
    }

    //sort(edges.begin(), edges.end(), cmp);
    vector<int> ans;
    for(auto e : edges){
        if(merge(e.a, e.b)) {
            ans.push_back(e.idx);
        }
    }
    
    if(ans.size() < n-1) cout << "Disconnected Graph" << "\n";
    else {
        for(int i : ans) {
            cout << i << "\n";
        }
    }

    return 0;
}