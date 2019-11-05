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
    string s;
    cin >> s;
    int n = s.size();
    bool is = true;
    REP(i, n){
        if (i % 2 == 0){
            if (s[i] == 'L') is = false;
        }else{
            if (s[i] == 'R') is = false;
        }
    }
    string ans = is ? "Yes" : "No";
    cout << ans << endl;
    return 0;
}