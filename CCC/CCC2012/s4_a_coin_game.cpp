#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>

int power(int a, int b) {
    int ans = 1;
    for(int i = 0; i < b; i++) ans *= a;
    return ans;
}

int getDigit(int n, int k) {
    int a = n;
    a %= power(10, k);
    a /= power(10, k-1);
    return a;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    //2010000
    int dist[10000];
    int n;
    cin >> n;
    while(n != 0) {;
        memset(dist, 0, sizeof(dist));
        int goals = 0;
        int st = 0;
        for(int i = 1; i <= n; i++) {
            int c;
            cin >> c;

            int a = 1;
            a *= power(10, c-1);
            a *= i;
            st += a;
        }
        int urmom = 1;
        for(int i = 1; i <= n; i++) {
            goals += i*urmom;
            urmom *= 10;
        }

        int cur[n+1];
        memset(cur, 0, sizeof(cur));

        queue<int> q;
        dist[st] = 1;
        q.push(st);
        while(!q.empty()) {
            if(dist[goals] != 0) break;
            int curs = q.front();
            q.pop();

            memset(cur, 0, sizeof(cur));
            for(int i = n; i >= 1; i--) {
                int curPlace = getDigit(curs, i);
                cur[curPlace] = i;
            }

            if(cur[1] != 0) {
                if(cur[1] < cur[2] || cur[2] == 0) {
                    int news = curs + power(10, cur[1]-1);
                    if(dist[news] == 0) {
                        dist[news] = dist[curs] + 1;
                        q.push(news);
                    }
                }
            } 
            for(int i = 2; i < n; i++) {
                if(cur[i] == 0) continue;
                if(cur[i] < cur[i-1] || cur[i-1] == 0) {
                    int news = curs - power(10, cur[i]-1);
                    if(dist[news] == 0) {
                        dist[news] = dist[curs] + 1;
                        q.push(news);
                    }
                }
                if(cur[i] < cur[i+1] || cur[i+1] == 0) {
                    int news = curs + power(10, cur[i]-1);
                    if(dist[news] == 0) {
                        dist[news] = dist[curs] + 1;
                        q.push(news);
                    }
                }
            }
            if(cur[n] != 0) {
                if(cur[n] < cur[n-1] || cur[n-1] == 0) {
                    int news = curs - power(10, cur[n]-1);
                    if(dist[news] == 0) {
                        dist[news] = dist[curs] + 1;
                        q.push(news);
                    }
                }
            }
        }

        if(dist[goals] == 0) {
            cout << "IMPOSSIBLE" << "\n";
        }
        else {
            cout << dist[goals]-1 << "\n";
        }

        cin >> n;
    }

    return 0;
}