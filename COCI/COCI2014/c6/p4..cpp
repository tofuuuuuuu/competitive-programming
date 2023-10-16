#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
const ll BFN = (ll)1e20;
int a[MAXN];
int n, q, k;
vector<int> ans;

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    // for(int i = 1; i <= n; i++) {
    //     cin >> a[i];
    // }

    for(int i = 1; i <= n/k; i++) {
        for(int j = (i)*k; j > (i-1)*k; j--) {
            ans.push_back(j);
        }
    }
    for(int i = n; i > (n/k)*k; i--) {
        ans.push_back(i);
    }

    int cnt = n/k;
    if(n % k > 0) cnt++;

    if(cnt > k) {
        cout << "-1\n";
        return 0;
    }

    for(int i : ans) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}