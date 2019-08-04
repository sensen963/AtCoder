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
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

int gcd(int a, int b){
    if (a < b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {

    int A, B, K;
    cin >> A >> B >> K;
    int tmp = 0;
    int i = min(A, B) + 1;
    while(tmp < K){
        i--;
        if (A % i == 0 && B % i == 0){
            tmp++;
        }
        
    }

    cout << i << endl;

    return 0;
}