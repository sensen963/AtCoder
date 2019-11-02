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
    ll N;
    cin >> N;

    ll n = sqrt(N);

    ll m = N;

    REP(i, n+1){
        if (i == 0) continue;
        if (N % i == 0){
            m = min(m, i + (N / i) - 2);
            //cout << m << " " << i << endl;
        }
    }
    cout << m << endl;

    return 0;
}