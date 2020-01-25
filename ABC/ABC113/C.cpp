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


int main() {

    int N, M;
    cin >> N >> M;

    int p, y;
    vector<vector<int>> v(M, vector<int>(2));
    vector<vector<int>> v1(M, vector<int>(2));
    vector<P> pp(M);
    REP(i, M){
        cin >> v[i][0] >> v[i][1];
        v1[i][0] = v[i][0];
        v1[i][1] = v[i][1];
    }
    sort(v1.begin(), v1.end(), [](vector<int> a, vector<int> b){return a[1] < b[1];});

    vector<int> r(N+1, 1);
    map<int, int> m; 
    REP(i, M){
        m[v1[i][1]] = r[v1[i][0]]++;
    }
    REP(i, M){
        printf("%06d", v[i][0]);
        printf("%06d\n", m[v[i][1]]);
    } 



    return 0;
}