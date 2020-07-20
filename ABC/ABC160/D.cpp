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
typedef pair<int, int> P;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {

    int N, X, Y;
    cin >> N >> X >> Y;
    X--;
    Y--;
    vector<int> ans(N, 0);
    REP(i, N){
        vector<int> d(N, 1e5);
        d[i] = 0;
        queue<P> q;
        if (i > 0) q.push(P(i, i-1));
        if (i < N-1) q.push(P(i, i+1));
        if (i == X) q.push(P(i, Y));
        if (i == Y) q.push(P(i, X));
        while(q.size() > 0){
            P tmp = q.front();
            int t = tmp.second;
            d[tmp.second] = min(d[tmp.second], d[tmp.first] + 1);
            if (t > 0 && d[t-1] == 1e5) q.push(P(t, t-1));
            if (t < N-1 && d[t+1] == 1e5) q.push(P(t, t+1));
            if (t == X && d[Y] == 1e5) q.push(P(t, Y));
            if (t == Y && d[X] == 1e5) q.push(P(t, X));
            q.pop();
        }
        REP(i, N) ans[d[i]]++;
    }
    REP(i, N-1) cout << (ans[i+1] / 2) << endl;
    return 0;
}
