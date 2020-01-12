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
typedef pair<int, int> P;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

int getX(int num, int d){
    int tmp = num >> d;
    return (tmp % 2);
}

int getS(int num, int d){
    int ans = 0;
    REP(i, d){
        ans += getX(num, i);
    }
    return ans;
}

int main() {

    int N;
    cin >> N;
    vector<vector<P>> A(N);
    REP(i, N){
        int a;
        cin >> a;
        REP(j, a){
            int b, c;
            cin >> b >> c;
            A[i].push_back(P(b-1, c));
        }
    }
    int ans = 0;
    REP(i, (1<<N)){
        bool flag = true;
        REP(j, N){
            //if (i == 4 && j == 2) cout <<getX(i, j);
            if (getX(i, j) == 0) continue;
            for(auto iter : A[j]){
                //if (i == 4) cout << getX(i, iter.first) << iter.second << endl;
                if (getX(i, iter.first) != iter.second){
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        //cout << i << " " << flag << " " << getS(i, N)<< endl;
        if (flag) ans = max(ans, getS(i, N));
    }

    cout << ans << endl;


    return 0;
}