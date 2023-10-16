#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

int getDif(int msk, int a) {
    int b = msk % 4; int c = msk / 4;
    int cnt []{0, 0, 0, 0};
    cnt[a]++; cnt[b]++; cnt[c]++;
    if(cnt[1] + cnt[0] == 3 || cnt[2] + cnt[0] == 3 || cnt[3] + cnt[0] == 3) return 1;
    if(cnt[1] + cnt[0] == 2 || cnt[2] + cnt[0] == 2 || cnt[3] + cnt[0] == 2) return 2;
    else return 3;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n; 
    int a[n+1]; 
    string aS; cin >> aS;
    for(int i = 1; i <= n; i++) {
        if(aS[i-1] == 'M') a[i] = 1;
        else if(aS[i-1] == 'F') a[i] = 2;
        else a[i] = 3;
    }

    int dp[2][4*4][4*4];
    for(int i = 0; i < 2; i++) {
        for(int msk1 = 0; msk1 < 4*4; msk1++) {
            for(int msk2 = 0; msk2 < 4*4; msk2++) {
                dp[i][msk1][msk2] = -100000000;
            }
        }
    }
    dp[0][0][0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int msk1 = 0; msk1 < 4*4; msk1++) {
            for(int msk2 = 0; msk2 < 4*4; msk2++) {
                int dif1 = getDif(msk1, a[i]);
                int dif2 = getDif(msk2, a[i]);
                int newState1 = msk1/4 + a[i]*4;
                int newState2 = msk2/4 + a[i]*4;
                dp[1][newState1][msk2] = max(dp[1][newState1][msk2], dp[0][msk1][msk2] + dif1);
                dp[1][msk1][newState2] = max(dp[1][msk1][newState2], dp[0][msk1][msk2] + dif2);
            }
        }

        swap(dp[1], dp[0]);
    }

    int ans = 0;
    for(int msk1 = 0; msk1 < 4*4; msk1++) {
        for(int msk2 = 0; msk2 < 4*4; msk2++) {
            ans = max(ans, dp[0][msk1][msk2]);
        }
    }

    cout << ans << "\n";
    
    return 0;
}