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
typedef pair<int, int> P;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {

    int n;
    cin >> n;

    vector<int> x(n), y(n);
    REP(i, n) {
        cin >> x[i];
        y[i] = x[i];
    }
    sort(x.begin(), x.end());

    int mid1 = x[n / 2 - 1];
    int mid2 = x[n / 2];
    REP(i, n){
        if (y[i] < mid2) cout << mid2 << endl;
        else cout << mid1 << endl;
    }


    return 0;
}
