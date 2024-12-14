#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 100005;
const ll MOD = 1000000007;
//const ll BFN = (ll)1e17;
const int BFN = (int)1e9;
int n, q, h;
int v [MAXN][2];

int findSample(int n, int confidence[], int host[], int protocol[]) {
    for(int i = 0; i < n; i++) {
        v[i][1] = confidence[i];
    }

    for(int i = n-1; i > 0; i--) {
        h = host[i];
        if(protocol[i] == 0) {
            v[h][1] += v[i][0];
            v[h][0] += max(v[i][1], v[i][0]);
        }
        else if(protocol[i] == 1) {
            v[h][1] = max(v[h][1] + max(v[i][0], v[i][1]), v[h][0] + max(v[i][0], v[i][1]));
            v[h][0] += v[i][0];
        }
        else {
            v[h][1] = max(v[h][1] + v[i][0], v[h][0] + v[i][1]);
            v[h][0] += v[i][0];
        }
    }

    int ans = max(v[0][1], v[0][0]);
    return ans;
}

void sol() { 
    
}

int main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sol();

    return 0;
}