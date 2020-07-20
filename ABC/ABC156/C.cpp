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
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {

    int N;
    cin >> N;
    vector<int> x(N);
    double m = 0;
    REP(i, N) {
        cin >> x[i];
        m += x[i];
    }
    m /= (double)N;
    vector<int> y;
    y.push_back(ceil(m-1));
    y.push_back(ceil(m));
    y.push_back(floor(m));
    y.push_back(floor(m+1));
    ll tmp = 1e10;
    REP(i, 4){
        ll sum = 0;
        REP(j, N){
            sum += (y[i] - x[j]) * (y[i] - x[j]);
        }
    tmp = min(tmp, sum);
    }

    cout << tmp << endl;


    return 0;
}
