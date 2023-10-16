#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
int n;
int p[MAXN];
int r[MAXN];

struct Point {
    int x, y, z, idx;

    Point(int x, int y, int z, int idx) {
        this-> x = x;
        this-> y = y;
        this-> z = z;
        this-> idx = idx;
    }
};

vector<Point> pt;

bool cmpX(Point &a, Point &b) {
    if(a.x == b.x) {
        if(a.y == b.y) {
            return a.z > b.z;
        }
        return a.y > b.y;
    }
    return a.x > b.x;
}

bool cmpY(Point &a, Point &b) {
    if(a.y == b.y) {
        if(a.x == b.x) {
            return a.z > b.z;
        }
        return a.x > b.x;
    }
    return a.y > b.y;
}

bool cmpZ(Point &a, Point &b) {
    if(a.z == b.z) {
        if(a.x == b.x) {
            return a.y > b.y;
        }
        return a.x > b.x;
    }
    return a.z > b.z;
}

int pointDist(Point a, Point b) {
    return min(abs(a.x - b.x), min(abs(a.y - b.y), abs(a.z - b.z)));
}

struct Edge {
    int a, b, w;

    Edge(int a, int b, int weight) {
        this->a = a;
        this->b = b;
        this->w = weight;
    }
};

vector<Edge> edges;

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

	cin >> n;
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        r[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pt.push_back(Point(a, b, c, i));
    }

    sort(pt.begin(), pt.end(), cmpX);
    for(int i = 0; i < n; i++) {
        if(i != 0) edges.push_back(Edge(pt[i].idx, pt[i-1].idx, pointDist(pt[i], pt[i-1])));
        if(i != n-1) edges.push_back(Edge(pt[i].idx, pt[i+1].idx, pointDist(pt[i], pt[i+1])));
    }
    sort(pt.begin(), pt.end(), cmpY);
    for(int i = 0; i < n; i++) {
        if(i != 0) edges.push_back(Edge(pt[i].idx, pt[i-1].idx, pointDist(pt[i], pt[i-1])));
        if(i != n-1) edges.push_back(Edge(pt[i].idx, pt[i+1].idx, pointDist(pt[i], pt[i+1])));
    }
    sort(pt.begin(), pt.end(), cmpZ);
    for(int i = 0; i < n; i++) {
        if(i != 0) edges.push_back(Edge(pt[i].idx, pt[i-1].idx, pointDist(pt[i], pt[i-1])));
        if(i != n-1) edges.push_back(Edge(pt[i].idx, pt[i+1].idx, pointDist(pt[i], pt[i+1])));
    }

    int cnt = 0;
    ll ans = 0;
    sort(edges.begin(), edges.end(), cmp);
    for(auto e : edges){
        if(cnt == n-1) break;

        if(merge(e.a, e.b)) {
            cnt++;
            ans += e.w;
        }
    }

    cout << ans << "\n";

    return 0;
}