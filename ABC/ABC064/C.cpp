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
    int N;
    cin >> N;
    vector<int> A(9, 0);
    int a;
    REP(i, N){
        cin >> a;
        a = min(a, 3200);
        a /= 400;
        A[a]++;
    }
    int ans = 0;
    REP(i, 8) if(A[i] > 0) ans++;
    if (ans == 0) {ans = 1; A[8]--;}
    cout << ans << " " << (ans + A[8]) << endl;
    

    return 0;
}
