#include <bits/stdc++.h>
using namespace std;

int main ()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    long long n, c;
    cin >> n >> c;
    long long p[2*n];
    long long freq[c];
    memset(freq, 0, sizeof(freq));
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i + n] = p[i] + c;
        freq[p[i]]++; 
    }
    sort(p, p+2*n);

    long long cnt = 0;
    for(long long l = 0, r = 0; l < n; l++) {
        while(p[r+1] <= p[l] + c/2) r++;

        cnt += (r-l)*(r-l-1)/2;
    }

    if(c % 2 == 0) {
        for(int i = 0; i < c/2; i++) {
            long long a = freq[i]; long long b = freq[i + c/2];
            long long sa = 0; long long sb = 0;
            for(int j = 1; j <= a; j++) sa += (b+a-j)*(b+a-j-1)/2;
            for(int j = 1; j <= b; j++) sb += (a+b-j)*(a+b-j-1)/2;

            cnt += (a+b)*(a+b-1)*(a+b-2)/6 - sa - sb;
        }
    }
    
    cout << (n)*(n-1)*(n-2)/6 - cnt;
    
    return 0;
}