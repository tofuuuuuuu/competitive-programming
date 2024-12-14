#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

const int MAXN = 1500000;
const int LEN = 32;
const ll BFN = (ll)1e19;
//const int BFN = (int)1e9;
int n, q, k;

struct Trie {
    int trie[MAXN][2];
    int t, nxtFree, idx;
    vector<int> s;

    void init() {
        nxtFree = 1;
        for(int i = 0; i < MAXN; i++) {
            for(int j = 0; j < 2; j++) {
                trie[i][j] = -1;
            }
        }
        for(int i = 0; i < LEN; i++) {
            s.push_back(0);
        }
    }

    void add(int cur, int charPos) {
        if(charPos == s.size()) {
            if(trie[cur][0] == -1) {
                trie[cur][0] = idx;
                trie[cur][1] = idx;
            }
            return;
        }
        if(trie[cur][s[charPos]] != -1) {
            cur = trie[cur][s[charPos]];
            add(cur, charPos+1);
            return;
        }
        
        trie[cur][s[charPos]] = nxtFree; 
        cur = nxtFree;
        nxtFree++;
        return add(cur, charPos+1);
    }

    int find(int cur, int charPos) { 
        if(charPos == s.size()) {
            return trie[cur][0];
        }
        if(trie[cur][s[charPos]] != -1) {
            cur = trie[cur][s[charPos]];
            return find(cur, charPos+1);
        }
        
        cur = trie[cur][(s[charPos] ^ 1)];
        return find(cur, charPos+1);
    }
} tr;

void get_vector(int k) {
    for(int i = 0; i < LEN; i++) {
        tr.s[i] = k % 2;
        k /= 2;
    }
    reverse(tr.s.begin(), tr.s.end());
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    tr.init();

    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> k;
        get_vector(k);
        tr.idx = i;
        tr.add(0, 0);
    }

    int curXor = 0;
    for(int i = 0; i < q; i++) {
        cin >> k;
        curXor ^= k;
        get_vector(curXor);
        cout << tr.find(0, 0) << "\n";
    }

    return 0;
}