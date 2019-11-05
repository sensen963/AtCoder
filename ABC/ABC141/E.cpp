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
    
    string s;
    cin >> s;
    s = s + '0';
    int tmp = 0;
    bool mode = false;
    int start, end;
    for(int i = 1;i < n; i++){
        for(int j = 0; j < n - i + 1; j++){
            if (s[j]==s[i+j]){
                if (!mode){
                    mode = true;
                    start = j;
                }
            }else{
                if (mode){
                    mode = false;
                    end = j - 1;
                    if (end >= start + i){
                        tmp = max(tmp, end - start + 1 - (end - start - i + 1));
                    }else{
                        tmp = max(tmp, end - start + 1);
                    }
                }
            }
        }
    }
    cout << tmp << endl;

    return 0;
}