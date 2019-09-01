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
    int s;
    cin >> s;

    set<int> a;
    a.insert(s);
    int i = 1;
    int tmp = s;
    while(true){
        i++;
        if (tmp % 2 == 0) tmp /= 2;
        else tmp = 3 * tmp + 1;
        if (a.find(tmp) != a.end()) {
            cout << i << endl;
            break;
        }
        a.insert(tmp);
    }

    return 0;
}