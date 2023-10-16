#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

int n, k;
vector<int> a[10];
bool vis[10][100];
pii dir[]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void resetVis() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 100; j++) vis[i][j] = false;
    }
}

int dfs(int i, int j, int val) {
    int ret = 1;
    for(pii d : dir) {
        int x = i + d.first; int y = j + d.second;
        if(x < 0 || x > 9) continue;
        if(y >= a[x].size()) continue;
        if(vis[x][y]) continue;

        if(a[x][y] == val) {
            vis[x][y] = true;
            ret += dfs(x, y, val);
        }
    }
    return ret;
}

void dfsFill(int i, int j, int val) {
    for(pii d : dir) {
        int x = i + d.first; int y = j + d.second;
        if(x < 0 || x > 9) continue;
        if(y >= a[x].size()) continue;

        if(a[x][y] == val) {
            a[x][y] = 0;
            dfsFill(x, y, val);
        }
    }
}

bool fun() {
    resetVis();
    bool isDone = false;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < a[i].size(); j++) {
            if(vis[i][j]) continue;
            vis[i][j] = true;
            int amt = dfs(i, j, a[i][j]);
            if(amt >= k) {
                isDone = true;
                dfsFill(i, j, a[i][j]);
            }
        }
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < a[i].size(); j++) {
            if(a[i][j] == 0) {
                a[i].erase(a[i].begin() + j);
                j--;
            }
        }
    }

    return isDone;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string s; cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < 10; j++){
            if(s[j] == '0') continue;
            a[j].push_back(s[j] - '0');
        }
    }
    for(int i = 0; i < 10; i++) reverse(a[i].begin(), a[i].end());
    
    while(fun()) {}

    for(int i = 0; i < 10; i++) {
        while(a[i].size() != n) a[i].push_back(0);
        reverse(a[i].begin(), a[i].end());
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < 10; j++) cout << a[j][i];
        cout << "\n";
    }
    
    return 0;
}