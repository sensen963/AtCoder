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

int main() {

    int N, M;
    cin >> N;
    vector<string> s(N);
    REP(i, N) cin >> s[i];
    cin >> M;
    vector<string> t(M);
    REP(i, M) cin >> t[i];

    int ans = 0;
    int score = 0;
    string tmp;
    REP(i, N){
        score = 0;
        tmp = s[i];
        REP(j, N) if (tmp == s[j]) score++;
        REP(j, M) if (tmp == t[j]) score--;
        ans = max(ans, score);
    }
    cout << ans << endl;

    return 0;
}