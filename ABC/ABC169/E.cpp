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
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    REP(i, N){
        cin >> A[i] >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if (N % 2 == 0){
        double l = double(A[N / 2] + A[N / 2 -1]) / 2.0;
        double r = double(B[N / 2] + B[N / 2 -1]) / 2.0;
        cout << int((r - l) * 2.0) + 1 << endl;
    }else{
        cout << (B[N / 2] - A[N / 2]) + 1 << endl;
    }

    return 0;
}