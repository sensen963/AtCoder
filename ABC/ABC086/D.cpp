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

#define ps(ss, i, j, ii, jj) ss[i][j] - ss[i][jj] - ss[ii][j] + ss[ii][jj]

int main() {

    int N, K;
    cin >> N >> K;
    int K2 = 2 * K;
    vector<vector<int>> s(K2, vector<int>(K2, 0));
    vector<vector<int>> s1(K2, vector<int>(K2, 0));
    int a, b;
    char c;
    int cb = 0, cw = 0;
    REP(i, N){
        cin >> a >> b >> c;
        if (c == 'B') {s[a%K2][b%K2]++; cb++;}
        else {s1[a%K2][b%K2]++; cw++;}
    }
    vector<vector<int>> sb(K2+1, vector<int>(K2+1, 0));
    vector<vector<int>> sw(K2+1, vector<int>(K2+1, 0));
    REP(i, K2) REP(j, K2){
        sb[i+1][j+1] = s[i][j] + sb[i][j+1] + sb[i+1][j] - sb[i][j];
        sw[i+1][j+1] = s1[i][j] + sw[i][j+1] + sw[i+1][j] - sw[i][j];
    }
    int tmp, tmp1, ans = 0;
    rep(i, K + 1,  K2 + 1) rep(j, K + 1, K2 + 1){
        tmp = ps(sb, K2, j, i, j - K) + ps(sb, i, K2, i - K, j) + ps(sb, i, j - K, i - K, 0) + ps(sb, i - K, j, 0, j - K);
        tmp1 = ps(sw, K2, j, i, j - K) + ps(sw, i, K2, i - K, j) + ps(sw, i, j - K, i - K, 0) + ps(sw, i - K, j, 0, j - K);
        ans = max(ans, tmp + cw - tmp1);
        ans = max(ans, tmp1 + cb - tmp);
    }

    cout << ans << endl;

    return 0;
}