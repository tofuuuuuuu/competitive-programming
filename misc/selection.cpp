#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 300005;
int BIT[21][MAXN];

int lowbit(int n) {return n&(-n);}

void update(int g, int idx, int val) {
    for(int i = idx; i < MAXN; i+=lowbit(i)) {
        BIT[g][i] += val;
    }
}

int query(int g, int idx) {
    int ans = 0;
    for(int i = idx; i > 0; i-=lowbit(i)) {
        ans += BIT[g][i];
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i <= 20; i++) {
        for(int j = 0; j <= MAXN; j++) {
            BIT[i][j] = 0;
        }
    }

    int n, m;
    cin >> n >> m;
    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        update(a[i], i, 1);
    }
    for(int i = 1; i <= m; i++) {
        int t; cin >> t;
        if(t == 1) {
            int idx, newG;
            cin >> idx >> newG;
            update(a[idx], idx, -1);
            update(newG, idx, 1);
            a[idx] = newG;
        }
        else {
            int l, r, c;
            cin >> l >> r >> c;

            int cnt = 0;
            for(int g = 20; g >= 0; g--) {
                cnt += query(g, r) - query(g, l-1);
                if(cnt >= c) {
                    cout << g << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}