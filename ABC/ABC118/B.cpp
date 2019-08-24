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
    int N, M;
    cin >> N >> M;
    vector<int> v(M, 0);
    REP(i, N){
        int K;
        cin >> K;
        int tmp;
        REP(j, K) {
            cin >> tmp;
            v[--tmp]++;
            }
    }
    int ans = 0;
    REP(i, M) if(v[i] == N) ans++;
    cout << ans << endl;

    return 0;
}