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
typedef pair<int, int> P;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {

    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    REP(i, H) cin >> S[i];

    vector<vector<int>> M(H, vector<int>(W, -1));

    queue<P> q;
    M[0][0] = 1; 
    q.push(P(0, 0));
    while(q.size() > 0){
        P tmp = q.front();
        if (tmp.first < H - 1 && S[tmp.first + 1][tmp.second] == '.' && M[tmp.first + 1][tmp.second] < 0){
            M[tmp.first + 1][tmp.second] = M[tmp.first][tmp.second] + 1;
            q.push(P(tmp.first + 1, tmp.second));
        }

        if (tmp.second < W - 1 && S[tmp.first][tmp.second + 1] == '.' && M[tmp.first][tmp.second + 1] < 0){
            M[tmp.first][tmp.second + 1] = M[tmp.first][tmp.second] + 1;
            q.push(P(tmp.first, tmp.second + 1));
        }

        if (tmp.first > 0 && S[tmp.first - 1][tmp.second] == '.' && M[tmp.first - 1][tmp.second] < 0){
            M[tmp.first - 1][tmp.second] = M[tmp.first][tmp.second] + 1;
            q.push(P(tmp.first - 1, tmp.second));
        }

        if (tmp.second > 0 && S[tmp.first][tmp.second - 1] == '.' && M[tmp.first][tmp.second - 1] < 0){
            M[tmp.first][tmp.second - 1] = M[tmp.first][tmp.second] + 1;
            q.push(P(tmp.first, tmp.second - 1));
        }

        q.pop();
        //if (tmp.first == H - 2 && tmp.second == W - 1) break;
        //if (tmp.first == H - 1 && tmp.second == W - 2) break;
    }

    if (M[H-1][W-1] < 0){
        cout << -1 << endl;
        return 0;
    }

    int cnt = 0;
    REP(i, H) REP(j, W) if (S[i][j] == '.') cnt++;
    int ans = cnt - M[H-1][W-1];

    cout << ans << endl;

    
    return 0;
}