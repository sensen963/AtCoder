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

    double N, T, A;
    cin >> N ;
    cin >> T >> A;
    vector<double> H(N);

    double tmp = 1e9, tmp2;
    int ans;
    REP(i, N){
        cin >> H[i];
        tmp2 = abs(T - H[i] * 0.006 - A);
        //cout << tmp2 << endl;
        if (tmp2 < tmp){
            tmp = tmp2;
            ans = i + 1;
        }
    }

    cout << ans << endl;

    return 0;
}