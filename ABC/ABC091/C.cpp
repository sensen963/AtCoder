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
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

struct v{
    bool isA;
    int x;
    int y;
};

int main() {
    int N;
    cin >> N;
    vector<v> A(2 * N);
    REP(i, N){
        A[i].isA = true;
        cin >> A[i].x >> A[i].y;
    }
    REP(i, N){
        A[i+N].isA = false;
        cin >> A[i+N].x >> A[i+N].y;
    }
    sort(A.begin(), A.end(), [](v& a, v& b){return a.x > b.x;});

    set<int> s;
    int ans = 0;
    REP(i, 2*N){
        if (!A[i].isA) s.insert(A[i].y);
        else{
            auto iter = s.lower_bound(A[i].y);
            if (iter != s.end()){
                s.erase(iter);
                //cout << A[i].y << " " << *iter << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;


    return 0;
}