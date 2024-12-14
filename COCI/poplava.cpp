#include <bits/stdc++.h>
using namespace std;

int main ()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    long n;
    long x;
    cin >> n >> x;

    if(x > (n-1)*(n-2)/2) {
        cout << "-1"; 
        return 0;
    }

    long cur = (n-2)*(n-1)/2 - x;
    int removed[n];

    int cnt = 0;
    cout << n << " ";
    for(int i = 1; i <= n-2; i++) {
        if(cur - (n-1 - i) >= 0) {
            cur -= (n-1 - i);
            removed[cnt] = i;
            cnt++;
        }
        else {
            cout << i << " ";
        }
    }
    cout << (n-1) << " ";

    cnt--;
    while(cnt >= 0) {
        cout << removed[cnt] << " ";
        cnt--;
    }
    cout << "\n";

    return 0;
}