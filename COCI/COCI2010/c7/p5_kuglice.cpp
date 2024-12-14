#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

struct Query{
    int type, v, nxt;

    Query(int type, int v, int nxt) {
        this->type = type;
        this->v = v;
        this->nxt = nxt;
    } 
};

const int MAXN = 300005;
int nxt[MAXN];
int dest[MAXN];
bool vis[MAXN];

void dfs(int v) {
    if(vis[v]) return;

    dest[v] = -1;
    vis[v] = true;

    if(nxt[v] == 0) {
        dest[v] = v;
    }
    else {
        dfs(nxt[v]);
        dest[v] = dest[nxt[v]];
    }
}

int find(int v) {
    if(v == -1) return -1;

    if(v == nxt[v]) return v;
    nxt[v] = find(nxt[v]);
    return nxt[v];
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> nxt[i];
    }

    int q; cin >> q;
    vector<Query> queries;
    for(int i = 0; i < q; i++) {
        int type, v; cin >> type >> v;
        queries.push_back(Query(type, v, nxt[v]));

        if(type == 2) {
            nxt[v] = 0;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    for(int i = 1; i <= n; i++) {
        nxt[i] = dest[i];
    }

    stack<int> ans;
    for(int i = q-1; i >= 0; i--) {
        int type = queries[i].type; int v = queries[i].v;
        if(type == 1) {
            ans.push(find(v));   
        }
        else {
            if(find(queries[i].nxt) == v) {
                nxt[v] = -1;
            }
            else {
                nxt[v] = queries[i].nxt;
            }
        }
    }

    while(!ans.empty()) {
        if(ans.top() == -1) {
            cout << "CIKLUS\n";
        }
        else {
            cout << ans.top() << "\n";
        }
        ans.pop();
    }

    return 0;
}