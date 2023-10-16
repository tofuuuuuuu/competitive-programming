#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
const ll BFN = (ll)1e20;
int a[MAXN];
ll n, q, k, x, y, tmp;
vector<string> ans;

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    // cin >> n >> q;
    // for(int i = 1; i <= n; i++) {
    //     cin >> a[i];
    // }

    cin >> x >> y;
    if(x <= y) {
        tmp = x;
        while(tmp > 0) {
            if(tmp % 2 == 1) {
                ans.push_back("B C C\n");
            }
            ans.push_back("B B B\n");
            tmp /= 2;
        }
    }
    else {
        tmp = y;
        while(tmp > 0) {
            if(tmp % 2 == 1) {
                ans.push_back("A C C\n");
            }
            ans.push_back("A A A\n");
            tmp /= 2;
        }
    }

    cout << ans.size() << "\n";
    for(string s : ans) {
        cout << s;
    }

    cout << "C\n";

    return 0;
}