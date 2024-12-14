#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 500005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, q, x, y; char qType;

void sol(vector<int> &cap, vector<int> &bot) {
    if(cap.size() == 0) return;
    if(cap.size() == 1) {
        cout << "1 " << cap[0] << " " << bot[0] << endl;
        return;
    }

    int c = cap[0];
    int bAns = -1;

    vector<int> lowerBot; vector<int> higherBot;
    for(int i : bot) {
        cout << "0 " << c << " " << i << endl; cin >> x;
        if(x == 0) {
            bAns = i;
        }
        else if(x == 1) {
            lowerBot.push_back(i);
        }
        else {
            higherBot.push_back(i);
        }
    }

    vector<int> lowerCap; vector<int> higherCap;
    for(int i : cap) {
        cout << "0 " << i << " " << bAns << endl; cin >> x;
        if(i == c) continue;

        if(x == 1) {
            higherCap.push_back(i);
        }
        else {
            lowerCap.push_back(i);
        }
    }

    cout << "1 " << c << " " << bAns << endl;

    sol(lowerCap, lowerBot);
    sol(higherCap, higherBot);
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    vector<int> cap;
    vector<int> bot;
    for(int i = 1; i <= n; i++) {
        cap.push_back(i);
        bot.push_back(i);
    }
    random_shuffle(cap.begin(), cap.end());
    random_shuffle(bot.begin(), bot.end());

    sol(cap, bot);

    return 0;
}