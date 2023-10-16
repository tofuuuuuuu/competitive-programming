#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

struct Grid{
    int idx, r, c;
    
    Grid(int idx, int r, int c) {
        this->idx = idx;
        this->r = r;
        this->c = c;
    }
};

struct Move{
    int idx, amt;
    char c;

    Move(int idx, char c, int amt) {
        this->idx = idx;
        this->c = c;
        this->amt = amt;
    }
};

class cmpR {
public:
    bool operator() (Grid a, Grid b) {
        return a.r > b.r;
    }
};

class cmpC {
public:
    bool operator() (Grid a, Grid b) {
        return a.c > b.c;
    }
};

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    vector<Move> ans;
    ll cnt = 0;

    int n; cin >> n;
    vector<Grid> a;
    for(int i = 1; i <= n; i++) {
        int r, c; cin >> r >> c;
        a.push_back(Grid(i, r, c));
    }

    sort(a.begin(), a.end(), cmpR());
    stack<Move> downMoves;
    int curV = n;
    for(Grid g : a) {
        int dif = curV - g.r; cnt += abs(dif);
        if(dif > 0) {
            ans.push_back(Move(g.idx, 'D', dif));
        }
        else if(dif < 0){
            downMoves.push(Move(g.idx, 'U', -dif));
        }

        curV--;
    }
    while(!downMoves.empty()) {
        ans.push_back(downMoves.top());
        downMoves.pop();
    }

    sort(a.begin(), a.end(), cmpC());
    curV = n;
    for(Grid g : a) {
        int dif = curV - g.c; cnt += abs(dif);
        if(dif > 0) {
            ans.push_back(Move(g.idx, 'R', dif));
        }
        else if(dif < 0){
            downMoves.push(Move(g.idx, 'L', -dif));
        }

        curV--;
    }
    while(!downMoves.empty()) {
        ans.push_back(downMoves.top());
        downMoves.pop();
    }

    cout << cnt << "\n";
    for(Move m : ans) {
        for(int i = 0; i < m.amt; i++) {
            cout << m.idx << " " << m.c << "\n";
        }
    }

    return 0;
}