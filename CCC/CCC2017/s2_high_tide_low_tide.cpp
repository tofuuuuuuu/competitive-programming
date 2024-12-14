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
    
    int n; cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        int k; cin >> k; a.push_back(k);
    }
    sort(a.begin(), a.end());
    
    int mid = 0;
    if(n % 2 == 0) {
        mid = n/2 - 1;
    }
    else {
        mid = n/2;
    }

    vector<int> low;
    vector<int> high;
    for(int i = mid; i >= 0; i--) {
        low.push_back(a[i]);
    }
    for(int i = mid+1; i < n; i++) {
        high.push_back(a[i]);
    }
    
    for(int i = 0; i < low.size() && i < high.size(); i++) {
        cout << low[i] << " " << high[i] << " ";
    }
    if(low.size() > high.size()) cout << low[low.size()-1];
    cout << "\n";
    
    return 0;
}