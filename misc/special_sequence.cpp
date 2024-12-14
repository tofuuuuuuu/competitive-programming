#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MAXN = 300005;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const ll BFN = (ll)1e16;
// const int BFN = (int)1e8;
int n, k, x;
vector<string> v;

bool cmp(string a, string b) {
    if(a.length() == b.length()) {
        return a.compare(b) < 0;
    }
    return a.length() < b.length();
}

int32_t main(){
    //freopen("main_file.in", "r", stdin);
	//freopen("main_file.out", "w", stdout);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string s1 = "70";
    string s2 = "2120";
    string s3 = "3148";
    string s4 = "3074003";
    string s5 = "953671853653";
    string s6 = "2118984413357";
    string s7 = "2121179131852";
    string s8 = "6328428636000007";
    string s9 = "99704560597822753";
    for(int i = 1; i <= 200; i++) {
        v.push_back(s1);
        v.push_back(s2);
        v.push_back(s3);
        v.push_back(s4);
        v.push_back(s5);
        v.push_back(s6);
        v.push_back(s7);
        v.push_back(s8);
        v.push_back(s9);

        s1 = s1 + "0";
        s2 = s2 + "0";
        s3 = s3 + "0";
        s4 = s4 + "0";
        s5 = s5 + "0";
        s6 = s6 + "0";
        s7 = s7 + "0";
        s8 = s8 + "0";
        s9 = s9 + "0";
    }

    s1 = "0";
    for(int i = 1; i <= 180; i++) {
        s2 = "";
        for(int j = 1; j <= 180; j++) {
            v.push_back("2"+s1+"1"+s1+"2"+s2);
            s2 = s2 + "0";
        }
        s1 = s1 + "0";
    }

    s1 = "9";
    for(int i = 1; i <= 180; i++) {
        s2 = "";
        for(int j = 1; j <= 180; j++) {
            v.push_back(s1+"7"+s2);
            s2 = s2 + "0";
        }
        s1 = s1 + "9";
    }

    sort(v.begin(), v.end(), cmp);
    // for(string s : v) {
    //     cout << s << "\n";
    // }

    cin >> n;
    cout << v[n-1] << "\n";

    return 0;
}