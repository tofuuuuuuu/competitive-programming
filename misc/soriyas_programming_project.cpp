#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 500015;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, x;
int a[MAXN];
int p[MAXN];
int ans[MAXN];

int BIT[MAXN];

int lowbit(int n) {return n&(-n);}

void update(int idx, int val) {
    for(int i = idx; i < MAXN; i+=lowbit(i)) {
        BIT[i] += val;
    }
}

ll query(int idx) {
    ll ans = 0;
    for(int i = idx; i > 0; i-=lowbit(i)) {
        ans += BIT[i];
    }
    return ans;
}

struct Pt{
    int idx, p, a;
    
    Pt(int x, int y, int z) {
        idx = x;
        p = y;
        a = z;
    }
};
vector<Pt> v;

void cdq1(int l, int r) { //p[i] < p[j] && a[p[i]] > a[p[j]]
    if(l == r) return; 
    int m = (l+r) / 2;
    if(l < r) {
        cdq1(l, m); 
        cdq1(m+1, r);
    }

    vector<Pt> sorted;
    vector<int> updates;
    int a = l, b = m+1;
    while(a <= m || b <= r) {
        if(b > r || (a <= m &&  v[a].p < v[b].p)) {
            update(v[a].a, 1);
            updates.push_back(v[a].a);
            sorted.push_back(v[a]);
            a++;
        }
        else {
            ans[v[b].idx] += query(500001) - query(v[b].a);
            sorted.push_back(v[b]);
            b++;
        }
    }

    for(int i : updates) {
        update(i, -1);
    }

    int cnt = 0;
    for(int i = l; i <= r; i++) {
        v[i] = sorted[cnt];
        cnt++;
    }
}

void cdq2(int l, int r) { // p[i] > p[j] && a[p[i]] < a[p[j]if()
    if(l == r) return;
    int m = (l+r) / 2;
    if(l < r) {
        cdq2(l, m); 
        cdq2(m+1, r);
    }

    vector<Pt> sorted;
    vector<int> updates;
    int a = l, b = m+1;
    while(a <= m || b <= r) {
        if(b > r || (a <= m &&  v[a].p > v[b].p)) {
            update(v[a].a, 1);
            updates.push_back(v[a].a);
            sorted.push_back(v[a]);
            a++;
        }
        else {
            ans[v[b].idx] += query(v[b].a - 1);
            sorted.push_back(v[b]);
            b++;
        }
    }

    for(int i : updates) {
        update(i, -1);
    }

    int cnt = 0;
    for(int i = l; i <= r; i++) {
        v[i] = sorted[cnt];
        cnt++;
    }
}

void sol() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<Pt> orig;
    orig.push_back(Pt(0, 0, 0));
    for(int i = 1; i <= n; i++) {
        orig.push_back(Pt(i, p[i], a[p[i]]));
    }
    
    v = orig;
    cdq1(1, n);
    v = orig;
    cdq2(1, n);

    ll cur = 0;
    for(int i = 1; i <= n; i++) {
        cur = cur + ans[i];
        cout << cur << "\n";
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