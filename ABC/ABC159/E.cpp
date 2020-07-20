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
    int H, W, K;
    cin >> H >> W >> K;
    vector<vector<int>> s(H, vector<int>(W, 0));
    vector<string> ss(H);
    REP(i, H) cin >> ss[i];
    REP(i, H) REP(j, W) s[i][j] = ss[i][j] - '0';

    int ans = W * H;
    REP(i, 1<<(H-1)){
        vector<int> sp(H, 0);
        int ii = 0;
        REP(j, H){
            sp[j] = ii;
            if (((i >> j) & 1) == 1) ii++; 
        }
        ii++;
        //REP(j, H) cout << sp[j];
        //cout << endl;
        vector<int> acc(ii, 0), tmp(ii, 0);
        int ans_tmp = ii - 1;
        REP(j, W){
            REP(k, H) acc[sp[k]] += s[k][j];
            
            bool hoge = false;
            REP(k, ii) if (acc[k] > K) {ans_tmp = H * W; hoge = true;}
            if (hoge) break;

            hoge = true;
            REP(k, ii) hoge &= (acc[k] + tmp[k] <= K);
            if (hoge){
                REP(k, ii) {tmp[k] += acc[k]; acc[k] = 0;}
            }else{
                REP(k, ii) {tmp[k] = acc[k]; acc[k] = 0;}
                ans_tmp++;
                //cout << j;
            }
        }
        //REP(j, H) cout << sp[j];
        //cout << " " << ans_tmp << endl;
        ans = min(ans, ans_tmp);
    }

    cout << ans << endl;

    return 0;
}
