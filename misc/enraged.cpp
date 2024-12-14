#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

int movement[9][2] = {{1, 0}, {0, 1}, {1, 1}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};
bool isValid(int x, int y, int n) {
    if(x <= 0) return false;
    if(y <= 0) return false;
    if(x > n) return false;
    if(y > 2) return false; 
    return true;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int g[n+1][3];
    for(int j = 1; j <= 2; j++) {
        string fuck;
        cin >> fuck;
        for(int i = 1; i <= n; i++) {
            if(fuck[i-1] == 'S') g[i][j] = 1;
            else g[i][j] = 0;
        }
    }

    int dist[n+1][3][3];
    memset(dist, 0, sizeof(dist));

    queue<int> q;
    dist[1][1][0] = 1;
    q.push(1); q.push(1); q.push(0);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        int breakAmt = q.front(); q.pop();
        
        for(int i = 0; i < 9; i++) {
            int newX = x + movement[i][0];
            int newY = y + movement[i][1];
            int newBreak = breakAmt;
            if(!isValid(newX, newY, n)) continue;
            if(g[newX][newY] == 1) newBreak = breakAmt + 1;
            if(newBreak > 2) continue;
            if(dist[newX][newY][newBreak] != 0) continue;

            dist[newX][newY][newBreak] = 1;
            q.push(newX); q.push(newY); q.push(newBreak);
        }
    }

    if(dist[n][2][0] || dist[n][2][1] || dist[n][2][2]) cout << "YES" << "\n";
    else cout << "NO" << "\n";

    return 0;
}