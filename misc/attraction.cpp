#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 200005;
//const ll BFN = (ll)1e17;
const ll MOD = 1000000007;
const int BFN = (int)1e9;
int n, t, a, b; ll c; 
pair<ll, pair<ll, ll>> tmp;
ll p[MAXN];

void sol() { 
    cin >> n >> a >> b;
    for(int i = 1; i <= a; i++) {
        cin >> p[i];
    }
    sort(p+1, p+a+1);

    priority_queue<pair<ll, pair<ll, ll>>> pq;
    for(int i = 1; i < a; i++) {
        c = p[i+1] - p[i] - 1;
        if(c == 1) {
            tmp.first = 1; tmp.second = {1, 0};
        }
        else {
            tmp.first = (c+1)/2; tmp.second = {c, 1};
        }
        pq.emplace(tmp);
    }

    tmp.first = p[1] - 1; tmp.second = {p[1] - 1, 0};
    pq.emplace(tmp);
    tmp.first = n - p[a]; tmp.second = {n - p[a], 0};
    pq.emplace(tmp);

    ll ans = 0;
    for(int i = 1; i <= b; i++) {
        if(pq.empty()) break;
        tmp = pq.top(); pq.pop();

        ans += tmp.first;
        
        if(tmp.second.second == 1) {
            if(tmp.second.first % 2 == 0) {
                tmp.first = tmp.second.first - tmp.first;
                tmp.second.first = tmp.first;
                tmp.second.second = 0;
                pq.emplace(tmp);
            }
            else {
                tmp.first = tmp.second.first - tmp.first - 1;
                tmp.second.second = 2;
                pq.emplace(tmp);
            }
        }
        else if(tmp.second.second == 2) {
            tmp.first = 1;
            tmp.second.second = 0;
            pq.emplace(tmp);
        }
    }
    cout << ans << "\n";
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for(int i = 1; i <= t; i++) {
        sol();
    }

    return 0;
}