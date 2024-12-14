#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

int find_subset(int l, int u, int a[], int n, int result[]) {
    pll w[n];
    for(int i = 0; i < n; i++) {
        w[i] = {a[i], i};
    }
    sort(w, w + n);

    ll sum = w[0].first; int left = 0; int right = 0;
    while(true) {
        if(sum < l) {
            right++;
            if(right == n) break;
            sum += w[right].first;
        }
        else if(sum > u){
            sum -= w[left].first;
            left++;
            if(left > right) break;
        }
        else{
            break;
        }
    }

    if(l <= sum && sum <= u) {
        int cnt = 0;
        for(int i = left; i <= right; i++) {
            result[cnt] = w[i].second;
            cnt++;
        }
        return right - left + 1;
    }

    return 0;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int result[100];
    int a[]{9, 2, 1, 9};
    int len = find_subset(7, 7, a, 4, result);
    cout << len << "\n";
    for(int i = 0; i < len; i++) {
        cout << result[i] << "\n";    
    }
    return 0;
}