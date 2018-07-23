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
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {

  string S, T;

  cin >> S;
  cin >> T;

  int l = S.size();

  string a;
  bool ans = false;
  for (int i = 0; i < l; i++){
    a = S[l - 1];
    S.pop_back();
    S = a + S;
    //cout << S << endl;
    if (S == T) {
      ans = true;
      break;
    }
  }

  if (ans){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
