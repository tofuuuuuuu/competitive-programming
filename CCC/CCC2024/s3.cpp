#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 300005;
const ll MOD = 1000000007;
const ll BFN = (ll)1e16;
int n, t;
int a[MAXN];
int b[MAXN];
vector<pair<char, pii>> ans;
stack<pair<char, pii>> st;

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int aIdx = 1, bIdx = 1;
    while(bIdx <= n) {
        int bLft = bIdx, bRgh = bIdx;

        while(bRgh + 1 <= n && b[bRgh + 1] == b[bRgh]) {
            bRgh++;
        }

        while(aIdx <= n && a[aIdx] != b[bLft]) {
            aIdx++;
        }

        if(aIdx == n+1) {
            cout << "NO\n";
            return 0;
        }

        if(bLft < aIdx) {
            while(!st.empty()) {
                ans.push_back(st.top()); st.pop();
            }

            ans.push_back({'L', {bLft-1, aIdx-1}});
        }
        if (aIdx < bRgh) {
            st.push({'R', {aIdx-1, bRgh-1}});
        }

        aIdx++;
        bIdx = bRgh + 1;
    }
    while(!st.empty()) {
        ans.push_back(st.top()); st.pop();
    }

    cout << "YES\n";
    cout << ans.size() << "\n";
    for(auto i : ans) {
        cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
    }

    return 0;
}