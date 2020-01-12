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

    vector<string> day{"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    REP(i, 7){
        if (day[i] == s) {
            i = 7 - i;
            cout << i << endl;
            break;
        }
    }

    return 0;
}
