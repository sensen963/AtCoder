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
//#include <function>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {

  string ATCG;
  cin >> ATCG;

  int count = 0;
  int max_count = 0;
  bool flag = true;
  for(auto ss : ATCG){
    if (ss == 'A' || ss == 'C' || ss == 'G' || ss == 'T'){
      count++;
    }else {
      max_count = max(max_count, count);
      count = 0;
    }
  }
  max_count = max(max_count, count);
  cout << max_count << endl;
  
  return 0;
}
