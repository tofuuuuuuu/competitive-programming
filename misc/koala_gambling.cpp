#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

void fun() {
    int n, a; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());

    if(n % 2 == 1) {
        cout << arr[0];
        for(int i = 1; i < n; i++) {
            cout << " " << arr[i];
        }
        cout << "\n";
        return;
    }

    if(arr[0] == arr[n-1]) {
        cout << "-1\n";
        return;
    }

    cout << arr[n-1];
    for(int i = 0, j = n-2; i < j; i++, j--) {
        cout << " " << arr[i] << " " << arr[j];
    }
    cout << " " << arr[n/2 - 1] << "\n";
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