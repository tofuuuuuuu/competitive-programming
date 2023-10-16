#include <bits/stdc++.h>
#include <stack>
#include <queue>
#include <map>
using namespace std;
#define ll long long

int main ()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string str, explode;
    cin >> str >> explode;
    int sLen = str.length();
    int eLen = explode.length();

    stack<char> s;
    stack<char> s2;
    for(int i = 0; i < sLen; i++) {
        char cur = str[i];
        s.push(cur);

        int idx = eLen-1;
        while(idx >= 0 && explode[idx] == s.top()) {
            char c = s.top();
            s.pop();
            s2.push(c);
            idx--;
        }

        if(idx != -1) {
            while(!s2.empty()) {
                char c = s2.top();
                s2.pop();
                s.push(c);
            }
        }
        while(!s2.empty()) s2.pop();
    }

    if(s.empty()) {
        cout << "FRULA" << "\n";
        return 0;
    }

    while(!s.empty()) {
        s2.push(s.top());
        s.pop();
    }
    while(!s2.empty()) {
        cout << s2.top();
        s2.pop();
    }
    cout << "\n";
    return 0;
}