#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

const int MAXN = 100005;
int n, m, r;
ll cow[MAXN];
pll milk[MAXN];
ll rent[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;
    for(int i = 0; i < n; i++) {
        cin >> cow[i];
    }
    for(int i = 0; i < m; i++) {
        ll g, p; cin >> g >> p;
        milk[i] = {p, g};
    }
    for(int i = 0; i < r; i++) {
        cin >> rent[i];
    }
    sort(cow, cow+n);
    sort(milk, milk+m);
    sort(rent, rent+r);

    ll ans = 0;
    ll curLeft = milk[m-1].second;
    int cowIdx = 0;
    int milkIdx = m-1;
    int rentIdx = r-1;
    for(int i = n-1; i >= cowIdx; i--) {
        ll g = cow[i];
        ll milkGain = 0; ll newLeft = 0; ll newMilkIdx = milkIdx;
        if(milkIdx >= 0 && curLeft <= g) {
            milkGain += curLeft * milk[milkIdx].first;
            g -= curLeft;

            int j = milkIdx-1;
            while(j >= 0) {
                if(g >= milk[j].second) {
                    milkGain += milk[j].second * milk[j].first;
                    g -= milk[j].second;
                    j--;
                }
                else {
                    break;
                }
            }
            milkGain += g * milk[j].first;
            newLeft = milk[j].second - g;
            newMilkIdx = j;
        }
        else if(milkIdx >= 0){
            milkGain += g * milk[milkIdx].first;
            newLeft = curLeft - g;
        }

        if(rentIdx < 0 || milkGain > rent[rentIdx]) {
            ans += milkGain; 
            curLeft = newLeft;
            milkIdx = newMilkIdx;
        }
        else {
            ans += rent[rentIdx];
            rentIdx--;
            cowIdx++;
            i++;
        }
    }

    cout << ans << "\n";
    
    return 0;
}