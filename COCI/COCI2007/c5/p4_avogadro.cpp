#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int> 

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;    
    unordered_set<int> del;
    unordered_map<int, vector<int>> idx1;
    unordered_map<int, vector<int>> idx2;
    unordered_map<int, vector<int>> idx3;
    int a1[n];
    int a2[n]; int cnt2[n+1];
    int a3[n]; int cnt3[n+1];

    memset(cnt2, 0, sizeof(cnt2));
    memset(cnt3, 0, sizeof(cnt3));
    for(int i = 0; i < n; i++) {
        cin >> a1[i];
        idx1[a1[i]].push_back(i);
    }
    for(int i = 0; i < n; i++) {
        cin >> a2[i]; cnt2[a2[i]]++;
        idx2[a2[i]].push_back(i);
    }
    for(int i = 0; i < n; i++) {
        cin >> a3[i]; cnt3[a3[i]]++;
        idx3[a3[i]].push_back(i);
    }

    queue<int> delQ;
    for(int num = 1; num <= n; num++) {
        if(cnt2[num] == 0) {
            int i1 = idx1[num][0];
            if(del.find(i1) == del.end()) {
                delQ.push(i1);
                del.insert(i1);
            }

            for(int i : idx3[num]) {
                if(del.find(i) != del.end()) continue;
                delQ.push(i);
                del.insert(i);
            }
        }

        if(cnt3[num] == 0) {
            int i1 = idx1[num][0];
            if(del.find(i1) == del.end()) {
                delQ.push(i1);
                del.insert(i1);
            }

            for(int i : idx2[num]) {
                if(del.find(i) != del.end()) continue;
                delQ.push(i);
                del.insert(i);
            }
        }
    }

    while(!delQ.empty()) {
        int i = delQ.front(); delQ.pop();
        cnt2[a2[i]]--; cnt3[a3[i]]--;

        int n1 = a1[i];
        for(int i : idx2[n1]) {
            if(del.find(i) != del.end()) continue;
            delQ.push(i);
            del.insert(i);
        }
        for(int i : idx3[n1]) {
            if(del.find(i) != del.end()) continue;
            delQ.push(i);
            del.insert(i);
        }

        if(cnt2[a2[i]] == 0) {
            int i1 = idx1[a2[i]][0];
            if(del.find(i1) == del.end()) {
                delQ.push(i1);
                del.insert(i1);
            }

            for(int i : idx3[a2[i]]) {
                if(del.find(i) != del.end()) continue;
                delQ.push(i);
                del.insert(i);
            }
        }
        if(cnt3[a3[i]] == 0) {
            int i1 = idx1[a3[i]][0];
            if(del.find(i1) == del.end()) {
             delQ.push(i1);
                del.insert(i1);
            }

            for(int i : idx2[a3[i]]) {
                if(del.find(i) != del.end()) continue;
                delQ.push(i);
                del.insert(i);
            }
        }
    }

    cout << del.size() << "\n";
    
    return 0;
}