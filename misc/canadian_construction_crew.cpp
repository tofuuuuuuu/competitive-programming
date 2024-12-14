#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100006;
int p[MAXN];
int r[MAXN];
ll sz[MAXN];
ll deg[MAXN];

int find(int v) {
    if(p[v] != v) p[v] = find(p[v]);
    return p[v];
}

void merge(int a, int b) {
    int p1 = find(a);
    int p2 = find(b);
    if(p1 == p2) return;

    if(r[p1] == r[p2]) {
        p[p2] = p1;
        sz[p1] += sz[p2];
        r[p1]++;
    }
    else if(r[p1] > r[p2]) {
        p[p2] = p1;
        sz[p1] += sz[p2];
    }
    else {
        p[p1] = p2;
        sz[p2] += sz[p1];
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        r[i] = 0;
        sz[i] = 1;
        deg[i] = 0;
    }

    ll oddCnt = 0;
    ll evenCnt = 0;
    unordered_set<int> nodes;
    for(int i = 1; i <= q; i++) {
        int a, b, t; cin >> a >> b >> t;
        nodes.emplace(a); nodes.emplace(b);

        deg[a] += t; deg[b] += t;
        if(deg[a] == t) {
            if(deg[a] % 2 == 0) evenCnt++;
            else oddCnt++;
        }
        else if(t % 2 == 1){
            if(deg[a] % 2 == 0) {
                evenCnt++; oddCnt--;
            }
            else {
                oddCnt++; evenCnt--;
            }
        }
        if(deg[b] == t) {
            if(deg[b] % 2 == 0) evenCnt++;
            else oddCnt++;
        }
        else if(t % 2 == 1){
            if(deg[b] % 2 == 0) {
                evenCnt++; oddCnt--;
            }
            else {
                oddCnt++; evenCnt--;
            }
        }

        merge(a, b);
        if(sz[find(a)] != nodes.size()) cout << "NO\n";
        else {
            if(oddCnt <= 2) cout << "YES\n";
            else cout << "NO\n";
        }
        
    }

    return 0;
}