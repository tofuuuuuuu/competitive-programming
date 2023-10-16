#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 505;
ll n; 
vector<int> ans;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    //(b+1)(A) = n
    for(int i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            if(i - 1 > n/i) ans.push_back(i - 1);
            if(n/i - 1 > i) ans.push_back(n/i - 1);
        }
    }
    
    for(int i = 2; i*i <= n; i++) {
        vector<int> cur;
        int x = n;
        while(x > 0) {
            cur.push_back(x % i);
            x /= i;
        }
        
        bool bad = false;
        for(int i = 0; i < cur.size()/2; i++) {
            if(cur[i] != cur[cur.size() - i - 1]) {
                bad = true;
                break;
            }
        }

        if(bad) continue;
        ans.push_back(i);
    }
    sort(ans.begin(), ans.end());

    for(int i : ans) {
        cout << i << "\n";
    }

    return 0;
} 