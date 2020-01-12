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

    ll a, b, c;
    cin >> a >> b >> c;

    ll d, e;
    if (a > c){
        d = a - c;
        e = b;
    }else if(a + b > c){
        d = 0;
        e = a + b - c;
    }else{
        d = 0;
        e = 0;
    }
    cout << d << " " << e << endl;

    return 0;
}