#include <bits/stdc++.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define ll long long

int n, c, q;
set<int> s;

int query(int a, int b) {
    int d;
    cout << "? " << a << " " << b << endl;
    cin >> d;
    return d;
}

int findLast(int dist) {
    int l = 0; int r = c; int ans = 0;
    while(l <= r) {
        int m = (l+r)/2;
        int d = query(0, m);
        if(m - d == dist) {
            ans = m;
            r = m-1;
        }
        else if(m - d < dist){
            l = m + 1;
        }
        else {
            r = m-1;
        }
    }

    return ans;
}

void find(int l, int r) {
    if(s.size() == n) return;
    if(l + 2 >= r) return;

    int m = (l+r)/2;
    int d = query(l, m);
    if(d == m-l) return;
    
    if(query(l, m + d) == 0) {
        s.insert(m+d);
        find(l, m+d);
        find(m+d, r);
    }
    else {
        s.insert(m-d);
        find(l, m-d);
        find(m-d, r);
    }
}

int main ()
{
    //1, 3, 5
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c >> q;

    int d = query(0, c);
    int last = findLast(c - d);
    int first = last - c + d;

    s.insert(first); s.insert(last);
    find(first, last);

    cout << "!";
    for(int i : s) {
        cout << " " << i;
    }
    cout << endl;
    return 0;
}