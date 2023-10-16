#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int MAXN = 200000;
int a[MAXN];

void fun(int l, int r) {
    if(l == r) {
        cout << a[l] << " ";
        return;
    }
        
    int len = r - l + 1;
    int p1 = l;
    int p2 = l + len/3;
    int p3 = l + 2*len/3;

    fun(p3, r);
    fun(p1, p2 - 1);
    fun(p2, p3 - 1);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    fun(1, n);

    return 0;
}