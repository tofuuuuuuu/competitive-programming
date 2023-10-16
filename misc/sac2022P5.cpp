#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
vector<int> v;
int ans[MAXN];

bool cmp1(int a, int b) {
    return ans[a] < ans[b];
}

bool cmp2(int a, int b)
{
    cout << "c " << a << " " << b << endl;
    int higher; 
    cin >> higher;
    return higher != a;
}

int main ()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, q1, q2, t;
    cin >> n >> q1 >> q2 >> t;
    for(int i = 1; i <= q2 && i <= n; i++) {
        cout << "h " << i << endl; 
        cin >> ans[i];
        v.push_back(i);
    }
    sort(v.begin(), v.end(), cmp1);

    for(int i = q2+1; i <= n; i++) {
        v.insert(upper_bound(v.begin(), v.end(), i, cmp2), i);
    }   

    int cnt = 1;
    for(auto i : v) {
        ans[i] = cnt;
        cnt++;
    }

    cout << "! ";
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}