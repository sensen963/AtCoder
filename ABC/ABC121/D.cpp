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
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {

  ll A, B;
  cin >> A >> B;
  ll tmp = 0;

  if ((A == B) || (B < 8)){
    for(ll i = A; i <= B; i++) tmp = ll(tmp ^ i);
    cout << tmp << endl;
    return 0;
  }



  tmp = 0;
  REP(i, 4){
    if ((A + i) % 4 == 0){
      break;
    }else{
      tmp = ll(tmp ^ (A + i));
    }
  }

  REP(i, 4){
    if ((B - i) % 4 == 3){
      break;
    } else{
      tmp = ll(tmp ^ (B - i));
    }
  }

  cout << tmp << endl;

  return 0;
}
