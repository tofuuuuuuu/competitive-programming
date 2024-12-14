#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 1000005;
const ll MOD = 1000000007;
const ll BFN = (ll)1e16;
int n, t;
string s;
map<int, int> cnt;

void check() {
    cnt.clear();

    for(int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }

    if(cnt[s[0]] == 1) {
        for(int i = 1; i < n; i++) {
            if(i % 2 == 0) {
                if(cnt[s[i]] != 1) {
                    cout << "F\n";
                    return;
                }
            }
            else {
                if(cnt[s[i]] == 1) {
                    cout << "F\n";
                    return;
                }
            }
        }
    }
    else {
        for(int i = 1; i < n; i++) {
            if(i % 2 == 1) {
                if(cnt[s[i]] != 1) {
                    cout << "F\n";
                    return;
                }
            }
            else {
                if(cnt[s[i]] == 1) {
                    cout << "F\n";
                    return;
                }
            }
        }
    }

    cout << "T\n";
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> n;

    for(int i = 1; i <= t; i++) {
        cin >> s;
        check();
    }

    return 0;
}