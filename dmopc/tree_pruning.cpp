#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 1000006;
int n;
ll k;
ll w[MAXN];
vector<int> adj[MAXN];
bool vis[MAXN];
ll curSum = -1;
set<int> ans;

void dfs(int v) {
    for(int i : adj[v]) {
        if(vis[i]) continue;  
        if(w[i] > k) continue;

        vis[i] = true;

        if(curSum < k) {
            curSum += w[i];
            ans.insert(i);
            dfs(i);
        }
    }
}

int main(){
    //freopen("filename.in", "r", stdin);
	//freopen("filename.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for(int i = 1; i <= n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        if(w[i] > 2*k) continue;
        
        ans.clear();
        vis[i] = true;
        ans.insert(i);
        curSum = w[i];
        dfs(i);

        if(curSum >= k && curSum <= 2*k) break;
    }

    if(curSum >= k && curSum <= 2*k) {
        cout << ans.size() << "\n";
        for(int i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
    else {
        cout << "-1\n";
    }

    return 0;
}