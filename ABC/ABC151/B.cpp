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

    int N, K, M;
    cin >> N >> K >> M;
    int tmp, sum = 0;
    REP(i, N-1){
        cin >> tmp;
        sum += tmp;
    }
    int hoge = M * N - sum;
    if (hoge > K) hoge = -1;
    else if (hoge < 0) hoge = 0;
    cout << hoge << endl;

    return 0;
}