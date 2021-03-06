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

    int a, b, c;
    cin >> a >> b >> c;

    if (a + c - 1 >= b - c + 1){
        for(int i = a; i <= b; i++) cout << i << endl;
    }
    else{
        REP(i, c) cout << (a+i) << endl;
        REP(i, c) cout << (b-c+1+i) << endl;
    }

    return 0;
}
