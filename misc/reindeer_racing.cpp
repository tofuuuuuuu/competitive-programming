#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, s, f, l, r; cin >> n >> m >> s >> f >> l >> r;
    int k[m+1];
    int lastF = 0;
    for(int i = 1; i <= m; i++) {
        cin >> k[i];
        if(k[i] == f) {
            lastF = i;
        }
    }
    k[0] = s;

    if(r == 0 && s != f) {
        cout << "-1\n";
        return 0;
    }
    if(lastF == 0 && s != f) {
        cout << "-1\n";
        return 0;
    }
    if((lastF)*n + (m  - lastF)*(n-1) < l) {
        cout << "-1\n";
        return 0;
    }

    int x = 0;
    int cnt = l;
    int pos = s;
    int ans[n+1][m+1];
    memset(ans, 0, sizeof(ans));
    
    if(l == 0 && s == f) {
        cout << x << "\n";
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m-1; j++) {
                cout << ans[i][j] << " ";
            }
            cout << ans[i][m] << "\n";
        }
        return 0;
    }

    for(int j = 1; j < lastF; j++) {
        for(int i = 1; i <= n; i++) {
            if(cnt > 1) {
                x++; cnt--;
                ans[i][j] = 1;
                if(pos == i) pos = k[j];
            }
        }
    }

    if(lastF != 0) {
    ans[pos][lastF] = 1; cnt--; x++;
    for(int i = 1; i <= n; i++) {
        if(i == pos) continue;
         if(cnt > 0) {
            x++; cnt--;
            ans[i][lastF] = 1;
        }
    }
    }

    for(int j = lastF+1; j <= m; j++) {
        for(int i = 1; i <= n; i++) {
            if(i == f) continue;
            if(cnt > 0) {
                x++; cnt--;
                ans[i][j] = 1;
            }
        }
    }

    cout << x << "\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m-1; j++) {
            cout << ans[i][j] << " ";
        }
        cout << ans[i][m] << "\n";
    }
    
    return 0;
}