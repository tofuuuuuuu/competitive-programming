#include <bits/stdc++.h>
using namespace std;
#define ll long long

// #define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 1000005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, m;
string s;
vector<int> a[MAXN];
vector<bool> removed[MAXN];
vector<int> rows;
vector<int> removed_rows;

void flip(int r, int c) {
    if(r+1 < n) a[r+1][c] ^= 1;
    if(c+1 < m) a[r][c+1] ^= 1;
    if(r-1 >= 0) a[r-1][c] ^= 1;
    if(c-1 >= 0) a[r][c-1] ^= 1; 
}

void removeRow(int r) {
    int cur = 0;
    while(cur < m) {
        if(a[r][cur] == 1) {
            int tmp = cur;
            while(tmp >= 0 && !removed[r][tmp]) {
                cout << r+1 << " " << tmp+1 << "\n";

                flip(r, tmp);

                removed[r][tmp] = true;
                tmp--;
            }
        }
        cur++;
    }
}

void sol() {
    cin >> n >> m;
    int tot = 0;
    for(int i = 0; i < n; i++) {
        int rSum = 0;
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == 'H') {
                a[i].push_back(1);
                rSum++;
                tot++;
            }
            else a[i].push_back(0);

            removed[i].push_back(false);
        }

        rows.push_back(rSum % 2);
        removed_rows.push_back(false);
    }

    if(tot % 2 == 0) {
        cout << "-1\n";
        return;
    }

    int cur = 0;
    while(cur < n){
        if(rows[cur] == 1) {
            int tmp = cur;
            while(tmp >= 0 && !removed_rows[tmp]) {
                removeRow(tmp);
                removed_rows[tmp] = true;
                tmp--;
            }
            if(cur + 1 < n) rows[cur+1] ^= 1;
        }
        cur++;
    }
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    sol();

    return 0;
}