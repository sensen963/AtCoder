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
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    int sum = 0;
    REP(i, N){
        cin >> a[i];
        sum += a[i];
    }
    int cnt = 0;
    REP(i, N) if (a[i] * 4 * M >= sum) cnt++;
    string ans = (cnt >= M) ? "Yes" :"No";
    cout << ans << endl;

    return 0;
}