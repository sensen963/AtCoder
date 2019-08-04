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
    int len = s.size();

    int r = 0;
    int b = 0;
    REP(i, len){
        if (s[i] == '0') r++;
        else b++;
    }

    cout << (2 *min(b, r)) << endl;
    return 0;
}
