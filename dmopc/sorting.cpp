#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 105;
int n;
int nxt[MAXN];
bool vis[MAXN];
int newNxt[MAXN];
bool newVis[MAXN];
vector<int> ans;
vector<int> newAns;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

	cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> nxt[i];
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        if(nxt[i] == i) continue;

        ans.push_back(i);
        vis[i] = true;
        int cur = nxt[i];
        while(!vis[cur]) {
            ans.push_back(cur);
            vis[cur] = true;
            cur = nxt[cur];
        }

        cnt++;
    }

    if(cnt == 0) {
        cout << "0\n";
        return 0;
    }
    if(cnt == 1) {
        cout << "1\n";
        cout << ans.size();
        for(int i : ans) {
            cout << " " << i;
        }
        cout << "\n";
        return 0;
    }

    for(int i = 0; i < ans.size() - 1; i++) {
        newNxt[ans[i+1]] = nxt[ans[i]];
    }
    newNxt[ans[0]] = nxt[ans[ans.size()-1]];
    for(int i = 1; i <= n; i++) {
        if(nxt[i] == i) newNxt[i] = i;
    }

    for(int i = 1; i <= n; i++) {
        if(newVis[i]) continue;
        if(newNxt[i] == i) continue;

        newAns.push_back(i);
        newVis[i] = true;
        int cur = newNxt[i];
        while(!newVis[cur]) {
            newAns.push_back(cur);
            newVis[cur] = true;
            cur = newNxt[cur];
        }
    }

    cout << "2\n";

    cout << ans.size();
    for(int i : ans) {
        cout << " " << i;
    }
    cout << "\n";

    cout << newAns.size();
    for(int i : newAns) {
        cout << " " << i;
    }
    cout << "\n";

    return 0;
}