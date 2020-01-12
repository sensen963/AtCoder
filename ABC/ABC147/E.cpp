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
    vector<vector<vector<bool>>> C(H+1, vector<vector<bool>>(W+1, vector<bool>(M, false)));
    C[0][0][0] = true;
    REP(i, H)REP(j, W)REP(k, M){
        if (C[i][j][k]){
            int tmp0 = k + abs(A[i][j] - B[i][j]);
            int tmp1 = abs(k - abs(A[i][j] - B[i][j]));
            //cout << i << " " << j << " " << tmp0 << " " << tmp1 << endl;
            C[i+1][j][tmp0] = true;
            C[i+1][j][tmp1] = true;
            C[i][j+1][tmp0] = true;
            C[i][j+1][tmp1] = true;
        } 
    }
    int ans = M;
    REP(i, M) if(C[H][W-1][i]) ans = min(ans, i);
    cout << ans << endl;

    return 0;
}