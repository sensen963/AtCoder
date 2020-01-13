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

    vector<int> p(M);
    vector<string> S(M);
    REP(i, M) {cin >> p[i] >> S[i]; p[i]--;}

    vector<bool> ok(N, false);
    vector<int> b(N, 0);
    int a = 0, c = 0;
    REP(i, M){
        if (!ok[p[i]]){
            if (S[i] == "AC"){
                ok[p[i]] = true;
                a++;
            }else b[p[i]]++;
        }
    }
    REP(i, N)if(ok[i]) c += b[i];
    cout << a << " " << c << endl;


    return 0;
}