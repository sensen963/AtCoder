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

    int N, M, X;
    cin >> N >> M >> X;
    vector<int> A(M);
    REP(i, M) cin >> A[i];

    int a = 0, b = 0;
    REP(i, M){
        if (A[i] < X) a++;
        else b++;
    }

    cout << min(a, b) << endl;

    return 0;
}
