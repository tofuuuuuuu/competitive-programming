#include <bits/stdc++.h>
using namespace std;
#define ll long long

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T>
// using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// Tree<ll> tr;

// #define int long long
#define pii pair<int, int>
#define pll pair<ll ,ll>

// #define scanu(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
// char _;

const int MAXN = 500005;
const ll MOD = 1000000007;
const ll BFN = (ll)1e17;
//const int BFN = (int)2e9;
int t, n;
int a[MAXN];
int idx1, idxn;

bool sol() {
    cin >> n; 
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if(n == 1 || n == 2) return true;
    
    int curTop = a[1], curBot = a[1], l = 2, r = n;
    bool good = true;
    while(l <= r) {
        if(a[l] == curTop - 1) {
            curTop = a[l];
            l++;
        }
        else if(a[l] == curBot + 1) {
            curBot = a[l];
            l++;
        }
        else if(a[r] == curTop - 1) {
            curTop = a[r];
            r--;
        }
        else if(a[r] == curBot + 1) {
            curBot = a[r];
            r--;
        }
        else {
            good = false;
            break;
        }
    }

    if(good) return true;

    curTop = a[n], curBot = a[n], l = 1, r = n-1;
    good = true;
    while(l <= r) {
        if(a[l] == curTop - 1) {
            curTop = a[l];
            l++;
        }
        else if(a[l] == curBot + 1) {
            curBot = a[l];
            l++;
        }
        else if(a[r] == curTop - 1) {
            curTop = a[r];
            r--;
        }
        else if(a[r] == curBot + 1) {
            curBot = a[r];
            r--;
        }
        else {
            good = false;
            break;
        }
    }

    return good;
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        if(sol()) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

    return 0;
}