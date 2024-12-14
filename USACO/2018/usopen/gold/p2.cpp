#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
const ll MOD = 1000000007;
//const ll BFN = (ll)1e17;
const int BFN = (int)1e9;
int n, m, mi;
int a[MAXN];
vector<pii> adj[MAXN];
int inDeg[MAXN];
vector<int> ret;

bool fun(int x) {
    for(int i = 1; i <= n; i++) {
        inDeg[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(pii p : adj[i]) {
            if(p.second > x) continue;
            inDeg[p.first]++;
        }
    }

    int cnt = 0;
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(inDeg[i] == 0) {
            q.push(i);
            cnt++;
        }
    }

    int cur;
    while(!q.empty()) {
        cur = q.front(); q.pop();
        for(pii p : adj[cur]) {
            if(p.second > x) continue;
            inDeg[p.first]--;
            if(inDeg[p.first] == 0) {
                q.push(p.first);
                cnt++;
            }
        }
    }

    return cnt == n;
}

void getAns(int x) {
    for(int i = 1; i <= n; i++) {
        inDeg[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(pii p : adj[i]) {
            if(p.second > x) continue;
            inDeg[p.first]++;
        }
    }

    priority_queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(inDeg[i] == 0) {
            q.push(-i);
        }
    }

    int cur;
    while(!q.empty()) {
        cur = -q.top(); q.pop();
        ret.push_back(cur);
        for(pii p : adj[cur]) {
            if(p.second > x) continue;
            inDeg[p.first]--;
            if(inDeg[p.first] == 0) {
                q.push(-p.first);
            }
        }
    }
}

void sol() { 
    cin >> n >> m;
    int x, y;
    for(int i = 1; i <= m; i++) {
        cin >> mi >> x;
        for(int j = 2; j <= mi; j++) {
            cin >> y;
            adj[x].push_back({y, i});
            x = y;
        }
    }


    int ans = -1, l = 1, r = m;
    while(l <= r) {
        int m = (l+r)/2;
        if(fun(m)) {
            ans = m;
            l = m+1;
        }
        else {
            r = m-1;
        }
    }

    getAns(ans);
    for(int i : ret) {
        cout << i << " ";
    }
    cout << "\n";
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}