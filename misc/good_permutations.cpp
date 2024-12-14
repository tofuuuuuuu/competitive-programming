#include <bits/stdc++.h>
using namespace std;
#define ll long long

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T>
// using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// Tree<ll> tr;

#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

// #define scanu(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
// char _;

const int MAXN = 500005;
const ll MOD = 1000000007;
// const ll BFN = (ll)1e16;
const int BFN = (int)1e8;
int n;
int a[MAXN];
int inDeg[MAXN];
int sieve[MAXN];
int pos[MAXN];
vector<int> edge[MAXN];
vector<int> pri[MAXN];
vector<int> ans;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

void toposort() {
    priority_queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(inDeg[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int cur = q.top(); q.pop();
        ans.push_back(cur);
        
        for(int i : edge[cur]) {
            inDeg[i]--;
            if(inDeg[i] == 0) {
                q.push(i);
            }
        }
    }
}

void sol() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for(int i = 2; i <= n; i++) {
        if(sieve[i] != 0) continue;

        for(int j = i; j <= n; j += i) {
            sieve[j]++;
            pri[i].push_back(pos[j]);
        }
        sort(pri[i].begin(), pri[i].end());

        for(int j = 1; j < pri[i].size(); j++) {
            edge[a[pri[i][j-1]]].push_back(a[pri[i][j]]);
            inDeg[a[pri[i][j]]]++;
        }
    }

    toposort();

    for(int i : ans) {
        cout << i << " ";
    }
    cout << "\n";
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();
    cout << "\n";

    return 0;
}