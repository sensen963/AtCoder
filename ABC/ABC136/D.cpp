#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <numeric>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {
    string s;
    cin >> s;

    ll len = s.size();
    vector<ll> con;
    REP(i, len - 1){
        if (s[i] == 'R' && s[i + 1] == 'L') con.push_back(i + 1);
    }
    con.push_back(len);
    vector<ll> ans(len, 0);
    ll j = 0;
    REP(i, len){
        if (s[i] == 'R'){
            if (i > con[j]) j++;
            ll tmp = con[j] - i;
            if (tmp % 2 == 0) ans[con[j]]++;
            else ans[con[j] - 1]++;
        }else{
            if (i >= con[j]) j++;
            ll tmp = i - con[j - 1];
            if (tmp % 2 == 0) ans[con[j - 1]]++;
            else ans[con[j - 1] - 1]++;
        }
        
    }
    REP(i, len) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
