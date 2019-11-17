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
    int N;
    cin >> N;
    vector<double> x(N), y(N);
    REP(i, N){
        cin >> x[i] >> y[i];
    }

    vector<vector<double>> m(N, vector<double>(N, 0));
    double s = 0;
    REP(i, N)REP(j, N){
        m[i][j] = sqrt((x[i] - x[j]) *(x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        s += m[i][j];
    }
    s /= N;
    //cout << s << endl;
    printf("%.8f\n", s);
    return 0;
}