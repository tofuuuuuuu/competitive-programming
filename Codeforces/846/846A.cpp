#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    for(int cases = 0; cases < t; cases++) {
        int n; cin >> n;
        int evenCnt = 0, oddCnt = 0;
        vector<int> oddP;
        vector<int> evenP;
        for(int i = 1; i <= n; i++) {
            int k; cin >> k;
            if(k % 2 == 0) {
                evenCnt++;
                evenP.push_back(i);
            }
            else {
                oddCnt++;
                oddP.push_back(i);
            }
        }

        if(oddCnt >= 3) {
            cout << "YES" << "\n";
            cout << oddP[0] << " " << oddP[1] << " " << oddP[2] << "\n";
        } 
        else if(oddCnt >= 1 && evenCnt >= 2) {
            cout << "YES" << "\n";
            cout << oddP[0] << " " << evenP[0] << " " << evenP[1] << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}