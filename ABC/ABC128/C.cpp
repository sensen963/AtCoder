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


int main() {

  int N, M;
  cin >> N >> M;

  vector<vector<int>> s(M);
  vector<int> k(M);
  vector<int> p(M);

  int tmp;
  REP(i, M){
    cin >> k[i];
    REP(j, k[i]) {
      cin >> tmp;
      tmp--;
      s[i].push_back(tmp);
    }
  }
  REP(i, M) cin >> p[i];

  int count = 0;
  REP(i, pow(2, N)){
      vector<int> on;
      int tmp = i;
      int tmp1;
      REP(j, N){
        on.push_back(tmp % 2);
        tmp /= 2;
      }
      bool flag = true;
      REP(j, M){
        tmp = 0;
        for(auto iter : s[j]) tmp += on[iter];
        if (tmp % 2 != p[j]) {
          flag = false;
        }
        //cout <<  tmp << " " << j << " " <<(tmp % 2) << endl;

      }
      if (flag) count++;
  }

  cout << count << endl;


  return 0;
}
