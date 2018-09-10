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

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {

  int n;
  cin >> n;

  vector<string> array(n);

  REP(i, n){
    cin >> array[i];
  }

  bool flag = true;

  REP(i, n-1) {
    if (*(array[i].end() - 1) != *array[i+1].begin()) {
      flag = false;
      //cout << *(array[i].end() - 1) << " " << array[i+1] << endl;
    }
  }

  for (int i = 1; i < n; i++){
    for (int j = 0; j < i; j++){
      if (array[i] == array[j]) flag = false;
    }
  }

  if (flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
