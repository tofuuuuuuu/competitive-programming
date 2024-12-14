#include <bits/stdc++.h>
using namespace std;
#define ll long long

// #define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 100005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, m, x, y;
char qType;

struct Segtree{
    int seg[4*MAXN];

    void pushup(int cur) {
        seg[cur] = max(seg[2*cur], seg[2*cur+1]);
    }

    void update(int cur, int l, int r, int idx, int val) {
        if(l == r) {
            seg[cur] = val;
            return;
        }
        
        int m = (l+r)/2;
        if(idx <= m) update(2*cur, l, m, idx, val);
        else update(2*cur+1, m+1, r, idx, val);
        pushup(cur);
    }

    int walk(int cur, int l, int r, int qIdx, int qVal) {
        if(seg[cur] < qVal) {
            return -1;
        }
        if(l == r) {
            if(qIdx > l || qVal > seg[cur]) {
                return -1;
            }
            return l;
        } 

        int m = (l+r)/2;
        if(qIdx > m) {
            return walk(2*cur+1, m+1, r, qIdx, qVal);
        }

        int ret = walk(2*cur, l, m, qIdx, qVal);
        if(ret == -1) {
            ret = walk(2*cur+1, m+1, r, qIdx, qVal);
        }
        return ret;
    }
} seg;

struct Query{
    int type, x, y;

    Query(int a, int b, int c) {
        type = a; x = b; y = c;
    }
};

vector<Query> queries; 
vector<pii> ppl;
map<int, pii> a;
map<pii, pii> mp;
void sol() {
    cin >> n;

    int cnt = 1;
    for(int i = 1; i <= n; i++) {
        cin >> qType;
        if(qType == 'D') {
            cin >> y >> x;
            queries.push_back(Query(1, x, y));
            ppl.push_back({x, y});

            a[cnt] = {x, y};
            mp[{x, y}].first = cnt;
            cnt++;
        }
        else {
            cin >> x;
            queries.push_back(Query(2, x, 0));
        }
    }

    sort(ppl.begin(), ppl.end());
    cnt = 1;
    for(pii p : ppl) {
        mp[p].second = cnt;
        cnt++;
    }

    for(Query q : queries) {
        if(q.type == 1) {
            seg.update(1, 1, ppl.size(), mp[{q.x, q.y}].second, q.y);
        }
        else {
            int ret = seg.walk(1, 1, ppl.size(), mp[a[q.x]].second + 1, a[q.x].second);
            if(ret == -1) cout << "NE\n";
            else cout << mp[ppl[ret - 1]].first << "\n";
        }
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