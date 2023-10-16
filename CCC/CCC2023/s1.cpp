#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int a[3][n+1];
    
    ll totalCnt = 0;
    for(int i = 1; i <= 2; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) totalCnt++;
        }
    }
    totalCnt = totalCnt * 3;

    for(int i = 1; i <= 2; i++) {
        for(int j = 2; j <= n; j++) {
            if(a[i][j] == 1 && a[i][j-1] == 1)  totalCnt -= 2;
        }
    }

    for(int i = 1; i <= n; i+=2) {
        if(a[1][i] == 1 && a[2][i] == 1) totalCnt-=2;
    }

    cout << totalCnt << "\n";

    return 0;
}