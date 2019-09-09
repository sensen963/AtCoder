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
    vector<int> h(N + 2, 0);
    int m = 0;
    REP(i, N) {
        cin >> h[i + 1];
    }
    int count = 0;
    REP(o, 101){
        REP(i, N){
            if (h[i] == 0 && h[i + 1] > 0) count++;
        }
        REP(i, N) if (h[i + 1] > 0) h[i + 1]--;
    }
    cout << count << endl;
    return 0;
}