#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

void fun() {
    string s; int k; cin >> s >> k;
    int n = s.length();
    int next[n][10];

    int last[10];
    last[0] = n;
    for(int i = 1; i <= 9; i++) last[i] = -1;
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j <= 9; j++) next[i][j] = last[j];
        last[s[i] - '0'] = i;
    }

    vector<char> fron;
    vector<char> bac;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < s[i] - '0'; j++) {
            if(next[i][j] == -1) continue;
            int nextPos = next[i][j];
            int dist = nextPos - i;
            if(dist > k) continue;

            k -= dist;
            while(i < nextPos) {
                bac.push_back(s[i]);
                i++;
            }
            break;
        }
        if(i != n) fron.push_back(s[i]);
    }
    sort(bac.begin(), bac.end());

    for(char c : fron) {
        cout << c;
    }
    for(char c : bac) {
        cout << c;
    }
    cout << "\n";
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; 
    for(int i = 0; i < t; i++) {
        fun();
    }

    return 0;
}