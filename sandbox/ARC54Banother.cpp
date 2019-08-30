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
    double P;
    cin >> P;

    auto fn = [](double x, double p){
        return (p / pow(2.0, x / 1.5) + x);
    };

    double a, b, R, L;
    L = 0.0;
    R = P;
    a = P / 3.0;
    b = 2.0 * P / 3.0;
    double tmp1 = 0, tmp2 = 1;
    int i = 0;
    while(abs(tmp1 - tmp2) > 1e-9 && abs(a - b) > 1e-9){
        a = (L * 2.0 + R) / 3.0;
        b = (L + R * 2.0) / 3.0;
        tmp1 = fn(a, P);
        tmp2 = fn(b, P);
        if (tmp1 < tmp2){
            R = b;
        }else{
            L = a;
        }
    }
    //cout << tmp1 << endl;
    printf("%.9f\n", tmp1);
    return 0;
}