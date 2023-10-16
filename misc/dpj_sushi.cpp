#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 305;
//const ll BFN = (ll)1e17;
const ll MOD = 1000000007;
const int BFN = (int)1e9;
int n, k; long double num;
long double dp[MAXN][MAXN][MAXN];

long double fun(int cnt1, int cnt2, int cnt3) {
    if(dp[cnt1][cnt2][cnt3] >= 0.0) return dp[cnt1][cnt2][cnt3];
    if(cnt1 < 0 || cnt2 < 0 || cnt3 < 0) return (long double) 0.0;
    if(cnt1 == 0 && cnt2 == 0 && cnt3 == 0) return (long double) 0.0;

    long double c1 = (long double)cnt1, c2 = (long double)cnt2, c3 = (long double)cnt3; 
    dp[cnt1][cnt2][cnt3] = (long double) 0.0;
    if(cnt1 != 0) dp[cnt1][cnt2][cnt3] += (c1/num) * (fun(cnt1-1, cnt2, cnt3) + (long double)1);
    if(cnt2 != 0) dp[cnt1][cnt2][cnt3] += (c2/num) * (fun(cnt1+1, cnt2-1, cnt3) + (long double)1);
    if(cnt3 != 0) dp[cnt1][cnt2][cnt3] += (c3/num) * (fun(cnt1, cnt2+1, cnt3-1) + (long double)1);
    if(cnt1 + cnt2 + cnt3 != n) dp[cnt1][cnt2][cnt3] += (num - c1 - c2 - c3)/num;
    if(n - cnt1 - cnt2 - cnt3 != 0) {
        dp[cnt1][cnt2][cnt3] *= num/((long double)c1 + c2 + c3);
    }
    return dp[cnt1][cnt2][cnt3];
}

void sol() {
    for(int i = 0; i < MAXN; i++) {
        for(int j = 0; j < MAXN; j++) {
            for(int k = 0; k < MAXN; k++) {
                dp[i][j][k] = (long double)-1.0;
            }
        }
    }

    cin >> n; num = (long double)n;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for(int i = 1; i <= n; i++) {
        cin >> k;
        if(k == 1) cnt1++;
        else if(k == 2) cnt2++;
        else cnt3++;
    }

    fun(cnt1, cnt2, cnt3);
    cout << fixed << setprecision(11) << dp[cnt1][cnt2][cnt3] << "\n";
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}