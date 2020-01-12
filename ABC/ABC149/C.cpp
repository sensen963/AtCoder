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

    int n;
    cin >> n;

    int tmp = n;
    while(true){
        int i;
        for(i = 2; i < tmp; i++){
            if (tmp % i == 0){
                tmp++;
                break;
            }
        }
        if (i == tmp){
            cout << tmp << endl;
            return 0;
        }
    }

    return 0;
}