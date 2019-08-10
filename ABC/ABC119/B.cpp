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
    int N;
    cin >> N;
    double ans = 0;
    double m;
    string s;
    REP(i, N){
        cin >> m >> s;
        if (s[0] == 'J') ans += m;
        else ans += m * 380000.0;
    }
    cout << ans << endl;

    return 0;
}
