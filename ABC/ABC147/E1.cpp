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

    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> B(H, vector<int>(W));
    REP(i, H)REP(j, W) cin >> A[i][j];
    REP(i, H)REP(j, W) cin >> B[i][j];
    int M = 80 * 80 * 5;
    vector<vector<set<int>>> C(H+1, vector<set<int>>(W+1));
    C[0][0].insert(0);
    REP(i, H)REP(j, W)for(auto iter : C[i][j]){
        int tmp0 = iter + abs(A[i][j] - B[i][j]);
        int tmp1 = abs(iter - abs(A[i][j] - B[i][j]));
        C[i+1][j].insert(tmp0);
        C[i+1][j].insert(tmp1);
        C[i][j+1].insert(tmp0);
        C[i][j+1].insert(tmp1);
    }
    int ans = *C[H][W-1].begin();
    cout << ans << endl;

    return 0;
}