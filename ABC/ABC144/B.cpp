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
    bool ans = false;
    for (int i = 1; i < 10; i++){
        if (N % i == 0 && 1 <= (N / i) && (N / i) <= 9) ans = true;
    }
    if (ans){
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }

    return 0;
}