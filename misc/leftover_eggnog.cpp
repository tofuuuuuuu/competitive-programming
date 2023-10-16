#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 1005;
pair<int, pii> prevA[MAXN][MAXN];
int a, b, m;
queue<pii> q;
pii ans = {-1, -1};
vector<int> ret;
//1 = fill A
//2 = fill B
//3 = chug A
//4 = chug B
//5 = pour A B 
//6 = pour B A

bool vis(pii p) {
    if(prevA[p.first][p.second].first == 0) return false;
    return true;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> m;
    q.push({0, 0});
    prevA[0][0] = {-1, {0, 0}};
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        int curA = cur.first; 
        int curB = cur.second; 
        if(curA == m || curB == m) {
            ans = cur;
            break;
        }

        if(!vis({a, curB})) {
            prevA[a][curB] = {1, cur};
            q.push({a, curB});
        }
        if(!vis({curA, b})) {
            prevA[curA][b] = {2, cur};
            q.push({curA, b});
        }
        if(!vis({0, curB})) {
            prevA[0][curB] = {3, cur};
            q.push({0, curB});
        }
        if(!vis({curA, 0})) {
            prevA[curA][0] = {4, cur};
            q.push({curA, 0});
        }
        
        int newA, newB;
        if(b >= curA + curB) {
            newA = 0;
            newB = curA + curB;
        }
        else {
            newA = curA - (b - curB);
            newB = b;
        }
        if(!vis({newA, newB})) {
            prevA[newA][newB] = {5, cur};
            q.push({newA, newB});
        }

        if(a >= curA + curB) {
            newA = curA + curB;
            newB = 0;
        }
        else {
            newA = a;
            newB = curB - (a - curA);
        }
        if(!vis({newA, newB})) {
            prevA[newA][newB] = {6, cur};
            q.push({newA, newB});
        }
    }

    if(ans.first == -1) {
        cout << "Not possible\n";
        return 0;
    }

    pii cur = ans;
    while(!(cur.first == 0 && cur.second == 0)) {
        ret.push_back(prevA[cur.first][cur.second].first);
        cur = prevA[cur.first][cur.second].second;
    }
    reverse(ret.begin(), ret.end());

    for(int i : ret) {
        if(i == 1) {
            cout << "fill A\n";
        }
        else if(i == 2) {
            cout << "fill B\n";
        }
        else if(i == 3) {
            cout << "chug A\n";
        }
        else if(i == 4) {
            cout << "chug B\n";
        }
        else if(i == 5) {
            cout << "pour A B\n";
        }
        else {
            cout << "pour B A\n";
        }
    }

    return 0;
}