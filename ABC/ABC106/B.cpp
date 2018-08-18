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
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {

  int N;

  cin >> N;
  int count = 0;
  if (N < 105) {
    count = 0;
  }else if (N < 135){
    count = 1;
  }else if (N < 165){
    count = 2;
  }else if (N < 189){
    count = 3;
  }else if (N < 195){
    count = 4;
  }else {
    count = 5;
  }

  cout << count << endl;

  return 0;
}
