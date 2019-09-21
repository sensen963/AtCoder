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

    int N;
    cin >> N;

    vector<int> A(N), B(N), C(N-1);

    REP(i, N) {
        cin >> A[i];
        A[i]--;
    }
    REP(i, N) cin >> B[i];
    REP(i, N-1) cin >> C[i];

    int tmp = -3, sum = 0;
    REP(i, N){
        sum += B[A[i]];
        if (tmp + 1 == A[i]) sum += C[tmp];
        tmp = A[i];
    }
    cout << sum << endl;
    return 0;
}