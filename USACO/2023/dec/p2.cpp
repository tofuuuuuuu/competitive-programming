#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

#define int long long
const int MAXN = 500005;
int n, k;
int a[MAXN];
int b[MAXN];
int pos1[MAXN];
int pos2[MAXN];
unordered_set<int> tot;
unordered_set<int> st1;
unordered_set<int> st2;
unordered_map<int, int> delta;
int rt, d;

bool isValid(int i) {
    return (pos1[i] != 0) && (pos2[i] != 0);
}

int getDelta(int x) {
    int d1 = pos1[x] - pos1[rt];
    if(d1 < 0) d1 += k;
    int d2 = pos2[x] - pos2[rt];
    if(d2 < 0) d2 += k;
    int diff = d2 - d1;
    if(diff < 0) diff += k;

    return diff;
}

void fun() {
    delta.clear();
    for(int i = 1; i <= n; i++) {
        if(!isValid(i)) continue;

        delta[getDelta(i)]++;
    }
}

void reverse2() {
    for(int i = 1; i <= k; i++) {
        pos2[b[i]] = k - i + 1;
    }
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= k; i++) {
        cin >> a[i]; pos1[a[i]] = i;
        st1.insert(a[i]);
        tot.insert(a[i]);
    }
    for(int i = 1; i <= k; i++) {
        cin >> b[i]; pos2[b[i]] = i;
        st2.insert(b[i]);
        tot.insert(b[i]);
    }

    rt = -1;
    for(int i = 1; i <= n; i++) {
        if(!isValid(i)) continue;

        rt = i;
        break;
    }

    if(rt == -1) {
        cout << n - tot.size() << "\n";
        return 0;
    }

    fun();

    int mx = 0;
    for(auto i : delta) {
        mx = max(mx, i.second);
    }

    reverse2();
    fun();
    for(auto i : delta) {
        mx = max(mx, i.second);
    }

    cout << mx + (n - tot.size()) << "\n";

    return 0;
}