#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 1000006;
int p[MAXN];
int r[MAXN];

int find(int v) {
    if(p[v] != v) p[v] = find(p[v]);
    return p[v];
}

void merge(int a, int b) {
    int p1 = find(a);
    int p2 = find(b);
    if(p1 == p2) return;

    if(r[p1] == r[p2]) {
        p[p2] = p1;
        r[p1]++;
    }
    else if(r[p1] > r[p2]) {
        p[p2] = p1;
    }
    else {
        p[p1] = p2;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        r[i] = 0;
    }
    vector<int> a[n+1];
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i].push_back(x);
        a[x].push_back(i);
        merge(i, x);
    }   

    unordered_set<int> totalCnt;
    for(int i = 1; i <= n; i++) {
        int f = find(i);
        if(totalCnt.find(f) == totalCnt.end()) totalCnt.emplace(find(i));
    }
    int total = totalCnt.size();

    int idxMp[n+1];
    for(int qCnt = 1; qCnt <= q; qCnt++) {
        int ans = 0;
        int qAmt;
        cin >> qAmt;
        int qA[qAmt];
        unordered_set<int> qSet;
        unordered_set<int> affected;
        bool done[qAmt];
        for(int i = 0; i < qAmt; i++) {
            cin >> qA[i];
            qSet.emplace(qA[i]);
            idxMp[qA[i]] = i;
            done[idxMp[qA[i]]] = false;

            int f1 = find(qA[i]);
            if(affected.find(f1) == affected.end()) affected.emplace(f1);
        }
        
        for(int v : qA) {
            if(done[idxMp[v]]) continue;
            int curV = v;
            done[idxMp[v]] = true;
            if(qSet.find(a[curV][0]) != qSet.end() && !done[idxMp[a[curV][0]]]) {
                curV = a[curV][0];
                done[idxMp[curV]] = true;
                while(true) {
                    if(qSet.find(a[curV][0]) != qSet.end() && !done[idxMp[a[curV][0]]]) {
                        curV = a[curV][0];
                        done[idxMp[curV]] = true;
                    }
                    else if(qSet.find(a[curV][1]) != qSet.end() && !done[idxMp[a[curV][1]]]) {
                        curV = a[curV][1];
                        done[idxMp[curV]] = true;
                    }
                    else {
                        break;
                    }
                }
            }
            int endV = curV;
            
            if(endV == a[v][1]) continue;

            curV = v;
            if(qSet.find(a[curV][1]) != qSet.end() && !done[idxMp[a[curV][1]]]) {
                curV = a[curV][1];
                done[idxMp[curV]] = true;
                while(true) {
                    if(qSet.find(a[curV][0]) != qSet.end() && !done[idxMp[a[curV][0]]]) {
                        curV = a[curV][0];
                        done[idxMp[curV]] = true;
                    }
                    else if(qSet.find(a[curV][1]) != qSet.end() && !done[idxMp[a[curV][1]]]) {
                        curV = a[curV][1];
                        done[idxMp[curV]] = true;
                    }
                    else {
                        break;
                    }
                }
            }
            ans++; 
        }

        cout << ans + total - affected.size() << "\n";
    }

    return 0;
}