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

    int N;
    cin >> N;
    vector<int> C(N, 0), S(N, 0) ,F(N, 0);
    REP(i, N - 1) cin >> C[i] >> S[i] >> F[i];

    REP(i, N){
        int tmp = 0;
        int clock = 0;
        rep(j, i, N - 1){
            if (clock <= S[j]){
                clock = S[j] + C[j];
            }
            else{
                int hoge = (int)ceil((double)clock / (double)F[j]);
                clock = F[j] * hoge + C[j];
            }
        }
        cout << clock << endl;
    }

    return 0;
}