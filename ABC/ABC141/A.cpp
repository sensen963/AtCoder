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
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {
    vector<string> v;
    v.push_back("Sunny");
    v.push_back("Cloudy");
    v.push_back("Rainy");

    string s, ans;
    cin >> s;
    REP(i, 3){
        if (v[i] == s) ans = v[(i + 1) % 3];
    }
    cout << ans << endl;

    return 0;
}