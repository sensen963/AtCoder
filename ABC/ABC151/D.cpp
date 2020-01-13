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
    int D = H * W;
    vector<string> S(H);
    REP(i, H) cin >> S[i];

    vector<vector<int>> d(D, vector<int>(D, 1e9));
    REP(i, H)REP(j, W){
        if(S[i][j] != '.')continue;
        for(int k = -1; k <= 1; k++)for(int l = -1; l <= 1; l++){
            if(k == 0 && l == 0){
                d[i*W+j][i*W+j] = 0;
            }
            else if(i+k >= 0 && i+k < H && j+l >= 0 && j+l < W && S[i+k][j+l] == '.'){
                if (k == 0 || l == 0){
                d[i*W+j][(i+k)*W+(j+l)] = 1;
                d[(i+k)*W+j+l][i*W+j] = 1;
                }

            }
        }
    }
    /*
    REP(i, D) {
        REP(j, D) cout << d[i][j] << " ";
        cout << endl;
    }
*/
    REP(l, D)REP(i, D)REP(j, D) d[i][j] = min(d[i][j], d[i][l] + d[l][j]);

    int tmp = 0;
    REP(i, D)REP(j, D){
        if (d[i][j] > tmp && d[i][j] < 1e9 ) tmp = d[i][j];
    }
    cout << tmp << endl;
/*
    REP(i, D) {
        REP(j, D) cout << d[i][j] << " ";
        cout << endl;
    }
*/

    return 0;
}