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

  int A, B;
  cin >> A >> B;

  int tmp = 0;
  if (A > B) {

    tmp += A;
    A--;
  }else{

    tmp += B;
    B--;
  }
  tmp += max(A, B);

  cout << tmp << endl;

  return 0;
}
