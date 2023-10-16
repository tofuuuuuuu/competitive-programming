#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

struct Cow {
    int idx, arrive, time;

    Cow(int idx, int a, int t) {
        this->idx = idx;
        this->arrive = a;
        this->time = t;
    }
};

class cmp1 {
public:
    bool operator() (Cow a, Cow b) {
        return a.idx > b.idx;
    }
};

class cmp2 {
public:
    bool operator() (Cow a, Cow b) {
        return a.arrive < b.arrive;
    }
};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, a, t; cin >> n;
    vector<Cow> cows;
    int ans[n+1];
    for(int i = 0; i < n; i++) {
        cin >> a >> t;
        cows.push_back(Cow(i+1, a, t));
    }
    sort(cows.begin(), cows.end(), cmp2());

    int curT = 0;
    priority_queue<Cow, vector<Cow>, cmp1> q;
    int i = 0;
    while(i < n) {
        if(q.empty()) {
            q.emplace(cows[i]);
            curT = cows[i].arrive;
            i++;

            while(i < n && cows[i].arrive == cows[i-1].arrive) {
                q.push(cows[i]);
                i++;
            }
        }

        Cow cur = q.top(); q.pop();
        ans[cur.idx] = curT - cur.arrive;

        while(i < n && cows[i].arrive <= curT + cur.time) {
            q.push(cows[i]);
            i++;
        }

        curT = curT + cur.time;
    }

    while(!q.empty()) {
        Cow cur = q.top(); q.pop();

        ans[cur.idx] = curT - cur.arrive;
        curT = curT = cur.time;
    }

    int maxAns = 0;
    for(int i = 1; i <= n; i++) {
        if(ans[i] > maxAns) maxAns = ans[i];
    }

    cout << maxAns << "\n";
    
    return 0;
}