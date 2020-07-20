
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
#include <fstream>
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

    int A[3][3];
    REP(i, 3) REP(j, 3) cin >> A[i][j];
    int N;
    cin >> N;
    int b;
    REP(i, N){
        cin >> b;
        REP(j, 3) REP(k, 3) if (A[j][k] == b) A[j][k] = 0;
    }
    bool f = false;
    REP(i, 3){
        if (A[i][0] + A[i][1] + A[i][2] == 0) f = true;
    }
    REP(i, 3){
        if (A[0][i] + A[1][i] + A[2][i] == 0) f = true;
    }
    if (A[0][0] + A[1][1] + A[2][2] == 0) f = true;
    if (A[0][2] + A[1][1] + A[2][0] == 0) f = true;

    string ans = f ? "Yes" : "No";
    cout << ans << endl;
    return 0;
}

